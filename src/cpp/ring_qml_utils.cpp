/*
    Project      : RingQML library for Ring Programming Language
    Author       : Mohannad Azeez Al-Ayash 
    E-Mail       : mohannadazazalayash@gmail.com
    WebSite      : https://mohannad-aldulaimi.github.io
    File Purpose :
     * Implementation of UILS Functions :
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
#include "ring_qml_utils.h"
//<IncludeStart>
#include <QDebug>
#include <QMetaProperty>
//<IncludeEnd>
/*
QVariant ringListToQVariant(List* pList) {
    if (!pList) return QVariantList();

    int nSize = ring_list_getsize(pList);

    // 1. Check for QObject Pointer: [Pointer, "QObject", Type]
    if (nSize == 3) {
        if (ring_list_ispointer(pList, 1) && ring_list_isstring(pList, 2)) {
            QString typeName = QString::fromUtf8(ring_list_getstring(pList, 2));
            if (typeName == "QObject") {
                QObject* obj = static_cast<QObject*>(ring_list_getpointer(pList, 1));
                return QVariant::fromValue(obj);
            }
        }
    }

    // 2. Check for Hash/Map-like structure
    // Logic: List size is even, items are String keys followed by values.
    bool looksLikeMap = (nSize > 0 && nSize % 2 == 0);
    if (looksLikeMap) {
        for (int i = 1; i <= nSize; i += 2) {
            if (!ring_list_isstring(pList, i)) {
                looksLikeMap = false;
                break;
            }
            // Basic validation to prevent arbitrary sentences from being treated as maps
            std::string key = ring_list_getstring(pList, i);
            if (key.find(' ') != std::string::npos) {
                looksLikeMap = false;
                break;
            }
        }
    }

    if (looksLikeMap) {
        QVariantMap variantMap;
        for (int i = 1; i <= nSize; i += 2) {
            QString key = QString::fromUtf8(ring_list_getstring(pList, i));
            // Recursive call for the value (i + 1)
            int valType = ring_list_gettype(pList, i + 1);
            if (valType == ITEMTYPE_LIST) {
                variantMap[key] = ringListToQVariant(ring_list_getlist(pList, i + 1));
            } else if (valType == ITEMTYPE_STRING) {
                variantMap[key] = QString::fromUtf8(ring_list_getstring(pList, i + 1));
            } else if (valType == ITEMTYPE_NUMBER) {
                variantMap[key] = ring_list_getdouble(pList, i + 1);
            }
        }
        return variantMap;
    }

    // 3. Standard List
    QVariantList variantList;
    for (int i = 1; i <= nSize; ++i) {
        if (ring_list_islist(pList, i)) {
            variantList.append(ringListToQVariant(ring_list_getlist(pList, i)));
        } else if (ring_list_isstring(pList, i)) {
            QString str = QString::fromUtf8(ring_list_getstring(pList, i));
            // Check if string is actually JSON
            QString trimmed = str.trimmed();
            if ((trimmed.startsWith('{') && trimmed.endsWith('}')) || 
                (trimmed.startsWith('[') && trimmed.endsWith(']'))) {
                QJsonParseError error;
                QJsonDocument doc = QJsonDocument::fromJson(trimmed.toUtf8(), &error);
                if (error.error == QJsonParseError::NoError) {
                    variantList.append(doc.toVariant());
                } else {
                    variantList.append(str);
                }
            } else {
                variantList.append(str);
            }
        } else if (ring_list_isnumber(pList, i)) {
            variantList.append(ring_list_getdouble(pList, i));
        } else if (ring_list_ispointer(pList, i)) {
            // Handle raw pointer or QObject pointer in list
            void* ptr = ring_list_getpointer(pList, i);
            // Check next item for type string if possible, otherwise generic void*
            if (i < nSize && ring_list_isstring(pList, i+1) && 
                strcmp(ring_list_getstring(pList, i+1), "QObject") == 0) {
                 variantList.append(QVariant::fromValue(static_cast<QObject*>(ptr)));
                 i++; // Skip type
            } else {
                 variantList.append(QVariant::fromValue(ptr));
            }
        }
    }
    return variantList;
}
*/

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
//<FileEnd>