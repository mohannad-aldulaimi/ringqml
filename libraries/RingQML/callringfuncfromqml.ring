RingQML_Variables_nTabs=0
RingQML_Variables_aIndexs = []

func RingQml_Functions_prepare_callringfuncfromqml
		nIndex=len(G_aFunctionsCalledFromQML)
		cFuncName = G_aFunctionsCalledFromQML[nIndex][1]
		aFuncParams = G_aFunctionsCalledFromQML[nIndex][2]
		cCodeToExecute =''
		//? G_aFunctionsCalledFromQML
		if len(aFuncParams) > 0
		/*
		 * we used this way because it more simple/practical than 
		   get each para and check its type and if it is 
		   string check if it contains ' or " or `
		 * also to handle if we have para like : array of objects/items
		   contains array of objetcs/items : [[o1,o2,"Str",{"test":true}],other array]
		 * also to maintain the object when we have a pointer sent from QML
		*/
			nParaCount = len(aFuncParams)
			cCodeToExecute = 'aFuncParams = G_aFunctionsCalledFromQML[1][2]'+nl
			cCodeToExecute += RingQml_Functions_getQMLCodeForEval(:aFuncParams,0,aFuncParams)+nl+nl
			
			cCodeToExecute+='G_FunctionCalledFromQML_out = '+cFuncName+'('
			for nPara=1 to nParaCount
				cCodeToExecute+='p'+nPara
				if nPara != nParaCount
					cCodeToExecute+=','
				ok
			next
			cCodeToExecute+=')'
			//? cCodeToExecute
			eval('cFunc = func {'+cCodeToExecute+' }')
			call cFunc()
			
			G_aFunctionsCalledFromQML=[]

		else
			G_FunctionCalledFromQML_out = call cFuncName()
		
			G_aFunctionsCalledFromQML =[]
				
		ok
		RingQml_Functions_process_qml_callfunc_out()
			//? G_FunctionCalledFromQML_out

func RingQml_Functions_process_qml_callfunc_out 
	if isobject(G_FunctionCalledFromQML_out)
		G_FunctionCalledFromQML_out = getobjectpointerfromringobject(G_FunctionCalledFromQML_out)
	but ispointer(G_FunctionCalledFromQML_out)
		if type(G_FunctionCalledFromQML_out) != 'QObject'
			raise('Error ,returned pointer type : "'+type(G_FunctionCalledFromQML_out)+'",must be QObject'+nl)
		ok
	but islist(G_FunctionCalledFromQML_out)
		RingQml_Functions_processpointersiffound(G_FunctionCalledFromQML_out)
	ok

func RingQml_Functions_processpointersiffound alist
	for item in alist
		if isobject(item)
			item = getobjectpointerfromringobject(item)
		but ispointer(item)
			if type(item) != 'QObject'
				raise('Error ,returned pointer type : "'+type(item)+'",must be QObject'+nl)
			ok
		but islist(item)
			RingQml_Functions_processpointersiffound(item)
		ok
	next
func RingQml_Functions_getQMLCodeForEval cListName,nIndex, alist
	cCode =''
	if nIndex = 0 // Startup para array
		for nPara=1 to len(alist)
			if ispointer(alist[nPara])//
				//cCode += 'p'+nPara+' = new qObject(){ pObject='+cListName+'['+nPara+'] }'+nl
				if alist[nPara][2]= 'QObject'
					cCode += 'p'+nPara+' = new qObject('+cListName+'['+nPara+'] )'+nl
				but alist[nPara][2] != 'QObject' and isclass(alist[nPara][2])
					cCode += 'p'+nPara+' = new '+alist[nPara][2]+'{ pObject='+cListName+'['+nPara+'] }'+nl
				else
					cCode += 'p'+nPara+' = '+cListName+'['+nPara+'] '+nl
				ok
			but islist(alist[nPara])
				RingQML_Variables_nTabs++
				
				RingQML_Variables_aIndexs + nPara
				cCode += 'p'+nPara+' = ['+nl +RingQml_Functions_getQMLCodeForEval(cListName,1, alist[nPara])+nl 
				del(RingQML_Variables_aIndexs,1)

				RingQML_Variables_nTabs--
			else
				cCode += 'p'+nPara+' = '+cListName+'['+nPara+']'+nl
			
			ok
		next
	else
		for nPara=1 to len(alist)
			cCode += RingQml_Functions_gettabs() 
			if ispointer(alist[nPara])
				RingQML_Variables_aIndexs + nPara

			//	cCode += ' new qObject(){ pObject='+cListName+getIndexsBraces()+' }'
			//	cCode += ' new ringQMLObject('+cListName+getIndexsBraces()+')'
				cCode += ' new qObject('+cListName+getIndexsBraces()+')'
				del(RingQML_Variables_aIndexs,len(RingQML_Variables_aIndexs))

			but islist(alist[nPara]) 
				RingQML_Variables_aIndexs + nPara

				cCode += ' ['+nl
				RingQML_Variables_nTabs++
				cCode += RingQml_Functions_getQMLCodeForEval(cListName,nIndex, alist[nPara])
				del(RingQML_Variables_aIndexs,len(RingQML_Variables_aIndexs))

				RingQML_Variables_nTabs--
			else
				RingQML_Variables_aIndexs + nPara

				cCode +=' '+cListName+getIndexsBraces()
				del(RingQML_Variables_aIndexs,len(RingQML_Variables_aIndexs))

			ok
			if nPara != len(alist)
				cCode+= ','+nl
			ok
		next

		cCode+=nl+RingQml_Functions_gettabsMone()+' ]'
	ok
	return cCode
	func RingQml_Functions_gettabs
		return copy(tab,RingQML_Variables_nTabs)
	func RingQml_Functions_gettabsMone() //Tabs - 1
		return copy(tab,RingQML_Variables_nTabs-1)