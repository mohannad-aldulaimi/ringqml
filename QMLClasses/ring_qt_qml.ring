
load "codegenlib.ring"

Class QObject

	pObject

	Func init 
		pObject = QObject_new()
		return self

	Func delete
		pObject = QObject_delete(pObject)

	Func ObjectPointer
		return pObject

	Func blockSignals P1
		return QObject_blockSignals(pObject,P1)

	Func children 
		return QObject_children(pObject)

	Func dumpObjectInfo 
		return QObject_dumpObjectInfo(pObject)

	Func dumpObjectTree 
		return QObject_dumpObjectTree(pObject)

	Func inherits P1
		return QObject_inherits(pObject,P1)

	Func installEventFilter P1
		return QObject_installEventFilter(pObject,GetObjectPointerFromRingObject(P1))

	Func isWidgetType 
		return QObject_isWidgetType(pObject)

	Func killTimer P1
		return QObject_killTimer(pObject,P1)

	Func moveToThread P1
		return QObject_moveToThread(pObject,GetObjectPointerFromRingObject(P1))

	Func objectName 
		return QObject_objectName(pObject)

	Func parent 
		pTempObj = new QObject
		pTempObj.pObject = QObject_parent(pObject)
		return pTempObj

	Func property P1
		pTempObj = new QVariant
		pTempObj.pObject = QObject_property(pObject,P1)
		return pTempObj

	Func removeEventFilter P1
		return QObject_removeEventFilter(pObject,GetObjectPointerFromRingObject(P1))

	Func setObjectName P1
		return QObject_setObjectName(pObject,P1)

	Func setParent P1
		return QObject_setParent(pObject,GetObjectPointerFromRingObject(P1))

	Func setProperty P1,P2
		return QObject_setProperty(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func setProperty_2 P1,P2
		return QObject_setProperty_2(pObject,P1,P2)

	Func setProperty_3 P1,P2
		return QObject_setProperty_3(pObject,P1,P2)

	Func setProperty_4 P1,P2
		return QObject_setProperty_4(pObject,P1,P2)

	Func setProperty_int P1,P2
		return QObject_setProperty_int(pObject,P1,P2)

	Func setProperty_float P1,P2
		return QObject_setProperty_float(pObject,P1,P2)

	Func setProperty_double P1,P2
		return QObject_setProperty_double(pObject,P1,P2)

	Func setProperty_5 P1,P2
		return QObject_setProperty_5(pObject,P1,P2)

	Func setProperty_string P1,P2
		return QObject_setProperty_string(pObject,P1,P2)

	Func signalsBlocked 
		return QObject_signalsBlocked(pObject)

	Func startTimer P1
		return QObject_startTimer(pObject,P1)

	Func thread 
		pTempObj = new QThread
		pTempObj.pObject = QObject_thread(pObject)
		return pTempObj

	Func deleteLater 
		return QObject_deleteLater(pObject)

Class QDir

	pObject

	Func init 
		pObject = QDir_new()
		return self

	Func delete
		pObject = QDir_delete(pObject)

	Func ObjectPointer
		return pObject

	Func absoluteFilePath P1
		return QDir_absoluteFilePath(pObject,P1)

	Func absolutePath 
		return QDir_absolutePath(pObject)

	Func canonicalPath 
		return QDir_canonicalPath(pObject)

	Func cd P1
		return QDir_cd(pObject,P1)

	Func cdUp 
		return QDir_cdUp(pObject)

	Func count 
		return QDir_count(pObject)

	Func dirName 
		return QDir_dirName(pObject)

	Func entryInfoList P1,P2,P3
		return QDir_entryInfoList(pObject,GetObjectPointerFromRingObject(P1),P2,P3)

	Func entryInfoList_2 P1,P2
		return QDir_entryInfoList_2(pObject,P1,P2)

	Func entryList P1,P2,P3
		pTempObj = new QStringList
		pTempObj.pObject = QDir_entryList(pObject,GetObjectPointerFromRingObject(P1),P2,P3)
		return pTempObj

	Func entryList_2 P1,P2
		pTempObj = new QStringList
		pTempObj.pObject = QDir_entryList_2(pObject,P1,P2)
		return pTempObj

	Func exists P1
		return QDir_exists(pObject,P1)

	Func exists_2 
		return QDir_exists_2(pObject)

	Func filePath P1
		return QDir_filePath(pObject,P1)

	Func filter 
		return QDir_filter(pObject)

	Func isAbsolute 
		return QDir_isAbsolute(pObject)

	Func isReadable 
		return QDir_isReadable(pObject)

	Func isRelative 
		return QDir_isRelative(pObject)

	Func isRoot 
		return QDir_isRoot(pObject)

	Func makeAbsolute 
		return QDir_makeAbsolute(pObject)

	Func mkdir P1
		return QDir_mkdir(pObject,P1)

	Func mkpath P1
		return QDir_mkpath(pObject,P1)

	Func nameFilters 
		pTempObj = new QStringList
		pTempObj.pObject = QDir_nameFilters(pObject)
		return pTempObj

	Func path 
		return QDir_path(pObject)

	Func refresh 
		return QDir_refresh(pObject)

	Func relativeFilePath P1
		return QDir_relativeFilePath(pObject,P1)

	Func remove P1
		return QDir_remove(pObject,P1)

	Func removeRecursively 
		return QDir_removeRecursively(pObject)

	Func rename P1,P2
		return QDir_rename(pObject,P1,P2)

	Func rmdir P1
		return QDir_rmdir(pObject,P1)

	Func rmpath P1
		return QDir_rmpath(pObject,P1)

	Func setFilter P1
		return QDir_setFilter(pObject,P1)

	Func setNameFilters P1
		return QDir_setNameFilters(pObject,GetObjectPointerFromRingObject(P1))

	Func setPath P1
		return QDir_setPath(pObject,P1)

	Func setSorting P1
		return QDir_setSorting(pObject,P1)

	Func sorting 
		return QDir_sorting(pObject)

	Func swap P1
		return QDir_swap(pObject,GetObjectPointerFromRingObject(P1))

	Func addSearchPath P1,P2
		return QDir_addSearchPath(pObject,P1,P2)

	Func cleanPath P1
		return QDir_cleanPath(pObject,P1)

	Func current 
		pTempObj = new QDir
		pTempObj.pObject = QDir_current(pObject)
		return pTempObj

	Func currentPath 
		return QDir_currentPath(pObject)

	Func drives 
		return QDir_drives(pObject)

	Func fromNativeSeparators P1
		return QDir_fromNativeSeparators(pObject,P1)

	Func home 
		pTempObj = new QDir
		pTempObj.pObject = QDir_home(pObject)
		return pTempObj

	Func homePath 
		return QDir_homePath(pObject)

	Func isAbsolutePath P1
		return QDir_isAbsolutePath(pObject,P1)

	Func isRelativePath P1
		return QDir_isRelativePath(pObject,P1)

	Func match P1,P2
		return QDir_match(pObject,P1,P2)

	Func match_2 P1,P2
		return QDir_match_2(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func root 
		pTempObj = new QDir
		pTempObj.pObject = QDir_root(pObject)
		return pTempObj

	Func rootPath 
		return QDir_rootPath(pObject)

	Func searchPaths P1
		pTempObj = new QStringList
		pTempObj.pObject = QDir_searchPaths(pObject,P1)
		return pTempObj

	Func separator 
		pTempObj = new QChar
		pTempObj.pObject = QDir_separator(pObject)
		return pTempObj

	Func setCurrent P1
		return QDir_setCurrent(pObject,P1)

	Func setSearchPaths P1,P2
		return QDir_setSearchPaths(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func temp 
		pTempObj = new QDir
		pTempObj.pObject = QDir_temp(pObject)
		return pTempObj

	Func tempPath 
		return QDir_tempPath(pObject)

	Func toNativeSeparators P1
		return QDir_toNativeSeparators(pObject,P1)

Class QUrl

	pObject

	Func init P1
		pObject = QUrl_new(P1)
		return self

	Func delete
		pObject = QUrl_delete(pObject)

	Func ObjectPointer
		return pObject

	Func authority P1
		return QUrl_authority(pObject,P1)

	Func clear 
		return QUrl_clear(pObject)

	Func errorString 
		return QUrl_errorString(pObject)

	Func fileName P1
		return QUrl_fileName(pObject,P1)

	Func fragment P1
		return QUrl_fragment(pObject,P1)

	Func hasFragment 
		return QUrl_hasFragment(pObject)

	Func hasQuery 
		return QUrl_hasQuery(pObject)

	Func host P1
		return QUrl_host(pObject,P1)

	Func isEmpty 
		return QUrl_isEmpty(pObject)

	Func isLocalFile 
		return QUrl_isLocalFile(pObject)

	Func isParentOf P1
		return QUrl_isParentOf(pObject,GetObjectPointerFromRingObject(P1))

	Func isRelative 
		return QUrl_isRelative(pObject)

	Func isValid 
		return QUrl_isValid(pObject)

	Func password P1
		return QUrl_password(pObject,P1)

	Func path P1
		return QUrl_path(pObject,P1)

	Func port P1
		return QUrl_port(pObject,P1)

	Func query P1
		return QUrl_query(pObject,P1)

	Func resolved P1
		pTempObj = new QUrl
		pTempObj.pObject = QUrl_resolved(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

	Func scheme 
		return QUrl_scheme(pObject)

	Func setAuthority P1,P2
		return QUrl_setAuthority(pObject,P1,P2)

	Func setFragment P1,P2
		return QUrl_setFragment(pObject,P1,P2)

	Func setHost P1,P2
		return QUrl_setHost(pObject,P1,P2)

	Func setPassword P1,P2
		return QUrl_setPassword(pObject,P1,P2)

	Func setPath P1,P2
		return QUrl_setPath(pObject,P1,P2)

	Func setPort P1
		return QUrl_setPort(pObject,P1)

	Func setQuery P1,P2
		return QUrl_setQuery(pObject,P1,P2)

	Func setScheme P1
		return QUrl_setScheme(pObject,P1)

	Func setUrl P1,P2
		return QUrl_setUrl(pObject,P1,P2)

	Func setUserInfo P1,P2
		return QUrl_setUserInfo(pObject,P1,P2)

	Func setUserName P1,P2
		return QUrl_setUserName(pObject,P1,P2)

	Func swap P1
		return QUrl_swap(pObject,GetObjectPointerFromRingObject(P1))

	Func toLocalFile 
		return QUrl_toLocalFile(pObject)

	Func userInfo P1
		return QUrl_userInfo(pObject,P1)

	Func userName P1
		return QUrl_userName(pObject,P1)

	Func fromLocalFile P1
		pTempObj = new QUrl
		pTempObj.pObject = QUrl_fromLocalFile(pObject,P1)
		return pTempObj

Class QEvent

	pObject

	Func init P1
		pObject = QEvent_new(P1)
		return self

	Func delete
		pObject = QEvent_delete(pObject)

	Func ObjectPointer
		return pObject

	Func accept 
		return QEvent_accept(pObject)

	Func ignore 
		return QEvent_ignore(pObject)

	Func isAccepted 
		return QEvent_isAccepted(pObject)

	Func setAccepted P1
		return QEvent_setAccepted(pObject,P1)

	Func spontaneous 
		return QEvent_spontaneous(pObject)

	Func type 
		return QEvent_type(pObject)

Class QTimer

	pObject

	Func init P1
		pObject = QTimer_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QTimer_delete(pObject)

	Func ObjectPointer
		return pObject

	Func interval 
		return QTimer_interval(pObject)

	Func isActive 
		return QTimer_isActive(pObject)

	Func isSingleShot 
		return QTimer_isSingleShot(pObject)

	Func setInterval P1
		return QTimer_setInterval(pObject,P1)

	Func setSingleShot P1
		return QTimer_setSingleShot(pObject,P1)

	Func timerId 
		return QTimer_timerId(pObject)

	Func start 
		return QTimer_start(pObject)

	Func stop 
		return QTimer_stop(pObject)

	Func settimeoutEvent P1
		return QTimer_settimeoutEvent(pObject,P1)

	Func gettimeoutEvent 
		return QTimer_gettimeoutEvent(pObject)

Class QByteArray

	pObject

	Func init 
		pObject = QByteArray_new()
		return self

	Func delete
		pObject = QByteArray_delete(pObject)

	Func ObjectPointer
		return pObject

	Func append P1
		pTempObj = new QByteArray
		pTempObj.pObject = QByteArray_append(pObject,P1)
		return pTempObj

	Func append_2 P1,P2
		pTempObj = new QByteArray
		pTempObj.pObject = QByteArray_append_2(pObject,P1,P2)
		return pTempObj

	Func at P1
		return QByteArray_at(pObject,P1)

	Func capacity 
		return QByteArray_capacity(pObject)

	Func chop P1
		return QByteArray_chop(pObject,P1)

	Func clear 
		return QByteArray_clear(pObject)

	Func constData 
		return QByteArray_constData(pObject)

	Func contains P1
		return QByteArray_contains(pObject,P1)

	Func count P1
		return QByteArray_count(pObject,P1)

	Func data 
		return QByteArray_data(pObject)

	Func endsWith P1
		return QByteArray_endsWith(pObject,P1)

	Func fill P1,P2
		pTempObj = new QByteArray
		pTempObj.pObject = QByteArray_fill(pObject,P1,P2)
		return pTempObj

	Func indexOf P1,P2
		return QByteArray_indexOf(pObject,P1,P2)

	Func insert P1,P2,P3
		pTempObj = new QByteArray
		pTempObj.pObject = QByteArray_insert(pObject,P1,P2,P3)
		return pTempObj

	Func isEmpty 
		return QByteArray_isEmpty(pObject)

	Func isNull 
		return QByteArray_isNull(pObject)

	Func lastIndexOf P1,P2
		return QByteArray_lastIndexOf(pObject,P1,P2)

	Func left P1
		pTempObj = new QByteArray
		pTempObj.pObject = QByteArray_left(pObject,P1)
		return pTempObj

	Func leftJustified P1,P2,P3
		pTempObj = new QByteArray
		pTempObj.pObject = QByteArray_leftJustified(pObject,P1,P2,P3)
		return pTempObj

	Func length 
		return QByteArray_length(pObject)

	Func mid P1,P2
		pTempObj = new QByteArray
		pTempObj.pObject = QByteArray_mid(pObject,P1,P2)
		return pTempObj

	Func prepend P1,P2
		pTempObj = new QByteArray
		pTempObj.pObject = QByteArray_prepend(pObject,P1,P2)
		return pTempObj

	Func push_back P1
		return QByteArray_push_back(pObject,P1)

	Func push_front P1
		return QByteArray_push_front(pObject,P1)

	Func remove P1,P2
		pTempObj = new QByteArray
		pTempObj.pObject = QByteArray_remove(pObject,P1,P2)
		return pTempObj

	Func repeated P1
		pTempObj = new QByteArray
		pTempObj.pObject = QByteArray_repeated(pObject,P1)
		return pTempObj

	Func replace P1,P2,P3,P4
		pTempObj = new QByteArray
		pTempObj.pObject = QByteArray_replace(pObject,P1,P2,P3,P4)
		return pTempObj

	Func replace_2 P1,P2,P3
		pTempObj = new QByteArray
		pTempObj.pObject = QByteArray_replace_2(pObject,P1,P2,GetObjectPointerFromRingObject(P3))
		return pTempObj

	Func replace_3 P1,P2,P3
		pTempObj = new QByteArray
		pTempObj.pObject = QByteArray_replace_3(pObject,P1,P2,P3)
		return pTempObj

	Func replace_4 P1,P2
		pTempObj = new QByteArray
		pTempObj.pObject = QByteArray_replace_4(pObject,P1,P2)
		return pTempObj

	Func replace_5 P1,P2
		pTempObj = new QByteArray
		pTempObj.pObject = QByteArray_replace_5(pObject,P1,GetObjectPointerFromRingObject(P2))
		return pTempObj

	Func replace_6 P1,P2
		pTempObj = new QByteArray
		pTempObj.pObject = QByteArray_replace_6(pObject,P1,P2)
		return pTempObj

	Func replace_7 P1,P2,P3,P4
		pTempObj = new QByteArray
		pTempObj.pObject = QByteArray_replace_7(pObject,P1,P2,P3,P4)
		return pTempObj

	Func replace_8 P1,P2
		pTempObj = new QByteArray
		pTempObj.pObject = QByteArray_replace_8(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2))
		return pTempObj

	Func replace_9 P1,P2
		pTempObj = new QByteArray
		pTempObj.pObject = QByteArray_replace_9(pObject,GetObjectPointerFromRingObject(P1),P2)
		return pTempObj

	Func replace_10 P1,P2
		pTempObj = new QByteArray
		pTempObj.pObject = QByteArray_replace_10(pObject,P1,GetObjectPointerFromRingObject(P2))
		return pTempObj

	Func replace_11 P1,P2
		pTempObj = new QByteArray
		pTempObj.pObject = QByteArray_replace_11(pObject,P1,P2)
		return pTempObj

	Func reserve P1
		return QByteArray_reserve(pObject,P1)

	Func resize P1
		return QByteArray_resize(pObject,P1)

	Func right P1
		pTempObj = new QByteArray
		pTempObj.pObject = QByteArray_right(pObject,P1)
		return pTempObj

	Func rightJustified P1,P2,P3
		pTempObj = new QByteArray
		pTempObj.pObject = QByteArray_rightJustified(pObject,P1,P2,P3)
		return pTempObj

	Func setNum P1,P2
		pTempObj = new QByteArray
		pTempObj.pObject = QByteArray_setNum(pObject,P1,P2)
		return pTempObj

	Func setRawData P1,P2
		pTempObj = new QByteArray
		pTempObj.pObject = QByteArray_setRawData(pObject,P1,P2)
		return pTempObj

	Func simplified 
		pTempObj = new QByteArray
		pTempObj.pObject = QByteArray_simplified(pObject)
		return pTempObj

	Func size 
		return QByteArray_size(pObject)

	Func squeeze 
		return QByteArray_squeeze(pObject)

	Func startsWith P1
		return QByteArray_startsWith(pObject,P1)

	Func swap P1
		return QByteArray_swap(pObject,GetObjectPointerFromRingObject(P1))

	Func toBase64 
		pTempObj = new QByteArray
		pTempObj.pObject = QByteArray_toBase64(pObject)
		return pTempObj

	Func toDouble P1
		return QByteArray_toDouble(pObject,GetObjectPointerFromRingObject(P1))

	Func toFloat P1
		return QByteArray_toFloat(pObject,GetObjectPointerFromRingObject(P1))

	Func toHex 
		pTempObj = new QByteArray
		pTempObj.pObject = QByteArray_toHex(pObject)
		return pTempObj

	Func toInt P1,P2
		return QByteArray_toInt(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func toLong P1,P2
		return QByteArray_toLong(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func toLongLong P1,P2
		return QByteArray_toLongLong(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func toLower 
		pTempObj = new QByteArray
		pTempObj.pObject = QByteArray_toLower(pObject)
		return pTempObj

	Func toPercentEncoding P1,P2,P3
		pTempObj = new QByteArray
		pTempObj.pObject = QByteArray_toPercentEncoding(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2),P3)
		return pTempObj

	Func toShort P1,P2
		return QByteArray_toShort(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func toUInt P1,P2
		return QByteArray_toUInt(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func toULong P1,P2
		return QByteArray_toULong(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func toULongLong P1,P2
		return QByteArray_toULongLong(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func toUShort P1,P2
		return QByteArray_toUShort(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func toUpper 
		pTempObj = new QByteArray
		pTempObj.pObject = QByteArray_toUpper(pObject)
		return pTempObj

	Func trimmed 
		pTempObj = new QByteArray
		pTempObj.pObject = QByteArray_trimmed(pObject)
		return pTempObj

	Func truncate P1
		return QByteArray_truncate(pObject,P1)

	Func fromBase64 P1
		pTempObj = new QByteArray
		pTempObj.pObject = QByteArray_fromBase64(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

	Func fromHex P1
		pTempObj = new QByteArray
		pTempObj.pObject = QByteArray_fromHex(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

	Func fromPercentEncoding P1,P2
		pTempObj = new QByteArray
		pTempObj.pObject = QByteArray_fromPercentEncoding(pObject,GetObjectPointerFromRingObject(P1),P2)
		return pTempObj

	Func fromRawData P1,P2
		pTempObj = new QByteArray
		pTempObj.pObject = QByteArray_fromRawData(pObject,P1,P2)
		return pTempObj

	Func number P1,P2
		pTempObj = new QByteArray
		pTempObj.pObject = QByteArray_number(pObject,P1,P2)
		return pTempObj

Class QIODevice from QObject

	pObject

	Func init 
		pObject = QIODevice_new()
		return self

	Func delete
		pObject = QIODevice_delete(pObject)

	Func ObjectPointer
		return pObject

	Func errorString 
		return QIODevice_errorString(pObject)

	Func getChar P1
		return QIODevice_getChar(pObject,P1)

	Func isOpen 
		return QIODevice_isOpen(pObject)

	Func isReadable 
		return QIODevice_isReadable(pObject)

	Func isTextModeEnabled 
		return QIODevice_isTextModeEnabled(pObject)

	Func isWritable 
		return QIODevice_isWritable(pObject)

	Func openMode 
		return QIODevice_openMode(pObject)

	Func peek P1,P2
		return QIODevice_peek(pObject,P1,P2)

	Func putChar P1
		return QIODevice_putChar(pObject,P1)

	Func read P1,P2
		return QIODevice_read(pObject,P1,P2)

	Func readAll 
		pTempObj = new QByteArray
		pTempObj.pObject = QIODevice_readAll(pObject)
		return pTempObj

	Func readLine P1,P2
		return QIODevice_readLine(pObject,P1,P2)

	Func setTextModeEnabled P1
		return QIODevice_setTextModeEnabled(pObject,P1)

	Func ungetChar P1
		return QIODevice_ungetChar(pObject,P1)

	Func write P1,P2
		return QIODevice_write(pObject,P1,P2)

	Func atEnd 
		return QIODevice_atEnd(pObject)

	Func canReadLine 
		return QIODevice_canReadLine(pObject)

	Func close 
		return QIODevice_close(pObject)

	Func open P1
		return QIODevice_open(pObject,P1)

	Func pos 
		return QIODevice_pos(pObject)

	Func seek P1
		return QIODevice_seek(pObject,P1)

	Func size 
		return QIODevice_size(pObject)

	Func setaboutToCloseEvent P1
		return QIODevice_setaboutToCloseEvent(pObject,P1)

	Func setbytesWrittenEvent P1
		return QIODevice_setbytesWrittenEvent(pObject,P1)

	Func setreadChannelFinishedEvent P1
		return QIODevice_setreadChannelFinishedEvent(pObject,P1)

	Func setreadyReadEvent P1
		return QIODevice_setreadyReadEvent(pObject,P1)

	Func getaboutToCloseEvent 
		return QIODevice_getaboutToCloseEvent(pObject)

	Func getbytesWrittenEvent 
		return QIODevice_getbytesWrittenEvent(pObject)

	Func getreadChannelFinishedEvent 
		return QIODevice_getreadChannelFinishedEvent(pObject)

	Func getreadyReadEvent 
		return QIODevice_getreadyReadEvent(pObject)

Class QFileInfo

	pObject

	Func init 
		pObject = QFileInfo_new()
		return self

	Func delete
		pObject = QFileInfo_delete(pObject)

	Func ObjectPointer
		return pObject

	Func absoluteDir 
		pTempObj = new QDir
		pTempObj.pObject = QFileInfo_absoluteDir(pObject)
		return pTempObj

	Func absoluteFilePath 
		return QFileInfo_absoluteFilePath(pObject)

	Func absolutePath 
		return QFileInfo_absolutePath(pObject)

	Func baseName 
		return QFileInfo_baseName(pObject)

	Func bundleName 
		return QFileInfo_bundleName(pObject)

	Func caching 
		return QFileInfo_caching(pObject)

	Func canonicalFilePath 
		return QFileInfo_canonicalFilePath(pObject)

	Func canonicalPath 
		return QFileInfo_canonicalPath(pObject)

	Func completeBaseName 
		return QFileInfo_completeBaseName(pObject)

	Func completeSuffix 
		return QFileInfo_completeSuffix(pObject)

	Func dir 
		pTempObj = new QDir
		pTempObj.pObject = QFileInfo_dir(pObject)
		return pTempObj

	Func exists 
		return QFileInfo_exists(pObject)

	Func fileName 
		return QFileInfo_fileName(pObject)

	Func filePath 
		return QFileInfo_filePath(pObject)

	Func group 
		return QFileInfo_group(pObject)

	Func groupId 
		return QFileInfo_groupId(pObject)

	Func isAbsolute 
		return QFileInfo_isAbsolute(pObject)

	Func isBundle 
		return QFileInfo_isBundle(pObject)

	Func isDir 
		return QFileInfo_isDir(pObject)

	Func isExecutable 
		return QFileInfo_isExecutable(pObject)

	Func isFile 
		return QFileInfo_isFile(pObject)

	Func isHidden 
		return QFileInfo_isHidden(pObject)

	Func isNativePath 
		return QFileInfo_isNativePath(pObject)

	Func isReadable 
		return QFileInfo_isReadable(pObject)

	Func isRelative 
		return QFileInfo_isRelative(pObject)

	Func isRoot 
		return QFileInfo_isRoot(pObject)

	Func isSymLink 
		return QFileInfo_isSymLink(pObject)

	Func isWritable 
		return QFileInfo_isWritable(pObject)

	Func lastModified 
		pTempObj = new QDateTime
		pTempObj.pObject = QFileInfo_lastModified(pObject)
		return pTempObj

	Func lastRead 
		pTempObj = new QDateTime
		pTempObj.pObject = QFileInfo_lastRead(pObject)
		return pTempObj

	Func makeAbsolute 
		return QFileInfo_makeAbsolute(pObject)

	Func owner 
		return QFileInfo_owner(pObject)

	Func ownerId 
		return QFileInfo_ownerId(pObject)

	Func path 
		return QFileInfo_path(pObject)

	Func permission P1
		return QFileInfo_permission(pObject,P1)

	Func permissions 
		return QFileInfo_permissions(pObject)

	Func refresh 
		return QFileInfo_refresh(pObject)

	Func setCaching P1
		return QFileInfo_setCaching(pObject,P1)

	Func setFile P1
		return QFileInfo_setFile(pObject,P1)

	Func size 
		return QFileInfo_size(pObject)

	Func suffix 
		return QFileInfo_suffix(pObject)

	Func swap P1
		return QFileInfo_swap(pObject,GetObjectPointerFromRingObject(P1))

	Func symLinkTarget 
		return QFileInfo_symLinkTarget(pObject)

Class QStringList

	pObject

	Func init 
		pObject = QStringList_new()
		return self

	Func delete
		pObject = QStringList_delete(pObject)

	Func ObjectPointer
		return pObject

	Func join P1
		return QStringList_join(pObject,P1)

	Func sort 
		return QStringList_sort(pObject)

	Func removeDuplicates 
		return QStringList_removeDuplicates(pObject)

	Func filter P1,P2
		pTempObj = new QStringList
		pTempObj.pObject = QStringList_filter(pObject,P1,P2)
		return pTempObj

	Func replaceInStrings P1,P2,P3
		pTempObj = new QStringList
		pTempObj.pObject = QStringList_replaceInStrings(pObject,P1,P2,P3)
		return pTempObj

	Func append P1
		return QStringList_append(pObject,P1)

	Func at P1
		return QStringList_at(pObject,P1)

	Func back 
		return QStringList_back(pObject)

	Func clear 
		return QStringList_clear(pObject)

	Func contains P1
		return QStringList_contains(pObject,P1)

	Func count 
		return QStringList_count(pObject)

	Func empty 
		return QStringList_empty(pObject)

	Func endsWith P1
		return QStringList_endsWith(pObject,P1)

	Func first 
		return QStringList_first(pObject)

	Func front 
		return QStringList_front(pObject)

	Func indexOf P1,P2
		return QStringList_indexOf(pObject,P1,P2)

	Func insert P1,P2
		return QStringList_insert(pObject,P1,P2)

	Func isEmpty 
		return QStringList_isEmpty(pObject)

	Func last 
		return QStringList_last(pObject)

	Func lastIndexOf P1,P2
		return QStringList_lastIndexOf(pObject,P1,P2)

	Func length 
		return QStringList_length(pObject)

	Func move P1,P2
		return QStringList_move(pObject,P1,P2)

	Func pop_back 
		return QStringList_pop_back(pObject)

	Func pop_front 
		return QStringList_pop_front(pObject)

	Func prepend P1
		return QStringList_prepend(pObject,P1)

	Func push_back P1
		return QStringList_push_back(pObject,P1)

	Func push_front P1
		return QStringList_push_front(pObject,P1)

	Func removeAll P1
		return QStringList_removeAll(pObject,P1)

	Func removeAt P1
		return QStringList_removeAt(pObject,P1)

	Func removeFirst 
		return QStringList_removeFirst(pObject)

	Func removeLast 
		return QStringList_removeLast(pObject)

	Func removeOne P1
		return QStringList_removeOne(pObject,P1)

	Func replace P1,P2
		return QStringList_replace(pObject,P1,P2)

	Func reserve P1
		return QStringList_reserve(pObject,P1)

	Func size 
		return QStringList_size(pObject)

	Func startsWith P1
		return QStringList_startsWith(pObject,P1)

	Func takeAt P1
		return QStringList_takeAt(pObject,P1)

	Func takeFirst 
		return QStringList_takeFirst(pObject)

	Func takeLast 
		return QStringList_takeLast(pObject)

	Func value P1
		return QStringList_value(pObject,P1)

Class QTime

	pObject

	Func init 
		pObject = QTime_new()
		return self

	Func delete
		pObject = QTime_delete(pObject)

	Func ObjectPointer
		return pObject

	Func addMSecs P1
		pTempObj = new QTime
		pTempObj.pObject = QTime_addMSecs(pObject,P1)
		return pTempObj

	Func addSecs P1
		pTempObj = new QTime
		pTempObj.pObject = QTime_addSecs(pObject,P1)
		return pTempObj

	Func hour 
		return QTime_hour(pObject)

	Func isNull 
		return QTime_isNull(pObject)

	Func isValid 
		return QTime_isValid(pObject)

	Func minute 
		return QTime_minute(pObject)

	Func msec 
		return QTime_msec(pObject)

	Func msecsSinceStartOfDay 
		return QTime_msecsSinceStartOfDay(pObject)

	Func msecsTo P1
		return QTime_msecsTo(pObject,GetObjectPointerFromRingObject(P1))

	Func second 
		return QTime_second(pObject)

	Func secsTo P1
		return QTime_secsTo(pObject,GetObjectPointerFromRingObject(P1))

	Func setHMS P1,P2,P3,P4
		return QTime_setHMS(pObject,P1,P2,P3,P4)

	Func toString P1
		return QTime_toString(pObject,P1)

	Func currentTime 
		pTempObj = new QTime
		pTempObj.pObject = QTime_currentTime(pObject)
		return pTempObj

	Func fromMSecsSinceStartOfDay P1
		pTempObj = new QTime
		pTempObj.pObject = QTime_fromMSecsSinceStartOfDay(pObject,P1)
		return pTempObj

	Func fromString P1,P2
		pTempObj = new QTime
		pTempObj.pObject = QTime_fromString(pObject,P1,P2)
		return pTempObj

Class QDate

	pObject

	Func init 
		pObject = QDate_new()
		return self

	Func delete
		pObject = QDate_delete(pObject)

	Func ObjectPointer
		return pObject

	Func addDays P1
		pTempObj = new QDate
		pTempObj.pObject = QDate_addDays(pObject,P1)
		return pTempObj

	Func addMonths P1
		pTempObj = new QDate
		pTempObj.pObject = QDate_addMonths(pObject,P1)
		return pTempObj

	Func addYears P1
		pTempObj = new QDate
		pTempObj.pObject = QDate_addYears(pObject,P1)
		return pTempObj

	Func day 
		return QDate_day(pObject)

	Func dayOfWeek 
		return QDate_dayOfWeek(pObject)

	Func dayOfYear 
		return QDate_dayOfYear(pObject)

	Func daysInMonth 
		return QDate_daysInMonth(pObject)

	Func daysInYear 
		return QDate_daysInYear(pObject)

	Func daysTo P1
		return QDate_daysTo(pObject,GetObjectPointerFromRingObject(P1))

	Func getDate P1,P2,P3
		return QDate_getDate(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2),GetObjectPointerFromRingObject(P3))

	Func isNull 
		return QDate_isNull(pObject)

	Func isValid 
		return QDate_isValid(pObject)

	Func month 
		return QDate_month(pObject)

	Func setDate P1,P2,P3
		return QDate_setDate(pObject,P1,P2,P3)

	Func toJulianDay 
		return QDate_toJulianDay(pObject)

	Func toString P1
		return QDate_toString(pObject,P1)

	Func weekNumber P1
		return QDate_weekNumber(pObject,GetObjectPointerFromRingObject(P1))

	Func year 
		return QDate_year(pObject)

	Func currentDate 
		pTempObj = new QDate
		pTempObj.pObject = QDate_currentDate(pObject)
		return pTempObj

	Func fromJulianDay P1
		pTempObj = new QDate
		pTempObj.pObject = QDate_fromJulianDay(pObject,P1)
		return pTempObj

	Func fromString P1,P2
		pTempObj = new QDate
		pTempObj.pObject = QDate_fromString(pObject,P1,P2)
		return pTempObj

	Func isLeapYear P1
		return QDate_isLeapYear(pObject,P1)

Class QVariant

	pObject

	Func init 
		pObject = QVariant_new()
		return self

	Func delete
		pObject = QVariant_delete(pObject)

	Func ObjectPointer
		return pObject

	Func canConvert P1
		return QVariant_canConvert(pObject,P1)

	Func clear 
		return QVariant_clear(pObject)

	Func convert P1
		return QVariant_convert(pObject,P1)

	Func isNull 
		return QVariant_isNull(pObject)

	Func isValid 
		return QVariant_isValid(pObject)

	Func swap P1
		return QVariant_swap(pObject,GetObjectPointerFromRingObject(P1))

	Func toBitArray 
		return QVariant_toBitArray(pObject)

	Func toBool 
		return QVariant_toBool(pObject)

	Func toByteArray 
		pTempObj = new QByteArray
		pTempObj.pObject = QVariant_toByteArray(pObject)
		return pTempObj

	Func toChar 
		pTempObj = new QChar
		pTempObj.pObject = QVariant_toChar(pObject)
		return pTempObj

	Func toDate 
		pTempObj = new QDate
		pTempObj.pObject = QVariant_toDate(pObject)
		return pTempObj

	Func toDateTime 
		pTempObj = new QDateTime
		pTempObj.pObject = QVariant_toDateTime(pObject)
		return pTempObj

	Func toDouble P1
		return QVariant_toDouble(pObject,GetObjectPointerFromRingObject(P1))

	Func toEasingCurve 
		return QVariant_toEasingCurve(pObject)

	Func toFloat P1
		return QVariant_toFloat(pObject,GetObjectPointerFromRingObject(P1))

	Func toInt P1
		return QVariant_toInt(pObject,GetObjectPointerFromRingObject(P1))

	Func toJsonArray 
		pTempObj = new QJsonArray
		pTempObj.pObject = QVariant_toJsonArray(pObject)
		return pTempObj

	Func toJsonDocument 
		pTempObj = new QJsonDocument
		pTempObj.pObject = QVariant_toJsonDocument(pObject)
		return pTempObj

	Func toJsonObject 
		pTempObj = new QJsonObject
		pTempObj.pObject = QVariant_toJsonObject(pObject)
		return pTempObj

	Func toJsonValue 
		pTempObj = new QJsonValue
		pTempObj.pObject = QVariant_toJsonValue(pObject)
		return pTempObj

	Func toLine 
		return QVariant_toLine(pObject)

	Func toLineF 
		return QVariant_toLineF(pObject)

	Func toLocale 
		pTempObj = new QLocale
		pTempObj.pObject = QVariant_toLocale(pObject)
		return pTempObj

	Func toLongLong P1
		return QVariant_toLongLong(pObject,GetObjectPointerFromRingObject(P1))

	Func toModelIndex 
		return QVariant_toModelIndex(pObject)

	Func toPoint 
		return QVariant_toPoint(pObject)

	Func toPointF 
		return QVariant_toPointF(pObject)

	Func toReal P1
		return QVariant_toReal(pObject,GetObjectPointerFromRingObject(P1))

	Func toRect 
		return QVariant_toRect(pObject)

	Func toRectF 
		return QVariant_toRectF(pObject)

	Func toSize 
		pTempObj = new QSize
		pTempObj.pObject = QVariant_toSize(pObject)
		return pTempObj

	Func toSizeF 
		return QVariant_toSizeF(pObject)

	Func toStringList 
		pTempObj = new QStringList
		pTempObj.pObject = QVariant_toStringList(pObject)
		return pTempObj

	Func toTime 
		pTempObj = new QTime
		pTempObj.pObject = QVariant_toTime(pObject)
		return pTempObj

	Func toUInt P1
		return QVariant_toUInt(pObject,GetObjectPointerFromRingObject(P1))

	Func toULongLong P1
		return QVariant_toULongLong(pObject,GetObjectPointerFromRingObject(P1))

	Func toUrl 
		pTempObj = new QUrl
		pTempObj.pObject = QVariant_toUrl(pObject)
		return pTempObj

	Func toUuid 
		pTempObj = new QUuid
		pTempObj.pObject = QVariant_toUuid(pObject)
		return pTempObj

	Func type 
		return QVariant_type(pObject)

	Func typeName 
		return QVariant_typeName(pObject)

	Func userType 
		return QVariant_userType(pObject)

	Func toString 
		return QVariant_toString(pObject)

Class QJsonArray

	pObject

	Func init 
		pObject = QJsonArray_new()
		return self

	Func delete
		pObject = QJsonArray_delete(pObject)

	Func ObjectPointer
		return pObject

	Func append P1
		return QJsonArray_append(pObject,GetObjectPointerFromRingObject(P1))

	Func at P1
		pTempObj = new QJsonValue
		pTempObj.pObject = QJsonArray_at(pObject,P1)
		return pTempObj

	Func contains P1
		return QJsonArray_contains(pObject,GetObjectPointerFromRingObject(P1))

	Func count 
		return QJsonArray_count(pObject)

	Func empty 
		return QJsonArray_empty(pObject)

	Func first 
		pTempObj = new QJsonValue
		pTempObj.pObject = QJsonArray_first(pObject)
		return pTempObj

	Func insert P1,P2
		return QJsonArray_insert(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func isEmpty 
		return QJsonArray_isEmpty(pObject)

	Func last 
		pTempObj = new QJsonValue
		pTempObj.pObject = QJsonArray_last(pObject)
		return pTempObj

	Func pop_back 
		return QJsonArray_pop_back(pObject)

	Func pop_front 
		return QJsonArray_pop_front(pObject)

	Func prepend P1
		return QJsonArray_prepend(pObject,GetObjectPointerFromRingObject(P1))

	Func push_back P1
		return QJsonArray_push_back(pObject,GetObjectPointerFromRingObject(P1))

	Func push_front P1
		return QJsonArray_push_front(pObject,GetObjectPointerFromRingObject(P1))

	Func removeAt P1
		return QJsonArray_removeAt(pObject,P1)

	Func removeFirst 
		return QJsonArray_removeFirst(pObject)

	Func removeLast 
		return QJsonArray_removeLast(pObject)

	Func replace P1,P2
		return QJsonArray_replace(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func size 
		return QJsonArray_size(pObject)

	Func takeAt P1
		pTempObj = new QJsonValue
		pTempObj.pObject = QJsonArray_takeAt(pObject,P1)
		return pTempObj

	Func toVariantList 
		return QJsonArray_toVariantList(pObject)

	Func fromStringList P1
		pTempObj = new QJsonArray
		pTempObj.pObject = QJsonArray_fromStringList(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

	Func fromVariantList P1
		pTempObj = new QJsonArray
		pTempObj.pObject = QJsonArray_fromVariantList(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

Class QJsonDocument

	pObject

	Func init 
		pObject = QJsonDocument_new()
		return self

	Func delete
		pObject = QJsonDocument_delete(pObject)

	Func ObjectPointer
		return pObject

	Func array 
		pTempObj = new QJsonArray
		pTempObj.pObject = QJsonDocument_array(pObject)
		return pTempObj

	Func isArray 
		return QJsonDocument_isArray(pObject)

	Func isEmpty 
		return QJsonDocument_isEmpty(pObject)

	Func isNull 
		return QJsonDocument_isNull(pObject)

	Func isObject 
		return QJsonDocument_isObject(pObject)

	Func object 
		pTempObj = new QJsonObject
		pTempObj.pObject = QJsonDocument_object(pObject)
		return pTempObj

	Func setArray P1
		return QJsonDocument_setArray(pObject,GetObjectPointerFromRingObject(P1))

	Func setObject P1
		return QJsonDocument_setObject(pObject,GetObjectPointerFromRingObject(P1))

	Func toJson P1
		pTempObj = new QByteArray
		pTempObj.pObject = QJsonDocument_toJson(pObject,P1)
		return pTempObj

	Func toVariant 
		pTempObj = new QVariant
		pTempObj.pObject = QJsonDocument_toVariant(pObject)
		return pTempObj

	Func fromJson P1,P2
		pTempObj = new QJsonDocument
		pTempObj.pObject = QJsonDocument_fromJson(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2))
		return pTempObj

	Func fromVariant P1
		pTempObj = new QJsonDocument
		pTempObj.pObject = QJsonDocument_fromVariant(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

Class QJsonObject

	pObject

	Func init 
		pObject = QJsonObject_new()
		return self

	Func delete
		pObject = QJsonObject_delete(pObject)

	Func ObjectPointer
		return pObject

	Func contains P1
		return QJsonObject_contains(pObject,P1)

	Func count 
		return QJsonObject_count(pObject)

	Func empty 
		return QJsonObject_empty(pObject)

	Func isEmpty 
		return QJsonObject_isEmpty(pObject)

	Func keys 
		pTempObj = new QStringList
		pTempObj.pObject = QJsonObject_keys(pObject)
		return pTempObj

	Func length 
		return QJsonObject_length(pObject)

	Func remove P1
		return QJsonObject_remove(pObject,P1)

	Func size 
		return QJsonObject_size(pObject)

	Func take P1
		pTempObj = new QJsonValue
		pTempObj.pObject = QJsonObject_take(pObject,P1)
		return pTempObj

	Func toVariantMap 
		return QJsonObject_toVariantMap(pObject)

	Func value P1
		pTempObj = new QJsonValue
		pTempObj.pObject = QJsonObject_value(pObject,P1)
		return pTempObj

	Func fromVariantMap P1
		pTempObj = new QJsonObject
		pTempObj.pObject = QJsonObject_fromVariantMap(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

Class QJsonParseError

	pObject

	Func init 
		pObject = QJsonParseError_new()
		return self

	Func delete
		pObject = QJsonParseError_delete(pObject)

	Func ObjectPointer
		return pObject

	Func errorString 
		return QJsonParseError_errorString(pObject)

Class QJsonValue

	pObject

	Func init 
		pObject = QJsonValue_new()
		return self

	Func delete
		pObject = QJsonValue_delete(pObject)

	Func ObjectPointer
		return pObject

	Func isArray 
		return QJsonValue_isArray(pObject)

	Func isBool 
		return QJsonValue_isBool(pObject)

	Func isDouble 
		return QJsonValue_isDouble(pObject)

	Func isNull 
		return QJsonValue_isNull(pObject)

	Func isObject 
		return QJsonValue_isObject(pObject)

	Func isString 
		return QJsonValue_isString(pObject)

	Func isUndefined 
		return QJsonValue_isUndefined(pObject)

	Func toArray P1
		pTempObj = new QJsonArray
		pTempObj.pObject = QJsonValue_toArray(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

	Func toArray_2 
		pTempObj = new QJsonArray
		pTempObj.pObject = QJsonValue_toArray_2(pObject)
		return pTempObj

	Func toBool P1
		return QJsonValue_toBool(pObject,P1)

	Func toDouble P1
		return QJsonValue_toDouble(pObject,P1)

	Func toInt P1
		return QJsonValue_toInt(pObject,P1)

	Func toObject P1
		pTempObj = new QJsonObject
		pTempObj.pObject = QJsonValue_toObject(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

	Func toObject_2 
		pTempObj = new QJsonObject
		pTempObj.pObject = QJsonValue_toObject_2(pObject)
		return pTempObj

	Func toString P1
		return QJsonValue_toString(pObject,P1)

	Func toVariant 
		pTempObj = new QVariant
		pTempObj.pObject = QJsonValue_toVariant(pObject)
		return pTempObj

	Func type 
		return QJsonValue_type(pObject)

	Func fromVariant P1
		pTempObj = new QJsonValue
		pTempObj.pObject = QJsonValue_fromVariant(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

Class QString2

	pObject

	Func init 
		pObject = QString2_new()
		return self

	Func delete
		pObject = QString2_delete(pObject)

	Func ObjectPointer
		return pObject

	Func split P1,P2,P3
		pTempObj = new QStringList
		pTempObj.pObject = QString2_split(pObject,P1,P2,P3)
		return pTempObj

	Func split_2 P1,P2,P3
		pTempObj = new QStringList
		pTempObj.pObject = QString2_split_2(pObject,GetObjectPointerFromRingObject(P1),P2,P3)
		return pTempObj

	Func split_4 P1,P2
		pTempObj = new QStringList
		pTempObj.pObject = QString2_split_4(pObject,GetObjectPointerFromRingObject(P1),P2)
		return pTempObj

	Func append P1
		return QString2_append(pObject,P1)

	Func append_2 P1
		return QString2_append_2(pObject,GetObjectPointerFromRingObject(P1))

	Func toUtf8 
		pTempObj = new QByteArray
		pTempObj.pObject = QString2_toUtf8(pObject)
		return pTempObj

	Func toLatin1 
		pTempObj = new QByteArray
		pTempObj.pObject = QString2_toLatin1(pObject)
		return pTempObj

	Func toLocal8Bit 
		pTempObj = new QByteArray
		pTempObj.pObject = QString2_toLocal8Bit(pObject)
		return pTempObj

	Func unicode 
		pTempObj = new QChar
		pTempObj.pObject = QString2_unicode(pObject)
		return pTempObj

	Func number P1,P2
		return QString2_number(pObject,P1,P2)

	Func count 
		return QString2_count(pObject)

	Func left P1
		return QString2_left(pObject,P1)

	Func mid P1,P2
		return QString2_mid(pObject,P1,P2)

	Func right P1
		return QString2_right(pObject,P1)

	Func compare P1,P2
		return QString2_compare(pObject,P1,P2)

	Func contains P1,P2
		return QString2_contains(pObject,P1,P2)

	Func indexOf P1,P2,P3
		return QString2_indexOf(pObject,P1,P2,P3)

	Func lastIndexOf P1,P2,P3
		return QString2_lastIndexOf(pObject,P1,P2,P3)

	Func insert P1,P2
		return QString2_insert(pObject,P1,P2)

	Func isRightToLeft 
		return QString2_isRightToLeft(pObject)

	Func repeated P1
		return QString2_repeated(pObject,P1)

	Func replace P1,P2,P3
		return QString2_replace(pObject,P1,P2,P3)

	Func replace_2 P1,P2,P3
		return QString2_replace_2(pObject,P1,P2,P3)

	Func startsWith P1,P2
		return QString2_startsWith(pObject,P1,P2)

	Func endsWith P1,P2
		return QString2_endsWith(pObject,P1,P2)

	Func toHtmlEscaped 
		return QString2_toHtmlEscaped(pObject)

	Func clear 
		return QString2_clear(pObject)

	Func isNull 
		return QString2_isNull(pObject)

	Func resize P1
		return QString2_resize(pObject,P1)

	Func fill P1,P2
		return QString2_fill(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func localeAwareCompare P1
		return QString2_localeAwareCompare(pObject,P1)

	Func leftJustified P1,P2,P3
		return QString2_leftJustified(pObject,P1,GetObjectPointerFromRingObject(P2),P3)

	Func rightJustified P1,P2,P3
		return QString2_rightJustified(pObject,P1,GetObjectPointerFromRingObject(P2),P3)

	Func section_1 P1,P2,P3,P4
		return QString2_section_1(pObject,GetObjectPointerFromRingObject(P1),P2,P3,GetObjectPointerFromRingObject(P4))

	Func section_2 P1,P2,P3,P4
		return QString2_section_2(pObject,P1,P2,P3,GetObjectPointerFromRingObject(P4))

	Func section_4 P1,P2,P3,P4
		return QString2_section_4(pObject,GetObjectPointerFromRingObject(P1),P2,P3,GetObjectPointerFromRingObject(P4))

	Func simplified 
		return QString2_simplified(pObject)

	Func toCaseFolded 
		return QString2_toCaseFolded(pObject)

	Func trimmed 
		return QString2_trimmed(pObject)

	Func truncate P1
		return QString2_truncate(pObject,P1)

	Func length 
		return QString2_length(pObject)

	Func size 
		return QString2_size(pObject)

Class QBuffer from QIODevice

	pObject

	Func init P1
		pObject = QBuffer_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QBuffer_delete(pObject)

	Func ObjectPointer
		return pObject

	Func buffer 
		pTempObj = new QByteArray
		pTempObj.pObject = QBuffer_buffer(pObject)
		return pTempObj

	Func data 
		pTempObj = new QByteArray
		pTempObj.pObject = QBuffer_data(pObject)
		return pTempObj

	Func setBuffer P1
		return QBuffer_setBuffer(pObject,GetObjectPointerFromRingObject(P1))

	Func setData P1
		return QBuffer_setData(pObject,GetObjectPointerFromRingObject(P1))

	Func setData_2 P1,P2
		return QBuffer_setData_2(pObject,P1,P2)

Class QDateTime

	pObject

	Func init 
		pObject = QDateTime_new()
		return self

	Func delete
		pObject = QDateTime_delete(pObject)

	Func ObjectPointer
		return pObject

	Func addDays P1
		pTempObj = new QDateTime
		pTempObj.pObject = QDateTime_addDays(pObject,P1)
		return pTempObj

	Func addMSecs P1
		pTempObj = new QDateTime
		pTempObj.pObject = QDateTime_addMSecs(pObject,P1)
		return pTempObj

	Func addMonths P1
		pTempObj = new QDateTime
		pTempObj.pObject = QDateTime_addMonths(pObject,P1)
		return pTempObj

	Func addSecs P1
		pTempObj = new QDateTime
		pTempObj.pObject = QDateTime_addSecs(pObject,P1)
		return pTempObj

	Func addYears P1
		pTempObj = new QDateTime
		pTempObj.pObject = QDateTime_addYears(pObject,P1)
		return pTempObj

	Func date 
		pTempObj = new QDate
		pTempObj.pObject = QDateTime_date(pObject)
		return pTempObj

	Func daysTo P1
		return QDateTime_daysTo(pObject,GetObjectPointerFromRingObject(P1))

	Func isNull 
		return QDateTime_isNull(pObject)

	Func isValid 
		return QDateTime_isValid(pObject)

	Func msecsTo P1
		return QDateTime_msecsTo(pObject,GetObjectPointerFromRingObject(P1))

	Func secsTo P1
		return QDateTime_secsTo(pObject,GetObjectPointerFromRingObject(P1))

	Func setDate P1
		return QDateTime_setDate(pObject,GetObjectPointerFromRingObject(P1))

	Func setMSecsSinceEpoch P1
		return QDateTime_setMSecsSinceEpoch(pObject,P1)

	Func setTime P1
		return QDateTime_setTime(pObject,GetObjectPointerFromRingObject(P1))

	Func setTimeSpec P1
		return QDateTime_setTimeSpec(pObject,P1)

	Func time 
		pTempObj = new QTime
		pTempObj.pObject = QDateTime_time(pObject)
		return pTempObj

	Func timeSpec 
		return QDateTime_timeSpec(pObject)

	Func toLocalTime 
		pTempObj = new QDateTime
		pTempObj.pObject = QDateTime_toLocalTime(pObject)
		return pTempObj

	Func toMSecsSinceEpoch 
		return QDateTime_toMSecsSinceEpoch(pObject)

	Func toString P1
		return QDateTime_toString(pObject,P1)

	Func toString_2 P1
		return QDateTime_toString_2(pObject,P1)

	Func toTimeSpec P1
		pTempObj = new QDateTime
		pTempObj.pObject = QDateTime_toTimeSpec(pObject,P1)
		return pTempObj

	Func toUTC 
		pTempObj = new QDateTime
		pTempObj.pObject = QDateTime_toUTC(pObject)
		return pTempObj

	Func currentDateTime 
		pTempObj = new QDateTime
		pTempObj.pObject = QDateTime_currentDateTime(pObject)
		return pTempObj

	Func currentDateTimeUtc 
		pTempObj = new QDateTime
		pTempObj.pObject = QDateTime_currentDateTimeUtc(pObject)
		return pTempObj

	Func currentMSecsSinceEpoch 
		return QDateTime_currentMSecsSinceEpoch(pObject)

	Func fromMSecsSinceEpoch P1
		pTempObj = new QDateTime
		pTempObj.pObject = QDateTime_fromMSecsSinceEpoch(pObject,P1)
		return pTempObj

	Func fromString P1,P2
		pTempObj = new QDateTime
		pTempObj.pObject = QDateTime_fromString(pObject,P1,P2)
		return pTempObj

	Func fromString_2 P1,P2
		pTempObj = new QDateTime
		pTempObj.pObject = QDateTime_fromString_2(pObject,P1,P2)
		return pTempObj

Class QCoreApplication from QObject

	pObject


	Func installNativeEventFilter P1
		return QCoreApplication_installNativeEventFilter(GetObjectPointerFromRingObject(P1))

	Func removeNativeEventFilter P1
		return QCoreApplication_removeNativeEventFilter(GetObjectPointerFromRingObject(P1))

	Func quit 
		return QCoreApplication_quit()

	Func addLibraryPath P1
		return QCoreApplication_addLibraryPath(P1)

	Func applicationDirPath 
		return QCoreApplication_applicationDirPath()

	Func applicationFilePath 
		return QCoreApplication_applicationFilePath()

	Func applicationName 
		return QCoreApplication_applicationName()

	Func applicationPid 
		return QCoreApplication_applicationPid()

	Func applicationVersion 
		return QCoreApplication_applicationVersion()

	Func arguments 
		pTempObj = new QStringList
		pTempObj.pObject = QCoreApplication_arguments()
		return pTempObj

	Func closingDown 
		return QCoreApplication_closingDown()

	Func eventDispatcher 
		return QCoreApplication_eventDispatcher()

	Func exec 
		return QCoreApplication_exec()

	Func exitfromapplication P1
		return QCoreApplication_exit(P1)

	Func installTranslator P1
		return QCoreApplication_installTranslator(GetObjectPointerFromRingObject(P1))

	Func instance 
		return QCoreApplication_instance()

	Func isQuitLockEnabled 
		return QCoreApplication_isQuitLockEnabled()

	Func libraryPaths 
		pTempObj = new QStringList
		pTempObj.pObject = QCoreApplication_libraryPaths()
		return pTempObj

	Func organizationDomain 
		return QCoreApplication_organizationDomain()

	Func organizationName 
		return QCoreApplication_organizationName()

	Func postEvent P1,P2,P3
		return QCoreApplication_postEvent(GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2),P3)

	Func processEvents P1
		return QCoreApplication_processEvents(P1)

	Func processEvents_2 P1,P2
		return QCoreApplication_processEvents_2(P1,P2)

	Func removeLibraryPath P1
		return QCoreApplication_removeLibraryPath(P1)

	Func removePostedEvents P1,P2
		return QCoreApplication_removePostedEvents(GetObjectPointerFromRingObject(P1),P2)

	Func removeTranslator P1
		return QCoreApplication_removeTranslator(GetObjectPointerFromRingObject(P1))

	Func sendEvent P1,P2
		return QCoreApplication_sendEvent(GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2))

	Func sendPostedEvents P1,P2
		return QCoreApplication_sendPostedEvents(GetObjectPointerFromRingObject(P1),P2)

	Func setApplicationName P1
		return QCoreApplication_setApplicationName(P1)

	Func setApplicationVersion P1
		return QCoreApplication_setApplicationVersion(P1)

	Func setAttribute P1,P2
		return QCoreApplication_setAttribute(P1,P2)

	Func setEventDispatcher P1
		return QCoreApplication_setEventDispatcher(GetObjectPointerFromRingObject(P1))

	Func setLibraryPaths P1
		return QCoreApplication_setLibraryPaths(GetObjectPointerFromRingObject(P1))

	Func setOrganizationDomain P1
		return QCoreApplication_setOrganizationDomain(P1)

	Func setOrganizationName P1
		return QCoreApplication_setOrganizationName(P1)

	Func setQuitLockEnabled P1
		return QCoreApplication_setQuitLockEnabled(P1)

	Func startingUp 
		return QCoreApplication_startingUp()

	Func testAttribute P1
		return QCoreApplication_testAttribute(P1)

	Func translate P1,P2,P3,P4
		return QCoreApplication_translate(P1,P2,P3,P4)

Class QFile from QFileDevice

	pObject

	Func init 
		pObject = QFile_new()
		return self

	Func delete
		pObject = QFile_delete(pObject)

	Func ObjectPointer
		return pObject

	Func copy P1
		return QFile_copy(pObject,P1)

	Func exists 
		return QFile_exists(pObject)

	Func link P1
		return QFile_link(pObject,P1)

	Func open P1,P2,P3
		return QFile_open(pObject,GetObjectPointerFromRingObject(P1),P2,P3)

	Func open_2 P1,P2,P3
		return QFile_open_2(pObject,P1,P2,P3)

	Func open_3 P1
		return QFile_open_3(pObject,P1)

	Func remove 
		return QFile_remove(pObject)

	Func rename P1
		return QFile_rename(pObject,P1)

	Func setFileName P1
		return QFile_setFileName(pObject,P1)

	Func symLinkTarget 
		return QFile_symLinkTarget(pObject)

	Func copy_2 P1,P2
		return QFile_copy_2(pObject,P1,P2)

	Func decodeName P1
		return QFile_decodeName(pObject,GetObjectPointerFromRingObject(P1))

	Func decodeName_2 P1
		return QFile_decodeName_2(pObject,P1)

	Func encodeName P1
		pTempObj = new QByteArray
		pTempObj.pObject = QFile_encodeName(pObject,P1)
		return pTempObj

	Func exists_2 P1
		return QFile_exists_2(pObject,P1)

	Func link_2 P1,P2
		return QFile_link_2(pObject,P1,P2)

	Func permissions P1
		return QFile_permissions(pObject,P1)

	Func remove_2 P1
		return QFile_remove_2(pObject,P1)

	Func rename_2 P1,P2
		return QFile_rename_2(pObject,P1,P2)

	Func resize P1,P2
		return QFile_resize(pObject,P1,P2)

	Func setPermissions P1,P2
		return QFile_setPermissions(pObject,P1,P2)

	Func symLinkTarget_2 P1
		return QFile_symLinkTarget_2(pObject,P1)

Class QFileDevice from QIODevice

	pObject


	Func error 
		return QFileDevice_error()

	Func flush 
		return QFileDevice_flush()

	Func handle 
		return QFileDevice_handle()

	Func map P1,P2,P3
		return QFileDevice_map(P1,P2,P3)

	Func permissions 
		return QFileDevice_permissions()

	Func resize P1
		return QFileDevice_resize(P1)

	Func fileName 
		return QFileDevice_fileName()

	Func setPermissions P1
		return QFileDevice_setPermissions(P1)

	Func unmap P1
		return QFileDevice_unmap(GetObjectPointerFromRingObject(P1))

	Func unsetError 
		return QFileDevice_unsetError()

Class QStandardPaths

	pObject


	Func displayName P1
		return QStandardPaths_displayName(P1)

	Func findExecutable P1,P2
		return QStandardPaths_findExecutable(P1,GetObjectPointerFromRingObject(P2))

	Func locate P1,P2,P3
		return QStandardPaths_locate(P1,P2,P3)

	Func locateAll P1,P2,P3
		pTempObj = new QStringList
		pTempObj.pObject = QStandardPaths_locateAll(P1,P2,P3)
		return pTempObj

	Func setTestModeEnabled P1
		return QStandardPaths_setTestModeEnabled(P1)

	Func standardLocations P1
		pTempObj = new QStringList
		pTempObj.pObject = QStandardPaths_standardLocations(P1)
		return pTempObj

	Func writableLocation P1
		return QStandardPaths_writableLocation(P1)

Class QMimeData from QObject

	pObject

	Func init 
		pObject = QMimeData_new()
		return self

	Func delete
		pObject = QMimeData_delete(pObject)

	Func ObjectPointer
		return pObject

	Func clear 
		return QMimeData_clear(pObject)

	Func colorData 
		pTempObj = new QVariant
		pTempObj.pObject = QMimeData_colorData(pObject)
		return pTempObj

	Func data P1
		pTempObj = new QByteArray
		pTempObj.pObject = QMimeData_data(pObject,P1)
		return pTempObj

	Func formats 
		pTempObj = new QStringList
		pTempObj.pObject = QMimeData_formats(pObject)
		return pTempObj

	Func hasColor 
		return QMimeData_hasColor(pObject)

	Func hasFormat P1
		return QMimeData_hasFormat(pObject,P1)

	Func hasHtml 
		return QMimeData_hasHtml(pObject)

	Func hasImage 
		return QMimeData_hasImage(pObject)

	Func hasText 
		return QMimeData_hasText(pObject)

	Func hasUrls 
		return QMimeData_hasUrls(pObject)

	Func html 
		return QMimeData_html(pObject)

	Func imageData 
		pTempObj = new QVariant
		pTempObj.pObject = QMimeData_imageData(pObject)
		return pTempObj

	Func removeFormat P1
		return QMimeData_removeFormat(pObject,P1)

	Func setColorData P1
		return QMimeData_setColorData(pObject,GetObjectPointerFromRingObject(P1))

	Func setData P1,P2
		return QMimeData_setData(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func setHtml P1
		return QMimeData_setHtml(pObject,P1)

	Func setImageData P1
		return QMimeData_setImageData(pObject,GetObjectPointerFromRingObject(P1))

	Func setText P1
		return QMimeData_setText(pObject,P1)

	Func setUrls P1
		return QMimeData_setUrls(pObject,GetObjectPointerFromRingObject(P1))

	Func text 
		return QMimeData_text(pObject)

	Func urls 
		return QMimeData_urls(pObject)

Class QChar

	pObject

	Func init P1
		pObject = QChar_new(P1)
		return self

	Func delete
		pObject = QChar_delete(pObject)

	Func ObjectPointer
		return pObject

	Func category 
		return QChar_category(pObject)

	Func cell 
		return QChar_cell(pObject)

	Func combiningClass 
		return QChar_combiningClass(pObject)

	Func decomposition 
		return QChar_decomposition(pObject)

	Func decompositionTag 
		return QChar_decompositionTag(pObject)

	Func digitValue 
		return QChar_digitValue(pObject)

	Func direction 
		return QChar_direction(pObject)

	Func hasMirrored 
		return QChar_hasMirrored(pObject)

	Func isDigit 
		return QChar_isDigit(pObject)

	Func isHighSurrogate 
		return QChar_isHighSurrogate(pObject)

	Func isLetter 
		return QChar_isLetter(pObject)

	Func isLetterOrNumber 
		return QChar_isLetterOrNumber(pObject)

	Func isLowSurrogate 
		return QChar_isLowSurrogate(pObject)

	Func isLower 
		return QChar_isLower(pObject)

	Func isMark 
		return QChar_isMark(pObject)

	Func isNonCharacter 
		return QChar_isNonCharacter(pObject)

	Func isNull 
		return QChar_isNull(pObject)

	Func isNumber 
		return QChar_isNumber(pObject)

	Func isPrint 
		return QChar_isPrint(pObject)

	Func isPunct 
		return QChar_isPunct(pObject)

	Func isSpace 
		return QChar_isSpace(pObject)

	Func isSurrogate 
		return QChar_isSurrogate(pObject)

	Func isSymbol 
		return QChar_isSymbol(pObject)

	Func isTitleCase 
		return QChar_isTitleCase(pObject)

	Func isUpper 
		return QChar_isUpper(pObject)

	Func mirroredChar 
		pTempObj = new QChar
		pTempObj.pObject = QChar_mirroredChar(pObject)
		return pTempObj

	Func row 
		return QChar_row(pObject)

	Func script 
		return QChar_script(pObject)

	Func toCaseFolded 
		pTempObj = new QChar
		pTempObj.pObject = QChar_toCaseFolded(pObject)
		return pTempObj

	Func toLatin1 
		return QChar_toLatin1(pObject)

	Func toLower 
		pTempObj = new QChar
		pTempObj.pObject = QChar_toLower(pObject)
		return pTempObj

	Func toTitleCase 
		pTempObj = new QChar
		pTempObj.pObject = QChar_toTitleCase(pObject)
		return pTempObj

	Func toUpper 
		pTempObj = new QChar
		pTempObj.pObject = QChar_toUpper(pObject)
		return pTempObj

	Func unicode 
		return QChar_unicode(pObject)

	Func unicode_2 
		return QChar_unicode_2(pObject)

	Func unicodeVersion 
		return QChar_unicodeVersion(pObject)

	Func category_2 P1
		return QChar_category_2(pObject,P1)

	Func combiningClass_2 P1
		return QChar_combiningClass_2(pObject,P1)

	Func currentUnicodeVersion 
		return QChar_currentUnicodeVersion(pObject)

	Func decomposition_2 P1
		return QChar_decomposition_2(pObject,P1)

	Func decompositionTag_2 P1
		return QChar_decompositionTag_2(pObject,P1)

	Func digitValue_2 P1
		return QChar_digitValue_2(pObject,P1)

	Func direction_2 P1
		return QChar_direction_2(pObject,P1)

	Func fromLatin1 P1
		pTempObj = new QChar
		pTempObj.pObject = QChar_fromLatin1(pObject,P1)
		return pTempObj

	Func hasMirrored_2 P1
		return QChar_hasMirrored_2(pObject,P1)

	Func highSurrogate P1
		return QChar_highSurrogate(pObject,P1)

	Func isDigit_2 P1
		return QChar_isDigit_2(pObject,P1)

	Func isHighSurrogate_2 P1
		return QChar_isHighSurrogate_2(pObject,P1)

	Func isLetter_2 P1
		return QChar_isLetter_2(pObject,P1)

	Func isLetterOrNumber_2 P1
		return QChar_isLetterOrNumber_2(pObject,P1)

	Func isLowSurrogate_2 P1
		return QChar_isLowSurrogate_2(pObject,P1)

	Func isLower_2 P1
		return QChar_isLower_2(pObject,P1)

	Func isMark_2 P1
		return QChar_isMark_2(pObject,P1)

	Func isNonCharacter_2 P1
		return QChar_isNonCharacter_2(pObject,P1)

	Func isNumber_2 P1
		return QChar_isNumber_2(pObject,P1)

	Func isPrint_2 P1
		return QChar_isPrint_2(pObject,P1)

	Func isPunct_2 P1
		return QChar_isPunct_2(pObject,P1)

	Func isSpace_2 P1
		return QChar_isSpace_2(pObject,P1)

	Func isSurrogate_2 P1
		return QChar_isSurrogate_2(pObject,P1)

	Func isSymbol_2 P1
		return QChar_isSymbol_2(pObject,P1)

	Func isTitleCase_2 P1
		return QChar_isTitleCase_2(pObject,P1)

	Func isUpper_2 P1
		return QChar_isUpper_2(pObject,P1)

	Func lowSurrogate P1
		return QChar_lowSurrogate(pObject,P1)

	Func mirroredChar_2 P1
		return QChar_mirroredChar_2(pObject,P1)

	Func requiresSurrogates P1
		return QChar_requiresSurrogates(pObject,P1)

	Func script_2 P1
		return QChar_script_2(pObject,P1)

	Func surrogateToUcs4 P1,P2
		return QChar_surrogateToUcs4(pObject,P1,P2)

	Func surrogateToUcs4_2 P1,P2
		return QChar_surrogateToUcs4_2(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2))

	Func toCaseFolded_2 P1
		return QChar_toCaseFolded_2(pObject,P1)

	Func toLower_2 P1
		return QChar_toLower_2(pObject,P1)

	Func toTitleCase_2 P1
		return QChar_toTitleCase_2(pObject,P1)

	Func toUpper_2 P1
		return QChar_toUpper_2(pObject,P1)

	Func unicodeVersion_2 P1
		return QChar_unicodeVersion_2(pObject,P1)

Class QChildEvent from QEvent

	pObject

	Func init P1,P2
		pObject = QChildEvent_new(P1,GetObjectPointerFromRingObject(P2))
		return self

	Func delete
		pObject = QChildEvent_delete(pObject)

	Func ObjectPointer
		return pObject

	Func added 
		return QChildEvent_added(pObject)

	Func child 
		pTempObj = new QObject
		pTempObj.pObject = QChildEvent_child(pObject)
		return pTempObj

	Func polished 
		return QChildEvent_polished(pObject)

	Func removed 
		return QChildEvent_removed(pObject)

Class QLocale

	pObject

	Func init P1
		pObject = QLocale_new(P1)
		return self

	Func delete
		pObject = QLocale_delete(pObject)

	Func ObjectPointer
		return pObject

	Func amText 
		return QLocale_amText(pObject)

	Func bcp47Name 
		return QLocale_bcp47Name(pObject)

	Func country 
		return QLocale_country(pObject)

	Func createSeparatedList P1
		return QLocale_createSeparatedList(pObject,GetObjectPointerFromRingObject(P1))

	Func currencySymbol P1
		return QLocale_currencySymbol(pObject,P1)

	Func dateFormat P1
		return QLocale_dateFormat(pObject,P1)

	Func dateTimeFormat P1
		return QLocale_dateTimeFormat(pObject,P1)

	Func dayName P1,P2
		return QLocale_dayName(pObject,P1,P2)

	Func decimalPoint 
		return QLocale_decimalPoint(pObject)

	Func exponential 
		return QLocale_exponential(pObject)

	Func firstDayOfWeek 
		return QLocale_firstDayOfWeek(pObject)

	Func groupSeparator 
		return QLocale_groupSeparator(pObject)

	Func language 
		return QLocale_language(pObject)

	Func measurementSystem 
		return QLocale_measurementSystem(pObject)

	Func monthName P1,P2
		return QLocale_monthName(pObject,P1,P2)

	Func name 
		return QLocale_name(pObject)

	Func nativeCountryName 
		return QLocale_nativeCountryName(pObject)

	Func nativeLanguageName 
		return QLocale_nativeLanguageName(pObject)

	Func negativeSign 
		return QLocale_negativeSign(pObject)

	Func numberOptions 
		return QLocale_numberOptions(pObject)

	Func percent 
		return QLocale_percent(pObject)

	Func pmText 
		return QLocale_pmText(pObject)

	Func positiveSign 
		return QLocale_positiveSign(pObject)

	Func quoteString P1,P2
		return QLocale_quoteString(pObject,P1,P2)

	Func script 
		return QLocale_script(pObject)

	Func setNumberOptions P1
		return QLocale_setNumberOptions(pObject,P1)

	Func standaloneDayName P1,P2
		return QLocale_standaloneDayName(pObject,P1,P2)

	Func standaloneMonthName P1,P2
		return QLocale_standaloneMonthName(pObject,P1,P2)

	Func textDirection 
		return QLocale_textDirection(pObject)

	Func timeFormat P1
		return QLocale_timeFormat(pObject,P1)

	Func toDouble P1,P2
		return QLocale_toDouble(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func toFloat P1,P2
		return QLocale_toFloat(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func toInt P1,P2
		return QLocale_toInt(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func toLongLong P1,P2
		return QLocale_toLongLong(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func toLower P1
		return QLocale_toLower(pObject,P1)

	Func toShort P1,P2
		return QLocale_toShort(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func toString P1
		return QLocale_toString(pObject,GetObjectPointerFromRingObject(P1))

	Func toString_2 P1
		return QLocale_toString_2(pObject,GetObjectPointerFromRingObject(P1))

	Func toString_4 P1
		return QLocale_toString_4(pObject,GetObjectPointerFromRingObject(P1))

	Func toString_5 P1
		return QLocale_toString_5(pObject,P1)

	Func toString_6 P1
		return QLocale_toString_6(pObject,P1)

	Func toString_7 P1
		return QLocale_toString_7(pObject,P1)

	Func toString_8 P1,P2,P3
		return QLocale_toString_8(pObject,P1,P2,P3)

	Func toString_9 P1,P2,P3
		return QLocale_toString_9(pObject,P1,P2,P3)

	Func toString_10 P1,P2
		return QLocale_toString_10(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func toString_11 P1,P2
		return QLocale_toString_11(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func toString_12 P1,P2
		return QLocale_toString_12(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func toString_13 P1,P2
		return QLocale_toString_13(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func toString_14 P1,P2
		return QLocale_toString_14(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func toString_15 P1,P2
		return QLocale_toString_15(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func toTime P1,P2
		pTempObj = new QTime
		pTempObj.pObject = QLocale_toTime(pObject,P1,P2)
		return pTempObj

	Func toTime_2 P1,P2
		pTempObj = new QTime
		pTempObj.pObject = QLocale_toTime_2(pObject,P1,P2)
		return pTempObj

	Func toUInt P1,P2
		return QLocale_toUInt(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func toULongLong P1,P2
		return QLocale_toULongLong(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func toUShort P1,P2
		return QLocale_toUShort(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func toUpper P1
		return QLocale_toUpper(pObject,P1)

	Func uiLanguages 
		pTempObj = new QStringList
		pTempObj.pObject = QLocale_uiLanguages(pObject)
		return pTempObj

	Func weekdays 
		return QLocale_weekdays(pObject)

	Func zeroDigit 
		return QLocale_zeroDigit(pObject)

	Func c 
		pTempObj = new QLocale
		pTempObj.pObject = QLocale_c(pObject)
		return pTempObj

	Func countryToString P1
		return QLocale_countryToString(pObject,P1)

	Func languageToString P1
		return QLocale_languageToString(pObject,P1)

	Func matchingLocales P1,P2,P3
		return QLocale_matchingLocales(pObject,P1,P2,P3)

	Func scriptToString P1
		return QLocale_scriptToString(pObject,P1)

	Func setDefault P1
		return QLocale_setDefault(pObject,GetObjectPointerFromRingObject(P1))

	Func system 
		pTempObj = new QLocale
		pTempObj.pObject = QLocale_system(pObject)
		return pTempObj

Class QThread from QObject

	pObject

	Func init P1
		pObject = QThread_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QThread_delete(pObject)

	Func ObjectPointer
		return pObject

	Func eventDispatcher 
		return QThread_eventDispatcher(pObject)

	Func exitfromthread P1
		return QThread_exit(pObject,P1)

	Func isFinished 
		return QThread_isFinished(pObject)

	Func isInterruptionRequested 
		return QThread_isInterruptionRequested(pObject)

	Func isRunning 
		return QThread_isRunning(pObject)

	Func priority 
		return QThread_priority(pObject)

	Func requestInterruption 
		return QThread_requestInterruption(pObject)

	Func setEventDispatcher P1
		return QThread_setEventDispatcher(pObject,GetObjectPointerFromRingObject(P1))

	Func setPriority P1
		return QThread_setPriority(pObject,P1)

	Func setStackSize P1
		return QThread_setStackSize(pObject,P1)

	Func stackSize 
		return QThread_stackSize(pObject)

	Func wait P1
		return QThread_wait(pObject,GetObjectPointerFromRingObject(P1))

	Func quit 
		return QThread_quit(pObject)

	Func start P1
		return QThread_start(pObject,P1)

	Func terminate 
		return QThread_terminate(pObject)

	Func currentThread 
		pTempObj = new QThread
		pTempObj.pObject = QThread_currentThread(pObject)
		return pTempObj

	Func currentThreadId 
		return QThread_currentThreadId(pObject)

	Func idealThreadCount 
		return QThread_idealThreadCount(pObject)

	Func msleep P1
		return QThread_msleep(pObject,GetObjectPointerFromRingObject(P1))

	Func sleep P1
		return QThread_sleep(pObject,GetObjectPointerFromRingObject(P1))

	Func usleep P1
		return QThread_usleep(pObject,GetObjectPointerFromRingObject(P1))

	Func yieldCurrentThread 
		return QThread_yieldCurrentThread(pObject)

	Func setStartedEvent P1
		return QThread_setStartedEvent(pObject,P1)

	Func setFinishedEvent P1
		return QThread_setFinishedEvent(pObject,P1)

	Func getStartedEvent 
		return QThread_getStartedEvent(pObject)

	Func getFinishedEvent 
		return QThread_getFinishedEvent(pObject)

Class QThreadPool from QObject

	pObject

	Func init 
		pObject = QThreadPool_new()
		return self

	Func delete
		pObject = QThreadPool_delete(pObject)

	Func ObjectPointer
		return pObject

	Func activeThreadCount 
		return QThreadPool_activeThreadCount(pObject)

	Func clear 
		return QThreadPool_clear(pObject)

	Func expiryTimeout 
		return QThreadPool_expiryTimeout(pObject)

	Func maxThreadCount 
		return QThreadPool_maxThreadCount(pObject)

	Func releaseThread 
		return QThreadPool_releaseThread(pObject)

	Func reserveThread 
		return QThreadPool_reserveThread(pObject)

	Func setExpiryTimeout P1
		return QThreadPool_setExpiryTimeout(pObject,P1)

	Func setMaxThreadCount P1
		return QThreadPool_setMaxThreadCount(pObject,P1)

	Func start P1,P2
		return QThreadPool_start(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func tryStart P1
		return QThreadPool_tryStart(pObject,GetObjectPointerFromRingObject(P1))

	Func waitForDone P1
		return QThreadPool_waitForDone(pObject,P1)

	Func globalInstance 
		pTempObj = new QThreadPool
		pTempObj.pObject = QThreadPool_globalInstance(pObject)
		return pTempObj

Class QProcess from QIODevice

	pObject

	Func init P1
		pObject = QProcess_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QProcess_delete(pObject)

	Func ObjectPointer
		return pObject

	Func arguments 
		pTempObj = new QStringList
		pTempObj.pObject = QProcess_arguments(pObject)
		return pTempObj

	Func closeReadChannel P1
		return QProcess_closeReadChannel(pObject,P1)

	Func closeWriteChannel 
		return QProcess_closeWriteChannel(pObject)

	Func error 
		return QProcess_error(pObject)

	Func exitCode 
		return QProcess_exitCode(pObject)

	Func exitStatus 
		return QProcess_exitStatus(pObject)

	Func inputChannelMode 
		return QProcess_inputChannelMode(pObject)

	Func processChannelMode 
		return QProcess_processChannelMode(pObject)

	Func processEnvironment 
		return QProcess_processEnvironment(pObject)

	Func program 
		return QProcess_program(pObject)

	Func readAllStandardError 
		pTempObj = new QByteArray
		pTempObj.pObject = QProcess_readAllStandardError(pObject)
		return pTempObj

	Func readAllStandardOutput 
		pTempObj = new QByteArray
		pTempObj.pObject = QProcess_readAllStandardOutput(pObject)
		return pTempObj

	Func readChannel 
		return QProcess_readChannel(pObject)

	Func setArguments P1
		return QProcess_setArguments(pObject,GetObjectPointerFromRingObject(P1))

	Func setInputChannelMode P1
		return QProcess_setInputChannelMode(pObject,P1)

	Func setProcessChannelMode P1
		return QProcess_setProcessChannelMode(pObject,P1)

	Func setProcessEnvironment P1
		return QProcess_setProcessEnvironment(pObject,GetObjectPointerFromRingObject(P1))

	Func setProgram P1
		return QProcess_setProgram(pObject,P1)

	Func setReadChannel P1
		return QProcess_setReadChannel(pObject,P1)

	Func setStandardErrorFile P1,P2
		return QProcess_setStandardErrorFile(pObject,P1,P2)

	Func setStandardInputFile P1
		return QProcess_setStandardInputFile(pObject,P1)

	Func setStandardOutputFile P1,P2
		return QProcess_setStandardOutputFile(pObject,P1,P2)

	Func setStandardOutputProcess P1
		return QProcess_setStandardOutputProcess(pObject,GetObjectPointerFromRingObject(P1))

	Func setWorkingDirectory P1
		return QProcess_setWorkingDirectory(pObject,P1)

	Func start P1,P2,P3
		return QProcess_start(pObject,P1,GetObjectPointerFromRingObject(P2),P3)

	Func start_3 P1
		return QProcess_start_3(pObject,P1)

	Func state 
		return QProcess_state(pObject)

	Func waitForFinished P1
		return QProcess_waitForFinished(pObject,P1)

	Func waitForStarted P1
		return QProcess_waitForStarted(pObject,P1)

	Func workingDirectory 
		return QProcess_workingDirectory(pObject)

	Func kill 
		return QProcess_kill(pObject)

	Func terminate 
		return QProcess_terminate(pObject)

	Func setreadyReadStandardErrorEvent P1
		return QProcess_setreadyReadStandardErrorEvent(pObject,P1)

	Func setreadyReadStandardOutputEvent P1
		return QProcess_setreadyReadStandardOutputEvent(pObject,P1)

	Func getreadyReadStandardErrorEvent 
		return QProcess_getreadyReadStandardErrorEvent(pObject)

	Func getreadyReadStandardOutputEvent 
		return QProcess_getreadyReadStandardOutputEvent(pObject)

Class QUuid

	pObject

	Func init 
		pObject = QUuid_new()
		return self

	Func delete
		pObject = QUuid_delete(pObject)

	Func ObjectPointer
		return pObject

	Func toString 
		return QUuid_toString(pObject)

Class QMutex

	pObject


	Func lock 
		return QMutex_lock()

	Func unlock 
		return QMutex_unlock()

Class QMutexLocker

	pObject

	Func init P1
		pObject = QMutexLocker_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QMutexLocker_delete(pObject)

	Func ObjectPointer
		return pObject

	Func mutex 
		return QMutexLocker_mutex(pObject)

	Func relock 
		return QMutexLocker_relock(pObject)

	Func unlock 
		return QMutexLocker_unlock(pObject)

Class QVersionNumber

	pObject

	Func init 
		pObject = QVersionNumber_new()
		return self

	Func delete
		pObject = QVersionNumber_delete(pObject)

	Func ObjectPointer
		return pObject

	Func isNormalized 
		return QVersionNumber_isNormalized(pObject)

	Func isNull 
		return QVersionNumber_isNull(pObject)

	Func isPrefixOf P1
		return QVersionNumber_isPrefixOf(pObject,GetObjectPointerFromRingObject(P1))

	Func majorVersion 
		return QVersionNumber_majorVersion(pObject)

	Func microVersion 
		return QVersionNumber_microVersion(pObject)

	Func minorVersion 
		return QVersionNumber_minorVersion(pObject)

	Func normalized 
		pTempObj = new QVersionNumber
		pTempObj.pObject = QVersionNumber_normalized(pObject)
		return pTempObj

	Func segmentAt P1
		return QVersionNumber_segmentAt(pObject,P1)

	Func segmentCount 
		return QVersionNumber_segmentCount(pObject)

	Func segments 
		return QVersionNumber_segments(pObject)

	Func toString 
		return QVersionNumber_toString(pObject)

Class QLibraryInfo

	pObject


	Func isDebugBuild 
		return QLibraryInfo_isDebugBuild()

	Func version 
		pTempObj = new QVersionNumber
		pTempObj.pObject = QLibraryInfo_version()
		return pTempObj

Class QPixmap

	pObject

	Func init P1
		pObject = QPixmap_new(P1)
		return self

	Func delete
		pObject = QPixmap_delete(pObject)

	Func ObjectPointer
		return pObject

	Func transformed P1,P2
		pTempObj = new QPixmap
		pTempObj.pObject = QPixmap_transformed(pObject,GetObjectPointerFromRingObject(P1),P2)
		return pTempObj

	Func copy P1,P2,P3,P4
		pTempObj = new QPixmap
		pTempObj.pObject = QPixmap_copy(pObject,P1,P2,P3,P4)
		return pTempObj

	Func scaled P1,P2,P3,P4
		pTempObj = new QPixmap
		pTempObj.pObject = QPixmap_scaled(pObject,P1,P2,P3,P4)
		return pTempObj

	Func width 
		return QPixmap_width(pObject)

	Func height 
		return QPixmap_height(pObject)

	Func createMaskFromColor P1,P2
		return QPixmap_createMaskFromColor(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func mask 
		return QPixmap_mask(pObject)

	Func setMask P1
		return QPixmap_setMask(pObject,GetObjectPointerFromRingObject(P1))

	Func fill P1
		return QPixmap_fill(pObject,GetObjectPointerFromRingObject(P1))

	Func fromImage P1,P2
		pTempObj = new QPixmap
		pTempObj.pObject = QPixmap_fromImage(pObject,GetObjectPointerFromRingObject(P1),P2)
		return pTempObj

	Func loadpixmap P1,P2,P3
		return QPixmap_load(pObject,P1,P2,P3)

	Func cacheKey 
		return QPixmap_cacheKey(pObject)

	Func convertFromImage P1,P2
		return QPixmap_convertFromImage(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func copy_2 P1
		pTempObj = new QPixmap
		pTempObj.pObject = QPixmap_copy_2(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

	Func createHeuristicMask P1
		return QPixmap_createHeuristicMask(pObject,P1)

	Func depth 
		return QPixmap_depth(pObject)

	Func detach 
		return QPixmap_detach(pObject)

	Func devicePixelRatio 
		return QPixmap_devicePixelRatio(pObject)

	Func hasAlpha 
		return QPixmap_hasAlpha(pObject)

	Func hasAlphaChannel 
		return QPixmap_hasAlphaChannel(pObject)

	Func isNull 
		return QPixmap_isNull(pObject)

	Func isQBitmap 
		return QPixmap_isQBitmap(pObject)

	Func loadFromData P1,P2,P3,P4
		return QPixmap_loadFromData(pObject,GetObjectPointerFromRingObject(P1),P2,P3,P4)

	Func loadFromData_2 P1,P2,P3
		return QPixmap_loadFromData_2(pObject,GetObjectPointerFromRingObject(P1),P2,P3)

	Func rect 
		return QPixmap_rect(pObject)

	Func save P1,P2,P3
		return QPixmap_save(pObject,P1,P2,P3)

	Func save_2 P1,P2,P3
		return QPixmap_save_2(pObject,GetObjectPointerFromRingObject(P1),P2,P3)

	Func scaled_2 P1,P2,P3
		pTempObj = new QPixmap
		pTempObj.pObject = QPixmap_scaled_2(pObject,GetObjectPointerFromRingObject(P1),P2,P3)
		return pTempObj

	Func scaledToHeight P1,P2
		pTempObj = new QPixmap
		pTempObj.pObject = QPixmap_scaledToHeight(pObject,P1,P2)
		return pTempObj

	Func scaledToWidth P1,P2
		pTempObj = new QPixmap
		pTempObj.pObject = QPixmap_scaledToWidth(pObject,P1,P2)
		return pTempObj

	Func scroll P1,P2,P3,P4,P5,P6,P7
		return QPixmap_scroll(pObject,P1,P2,P3,P4,P5,P6,GetObjectPointerFromRingObject(P7))

	Func scroll_2 P1,P2,P3,P4
		return QPixmap_scroll_2(pObject,P1,P2,GetObjectPointerFromRingObject(P3),GetObjectPointerFromRingObject(P4))

	Func setDevicePixelRatio P1
		return QPixmap_setDevicePixelRatio(pObject,P1)

	Func size 
		pTempObj = new QSize
		pTempObj.pObject = QPixmap_size(pObject)
		return pTempObj

	Func swap P1
		return QPixmap_swap(pObject,GetObjectPointerFromRingObject(P1))

	Func toImage 
		pTempObj = new QImage
		pTempObj.pObject = QPixmap_toImage(pObject)
		return pTempObj

	Func transformed_2 P1,P2
		pTempObj = new QPixmap
		pTempObj.pObject = QPixmap_transformed_2(pObject,GetObjectPointerFromRingObject(P1),P2)
		return pTempObj

	Func defaultDepth 
		return QPixmap_defaultDepth(pObject)

	Func fromImage_2 P1,P2
		pTempObj = new QPixmap
		pTempObj.pObject = QPixmap_fromImage_2(pObject,GetObjectPointerFromRingObject(P1),P2)
		return pTempObj

	Func fromImageReader P1,P2
		pTempObj = new QPixmap
		pTempObj.pObject = QPixmap_fromImageReader(pObject,GetObjectPointerFromRingObject(P1),P2)
		return pTempObj

	Func trueMatrix P1,P2,P3
		return QPixmap_trueMatrix(pObject,GetObjectPointerFromRingObject(P1),P2,P3)

Class QPicture

	pObject

	Func init 
		pObject = QPicture_new()
		return self

	Func delete
		pObject = QPicture_delete(pObject)

	Func ObjectPointer
		return pObject

	Func boundingRect 
		return QPicture_boundingRect(pObject)

	Func data 
		return QPicture_data(pObject)

	Func isNull 
		return QPicture_isNull(pObject)

	Func loadfile P1
		return QPicture_load(pObject,P1)

	Func play P1
		return QPicture_play(pObject,GetObjectPointerFromRingObject(P1))

	Func save P1
		return QPicture_save(pObject,P1)

	Func setBoundingRect P1
		return QPicture_setBoundingRect(pObject,GetObjectPointerFromRingObject(P1))

	Func size 
		return QPicture_size(pObject)

	Func swap P1
		return QPicture_swap(pObject,GetObjectPointerFromRingObject(P1))

Class QFont

	pObject

	Func init P1,P2,P3,P4
		pObject = QFont_new(P1,P2,P3,P4)
		return self

	Func delete
		pObject = QFont_delete(pObject)

	Func ObjectPointer
		return pObject

	Func bold 
		return QFont_bold(pObject)

	Func capitalization 
		return QFont_capitalization(pObject)

	Func defaultFamily 
		return QFont_defaultFamily(pObject)

	Func exactMatch 
		return QFont_exactMatch(pObject)

	Func family 
		return QFont_family(pObject)

	Func fixedPitch 
		return QFont_fixedPitch(pObject)

	Func fromString P1
		return QFont_fromString(pObject,P1)

	Func hintingPreference 
		return QFont_hintingPreference(pObject)

	Func isCopyOf P1
		return QFont_isCopyOf(pObject,GetObjectPointerFromRingObject(P1))

	Func italic 
		return QFont_italic(pObject)

	Func kerning 
		return QFont_kerning(pObject)

	Func key 
		return QFont_key(pObject)

	Func letterSpacing 
		return QFont_letterSpacing(pObject)

	Func letterSpacingType 
		return QFont_letterSpacingType(pObject)

	Func overline 
		return QFont_overline(pObject)

	Func pixelSize 
		return QFont_pixelSize(pObject)

	Func pointSize 
		return QFont_pointSize(pObject)

	Func pointSizeF 
		return QFont_pointSizeF(pObject)

	Func resolve P1
		pTempObj = new QFont
		pTempObj.pObject = QFont_resolve(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

	Func setBold P1
		return QFont_setBold(pObject,P1)

	Func setCapitalization P1
		return QFont_setCapitalization(pObject,P1)

	Func setFamily P1
		return QFont_setFamily(pObject,P1)

	Func setFixedPitch P1
		return QFont_setFixedPitch(pObject,P1)

	Func setHintingPreference P1
		return QFont_setHintingPreference(pObject,P1)

	Func setItalic P1
		return QFont_setItalic(pObject,P1)

	Func setKerning P1
		return QFont_setKerning(pObject,P1)

	Func setLetterSpacing P1,P2
		return QFont_setLetterSpacing(pObject,P1,P2)

	Func setOverline P1
		return QFont_setOverline(pObject,P1)

	Func setPixelSize P1
		return QFont_setPixelSize(pObject,P1)

	Func setPointSize P1
		return QFont_setPointSize(pObject,P1)

	Func setPointSizeF P1
		return QFont_setPointSizeF(pObject,P1)

	Func setStretch P1
		return QFont_setStretch(pObject,P1)

	Func setStrikeOut P1
		return QFont_setStrikeOut(pObject,P1)

	Func setStyle P1
		return QFont_setStyle(pObject,P1)

	Func setStyleHint P1,P2
		return QFont_setStyleHint(pObject,P1,P2)

	Func setStyleName P1
		return QFont_setStyleName(pObject,P1)

	Func setStyleStrategy P1
		return QFont_setStyleStrategy(pObject,P1)

	Func setUnderline P1
		return QFont_setUnderline(pObject,P1)

	Func setWeight P1
		return QFont_setWeight(pObject,GetObjectPointerFromRingObject(P1))

	Func setWordSpacing P1
		return QFont_setWordSpacing(pObject,P1)

	Func stretch 
		return QFont_stretch(pObject)

	Func strikeOut 
		return QFont_strikeOut(pObject)

	Func style 
		return QFont_style(pObject)

	Func styleHint 
		return QFont_styleHint(pObject)

	Func styleName 
		return QFont_styleName(pObject)

	Func styleStrategy 
		return QFont_styleStrategy(pObject)

	Func toString 
		return QFont_toString(pObject)

	Func underline 
		return QFont_underline(pObject)

	Func weight 
		return QFont_weight(pObject)

	Func wordSpacing 
		return QFont_wordSpacing(pObject)

	Func insertSubstitution P1,P2
		return QFont_insertSubstitution(pObject,P1,P2)

	Func insertSubstitutions P1,P2
		return QFont_insertSubstitutions(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func substitute P1
		return QFont_substitute(pObject,P1)

	Func substitutes P1
		pTempObj = new QStringList
		pTempObj.pObject = QFont_substitutes(pObject,P1)
		return pTempObj

	Func substitutions 
		pTempObj = new QStringList
		pTempObj.pObject = QFont_substitutions(pObject)
		return pTempObj

Class QImage

	pObject

	Func init 
		pObject = QImage_new()
		return self

	Func delete
		pObject = QImage_delete(pObject)

	Func ObjectPointer
		return pObject

	Func allGray 
		return QImage_allGray(pObject)

	Func bitPlaneCount 
		return QImage_bitPlaneCount(pObject)

	Func bits 
		return QImage_bits(pObject)

	Func bytesPerLine 
		return QImage_bytesPerLine(pObject)

	Func cacheKey 
		return QImage_cacheKey(pObject)

	Func color P1
		return QImage_color(pObject,P1)

	Func colorCount 
		return QImage_colorCount(pObject)

	Func constBits 
		return QImage_constBits(pObject)

	Func constScanLine P1
		return QImage_constScanLine(pObject,P1)

	Func convertToFormat P1,P2
		pTempObj = new QImage
		pTempObj.pObject = QImage_convertToFormat(pObject,P1,P2)
		return pTempObj

	Func copy P1,P2,P3,P4
		pTempObj = new QImage
		pTempObj.pObject = QImage_copy(pObject,P1,P2,P3,P4)
		return pTempObj

	Func createAlphaMask P1
		pTempObj = new QImage
		pTempObj.pObject = QImage_createAlphaMask(pObject,P1)
		return pTempObj

	Func createHeuristicMask P1
		pTempObj = new QImage
		pTempObj.pObject = QImage_createHeuristicMask(pObject,P1)
		return pTempObj

	Func createMaskFromColor P1,P2
		pTempObj = new QImage
		pTempObj.pObject = QImage_createMaskFromColor(pObject,GetObjectPointerFromRingObject(P1),P2)
		return pTempObj

	Func depth 
		return QImage_depth(pObject)

	Func dotsPerMeterX 
		return QImage_dotsPerMeterX(pObject)

	Func dotsPerMeterY 
		return QImage_dotsPerMeterY(pObject)

	Func fill P1
		return QImage_fill(pObject,GetObjectPointerFromRingObject(P1))

	Func format 
		return QImage_format(pObject)

	Func hasAlphaChannel 
		return QImage_hasAlphaChannel(pObject)

	Func height 
		return QImage_height(pObject)

	Func invertPixels P1
		return QImage_invertPixels(pObject,P1)

	Func isGrayscale 
		return QImage_isGrayscale(pObject)

	Func isNull 
		return QImage_isNull(pObject)

	Func loadimage P1,P2
		return QImage_load(pObject,P1,P2)

	Func loadFromData P1,P2
		return QImage_loadFromData(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func mirrored P1,P2
		pTempObj = new QImage
		pTempObj.pObject = QImage_mirrored(pObject,P1,P2)
		return pTempObj

	Func offset 
		return QImage_offset(pObject)

	Func pixel P1,P2
		return QImage_pixel(pObject,P1,P2)

	Func pixelIndex P1,P2
		return QImage_pixelIndex(pObject,P1,P2)

	Func rect 
		return QImage_rect(pObject)

	Func rgbSwapped 
		pTempObj = new QImage
		pTempObj.pObject = QImage_rgbSwapped(pObject)
		return pTempObj

	Func save P1,P2,P3
		return QImage_save(pObject,P1,P2,P3)

	Func scaled P1,P2,P3,P4
		pTempObj = new QImage
		pTempObj.pObject = QImage_scaled(pObject,P1,P2,P3,P4)
		return pTempObj

	Func scaledToHeight P1,P2
		pTempObj = new QImage
		pTempObj.pObject = QImage_scaledToHeight(pObject,P1,P2)
		return pTempObj

	Func scaledToWidth P1,P2
		pTempObj = new QImage
		pTempObj.pObject = QImage_scaledToWidth(pObject,P1,P2)
		return pTempObj

	Func scanLine P1
		return QImage_scanLine(pObject,P1)

	Func setColor P1,P2
		return QImage_setColor(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func setColorCount P1
		return QImage_setColorCount(pObject,P1)

	Func setDotsPerMeterX P1
		return QImage_setDotsPerMeterX(pObject,P1)

	Func setDotsPerMeterY P1
		return QImage_setDotsPerMeterY(pObject,P1)

	Func setOffset P1
		return QImage_setOffset(pObject,GetObjectPointerFromRingObject(P1))

	Func setPixel P1,P2,P3
		return QImage_setPixel(pObject,P1,P2,P3)

	Func setText P1,P2
		return QImage_setText(pObject,P1,P2)

	Func size 
		pTempObj = new QSize
		pTempObj.pObject = QImage_size(pObject)
		return pTempObj

	Func swap P1
		return QImage_swap(pObject,GetObjectPointerFromRingObject(P1))

	Func text P1
		return QImage_text(pObject,P1)

	Func textKeys 
		pTempObj = new QStringList
		pTempObj.pObject = QImage_textKeys(pObject)
		return pTempObj

	Func valid P1,P2
		return QImage_valid(pObject,P1,P2)

	Func width 
		return QImage_width(pObject)

Class QWindow from QObject

	pObject

	Func init P1
		pObject = QWindow_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QWindow_delete(pObject)

	Func ObjectPointer
		return pObject

	Func baseSize 
		pTempObj = new QSize
		pTempObj.pObject = QWindow_baseSize(pObject)
		return pTempObj

	Func contentOrientation 
		return QWindow_contentOrientation(pObject)

	Func create 
		return QWindow_create(pObject)

	Func cursor 
		return QWindow_cursor(pObject)

	Func destroy 
		return QWindow_destroy(pObject)

	Func devicePixelRatio 
		return QWindow_devicePixelRatio(pObject)

	Func filePath 
		return QWindow_filePath(pObject)

	Func flags 
		return QWindow_flags(pObject)

	Func focusObject 
		pTempObj = new QObject
		pTempObj.pObject = QWindow_focusObject(pObject)
		return pTempObj

	Func frameGeometry 
		return QWindow_frameGeometry(pObject)

	Func frameMargins 
		return QWindow_frameMargins(pObject)

	Func framePosition 
		return QWindow_framePosition(pObject)

	Func geometry 
		return QWindow_geometry(pObject)

	Func height 
		return QWindow_height(pObject)

	Func icon 
		pTempObj = new QIcon
		pTempObj.pObject = QWindow_icon(pObject)
		return pTempObj

	Func isActive 
		return QWindow_isActive(pObject)

	Func isAncestorOf P1,P2
		return QWindow_isAncestorOf(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func isExposed 
		return QWindow_isExposed(pObject)

	Func isModal 
		return QWindow_isModal(pObject)

	Func isTopLevel 
		return QWindow_isTopLevel(pObject)

	Func isVisible 
		return QWindow_isVisible(pObject)

	Func mapFromGlobal P1
		return QWindow_mapFromGlobal(pObject,GetObjectPointerFromRingObject(P1))

	Func mapToGlobal P1
		return QWindow_mapToGlobal(pObject,GetObjectPointerFromRingObject(P1))

	Func mask 
		return QWindow_mask(pObject)

	Func maximumHeight 
		return QWindow_maximumHeight(pObject)

	Func maximumSize 
		pTempObj = new QSize
		pTempObj.pObject = QWindow_maximumSize(pObject)
		return pTempObj

	Func maximumWidth 
		return QWindow_maximumWidth(pObject)

	Func minimumHeight 
		return QWindow_minimumHeight(pObject)

	Func minimumSize 
		pTempObj = new QSize
		pTempObj.pObject = QWindow_minimumSize(pObject)
		return pTempObj

	Func minimumWidth 
		return QWindow_minimumWidth(pObject)

	Func modality 
		return QWindow_modality(pObject)

	Func opacity 
		return QWindow_opacity(pObject)

	Func position 
		return QWindow_position(pObject)

	Func reportContentOrientationChange P1
		return QWindow_reportContentOrientationChange(pObject,GetObjectPointerFromRingObject(P1))

	Func requestedFormat 
		return QWindow_requestedFormat(pObject)

	Func resize P1
		return QWindow_resize(pObject,GetObjectPointerFromRingObject(P1))

	Func resize_2 P1,P2
		return QWindow_resize_2(pObject,P1,P2)

	Func screen 
		return QWindow_screen(pObject)

	Func setBaseSize P1
		return QWindow_setBaseSize(pObject,GetObjectPointerFromRingObject(P1))

	Func setCursor P1
		return QWindow_setCursor(pObject,GetObjectPointerFromRingObject(P1))

	Func setFilePath P1
		return QWindow_setFilePath(pObject,P1)

	Func setFlags P1
		return QWindow_setFlags(pObject,P1)

	Func setFormat P1
		return QWindow_setFormat(pObject,GetObjectPointerFromRingObject(P1))

	Func setFramePosition P1
		return QWindow_setFramePosition(pObject,GetObjectPointerFromRingObject(P1))

	Func setGeometry P1,P2,P3,P4
		return QWindow_setGeometry(pObject,P1,P2,P3,P4)

	Func setGeometry_2 P1
		return QWindow_setGeometry_2(pObject,GetObjectPointerFromRingObject(P1))

	Func setIcon P1
		return QWindow_setIcon(pObject,GetObjectPointerFromRingObject(P1))

	Func setKeyboardGrabEnabled P1
		return QWindow_setKeyboardGrabEnabled(pObject,P1)

	Func setMask P1
		return QWindow_setMask(pObject,GetObjectPointerFromRingObject(P1))

	Func setMaximumSize P1
		return QWindow_setMaximumSize(pObject,GetObjectPointerFromRingObject(P1))

	Func setMinimumSize P1
		return QWindow_setMinimumSize(pObject,GetObjectPointerFromRingObject(P1))

	Func setModality P1
		return QWindow_setModality(pObject,P1)

	Func setMouseGrabEnabled P1
		return QWindow_setMouseGrabEnabled(pObject,P1)

	Func setOpacity P1
		return QWindow_setOpacity(pObject,P1)

	Func setParent P1
		return QWindow_setParent(pObject,GetObjectPointerFromRingObject(P1))

	Func setPosition P1
		return QWindow_setPosition(pObject,GetObjectPointerFromRingObject(P1))

	Func setPosition_2 P1,P2
		return QWindow_setPosition_2(pObject,P1,P2)

	Func setScreen P1
		return QWindow_setScreen(pObject,GetObjectPointerFromRingObject(P1))

	Func setSizeIncrement P1
		return QWindow_setSizeIncrement(pObject,GetObjectPointerFromRingObject(P1))

	Func setTransientParent P1
		return QWindow_setTransientParent(pObject,GetObjectPointerFromRingObject(P1))

	Func setVisibility P1
		return QWindow_setVisibility(pObject,P1)

	Func setWindowState P1
		return QWindow_setWindowState(pObject,P1)

	Func sizeIncrement 
		pTempObj = new QSize
		pTempObj.pObject = QWindow_sizeIncrement(pObject)
		return pTempObj

	Func title 
		return QWindow_title(pObject)

	Func transientParent 
		pTempObj = new QWindow
		pTempObj.pObject = QWindow_transientParent(pObject)
		return pTempObj

	Func type 
		return QWindow_type(pObject)

	Func unsetCursor 
		return QWindow_unsetCursor(pObject)

	Func visibility 
		return QWindow_visibility(pObject)

	Func width 
		return QWindow_width(pObject)

	Func winId 
		return QWindow_winId(pObject)

	Func windowState 
		return QWindow_windowState(pObject)

	Func x 
		return QWindow_x(pObject)

	Func y 
		return QWindow_y(pObject)

	Func alert P1
		return QWindow_alert(pObject,P1)

	Func close 
		return QWindow_close(pObject)

	Func hide 
		return QWindow_hide(pObject)

	Func lower 
		return QWindow_lower(pObject)

	Func raise 
		return QWindow_raise(pObject)

	Func requestActivate 
		return QWindow_requestActivate(pObject)

	Func setHeight P1
		return QWindow_setHeight(pObject,P1)

	Func setMaximumHeight P1
		return QWindow_setMaximumHeight(pObject,P1)

	Func setMaximumWidth P1
		return QWindow_setMaximumWidth(pObject,P1)

	Func setMinimumHeight P1
		return QWindow_setMinimumHeight(pObject,P1)

	Func setMinimumWidth P1
		return QWindow_setMinimumWidth(pObject,P1)

	Func setTitle P1
		return QWindow_setTitle(pObject,P1)

	Func setVisible P1
		return QWindow_setVisible(pObject,P1)

	Func setWidth P1
		return QWindow_setWidth(pObject,P1)

	Func setX P1
		return QWindow_setX(pObject,P1)

	Func setY P1
		return QWindow_setY(pObject,P1)

	Func show 
		return QWindow_show(pObject)

	Func showFullScreen 
		return QWindow_showFullScreen(pObject)

	Func showMaximized 
		return QWindow_showMaximized(pObject)

	Func showMinimized 
		return QWindow_showMinimized(pObject)

	Func showNormal 
		return QWindow_showNormal(pObject)

	Func fromWinId P1
		pTempObj = new QWindow
		pTempObj.pObject = QWindow_fromWinId(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

	Func setactiveChangedEvent P1
		return QWindow_setactiveChangedEvent(pObject,P1)

	Func setcontentOrientationChangedEvent P1
		return QWindow_setcontentOrientationChangedEvent(pObject,P1)

	Func setfocusObjectChangedEvent P1
		return QWindow_setfocusObjectChangedEvent(pObject,P1)

	Func setheightChangedEvent P1
		return QWindow_setheightChangedEvent(pObject,P1)

	Func setmaximumHeightChangedEvent P1
		return QWindow_setmaximumHeightChangedEvent(pObject,P1)

	Func setmaximumWidthChangedEvent P1
		return QWindow_setmaximumWidthChangedEvent(pObject,P1)

	Func setminimumHeightChangedEvent P1
		return QWindow_setminimumHeightChangedEvent(pObject,P1)

	Func setminimumWidthChangedEvent P1
		return QWindow_setminimumWidthChangedEvent(pObject,P1)

	Func setmodalityChangedEvent P1
		return QWindow_setmodalityChangedEvent(pObject,P1)

	Func setopacityChangedEvent P1
		return QWindow_setopacityChangedEvent(pObject,P1)

	Func setscreenChangedEvent P1
		return QWindow_setscreenChangedEvent(pObject,P1)

	Func setvisibilityChangedEvent P1
		return QWindow_setvisibilityChangedEvent(pObject,P1)

	Func setvisibleChangedEvent P1
		return QWindow_setvisibleChangedEvent(pObject,P1)

	Func setwidthChangedEvent P1
		return QWindow_setwidthChangedEvent(pObject,P1)

	Func setwindowStateChangedEvent P1
		return QWindow_setwindowStateChangedEvent(pObject,P1)

	Func setwindowTitleChangedEvent P1
		return QWindow_setwindowTitleChangedEvent(pObject,P1)

	Func setxChangedEvent P1
		return QWindow_setxChangedEvent(pObject,P1)

	Func setyChangedEvent P1
		return QWindow_setyChangedEvent(pObject,P1)

	Func getactiveChangedEvent 
		return QWindow_getactiveChangedEvent(pObject)

	Func getcontentOrientationChangedEvent 
		return QWindow_getcontentOrientationChangedEvent(pObject)

	Func getfocusObjectChangedEvent 
		return QWindow_getfocusObjectChangedEvent(pObject)

	Func getheightChangedEvent 
		return QWindow_getheightChangedEvent(pObject)

	Func getmaximumHeightChangedEvent 
		return QWindow_getmaximumHeightChangedEvent(pObject)

	Func getmaximumWidthChangedEvent 
		return QWindow_getmaximumWidthChangedEvent(pObject)

	Func getminimumHeightChangedEvent 
		return QWindow_getminimumHeightChangedEvent(pObject)

	Func getminimumWidthChangedEvent 
		return QWindow_getminimumWidthChangedEvent(pObject)

	Func getmodalityChangedEvent 
		return QWindow_getmodalityChangedEvent(pObject)

	Func getopacityChangedEvent 
		return QWindow_getopacityChangedEvent(pObject)

	Func getscreenChangedEvent 
		return QWindow_getscreenChangedEvent(pObject)

	Func getvisibilityChangedEvent 
		return QWindow_getvisibilityChangedEvent(pObject)

	Func getvisibleChangedEvent 
		return QWindow_getvisibleChangedEvent(pObject)

	Func getwidthChangedEvent 
		return QWindow_getwidthChangedEvent(pObject)

	Func getwindowStateChangedEvent 
		return QWindow_getwindowStateChangedEvent(pObject)

	Func getwindowTitleChangedEvent 
		return QWindow_getwindowTitleChangedEvent(pObject)

	Func getxChangedEvent 
		return QWindow_getxChangedEvent(pObject)

	Func getyChangedEvent 
		return QWindow_getyChangedEvent(pObject)

Class QGuiApplication from QCoreApplication

	pObject

	Func init P1,P2
		pObject = QGuiApplication_new(P1,GetObjectPointerFromRingObject(P2))
		return self

	Func delete
		pObject = QGuiApplication_delete(pObject)

	Func ObjectPointer
		return pObject

	Func devicePixelRatio 
		return QGuiApplication_devicePixelRatio(pObject)

	Func isSavingSession 
		return QGuiApplication_isSavingSession(pObject)

	Func isSessionRestored 
		return QGuiApplication_isSessionRestored(pObject)

	Func sessionId 
		return QGuiApplication_sessionId(pObject)

	Func sessionKey 
		return QGuiApplication_sessionKey(pObject)

	Func allWindows 
		return QGuiApplication_allWindows(pObject)

	Func applicationDisplayName 
		return QGuiApplication_applicationDisplayName(pObject)

	Func applicationState 
		return QGuiApplication_applicationState(pObject)

	Func changeOverrideCursor P1
		return QGuiApplication_changeOverrideCursor(pObject,GetObjectPointerFromRingObject(P1))

	Func clipboard 
		pTempObj = new QClipboard
		pTempObj.pObject = QGuiApplication_clipboard(pObject)
		return pTempObj

	Func desktopSettingsAware 
		return QGuiApplication_desktopSettingsAware(pObject)

	Func exec 
		return QGuiApplication_exec(pObject)

	Func focusObject 
		pTempObj = new QObject
		pTempObj.pObject = QGuiApplication_focusObject(pObject)
		return pTempObj

	Func focusWindow 
		pTempObj = new QWindow
		pTempObj.pObject = QGuiApplication_focusWindow(pObject)
		return pTempObj

	Func font 
		pTempObj = new QFont
		pTempObj.pObject = QGuiApplication_font(pObject)
		return pTempObj

	Func inputMethod 
		return QGuiApplication_inputMethod(pObject)

	Func isLeftToRight 
		return QGuiApplication_isLeftToRight(pObject)

	Func isRightToLeft 
		return QGuiApplication_isRightToLeft(pObject)

	Func keyboardModifiers 
		return QGuiApplication_keyboardModifiers(pObject)

	Func layoutDirection 
		return QGuiApplication_layoutDirection(pObject)

	Func modalWindow 
		pTempObj = new QWindow
		pTempObj.pObject = QGuiApplication_modalWindow(pObject)
		return pTempObj

	Func mouseButtons 
		return QGuiApplication_mouseButtons(pObject)

	Func overrideCursor 
		return QGuiApplication_overrideCursor(pObject)

	Func palette 
		return QGuiApplication_palette(pObject)

	Func platformName 
		return QGuiApplication_platformName(pObject)

	Func platformNativeInterface 
		return QGuiApplication_platformNativeInterface(pObject)

	Func primaryScreen 
		return QGuiApplication_primaryScreen(pObject)

	Func queryKeyboardModifiers 
		return QGuiApplication_queryKeyboardModifiers(pObject)

	Func quitOnLastWindowClosed 
		return QGuiApplication_quitOnLastWindowClosed(pObject)

	Func restoreOverrideCursor 
		return QGuiApplication_restoreOverrideCursor(pObject)

	Func screens 
		return QGuiApplication_screens(pObject)

	Func setApplicationDisplayName P1
		return QGuiApplication_setApplicationDisplayName(pObject,P1)

	Func setDesktopSettingsAware P1
		return QGuiApplication_setDesktopSettingsAware(pObject,P1)

	Func setFont P1
		return QGuiApplication_setFont(pObject,GetObjectPointerFromRingObject(P1))

	Func setLayoutDirection P1
		return QGuiApplication_setLayoutDirection(pObject,P1)

	Func setOverrideCursor P1
		return QGuiApplication_setOverrideCursor(pObject,GetObjectPointerFromRingObject(P1))

	Func setPalette P1
		return QGuiApplication_setPalette(pObject,GetObjectPointerFromRingObject(P1))

	Func setQuitOnLastWindowClosed P1
		return QGuiApplication_setQuitOnLastWindowClosed(pObject,P1)

	Func styleHints 
		return QGuiApplication_styleHints(pObject)

	Func sync 
		return QGuiApplication_sync(pObject)

	Func topLevelAt P1
		pTempObj = new QWindow
		pTempObj.pObject = QGuiApplication_topLevelAt(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

	Func topLevelWindows 
		return QGuiApplication_topLevelWindows(pObject)

	Func setapplicationDisplayNameChangedEvent P1
		return QGuiApplication_setapplicationDisplayNameChangedEvent(pObject,P1)

	Func setapplicationStateChangedEvent P1
		return QGuiApplication_setapplicationStateChangedEvent(pObject,P1)

	Func setcommitDataRequestEvent P1
		return QGuiApplication_setcommitDataRequestEvent(pObject,P1)

	Func setfocusObjectChangedEvent P1
		return QGuiApplication_setfocusObjectChangedEvent(pObject,P1)

	Func setfocusWindowChangedEvent P1
		return QGuiApplication_setfocusWindowChangedEvent(pObject,P1)

	Func setfontDatabaseChangedEvent P1
		return QGuiApplication_setfontDatabaseChangedEvent(pObject,P1)

	Func setlastWindowClosedEvent P1
		return QGuiApplication_setlastWindowClosedEvent(pObject,P1)

	Func setlayoutDirectionChangedEvent P1
		return QGuiApplication_setlayoutDirectionChangedEvent(pObject,P1)

	Func setpaletteChangedEvent P1
		return QGuiApplication_setpaletteChangedEvent(pObject,P1)

	Func setprimaryScreenChangedEvent P1
		return QGuiApplication_setprimaryScreenChangedEvent(pObject,P1)

	Func setsaveStateRequestEvent P1
		return QGuiApplication_setsaveStateRequestEvent(pObject,P1)

	Func setscreenAddedEvent P1
		return QGuiApplication_setscreenAddedEvent(pObject,P1)

	Func setscreenRemovedEvent P1
		return QGuiApplication_setscreenRemovedEvent(pObject,P1)

	Func getapplicationDisplayNameChangedEvent 
		return QGuiApplication_getapplicationDisplayNameChangedEvent(pObject)

	Func getapplicationStateChangedEvent 
		return QGuiApplication_getapplicationStateChangedEvent(pObject)

	Func getcommitDataRequestEvent 
		return QGuiApplication_getcommitDataRequestEvent(pObject)

	Func getfocusObjectChangedEvent 
		return QGuiApplication_getfocusObjectChangedEvent(pObject)

	Func getfocusWindowChangedEvent 
		return QGuiApplication_getfocusWindowChangedEvent(pObject)

	Func getfontDatabaseChangedEvent 
		return QGuiApplication_getfontDatabaseChangedEvent(pObject)

	Func getlastWindowClosedEvent 
		return QGuiApplication_getlastWindowClosedEvent(pObject)

	Func getlayoutDirectionChangedEvent 
		return QGuiApplication_getlayoutDirectionChangedEvent(pObject)

	Func getpaletteChangedEvent 
		return QGuiApplication_getpaletteChangedEvent(pObject)

	Func getprimaryScreenChangedEvent 
		return QGuiApplication_getprimaryScreenChangedEvent(pObject)

	Func getsaveStateRequestEvent 
		return QGuiApplication_getsaveStateRequestEvent(pObject)

	Func getscreenAddedEvent 
		return QGuiApplication_getscreenAddedEvent(pObject)

	Func getscreenRemovedEvent 
		return QGuiApplication_getscreenRemovedEvent(pObject)

Class QClipboard

	pObject


	Func clear P1
		return QClipboard_clear(pObject,P1)

	Func image P1
		pTempObj = new QImage
		pTempObj.pObject = QClipboard_image(pObject,P1)
		return pTempObj

	Func mimeData P1
		pTempObj = new QMimeData
		pTempObj.pObject = QClipboard_mimeData(pObject,P1)
		return pTempObj

	Func ownsClipboard 
		return QClipboard_ownsClipboard(pObject)

	Func ownsFindBuffer 
		return QClipboard_ownsFindBuffer(pObject)

	Func ownsSelection 
		return QClipboard_ownsSelection(pObject)

	Func pixmap P1
		pTempObj = new QPixmap
		pTempObj.pObject = QClipboard_pixmap(pObject,P1)
		return pTempObj

	Func setImage P1,P2
		return QClipboard_setImage(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func setMimeData P1,P2
		return QClipboard_setMimeData(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func setPixmap P1,P2
		return QClipboard_setPixmap(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func setText P1,P2
		return QClipboard_setText(pObject,P1,P2)

	Func supportsFindBuffer 
		return QClipboard_supportsFindBuffer(pObject)

	Func supportsSelection 
		return QClipboard_supportsSelection(pObject)

	Func text P1
		return QClipboard_text(pObject,P1)

Class QFontDatabase

	pObject

	Func init 
		pObject = QFontDatabase_new()
		return self

	Func delete
		pObject = QFontDatabase_delete(pObject)

	Func ObjectPointer
		return pObject

	Func bold P1,P2
		return QFontDatabase_bold(pObject,P1,P2)

	Func families P1
		pTempObj = new QStringList
		pTempObj.pObject = QFontDatabase_families(pObject,P1)
		return pTempObj

	Func font P1,P2,P3
		pTempObj = new QFont
		pTempObj.pObject = QFontDatabase_font(pObject,P1,P2,P3)
		return pTempObj

	Func isBitmapScalable P1,P2
		return QFontDatabase_isBitmapScalable(pObject,P1,P2)

	Func isFixedPitch P1,P2
		return QFontDatabase_isFixedPitch(pObject,P1,P2)

	Func isPrivateFamily P1
		return QFontDatabase_isPrivateFamily(pObject,P1)

	Func isScalable P1,P2
		return QFontDatabase_isScalable(pObject,P1,P2)

	Func isSmoothlyScalable P1,P2
		return QFontDatabase_isSmoothlyScalable(pObject,P1,P2)

	Func italic P1,P2
		return QFontDatabase_italic(pObject,P1,P2)

	Func pointSizes P1,P2
		return QFontDatabase_pointSizes(pObject,P1,P2)

	Func smoothSizes P1,P2
		return QFontDatabase_smoothSizes(pObject,P1,P2)

	Func styleString P1
		return QFontDatabase_styleString(pObject,GetObjectPointerFromRingObject(P1))

	Func styleString_2 P1
		return QFontDatabase_styleString_2(pObject,GetObjectPointerFromRingObject(P1))

	Func styles P1
		pTempObj = new QStringList
		pTempObj.pObject = QFontDatabase_styles(pObject,P1)
		return pTempObj

	Func weight P1,P2
		return QFontDatabase_weight(pObject,P1,P2)

	Func writingSystems 
		return QFontDatabase_writingSystems(pObject)

	Func writingSystems_2 P1
		return QFontDatabase_writingSystems_2(pObject,P1)

	Func addApplicationFont P1
		return QFontDatabase_addApplicationFont(pObject,P1)

	Func addApplicationFontFromData P1
		return QFontDatabase_addApplicationFontFromData(pObject,GetObjectPointerFromRingObject(P1))

	Func applicationFontFamilies P1
		pTempObj = new QStringList
		pTempObj.pObject = QFontDatabase_applicationFontFamilies(pObject,P1)
		return pTempObj

	Func removeAllApplicationFonts 
		return QFontDatabase_removeAllApplicationFonts(pObject)

	Func removeApplicationFont P1
		return QFontDatabase_removeApplicationFont(pObject,P1)

	Func standardSizes 
		return QFontDatabase_standardSizes(pObject)

	Func systemFont P1
		pTempObj = new QFont
		pTempObj.pObject = QFontDatabase_systemFont(pObject,P1)
		return pTempObj

	Func writingSystemName P1
		return QFontDatabase_writingSystemName(pObject,P1)

	Func writingSystemSample P1
		return QFontDatabase_writingSystemSample(pObject,P1)

Class QApp from QGuiApplication

	pObject


	Func exec 
		return QApp_exec()

	Func quit 
		return QApp_quit()

	Func processEvents 
		return QApp_processEvents()

	Func styleWindows 
		return QApp_styleWindows()

	Func styleWindowsVista 
		return QApp_styleWindowsVista()

	Func styleFusion 
		return QApp_styleFusion()

	Func styleFusionBlack 
		return QApp_styleFusionBlack()

	Func styleFusionCustom P1,P2,P3,P4,P5,P6,P7,P8,P9,P10,P11,P12
		return QApp_styleFusionCustom(GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2),GetObjectPointerFromRingObject(P3),GetObjectPointerFromRingObject(P4),GetObjectPointerFromRingObject(P5),GetObjectPointerFromRingObject(P6),GetObjectPointerFromRingObject(P7),GetObjectPointerFromRingObject(P8),GetObjectPointerFromRingObject(P9),GetObjectPointerFromRingObject(P10),GetObjectPointerFromRingObject(P11),GetObjectPointerFromRingObject(P12))

	Func closeAllWindows 
		return QApp_closeAllWindows()

	Func keyboardModifiers 
		return QApp_keyboardModifiers()

	Func clipboard 
		pTempObj = new QClipboard
		pTempObj.pObject = QApp_clipboard()
		return pTempObj

	Func style 
		return QApp_style()

	Func aboutQt 
		return QApp_aboutQt()

	Func activeModalWidget 
		return QApp_activeModalWidget()

	Func activePopupWidget 
		return QApp_activePopupWidget()

	Func activeWindow 
		return QApp_activeWindow()

	Func focusWidget 
		return QApp_focusWidget()

	Func titlebarHeight 
		return QApp_titlebarHeight()

Class QAllEvents from QWidget

	pObject

	Func init P1
		pObject = QAllEvents_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QAllEvents_delete(pObject)

	Func ObjectPointer
		return pObject

	Func accept 
		return QAllEvents_accept(pObject)

	Func ignore 
		return QAllEvents_ignore(pObject)

	Func getKeyCode 
		return QAllEvents_getKeyCode(pObject)

	Func getKeyText 
		return QAllEvents_getKeyText(pObject)

	Func getModifiers 
		return QAllEvents_getModifiers(pObject)

	Func getx 
		return QAllEvents_getx(pObject)

	Func gety 
		return QAllEvents_gety(pObject)

	Func getglobalx 
		return QAllEvents_getglobalx(pObject)

	Func getglobaly 
		return QAllEvents_getglobaly(pObject)

	Func getbutton 
		return QAllEvents_getbutton(pObject)

	Func getbuttons 
		return QAllEvents_getbuttons(pObject)

	Func setKeyPressEvent P1
		return QAllEvents_setKeyPressEvent(pObject,P1)

	Func setMouseButtonPressEvent P1
		return QAllEvents_setMouseButtonPressEvent(pObject,P1)

	Func setMouseButtonReleaseEvent P1
		return QAllEvents_setMouseButtonReleaseEvent(pObject,P1)

	Func setMouseButtonDblClickEvent P1
		return QAllEvents_setMouseButtonDblClickEvent(pObject,P1)

	Func setMouseMoveEvent P1
		return QAllEvents_setMouseMoveEvent(pObject,P1)

	Func setCloseEvent P1
		return QAllEvents_setCloseEvent(pObject,P1)

	Func setContextMenuEvent P1
		return QAllEvents_setContextMenuEvent(pObject,P1)

	Func setDragEnterEvent P1
		return QAllEvents_setDragEnterEvent(pObject,P1)

	Func setDragLeaveEvent P1
		return QAllEvents_setDragLeaveEvent(pObject,P1)

	Func setDragMoveEvent P1
		return QAllEvents_setDragMoveEvent(pObject,P1)

	Func setDropEvent P1
		return QAllEvents_setDropEvent(pObject,P1)

	Func setEnterEvent P1
		return QAllEvents_setEnterEvent(pObject,P1)

	Func setFocusInEvent P1
		return QAllEvents_setFocusInEvent(pObject,P1)

	Func setFocusOutEvent P1
		return QAllEvents_setFocusOutEvent(pObject,P1)

	Func setKeyReleaseEvent P1
		return QAllEvents_setKeyReleaseEvent(pObject,P1)

	Func setLeaveEvent P1
		return QAllEvents_setLeaveEvent(pObject,P1)

	Func setNonClientAreaMouseButtonDblClickEvent P1
		return QAllEvents_setNonClientAreaMouseButtonDblClickEvent(pObject,P1)

	Func setNonClientAreaMouseButtonPressEvent P1
		return QAllEvents_setNonClientAreaMouseButtonPressEvent(pObject,P1)

	Func setNonClientAreaMouseButtonReleaseEvent P1
		return QAllEvents_setNonClientAreaMouseButtonReleaseEvent(pObject,P1)

	Func setNonClientAreaMouseMoveEvent P1
		return QAllEvents_setNonClientAreaMouseMoveEvent(pObject,P1)

	Func setMoveEvent P1
		return QAllEvents_setMoveEvent(pObject,P1)

	Func setResizeEvent P1
		return QAllEvents_setResizeEvent(pObject,P1)

	Func setWindowActivateEvent P1
		return QAllEvents_setWindowActivateEvent(pObject,P1)

	Func setWindowBlockedEvent P1
		return QAllEvents_setWindowBlockedEvent(pObject,P1)

	Func setWindowDeactivateEvent P1
		return QAllEvents_setWindowDeactivateEvent(pObject,P1)

	Func setWindowStateChangeEvent P1
		return QAllEvents_setWindowStateChangeEvent(pObject,P1)

	Func setWindowUnblockedEvent P1
		return QAllEvents_setWindowUnblockedEvent(pObject,P1)

	Func setPaintEvent P1
		return QAllEvents_setPaintEvent(pObject,P1)

	Func setChildAddedEvent P1
		return QAllEvents_setChildAddedEvent(pObject,P1)

	Func setChildPolishedEvent P1
		return QAllEvents_setChildPolishedEvent(pObject,P1)

	Func setChildRemovedEvent P1
		return QAllEvents_setChildRemovedEvent(pObject,P1)

	Func getKeyPressEvent 
		return QAllEvents_getKeyPressEvent(pObject)

	Func getMouseButtonPressEvent 
		return QAllEvents_getMouseButtonPressEvent(pObject)

	Func getMouseButtonReleaseEvent 
		return QAllEvents_getMouseButtonReleaseEvent(pObject)

	Func getMouseButtonDblClickEvent 
		return QAllEvents_getMouseButtonDblClickEvent(pObject)

	Func getMouseMoveEvent 
		return QAllEvents_getMouseMoveEvent(pObject)

	Func getCloseEvent 
		return QAllEvents_getCloseEvent(pObject)

	Func getContextMenuEvent 
		return QAllEvents_getContextMenuEvent(pObject)

	Func getDragEnterEvent 
		return QAllEvents_getDragEnterEvent(pObject)

	Func getDragLeaveEvent 
		return QAllEvents_getDragLeaveEvent(pObject)

	Func getDragMoveEvent 
		return QAllEvents_getDragMoveEvent(pObject)

	Func getDropEvent 
		return QAllEvents_getDropEvent(pObject)

	Func getEnterEvent 
		return QAllEvents_getEnterEvent(pObject)

	Func getFocusInEvent 
		return QAllEvents_getFocusInEvent(pObject)

	Func getFocusOutEvent 
		return QAllEvents_getFocusOutEvent(pObject)

	Func getKeyReleaseEvent 
		return QAllEvents_getKeyReleaseEvent(pObject)

	Func getLeaveEvent 
		return QAllEvents_getLeaveEvent(pObject)

	Func getNonClientAreaMouseButtonDblClickEvent 
		return QAllEvents_getNonClientAreaMouseButtonDblClickEvent(pObject)

	Func getNonClientAreaMouseButtonPressEvent 
		return QAllEvents_getNonClientAreaMouseButtonPressEvent(pObject)

	Func getNonClientAreaMouseButtonReleaseEvent 
		return QAllEvents_getNonClientAreaMouseButtonReleaseEvent(pObject)

	Func getNonClientAreaMouseMoveEvent 
		return QAllEvents_getNonClientAreaMouseMoveEvent(pObject)

	Func getMoveEvent 
		return QAllEvents_getMoveEvent(pObject)

	Func getResizeEvent 
		return QAllEvents_getResizeEvent(pObject)

	Func getWindowActivateEvent 
		return QAllEvents_getWindowActivateEvent(pObject)

	Func getWindowBlockedEvent 
		return QAllEvents_getWindowBlockedEvent(pObject)

	Func getWindowDeactivateEvent 
		return QAllEvents_getWindowDeactivateEvent(pObject)

	Func getWindowStateChangeEvent 
		return QAllEvents_getWindowStateChangeEvent(pObject)

	Func getWindowUnblockedEvent 
		return QAllEvents_getWindowUnblockedEvent(pObject)

	Func getPaintEvent 
		return QAllEvents_getPaintEvent(pObject)

	Func getChildAddedEvent 
		return QAllEvents_getChildAddedEvent(pObject)

	Func getChildPolishedEvent 
		return QAllEvents_getChildPolishedEvent(pObject)

	Func getChildRemovedEvent 
		return QAllEvents_getChildRemovedEvent(pObject)

	Func setEventOutput P1
		return QAllEvents_setEventOutput(pObject,P1)

	Func getParentObject 
		pTempObj = new QObject
		pTempObj.pObject = QAllEvents_getParentObject(pObject)
		return pTempObj

	Func getParentWidget 
		return QAllEvents_getParentWidget(pObject)

	Func setKeyPressFunc P1
		return QAllEvents_setKeyPressFunc(pObject,P1)

	Func setMouseButtonPressFunc P1
		return QAllEvents_setMouseButtonPressFunc(pObject,P1)

	Func setMouseButtonReleaseFunc P1
		return QAllEvents_setMouseButtonReleaseFunc(pObject,P1)

	Func setMouseButtonDblClickFunc P1
		return QAllEvents_setMouseButtonDblClickFunc(pObject,P1)

	Func setMouseMoveFunc P1
		return QAllEvents_setMouseMoveFunc(pObject,P1)

	Func setCloseFunc P1
		return QAllEvents_setCloseFunc(pObject,P1)

	Func setContextMenuFunc P1
		return QAllEvents_setContextMenuFunc(pObject,P1)

	Func setDragEnterFunc P1
		return QAllEvents_setDragEnterFunc(pObject,P1)

	Func setDragLeaveFunc P1
		return QAllEvents_setDragLeaveFunc(pObject,P1)

	Func setDragMoveFunc P1
		return QAllEvents_setDragMoveFunc(pObject,P1)

	Func setDropFunc P1
		return QAllEvents_setDropFunc(pObject,P1)

	Func setEnterFunc P1
		return QAllEvents_setEnterFunc(pObject,P1)

	Func setFocusInFunc P1
		return QAllEvents_setFocusInFunc(pObject,P1)

	Func setFocusOutFunc P1
		return QAllEvents_setFocusOutFunc(pObject,P1)

	Func setKeyReleaseFunc P1
		return QAllEvents_setKeyReleaseFunc(pObject,P1)

	Func setLeaveFunc P1
		return QAllEvents_setLeaveFunc(pObject,P1)

	Func setNonClientAreaMouseButtonDblClickFunc P1
		return QAllEvents_setNonClientAreaMouseButtonDblClickFunc(pObject,P1)

	Func setNonClientAreaMouseButtonPressFunc P1
		return QAllEvents_setNonClientAreaMouseButtonPressFunc(pObject,P1)

	Func setNonClientAreaMouseButtonReleaseFunc P1
		return QAllEvents_setNonClientAreaMouseButtonReleaseFunc(pObject,P1)

	Func setNonClientAreaMouseMoveFunc P1
		return QAllEvents_setNonClientAreaMouseMoveFunc(pObject,P1)

	Func setMoveFunc P1
		return QAllEvents_setMoveFunc(pObject,P1)

	Func setResizeFunc P1
		return QAllEvents_setResizeFunc(pObject,P1)

	Func setWindowActivateFunc P1
		return QAllEvents_setWindowActivateFunc(pObject,P1)

	Func setWindowBlockedFunc P1
		return QAllEvents_setWindowBlockedFunc(pObject,P1)

	Func setWindowDeactivateFunc P1
		return QAllEvents_setWindowDeactivateFunc(pObject,P1)

	Func setWindowStateChangeFunc P1
		return QAllEvents_setWindowStateChangeFunc(pObject,P1)

	Func setWindowUnblockedFunc P1
		return QAllEvents_setWindowUnblockedFunc(pObject,P1)

	Func setPaintFunc P1
		return QAllEvents_setPaintFunc(pObject,P1)

	Func setChildAddedFunc P1
		return QAllEvents_setChildAddedFunc(pObject,P1)

	Func setChildPolishedFunc P1
		return QAllEvents_setChildPolishedFunc(pObject,P1)

	Func setChildRemovedFunc P1
		return QAllEvents_setChildRemovedFunc(pObject,P1)

	Func getKeyPressFunc 
		return QAllEvents_getKeyPressFunc(pObject)

	Func getMouseButtonPressFunc 
		return QAllEvents_getMouseButtonPressFunc(pObject)

	Func getMouseButtonReleaseFunc 
		return QAllEvents_getMouseButtonReleaseFunc(pObject)

	Func getMouseButtonDblClickFunc 
		return QAllEvents_getMouseButtonDblClickFunc(pObject)

	Func getMouseMoveFunc 
		return QAllEvents_getMouseMoveFunc(pObject)

	Func getCloseFunc 
		return QAllEvents_getCloseFunc(pObject)

	Func getContextMenuFunc 
		return QAllEvents_getContextMenuFunc(pObject)

	Func getDragEnterFunc 
		return QAllEvents_getDragEnterFunc(pObject)

	Func getDragLeaveFunc 
		return QAllEvents_getDragLeaveFunc(pObject)

	Func getDragMoveFunc 
		return QAllEvents_getDragMoveFunc(pObject)

	Func getDropFunc 
		return QAllEvents_getDropFunc(pObject)

	Func getEnterFunc 
		return QAllEvents_getEnterFunc(pObject)

	Func getFocusInFunc 
		return QAllEvents_getFocusInFunc(pObject)

	Func getFocusOutFunc 
		return QAllEvents_getFocusOutFunc(pObject)

	Func getKeyReleaseFunc 
		return QAllEvents_getKeyReleaseFunc(pObject)

	Func getLeaveFunc 
		return QAllEvents_getLeaveFunc(pObject)

	Func getNonClientAreaMouseButtonDblClickFunc 
		return QAllEvents_getNonClientAreaMouseButtonDblClickFunc(pObject)

	Func getNonClientAreaMouseButtonPressFunc 
		return QAllEvents_getNonClientAreaMouseButtonPressFunc(pObject)

	Func getNonClientAreaMouseButtonReleaseFunc 
		return QAllEvents_getNonClientAreaMouseButtonReleaseFunc(pObject)

	Func getNonClientAreaMouseMoveFunc 
		return QAllEvents_getNonClientAreaMouseMoveFunc(pObject)

	Func getMoveFunc 
		return QAllEvents_getMoveFunc(pObject)

	Func getResizeFunc 
		return QAllEvents_getResizeFunc(pObject)

	Func getWindowActivateFunc 
		return QAllEvents_getWindowActivateFunc(pObject)

	Func getWindowBlockedFunc 
		return QAllEvents_getWindowBlockedFunc(pObject)

	Func getWindowDeactivateFunc 
		return QAllEvents_getWindowDeactivateFunc(pObject)

	Func getWindowStateChangeFunc 
		return QAllEvents_getWindowStateChangeFunc(pObject)

	Func getWindowUnblockedFunc 
		return QAllEvents_getWindowUnblockedFunc(pObject)

	Func getPaintFunc 
		return QAllEvents_getPaintFunc(pObject)

	Func getChildAddedFunc 
		return QAllEvents_getChildAddedFunc(pObject)

	Func getChildPolishedFunc 
		return QAllEvents_getChildPolishedFunc(pObject)

	Func getChildRemovedFunc 
		return QAllEvents_getChildRemovedFunc(pObject)

	Func getDropEventObject 
		return QAllEvents_getDropEventObject(pObject)

	Func getDragMoveEventObject 
		return QAllEvents_getDragMoveEventObject(pObject)

	Func getDragEnterEventObject 
		return QAllEvents_getDragEnterEventObject(pObject)

	Func getDragLeaveEventObject 
		return QAllEvents_getDragLeaveEventObject(pObject)

	Func getChildEventObject 
		pTempObj = new QChildEvent
		pTempObj.pObject = QAllEvents_getChildEventObject(pObject)
		return pTempObj

Class QAbstractSocket from QIODevice

	pObject

	Func init 
		pObject = QAbstractSocket_new()
		return self

	Func delete
		pObject = QAbstractSocket_delete(pObject)

	Func ObjectPointer
		return pObject

	Func abort 
		return QAbstractSocket_abort(pObject)

	Func bind P1,P2,P3
		return QAbstractSocket_bind(pObject,GetObjectPointerFromRingObject(P1),P2,P3)

	Func connectToHost P1,P2,P3,P4
		return QAbstractSocket_connectToHost(pObject,P1,P2,P3,P4)

	Func disconnectFromHost 
		return QAbstractSocket_disconnectFromHost(pObject)

	Func error 
		return QAbstractSocket_error(pObject)

	Func flush 
		return QAbstractSocket_flush(pObject)

	Func isValid 
		return QAbstractSocket_isValid(pObject)

	Func localAddress 
		pTempObj = new QHostAddress
		pTempObj.pObject = QAbstractSocket_localAddress(pObject)
		return pTempObj

	Func localPort 
		return QAbstractSocket_localPort(pObject)

	Func pauseMode 
		return QAbstractSocket_pauseMode(pObject)

	Func peerAddress 
		pTempObj = new QHostAddress
		pTempObj.pObject = QAbstractSocket_peerAddress(pObject)
		return pTempObj

	Func peerName 
		return QAbstractSocket_peerName(pObject)

	Func peerPort 
		return QAbstractSocket_peerPort(pObject)

	Func proxy 
		pTempObj = new QNetworkProxy
		pTempObj.pObject = QAbstractSocket_proxy(pObject)
		return pTempObj

	Func readBufferSize 
		return QAbstractSocket_readBufferSize(pObject)

	Func resume 
		return QAbstractSocket_resume(pObject)

	Func setPauseMode P1
		return QAbstractSocket_setPauseMode(pObject,P1)

	Func setProxy P1
		return QAbstractSocket_setProxy(pObject,GetObjectPointerFromRingObject(P1))

	Func setReadBufferSize P1
		return QAbstractSocket_setReadBufferSize(pObject,P1)

	Func setSocketDescriptor P1,P2,P3
		return QAbstractSocket_setSocketDescriptor(pObject,GetObjectPointerFromRingObject(P1),P2,P3)

	Func setSocketOption P1,P2
		return QAbstractSocket_setSocketOption(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func socketDescriptor 
		return QAbstractSocket_socketDescriptor(pObject)

	Func socketOption P1
		pTempObj = new QVariant
		pTempObj.pObject = QAbstractSocket_socketOption(pObject,P1)
		return pTempObj

	Func socketType 
		return QAbstractSocket_socketType(pObject)

	Func state 
		return QAbstractSocket_state(pObject)

	Func waitForConnected P1
		return QAbstractSocket_waitForConnected(pObject,P1)

	Func waitForDisconnected P1
		return QAbstractSocket_waitForDisconnected(pObject,P1)

	Func atEnd 
		return QAbstractSocket_atEnd(pObject)

	Func bytesAvailable 
		return QAbstractSocket_bytesAvailable(pObject)

	Func bytesToWrite 
		return QAbstractSocket_bytesToWrite(pObject)

	Func canReadLine 
		return QAbstractSocket_canReadLine(pObject)

	Func close 
		return QAbstractSocket_close(pObject)

	Func isSequential 
		return QAbstractSocket_isSequential(pObject)

	Func waitForBytesWritten P1
		return QAbstractSocket_waitForBytesWritten(pObject,P1)

	Func waitForReadyRead P1
		return QAbstractSocket_waitForReadyRead(pObject,P1)

	Func setconnectedEvent P1
		return QAbstractSocket_setconnectedEvent(pObject,P1)

	Func setdisconnectedEvent P1
		return QAbstractSocket_setdisconnectedEvent(pObject,P1)

	Func seterrorEvent P1
		return QAbstractSocket_seterrorEvent(pObject,P1)

	Func sethostFoundEvent P1
		return QAbstractSocket_sethostFoundEvent(pObject,P1)

	Func setproxyAuthenticationRequiredEvent P1
		return QAbstractSocket_setproxyAuthenticationRequiredEvent(pObject,P1)

	Func setstateChangedEvent P1
		return QAbstractSocket_setstateChangedEvent(pObject,P1)

	Func getconnectedEvent 
		return QAbstractSocket_getconnectedEvent(pObject)

	Func getdisconnectedEvent 
		return QAbstractSocket_getdisconnectedEvent(pObject)

	Func geterrorEvent 
		return QAbstractSocket_geterrorEvent(pObject)

	Func gethostFoundEvent 
		return QAbstractSocket_gethostFoundEvent(pObject)

	Func getproxyAuthenticationRequiredEvent 
		return QAbstractSocket_getproxyAuthenticationRequiredEvent(pObject)

	Func getstateChangedEvent 
		return QAbstractSocket_getstateChangedEvent(pObject)

Class QNetworkProxy

	pObject

	Func init 
		pObject = QNetworkProxy_new()
		return self

	Func delete
		pObject = QNetworkProxy_delete(pObject)

	Func ObjectPointer
		return pObject

	Func capabilities 
		return QNetworkProxy_capabilities(pObject)

	Func hasRawHeader P1
		return QNetworkProxy_hasRawHeader(pObject,GetObjectPointerFromRingObject(P1))

	Func header P1
		pTempObj = new QVariant
		pTempObj.pObject = QNetworkProxy_header(pObject,P1)
		return pTempObj

	Func hostName 
		return QNetworkProxy_hostName(pObject)

	Func isCachingProxy 
		return QNetworkProxy_isCachingProxy(pObject)

	Func isTransparentProxy 
		return QNetworkProxy_isTransparentProxy(pObject)

	Func password 
		return QNetworkProxy_password(pObject)

	Func port 
		return QNetworkProxy_port(pObject)

	Func rawHeader P1
		pTempObj = new QByteArray
		pTempObj.pObject = QNetworkProxy_rawHeader(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

	Func setCapabilities P1
		return QNetworkProxy_setCapabilities(pObject,P1)

	Func setHeader P1,P2
		return QNetworkProxy_setHeader(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func setHostName P1
		return QNetworkProxy_setHostName(pObject,P1)

	Func setPassword P1
		return QNetworkProxy_setPassword(pObject,P1)

	Func setPort P1
		return QNetworkProxy_setPort(pObject,P1)

	Func setRawHeader P1,P2
		return QNetworkProxy_setRawHeader(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2))

	Func setType P1
		return QNetworkProxy_setType(pObject,P1)

	Func setUser P1
		return QNetworkProxy_setUser(pObject,P1)

	Func swap P1
		return QNetworkProxy_swap(pObject,GetObjectPointerFromRingObject(P1))

	Func type 
		return QNetworkProxy_type(pObject)

	Func user 
		return QNetworkProxy_user(pObject)

	Func applicationProxy 
		pTempObj = new QNetworkProxy
		pTempObj.pObject = QNetworkProxy_applicationProxy(pObject)
		return pTempObj

	Func setApplicationProxy P1
		return QNetworkProxy_setApplicationProxy(pObject,GetObjectPointerFromRingObject(P1))

Class QTcpSocket from QAbstractSocket

	pObject

	Func init P1
		pObject = QTcpSocket_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QTcpSocket_delete(pObject)

	Func ObjectPointer
		return pObject

	Func setconnectedEvent P1
		return QTcpSocket_setconnectedEvent(pObject,P1)

	Func setdisconnectedEvent P1
		return QTcpSocket_setdisconnectedEvent(pObject,P1)

	Func seterrorEvent P1
		return QTcpSocket_seterrorEvent(pObject,P1)

	Func sethostFoundEvent P1
		return QTcpSocket_sethostFoundEvent(pObject,P1)

	Func setproxyAuthenticationRequiredEvent P1
		return QTcpSocket_setproxyAuthenticationRequiredEvent(pObject,P1)

	Func setstateChangedEvent P1
		return QTcpSocket_setstateChangedEvent(pObject,P1)

	Func setaboutToCloseEvent P1
		return QTcpSocket_setaboutToCloseEvent(pObject,P1)

	Func setbytesWrittenEvent P1
		return QTcpSocket_setbytesWrittenEvent(pObject,P1)

	Func setreadChannelFinishedEvent P1
		return QTcpSocket_setreadChannelFinishedEvent(pObject,P1)

	Func setreadyReadEvent P1
		return QTcpSocket_setreadyReadEvent(pObject,P1)

	Func getconnectedEvent 
		return QTcpSocket_getconnectedEvent(pObject)

	Func getdisconnectedEvent 
		return QTcpSocket_getdisconnectedEvent(pObject)

	Func geterrorEvent 
		return QTcpSocket_geterrorEvent(pObject)

	Func gethostFoundEvent 
		return QTcpSocket_gethostFoundEvent(pObject)

	Func getproxyAuthenticationRequiredEvent 
		return QTcpSocket_getproxyAuthenticationRequiredEvent(pObject)

	Func getstateChangedEvent 
		return QTcpSocket_getstateChangedEvent(pObject)

	Func getaboutToCloseEvent 
		return QTcpSocket_getaboutToCloseEvent(pObject)

	Func getbytesWrittenEvent 
		return QTcpSocket_getbytesWrittenEvent(pObject)

	Func getreadChannelFinishedEvent 
		return QTcpSocket_getreadChannelFinishedEvent(pObject)

	Func getreadyReadEvent 
		return QTcpSocket_getreadyReadEvent(pObject)

Class QTcpServer

	pObject

	Func init P1
		pObject = QTcpServer_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QTcpServer_delete(pObject)

	Func ObjectPointer
		return pObject

	Func close 
		return QTcpServer_close(pObject)

	Func errorString 
		return QTcpServer_errorString(pObject)

	Func hasPendingConnections 
		return QTcpServer_hasPendingConnections(pObject)

	Func isListening 
		return QTcpServer_isListening(pObject)

	Func listen P1,P2
		return QTcpServer_listen(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func maxPendingConnections 
		return QTcpServer_maxPendingConnections(pObject)

	Func nextPendingConnection 
		pTempObj = new QTcpSocket
		pTempObj.pObject = QTcpServer_nextPendingConnection(pObject)
		return pTempObj

	Func pauseAccepting 
		return QTcpServer_pauseAccepting(pObject)

	Func proxy 
		pTempObj = new QNetworkProxy
		pTempObj.pObject = QTcpServer_proxy(pObject)
		return pTempObj

	Func resumeAccepting 
		return QTcpServer_resumeAccepting(pObject)

	Func serverAddress 
		pTempObj = new QHostAddress
		pTempObj.pObject = QTcpServer_serverAddress(pObject)
		return pTempObj

	Func serverError 
		return QTcpServer_serverError(pObject)

	Func serverPort 
		return QTcpServer_serverPort(pObject)

	Func setMaxPendingConnections P1
		return QTcpServer_setMaxPendingConnections(pObject,P1)

	Func setProxy P1
		return QTcpServer_setProxy(pObject,GetObjectPointerFromRingObject(P1))

	Func setSocketDescriptor P1
		return QTcpServer_setSocketDescriptor(pObject,GetObjectPointerFromRingObject(P1))

	Func socketDescriptor 
		return QTcpServer_socketDescriptor(pObject)

	Func waitForNewConnection P1,P2
		return QTcpServer_waitForNewConnection(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func setacceptErrorEvent P1
		return QTcpServer_setacceptErrorEvent(pObject,P1)

	Func setnewConnectionEvent P1
		return QTcpServer_setnewConnectionEvent(pObject,P1)

	Func getacceptErrorEvent 
		return QTcpServer_getacceptErrorEvent(pObject)

	Func getnewConnectionEvent 
		return QTcpServer_getnewConnectionEvent(pObject)

Class QHostAddress

	pObject

	Func init 
		pObject = QHostAddress_new()
		return self

	Func delete
		pObject = QHostAddress_delete(pObject)

	Func ObjectPointer
		return pObject

	Func clear 
		return QHostAddress_clear(pObject)

	Func isInSubnet P1,P2
		return QHostAddress_isInSubnet(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func isNull 
		return QHostAddress_isNull(pObject)

	Func protocol 
		return QHostAddress_protocol(pObject)

	Func scopeId 
		return QHostAddress_scopeId(pObject)

	Func setAddress P1
		return QHostAddress_setAddress(pObject,P1)

	Func toIPv4Address 
		return QHostAddress_toIPv4Address(pObject)

	Func toIPv6Address 
		return QHostAddress_toIPv6Address(pObject)

	Func toString 
		return QHostAddress_toString(pObject)

Class QHostInfo

	pObject

	Func init 
		pObject = QHostInfo_new()
		return self

	Func delete
		pObject = QHostInfo_delete(pObject)

	Func ObjectPointer
		return pObject

	Func error 
		return QHostInfo_error(pObject)

	Func errorString 
		return QHostInfo_errorString(pObject)

	Func hostName 
		return QHostInfo_hostName(pObject)

	Func lookupId 
		return QHostInfo_lookupId(pObject)

	Func setError P1
		return QHostInfo_setError(pObject,P1)

	Func setErrorString P1
		return QHostInfo_setErrorString(pObject,P1)

	Func setHostName P1
		return QHostInfo_setHostName(pObject,P1)

	Func setLookupId P1
		return QHostInfo_setLookupId(pObject,P1)

	Func abortHostLookup P1
		return QHostInfo_abortHostLookup(pObject,P1)

	Func fromName P1
		pTempObj = new QHostInfo
		pTempObj.pObject = QHostInfo_fromName(pObject,P1)
		return pTempObj

	Func localDomainName 
		return QHostInfo_localDomainName(pObject)

	Func localHostName 
		return QHostInfo_localHostName(pObject)

Class QNetworkRequest

	pObject

	Func init P1
		pObject = QNetworkRequest_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QNetworkRequest_delete(pObject)

	Func ObjectPointer
		return pObject

	Func attribute P1,P2
		pTempObj = new QVariant
		pTempObj.pObject = QNetworkRequest_attribute(pObject,P1,GetObjectPointerFromRingObject(P2))
		return pTempObj

	Func hasRawHeader P1
		return QNetworkRequest_hasRawHeader(pObject,GetObjectPointerFromRingObject(P1))

	Func header P1
		pTempObj = new QVariant
		pTempObj.pObject = QNetworkRequest_header(pObject,P1)
		return pTempObj

	Func originatingObject 
		pTempObj = new QObject
		pTempObj.pObject = QNetworkRequest_originatingObject(pObject)
		return pTempObj

	Func priority 
		return QNetworkRequest_priority(pObject)

	Func rawHeader P1
		pTempObj = new QByteArray
		pTempObj.pObject = QNetworkRequest_rawHeader(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

	Func setAttribute P1,P2
		return QNetworkRequest_setAttribute(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func setHeader P1,P2
		return QNetworkRequest_setHeader(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func setOriginatingObject P1
		return QNetworkRequest_setOriginatingObject(pObject,GetObjectPointerFromRingObject(P1))

	Func setPriority P1
		return QNetworkRequest_setPriority(pObject,P1)

	Func setRawHeader P1,P2
		return QNetworkRequest_setRawHeader(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2))

	Func setUrl P1
		return QNetworkRequest_setUrl(pObject,GetObjectPointerFromRingObject(P1))

	Func swap P1
		return QNetworkRequest_swap(pObject,GetObjectPointerFromRingObject(P1))

	Func url 
		pTempObj = new QUrl
		pTempObj.pObject = QNetworkRequest_url(pObject)
		return pTempObj

Class QNetworkReply from QIODevice

	pObject

	Func init 
		pObject = QNetworkReply_new()
		return self

	Func delete
		pObject = QNetworkReply_delete(pObject)

	Func ObjectPointer
		return pObject

	Func attribute P1
		pTempObj = new QVariant
		pTempObj.pObject = QNetworkReply_attribute(pObject,P1)
		return pTempObj

	Func error 
		return QNetworkReply_error(pObject)

	Func hasRawHeader P1
		return QNetworkReply_hasRawHeader(pObject,GetObjectPointerFromRingObject(P1))

	Func header P1
		pTempObj = new QVariant
		pTempObj.pObject = QNetworkReply_header(pObject,P1)
		return pTempObj

	Func isFinished 
		return QNetworkReply_isFinished(pObject)

	Func isRunning 
		return QNetworkReply_isRunning(pObject)

	Func manager 
		pTempObj = new QNetworkAccessManager
		pTempObj.pObject = QNetworkReply_manager(pObject)
		return pTempObj

	Func operation 
		return QNetworkReply_operation(pObject)

	Func rawHeader P1
		pTempObj = new QByteArray
		pTempObj.pObject = QNetworkReply_rawHeader(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

	Func readBufferSize 
		return QNetworkReply_readBufferSize(pObject)

	Func request 
		pTempObj = new QNetworkRequest
		pTempObj.pObject = QNetworkReply_request(pObject)
		return pTempObj

	Func url 
		pTempObj = new QUrl
		pTempObj.pObject = QNetworkReply_url(pObject)
		return pTempObj

Class QNetworkAccessManager from QObject

	pObject

	Func init P1
		pObject = QNetworkAccessManager_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QNetworkAccessManager_delete(pObject)

	Func ObjectPointer
		return pObject

	Func setfinishedEvent P1
		return QNetworkAccessManager_setfinishedEvent(pObject,P1)

	Func getfinishedEvent 
		return QNetworkAccessManager_getfinishedEvent(pObject)

	Func cache 
		return QNetworkAccessManager_cache(pObject)

	Func clearAccessCache 
		return QNetworkAccessManager_clearAccessCache(pObject)

	Func connectToHost P1,P2
		return QNetworkAccessManager_connectToHost(pObject,P1,P2)

	Func cookieJar 
		return QNetworkAccessManager_cookieJar(pObject)

	Func deleteResource P1
		pTempObj = new QNetworkReply
		pTempObj.pObject = QNetworkAccessManager_deleteResource(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

	Func getvalue P1
		pTempObj = new QNetworkReply
		pTempObj.pObject = QNetworkAccessManager_get(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

	Func head P1
		pTempObj = new QNetworkReply
		pTempObj.pObject = QNetworkAccessManager_head(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

	Func post P1,P2
		pTempObj = new QNetworkReply
		pTempObj.pObject = QNetworkAccessManager_post(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2))
		return pTempObj

	Func proxy 
		pTempObj = new QNetworkProxy
		pTempObj.pObject = QNetworkAccessManager_proxy(pObject)
		return pTempObj

	Func proxyFactory 
		return QNetworkAccessManager_proxyFactory(pObject)

	Func putvalue P1,P2
		pTempObj = new QNetworkReply
		pTempObj.pObject = QNetworkAccessManager_put(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2))
		return pTempObj

	Func sendCustomRequest P1,P2,P3
		pTempObj = new QNetworkReply
		pTempObj.pObject = QNetworkAccessManager_sendCustomRequest(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2),GetObjectPointerFromRingObject(P3))
		return pTempObj

	Func setCache P1
		return QNetworkAccessManager_setCache(pObject,GetObjectPointerFromRingObject(P1))

	Func setCookieJar P1
		return QNetworkAccessManager_setCookieJar(pObject,GetObjectPointerFromRingObject(P1))

	Func setProxy P1
		return QNetworkAccessManager_setProxy(pObject,GetObjectPointerFromRingObject(P1))

	Func setProxyFactory P1
		return QNetworkAccessManager_setProxyFactory(pObject,GetObjectPointerFromRingObject(P1))

	Func supportedSchemes 
		pTempObj = new QStringList
		pTempObj.pObject = QNetworkAccessManager_supportedSchemes(pObject)
		return pTempObj

	Func geteventparameters 
		return QNetworkAccessManager_geteventparameters(pObject)

Class QQmlError

	pObject

	Func init 
		pObject = QQmlError_new()
		return self

	Func delete
		pObject = QQmlError_delete(pObject)

	Func ObjectPointer
		return pObject

	Func column 
		return QQmlError_column(pObject)

	Func description 
		return QQmlError_description(pObject)

	Func isValid 
		return QQmlError_isValid(pObject)

	Func line 
		return QQmlError_line(pObject)

	Func object 
		pTempObj = new QObject
		pTempObj.pObject = QQmlError_object(pObject)
		return pTempObj

	Func setColumn P1
		return QQmlError_setColumn(pObject,P1)

	Func setDescription P1
		return QQmlError_setDescription(pObject,P1)

	Func setLine P1
		return QQmlError_setLine(pObject,P1)

	Func setObject P1
		return QQmlError_setObject(pObject,GetObjectPointerFromRingObject(P1))

	Func setUrl P1
		return QQmlError_setUrl(pObject,GetObjectPointerFromRingObject(P1))

	Func toString 
		return QQmlError_toString(pObject)

	Func url 
		pTempObj = new QUrl
		pTempObj.pObject = QQmlError_url(pObject)
		return pTempObj

Class QQmlEngine

	pObject

	Func init P1
		pObject = QQmlEngine_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QQmlEngine_delete(pObject)

	Func ObjectPointer
		return pObject

	Func addImageProvider P1,P2
		return QQmlEngine_addImageProvider(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func addImportPath P1
		return QQmlEngine_addImportPath(pObject,P1)

	Func addPluginPath P1
		return QQmlEngine_addPluginPath(pObject,P1)

	Func baseUrl 
		pTempObj = new QUrl
		pTempObj.pObject = QQmlEngine_baseUrl(pObject)
		return pTempObj

	Func clearComponentCache 
		return QQmlEngine_clearComponentCache(pObject)

	Func imageProvider P1
		return QQmlEngine_imageProvider(pObject,P1)

	Func importPathList 
		pTempObj = new QStringList
		pTempObj.pObject = QQmlEngine_importPathList(pObject)
		return pTempObj

	Func importPlugin P1,P2,P3
		return QQmlEngine_importPlugin(pObject,P1,P2,GetObjectPointerFromRingObject(P3))

	Func incubationController 
		return QQmlEngine_incubationController(pObject)

	Func networkAccessManager 
		pTempObj = new QNetworkAccessManager
		pTempObj.pObject = QQmlEngine_networkAccessManager(pObject)
		return pTempObj

	Func networkAccessManagerFactory 
		return QQmlEngine_networkAccessManagerFactory(pObject)

	Func offlineStorageDatabaseFilePath P1
		return QQmlEngine_offlineStorageDatabaseFilePath(pObject,P1)

	Func offlineStoragePath 
		return QQmlEngine_offlineStoragePath(pObject)

	Func outputWarningsToStandardError 
		return QQmlEngine_outputWarningsToStandardError(pObject)

	Func pluginPathList 
		pTempObj = new QStringList
		pTempObj.pObject = QQmlEngine_pluginPathList(pObject)
		return pTempObj

	Func removeImageProvider P1
		return QQmlEngine_removeImageProvider(pObject,P1)

	Func rootContext 
		return QQmlEngine_rootContext(pObject)

	Func setBaseUrl P1
		return QQmlEngine_setBaseUrl(pObject,GetObjectPointerFromRingObject(P1))

	Func setImportPathList P1
		return QQmlEngine_setImportPathList(pObject,GetObjectPointerFromRingObject(P1))

	Func setIncubationController P1
		return QQmlEngine_setIncubationController(pObject,GetObjectPointerFromRingObject(P1))

	Func setNetworkAccessManagerFactory P1
		return QQmlEngine_setNetworkAccessManagerFactory(pObject,GetObjectPointerFromRingObject(P1))

	Func setOfflineStoragePath P1
		return QQmlEngine_setOfflineStoragePath(pObject,P1)

	Func setOutputWarningsToStandardError P1
		return QQmlEngine_setOutputWarningsToStandardError(pObject,P1)

	Func setPluginPathList P1
		return QQmlEngine_setPluginPathList(pObject,GetObjectPointerFromRingObject(P1))

	Func trimComponentCache 
		return QQmlEngine_trimComponentCache(pObject)

	Func retranslate 
		return QQmlEngine_retranslate(pObject)

	Func contextForObject P1
		return QQmlEngine_contextForObject(pObject,GetObjectPointerFromRingObject(P1))

	Func objectOwnership P1
		return QQmlEngine_objectOwnership(pObject,GetObjectPointerFromRingObject(P1))

	Func setContextForObject P1,P2
		return QQmlEngine_setContextForObject(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2))

	Func setObjectOwnership P1,P2
		return QQmlEngine_setObjectOwnership(pObject,GetObjectPointerFromRingObject(P1),P2)

Class QSize

	pObject

	Func init P1,P2
		pObject = QSize_new(P1,P2)
		return self

	Func delete
		pObject = QSize_delete(pObject)

	Func ObjectPointer
		return pObject

Class QVariant2 from QVariant

	pObject

	Func init P1
		pObject = QVariant2_new(P1)
		return self

	Func delete
		pObject = QVariant2_delete(pObject)

	Func ObjectPointer
		return pObject

Class QVariant3 from QVariant

	pObject

	Func init P1
		pObject = QVariant3_new(P1)
		return self

	Func delete
		pObject = QVariant3_delete(pObject)

	Func ObjectPointer
		return pObject

Class QVariant4 from QVariant

	pObject

	Func init P1
		pObject = QVariant4_new(P1)
		return self

	Func delete
		pObject = QVariant4_delete(pObject)

	Func ObjectPointer
		return pObject

Class QVariantInt from QVariant

	pObject

	Func init P1
		pObject = QVariantInt_new(P1)
		return self

	Func delete
		pObject = QVariantInt_delete(pObject)

	Func ObjectPointer
		return pObject

Class QVariantFloat from QVariant

	pObject

	Func init P1
		pObject = QVariantFloat_new(P1)
		return self

	Func delete
		pObject = QVariantFloat_delete(pObject)

	Func ObjectPointer
		return pObject

Class QVariantDouble from QVariant

	pObject

	Func init P1
		pObject = QVariantDouble_new(P1)
		return self

	Func delete
		pObject = QVariantDouble_delete(pObject)

	Func ObjectPointer
		return pObject

Class QFile2 from QFile

	pObject

	Func init P1
		pObject = QFile2_new(P1)
		return self

	Func delete
		pObject = QFile2_delete(pObject)

	Func ObjectPointer
		return pObject

Class QPixmap2 from QPixmap

	pObject

	Func init P1,P2
		pObject = QPixmap2_new(P1,P2)
		return self

	Func delete
		pObject = QPixmap2_delete(pObject)

	Func ObjectPointer
		return pObject

Class QIcon

	pObject

	Func init P1
		pObject = QIcon_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QIcon_delete(pObject)

	Func ObjectPointer
		return pObject
