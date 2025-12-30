/*
    Project      : RingQML library for Ring Programming Language
    Author       : Mohannad Azeez Al-Ayash 
    E-Mail       : mohannadazazalayash@gmail.com
    WebSite      : https://mohannad-aldulaimi.github.io
    File Purpose : RingQML Class Definition.
*/
//<FileStart>
#ifndef RING_QML_CORE_H
#define RING_QML_CORE_H
//<IncludeStart>
#include <QObject>
#include <QVariant>
#include <QQmlEngine>
//<IncludeEnd>
extern "C" {
    #include "ring.h"
}

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
//<FileEnd>
