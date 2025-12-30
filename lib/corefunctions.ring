func trimContent ctxt
	while (left(cTxt,1)= nl or left(cTxt,1)=windowsnl()) or left(cTxt,1)=' '
		cTxt = substr(cTxt,2)
	end

	while (right(cTxt,1)= nl or right(cTxt,1)=windowsnl()) or right(cTxt,1)=' '
		cTxt = left(cTxt,len(cTxt)-1)
	end

	return cTxt

func getQMLLoadingType cType 
	cType = lower(cType)
	cType = substr(cType,"qquick",'')
	switch cType
	on :view 
		return G_RINGQML_LOAD_TYPE_VIEW
	on :widget
		return G_RINGQML_LOAD_TYPE_WIDGET
	other
		return G_RINGQML_LOAD_TYPE_ENGINE
	off
