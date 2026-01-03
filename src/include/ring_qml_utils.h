/*
    Project      : RingQML library for Ring Programming Language
    Author       : Mohannad Azeez Al-Ayash 
    E-Mail       : mohannadazazalayash@gmail.com
    WebSite      : https://mohannad-aldulaimi.github.io
    File Purpose :
     * Definition of UILS Functions :
       * ringListToQVariant.
       * getQmlDefinedFunctions.
       * qVariantToRingList.
       * qVariantListToRingList.
       * qVariantMapToRingList.
       * flattenObject.
       * objectToJson.
       * setNestedProperty.
*/
//<FileStart>
#ifndef RING_QML_UTILS_H
#define RING_QML_UTILS_H
//<IncludeStart>
#include <QVariant>
#include <QVariantList>
#include <QVariantMap>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QSet>
#include <QString>
#include <QQuickItem>
#include <QImage>
//<IncludeEnd>
extern "C" {
    #include "ring.h"
}
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
//<FileEnd>