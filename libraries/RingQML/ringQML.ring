load 'codegenlib.ring'

load 'globals.ring'
load 'corefunctions.ring'
load 'ringQmlRoot.ring'
load 'callringfuncfromqml.ring'
if iswindows() 
	$GcLibExtensionFilePath =''
	if fexists('RingQML.dll')
		$GcLibExtensionFilePath ="RingQML.dll"
	but fexists(exefolder()+'RingQML.dll')
		$GcLibExtensionFilePath=exefolder()+'RingQML.dll'
	ok
	if $GcLibExtensionFilePath=''
		raise("Can not find the RingQML.dll File in your system")
	ok
	loadlib($GcLibExtensionFilePath)
ok
func getPointerOnly	oObj 
	return getobjectpointerfromringobject(oObj)

func ringqmlexecutefunctioncallfromqml
	RingQml_Functions_prepare_callringfuncfromqml()
class ringQML
	# General Attributes
		pParent
		pEngine
		pRootContent
		pQQuickItem
		nQMLLoadingType

		root
	# Logicals
		l_reapeateCallLoadContent=0
		l_isNewComponenetCreated=0
	/*
		Name : INIT
		Usage : new ringQML( parent )
		Params : QQuickWidget|QQuickView|NULL (if we want to use "QQmlApplicationEngine")
		return : self (Object)
	*/
	func init oParent
		if oParent=''
			pParent=ringqmlenginapp_new()
			pEngine = pParent
		else 
			pParent = getPointerOnly(oParent)
			pEngine = getPointerOnly(oParent.engine())
		ok
		nQMLLoadingType=getQMLLoadingType(pParent[2])
		initqmlclass(pEngine)
		return self 
	/*
		Name : ShareWidget
		Usage : ShareWidget(pWidget,cName)
		Params : pWidget (Object|Pointer),cName (String)
		return : null
	*/
	func ShareWidget pWidget,cName
		exposeQWidget(pWidget,cName)
	/*
		Name : exposeQWidget
		Usage : exposeQWidget(pWidget,cName)
		Params : pWidget (Object|Pointer),cName (String)
		return : null
	*/
	func exposeQWidget pWidget,cName
		exposeQWidgetToQML(
			pEngine,
			getobjectpointerfromringobject(pWidget),
			cName
		)
	/*
		Name : shareImage
		Usage : exposeQWidget(pImage)
		Params : pImage (QPixmap) (Object|Pointer)
		return : nId (Number) <- id used to get the image using RingProvider in QML
	*/
	func shareImage pImage 
		return exposeimagetoqml(pEngine,
			getobjectpointerfromringobject(pImage))
	/*
		Name : callQMLFunc
		Usage : callQMLFunc(cFunc ,aPara)
		Params : cFunc (String),aPara (list)
		return : 0|1 (Number)
	*/
	func callQMLFunc cFunc ,aPara
		if isnull(cFunc) return 0 ok
		return ringqmlcallqmlfunc(pQQuickItem,cFunc ,aPara)
	/*
		Name : NewComponent
		Usage : NewComponent(cComponentName ,cQml)
		Params : cComponentName (String),cQml (String)
		return : ringQmlRoot (Object)
	*/
	func NewComponent cComponentName ,cQml

		l_isNewComponenetCreated=1
		cQML =trimContent(cQML)
		pNewQQuickItem=createnewcomponent(pEngine,cComponentName ,cQml)
		return new ringQMLComponenet(pNewQQuickItem)
		

	/*
		Name : loadContent
		Usage : loadContent(cQmlCode)
		Params : cQmlCode (String)
		return : 0|1 (Number)
	*/
	func loadContent cQML 
		
		if l_reapeateCallLoadContent
			raise("Can not Call LoadContent more than one time...")
		ok
		l_reapeateCallLoadContent=1
		isLoadContentUsed=1
		cQML =trimContent(cQML)
		pParent = getobjectpointerfromringobject(pParent)

		if l_isNewComponenetCreated
			cQML='import Dynamic 1.0;'+cQML
		ok
		switch nQMLLoadingType
			on G_RINGQML_LOAD_TYPE_WIDGET
				pQQuickItem = ringqml_loadfrom_qmlwidget(pParent ,cQML )

			on G_RINGQML_LOAD_TYPE_VIEW
				pQQuickItem = ringqml_loadfrom_qmlview(pParent ,cQML )

			on G_RINGQML_LOAD_TYPE_ENGINE
				pQQuickItem = ringqml_loadfrom_qmlengin(pParent ,cQML )

		off 
		if ispointer(pQQuickItem)
			if pQQuickItem != nullptr()
				G_nComponentsCounter++
			
				cClassName = 'ringQmlComponenetRoot_'+G_nComponentsCounter
				eval('class '+cClassName+' from ringQmlRoot '+nl+' Func init(pQQuickItem) '+nl+' oQQuickItem = pQQuickItem '+nl+' addQmlFunctionsToClass()  ')
				cClassName= lower(cClassName)
				root = new from cClassName(pQQuickItem)
		
		
				return 1
			ok
		ok
		return 0
