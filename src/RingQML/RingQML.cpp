/*
    Project      : RingQML library for Ring Programming Language
    Author       : Mohannad Azeez Al-Ayash 
    E-Mail       : mohannadazazalayash@gmail.com
    WebSite      : https://mohannad-aldulaimi.github.io
	Date         : 29/12/2025
*/
#include <QObject>
#include <QVariant>
#include <QQmlEngine>
#include <QQuickImageProvider>
#include <QPixmap>
#include <QMap>
#include <QQuickWidget>
#include <QQuickView>
#include <QQmlApplicationEngine>
#include <QQuickItem>
#include <QString>
#include <QVariantList>
#include <QVariantMap>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QSet>
#include <QImage>
#include <QDebug>
#include <QJSValue>
#include <QQmlContext>
#include <QQmlComponent>
#include <QTemporaryDir>
#include <QFile>
#include <QTextStream>
#include <QDir>
#include <QLibraryInfo>
#include <QEventLoop>
#include <QMetaProperty>
#include <QQuickItemGrabResult>
#include <QSharedPointer>
#include <QIcon>
#include <QGuiApplication>
#include "RingQML.h"



// File : ring_qml_core.cpp
	RingQML *Ringbridge = nullptr;
	RingQML::RingQML(VM* vm, QObject* parent) 
	    : QObject(parent), m_vm(vm) 
	{
	}
	void RingQML::setVM(VM* vm) {
	    if (!m_vm) m_vm = vm;
	}
	void RingQML::callEvent(const QString& eventCode) {
	    if (!m_vm) return;
	    // ring_state_runcode requires the RingState pointer
	    ring_state_runcode(m_vm->pRingState, eventCode.toUtf8().data());
	}
	void RingQML::eval(const QString& code) {
	    callEvent(code);
	}
	QVariant RingQML::setVar(const QString& varName, const QVariant& valueIn) { 
	    // Create a mutable copy of the value.
	    // This solves the "const QVariant" assignment error because we are modifying our local copy, not the input ref.
	    QVariant value = valueIn;
	    // --- FIX START ---
	    // Check if the variant contains a QJSValue (common when coming from QML)
	    if (value.userType() == qMetaTypeId<QJSValue>()) {
	        QJSValue jsVal = value.value<QJSValue>();
	        // toVariant() converts JS Arrays to QVariantList and JS Objects to QVariantMap
	        value = jsVal.toVariant(); 
	    }
	    // --- FIX END ---
	    if (!m_vm) return QVariant(false);
	    QByteArray nameUtf8 = varName.toUtf8().toLower();
	    List* pList = ring_state_findvar(m_vm->pRingState, nameUtf8.data());
	    if (!pList) {
	        qWarning() << "RingQML: Variable not found:" << varName;
	        return QVariant(false);
	    }
	    // 1. Collections (Maps/Lists)
	    if (value.type() == QVariant::Map) {
	        ring_list_setlist_gc(m_vm->pRingState,pList,RING_VAR_VALUE);
	        List* pVarList = ring_list_getlist(pList,RING_VAR_VALUE);
	        ring_list_deleteallitems_gc(m_vm->pRingState, pVarList);
	        // FIX: Use a temp list to catch the sub-list created by the helper, then copy its content.
	        // This avoids the nesting issue [[key, val], ...]
	        List* pTemp = ring_list_new_gc(m_vm->pRingState, 0);
	        qVariantMapToRingList(m_vm, pTemp, value.toMap());
	        if (ring_list_getsize(pTemp) > 0 && ring_list_islist(pTemp, 1)) {
	             List* pGeneratedList = ring_list_getlist(pTemp, 1);
	             ring_list_copy(pVarList, pGeneratedList);
	        }
	        ring_list_delete_gc(m_vm->pRingState, pTemp);
	        return QVariant(true);
	    } 
	    if (value.type() == QVariant::List) {
	        ring_list_setlist_gc(m_vm->pRingState,pList,RING_VAR_VALUE);
	        List* pVarList = ring_list_getlist(pList,RING_VAR_VALUE);
	        ring_list_deleteallitems_gc(m_vm->pRingState, pVarList);
	        // FIX: Use a temp list to catch the sub-list created by the helper, then copy its content.
	        // This ensures pVarList becomes [1,2,3] instead of [[1,2,3]]
	        List* pTemp = ring_list_new_gc(m_vm->pRingState, 0);
	        qVariantListToRingList(m_vm, pTemp, value.toList());
	        // The helper adds a new list as the first item of pTemp
	        if (ring_list_getsize(pTemp) > 0 && ring_list_islist(pTemp, 1)) {
	             List* pGeneratedList = ring_list_getlist(pTemp, 1);
	             ring_list_copy(pVarList, pGeneratedList);
	        }
	        ring_list_delete_gc(m_vm->pRingState, pTemp);
	        return QVariant(true);
	    }
	    if (value.type() == QVariant::Bool) {
	        ring_list_setdouble_gc(m_vm->pRingState, pList,RING_VAR_VALUE, value.toBool() ? 1.0 : 0.0);
	        return QVariant(true);
	    }
	    if (value.type() == QVariant::Int || value.type() == QVariant::LongLong || value.type() == QVariant::UInt) {
	        ring_list_setdouble_gc(m_vm->pRingState, pList,RING_VAR_VALUE, (double)value.toLongLong());
	        return QVariant(true);
	    }
	    if (value.type() == QVariant::Double) {
	        ring_list_setdouble_gc(m_vm->pRingState, pList,RING_VAR_VALUE, value.toDouble());
	        return QVariant(true);
	    }
	    // 3. Strings (and anything that naturally acts as one)
	    if (value.canConvert<QString>() && value.type() != QVariant::UserType) {
	        ring_list_setstring_gc(m_vm->pRingState, pList,RING_VAR_VALUE, value.toString().toUtf8().constData());
	        return QVariant(true);
	    }
	    // 4. QObject Pointers (Standard Qt Objects)
	    if (value.canConvert<QObject*>()) {
	        ring_list_setlist_gc(m_vm->pRingState,pList,RING_VAR_VALUE);
	        QObject* obj = value.value<QObject*>();
	        List* pPtrList = ring_list_newlist_gc(m_vm->pRingState,ring_list_getlist(pList,RING_VAR_VALUE) ); 
	        ring_list_addpointer_gc(m_vm->pRingState, pPtrList, obj);
	        ring_list_addstring_gc(m_vm->pRingState, pPtrList, "QObject");
	        ring_list_adddouble_gc(m_vm->pRingState, pPtrList, 0.0);
	        return QVariant(true);
	    }
	    // 5. Fallback: Raw/Void/Custom Pointer Handling
	    // This logic extracts raw pointers from QVariants (e.g. void*, custom structs)
	    {
	        void* obj = nullptr;
	        // Check if it is strictly a void* type
	        if (value.userType() == QMetaType::VoidStar) {
	             obj = value.value<void*>();
	        } else {
	             // For registered custom pointer types, the QVariant data holds the pointer itself. 
	             // We cast the internal constData pointer to a pointer-to-void-pointer, then dereference it.
	             obj = *reinterpret_cast<void* const *>(value.constData());
	        }
	        const char * ptrType = value.typeName();
	        ring_list_setlist_gc(m_vm->pRingState,pList,RING_VAR_VALUE);
	        List* pPtrList = ring_list_newlist_gc(m_vm->pRingState,ring_list_getlist(pList,RING_VAR_VALUE) ); 
	        ring_list_addpointer_gc(m_vm->pRingState, pPtrList, obj);
	        // Use type name if available, otherwise generic
	        ring_list_addstring_gc(m_vm->pRingState, pPtrList, ptrType ? ptrType : "void*");
	        ring_list_adddouble_gc(m_vm->pRingState, pPtrList, 0.0);
	    }
	    return QVariant(true); // Added default return
	}
	QVariant RingQML::getVar(const QString& varName) {
	    if (!m_vm) return QVariant();
	    QByteArray nameUtf8 = varName.toUtf8().toLower();
	    List* pList = ring_state_findvar(m_vm->pRingState, nameUtf8.data());
	    if (!pList) {
	        qWarning() << "RingQML: Variable not found:" << varName;
	        return QVariant();
	    }
	    // The variable structure in Ring: [Type, Value, ...]
	    if (ring_list_isstring(pList, RING_VAR_VALUE)) {
	        QString str = QString::fromUtf8(ring_list_getstring(pList, RING_VAR_VALUE));
	        // Check if it's JSON-like string
	        QString trimmed = str.trimmed();
	        if ((trimmed.startsWith('{') && trimmed.endsWith('}')) ||
	            (trimmed.startsWith('[') && trimmed.endsWith(']'))) {
	             QJsonParseError err;
	             QJsonDocument doc = QJsonDocument::fromJson(trimmed.toUtf8(), &err);
	             if (err.error == QJsonParseError::NoError && doc.isObject()) {
	                 return doc.toVariant();
	             }
	        }
	        return str;
	    } else if (ring_list_isdouble(pList, RING_VAR_VALUE)) {
	        return QVariant(ring_list_getdouble(pList, RING_VAR_VALUE));
	    } else if (ring_list_islist(pList, RING_VAR_VALUE)) {
	        return ringListToQVariant(ring_list_getlist(pList, RING_VAR_VALUE));
	    }
	    return QVariant();
	}
	QVariant RingQML::callFunc(const QString& funcName, const QVariantList& params) {
	    if (!m_vm) return QVariant();
	        List *pList,*pCallingFuncInfoList;
	        pList = ring_state_findvar(m_vm->pRingState, "g_afunctionscalledfromqml");
	        if (! pList){
	            printf("RingQML Error: Using uninitialized Global variable : g_afunctionscalledfromqml \n");
	        }
	        pList = ring_list_getlist(pList,RING_VAR_VALUE);
	        pCallingFuncInfoList = ring_list_newlist_gc(m_vm->pRingState,pList);
	        ring_list_addstring_gc(m_vm->pRingState,pCallingFuncInfoList,funcName.toUtf8().data());
	        qVariantToRingList(m_vm ,pCallingFuncInfoList ,params );
			ring_vm_callfuncwithouteval(m_vm,"ringqmlexecutefunctioncallfromqml",RING_FALSE );
	        return this->getVar("g_functioncalledfromqml_out");
	}
	QString RingQML::getImage(const QVariant& id) {
	    return QString("image://RingProvider/%1").arg(id.toString());
	}


