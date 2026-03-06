func useQt6 cQt6Path
    if ! iswindows()
        return 
    ok
	if ! isglobal(lower('$G_RING_QT_QML'))
		raise("Please load ring_qt_qml.ring first, using: load 'ring_qt_qml.ring'")
	ok
	loadlib(exefolder()+"ring_qt_qml.dll")
    G_RINGQML_cQT6FolderPath = cQt6Path

    cDllPath = exefolder() + 'RingQML6.dll'
    
    # Set the QML import path for the engine
    SysSet("QML2_IMPORT_PATH", cQt6Path + "/qml")
    
    # Load the DLL (This registers the start_qt6_gui function, but doesn't start Qt yet)
    loadlib(cDllPath)
    
    # Trigger the bridge! This applies the paths inside C++ and starts QApplication
    start_qt6_gui(cQt6Path)