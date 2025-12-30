/*
    Project      : RingQML library for Ring Programming Language
    Author       : Mohannad Azeez Al-Ayash 
    E-Mail       : mohannadazazalayash@gmail.com
    WebSite      : https://mohannad-aldulaimi.github.io
    File Purpose :
     * Loaders (QQuickView\QQuickWidget\QQmlApplicationEngine). 
     * callQmlFunction Definition.
*/
//<FileStart>
#ifndef RING_QML_LOADER_H
#define RING_QML_LOADER_H
//<IncludeStart>
#include <QQuickWidget>
#include <QQuickView>
#include <QQmlApplicationEngine>
#include <QQuickItem>
#include <QString>
//<IncludeEnd>
extern "C" {
    #include "ring.h"
}

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
//<FileEnd>