// File : ring_qml_image.cpp
	SharedPixmapProvider::SharedPixmapProvider() 
	    : QQuickImageProvider(QQuickImageProvider::Pixmap), m_nextId(1) 
	{
	}
	int SharedPixmapProvider::shareImage(const QPixmap &pixmap) {
	    int id = m_nextId++;
	    m_pixmaps[id] = pixmap;
	    return id;
	}
	QPixmap SharedPixmapProvider::requestPixmap(const QString &idStr, QSize *size, const QSize &requestedSize) {
	    bool ok;
	    int id = idStr.toInt(&ok);
	    if (!ok || !m_pixmaps.contains(id)) return QPixmap();
	    QPixmap pixmap = m_pixmaps[id];
	    if (size) *size = pixmap.size();
	    if (requestedSize.width() > 0 && requestedSize.height() > 0) {
	        return pixmap.scaled(requestedSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);
	    }
	    return pixmap;
	}
	int exposePixmapToQML(QQmlEngine* engine, const QPixmap& pixmap) {
	    if (!engine) return -1;
	    static const QString providerId = "RingProvider";
	    SharedPixmapProvider* provider = dynamic_cast<SharedPixmapProvider*>(engine->imageProvider(providerId));
	    if (!provider) {
	        provider = new SharedPixmapProvider();
	        engine->addImageProvider(providerId, provider);
	    }
	    return provider->shareImage(pixmap);
	}


