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

extern "C" { 
	#include "ring.h"
}

// File : ring_qml_core.h
	#ifndef RING_QML_CORE_H
	#define RING_QML_CORE_H
	
	class RingQML : public QObject
	{
	    Q_OBJECT
	public:
	    explicit RingQML(VM* vm = nullptr, QObject* parent = nullptr);
	    // Update the VM pointer if it changes (rare, but good for safety)
	    void setVM(VM* vm);
	    // --- QML Callable Methods ---
	    // Executes Ring code
	    Q_INVOKABLE void callEvent(const QString& eventCode);
	    // Synonym for callEvent
	    Q_INVOKABLE void eval(const QString& code);
	    // Retrieves a variable from Ring Global Scope
	    Q_INVOKABLE QVariant getVar(const QString& varName);
	    // 
	    Q_INVOKABLE QVariant setVar(const QString& varName,const QVariant& vValue) ;
	    // Calls a defined Ring function
	    Q_INVOKABLE QVariant callFunc(const QString& funcName, const QVariantList& params = QVariantList());
	    // Helper to format image provider strings
	    Q_INVOKABLE QString getImage(const QVariant& id);
	private:
	    VM* m_vm;
	};
	// Global pointer for the bridge, used during initialization
	extern RingQML *Ringbridge;
	#endif // RING_QML_CORE_H


// File : ring_qml_image.h
	#ifndef RING_QML_IMAGE_H
	#define RING_QML_IMAGE_H
	class SharedPixmapProvider : public QQuickImageProvider {
	public:
	    SharedPixmapProvider();
	    // Returns the ID of the shared image
	    int shareImage(const QPixmap &pixmap);
	    QPixmap requestPixmap(const QString &id, QSize *size, const QSize &requestedSize) override;
	private:
	    QMap<int, QPixmap> m_pixmaps;
	    int m_nextId;
	};
	// Main function to expose a pixmap from C++ (Ring) to QML
	int exposePixmapToQML(QQmlEngine* engine, const QPixmap& pixmap);
	#endif // RING_QML_IMAGE_H


// File : ring_qml_loader.h
	#ifndef RING_QML_LOADER_H
	#define RING_QML_LOADER_H
	
	// Loads QML string into a QQuickView
	QQuickItem* loadQmlFromContentView(QQuickView* view, const char* qmlContent);
	// Loads QML string into a QQuickWidget
	QQuickItem* loadQmlFromContentWidget(QQuickWidget* widget, const char* qmlContent);
	// Loads QML string into a QQmlApplicationEngine
	QQuickItem* loadQmlFromContentEngine(QQmlApplicationEngine* engine, const char* qmlContent);
	// Creates a new QML component dynamically using temporary files
	QQuickItem* createNewComponent(QQmlEngine* engine, const char* componentName, const char* qmlCode);
	// Helper to set background colors transparent for embedding
	void setQuickColorLikeWindow(QQuickWidget* quickWidget);
	// Initialize the Ring bridge context property
	void SetRingEventForCallFromQML(VM* pVm, QQmlEngine* qmlEngine);
	// Call a specific function inside a QML Item
	bool callQmlFunction(QQuickItem* rootItem, const char* functionName, const QVariantList& params);
	#endif // RING_QML_LOADER_H


// File : ring_qml_utils.h
	#ifndef RING_QML_UTILS_H
	#define RING_QML_UTILS_H
	
	/**
	 * Take a SnapShot for QML Item using its objecName.
	 */
	QImage* grabItemSnapshot(QQuickItem* rootItem, const char* objectName);
	/**
	 * Converts a Ring List (and nested lists) into a QVariant.
	 * Handles Maps (Key-Value pairs), Lists, and QObject pointers.
	 */
	QVariant ringListToQVariant(List* pList);
	/**
	 * Converts a QVariant (Map, List, or Primitive) into a Ring List.
	 */
	void qVariantToRingList(VM* pVM, List* pParentList, const QVariant& value);
	/**
	 * Converts a QObject's properties into a JSON string.
	 */
	QString objectToJson(QObject* obj);
	QVariantList getQmlDefinedFunctions(QObject* object) ;
	/**
	 * Converts a QObject's properties directly into a Ring List.
	 */
	List* objectToRingList(QObject* obj);
	/**
	 * Sets a property on a QObject using a path string (e.g., "header_title_text").
	 * Returns 1 on success, 0 on failure.
	 */
	int setNestedProperty(QObject* obj, const QString& propertyPath, const QVariant& value);
	// --- Helper Declarations ---
	void qVariantListToRingList(VM* pVM, List* pParentList, const QVariantList& list);
	void qVariantMapToRingList(VM* pVM, List* pParentList, const QVariantMap& map);
	QJsonObject flattenObject(QObject *obj, const QString &prefix, QSet<QObject*> &visited) ;
	#endif // RING_QML_UTILS_H
