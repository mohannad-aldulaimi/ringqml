/*
    Project      : RingQML library for Ring Programming Language
    Author       : Mohannad Azeez Al-Ayash 
    E-Mail       : mohannadazazalayash@gmail.com
    WebSite      : https://mohannad-aldulaimi.github.io
    File Purpose :
     * Loaders (QQuickView\QQuickWidget\QQmlApplicationEngine). 
     * callQmlFunction Implementation.
*/
//<FileStart>
#include "ring_qml_loader.h"
#include "ring_qml_core.h" // For Ringbridge
//<IncludeStart>
#include <QQmlContext>
#include <QQmlComponent>
#include <QTemporaryDir>
#include <QFile>
#include <QTextStream>
#include <QDir>
#include <QLibraryInfo>
#include <QEventLoop>
#include <QDebug>
//<IncludeEnd>

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
//<FileEnd>