// File : ring_qml_loader.cpp
	void SetRingEventForCallFromQML(VM *pVm, QQmlEngine* qmlEngine) {
	    if (!qmlEngine || !pVm) return;
	    Ringbridge = new RingQML(pVm, qmlEngine);
	    qmlEngine->rootContext()->setContextProperty("Ring", Ringbridge);
	}
	void setQuickColorLikeWindow(QQuickWidget* quickWidget) {
	    if (!quickWidget) return;
	    quickWidget->setClearColor(QColor(245, 236, 230)); // Default Ring beige
	    quickWidget->setStyleSheet("QQuickWidget { background: transparent; border: none; }");
	    if (QWidget* parent = quickWidget->parentWidget()) {
	        parent->setProperty("quickContainer", true);
	        parent->setStyleSheet("[quickContainer=\"true\"] { background-color: #f5ece6; border: none; }");
	    }
	}
	// --- Common Helper for Async Loading ---
	// Waits for a QObject (Loader or Widget) to reach a specific property state
	void waitForStatus(QObject* object, const char* signal, const char* propName, int targetValue) {
	    if (object->property(propName).toInt() == targetValue) return;
	    QEventLoop loop;
	    QObject::connect(object, signal, &loop, SLOT(quit()));
	    // Double check to avoid hanging if signal fired before connect
	    if (object->property(propName).toInt() != targetValue) {
	        loop.exec();
	    }
	}
	QQuickItem* loadQmlFromContentView(QQuickView *view, const char* qmlContent) {
	    if (!view || !qmlContent) return nullptr;
	    QQmlEngine *engine = view->engine();
	    QQmlComponent *userComponent = new QQmlComponent(engine, view);
	    // Path resolution
	    QUrl baseUrl;
	    #if defined(Q_OS_WIN)
	        QString currentPath = QDir::currentPath();
	        baseUrl = QUrl::fromLocalFile(currentPath.endsWith('/') ? currentPath : currentPath + '/');
	        engine->addImportPath(currentPath);
	    #else
	        baseUrl = QUrl("qrc:/");
	    #endif
	    // Prepend Imports
	    QByteArray finalContent = qmlContent;
	    userComponent->setData(finalContent, baseUrl.resolved(QUrl("code.qml")));
	    if (userComponent->isError()) {
	        qWarning() << "RingQML Error:" << userComponent->errorString();
	        delete userComponent;
	        return nullptr;
	    }
	    // Create Host Loader
	    QQmlComponent hostComponent(engine, view);
	    hostComponent.setData("import QtQuick 2.0; Loader { anchors.fill: parent }", baseUrl);
	    QObject* hostObject = hostComponent.create();
	    QQuickItem* hostItem = qobject_cast<QQuickItem*>(hostObject);
	    if (hostItem) {
	        hostItem->setProperty("sourceComponent", QVariant::fromValue(userComponent));
	        hostItem->setParentItem(view->contentItem());
	        // Wait for loader to finish (Status 1 = Ready)
	        waitForStatus(hostItem, "2statusChanged()", "status", 1);
	        if (hostItem->property("status").toInt() == 1) {
	            return hostItem->property("item").value<QQuickItem*>();
	        }
	    }
	    delete hostObject;
	    return nullptr;
	}
	QQuickItem* loadQmlFromContentWidget(QQuickWidget *widget, const char* qmlContent) {
	    if (!widget || !qmlContent) return nullptr;
	    widget->setResizeMode(QQuickWidget::SizeRootObjectToView);
	    QQmlEngine *engine = widget->engine();
	    // 1. Create User Component
	    QQmlComponent *userComponent = new QQmlComponent(engine, widget);
	    QUrl baseUrl;
	    #if defined(Q_OS_WIN)
	        QString currentPath = QDir::currentPath();
	        baseUrl = QUrl::fromLocalFile(currentPath.endsWith('/') ? currentPath : currentPath + '/');
	        engine->addImportPath(currentPath);
	    #else
	        baseUrl = QUrl("qrc:/");
	    #endif
	    userComponent->setData(qmlContent, baseUrl.resolved(QUrl("code.qml")));
	    if (userComponent->isError()) {
	        qWarning() << "RingQML Component Error:" << userComponent->errorString();
	        delete userComponent;
	        return nullptr;
	    }
	    // 2. Set Context Property
	    engine->rootContext()->setContextProperty("dynamicUserComponentLoaderContent", QVariant::fromValue(userComponent));
	    // 3. Load Host QML via Source
	    const char* hostQml = "import QtQuick 2.0; import QtQuick.Controls 2.0; Rectangle { color: 'transparent'; Loader { anchors.fill: parent; sourceComponent: dynamicUserComponentLoaderContent; focus: true } }";
	    // Data URL for the host
	    QByteArray hostData = QByteArray(hostQml);
	    QUrl hostUrl("data:text/qml;charset=utf-8," + hostData.toPercentEncoding());
	    widget->setSource(hostUrl);
	    // 4. Wait for Widget
	    if (widget->status() != QQuickWidget::Ready) {
	        QEventLoop loop;
	        QObject::connect(widget, SIGNAL(statusChanged(QQuickWidget::Status)), &loop, SLOT(quit()));
	        loop.exec();
	    }
	    if (widget->status() != QQuickWidget::Ready) return nullptr;
	    // 5. Find the inner loader and return its item
	    QQuickItem* root = widget->rootObject();
	    if (root) {
	        // We know the structure is Rect -> Loader
	        QQuickItem* loader = root->childItems().isEmpty() ? nullptr : root->childItems().first();
	        if (loader) {
	             waitForStatus(loader, "2statusChanged()", "status", 1);
	             return loader->property("item").value<QQuickItem*>();
	        }
	    }
	    return nullptr;
	}
	QQuickItem* loadQmlFromContentEngine(QQmlApplicationEngine *engine, const char* qmlContent) {
	    if (!engine || !qmlContent) return nullptr;
	    QQmlComponent component(engine);
	    QUrl baseUrl = QUrl::fromLocalFile(QDir::currentPath() + "/");
	    component.setData(qmlContent, baseUrl.resolved(QUrl("code.qml")));
	    if (component.isError()) {
	        qWarning() << component.errorString();
	        return nullptr;
	    }
	    QObject* obj = component.create();
	    // If it's a Window
	    if (QQuickWindow* win = qobject_cast<QQuickWindow*>(obj)) {
	        return win->contentItem();
	    }
	    // If it's an Item
	    return qobject_cast<QQuickItem*>(obj);
	}
	QQuickItem* createNewComponent(QQmlEngine* engine, const char* componentName, const char* qmlCode) {
	    if (!engine || !componentName || !qmlCode) return nullptr;
	    static QTemporaryDir tempDir;
	    if (!tempDir.isValid()) return nullptr;
	    QString nameStr(componentName);
	    if (!nameStr.isEmpty()) nameStr[0] = nameStr[0].toUpper(); // Force Capitalized
	    QString fileName = nameStr + ".qml";
	    QString fullPath = tempDir.filePath(fileName);
	    QFile file(fullPath);
	    if (file.open(QIODevice::WriteOnly)) {
	        // no need to UTF-8 here the input char* is already in this encoding format.
	        file.write(qmlCode);
	        file.close();
	    } else {
	        return nullptr;
	    }
	    // Register type
	    QUrl url = QUrl::fromLocalFile(fullPath);
	    qmlRegisterType(url, "Dynamic", 1, 0, nameStr.toUtf8().constData());
	    QQmlComponent* component = new QQmlComponent(engine, url);
	    if (component->isError()) {
	        qWarning() << component->errorString();
	        delete component;
	        return nullptr;
	    }
	    // Also register as context property for legacy support
	    engine->rootContext()->setContextProperty(QString(componentName), component);
	    QObject* obj = component->create();
	    QQuickItem* item = qobject_cast<QQuickItem*>(obj);
	    if (item) QQmlEngine::setObjectOwnership(item, QQmlEngine::CppOwnership);
	    return item;
	}
	bool callQmlFunction(QQuickItem* rootItem, const char* functionName, const QVariantList& params) {
	    if (!rootItem) return false;
	    QVariant result;
	    QVariant genericParams[10]; // Max 10 args support
	    for(int i=0; i<params.size() && i<10; ++i) genericParams[i] = params[i];
	    return QMetaObject::invokeMethod(rootItem, functionName, 
	        params.size() > 0 ? Q_ARG(QVariant, genericParams[0]) : QGenericArgument(),
	        params.size() > 1 ? Q_ARG(QVariant, genericParams[1]) : QGenericArgument(),
	        params.size() > 2 ? Q_ARG(QVariant, genericParams[2]) : QGenericArgument(),
	        params.size() > 3 ? Q_ARG(QVariant, genericParams[3]) : QGenericArgument(),
	        params.size() > 4 ? Q_ARG(QVariant, genericParams[4]) : QGenericArgument(),
	        params.size() > 5 ? Q_ARG(QVariant, genericParams[5]) : QGenericArgument(),
	        params.size() > 6 ? Q_ARG(QVariant, genericParams[6]) : QGenericArgument(),
	        params.size() > 7 ? Q_ARG(QVariant, genericParams[7]) : QGenericArgument(),
	        params.size() > 8 ? Q_ARG(QVariant, genericParams[8]) : QGenericArgument(),
	        params.size() > 9 ? Q_ARG(QVariant, genericParams[9]) : QGenericArgument()
	    );
	}


