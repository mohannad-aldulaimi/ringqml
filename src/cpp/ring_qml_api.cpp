/*
    Project      : RingQML library for Ring Programming Language
    Author       : Mohannad Azeez Al-Ayash 
    E-Mail       : mohannadazazalayash@gmail.com
    WebSite      : https://mohannad-aldulaimi.github.io
    File Purpose : Main API.
*/
//<FileStart>
#include "ring_qml_core.h"
#include "ring_qml_utils.h"
#include "ring_qml_loader.h"
#include "ring_qml_image.h"
//<IncludeStart>
#include <QQmlEngine>
#include <QQmlContext>
//<IncludeEnd>
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

}

// Desktop Only we use RING_LIBINIT
#if !defined(Q_OS_ANDROID) && !defined(Q_OS_IOS) && !defined(Q_OS_WASM)
    extern "C"{
        RING_LIBINIT{
            ringQML_initLib(pRingState);
        }
    }
#endif
//<FileEnd>