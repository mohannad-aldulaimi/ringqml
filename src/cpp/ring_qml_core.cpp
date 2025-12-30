/*
    Project      : RingQML library for Ring Programming Language
    Author       : Mohannad Azeez Al-Ayash 
    E-Mail       : mohannadazazalayash@gmail.com
    WebSite      : https://mohannad-aldulaimi.github.io
    File Purpose : RingQML Class implementation.
*/
//<FileStart>
#include "ring_qml_core.h"
#include "ring_qml_utils.h"
//<IncludeStart>
#include <QDebug>
#include <QJSValue>
//<IncludeEnd>
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
//<FileEnd>