// File : ring_qml_utils.cpp
	QImage* grabItemSnapshot(QQuickItem* rootItem, const char* objectName){
	    // 1. Safety Checks
	    if (!rootItem) {
	        qWarning("Snapshot Error: rootItem is NULL");
	        return nullptr;
	    }
	    // 2. Find the child item by name
	    // (If objectName is empty/null, we assume you want to grab the rootItem itself)
	    QQuickItem* target = rootItem;
	    if (objectName && objectName[0] != '\0') {
	        target = rootItem->findChild<QQuickItem*>(QString::fromUtf8(objectName));
	    }
	    if (!target) {
	        qWarning("Snapshot Error: Could not find item '%s'", objectName);
	        return nullptr;
	    }
	    // 3. Start the Grab
	    auto grabResult = target->grabToImage();
	    if (!grabResult) return nullptr;
	    // 4. Wait for it to finish (Synchronous block)
	    QEventLoop loop;
	    QObject::connect(grabResult.data(), &QQuickItemGrabResult::ready, &loop, &QEventLoop::quit);
	    loop.exec(); 
	    // 5. Return the image (Caller owns this pointer!)
	    return new QImage(grabResult->image());
	}
	QVariant ringListToQVariant(List* pList) {
	    if (!pList) {
	        return QVariant(QVariantList());
	    }
	    int nSize = ring_list_getsize(pList);
	    bool looksLikeHashTable = (nSize % 2 == 0 && nSize > 0);
	    if ( nSize==3 ){
	        if (ring_list_ispointer(pList, 1)){
	            void* ptr = ring_list_getpointer(pList, 1);
	            QString typeName = ring_list_getstring(pList, 2);
	            QVariant var;
	            if (typeName == "QObject") {
	                QObject* obj = static_cast<QObject*>(ptr);
	                var.setValue(obj);
	                return var;
	            }
	        }
	    }
	    // Check if this looks like a hash table (even number of elements, alternating key-value)
	   if (looksLikeHashTable) {
	        for (int i = 1; i <= nSize; i += 2) {
	            if (!ring_list_isstring(pList, i)) {
	                looksLikeHashTable = false;
	                break;
	            }
	            // Check if key contains spaces (invalid for hash table keys)
	            const char* keyStr = ring_list_getstring(pList, i);
	            std::string key = std::string(keyStr);
	            if (key.find(' ') != std::string::npos || key.find('.') != std::string::npos || key.find(',') != std::string::npos || key.find('|') != std::string::npos || key.find('/') != std::string::npos || key.find('\\') != std::string::npos) {
	                looksLikeHashTable = false;
	                break;
	            }
	        }
	    }
	    if (looksLikeHashTable) {
	        // Process as hash table (QVariantMap)
	        QVariantMap variantMap;
	        for (int i = 1; i <= nSize; i += 2) {
	            QString key = QString::fromUtf8(ring_list_getstring(pList, i));
	            int valueType = ring_list_gettype(pList, i + 1);
	            switch (valueType) {
	                case ITEMTYPE_STRING:
	                    variantMap[key] = QString::fromUtf8(ring_list_getstring(pList, i + 1));
	                    break;
	                case ITEMTYPE_NUMBER:
	                    variantMap[key] = ring_list_getdouble(pList, i + 1);
	                    break;
	                case ITEMTYPE_LIST:
	                    variantMap[key] = ringListToQVariant(ring_list_getlist(pList, i + 1));
	                    break;
	                case ITEMTYPE_POINTER:
	                {
	                    void* ptr = ring_list_getpointer(pList, i + 1);
	                    QString typeName = ring_list_getstring(pList, i + 2);
	                    if (typeName == "QObject") {
	                        QObject* obj = static_cast<QObject*>(ptr);
	                        QVariant var;
	                        var.setValue(obj);
	                        variantMap[key] = var;
	                    } else {
	                        variantMap[key] = QVariant();
	                    }
	                    i++; // Skip the type name
	                    break;
	                }
	                default:
	                {
	                    const char* str = ring_list_getstring(pList, i + 1);
	                    if (str) {
	                        QString jsonString = QString::fromUtf8(str);
	                        if ((jsonString.trimmed().startsWith('{') && jsonString.trimmed().endsWith('}')) ||
	                            (jsonString.trimmed().startsWith('[') && jsonString.trimmed().endsWith(']'))) {
	                            QJsonParseError error;
	                            QJsonDocument doc = QJsonDocument::fromJson(jsonString.toUtf8(), &error);
	                            if (error.error == QJsonParseError::NoError) {
	                                variantMap[key] = doc.toVariant();
	                            } else {
	                                variantMap[key] = jsonString;
	                            }
	                        } else {
	                            variantMap[key] = jsonString;
	                        }
	                    } else {
	                        variantMap[key] = QVariant();
	                    }
	                    break;
	                }
	            }
	        }
	        return QVariant(variantMap);
	    }
	    // Otherwise, process as regular list/array
	    QVariantList variantList;
	    for (int i = 1; i <= nSize; ++i) {
	        int type = ring_list_gettype(pList, i);
	        switch (type) {
	            case ITEMTYPE_STRING: {
	                const char* str = ring_list_getstring(pList, i);
	                if (str) {
	                    variantList.append(QString::fromUtf8(str));
	                } else {
	                    variantList.append(QString());
	                }
	                break;
	            }
	            case ITEMTYPE_NUMBER: {
	                double num = ring_list_getdouble(pList, i);
	                if (num == (int)num) {
	                    variantList.append((int)num);
	                } else {
	                    variantList.append(num);
	                }
	                break;
	            }
	            case ITEMTYPE_POINTER: {
	                void* ptr = ring_list_getpointer(pList, i);
	                QString typeName = ring_list_getstring(pList, i + 1);
	                if (typeName == "QObject") {
	                    QObject* obj = static_cast<QObject*>(ptr);
	                    QVariant var;
	                    var.setValue(obj);
	                    variantList.append(var);
	                } else {
	                    variantList.append(QVariant());
	                }
	                i++; // Skip the next item (type name)
	                break;
	            }
	            case ITEMTYPE_LIST: {
	                List* subList = ring_list_getlist(pList, i);
	                if (subList) {
	                    int subSize = ring_list_getsize(subList);
	                    // Check if this sub-list looks like a list of key-value pairs
	                    // For example: [["id", 0], ["name", "Mohannad"], ["role", "Dev"]]
	                    bool subListLooksLikeKeyValuePairs = true;
	                    if (subSize > 0) {
	                        for (int j = 1; j <= subSize; ++j) {
	                            if (ring_list_islist(subList, j)) {
	                                List* pairList = ring_list_getlist(subList, j);
	                                int pairSize = ring_list_getsize(pairList);
	                                // A key-value pair should be [string, value] (size 2)
	                                if (pairSize != 2 || !ring_list_isstring(pairList, 1)) {
	                                    subListLooksLikeKeyValuePairs = false;
	                                    break;
	                                }
	                                // Check if key contains spaces (invalid for hash table keys)
	                                const char* keyStr = ring_list_getstring(pairList, 1);
	                                std::string key = std::string(keyStr);
	                                if (key.find(' ') != std::string::npos) {
	                                    subListLooksLikeKeyValuePairs = false;
	                                    break;
	                                }
	                            } else {
	                                subListLooksLikeKeyValuePairs = false;
	                                break;
	                            }
	                        }
	                    }
	                    if (subListLooksLikeKeyValuePairs) {
	                        // Convert list of key-value pairs to a single object
	                        QVariantMap subMap;
	                        for (int j = 1; j <= subSize; ++j) {
	                            List* pairList = ring_list_getlist(subList, j);
	                            if (ring_list_getsize(pairList) == 2) {
	                                QString key = QString::fromUtf8(ring_list_getstring(pairList, 1));
	                                int valType = ring_list_gettype(pairList, 2);
	                                switch (valType) {
	                                    case ITEMTYPE_STRING:
	                                        subMap[key] = QString::fromUtf8(ring_list_getstring(pairList, 2));
	                                        break;
	                                    case ITEMTYPE_NUMBER:
	                                        subMap[key] = ring_list_getdouble(pairList, 2);
	                                        break;
	                                    case ITEMTYPE_LIST:
	                                        subMap[key] = ringListToQVariant(ring_list_getlist(pairList, 2));
	                                        break;
	                                    default:
	                                        subMap[key] = QString::fromUtf8(ring_list_getstring(pairList, 2));
	                                        break;
	                                }
	                            }
	                        }
	                        variantList.append(QVariant(subMap));
	                    } else {
	                        variantList.append(ringListToQVariant(subList));
	                    }
	                } else {
	                    variantList.append(QVariantList());
	                }
	                break;
	            }
	            default: {
	                const char* str = ring_list_getstring(pList, i);
	                if (str) {
	                    QString jsonString = QString::fromUtf8(str);
	                    if ((jsonString.trimmed().startsWith('{') && jsonString.trimmed().endsWith('}')) ||
	                        (jsonString.trimmed().startsWith('[') && jsonString.trimmed().endsWith(']'))) {
	                        QJsonParseError error;
	                        QJsonDocument doc = QJsonDocument::fromJson(jsonString.toUtf8(), &error);
	                        if (error.error == QJsonParseError::NoError) {
	                            if (doc.isArray()) {
	                                variantList.append(doc.toVariant());
	                            } else if (doc.isObject()) {
	                                variantList.append(doc.toVariant());
	                            } else {
	                                variantList.append(jsonString);
	                            }
	                        } else {
	                            variantList.append(jsonString);
	                        }
	                    } else {
	                        variantList.append(jsonString);
	                    }
	                } else {
	                    variantList.append(QVariant());
	                }
	                break;
	            }
	        }
	    }
	    return QVariant(variantList);
	}
	QVariantList getQmlDefinedFunctions(QObject* object) {
	    QVariantList result;
	    if (!object) {
	        qWarning() << "getQmlDefinedFunctions: Object is null.";
	        return result;
	    }
	    const QMetaObject *metaObject = object->metaObject();
	    // methodOffset() is the key here. 
	    // It returns the index where the methods for *this specific class* start,
	    // strictly excluding methods inherited from parent classes (like QQuickItem, QObject).
	    // This ensures we get the functions defined in the QML file, not C++ base methods.
	    int offset = metaObject->methodOffset();
	    int count = metaObject->methodCount();
	    for (int i = offset; i < count; ++i) {
	        QMetaMethod method = metaObject->method(i);
	        // In QML, 'function foo()' is generated as a Method or Slot.
	        // We typically exclude Signals (methodType() == QMetaMethod::Signal)
	        // unless you specifically want to list signals as well.
	        if (method.methodType() == QMetaMethod::Method || 
	            method.methodType() == QMetaMethod::Slot) {
	            QVariantList functionData;
	            // 1. Function Name (QString)
	            functionData.append(QString::fromLatin1(method.name()));
	            // 2. Parameter Count (int)
	            functionData.append(method.parameterCount());
	            result.append(QVariant::fromValue(functionData));
	        }
	    }
	    return result;
	}
	void qVariantToRingList(VM* pVM, List* pParentList, const QVariant& value) {
	    // 1. Collections (Maps/Lists)
	    if (value.type() == QVariant::Map) {
	        qVariantMapToRingList(pVM, pParentList, value.toMap());
	        return;
	    } 
	    if (value.type() == QVariant::List) {
	        qVariantListToRingList(pVM, pParentList, value.toList());
	        return;
	    }
	    // 2. Specific Primitives
	    // We check types explicitly first to avoid accidental string conversions for Ints/Bools
	    if (value.type() == QVariant::Bool) {
	         ring_list_adddouble_gc(pVM->pRingState, pParentList, value.toBool() ? 1.0 : 0.0);
	         return;
	    }
	    if (value.type() == QVariant::Int || value.type() == QVariant::LongLong || value.type() == QVariant::UInt) {
	         ring_list_adddouble_gc(pVM->pRingState, pParentList, (double)value.toLongLong());
	         return;
	    }
	    if (value.type() == QVariant::Double) {
	         ring_list_adddouble_gc(pVM->pRingState, pParentList, value.toDouble());
	         return;
	    }
	    // 3. Strings (and anything that naturally acts as one)
	    if (value.canConvert<QString>() && value.type() != QVariant::UserType) {
	        ring_list_addstring_gc(pVM->pRingState, pParentList, value.toString().toUtf8().constData());
	        return;
	    }
	    // 4. QObject Pointers (Standard Qt Objects)
	    if (value.canConvert<QObject*>()) {
	        QObject* obj = value.value<QObject*>();
	        List* pPtrList = ring_list_newlist_gc(pVM->pRingState, pParentList);
	        ring_list_addpointer_gc(pVM->pRingState, pPtrList, obj);
	        ring_list_addstring_gc(pVM->pRingState, pPtrList, "QObject");
	        ring_list_adddouble_gc(pVM->pRingState, pPtrList, 0.0);
	        return;
	    }
	    // 5. Fallback: Raw/Void/Custom Pointer Handling
	    // This logic extracts raw pointers from QVariants (e.g. void*, custom structs)
	    {
	        void* obj = nullptr;
	        // Check if it is strictly a void* type
	        if (value.userType() == QMetaType::VoidStar) {
	             obj = value.value<void*>();
	        } else {
	             // For registered custom pointer types, the QVariant data holds the pointer itself. 
	             // We cast the internal constData pointer to a pointer-to-void-pointer, then dereference it.
	             obj = *reinterpret_cast<void* const *>(value.constData());
	        }
	        const char * ptrType = value.typeName();
	        List * pPtrList = ring_list_newlist_gc(pVM->pRingState, pParentList);
	        ring_list_addpointer_gc(pVM->pRingState, pPtrList, obj);
	        // Use type name if available, otherwise generic
	        ring_list_addstring_gc(pVM->pRingState, pPtrList, ptrType ? ptrType : "void*");
	        ring_list_adddouble_gc(pVM->pRingState, pPtrList, 0.0);
	    }
	}
	void qVariantListToRingList(VM* pVM, List* pParentList, const QVariantList& list) {
	    List* pSubList = ring_list_newlist_gc(pVM->pRingState, pParentList);
	    for (const QVariant& var : list) {
	        qVariantToRingList(pVM, pSubList, var);
	    }
	}
	void qVariantMapToRingList(VM* pVM, List* pParentList, const QVariantMap& map) {
	    List* pMainList = ring_list_newlist_gc(pVM->pRingState, pParentList);
	    QMapIterator<QString, QVariant> it(map);
	    while (it.hasNext()) {
	        it.next();
	        List* pEntry = ring_list_newlist_gc(pVM->pRingState, pMainList);
	        ring_list_addstring_gc(pVM->pRingState, pEntry, it.key().toUtf8().constData());
	        qVariantToRingList(pVM, pEntry, it.value());
	    }
	}
	// Helper for object flattening
	QJsonObject flattenObject(QObject *obj, const QString &prefix, QSet<QObject*> &visited) {
	    if (!obj || visited.contains(obj)) return QJsonObject();
	    visited.insert(obj);
	    QJsonObject json;
	    const QMetaObject *meta = obj->metaObject();
	    for (int i = 0; i < meta->propertyCount(); ++i) {
	        QMetaProperty prop = meta->property(i);
	        if (prop.isReadable()) {
	            QVariant value = obj->property(prop.name());
	            QString key = (prefix.isEmpty() ? "" : prefix + "_") + QString(prop.name());
	            if (value.canConvert<QObject*>()) {
	                QObject *nestedObj = value.value<QObject*>();
	                if (nestedObj && nestedObj != obj) {
	                    QJsonObject nestedJson = flattenObject(nestedObj, key, visited);
	                    for (auto it = nestedJson.begin(); it != nestedJson.end(); ++it) {
	                        json[it.key()] = it.value();
	                    }
	                }
	            } else {
	                json[key] = QJsonValue::fromVariant(value);
	            }
	        }
	    }
	    visited.remove(obj);
	    return json;
	}
	QString objectToJson(QObject *obj) {
	    QSet<QObject*> visited;
	    return QJsonDocument(flattenObject(obj, "", visited)).toJson(QJsonDocument::Compact);
	}
	int setNestedProperty(QObject *obj, const QString &propertyPath, const QVariant &value) {
	    QStringList parts = propertyPath.split('_');
	    QObject *current = obj;
	    // Navigate down to the second to last part
	    for (int i = 0; i < parts.size() - 1; ++i) {
	        QObject *child = nullptr;
	        // 1. Try finding by objectName
	        const auto children = current->children();
	        for (QObject *c : children) {
	            if (c->objectName().compare(parts[i], Qt::CaseInsensitive) == 0) {
	                child = c;
	                break;
	            }
	        }
	        // 2. Try finding by property that is a QObject
	        if (!child) {
	            const QMetaObject *meta = current->metaObject();
	            for (int j = 0; j < meta->propertyCount(); ++j) {
	                QMetaProperty prop = meta->property(j);
	                if (QString(prop.name()).compare(parts[i], Qt::CaseInsensitive) == 0) {
	                    child = qobject_cast<QObject*>(current->property(prop.name()).value<QObject*>());
	                    break;
	                }
	            }
	        }
	        if (!child) return 0; // Path not found
	        current = child;
	    }
	    // Set the property on the final object
	    QString propName = parts.last();
	    current->setProperty(propName.toUtf8().constData(), value);
	    return 1;
	}


