class ringQMLComponenet
	oQQuickItem
	root 
	func init pQQuickItem
		oQQuickItem = pQQuickItem
		G_nComponentsCounter++
		cClassName = 'ringQmlComponenetRoot_'+G_nComponentsCounter
		eval('class '+cClassName+' from ringQmlRoot '+nl+' Func init(pQQuickItem) '+nl+' oQQuickItem = pQQuickItem '+nl+' addQmlFunctionsToClass()  ')
		cClassName= lower(cClassName)
		root = new from cClassName(pQQuickItem)
		
		
		return self 
	func callQMLFunc cFuncName,aPara 
		if isnull(cFuncName) return 0 ok
		return ringqmlcallqmlfunc(oQQuickItem,cFuncName,aPara)

class ringQmlRoot
	oQQuickItem
	func init pQQuickItem
		oQQuickItem = pQQuickItem
		
		return self
	func addQmlFunctionsToClass
		aFunctionsList = getqmldefinedfunctions(oQQuickItem)
		aFunctionsList = aFunctionsList[1]
		nLength = len(aFunctionsList)
		for x=1 to nLength
			cMethod = "func "
			cPara = ''
			nTotalPara = 0+aFunctionsList[x][2]
			if nTotalPara
				for nPara=1 to nTotalPara
					if nPara != nTotalPara
						cPara+= 'p'+nPara+','
					else
						cPara+= 'p'+nPara
					ok
				next
			ok
			cMethod+=cPara+'{'+nl+' return callQMLFunc('+char(34)+aFunctionsList[x][1]+char(34)+',['+cPara+'])'+nl+'  }'
			//? 'cNewMethodName = '+cMethod
			//cNewMethodName = eval('return '+cMethod)

			//eval('cNewMethodName = '+cMethod)
			//if ! ismethod(self, lower(aFunctionsList[x][1]) )
				//addmethod(this,aFunctionsList[x][1],cNewMethodName)
			addmethod(this,aFunctionsList[x][1],eval('return '+cMethod))
			//ok
		next 
	func callQMLFunc cFuncName,aPara 
		if isnull(cFuncName) return 0 ok
		return ringqmlcallqmlfunc(oQQuickItem,cFuncName,aPara)
	