// File : ring_qml_api.cpp
	// --- API Implementation ---
	RING_FUNC(ring_InitClass) {
	    QQmlEngine* qmlEngine;
	    if (RING_API_PARACOUNT != 1) {
	        RING_API_ERROR(RING_API_BADPARACOUNT);
	        return;
	    }
	    RING_API_IGNORECPOINTERTYPE;
	    if(!RING_API_ISCPOINTER(1)){
	        RING_API_ERROR(RING_API_BADPARATYPE);
	        return; 
	    }
	    qmlEngine = (QQmlEngine *) RING_API_GETCPOINTER(1,"QQmlEngine");
	    SetRingEventForCallFromQML((VM*)pPointer, qmlEngine);
	}
	RING_FUNC(ring_loadQmlFromContentWidget) {
	    QQuickWidget* widget;
	    const char* qml;
	    if (RING_API_PARACOUNT != 2) {
	        RING_API_ERROR(RING_API_BADPARACOUNT);
	        return;
	    }
	    if (!RING_API_ISCPOINTER(1) || !RING_API_ISSTRING(2)) {
	        RING_API_ERROR(RING_API_BADPARATYPE);
	        return;
	    }
	    widget = (QQuickWidget*)RING_API_GETCPOINTER(1, "QQuickWidget");
	    qml = RING_API_GETSTRING(2);
	    RING_API_RETCPOINTER(loadQmlFromContentWidget(widget, qml), "QQuickItem");
	}
	RING_FUNC(ring_loadQmlFromContentView) {
	    QQuickView* view;
	    const char* qml;
	    if (RING_API_PARACOUNT != 2) {
	        RING_API_ERROR(RING_API_BADPARACOUNT);
	        return;
	    }
	    if (!RING_API_ISCPOINTER(1) || !RING_API_ISSTRING(2)) {
	        RING_API_ERROR(RING_API_BADPARATYPE);
	        return;
	    }
	    view = (QQuickView*)RING_API_GETCPOINTER(1, "QQuickView");
	    qml = RING_API_GETSTRING(2);
	    RING_API_RETCPOINTER(loadQmlFromContentView(view, qml), "QQuickItem");
	}
	RING_FUNC(ring_loadQmlFromContentEngine) {
	    QQmlApplicationEngine* engine;
	    const char* qml;
	    if (RING_API_PARACOUNT != 2) {
	        RING_API_ERROR(RING_API_BADPARACOUNT);
	        return;
	    }
	    if (!RING_API_ISCPOINTER(1) || !RING_API_ISSTRING(2)) {
	        RING_API_ERROR(RING_API_BADPARATYPE);
	        return;
	    }
	    engine = (QQmlApplicationEngine*)RING_API_GETCPOINTER(1, "QQmlApplicationEngine");
	    qml = RING_API_GETSTRING(2);
	    RING_API_RETCPOINTER(loadQmlFromContentEngine(engine, qml), "QQuickItem");
	}
	RING_FUNC(ring_createNewComponent) {
	    QQmlEngine* engine;
	    char* name;
	    char* code;
	    if (RING_API_PARACOUNT < 3) {
	        RING_API_ERROR(RING_API_BADPARACOUNT);
	        return;
	    }
	    if (!RING_API_ISCPOINTER(1) || !RING_API_ISSTRING(2) || !RING_API_ISSTRING(3)) {
	        RING_API_ERROR(RING_API_BADPARATYPE);
	        return;
	    }
	    engine = (QQmlEngine*)RING_API_GETCPOINTER(1, "QQmlEngine");
	    name = RING_API_GETSTRING(2);
	    code = RING_API_GETSTRING(3);
	    RING_API_RETCPOINTER(createNewComponent(engine, name, code), "QQuickItem");
	}
	RING_FUNC(ring_getQmlDefinedFunctions){
	    QQuickItem * pQQuickItem;
	    List *pList; 
	    pList = RING_API_NEWLIST;
	    if(RING_API_PARACOUNT != 1){
	        RING_API_ERROR(RING_API_BADPARACOUNT);
	        return;
	    }
	    RING_API_IGNORECPOINTERTYPE;
	    if( !RING_API_ISCPOINTER(1) ){
	        RING_API_ERROR(RING_API_BADPARATYPE);
	        return;
	    }
	    pQQuickItem = ( QQuickItem *) RING_API_GETCPOINTER(1,"QQuickItem");
	    qVariantToRingList( (VM *) pPointer,pList,getQmlDefinedFunctions(pQQuickItem));
	    RING_API_RETLISTBYREF(pList);
	}
	RING_FUNC(ring_callQMLFunc) {
	    char* funcName;
	    QVariant params;
	    QQuickItem* target;
	    QVariantList listArgs;
	    int ret;
	    if (RING_API_PARACOUNT != 3) {
	        RING_API_ERROR(RING_API_BADPARACOUNT);
	        return;
	    }
	    if(!RING_API_ISCPOINTER(1) || !RING_API_ISSTRING(2) || !RING_API_ISLIST(3)){
	        RING_API_ERROR(RING_API_BADPARATYPE);
	        return;
	    }
	    RING_API_IGNORECPOINTERTYPE;
	    target = (QQuickItem*)RING_API_GETCPOINTER(1, "QQuickItem");
	    funcName = RING_API_GETSTRING(2);
	    params = ringListToQVariant(RING_API_GETLIST(3));
	    listArgs = (params.type() == QVariant::List) ? params.toList() : params.toMap().values();
	    ret = callQmlFunction(target, funcName, listArgs);
	    RING_API_RETNUMBER((int)ret);
	}
	RING_FUNC(ring_qmlobjectsetpropByPath) {
	    QObject* obj;
	    const char* prop;
	    QVariant* val;
	    if (RING_API_PARACOUNT != 3) {
	        RING_API_ERROR(RING_API_BADPARACOUNT);
	        return;
	    }
	    if (!RING_API_ISCPOINTER(1) || !RING_API_ISSTRING(2) || !RING_API_ISCPOINTER(3)) {
	        RING_API_ERROR(RING_API_BADPARATYPE);
	        return;
	    }
	    obj = (QObject*)RING_API_GETCPOINTER(1, "QObject");
	    prop = RING_API_GETSTRING(2);
	    val = (QVariant*)RING_API_GETCPOINTER(3, "QVariant");
	    RING_API_RETNUMBER(setNestedProperty(obj, QString(prop), *val));
	}
	RING_FUNC(ring_qmlobjectgetallprops_now) {
	    QObject* obj;
	    List* pList;
	    QSet<QObject*> visited;
	    QVariantMap map;
	    if (RING_API_PARACOUNT != 1) {
	        RING_API_ERROR(RING_API_BADPARACOUNT);
	        return;
	    }
	    if (!RING_API_ISCPOINTER(1)) {
	        RING_API_ERROR(RING_API_BADPARATYPE);
	        return;
	    }
	    obj = (QObject*)RING_API_GETCPOINTER(1, "QObject");
	    pList = RING_API_NEWLIST;
	    map = flattenObject(obj, "", visited).toVariantMap();
	    qVariantMapToRingList((VM*)pPointer, pList, map);
	    RING_API_RETLISTBYREF(pList);
	}
	RING_FUNC(ring_exposePixmapToQML) {
	    QQmlEngine* engine;
	    QPixmap* pix;
	    if (RING_API_PARACOUNT != 2) {
	        RING_API_ERROR(RING_API_BADPARACOUNT);
	        return;
	    }
	    RING_API_IGNORECPOINTERTYPE;
	    if (!RING_API_ISCPOINTER(1) || !RING_API_ISCPOINTER(2)) {
	        RING_API_ERROR(RING_API_BADPARATYPE);
	        return;
	    }
	    engine = (QQmlEngine*)RING_API_GETCPOINTER(1, "QQmlEngine");
	    pix = (QPixmap*)RING_API_GETCPOINTER(2, "QPixmap");
	    RING_API_RETNUMBER(exposePixmapToQML(engine, *pix));
	}
	RING_FUNC(ring_qmlEnginApp_new) {
	    RING_API_RETCPOINTER(new QQmlApplicationEngine(), "QQmlApplicationEngine");
	}
	RING_FUNC(ring_ringlisttoqvaraint) {
	    QVariant* v;
	    if(RING_API_PARACOUNT != 1) {
	        RING_API_ERROR(RING_API_BADPARACOUNT);
	        return;
	    }
	    if (!RING_API_ISLIST(1)) {
	        RING_API_ERROR(RING_API_BADPARATYPE);
	        return;
	    }
	    v = new QVariant(ringListToQVariant(RING_API_GETLIST(1)));
	    RING_API_RETCPOINTER(v, "QVariant");
	}
	RING_FUNC(ring_exposeQWidgetToQML) {
	    QQmlEngine* engine;
	    QObject* widget;
	    const char* name;
	    if (RING_API_PARACOUNT != 3) {
	        RING_API_ERROR(RING_API_BADPARACOUNT);
	        return;
	    }
	    RING_API_IGNORECPOINTERTYPE;
	    if (!RING_API_ISCPOINTER(1) || !RING_API_ISCPOINTER(2) || !RING_API_ISSTRING(3)) {
	        RING_API_ERROR(RING_API_BADPARATYPE);
	        return;
	    }
	    engine = (QQmlEngine*)RING_API_GETCPOINTER(1, "QQmlEngine");
	    widget = (QObject*)RING_API_GETCPOINTER(2, "QObject");
	    name = RING_API_GETSTRING(3);
	    engine->rootContext()->setContextProperty(name, widget);
	}
	RING_FUNC(ring_grabItemSnapshot){
	    QImage* pImage;
	    QQuickItem* rootItem;
	    char * cObjectName;
	    if (RING_API_PARACOUNT != 2) {
	        RING_API_ERROR(RING_API_BADPARACOUNT);
	        return;
	    }
	    RING_API_IGNORECPOINTERTYPE;
	    if (!RING_API_ISCPOINTER(1) || !RING_API_ISSTRING(2)) {
	        RING_API_ERROR(RING_API_BADPARATYPE);
	        return;
	    }
	    rootItem = (QQuickItem*) RING_API_GETCPOINTER(1, "QQuickItem");
	    cObjectName = RING_API_GETSTRING(2);
	    pImage=grabItemSnapshot(rootItem,cObjectName);
	    RING_API_RETCPOINTER(pImage,"QImage");
	}
	RING_FUNC(ring_setQMLAppIconForqAppInstance){
	    char * cIcon;
	    if (RING_API_PARACOUNT != 1) {
	        RING_API_ERROR(RING_API_BADPARACOUNT);
	        return;
	    }
	    if (!RING_API_ISSTRING(1)){
	        RING_API_ERROR(RING_API_BADPARATYPE);
	        return;
	    }
	    cIcon = RING_API_GETSTRING(1);
	    if(qApp){
	        qApp->setWindowIcon(QIcon(cIcon));
	        RING_API_RETNUMBER(1.0);
	        return;
	    }
	    RING_API_RETNUMBER(0.0);
	}
	// --- Library Initialization ---
	void ringQML_initLib(RingState *pRingState) {
	    RING_API_REGISTER("initqmlclass", ring_InitClass);
	    RING_API_REGISTER("exposeqwidgettoqml", ring_exposeQWidgetToQML);
	    RING_API_REGISTER("ringqmlobjectgetallprops_now", ring_qmlobjectgetallprops_now);
	    RING_API_REGISTER("ringqmlobjectsetpropbypath", ring_qmlobjectsetpropByPath);
	    RING_API_REGISTER("ringqmlringlisttoqvaraint", ring_ringlisttoqvaraint);
	    RING_API_REGISTER("ringqml_loadfrom_qmlwidget", ring_loadQmlFromContentWidget);
	    RING_API_REGISTER("ringqml_loadfrom_qmlview", ring_loadQmlFromContentView);
	    RING_API_REGISTER("ringqml_loadfrom_qmlengin", ring_loadQmlFromContentEngine);
	    RING_API_REGISTER("ringqmlenginapp_new", ring_qmlEnginApp_new);
	    RING_API_REGISTER("ringqmlcallqmlfunc", ring_callQMLFunc);
	    RING_API_REGISTER("createnewcomponent", ring_createNewComponent);
	    RING_API_REGISTER("exposeimagetoqml", ring_exposePixmapToQML);
	    RING_API_REGISTER("getqmldefinedfunctions",ring_getQmlDefinedFunctions);
	    RING_API_REGISTER("ringqml_grabitemsnapshot",ring_grabItemSnapshot);
	    RING_API_REGISTER("setqmlappiconforqappinstance",ring_setQMLAppIconForqAppInstance);
	}
	// Desktop Only we use RING_LIBINIT
	#if !defined(Q_OS_ANDROID) && !defined(Q_OS_IOS) && !defined(Q_OS_WASM)
	    extern "C"{
	        RING_LIBINIT{
	            ringQML_initLib(pRingState);
	        }
	    }
	#endif
