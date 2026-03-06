/* Copyright (c) 2013-2022 Mahmoud Fayed <msfclipper@yahoo.com> */

extern "C" {
	#include "ring.h"
}

#include "gtimer.h"
#include "giodevice.h"
#include "gprocess.h"
#include "gthread.h"
#include <QtCore>

#include "gwindow.h"
#include "gguiapplication.h"
#include <QtGui>

#include "gallevents.h"






#include "gnetworkaccessmanager.h"
#include "gtcpserver.h"
#include "gabstractsocket.h"
#include "gtcpsocket.h"
#include <QAbstractSocket>
#include <QTcpSocket>
#include <QTcpServer>
#include <QNetworkProxy>
#include <QHostAddress>
#include <QHostInfo>
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <QNetworkReply>





#include <QQmlError>
#include <QQuickView>
#include <QQmlEngine>









#include <QByteArray>
#include <QString>
#include <QObject>


#include <windows.h>


extern "C" {
RING_API void ring_qt_start(RingState *pRingState);

RingState *g_pRingState = nullptr;

RING_FUNC(ring_start_qt6_gui) {
if (RING_API_PARACOUNT == 1) {
QString qtPath = QString(RING_API_GETSTRING(1));

QCoreApplication::addLibraryPath(qtPath + "/plugins");
qputenv("QT_QPA_PLATFORM_PLUGIN_PATH", (qtPath + "/plugins/platforms").toUtf8());

QString binPath = qtPath + "/bin;";
binPath.replace("/", "\\");

QByteArray currentPath = qgetenv("PATH");
qputenv("PATH", binPath.toUtf8() + currentPath);

if (g_pRingState) {
new QApplication(g_pRingState->nArgc, g_pRingState->pArgv);

// Handle silent exit for Windows while keeping Android/Wasm native
QObject::connect(qApp, &QCoreApplication::aboutToQuit, []() {

TerminateProcess(GetCurrentProcess(), 0);

});

ring_qt_start(g_pRingState);
}
}
}

RING_LIBINIT
{
g_pRingState = pRingState;
RING_API_REGISTER("start_qt6_gui", ring_start_qt6_gui);
}
}

// Functions Prototype - Functions used to Free Memory 

	void ring_QObject_freefunc(void *pState,void *pPointer);
	void ring_QSize_freefunc(void *pState,void *pPointer);
	void ring_QDir_freefunc(void *pState,void *pPointer);
	void ring_QUrl_freefunc(void *pState,void *pPointer);
	void ring_QEvent_freefunc(void *pState,void *pPointer);
	void ring_QTimer_freefunc(void *pState,void *pPointer);
	void ring_QByteArray_freefunc(void *pState,void *pPointer);
	void ring_QIODevice_freefunc(void *pState,void *pPointer);
	void ring_QFileInfo_freefunc(void *pState,void *pPointer);
	void ring_QStringList_freefunc(void *pState,void *pPointer);
	void ring_QTime_freefunc(void *pState,void *pPointer);
	void ring_QDate_freefunc(void *pState,void *pPointer);
	void ring_QVariant_freefunc(void *pState,void *pPointer);
	void ring_QVariant2_freefunc(void *pState,void *pPointer);
	void ring_QVariant3_freefunc(void *pState,void *pPointer);
	void ring_QVariant4_freefunc(void *pState,void *pPointer);
	void ring_QVariant5_freefunc(void *pState,void *pPointer);
	void ring_QVariantInt_freefunc(void *pState,void *pPointer);
	void ring_QVariantFloat_freefunc(void *pState,void *pPointer);
	void ring_QVariantDouble_freefunc(void *pState,void *pPointer);
	void ring_QVariantString_freefunc(void *pState,void *pPointer);
	void ring_QJsonArray_freefunc(void *pState,void *pPointer);
	void ring_QJsonDocument_freefunc(void *pState,void *pPointer);
	void ring_QJsonObject_freefunc(void *pState,void *pPointer);
	void ring_QJsonParseError_freefunc(void *pState,void *pPointer);
	void ring_QJsonValue_freefunc(void *pState,void *pPointer);
	void ring_QString2_freefunc(void *pState,void *pPointer);
	void ring_QBuffer_freefunc(void *pState,void *pPointer);
	void ring_QDateTime_freefunc(void *pState,void *pPointer);
	void ring_QCoreApplication_freefunc(void *pState,void *pPointer);
	void ring_QFile_freefunc(void *pState,void *pPointer);
	void ring_QFile2_freefunc(void *pState,void *pPointer);
	void ring_QFileDevice_freefunc(void *pState,void *pPointer);
	void ring_QStandardPaths_freefunc(void *pState,void *pPointer);
	void ring_QMimeData_freefunc(void *pState,void *pPointer);
	void ring_QChar_freefunc(void *pState,void *pPointer);
	void ring_QChildEvent_freefunc(void *pState,void *pPointer);
	void ring_QLocale_freefunc(void *pState,void *pPointer);
	void ring_QThread_freefunc(void *pState,void *pPointer);
	void ring_QThreadPool_freefunc(void *pState,void *pPointer);
	void ring_QProcess_freefunc(void *pState,void *pPointer);
	void ring_QUuid_freefunc(void *pState,void *pPointer);
	void ring_QMutex_freefunc(void *pState,void *pPointer);
	void ring_QMutexLocker_freefunc(void *pState,void *pPointer);
	void ring_QVersionNumber_freefunc(void *pState,void *pPointer);
	void ring_QLibraryInfo_freefunc(void *pState,void *pPointer);
	void ring_QPixmap_freefunc(void *pState,void *pPointer);
	void ring_QPixmap2_freefunc(void *pState,void *pPointer);
	void ring_QIcon_freefunc(void *pState,void *pPointer);
	void ring_QPicture_freefunc(void *pState,void *pPointer);
	void ring_QFont_freefunc(void *pState,void *pPointer);
	void ring_QImage_freefunc(void *pState,void *pPointer);
	void ring_QWindow_freefunc(void *pState,void *pPointer);
	void ring_QGuiApplication_freefunc(void *pState,void *pPointer);
	void ring_QClipboard_freefunc(void *pState,void *pPointer);
	void ring_QFontDatabase_freefunc(void *pState,void *pPointer);
	void ring_QApp_freefunc(void *pState,void *pPointer);
	void ring_QAllEvents_freefunc(void *pState,void *pPointer);
	void ring_QAbstractSocket_freefunc(void *pState,void *pPointer);
	void ring_QNetworkProxy_freefunc(void *pState,void *pPointer);
	void ring_QTcpSocket_freefunc(void *pState,void *pPointer);
	void ring_QTcpServer_freefunc(void *pState,void *pPointer);
	void ring_QHostAddress_freefunc(void *pState,void *pPointer);
	void ring_QHostInfo_freefunc(void *pState,void *pPointer);
	void ring_QNetworkRequest_freefunc(void *pState,void *pPointer);
	void ring_QNetworkReply_freefunc(void *pState,void *pPointer);
	void ring_QNetworkAccessManager_freefunc(void *pState,void *pPointer);
	void ring_QQmlError_freefunc(void *pState,void *pPointer);
	void ring_QQmlEngine_freefunc(void *pState,void *pPointer);

// End of Functions Prototype - Functions used to Free Memory 


RING_FUNC(ring_QObject_blockSignals)
{
	QObject *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QObject *) RING_API_GETCPOINTER(1,"QObject");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->blockSignals( (bool ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QObject_children)
{
	QObject *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QObject *) RING_API_GETCPOINTER(1,"QObject");
	{
		QObjectList *pValue ; 
		pValue = (QObjectList *) RING_API_MALLOC(sizeof(QObjectList)) ;
		*pValue = pObject->children();
		RING_API_RETMANAGEDCPOINTER(pValue,"QObjectList",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QObject_dumpObjectInfo)
{
	QObject *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QObject *) RING_API_GETCPOINTER(1,"QObject");
	pObject->dumpObjectInfo();
}


RING_FUNC(ring_QObject_dumpObjectTree)
{
	QObject *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QObject *) RING_API_GETCPOINTER(1,"QObject");
	pObject->dumpObjectTree();
}


RING_FUNC(ring_QObject_inherits)
{
	QObject *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QObject *) RING_API_GETCPOINTER(1,"QObject");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->inherits(RING_API_GETSTRING(2)));
}


RING_FUNC(ring_QObject_installEventFilter)
{
	QObject *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QObject *) RING_API_GETCPOINTER(1,"QObject");
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->installEventFilter((QObject *) RING_API_GETCPOINTER(2,"QObject"));
}


RING_FUNC(ring_QObject_isWidgetType)
{
	QObject *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QObject *) RING_API_GETCPOINTER(1,"QObject");
	RING_API_RETNUMBER(pObject->isWidgetType());
}


RING_FUNC(ring_QObject_killTimer)
{
	QObject *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QObject *) RING_API_GETCPOINTER(1,"QObject");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->killTimer( (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QObject_moveToThread)
{
	QObject *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QObject *) RING_API_GETCPOINTER(1,"QObject");
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->moveToThread((QThread *) RING_API_GETCPOINTER(2,"QThread"));
}


RING_FUNC(ring_QObject_objectName)
{
	QObject *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QObject *) RING_API_GETCPOINTER(1,"QObject");
	RING_API_RETSTRING(pObject->objectName().toStdString().c_str());
}


RING_FUNC(ring_QObject_parent)
{
	QObject *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QObject *) RING_API_GETCPOINTER(1,"QObject");
	RING_API_RETCPOINTER(pObject->parent(),"QObject");
}


RING_FUNC(ring_QObject_property)
{
	QObject *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QObject *) RING_API_GETCPOINTER(1,"QObject");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QVariant *pValue ; 
		pValue = new QVariant() ;
		*pValue = pObject->property(RING_API_GETSTRING(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"QVariant",ring_QVariant_freefunc);
	}
}


RING_FUNC(ring_QObject_removeEventFilter)
{
	QObject *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QObject *) RING_API_GETCPOINTER(1,"QObject");
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->removeEventFilter((QObject *) RING_API_GETCPOINTER(2,"QObject"));
}


RING_FUNC(ring_QObject_setObjectName)
{
	QObject *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QObject *) RING_API_GETCPOINTER(1,"QObject");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setObjectName(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QObject_setParent)
{
	QObject *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QObject *) RING_API_GETCPOINTER(1,"QObject");
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setParent((QObject *) RING_API_GETCPOINTER(2,"QObject"));
}


RING_FUNC(ring_QObject_setProperty)
{
	QObject *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QObject *) RING_API_GETCPOINTER(1,"QObject");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->setProperty(RING_API_GETSTRING(2),* (QVariant *) RING_API_GETCPOINTER(3,"QVariant")));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"QVariant"));
}


RING_FUNC(ring_QObject_setProperty_2)
{
	QObject *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QObject *) RING_API_GETCPOINTER(1,"QObject");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->setProperty(RING_API_GETSTRING(2), (int) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_QObject_setProperty_3)
{
	QObject *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QObject *) RING_API_GETCPOINTER(1,"QObject");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->setProperty(RING_API_GETSTRING(2), (float) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_QObject_setProperty_4)
{
	QObject *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QObject *) RING_API_GETCPOINTER(1,"QObject");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->setProperty(RING_API_GETSTRING(2), (double) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_QObject_setProperty_int)
{
	QObject *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QObject *) RING_API_GETCPOINTER(1,"QObject");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->setProperty(RING_API_GETSTRING(2), (int) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_QObject_setProperty_float)
{
	QObject *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QObject *) RING_API_GETCPOINTER(1,"QObject");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->setProperty(RING_API_GETSTRING(2), (float) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_QObject_setProperty_double)
{
	QObject *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QObject *) RING_API_GETCPOINTER(1,"QObject");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->setProperty(RING_API_GETSTRING(2), (double) RING_API_GETNUMBER(3)));
}

RING_FUNC(ring_QObject_setProperty_5)
{
	QObject *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QObject *) RING_API_GETCPOINTER(1,"QObject");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->setProperty(RING_API_GETSTRING(2),QVariant(QString(RING_API_GETSTRING(3)))));
}

RING_FUNC(ring_QObject_setProperty_string)
{
	QObject *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QObject *) RING_API_GETCPOINTER(1,"QObject");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->setProperty(RING_API_GETSTRING(2),QVariant(QString(RING_API_GETSTRING(3)))));
}

RING_FUNC(ring_QObject_signalsBlocked)
{
	QObject *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QObject *) RING_API_GETCPOINTER(1,"QObject");
	RING_API_RETNUMBER(pObject->signalsBlocked());
}


RING_FUNC(ring_QObject_startTimer)
{
	QObject *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QObject *) RING_API_GETCPOINTER(1,"QObject");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->startTimer( (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QObject_thread)
{
	QObject *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QObject *) RING_API_GETCPOINTER(1,"QObject");
	RING_API_RETCPOINTER(pObject->thread(),"QThread");
}


RING_FUNC(ring_QObject_deleteLater)
{
	QObject *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QObject *) RING_API_GETCPOINTER(1,"QObject");
	pObject->deleteLater();
}


RING_FUNC(ring_QDir_absoluteFilePath)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->absoluteFilePath(RING_API_GETSTRING(2)).toStdString().c_str());
}


RING_FUNC(ring_QDir_absolutePath)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	RING_API_RETSTRING(pObject->absolutePath().toStdString().c_str());
}


RING_FUNC(ring_QDir_canonicalPath)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	RING_API_RETSTRING(pObject->canonicalPath().toStdString().c_str());
}


RING_FUNC(ring_QDir_cd)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->cd(RING_API_GETSTRING(2)));
}


RING_FUNC(ring_QDir_cdUp)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	RING_API_RETNUMBER(pObject->cdUp());
}


RING_FUNC(ring_QDir_count)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	RING_API_RETNUMBER(pObject->count());
}


RING_FUNC(ring_QDir_dirName)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	RING_API_RETSTRING(pObject->dirName().toStdString().c_str());
}


RING_FUNC(ring_QDir_entryInfoList)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QFileInfoList *pValue ; 
		pValue = (QFileInfoList *) RING_API_MALLOC(sizeof(QFileInfoList)) ;
		*pValue = pObject->entryInfoList(* (QStringList  *) RING_API_GETCPOINTER(2,"QStringList"), (QDir::Filters )  (int) RING_API_GETNUMBER(3), (QDir::SortFlags )  (int) RING_API_GETNUMBER(4));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QStringList"));
		RING_API_RETMANAGEDCPOINTER(pValue,"QFileInfoList",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QDir_entryInfoList_2)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QFileInfoList *pValue ; 
		pValue = (QFileInfoList *) RING_API_MALLOC(sizeof(QFileInfoList)) ;
		*pValue = pObject->entryInfoList( (QDir::Filters )  (int) RING_API_GETNUMBER(2), (QDir::SortFlags )  (int) RING_API_GETNUMBER(3));
		RING_API_RETMANAGEDCPOINTER(pValue,"QFileInfoList",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QDir_entryList)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QStringList *pValue ; 
		pValue = new QStringList() ;
		*pValue = pObject->entryList(* (QStringList  *) RING_API_GETCPOINTER(2,"QStringList"), (QDir::Filters )  (int) RING_API_GETNUMBER(3), (QDir::SortFlags )  (int) RING_API_GETNUMBER(4));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QStringList"));
		RING_API_RETMANAGEDCPOINTER(pValue,"QStringList",ring_QStringList_freefunc);
	}
}


RING_FUNC(ring_QDir_entryList_2)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QStringList *pValue ; 
		pValue = new QStringList() ;
		*pValue = pObject->entryList( (QDir::Filters )  (int) RING_API_GETNUMBER(2), (QDir::SortFlags )  (int) RING_API_GETNUMBER(3));
		RING_API_RETMANAGEDCPOINTER(pValue,"QStringList",ring_QStringList_freefunc);
	}
}


RING_FUNC(ring_QDir_exists)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->exists(RING_API_GETSTRING(2)));
}


RING_FUNC(ring_QDir_exists_2)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	RING_API_RETNUMBER(pObject->exists());
}


RING_FUNC(ring_QDir_filePath)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->filePath(RING_API_GETSTRING(2)).toStdString().c_str());
}


RING_FUNC(ring_QDir_filter)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	RING_API_RETNUMBER(pObject->filter());
}


RING_FUNC(ring_QDir_isAbsolute)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	RING_API_RETNUMBER(pObject->isAbsolute());
}


RING_FUNC(ring_QDir_isReadable)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	RING_API_RETNUMBER(pObject->isReadable());
}


RING_FUNC(ring_QDir_isRelative)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	RING_API_RETNUMBER(pObject->isRelative());
}


RING_FUNC(ring_QDir_isRoot)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	RING_API_RETNUMBER(pObject->isRoot());
}


RING_FUNC(ring_QDir_makeAbsolute)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	RING_API_RETNUMBER(pObject->makeAbsolute());
}


RING_FUNC(ring_QDir_mkdir)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->mkdir(RING_API_GETSTRING(2)));
}


RING_FUNC(ring_QDir_mkpath)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->mkpath(RING_API_GETSTRING(2)));
}


RING_FUNC(ring_QDir_nameFilters)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	{
		QStringList *pValue ; 
		pValue = new QStringList() ;
		*pValue = pObject->nameFilters();
		RING_API_RETMANAGEDCPOINTER(pValue,"QStringList",ring_QStringList_freefunc);
	}
}


RING_FUNC(ring_QDir_path)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	RING_API_RETSTRING(pObject->path().toStdString().c_str());
}


RING_FUNC(ring_QDir_refresh)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	pObject->refresh();
}


RING_FUNC(ring_QDir_relativeFilePath)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->relativeFilePath(RING_API_GETSTRING(2)).toStdString().c_str());
}


RING_FUNC(ring_QDir_remove)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->remove(RING_API_GETSTRING(2)));
}


RING_FUNC(ring_QDir_removeRecursively)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	RING_API_RETNUMBER(pObject->removeRecursively());
}


RING_FUNC(ring_QDir_rename)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->rename(RING_API_GETSTRING(2),RING_API_GETSTRING(3)));
}


RING_FUNC(ring_QDir_rmdir)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->rmdir(RING_API_GETSTRING(2)));
}


RING_FUNC(ring_QDir_rmpath)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->rmpath(RING_API_GETSTRING(2)));
}


RING_FUNC(ring_QDir_setFilter)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setFilter( (QDir::Filters )  (int) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QDir_setNameFilters)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	pObject->setNameFilters(* (QStringList  *) RING_API_GETCPOINTER(2,"QStringList"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QStringList"));
}


RING_FUNC(ring_QDir_setPath)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setPath(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QDir_setSorting)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setSorting( (QDir::SortFlags )  (int) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QDir_sorting)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	RING_API_RETNUMBER(pObject->sorting());
}


RING_FUNC(ring_QDir_swap)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	pObject->swap(* (QDir  *) RING_API_GETCPOINTER(2,"QDir"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QDir"));
}


RING_FUNC(ring_QDir_addSearchPath)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->addSearchPath(RING_API_GETSTRING(2),RING_API_GETSTRING(3));
}


RING_FUNC(ring_QDir_cleanPath)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->cleanPath(RING_API_GETSTRING(2)).toStdString().c_str());
}


RING_FUNC(ring_QDir_current)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	{
		QDir *pValue ; 
		pValue = new QDir() ;
		*pValue = pObject->current();
		RING_API_RETMANAGEDCPOINTER(pValue,"QDir",ring_QDir_freefunc);
	}
}


RING_FUNC(ring_QDir_currentPath)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	RING_API_RETSTRING(pObject->currentPath().toStdString().c_str());
}


RING_FUNC(ring_QDir_drives)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	{
		QFileInfoList *pValue ; 
		pValue = (QFileInfoList *) RING_API_MALLOC(sizeof(QFileInfoList)) ;
		*pValue = pObject->drives();
		RING_API_RETMANAGEDCPOINTER(pValue,"QFileInfoList",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QDir_fromNativeSeparators)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->fromNativeSeparators(RING_API_GETSTRING(2)).toStdString().c_str());
}


RING_FUNC(ring_QDir_home)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	{
		QDir *pValue ; 
		pValue = new QDir() ;
		*pValue = pObject->home();
		RING_API_RETMANAGEDCPOINTER(pValue,"QDir",ring_QDir_freefunc);
	}
}


RING_FUNC(ring_QDir_homePath)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	RING_API_RETSTRING(pObject->homePath().toStdString().c_str());
}


RING_FUNC(ring_QDir_isAbsolutePath)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->isAbsolutePath(RING_API_GETSTRING(2)));
}


RING_FUNC(ring_QDir_isRelativePath)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->isRelativePath(RING_API_GETSTRING(2)));
}


RING_FUNC(ring_QDir_match)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->match(RING_API_GETSTRING(2),RING_API_GETSTRING(3)));
}


RING_FUNC(ring_QDir_match_2)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->match(* (QStringList  *) RING_API_GETCPOINTER(2,"QStringList"),RING_API_GETSTRING(3)));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QStringList"));
}


RING_FUNC(ring_QDir_root)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	{
		QDir *pValue ; 
		pValue = new QDir() ;
		*pValue = pObject->root();
		RING_API_RETMANAGEDCPOINTER(pValue,"QDir",ring_QDir_freefunc);
	}
}


RING_FUNC(ring_QDir_rootPath)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	RING_API_RETSTRING(pObject->rootPath().toStdString().c_str());
}


RING_FUNC(ring_QDir_searchPaths)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QStringList *pValue ; 
		pValue = new QStringList() ;
		*pValue = pObject->searchPaths(RING_API_GETSTRING(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"QStringList",ring_QStringList_freefunc);
	}
}


RING_FUNC(ring_QDir_separator)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	{
		QChar *pValue ; 
		pValue = new QChar() ;
		*pValue = pObject->separator();
		RING_API_RETMANAGEDCPOINTER(pValue,"QChar",ring_QChar_freefunc);
	}
}


RING_FUNC(ring_QDir_setCurrent)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->setCurrent(RING_API_GETSTRING(2)));
}


RING_FUNC(ring_QDir_setSearchPaths)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setSearchPaths(RING_API_GETSTRING(2),* (QStringList  *) RING_API_GETCPOINTER(3,"QStringList"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"QStringList"));
}


RING_FUNC(ring_QDir_temp)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	{
		QDir *pValue ; 
		pValue = new QDir() ;
		*pValue = pObject->temp();
		RING_API_RETMANAGEDCPOINTER(pValue,"QDir",ring_QDir_freefunc);
	}
}


RING_FUNC(ring_QDir_tempPath)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	RING_API_RETSTRING(pObject->tempPath().toStdString().c_str());
}


RING_FUNC(ring_QDir_toNativeSeparators)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->toNativeSeparators(RING_API_GETSTRING(2)).toStdString().c_str());
}


RING_FUNC(ring_QUrl_authority)
{
	QUrl *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QUrl *) RING_API_GETCPOINTER(1,"QUrl");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->authority( (QUrl::ComponentFormattingOption )  (int) RING_API_GETNUMBER(2)).toStdString().c_str());
}


RING_FUNC(ring_QUrl_clear)
{
	QUrl *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QUrl *) RING_API_GETCPOINTER(1,"QUrl");
	pObject->clear();
}


RING_FUNC(ring_QUrl_errorString)
{
	QUrl *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QUrl *) RING_API_GETCPOINTER(1,"QUrl");
	RING_API_RETSTRING(pObject->errorString().toStdString().c_str());
}


RING_FUNC(ring_QUrl_fileName)
{
	QUrl *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QUrl *) RING_API_GETCPOINTER(1,"QUrl");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->fileName( (QUrl::ComponentFormattingOption )  (int) RING_API_GETNUMBER(2)).toStdString().c_str());
}


RING_FUNC(ring_QUrl_fragment)
{
	QUrl *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QUrl *) RING_API_GETCPOINTER(1,"QUrl");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->fragment( (QUrl::ComponentFormattingOption )  (int) RING_API_GETNUMBER(2)).toStdString().c_str());
}


RING_FUNC(ring_QUrl_hasFragment)
{
	QUrl *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QUrl *) RING_API_GETCPOINTER(1,"QUrl");
	RING_API_RETNUMBER(pObject->hasFragment());
}


RING_FUNC(ring_QUrl_hasQuery)
{
	QUrl *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QUrl *) RING_API_GETCPOINTER(1,"QUrl");
	RING_API_RETNUMBER(pObject->hasQuery());
}


RING_FUNC(ring_QUrl_host)
{
	QUrl *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QUrl *) RING_API_GETCPOINTER(1,"QUrl");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->host( (QUrl::ComponentFormattingOption )  (int) RING_API_GETNUMBER(2)).toStdString().c_str());
}


RING_FUNC(ring_QUrl_isEmpty)
{
	QUrl *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QUrl *) RING_API_GETCPOINTER(1,"QUrl");
	RING_API_RETNUMBER(pObject->isEmpty());
}


RING_FUNC(ring_QUrl_isLocalFile)
{
	QUrl *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QUrl *) RING_API_GETCPOINTER(1,"QUrl");
	RING_API_RETNUMBER(pObject->isLocalFile());
}


RING_FUNC(ring_QUrl_isParentOf)
{
	QUrl *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QUrl *) RING_API_GETCPOINTER(1,"QUrl");
	RING_API_RETNUMBER(pObject->isParentOf(* (QUrl *) RING_API_GETCPOINTER(2,"QUrl")));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QUrl"));
}


RING_FUNC(ring_QUrl_isRelative)
{
	QUrl *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QUrl *) RING_API_GETCPOINTER(1,"QUrl");
	RING_API_RETNUMBER(pObject->isRelative());
}


RING_FUNC(ring_QUrl_isValid)
{
	QUrl *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QUrl *) RING_API_GETCPOINTER(1,"QUrl");
	RING_API_RETNUMBER(pObject->isValid());
}


RING_FUNC(ring_QUrl_password)
{
	QUrl *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QUrl *) RING_API_GETCPOINTER(1,"QUrl");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->password( (QUrl::ComponentFormattingOption )  (int) RING_API_GETNUMBER(2)).toStdString().c_str());
}


RING_FUNC(ring_QUrl_path)
{
	QUrl *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QUrl *) RING_API_GETCPOINTER(1,"QUrl");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->path( (QUrl::ComponentFormattingOption )  (int) RING_API_GETNUMBER(2)).toStdString().c_str());
}


RING_FUNC(ring_QUrl_port)
{
	QUrl *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QUrl *) RING_API_GETCPOINTER(1,"QUrl");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->port( (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QUrl_query)
{
	QUrl *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QUrl *) RING_API_GETCPOINTER(1,"QUrl");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->query( (QUrl::ComponentFormattingOption )  (int) RING_API_GETNUMBER(2)).toStdString().c_str());
}


RING_FUNC(ring_QUrl_resolved)
{
	QUrl *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QUrl *) RING_API_GETCPOINTER(1,"QUrl");
	{
		QUrl *pValue ; 
		pValue = new QUrl() ;
		*pValue = pObject->resolved(* (QUrl *) RING_API_GETCPOINTER(2,"QUrl"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QUrl"));
		RING_API_RETMANAGEDCPOINTER(pValue,"QUrl",ring_QUrl_freefunc);
	}
}


RING_FUNC(ring_QUrl_scheme)
{
	QUrl *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QUrl *) RING_API_GETCPOINTER(1,"QUrl");
	RING_API_RETSTRING(pObject->scheme().toStdString().c_str());
}


RING_FUNC(ring_QUrl_setAuthority)
{
	QUrl *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QUrl *) RING_API_GETCPOINTER(1,"QUrl");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setAuthority(RING_API_GETSTRING(2), (QUrl::ParsingMode )  (int) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_QUrl_setFragment)
{
	QUrl *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QUrl *) RING_API_GETCPOINTER(1,"QUrl");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setFragment(RING_API_GETSTRING(2), (QUrl::ParsingMode )  (int) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_QUrl_setHost)
{
	QUrl *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QUrl *) RING_API_GETCPOINTER(1,"QUrl");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setHost(RING_API_GETSTRING(2), (QUrl::ParsingMode )  (int) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_QUrl_setPassword)
{
	QUrl *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QUrl *) RING_API_GETCPOINTER(1,"QUrl");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setPassword(RING_API_GETSTRING(2), (QUrl::ParsingMode )  (int) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_QUrl_setPath)
{
	QUrl *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QUrl *) RING_API_GETCPOINTER(1,"QUrl");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setPath(RING_API_GETSTRING(2), (QUrl::ParsingMode )  (int) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_QUrl_setPort)
{
	QUrl *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QUrl *) RING_API_GETCPOINTER(1,"QUrl");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setPort( (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QUrl_setQuery)
{
	QUrl *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QUrl *) RING_API_GETCPOINTER(1,"QUrl");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setQuery(RING_API_GETSTRING(2), (QUrl::ParsingMode )  (int) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_QUrl_setScheme)
{
	QUrl *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QUrl *) RING_API_GETCPOINTER(1,"QUrl");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setScheme(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QUrl_setUrl)
{
	QUrl *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QUrl *) RING_API_GETCPOINTER(1,"QUrl");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setUrl(RING_API_GETSTRING(2), (QUrl::ParsingMode )  (int) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_QUrl_setUserInfo)
{
	QUrl *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QUrl *) RING_API_GETCPOINTER(1,"QUrl");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setUserInfo(RING_API_GETSTRING(2), (QUrl::ParsingMode )  (int) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_QUrl_setUserName)
{
	QUrl *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QUrl *) RING_API_GETCPOINTER(1,"QUrl");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setUserName(RING_API_GETSTRING(2), (QUrl::ParsingMode )  (int) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_QUrl_swap)
{
	QUrl *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QUrl *) RING_API_GETCPOINTER(1,"QUrl");
	pObject->swap(* (QUrl *) RING_API_GETCPOINTER(2,"QUrl"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QUrl"));
}


RING_FUNC(ring_QUrl_toLocalFile)
{
	QUrl *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QUrl *) RING_API_GETCPOINTER(1,"QUrl");
	RING_API_RETSTRING(pObject->toLocalFile().toStdString().c_str());
}


RING_FUNC(ring_QUrl_userInfo)
{
	QUrl *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QUrl *) RING_API_GETCPOINTER(1,"QUrl");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->userInfo( (QUrl::ComponentFormattingOption )  (int) RING_API_GETNUMBER(2)).toStdString().c_str());
}


RING_FUNC(ring_QUrl_userName)
{
	QUrl *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QUrl *) RING_API_GETCPOINTER(1,"QUrl");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->userName( (QUrl::ComponentFormattingOption )  (int) RING_API_GETNUMBER(2)).toStdString().c_str());
}


RING_FUNC(ring_QUrl_fromLocalFile)
{
	QUrl *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QUrl *) RING_API_GETCPOINTER(1,"QUrl");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QUrl *pValue ; 
		pValue = new QUrl() ;
		*pValue = pObject->fromLocalFile(RING_API_GETSTRING(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"QUrl",ring_QUrl_freefunc);
	}
}


RING_FUNC(ring_QEvent_accept)
{
	QEvent *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QEvent *) RING_API_GETCPOINTER(1,"QEvent");
	pObject->accept();
}


RING_FUNC(ring_QEvent_ignore)
{
	QEvent *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QEvent *) RING_API_GETCPOINTER(1,"QEvent");
	pObject->ignore();
}


RING_FUNC(ring_QEvent_isAccepted)
{
	QEvent *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QEvent *) RING_API_GETCPOINTER(1,"QEvent");
	RING_API_RETNUMBER(pObject->isAccepted());
}


RING_FUNC(ring_QEvent_setAccepted)
{
	QEvent *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QEvent *) RING_API_GETCPOINTER(1,"QEvent");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setAccepted( (bool ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QEvent_spontaneous)
{
	QEvent *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QEvent *) RING_API_GETCPOINTER(1,"QEvent");
	RING_API_RETNUMBER(pObject->spontaneous());
}


RING_FUNC(ring_QEvent_type)
{
	QEvent *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QEvent *) RING_API_GETCPOINTER(1,"QEvent");
	RING_API_RETNUMBER(pObject->type());
}


RING_FUNC(ring_QTimer_interval)
{
	GTimer *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GTimer *) RING_API_GETCPOINTER(1,"QTimer");
	RING_API_RETNUMBER(pObject->interval());
}


RING_FUNC(ring_QTimer_isActive)
{
	GTimer *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GTimer *) RING_API_GETCPOINTER(1,"QTimer");
	RING_API_RETNUMBER(pObject->isActive());
}


RING_FUNC(ring_QTimer_isSingleShot)
{
	GTimer *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GTimer *) RING_API_GETCPOINTER(1,"QTimer");
	RING_API_RETNUMBER(pObject->isSingleShot());
}


RING_FUNC(ring_QTimer_setInterval)
{
	GTimer *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GTimer *) RING_API_GETCPOINTER(1,"QTimer");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setInterval( (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QTimer_setSingleShot)
{
	GTimer *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GTimer *) RING_API_GETCPOINTER(1,"QTimer");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setSingleShot( (bool ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QTimer_timerId)
{
	GTimer *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GTimer *) RING_API_GETCPOINTER(1,"QTimer");
	RING_API_RETNUMBER(pObject->timerId());
}


RING_FUNC(ring_QTimer_start)
{
	GTimer *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GTimer *) RING_API_GETCPOINTER(1,"QTimer");
	pObject->start();
}


RING_FUNC(ring_QTimer_stop)
{
	GTimer *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GTimer *) RING_API_GETCPOINTER(1,"QTimer");
	pObject->stop();
}


RING_FUNC(ring_QTimer_settimeoutEvent)
{
	GTimer *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GTimer *) RING_API_GETCPOINTER(1,"QTimer");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->settimeoutEvent(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QTimer_gettimeoutEvent)
{
	GTimer *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GTimer *) RING_API_GETCPOINTER(1,"QTimer");
	RING_API_RETSTRING(pObject->gettimeoutEvent());
}


RING_FUNC(ring_QByteArray_append)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QByteArray *pValue ; 
		pValue = new QByteArray() ;
		*pValue = pObject->append(RING_API_GETSTRING(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"QByteArray",ring_QByteArray_freefunc);
	}
}


RING_FUNC(ring_QByteArray_append_2)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QByteArray *pValue ; 
		pValue = new QByteArray() ;
		*pValue = pObject->append(RING_API_GETSTRING(2), (int ) RING_API_GETNUMBER(3));
		RING_API_RETMANAGEDCPOINTER(pValue,"QByteArray",ring_QByteArray_freefunc);
	}
}


RING_FUNC(ring_QByteArray_at)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->at( (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QByteArray_capacity)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	RING_API_RETNUMBER(pObject->capacity());
}


RING_FUNC(ring_QByteArray_chop)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->chop( (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QByteArray_clear)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	pObject->clear();
}


RING_FUNC(ring_QByteArray_constData)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	RING_API_RETSTRING(pObject->constData());
}


RING_FUNC(ring_QByteArray_contains)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->contains(RING_API_GETSTRING(2)));
}


RING_FUNC(ring_QByteArray_count)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->count(RING_API_GETSTRING(2)));
}


RING_FUNC(ring_QByteArray_data)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	RING_API_RETSTRING(pObject->data());
}


RING_FUNC(ring_QByteArray_endsWith)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->endsWith(RING_API_GETSTRING(2)));
}


RING_FUNC(ring_QByteArray_fill)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QByteArray *pValue ; 
		pValue = new QByteArray() ;
		*pValue = pObject->fill( (char ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3));
		RING_API_RETMANAGEDCPOINTER(pValue,"QByteArray",ring_QByteArray_freefunc);
	}
}


RING_FUNC(ring_QByteArray_indexOf)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->indexOf(RING_API_GETSTRING(2), (int ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_QByteArray_insert)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QByteArray *pValue ; 
		pValue = new QByteArray() ;
		*pValue = pObject->insert( (int ) RING_API_GETNUMBER(2),RING_API_GETSTRING(3), (int ) RING_API_GETNUMBER(4));
		RING_API_RETMANAGEDCPOINTER(pValue,"QByteArray",ring_QByteArray_freefunc);
	}
}


RING_FUNC(ring_QByteArray_isEmpty)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	RING_API_RETNUMBER(pObject->isEmpty());
}


RING_FUNC(ring_QByteArray_isNull)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	RING_API_RETNUMBER(pObject->isNull());
}


RING_FUNC(ring_QByteArray_lastIndexOf)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->lastIndexOf(RING_API_GETSTRING(2), (int ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_QByteArray_left)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QByteArray *pValue ; 
		pValue = new QByteArray() ;
		*pValue = pObject->left( (int ) RING_API_GETNUMBER(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"QByteArray",ring_QByteArray_freefunc);
	}
}


RING_FUNC(ring_QByteArray_leftJustified)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QByteArray *pValue ; 
		pValue = new QByteArray() ;
		*pValue = pObject->leftJustified( (int ) RING_API_GETNUMBER(2), (char ) RING_API_GETNUMBER(3), (bool ) RING_API_GETNUMBER(4));
		RING_API_RETMANAGEDCPOINTER(pValue,"QByteArray",ring_QByteArray_freefunc);
	}
}


RING_FUNC(ring_QByteArray_length)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	RING_API_RETNUMBER(pObject->length());
}


RING_FUNC(ring_QByteArray_mid)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QByteArray *pValue ; 
		pValue = new QByteArray() ;
		*pValue = pObject->mid( (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3));
		RING_API_RETMANAGEDCPOINTER(pValue,"QByteArray",ring_QByteArray_freefunc);
	}
}


RING_FUNC(ring_QByteArray_prepend)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QByteArray *pValue ; 
		pValue = new QByteArray() ;
		*pValue = pObject->prepend(RING_API_GETSTRING(2), (int ) RING_API_GETNUMBER(3));
		RING_API_RETMANAGEDCPOINTER(pValue,"QByteArray",ring_QByteArray_freefunc);
	}
}


RING_FUNC(ring_QByteArray_push_back)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->push_back(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QByteArray_push_front)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->push_front(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QByteArray_remove)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QByteArray *pValue ; 
		pValue = new QByteArray() ;
		*pValue = pObject->remove( (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3));
		RING_API_RETMANAGEDCPOINTER(pValue,"QByteArray",ring_QByteArray_freefunc);
	}
}


RING_FUNC(ring_QByteArray_repeated)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QByteArray *pValue ; 
		pValue = new QByteArray() ;
		*pValue = pObject->repeated( (int ) RING_API_GETNUMBER(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"QByteArray",ring_QByteArray_freefunc);
	}
}


RING_FUNC(ring_QByteArray_replace)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QByteArray *pValue ; 
		pValue = new QByteArray() ;
		*pValue = pObject->replace( (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3),RING_API_GETSTRING(4), (int ) RING_API_GETNUMBER(5));
		RING_API_RETMANAGEDCPOINTER(pValue,"QByteArray",ring_QByteArray_freefunc);
	}
}


RING_FUNC(ring_QByteArray_replace_2)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QByteArray *pValue ; 
		pValue = new QByteArray() ;
		*pValue = pObject->replace( (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3),* (QByteArray  *) RING_API_GETCPOINTER(4,"QByteArray"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"QByteArray"));
		RING_API_RETMANAGEDCPOINTER(pValue,"QByteArray",ring_QByteArray_freefunc);
	}
}


RING_FUNC(ring_QByteArray_replace_3)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QByteArray *pValue ; 
		pValue = new QByteArray() ;
		*pValue = pObject->replace( (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3),RING_API_GETSTRING(4));
		RING_API_RETMANAGEDCPOINTER(pValue,"QByteArray",ring_QByteArray_freefunc);
	}
}


RING_FUNC(ring_QByteArray_replace_4)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QByteArray *pValue ; 
		pValue = new QByteArray() ;
		*pValue = pObject->replace( (char ) RING_API_GETNUMBER(2),RING_API_GETSTRING(3));
		RING_API_RETMANAGEDCPOINTER(pValue,"QByteArray",ring_QByteArray_freefunc);
	}
}


RING_FUNC(ring_QByteArray_replace_5)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QByteArray *pValue ; 
		pValue = new QByteArray() ;
		*pValue = pObject->replace( (char ) RING_API_GETNUMBER(2),* (QByteArray  *) RING_API_GETCPOINTER(3,"QByteArray"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"QByteArray"));
		RING_API_RETMANAGEDCPOINTER(pValue,"QByteArray",ring_QByteArray_freefunc);
	}
}


RING_FUNC(ring_QByteArray_replace_6)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QByteArray *pValue ; 
		pValue = new QByteArray() ;
		*pValue = pObject->replace(RING_API_GETSTRING(2),RING_API_GETSTRING(3));
		RING_API_RETMANAGEDCPOINTER(pValue,"QByteArray",ring_QByteArray_freefunc);
	}
}


RING_FUNC(ring_QByteArray_replace_7)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QByteArray *pValue ; 
		pValue = new QByteArray() ;
		*pValue = pObject->replace(RING_API_GETSTRING(2), (int ) RING_API_GETNUMBER(3),RING_API_GETSTRING(4), (int ) RING_API_GETNUMBER(5));
		RING_API_RETMANAGEDCPOINTER(pValue,"QByteArray",ring_QByteArray_freefunc);
	}
}


RING_FUNC(ring_QByteArray_replace_8)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	{
		QByteArray *pValue ; 
		pValue = new QByteArray() ;
		*pValue = pObject->replace(* (const QByteArray  *) RING_API_GETCPOINTER(2,"const QByteArray"),* (QByteArray  *) RING_API_GETCPOINTER(3,"QByteArray"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QByteArray"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"QByteArray"));
		RING_API_RETMANAGEDCPOINTER(pValue,"QByteArray",ring_QByteArray_freefunc);
	}
}


RING_FUNC(ring_QByteArray_replace_9)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QByteArray *pValue ; 
		pValue = new QByteArray() ;
		*pValue = pObject->replace(* (const QByteArray  *) RING_API_GETCPOINTER(2,"const QByteArray"),RING_API_GETSTRING(3));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QByteArray"));
		RING_API_RETMANAGEDCPOINTER(pValue,"QByteArray",ring_QByteArray_freefunc);
	}
}


RING_FUNC(ring_QByteArray_replace_10)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QByteArray *pValue ; 
		pValue = new QByteArray() ;
		*pValue = pObject->replace(RING_API_GETSTRING(2),* (QByteArray  *) RING_API_GETCPOINTER(3,"QByteArray"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"QByteArray"));
		RING_API_RETMANAGEDCPOINTER(pValue,"QByteArray",ring_QByteArray_freefunc);
	}
}


RING_FUNC(ring_QByteArray_replace_11)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QByteArray *pValue ; 
		pValue = new QByteArray() ;
		*pValue = pObject->replace( (char ) RING_API_GETNUMBER(2), (char ) RING_API_GETNUMBER(3));
		RING_API_RETMANAGEDCPOINTER(pValue,"QByteArray",ring_QByteArray_freefunc);
	}
}


RING_FUNC(ring_QByteArray_reserve)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->reserve( (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QByteArray_resize)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->resize( (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QByteArray_right)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QByteArray *pValue ; 
		pValue = new QByteArray() ;
		*pValue = pObject->right( (int ) RING_API_GETNUMBER(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"QByteArray",ring_QByteArray_freefunc);
	}
}


RING_FUNC(ring_QByteArray_rightJustified)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QByteArray *pValue ; 
		pValue = new QByteArray() ;
		*pValue = pObject->rightJustified( (int ) RING_API_GETNUMBER(2), (char ) RING_API_GETNUMBER(3), (bool ) RING_API_GETNUMBER(4));
		RING_API_RETMANAGEDCPOINTER(pValue,"QByteArray",ring_QByteArray_freefunc);
	}
}


RING_FUNC(ring_QByteArray_setNum)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QByteArray *pValue ; 
		pValue = new QByteArray() ;
		*pValue = pObject->setNum( (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3));
		RING_API_RETMANAGEDCPOINTER(pValue,"QByteArray",ring_QByteArray_freefunc);
	}
}


RING_FUNC(ring_QByteArray_setRawData)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QByteArray *pValue ; 
		pValue = new QByteArray() ;
		*pValue = pObject->setRawData(RING_API_GETSTRING(2), (uint ) RING_API_GETNUMBER(3));
		RING_API_RETMANAGEDCPOINTER(pValue,"QByteArray",ring_QByteArray_freefunc);
	}
}


RING_FUNC(ring_QByteArray_simplified)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	{
		QByteArray *pValue ; 
		pValue = new QByteArray() ;
		*pValue = pObject->simplified();
		RING_API_RETMANAGEDCPOINTER(pValue,"QByteArray",ring_QByteArray_freefunc);
	}
}


RING_FUNC(ring_QByteArray_size)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	RING_API_RETNUMBER(pObject->size());
}


RING_FUNC(ring_QByteArray_squeeze)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	pObject->squeeze();
}


RING_FUNC(ring_QByteArray_startsWith)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->startsWith(RING_API_GETSTRING(2)));
}


RING_FUNC(ring_QByteArray_swap)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	pObject->swap(* (QByteArray  *) RING_API_GETCPOINTER(2,"QByteArray"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QByteArray"));
}


RING_FUNC(ring_QByteArray_toBase64)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	{
		QByteArray *pValue ; 
		pValue = new QByteArray() ;
		*pValue = pObject->toBase64();
		RING_API_RETMANAGEDCPOINTER(pValue,"QByteArray",ring_QByteArray_freefunc);
	}
}


RING_FUNC(ring_QByteArray_toDouble)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->toDouble((bool *) RING_API_GETCPOINTER(2,"bool")));
}


RING_FUNC(ring_QByteArray_toFloat)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->toFloat((bool *) RING_API_GETCPOINTER(2,"bool")));
}


RING_FUNC(ring_QByteArray_toHex)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	{
		QByteArray *pValue ; 
		pValue = new QByteArray() ;
		*pValue = pObject->toHex();
		RING_API_RETMANAGEDCPOINTER(pValue,"QByteArray",ring_QByteArray_freefunc);
	}
}


RING_FUNC(ring_QByteArray_toInt)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->toInt((bool *) RING_API_GETCPOINTER(2,"bool"), (int ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_QByteArray_toLong)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		long *pValue ; 
		pValue = (long *) RING_API_MALLOC(sizeof(long)) ;
		*pValue = pObject->toLong((bool *) RING_API_GETCPOINTER(2,"bool"), (int ) RING_API_GETNUMBER(3));
		RING_API_RETMANAGEDCPOINTER(pValue,"long",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QByteArray_toLongLong)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		qlonglong *pValue ; 
		pValue = (qlonglong *) RING_API_MALLOC(sizeof(qlonglong)) ;
		*pValue = pObject->toLongLong((bool *) RING_API_GETCPOINTER(2,"bool"), (int ) RING_API_GETNUMBER(3));
		RING_API_RETMANAGEDCPOINTER(pValue,"qlonglong",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QByteArray_toLower)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	{
		QByteArray *pValue ; 
		pValue = new QByteArray() ;
		*pValue = pObject->toLower();
		RING_API_RETMANAGEDCPOINTER(pValue,"QByteArray",ring_QByteArray_freefunc);
	}
}


RING_FUNC(ring_QByteArray_toPercentEncoding)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QByteArray *pValue ; 
		pValue = new QByteArray() ;
		*pValue = pObject->toPercentEncoding(* (QByteArray *) RING_API_GETCPOINTER(2,"QByteArray"),* (QByteArray *) RING_API_GETCPOINTER(3,"QByteArray"), (char ) RING_API_GETNUMBER(4));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QByteArray"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"QByteArray"));
		RING_API_RETMANAGEDCPOINTER(pValue,"QByteArray",ring_QByteArray_freefunc);
	}
}


RING_FUNC(ring_QByteArray_toShort)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		short *pValue ; 
		pValue = (short *) RING_API_MALLOC(sizeof(short)) ;
		*pValue = pObject->toShort((bool *) RING_API_GETCPOINTER(2,"bool"), (int ) RING_API_GETNUMBER(3));
		RING_API_RETMANAGEDCPOINTER(pValue,"short",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QByteArray_toUInt)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->toUInt((bool *) RING_API_GETCPOINTER(2,"bool"), (int ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_QByteArray_toULong)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->toULong((bool *) RING_API_GETCPOINTER(2,"bool"), (int ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_QByteArray_toULongLong)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->toULongLong((bool *) RING_API_GETCPOINTER(2,"bool"), (int ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_QByteArray_toUShort)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->toUShort((bool *) RING_API_GETCPOINTER(2,"bool"), (int ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_QByteArray_toUpper)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	{
		QByteArray *pValue ; 
		pValue = new QByteArray() ;
		*pValue = pObject->toUpper();
		RING_API_RETMANAGEDCPOINTER(pValue,"QByteArray",ring_QByteArray_freefunc);
	}
}


RING_FUNC(ring_QByteArray_trimmed)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	{
		QByteArray *pValue ; 
		pValue = new QByteArray() ;
		*pValue = pObject->trimmed();
		RING_API_RETMANAGEDCPOINTER(pValue,"QByteArray",ring_QByteArray_freefunc);
	}
}


RING_FUNC(ring_QByteArray_truncate)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->truncate( (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QByteArray_fromBase64)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	{
		QByteArray *pValue ; 
		pValue = new QByteArray() ;
		*pValue = pObject->fromBase64(* (QByteArray *) RING_API_GETCPOINTER(2,"QByteArray"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QByteArray"));
		RING_API_RETMANAGEDCPOINTER(pValue,"QByteArray",ring_QByteArray_freefunc);
	}
}


RING_FUNC(ring_QByteArray_fromHex)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	{
		QByteArray *pValue ; 
		pValue = new QByteArray() ;
		*pValue = pObject->fromHex(* (QByteArray *) RING_API_GETCPOINTER(2,"QByteArray"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QByteArray"));
		RING_API_RETMANAGEDCPOINTER(pValue,"QByteArray",ring_QByteArray_freefunc);
	}
}


RING_FUNC(ring_QByteArray_fromPercentEncoding)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QByteArray *pValue ; 
		pValue = new QByteArray() ;
		*pValue = pObject->fromPercentEncoding(* (QByteArray *) RING_API_GETCPOINTER(2,"QByteArray"), (char ) RING_API_GETNUMBER(3));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QByteArray"));
		RING_API_RETMANAGEDCPOINTER(pValue,"QByteArray",ring_QByteArray_freefunc);
	}
}


RING_FUNC(ring_QByteArray_fromRawData)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QByteArray *pValue ; 
		pValue = new QByteArray() ;
		*pValue = pObject->fromRawData(RING_API_GETSTRING(2), (int ) RING_API_GETNUMBER(3));
		RING_API_RETMANAGEDCPOINTER(pValue,"QByteArray",ring_QByteArray_freefunc);
	}
}


RING_FUNC(ring_QByteArray_number)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QByteArray *pValue ; 
		pValue = new QByteArray() ;
		*pValue = pObject->number( (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3));
		RING_API_RETMANAGEDCPOINTER(pValue,"QByteArray",ring_QByteArray_freefunc);
	}
}


RING_FUNC(ring_QIODevice_errorString)
{
	GIODevice *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GIODevice *) RING_API_GETCPOINTER(1,"QIODevice");
	RING_API_RETSTRING(pObject->errorString().toStdString().c_str());
}


RING_FUNC(ring_QIODevice_getChar)
{
	GIODevice *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GIODevice *) RING_API_GETCPOINTER(1,"QIODevice");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->getChar(RING_API_GETSTRING(2)));
}


RING_FUNC(ring_QIODevice_isOpen)
{
	GIODevice *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GIODevice *) RING_API_GETCPOINTER(1,"QIODevice");
	RING_API_RETNUMBER(pObject->isOpen());
}


RING_FUNC(ring_QIODevice_isReadable)
{
	GIODevice *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GIODevice *) RING_API_GETCPOINTER(1,"QIODevice");
	RING_API_RETNUMBER(pObject->isReadable());
}


RING_FUNC(ring_QIODevice_isTextModeEnabled)
{
	GIODevice *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GIODevice *) RING_API_GETCPOINTER(1,"QIODevice");
	RING_API_RETNUMBER(pObject->isTextModeEnabled());
}


RING_FUNC(ring_QIODevice_isWritable)
{
	GIODevice *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GIODevice *) RING_API_GETCPOINTER(1,"QIODevice");
	RING_API_RETNUMBER(pObject->isWritable());
}


RING_FUNC(ring_QIODevice_openMode)
{
	GIODevice *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GIODevice *) RING_API_GETCPOINTER(1,"QIODevice");
	RING_API_RETNUMBER(pObject->openMode());
}


RING_FUNC(ring_QIODevice_peek)
{
	GIODevice *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GIODevice *) RING_API_GETCPOINTER(1,"QIODevice");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->peek(RING_API_GETSTRING(2), (int ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_QIODevice_putChar)
{
	GIODevice *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GIODevice *) RING_API_GETCPOINTER(1,"QIODevice");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->putChar( (char ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QIODevice_read)
{
	GIODevice *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GIODevice *) RING_API_GETCPOINTER(1,"QIODevice");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->read(RING_API_GETSTRING(2), (int ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_QIODevice_readAll)
{
	GIODevice *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GIODevice *) RING_API_GETCPOINTER(1,"QIODevice");
	{
		QByteArray *pValue ; 
		pValue = new QByteArray() ;
		*pValue = pObject->readAll();
		RING_API_RETMANAGEDCPOINTER(pValue,"QByteArray",ring_QByteArray_freefunc);
	}
}


RING_FUNC(ring_QIODevice_readLine)
{
	GIODevice *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GIODevice *) RING_API_GETCPOINTER(1,"QIODevice");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->readLine(RING_API_GETSTRING(2), (int ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_QIODevice_setTextModeEnabled)
{
	GIODevice *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GIODevice *) RING_API_GETCPOINTER(1,"QIODevice");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setTextModeEnabled( (bool ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QIODevice_ungetChar)
{
	GIODevice *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GIODevice *) RING_API_GETCPOINTER(1,"QIODevice");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->ungetChar( (char ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QIODevice_write)
{
	GIODevice *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GIODevice *) RING_API_GETCPOINTER(1,"QIODevice");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->write(RING_API_GETSTRING(2), (int ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_QIODevice_atEnd)
{
	GIODevice *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GIODevice *) RING_API_GETCPOINTER(1,"QIODevice");
	RING_API_RETNUMBER(pObject->atEnd());
}


RING_FUNC(ring_QIODevice_canReadLine)
{
	GIODevice *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GIODevice *) RING_API_GETCPOINTER(1,"QIODevice");
	RING_API_RETNUMBER(pObject->canReadLine());
}


RING_FUNC(ring_QIODevice_close)
{
	GIODevice *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GIODevice *) RING_API_GETCPOINTER(1,"QIODevice");
	pObject->close();
}


RING_FUNC(ring_QIODevice_open)
{
	GIODevice *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GIODevice *) RING_API_GETCPOINTER(1,"QIODevice");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->open( (QIODevice::OpenMode )  (int) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QIODevice_pos)
{
	GIODevice *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GIODevice *) RING_API_GETCPOINTER(1,"QIODevice");
	RING_API_RETNUMBER(pObject->pos());
}


RING_FUNC(ring_QIODevice_seek)
{
	GIODevice *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GIODevice *) RING_API_GETCPOINTER(1,"QIODevice");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->seek( (qint64 ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QIODevice_size)
{
	GIODevice *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GIODevice *) RING_API_GETCPOINTER(1,"QIODevice");
	RING_API_RETNUMBER(pObject->size());
}


RING_FUNC(ring_QIODevice_setaboutToCloseEvent)
{
	GIODevice *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GIODevice *) RING_API_GETCPOINTER(1,"QIODevice");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setaboutToCloseEvent(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QIODevice_setbytesWrittenEvent)
{
	GIODevice *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GIODevice *) RING_API_GETCPOINTER(1,"QIODevice");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setbytesWrittenEvent(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QIODevice_setreadChannelFinishedEvent)
{
	GIODevice *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GIODevice *) RING_API_GETCPOINTER(1,"QIODevice");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setreadChannelFinishedEvent(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QIODevice_setreadyReadEvent)
{
	GIODevice *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GIODevice *) RING_API_GETCPOINTER(1,"QIODevice");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setreadyReadEvent(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QIODevice_getaboutToCloseEvent)
{
	GIODevice *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GIODevice *) RING_API_GETCPOINTER(1,"QIODevice");
	RING_API_RETSTRING(pObject->getaboutToCloseEvent());
}


RING_FUNC(ring_QIODevice_getbytesWrittenEvent)
{
	GIODevice *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GIODevice *) RING_API_GETCPOINTER(1,"QIODevice");
	RING_API_RETSTRING(pObject->getbytesWrittenEvent());
}


RING_FUNC(ring_QIODevice_getreadChannelFinishedEvent)
{
	GIODevice *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GIODevice *) RING_API_GETCPOINTER(1,"QIODevice");
	RING_API_RETSTRING(pObject->getreadChannelFinishedEvent());
}


RING_FUNC(ring_QIODevice_getreadyReadEvent)
{
	GIODevice *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GIODevice *) RING_API_GETCPOINTER(1,"QIODevice");
	RING_API_RETSTRING(pObject->getreadyReadEvent());
}


RING_FUNC(ring_QFileInfo_absoluteDir)
{
	QFileInfo *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileInfo *) RING_API_GETCPOINTER(1,"QFileInfo");
	{
		QDir *pValue ; 
		pValue = new QDir() ;
		*pValue = pObject->absoluteDir();
		RING_API_RETMANAGEDCPOINTER(pValue,"QDir",ring_QDir_freefunc);
	}
}


RING_FUNC(ring_QFileInfo_absoluteFilePath)
{
	QFileInfo *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileInfo *) RING_API_GETCPOINTER(1,"QFileInfo");
	RING_API_RETSTRING(pObject->absoluteFilePath().toStdString().c_str());
}


RING_FUNC(ring_QFileInfo_absolutePath)
{
	QFileInfo *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileInfo *) RING_API_GETCPOINTER(1,"QFileInfo");
	RING_API_RETSTRING(pObject->absolutePath().toStdString().c_str());
}


RING_FUNC(ring_QFileInfo_baseName)
{
	QFileInfo *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileInfo *) RING_API_GETCPOINTER(1,"QFileInfo");
	RING_API_RETSTRING(pObject->baseName().toStdString().c_str());
}


RING_FUNC(ring_QFileInfo_bundleName)
{
	QFileInfo *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileInfo *) RING_API_GETCPOINTER(1,"QFileInfo");
	RING_API_RETSTRING(pObject->bundleName().toStdString().c_str());
}


RING_FUNC(ring_QFileInfo_caching)
{
	QFileInfo *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileInfo *) RING_API_GETCPOINTER(1,"QFileInfo");
	RING_API_RETNUMBER(pObject->caching());
}


RING_FUNC(ring_QFileInfo_canonicalFilePath)
{
	QFileInfo *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileInfo *) RING_API_GETCPOINTER(1,"QFileInfo");
	RING_API_RETSTRING(pObject->canonicalFilePath().toStdString().c_str());
}


RING_FUNC(ring_QFileInfo_canonicalPath)
{
	QFileInfo *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileInfo *) RING_API_GETCPOINTER(1,"QFileInfo");
	RING_API_RETSTRING(pObject->canonicalPath().toStdString().c_str());
}


RING_FUNC(ring_QFileInfo_completeBaseName)
{
	QFileInfo *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileInfo *) RING_API_GETCPOINTER(1,"QFileInfo");
	RING_API_RETSTRING(pObject->completeBaseName().toStdString().c_str());
}


RING_FUNC(ring_QFileInfo_completeSuffix)
{
	QFileInfo *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileInfo *) RING_API_GETCPOINTER(1,"QFileInfo");
	RING_API_RETSTRING(pObject->completeSuffix().toStdString().c_str());
}


RING_FUNC(ring_QFileInfo_dir)
{
	QFileInfo *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileInfo *) RING_API_GETCPOINTER(1,"QFileInfo");
	{
		QDir *pValue ; 
		pValue = new QDir() ;
		*pValue = pObject->dir();
		RING_API_RETMANAGEDCPOINTER(pValue,"QDir",ring_QDir_freefunc);
	}
}


RING_FUNC(ring_QFileInfo_exists)
{
	QFileInfo *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileInfo *) RING_API_GETCPOINTER(1,"QFileInfo");
	RING_API_RETNUMBER(pObject->exists());
}


RING_FUNC(ring_QFileInfo_fileName)
{
	QFileInfo *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileInfo *) RING_API_GETCPOINTER(1,"QFileInfo");
	RING_API_RETSTRING(pObject->fileName().toStdString().c_str());
}


RING_FUNC(ring_QFileInfo_filePath)
{
	QFileInfo *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileInfo *) RING_API_GETCPOINTER(1,"QFileInfo");
	RING_API_RETSTRING(pObject->filePath().toStdString().c_str());
}


RING_FUNC(ring_QFileInfo_group)
{
	QFileInfo *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileInfo *) RING_API_GETCPOINTER(1,"QFileInfo");
	RING_API_RETSTRING(pObject->group().toStdString().c_str());
}


RING_FUNC(ring_QFileInfo_groupId)
{
	QFileInfo *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileInfo *) RING_API_GETCPOINTER(1,"QFileInfo");
	RING_API_RETNUMBER(pObject->groupId());
}


RING_FUNC(ring_QFileInfo_isAbsolute)
{
	QFileInfo *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileInfo *) RING_API_GETCPOINTER(1,"QFileInfo");
	RING_API_RETNUMBER(pObject->isAbsolute());
}


RING_FUNC(ring_QFileInfo_isBundle)
{
	QFileInfo *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileInfo *) RING_API_GETCPOINTER(1,"QFileInfo");
	RING_API_RETNUMBER(pObject->isBundle());
}


RING_FUNC(ring_QFileInfo_isDir)
{
	QFileInfo *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileInfo *) RING_API_GETCPOINTER(1,"QFileInfo");
	RING_API_RETNUMBER(pObject->isDir());
}


RING_FUNC(ring_QFileInfo_isExecutable)
{
	QFileInfo *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileInfo *) RING_API_GETCPOINTER(1,"QFileInfo");
	RING_API_RETNUMBER(pObject->isExecutable());
}


RING_FUNC(ring_QFileInfo_isFile)
{
	QFileInfo *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileInfo *) RING_API_GETCPOINTER(1,"QFileInfo");
	RING_API_RETNUMBER(pObject->isFile());
}


RING_FUNC(ring_QFileInfo_isHidden)
{
	QFileInfo *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileInfo *) RING_API_GETCPOINTER(1,"QFileInfo");
	RING_API_RETNUMBER(pObject->isHidden());
}


RING_FUNC(ring_QFileInfo_isNativePath)
{
	QFileInfo *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileInfo *) RING_API_GETCPOINTER(1,"QFileInfo");
	RING_API_RETNUMBER(pObject->isNativePath());
}


RING_FUNC(ring_QFileInfo_isReadable)
{
	QFileInfo *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileInfo *) RING_API_GETCPOINTER(1,"QFileInfo");
	RING_API_RETNUMBER(pObject->isReadable());
}


RING_FUNC(ring_QFileInfo_isRelative)
{
	QFileInfo *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileInfo *) RING_API_GETCPOINTER(1,"QFileInfo");
	RING_API_RETNUMBER(pObject->isRelative());
}


RING_FUNC(ring_QFileInfo_isRoot)
{
	QFileInfo *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileInfo *) RING_API_GETCPOINTER(1,"QFileInfo");
	RING_API_RETNUMBER(pObject->isRoot());
}


RING_FUNC(ring_QFileInfo_isSymLink)
{
	QFileInfo *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileInfo *) RING_API_GETCPOINTER(1,"QFileInfo");
	RING_API_RETNUMBER(pObject->isSymLink());
}


RING_FUNC(ring_QFileInfo_isWritable)
{
	QFileInfo *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileInfo *) RING_API_GETCPOINTER(1,"QFileInfo");
	RING_API_RETNUMBER(pObject->isWritable());
}


RING_FUNC(ring_QFileInfo_lastModified)
{
	QFileInfo *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileInfo *) RING_API_GETCPOINTER(1,"QFileInfo");
	{
		QDateTime *pValue ; 
		pValue = new QDateTime() ;
		*pValue = pObject->lastModified();
		RING_API_RETMANAGEDCPOINTER(pValue,"QDateTime",ring_QDateTime_freefunc);
	}
}


RING_FUNC(ring_QFileInfo_lastRead)
{
	QFileInfo *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileInfo *) RING_API_GETCPOINTER(1,"QFileInfo");
	{
		QDateTime *pValue ; 
		pValue = new QDateTime() ;
		*pValue = pObject->lastRead();
		RING_API_RETMANAGEDCPOINTER(pValue,"QDateTime",ring_QDateTime_freefunc);
	}
}


RING_FUNC(ring_QFileInfo_makeAbsolute)
{
	QFileInfo *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileInfo *) RING_API_GETCPOINTER(1,"QFileInfo");
	RING_API_RETNUMBER(pObject->makeAbsolute());
}


RING_FUNC(ring_QFileInfo_owner)
{
	QFileInfo *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileInfo *) RING_API_GETCPOINTER(1,"QFileInfo");
	RING_API_RETSTRING(pObject->owner().toStdString().c_str());
}


RING_FUNC(ring_QFileInfo_ownerId)
{
	QFileInfo *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileInfo *) RING_API_GETCPOINTER(1,"QFileInfo");
	RING_API_RETNUMBER(pObject->ownerId());
}


RING_FUNC(ring_QFileInfo_path)
{
	QFileInfo *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileInfo *) RING_API_GETCPOINTER(1,"QFileInfo");
	RING_API_RETSTRING(pObject->path().toStdString().c_str());
}


RING_FUNC(ring_QFileInfo_permission)
{
	QFileInfo *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileInfo *) RING_API_GETCPOINTER(1,"QFileInfo");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->permission( (QFileDevice::Permission )  (int) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QFileInfo_permissions)
{
	QFileInfo *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileInfo *) RING_API_GETCPOINTER(1,"QFileInfo");
	RING_API_RETNUMBER(pObject->permissions());
}


RING_FUNC(ring_QFileInfo_refresh)
{
	QFileInfo *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileInfo *) RING_API_GETCPOINTER(1,"QFileInfo");
	pObject->refresh();
}


RING_FUNC(ring_QFileInfo_setCaching)
{
	QFileInfo *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileInfo *) RING_API_GETCPOINTER(1,"QFileInfo");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setCaching( (bool ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QFileInfo_setFile)
{
	QFileInfo *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileInfo *) RING_API_GETCPOINTER(1,"QFileInfo");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setFile(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QFileInfo_size)
{
	QFileInfo *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileInfo *) RING_API_GETCPOINTER(1,"QFileInfo");
	RING_API_RETNUMBER(pObject->size());
}


RING_FUNC(ring_QFileInfo_suffix)
{
	QFileInfo *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileInfo *) RING_API_GETCPOINTER(1,"QFileInfo");
	RING_API_RETSTRING(pObject->suffix().toStdString().c_str());
}


RING_FUNC(ring_QFileInfo_swap)
{
	QFileInfo *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileInfo *) RING_API_GETCPOINTER(1,"QFileInfo");
	pObject->swap(* (QFileInfo *) RING_API_GETCPOINTER(2,"QFileInfo"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QFileInfo"));
}


RING_FUNC(ring_QFileInfo_symLinkTarget)
{
	QFileInfo *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileInfo *) RING_API_GETCPOINTER(1,"QFileInfo");
	RING_API_RETSTRING(pObject->symLinkTarget().toStdString().c_str());
}


RING_FUNC(ring_QStringList_join)
{
	QStringList *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringList *) RING_API_GETCPOINTER(1,"QStringList");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->join(RING_API_GETSTRING(2)).toStdString().c_str());
}


RING_FUNC(ring_QStringList_sort)
{
	QStringList *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringList *) RING_API_GETCPOINTER(1,"QStringList");
	pObject->sort();
}


RING_FUNC(ring_QStringList_removeDuplicates)
{
	QStringList *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringList *) RING_API_GETCPOINTER(1,"QStringList");
	RING_API_RETNUMBER(pObject->removeDuplicates());
}


RING_FUNC(ring_QStringList_filter)
{
	QStringList *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringList *) RING_API_GETCPOINTER(1,"QStringList");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QStringList *pValue ; 
		pValue = new QStringList() ;
		*pValue = pObject->filter(RING_API_GETSTRING(2), (Qt::CaseSensitivity)  (int) RING_API_GETNUMBER(3));
		RING_API_RETMANAGEDCPOINTER(pValue,"QStringList",ring_QStringList_freefunc);
	}
}


RING_FUNC(ring_QStringList_replaceInStrings)
{
	QStringList *pObject ;
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringList *) RING_API_GETCPOINTER(1,"QStringList");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QStringList *pValue ; 
		pValue = new QStringList() ;
		*pValue = pObject->replaceInStrings(RING_API_GETSTRING(2),RING_API_GETSTRING(3), (Qt::CaseSensitivity)  (int) RING_API_GETNUMBER(4));
		RING_API_RETMANAGEDCPOINTER(pValue,"QStringList",ring_QStringList_freefunc);
	}
}


RING_FUNC(ring_QStringList_append)
{
	QStringList *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringList *) RING_API_GETCPOINTER(1,"QStringList");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->append(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QStringList_at)
{
	QStringList *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringList *) RING_API_GETCPOINTER(1,"QStringList");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->at( (int) RING_API_GETNUMBER(2)).toStdString().c_str());
}


RING_FUNC(ring_QStringList_back)
{
	QStringList *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringList *) RING_API_GETCPOINTER(1,"QStringList");
	RING_API_RETSTRING(pObject->back().toStdString().c_str());
}


RING_FUNC(ring_QStringList_clear)
{
	QStringList *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringList *) RING_API_GETCPOINTER(1,"QStringList");
	pObject->clear();
}


RING_FUNC(ring_QStringList_contains)
{
	QStringList *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringList *) RING_API_GETCPOINTER(1,"QStringList");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->contains(RING_API_GETSTRING(2)));
}


RING_FUNC(ring_QStringList_count)
{
	QStringList *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringList *) RING_API_GETCPOINTER(1,"QStringList");
	RING_API_RETNUMBER(pObject->count());
}


RING_FUNC(ring_QStringList_empty)
{
	QStringList *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringList *) RING_API_GETCPOINTER(1,"QStringList");
	RING_API_RETNUMBER(pObject->empty());
}


RING_FUNC(ring_QStringList_endsWith)
{
	QStringList *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringList *) RING_API_GETCPOINTER(1,"QStringList");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->endsWith(RING_API_GETSTRING(2)));
}


RING_FUNC(ring_QStringList_first)
{
	QStringList *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringList *) RING_API_GETCPOINTER(1,"QStringList");
	RING_API_RETSTRING(pObject->first().toStdString().c_str());
}


RING_FUNC(ring_QStringList_front)
{
	QStringList *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringList *) RING_API_GETCPOINTER(1,"QStringList");
	RING_API_RETSTRING(pObject->front().toStdString().c_str());
}


RING_FUNC(ring_QStringList_indexOf)
{
	QStringList *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringList *) RING_API_GETCPOINTER(1,"QStringList");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->indexOf(RING_API_GETSTRING(2), (int) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_QStringList_insert)
{
	QStringList *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringList *) RING_API_GETCPOINTER(1,"QStringList");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->insert( (int) RING_API_GETNUMBER(2),RING_API_GETSTRING(3));
}


RING_FUNC(ring_QStringList_isEmpty)
{
	QStringList *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringList *) RING_API_GETCPOINTER(1,"QStringList");
	RING_API_RETNUMBER(pObject->isEmpty());
}


RING_FUNC(ring_QStringList_last)
{
	QStringList *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringList *) RING_API_GETCPOINTER(1,"QStringList");
	RING_API_RETSTRING(pObject->last().toStdString().c_str());
}


RING_FUNC(ring_QStringList_lastIndexOf)
{
	QStringList *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringList *) RING_API_GETCPOINTER(1,"QStringList");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->lastIndexOf(RING_API_GETSTRING(2), (int) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_QStringList_length)
{
	QStringList *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringList *) RING_API_GETCPOINTER(1,"QStringList");
	RING_API_RETNUMBER(pObject->length());
}


RING_FUNC(ring_QStringList_move)
{
	QStringList *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringList *) RING_API_GETCPOINTER(1,"QStringList");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->move( (int) RING_API_GETNUMBER(2), (int) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_QStringList_pop_back)
{
	QStringList *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringList *) RING_API_GETCPOINTER(1,"QStringList");
	pObject->pop_back();
}


RING_FUNC(ring_QStringList_pop_front)
{
	QStringList *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringList *) RING_API_GETCPOINTER(1,"QStringList");
	pObject->pop_front();
}


RING_FUNC(ring_QStringList_prepend)
{
	QStringList *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringList *) RING_API_GETCPOINTER(1,"QStringList");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->prepend(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QStringList_push_back)
{
	QStringList *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringList *) RING_API_GETCPOINTER(1,"QStringList");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->push_back(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QStringList_push_front)
{
	QStringList *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringList *) RING_API_GETCPOINTER(1,"QStringList");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->push_front(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QStringList_removeAll)
{
	QStringList *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringList *) RING_API_GETCPOINTER(1,"QStringList");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->removeAll(RING_API_GETSTRING(2)));
}


RING_FUNC(ring_QStringList_removeAt)
{
	QStringList *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringList *) RING_API_GETCPOINTER(1,"QStringList");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->removeAt( (int) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QStringList_removeFirst)
{
	QStringList *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringList *) RING_API_GETCPOINTER(1,"QStringList");
	pObject->removeFirst();
}


RING_FUNC(ring_QStringList_removeLast)
{
	QStringList *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringList *) RING_API_GETCPOINTER(1,"QStringList");
	pObject->removeLast();
}


RING_FUNC(ring_QStringList_removeOne)
{
	QStringList *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringList *) RING_API_GETCPOINTER(1,"QStringList");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->removeOne(RING_API_GETSTRING(2)));
}


RING_FUNC(ring_QStringList_replace)
{
	QStringList *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringList *) RING_API_GETCPOINTER(1,"QStringList");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->replace( (int) RING_API_GETNUMBER(2),RING_API_GETSTRING(3));
}


RING_FUNC(ring_QStringList_reserve)
{
	QStringList *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringList *) RING_API_GETCPOINTER(1,"QStringList");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->reserve( (int) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QStringList_size)
{
	QStringList *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringList *) RING_API_GETCPOINTER(1,"QStringList");
	RING_API_RETNUMBER(pObject->size());
}


RING_FUNC(ring_QStringList_startsWith)
{
	QStringList *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringList *) RING_API_GETCPOINTER(1,"QStringList");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->startsWith(RING_API_GETSTRING(2)));
}


RING_FUNC(ring_QStringList_takeAt)
{
	QStringList *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringList *) RING_API_GETCPOINTER(1,"QStringList");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->takeAt( (int) RING_API_GETNUMBER(2)).toStdString().c_str());
}


RING_FUNC(ring_QStringList_takeFirst)
{
	QStringList *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringList *) RING_API_GETCPOINTER(1,"QStringList");
	RING_API_RETSTRING(pObject->takeFirst().toStdString().c_str());
}


RING_FUNC(ring_QStringList_takeLast)
{
	QStringList *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringList *) RING_API_GETCPOINTER(1,"QStringList");
	RING_API_RETSTRING(pObject->takeLast().toStdString().c_str());
}


RING_FUNC(ring_QStringList_value)
{
	QStringList *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringList *) RING_API_GETCPOINTER(1,"QStringList");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->value( (int) RING_API_GETNUMBER(2)).toStdString().c_str());
}


RING_FUNC(ring_QTime_addMSecs)
{
	QTime *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QTime *) RING_API_GETCPOINTER(1,"QTime");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QTime *pValue ; 
		pValue = new QTime() ;
		*pValue = pObject->addMSecs( (int ) RING_API_GETNUMBER(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"QTime",ring_QTime_freefunc);
	}
}


RING_FUNC(ring_QTime_addSecs)
{
	QTime *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QTime *) RING_API_GETCPOINTER(1,"QTime");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QTime *pValue ; 
		pValue = new QTime() ;
		*pValue = pObject->addSecs( (int ) RING_API_GETNUMBER(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"QTime",ring_QTime_freefunc);
	}
}


RING_FUNC(ring_QTime_hour)
{
	QTime *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QTime *) RING_API_GETCPOINTER(1,"QTime");
	RING_API_RETNUMBER(pObject->hour());
}


RING_FUNC(ring_QTime_isNull)
{
	QTime *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QTime *) RING_API_GETCPOINTER(1,"QTime");
	RING_API_RETNUMBER(pObject->isNull());
}


RING_FUNC(ring_QTime_isValid)
{
	QTime *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QTime *) RING_API_GETCPOINTER(1,"QTime");
	RING_API_RETNUMBER(pObject->isValid());
}


RING_FUNC(ring_QTime_minute)
{
	QTime *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QTime *) RING_API_GETCPOINTER(1,"QTime");
	RING_API_RETNUMBER(pObject->minute());
}


RING_FUNC(ring_QTime_msec)
{
	QTime *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QTime *) RING_API_GETCPOINTER(1,"QTime");
	RING_API_RETNUMBER(pObject->msec());
}


RING_FUNC(ring_QTime_msecsSinceStartOfDay)
{
	QTime *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QTime *) RING_API_GETCPOINTER(1,"QTime");
	RING_API_RETNUMBER(pObject->msecsSinceStartOfDay());
}


RING_FUNC(ring_QTime_msecsTo)
{
	QTime *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QTime *) RING_API_GETCPOINTER(1,"QTime");
	RING_API_RETNUMBER(pObject->msecsTo(* (QTime *) RING_API_GETCPOINTER(2,"QTime")));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QTime"));
}


RING_FUNC(ring_QTime_second)
{
	QTime *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QTime *) RING_API_GETCPOINTER(1,"QTime");
	RING_API_RETNUMBER(pObject->second());
}


RING_FUNC(ring_QTime_secsTo)
{
	QTime *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QTime *) RING_API_GETCPOINTER(1,"QTime");
	RING_API_RETNUMBER(pObject->secsTo(* (QTime *) RING_API_GETCPOINTER(2,"QTime")));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QTime"));
}


RING_FUNC(ring_QTime_setHMS)
{
	QTime *pObject ;
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QTime *) RING_API_GETCPOINTER(1,"QTime");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->setHMS( (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4), (int ) RING_API_GETNUMBER(5)));
}


RING_FUNC(ring_QTime_toString)
{
	QTime *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QTime *) RING_API_GETCPOINTER(1,"QTime");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->toString(RING_API_GETSTRING(2)).toStdString().c_str());
}


RING_FUNC(ring_QTime_currentTime)
{
	QTime *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QTime *) RING_API_GETCPOINTER(1,"QTime");
	{
		QTime *pValue ; 
		pValue = new QTime() ;
		*pValue = pObject->currentTime();
		RING_API_RETMANAGEDCPOINTER(pValue,"QTime",ring_QTime_freefunc);
	}
}


RING_FUNC(ring_QTime_fromMSecsSinceStartOfDay)
{
	QTime *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QTime *) RING_API_GETCPOINTER(1,"QTime");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QTime *pValue ; 
		pValue = new QTime() ;
		*pValue = pObject->fromMSecsSinceStartOfDay( (int ) RING_API_GETNUMBER(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"QTime",ring_QTime_freefunc);
	}
}


RING_FUNC(ring_QTime_fromString)
{
	QTime *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QTime *) RING_API_GETCPOINTER(1,"QTime");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QTime *pValue ; 
		pValue = new QTime() ;
		*pValue = pObject->fromString(RING_API_GETSTRING(2),RING_API_GETSTRING(3));
		RING_API_RETMANAGEDCPOINTER(pValue,"QTime",ring_QTime_freefunc);
	}
}


RING_FUNC(ring_QDate_addDays)
{
	QDate *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDate *) RING_API_GETCPOINTER(1,"QDate");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QDate *pValue ; 
		pValue = new QDate() ;
		*pValue = pObject->addDays( (int ) RING_API_GETNUMBER(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"QDate",ring_QDate_freefunc);
	}
}


RING_FUNC(ring_QDate_addMonths)
{
	QDate *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDate *) RING_API_GETCPOINTER(1,"QDate");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QDate *pValue ; 
		pValue = new QDate() ;
		*pValue = pObject->addMonths( (int ) RING_API_GETNUMBER(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"QDate",ring_QDate_freefunc);
	}
}


RING_FUNC(ring_QDate_addYears)
{
	QDate *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDate *) RING_API_GETCPOINTER(1,"QDate");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QDate *pValue ; 
		pValue = new QDate() ;
		*pValue = pObject->addYears( (int ) RING_API_GETNUMBER(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"QDate",ring_QDate_freefunc);
	}
}


RING_FUNC(ring_QDate_day)
{
	QDate *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDate *) RING_API_GETCPOINTER(1,"QDate");
	RING_API_RETNUMBER(pObject->day());
}


RING_FUNC(ring_QDate_dayOfWeek)
{
	QDate *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDate *) RING_API_GETCPOINTER(1,"QDate");
	RING_API_RETNUMBER(pObject->dayOfWeek());
}


RING_FUNC(ring_QDate_dayOfYear)
{
	QDate *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDate *) RING_API_GETCPOINTER(1,"QDate");
	RING_API_RETNUMBER(pObject->dayOfYear());
}


RING_FUNC(ring_QDate_daysInMonth)
{
	QDate *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDate *) RING_API_GETCPOINTER(1,"QDate");
	RING_API_RETNUMBER(pObject->daysInMonth());
}


RING_FUNC(ring_QDate_daysInYear)
{
	QDate *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDate *) RING_API_GETCPOINTER(1,"QDate");
	RING_API_RETNUMBER(pObject->daysInYear());
}


RING_FUNC(ring_QDate_daysTo)
{
	QDate *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDate *) RING_API_GETCPOINTER(1,"QDate");
	RING_API_RETNUMBER(pObject->daysTo(* (QDate *) RING_API_GETCPOINTER(2,"QDate")));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QDate"));
}


RING_FUNC(ring_QDate_getDate)
{
	QDate *pObject ;
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDate *) RING_API_GETCPOINTER(1,"QDate");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->getDate(RING_API_GETINTPOINTER(2),RING_API_GETINTPOINTER(3),RING_API_GETINTPOINTER(4));
	RING_API_ACCEPTINTVALUE(1) ;
	RING_API_ACCEPTINTVALUE(2) ;
	RING_API_ACCEPTINTVALUE(3) ;
}


RING_FUNC(ring_QDate_isNull)
{
	QDate *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDate *) RING_API_GETCPOINTER(1,"QDate");
	RING_API_RETNUMBER(pObject->isNull());
}


RING_FUNC(ring_QDate_isValid)
{
	QDate *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDate *) RING_API_GETCPOINTER(1,"QDate");
	RING_API_RETNUMBER(pObject->isValid());
}


RING_FUNC(ring_QDate_month)
{
	QDate *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDate *) RING_API_GETCPOINTER(1,"QDate");
	RING_API_RETNUMBER(pObject->month());
}


RING_FUNC(ring_QDate_setDate)
{
	QDate *pObject ;
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDate *) RING_API_GETCPOINTER(1,"QDate");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->setDate( (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4)));
}


RING_FUNC(ring_QDate_toJulianDay)
{
	QDate *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDate *) RING_API_GETCPOINTER(1,"QDate");
	RING_API_RETNUMBER(pObject->toJulianDay());
}


RING_FUNC(ring_QDate_toString)
{
	QDate *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDate *) RING_API_GETCPOINTER(1,"QDate");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->toString(RING_API_GETSTRING(2)).toStdString().c_str());
}


RING_FUNC(ring_QDate_weekNumber)
{
	QDate *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDate *) RING_API_GETCPOINTER(1,"QDate");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->weekNumber(RING_API_GETINTPOINTER(2)));
	RING_API_ACCEPTINTVALUE(1) ;
}


RING_FUNC(ring_QDate_year)
{
	QDate *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDate *) RING_API_GETCPOINTER(1,"QDate");
	RING_API_RETNUMBER(pObject->year());
}


RING_FUNC(ring_QDate_currentDate)
{
	QDate *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDate *) RING_API_GETCPOINTER(1,"QDate");
	{
		QDate *pValue ; 
		pValue = new QDate() ;
		*pValue = pObject->currentDate();
		RING_API_RETMANAGEDCPOINTER(pValue,"QDate",ring_QDate_freefunc);
	}
}


RING_FUNC(ring_QDate_fromJulianDay)
{
	QDate *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDate *) RING_API_GETCPOINTER(1,"QDate");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QDate *pValue ; 
		pValue = new QDate() ;
		*pValue = pObject->fromJulianDay( (int ) RING_API_GETNUMBER(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"QDate",ring_QDate_freefunc);
	}
}


RING_FUNC(ring_QDate_fromString)
{
	QDate *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDate *) RING_API_GETCPOINTER(1,"QDate");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QDate *pValue ; 
		pValue = new QDate() ;
		*pValue = pObject->fromString(RING_API_GETSTRING(2),RING_API_GETSTRING(3));
		RING_API_RETMANAGEDCPOINTER(pValue,"QDate",ring_QDate_freefunc);
	}
}


RING_FUNC(ring_QDate_isLeapYear)
{
	QDate *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDate *) RING_API_GETCPOINTER(1,"QDate");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->isLeapYear( (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QVariant_canConvert)
{
	QVariant *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QVariant *) RING_API_GETCPOINTER(1,"QVariant");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->canConvert( (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QVariant_clear)
{
	QVariant *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QVariant *) RING_API_GETCPOINTER(1,"QVariant");
	pObject->clear();
}


RING_FUNC(ring_QVariant_convert)
{
	QVariant *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QVariant *) RING_API_GETCPOINTER(1,"QVariant");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->convert( (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QVariant_isNull)
{
	QVariant *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QVariant *) RING_API_GETCPOINTER(1,"QVariant");
	RING_API_RETNUMBER(pObject->isNull());
}


RING_FUNC(ring_QVariant_isValid)
{
	QVariant *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QVariant *) RING_API_GETCPOINTER(1,"QVariant");
	RING_API_RETNUMBER(pObject->isValid());
}


RING_FUNC(ring_QVariant_swap)
{
	QVariant *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QVariant *) RING_API_GETCPOINTER(1,"QVariant");
	pObject->swap(* (QVariant *) RING_API_GETCPOINTER(2,"QVariant"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QVariant"));
}


RING_FUNC(ring_QVariant_toBitArray)
{
	QVariant *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QVariant *) RING_API_GETCPOINTER(1,"QVariant");
	{
		QBitArray *pValue ; 
		pValue = (QBitArray *) RING_API_MALLOC(sizeof(QBitArray)) ;
		*pValue = pObject->toBitArray();
		RING_API_RETMANAGEDCPOINTER(pValue,"QBitArray",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QVariant_toBool)
{
	QVariant *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QVariant *) RING_API_GETCPOINTER(1,"QVariant");
	RING_API_RETNUMBER(pObject->toBool());
}


RING_FUNC(ring_QVariant_toByteArray)
{
	QVariant *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QVariant *) RING_API_GETCPOINTER(1,"QVariant");
	{
		QByteArray *pValue ; 
		pValue = new QByteArray() ;
		*pValue = pObject->toByteArray();
		RING_API_RETMANAGEDCPOINTER(pValue,"QByteArray",ring_QByteArray_freefunc);
	}
}


RING_FUNC(ring_QVariant_toChar)
{
	QVariant *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QVariant *) RING_API_GETCPOINTER(1,"QVariant");
	{
		QChar *pValue ; 
		pValue = new QChar() ;
		*pValue = pObject->toChar();
		RING_API_RETMANAGEDCPOINTER(pValue,"QChar",ring_QChar_freefunc);
	}
}


RING_FUNC(ring_QVariant_toDate)
{
	QVariant *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QVariant *) RING_API_GETCPOINTER(1,"QVariant");
	{
		QDate *pValue ; 
		pValue = new QDate() ;
		*pValue = pObject->toDate();
		RING_API_RETMANAGEDCPOINTER(pValue,"QDate",ring_QDate_freefunc);
	}
}


RING_FUNC(ring_QVariant_toDateTime)
{
	QVariant *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QVariant *) RING_API_GETCPOINTER(1,"QVariant");
	{
		QDateTime *pValue ; 
		pValue = new QDateTime() ;
		*pValue = pObject->toDateTime();
		RING_API_RETMANAGEDCPOINTER(pValue,"QDateTime",ring_QDateTime_freefunc);
	}
}


RING_FUNC(ring_QVariant_toDouble)
{
	QVariant *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QVariant *) RING_API_GETCPOINTER(1,"QVariant");
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->toDouble((bool *) RING_API_GETCPOINTER(2,"bool")));
}


RING_FUNC(ring_QVariant_toEasingCurve)
{
	QVariant *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QVariant *) RING_API_GETCPOINTER(1,"QVariant");
	{
		QEasingCurve *pValue ; 
		pValue = (QEasingCurve *) RING_API_MALLOC(sizeof(QEasingCurve)) ;
		*pValue = pObject->toEasingCurve();
		RING_API_RETMANAGEDCPOINTER(pValue,"QEasingCurve",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QVariant_toFloat)
{
	QVariant *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QVariant *) RING_API_GETCPOINTER(1,"QVariant");
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->toFloat((bool *) RING_API_GETCPOINTER(2,"bool")));
}


RING_FUNC(ring_QVariant_toInt)
{
	QVariant *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QVariant *) RING_API_GETCPOINTER(1,"QVariant");
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->toInt((bool *) RING_API_GETCPOINTER(2,"bool")));
}


RING_FUNC(ring_QVariant_toJsonArray)
{
	QVariant *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QVariant *) RING_API_GETCPOINTER(1,"QVariant");
	{
		QJsonArray *pValue ; 
		pValue = new QJsonArray() ;
		*pValue = pObject->toJsonArray();
		RING_API_RETMANAGEDCPOINTER(pValue,"QJsonArray",ring_QJsonArray_freefunc);
	}
}


RING_FUNC(ring_QVariant_toJsonDocument)
{
	QVariant *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QVariant *) RING_API_GETCPOINTER(1,"QVariant");
	{
		QJsonDocument *pValue ; 
		pValue = new QJsonDocument() ;
		*pValue = pObject->toJsonDocument();
		RING_API_RETMANAGEDCPOINTER(pValue,"QJsonDocument",ring_QJsonDocument_freefunc);
	}
}


RING_FUNC(ring_QVariant_toJsonObject)
{
	QVariant *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QVariant *) RING_API_GETCPOINTER(1,"QVariant");
	{
		QJsonObject *pValue ; 
		pValue = new QJsonObject() ;
		*pValue = pObject->toJsonObject();
		RING_API_RETMANAGEDCPOINTER(pValue,"QJsonObject",ring_QJsonObject_freefunc);
	}
}


RING_FUNC(ring_QVariant_toJsonValue)
{
	QVariant *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QVariant *) RING_API_GETCPOINTER(1,"QVariant");
	{
		QJsonValue *pValue ; 
		pValue = new QJsonValue() ;
		*pValue = pObject->toJsonValue();
		RING_API_RETMANAGEDCPOINTER(pValue,"QJsonValue",ring_QJsonValue_freefunc);
	}
}


RING_FUNC(ring_QVariant_toLine)
{
	QVariant *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QVariant *) RING_API_GETCPOINTER(1,"QVariant");
	{
		QLine *pValue ; 
		pValue = (QLine *) RING_API_MALLOC(sizeof(QLine)) ;
		*pValue = pObject->toLine();
		RING_API_RETMANAGEDCPOINTER(pValue,"QLine",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QVariant_toLineF)
{
	QVariant *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QVariant *) RING_API_GETCPOINTER(1,"QVariant");
	{
		QLineF *pValue ; 
		pValue = (QLineF *) RING_API_MALLOC(sizeof(QLineF)) ;
		*pValue = pObject->toLineF();
		RING_API_RETMANAGEDCPOINTER(pValue,"QLineF",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QVariant_toLocale)
{
	QVariant *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QVariant *) RING_API_GETCPOINTER(1,"QVariant");
	{
		QLocale *pValue ; 
		pValue = new QLocale() ;
		*pValue = pObject->toLocale();
		RING_API_RETMANAGEDCPOINTER(pValue,"QLocale",ring_QLocale_freefunc);
	}
}


RING_FUNC(ring_QVariant_toLongLong)
{
	QVariant *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QVariant *) RING_API_GETCPOINTER(1,"QVariant");
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		qlonglong *pValue ; 
		pValue = (qlonglong *) RING_API_MALLOC(sizeof(qlonglong)) ;
		*pValue = pObject->toLongLong((bool *) RING_API_GETCPOINTER(2,"bool"));
		RING_API_RETMANAGEDCPOINTER(pValue,"qlonglong",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QVariant_toModelIndex)
{
	QVariant *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QVariant *) RING_API_GETCPOINTER(1,"QVariant");
	{
		QModelIndex *pValue ; 
		pValue = (QModelIndex *) RING_API_MALLOC(sizeof(QModelIndex)) ;
		*pValue = pObject->toModelIndex();
		RING_API_RETMANAGEDCPOINTER(pValue,"QModelIndex",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QVariant_toPoint)
{
	QVariant *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QVariant *) RING_API_GETCPOINTER(1,"QVariant");
	{
		QPoint *pValue ; 
		pValue = (QPoint *) RING_API_MALLOC(sizeof(QPoint)) ;
		*pValue = pObject->toPoint();
		RING_API_RETMANAGEDCPOINTER(pValue,"QPoint",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QVariant_toPointF)
{
	QVariant *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QVariant *) RING_API_GETCPOINTER(1,"QVariant");
	{
		QPointF *pValue ; 
		pValue = (QPointF *) RING_API_MALLOC(sizeof(QPointF)) ;
		*pValue = pObject->toPointF();
		RING_API_RETMANAGEDCPOINTER(pValue,"QPointF",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QVariant_toReal)
{
	QVariant *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QVariant *) RING_API_GETCPOINTER(1,"QVariant");
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->toReal((bool *) RING_API_GETCPOINTER(2,"bool")));
}


RING_FUNC(ring_QVariant_toRect)
{
	QVariant *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QVariant *) RING_API_GETCPOINTER(1,"QVariant");
	{
		QRect *pValue ; 
		pValue = (QRect *) RING_API_MALLOC(sizeof(QRect)) ;
		*pValue = pObject->toRect();
		RING_API_RETMANAGEDCPOINTER(pValue,"QRect",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QVariant_toRectF)
{
	QVariant *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QVariant *) RING_API_GETCPOINTER(1,"QVariant");
	{
		QRectF *pValue ; 
		pValue = (QRectF *) RING_API_MALLOC(sizeof(QRectF)) ;
		*pValue = pObject->toRectF();
		RING_API_RETMANAGEDCPOINTER(pValue,"QRectF",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QVariant_toSize)
{
	QVariant *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QVariant *) RING_API_GETCPOINTER(1,"QVariant");
	{
		QSize *pValue ; 
		pValue = new QSize() ;
		*pValue = pObject->toSize();
		RING_API_RETMANAGEDCPOINTER(pValue,"QSize",ring_QSize_freefunc);
	}
}


RING_FUNC(ring_QVariant_toSizeF)
{
	QVariant *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QVariant *) RING_API_GETCPOINTER(1,"QVariant");
	{
		QSizeF *pValue ; 
		pValue = (QSizeF *) RING_API_MALLOC(sizeof(QSizeF)) ;
		*pValue = pObject->toSizeF();
		RING_API_RETMANAGEDCPOINTER(pValue,"QSizeF",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QVariant_toStringList)
{
	QVariant *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QVariant *) RING_API_GETCPOINTER(1,"QVariant");
	{
		QStringList *pValue ; 
		pValue = new QStringList() ;
		*pValue = pObject->toStringList();
		RING_API_RETMANAGEDCPOINTER(pValue,"QStringList",ring_QStringList_freefunc);
	}
}


RING_FUNC(ring_QVariant_toTime)
{
	QVariant *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QVariant *) RING_API_GETCPOINTER(1,"QVariant");
	{
		QTime *pValue ; 
		pValue = new QTime() ;
		*pValue = pObject->toTime();
		RING_API_RETMANAGEDCPOINTER(pValue,"QTime",ring_QTime_freefunc);
	}
}


RING_FUNC(ring_QVariant_toUInt)
{
	QVariant *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QVariant *) RING_API_GETCPOINTER(1,"QVariant");
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->toUInt((bool *) RING_API_GETCPOINTER(2,"bool")));
}


RING_FUNC(ring_QVariant_toULongLong)
{
	QVariant *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QVariant *) RING_API_GETCPOINTER(1,"QVariant");
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		qulonglong *pValue ; 
		pValue = (qulonglong *) RING_API_MALLOC(sizeof(qulonglong)) ;
		*pValue = pObject->toULongLong((bool *) RING_API_GETCPOINTER(2,"bool"));
		RING_API_RETMANAGEDCPOINTER(pValue,"qulonglong",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QVariant_toUrl)
{
	QVariant *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QVariant *) RING_API_GETCPOINTER(1,"QVariant");
	{
		QUrl *pValue ; 
		pValue = new QUrl() ;
		*pValue = pObject->toUrl();
		RING_API_RETMANAGEDCPOINTER(pValue,"QUrl",ring_QUrl_freefunc);
	}
}


RING_FUNC(ring_QVariant_toUuid)
{
	QVariant *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QVariant *) RING_API_GETCPOINTER(1,"QVariant");
	{
		QUuid *pValue ; 
		pValue = new QUuid() ;
		*pValue = pObject->toUuid();
		RING_API_RETMANAGEDCPOINTER(pValue,"QUuid",ring_QUuid_freefunc);
	}
}


RING_FUNC(ring_QVariant_type)
{
	QVariant *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QVariant *) RING_API_GETCPOINTER(1,"QVariant");
	RING_API_RETNUMBER(pObject->type());
}


RING_FUNC(ring_QVariant_typeName)
{
	QVariant *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QVariant *) RING_API_GETCPOINTER(1,"QVariant");
	RING_API_RETSTRING(pObject->typeName());
}


RING_FUNC(ring_QVariant_userType)
{
	QVariant *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QVariant *) RING_API_GETCPOINTER(1,"QVariant");
	RING_API_RETNUMBER(pObject->userType());
}


RING_FUNC(ring_QVariant_toString)
{
	QVariant *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QVariant *) RING_API_GETCPOINTER(1,"QVariant");
	RING_API_RETSTRING(pObject->toString().toStdString().c_str());
}

RING_FUNC(ring_QVariant5_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	QVariant *pObject = new QVariant(QString(RING_API_GETSTRING(1)));
	RING_API_RETCPOINTER(pObject,"QVariant5");
}

RING_FUNC(ring_QVariantString_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	QVariant *pObject = new QVariant(QString(RING_API_GETSTRING(1)));
	RING_API_RETCPOINTER(pObject,"QVariantString");
}

RING_FUNC(ring_QJsonArray_append)
{
	QJsonArray *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonArray *) RING_API_GETCPOINTER(1,"QJsonArray");
	pObject->append(* (QJsonValue   *) RING_API_GETCPOINTER(2,"QJsonValue"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QJsonValue"));
}


RING_FUNC(ring_QJsonArray_at)
{
	QJsonArray *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonArray *) RING_API_GETCPOINTER(1,"QJsonArray");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QJsonValue *pValue ; 
		pValue = new QJsonValue() ;
		*pValue = pObject->at( (int ) RING_API_GETNUMBER(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"QJsonValue",ring_QJsonValue_freefunc);
	}
}


RING_FUNC(ring_QJsonArray_contains)
{
	QJsonArray *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonArray *) RING_API_GETCPOINTER(1,"QJsonArray");
	RING_API_RETNUMBER(pObject->contains(* (QJsonValue   *) RING_API_GETCPOINTER(2,"QJsonValue")));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QJsonValue"));
}


RING_FUNC(ring_QJsonArray_count)
{
	QJsonArray *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonArray *) RING_API_GETCPOINTER(1,"QJsonArray");
	RING_API_RETNUMBER(pObject->count());
}


RING_FUNC(ring_QJsonArray_empty)
{
	QJsonArray *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonArray *) RING_API_GETCPOINTER(1,"QJsonArray");
	RING_API_RETNUMBER(pObject->empty());
}


RING_FUNC(ring_QJsonArray_first)
{
	QJsonArray *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonArray *) RING_API_GETCPOINTER(1,"QJsonArray");
	{
		QJsonValue *pValue ; 
		pValue = new QJsonValue() ;
		*pValue = pObject->first();
		RING_API_RETMANAGEDCPOINTER(pValue,"QJsonValue",ring_QJsonValue_freefunc);
	}
}


RING_FUNC(ring_QJsonArray_insert)
{
	QJsonArray *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonArray *) RING_API_GETCPOINTER(1,"QJsonArray");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->insert( (int ) RING_API_GETNUMBER(2),* (QJsonValue   *) RING_API_GETCPOINTER(3,"QJsonValue"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"QJsonValue"));
}


RING_FUNC(ring_QJsonArray_isEmpty)
{
	QJsonArray *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonArray *) RING_API_GETCPOINTER(1,"QJsonArray");
	RING_API_RETNUMBER(pObject->isEmpty());
}


RING_FUNC(ring_QJsonArray_last)
{
	QJsonArray *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonArray *) RING_API_GETCPOINTER(1,"QJsonArray");
	{
		QJsonValue *pValue ; 
		pValue = new QJsonValue() ;
		*pValue = pObject->last();
		RING_API_RETMANAGEDCPOINTER(pValue,"QJsonValue",ring_QJsonValue_freefunc);
	}
}


RING_FUNC(ring_QJsonArray_pop_back)
{
	QJsonArray *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonArray *) RING_API_GETCPOINTER(1,"QJsonArray");
	pObject->pop_back();
}


RING_FUNC(ring_QJsonArray_pop_front)
{
	QJsonArray *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonArray *) RING_API_GETCPOINTER(1,"QJsonArray");
	pObject->pop_front();
}


RING_FUNC(ring_QJsonArray_prepend)
{
	QJsonArray *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonArray *) RING_API_GETCPOINTER(1,"QJsonArray");
	pObject->prepend(* (QJsonValue   *) RING_API_GETCPOINTER(2,"QJsonValue"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QJsonValue"));
}


RING_FUNC(ring_QJsonArray_push_back)
{
	QJsonArray *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonArray *) RING_API_GETCPOINTER(1,"QJsonArray");
	pObject->push_back(* (QJsonValue   *) RING_API_GETCPOINTER(2,"QJsonValue"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QJsonValue"));
}


RING_FUNC(ring_QJsonArray_push_front)
{
	QJsonArray *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonArray *) RING_API_GETCPOINTER(1,"QJsonArray");
	pObject->push_front(* (QJsonValue   *) RING_API_GETCPOINTER(2,"QJsonValue"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QJsonValue"));
}


RING_FUNC(ring_QJsonArray_removeAt)
{
	QJsonArray *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonArray *) RING_API_GETCPOINTER(1,"QJsonArray");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->removeAt( (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QJsonArray_removeFirst)
{
	QJsonArray *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonArray *) RING_API_GETCPOINTER(1,"QJsonArray");
	pObject->removeFirst();
}


RING_FUNC(ring_QJsonArray_removeLast)
{
	QJsonArray *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonArray *) RING_API_GETCPOINTER(1,"QJsonArray");
	pObject->removeLast();
}


RING_FUNC(ring_QJsonArray_replace)
{
	QJsonArray *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonArray *) RING_API_GETCPOINTER(1,"QJsonArray");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->replace( (int ) RING_API_GETNUMBER(2),* (QJsonValue   *) RING_API_GETCPOINTER(3,"QJsonValue"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"QJsonValue"));
}


RING_FUNC(ring_QJsonArray_size)
{
	QJsonArray *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonArray *) RING_API_GETCPOINTER(1,"QJsonArray");
	RING_API_RETNUMBER(pObject->size());
}


RING_FUNC(ring_QJsonArray_takeAt)
{
	QJsonArray *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonArray *) RING_API_GETCPOINTER(1,"QJsonArray");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QJsonValue *pValue ; 
		pValue = new QJsonValue() ;
		*pValue = pObject->takeAt( (int ) RING_API_GETNUMBER(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"QJsonValue",ring_QJsonValue_freefunc);
	}
}


RING_FUNC(ring_QJsonArray_toVariantList)
{
	QJsonArray *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonArray *) RING_API_GETCPOINTER(1,"QJsonArray");
	{
		QVariantList *pValue ; 
		pValue = (QVariantList *) RING_API_MALLOC(sizeof(QVariantList)) ;
		*pValue = pObject->toVariantList();
		RING_API_RETMANAGEDCPOINTER(pValue,"QVariantList",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QJsonArray_fromStringList)
{
	QJsonArray *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonArray *) RING_API_GETCPOINTER(1,"QJsonArray");
	{
		QJsonArray *pValue ; 
		pValue = new QJsonArray() ;
		*pValue = pObject->fromStringList(* (QStringList   *) RING_API_GETCPOINTER(2,"QStringList"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QStringList"));
		RING_API_RETMANAGEDCPOINTER(pValue,"QJsonArray",ring_QJsonArray_freefunc);
	}
}


RING_FUNC(ring_QJsonArray_fromVariantList)
{
	QJsonArray *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonArray *) RING_API_GETCPOINTER(1,"QJsonArray");
	{
		QJsonArray *pValue ; 
		pValue = new QJsonArray() ;
		*pValue = pObject->fromVariantList(* (QVariantList   *) RING_API_GETCPOINTER(2,"QVariantList"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QVariantList"));
		RING_API_RETMANAGEDCPOINTER(pValue,"QJsonArray",ring_QJsonArray_freefunc);
	}
}


RING_FUNC(ring_QJsonDocument_array)
{
	QJsonDocument *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonDocument *) RING_API_GETCPOINTER(1,"QJsonDocument");
	{
		QJsonArray *pValue ; 
		pValue = new QJsonArray() ;
		*pValue = pObject->array();
		RING_API_RETMANAGEDCPOINTER(pValue,"QJsonArray",ring_QJsonArray_freefunc);
	}
}


RING_FUNC(ring_QJsonDocument_isArray)
{
	QJsonDocument *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonDocument *) RING_API_GETCPOINTER(1,"QJsonDocument");
	RING_API_RETNUMBER(pObject->isArray());
}


RING_FUNC(ring_QJsonDocument_isEmpty)
{
	QJsonDocument *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonDocument *) RING_API_GETCPOINTER(1,"QJsonDocument");
	RING_API_RETNUMBER(pObject->isEmpty());
}


RING_FUNC(ring_QJsonDocument_isNull)
{
	QJsonDocument *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonDocument *) RING_API_GETCPOINTER(1,"QJsonDocument");
	RING_API_RETNUMBER(pObject->isNull());
}


RING_FUNC(ring_QJsonDocument_isObject)
{
	QJsonDocument *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonDocument *) RING_API_GETCPOINTER(1,"QJsonDocument");
	RING_API_RETNUMBER(pObject->isObject());
}


RING_FUNC(ring_QJsonDocument_object)
{
	QJsonDocument *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonDocument *) RING_API_GETCPOINTER(1,"QJsonDocument");
	{
		QJsonObject *pValue ; 
		pValue = new QJsonObject() ;
		*pValue = pObject->object();
		RING_API_RETMANAGEDCPOINTER(pValue,"QJsonObject",ring_QJsonObject_freefunc);
	}
}


RING_FUNC(ring_QJsonDocument_setArray)
{
	QJsonDocument *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonDocument *) RING_API_GETCPOINTER(1,"QJsonDocument");
	pObject->setArray(* (QJsonArray   *) RING_API_GETCPOINTER(2,"QJsonArray"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QJsonArray"));
}


RING_FUNC(ring_QJsonDocument_setObject)
{
	QJsonDocument *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonDocument *) RING_API_GETCPOINTER(1,"QJsonDocument");
	pObject->setObject(* (QJsonObject   *) RING_API_GETCPOINTER(2,"QJsonObject"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QJsonObject"));
}


RING_FUNC(ring_QJsonDocument_toJson)
{
	QJsonDocument *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonDocument *) RING_API_GETCPOINTER(1,"QJsonDocument");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QByteArray *pValue ; 
		pValue = new QByteArray() ;
		*pValue = pObject->toJson( (QJsonDocument::JsonFormat )  (int) RING_API_GETNUMBER(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"QByteArray",ring_QByteArray_freefunc);
	}
}


RING_FUNC(ring_QJsonDocument_toVariant)
{
	QJsonDocument *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonDocument *) RING_API_GETCPOINTER(1,"QJsonDocument");
	{
		QVariant *pValue ; 
		pValue = new QVariant() ;
		*pValue = pObject->toVariant();
		RING_API_RETMANAGEDCPOINTER(pValue,"QVariant",ring_QVariant_freefunc);
	}
}


RING_FUNC(ring_QJsonDocument_fromJson)
{
	QJsonDocument *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonDocument *) RING_API_GETCPOINTER(1,"QJsonDocument");
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QJsonDocument *pValue ; 
		pValue = new QJsonDocument() ;
		*pValue = pObject->fromJson(* (QByteArray   *) RING_API_GETCPOINTER(2,"QByteArray"),(QJsonParseError *) RING_API_GETCPOINTER(3,"QJsonParseError"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QByteArray"));
		RING_API_RETMANAGEDCPOINTER(pValue,"QJsonDocument",ring_QJsonDocument_freefunc);
	}
}


RING_FUNC(ring_QJsonDocument_fromVariant)
{
	QJsonDocument *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonDocument *) RING_API_GETCPOINTER(1,"QJsonDocument");
	{
		QJsonDocument *pValue ; 
		pValue = new QJsonDocument() ;
		*pValue = pObject->fromVariant(* (QVariant   *) RING_API_GETCPOINTER(2,"QVariant"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QVariant"));
		RING_API_RETMANAGEDCPOINTER(pValue,"QJsonDocument",ring_QJsonDocument_freefunc);
	}
}


RING_FUNC(ring_QJsonObject_contains)
{
	QJsonObject *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonObject *) RING_API_GETCPOINTER(1,"QJsonObject");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->contains(RING_API_GETSTRING(2)));
}


RING_FUNC(ring_QJsonObject_count)
{
	QJsonObject *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonObject *) RING_API_GETCPOINTER(1,"QJsonObject");
	RING_API_RETNUMBER(pObject->count());
}


RING_FUNC(ring_QJsonObject_empty)
{
	QJsonObject *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonObject *) RING_API_GETCPOINTER(1,"QJsonObject");
	RING_API_RETNUMBER(pObject->empty());
}


RING_FUNC(ring_QJsonObject_isEmpty)
{
	QJsonObject *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonObject *) RING_API_GETCPOINTER(1,"QJsonObject");
	RING_API_RETNUMBER(pObject->isEmpty());
}


RING_FUNC(ring_QJsonObject_keys)
{
	QJsonObject *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonObject *) RING_API_GETCPOINTER(1,"QJsonObject");
	{
		QStringList *pValue ; 
		pValue = new QStringList() ;
		*pValue = pObject->keys();
		RING_API_RETMANAGEDCPOINTER(pValue,"QStringList",ring_QStringList_freefunc);
	}
}


RING_FUNC(ring_QJsonObject_length)
{
	QJsonObject *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonObject *) RING_API_GETCPOINTER(1,"QJsonObject");
	RING_API_RETNUMBER(pObject->length());
}


RING_FUNC(ring_QJsonObject_remove)
{
	QJsonObject *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonObject *) RING_API_GETCPOINTER(1,"QJsonObject");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->remove(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QJsonObject_size)
{
	QJsonObject *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonObject *) RING_API_GETCPOINTER(1,"QJsonObject");
	RING_API_RETNUMBER(pObject->size());
}


RING_FUNC(ring_QJsonObject_take)
{
	QJsonObject *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonObject *) RING_API_GETCPOINTER(1,"QJsonObject");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QJsonValue *pValue ; 
		pValue = new QJsonValue() ;
		*pValue = pObject->take(RING_API_GETSTRING(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"QJsonValue",ring_QJsonValue_freefunc);
	}
}


RING_FUNC(ring_QJsonObject_toVariantMap)
{
	QJsonObject *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonObject *) RING_API_GETCPOINTER(1,"QJsonObject");
	{
		QVariantMap *pValue ; 
		pValue = (QVariantMap *) RING_API_MALLOC(sizeof(QVariantMap)) ;
		*pValue = pObject->toVariantMap();
		RING_API_RETMANAGEDCPOINTER(pValue,"QVariantMap",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QJsonObject_value)
{
	QJsonObject *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonObject *) RING_API_GETCPOINTER(1,"QJsonObject");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QJsonValue *pValue ; 
		pValue = new QJsonValue() ;
		*pValue = pObject->value(RING_API_GETSTRING(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"QJsonValue",ring_QJsonValue_freefunc);
	}
}


RING_FUNC(ring_QJsonObject_fromVariantMap)
{
	QJsonObject *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonObject *) RING_API_GETCPOINTER(1,"QJsonObject");
	{
		QJsonObject *pValue ; 
		pValue = new QJsonObject() ;
		*pValue = pObject->fromVariantMap(* (QVariantMap   *) RING_API_GETCPOINTER(2,"QVariantMap"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QVariantMap"));
		RING_API_RETMANAGEDCPOINTER(pValue,"QJsonObject",ring_QJsonObject_freefunc);
	}
}


RING_FUNC(ring_QJsonParseError_errorString)
{
	QJsonParseError *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonParseError *) RING_API_GETCPOINTER(1,"QJsonParseError");
	RING_API_RETSTRING(pObject->errorString().toStdString().c_str());
}


RING_FUNC(ring_QJsonValue_isArray)
{
	QJsonValue *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonValue *) RING_API_GETCPOINTER(1,"QJsonValue");
	RING_API_RETNUMBER(pObject->isArray());
}


RING_FUNC(ring_QJsonValue_isBool)
{
	QJsonValue *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonValue *) RING_API_GETCPOINTER(1,"QJsonValue");
	RING_API_RETNUMBER(pObject->isBool());
}


RING_FUNC(ring_QJsonValue_isDouble)
{
	QJsonValue *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonValue *) RING_API_GETCPOINTER(1,"QJsonValue");
	RING_API_RETNUMBER(pObject->isDouble());
}


RING_FUNC(ring_QJsonValue_isNull)
{
	QJsonValue *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonValue *) RING_API_GETCPOINTER(1,"QJsonValue");
	RING_API_RETNUMBER(pObject->isNull());
}


RING_FUNC(ring_QJsonValue_isObject)
{
	QJsonValue *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonValue *) RING_API_GETCPOINTER(1,"QJsonValue");
	RING_API_RETNUMBER(pObject->isObject());
}


RING_FUNC(ring_QJsonValue_isString)
{
	QJsonValue *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonValue *) RING_API_GETCPOINTER(1,"QJsonValue");
	RING_API_RETNUMBER(pObject->isString());
}


RING_FUNC(ring_QJsonValue_isUndefined)
{
	QJsonValue *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonValue *) RING_API_GETCPOINTER(1,"QJsonValue");
	RING_API_RETNUMBER(pObject->isUndefined());
}


RING_FUNC(ring_QJsonValue_toArray)
{
	QJsonValue *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonValue *) RING_API_GETCPOINTER(1,"QJsonValue");
	{
		QJsonArray *pValue ; 
		pValue = new QJsonArray() ;
		*pValue = pObject->toArray(* (QJsonArray   *) RING_API_GETCPOINTER(2,"QJsonArray"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QJsonArray"));
		RING_API_RETMANAGEDCPOINTER(pValue,"QJsonArray",ring_QJsonArray_freefunc);
	}
}


RING_FUNC(ring_QJsonValue_toArray_2)
{
	QJsonValue *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonValue *) RING_API_GETCPOINTER(1,"QJsonValue");
	{
		QJsonArray *pValue ; 
		pValue = new QJsonArray() ;
		*pValue = pObject->toArray();
		RING_API_RETMANAGEDCPOINTER(pValue,"QJsonArray",ring_QJsonArray_freefunc);
	}
}


RING_FUNC(ring_QJsonValue_toBool)
{
	QJsonValue *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonValue *) RING_API_GETCPOINTER(1,"QJsonValue");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->toBool( (bool ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QJsonValue_toDouble)
{
	QJsonValue *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonValue *) RING_API_GETCPOINTER(1,"QJsonValue");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->toDouble( (double ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QJsonValue_toInt)
{
	QJsonValue *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonValue *) RING_API_GETCPOINTER(1,"QJsonValue");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->toInt( (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QJsonValue_toObject)
{
	QJsonValue *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonValue *) RING_API_GETCPOINTER(1,"QJsonValue");
	{
		QJsonObject *pValue ; 
		pValue = new QJsonObject() ;
		*pValue = pObject->toObject(* (QJsonObject   *) RING_API_GETCPOINTER(2,"QJsonObject"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QJsonObject"));
		RING_API_RETMANAGEDCPOINTER(pValue,"QJsonObject",ring_QJsonObject_freefunc);
	}
}


RING_FUNC(ring_QJsonValue_toObject_2)
{
	QJsonValue *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonValue *) RING_API_GETCPOINTER(1,"QJsonValue");
	{
		QJsonObject *pValue ; 
		pValue = new QJsonObject() ;
		*pValue = pObject->toObject();
		RING_API_RETMANAGEDCPOINTER(pValue,"QJsonObject",ring_QJsonObject_freefunc);
	}
}


RING_FUNC(ring_QJsonValue_toString)
{
	QJsonValue *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonValue *) RING_API_GETCPOINTER(1,"QJsonValue");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->toString(RING_API_GETSTRING(2)).toStdString().c_str());
}


RING_FUNC(ring_QJsonValue_toVariant)
{
	QJsonValue *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonValue *) RING_API_GETCPOINTER(1,"QJsonValue");
	{
		QVariant *pValue ; 
		pValue = new QVariant() ;
		*pValue = pObject->toVariant();
		RING_API_RETMANAGEDCPOINTER(pValue,"QVariant",ring_QVariant_freefunc);
	}
}


RING_FUNC(ring_QJsonValue_type)
{
	QJsonValue *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonValue *) RING_API_GETCPOINTER(1,"QJsonValue");
	{
		QJsonValue::Type *pValue ; 
		pValue = (QJsonValue::Type *) RING_API_MALLOC(sizeof(QJsonValue::Type)) ;
		*pValue = pObject->type();
		RING_API_RETMANAGEDCPOINTER(pValue,"QJsonValue::Type",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QJsonValue_fromVariant)
{
	QJsonValue *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonValue *) RING_API_GETCPOINTER(1,"QJsonValue");
	{
		QJsonValue *pValue ; 
		pValue = new QJsonValue() ;
		*pValue = pObject->fromVariant(* (QVariant   *) RING_API_GETCPOINTER(2,"QVariant"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QVariant"));
		RING_API_RETMANAGEDCPOINTER(pValue,"QJsonValue",ring_QJsonValue_freefunc);
	}
}


RING_FUNC(ring_QString2_split)
{
	QString *pObject ;
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QString *) RING_API_GETCPOINTER(1,"QString2");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QStringList *pValue ; 
		pValue = new QStringList() ;
		*pValue = pObject->split(RING_API_GETSTRING(2), (Qt::SplitBehavior )  (int) RING_API_GETNUMBER(3), (Qt::CaseSensitivity )  (int) RING_API_GETNUMBER(4));
		RING_API_RETMANAGEDCPOINTER(pValue,"QStringList",ring_QStringList_freefunc);
	}
}


RING_FUNC(ring_QString2_split_2)
{
	QString *pObject ;
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QString *) RING_API_GETCPOINTER(1,"QString2");
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QStringList *pValue ; 
		pValue = new QStringList() ;
		*pValue = pObject->split(* (QChar  *) RING_API_GETCPOINTER(2,"QChar"), (Qt::SplitBehavior )  (int) RING_API_GETNUMBER(3), (Qt::CaseSensitivity )  (int) RING_API_GETNUMBER(4));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QChar"));
		RING_API_RETMANAGEDCPOINTER(pValue,"QStringList",ring_QStringList_freefunc);
	}
}


RING_FUNC(ring_QString2_split_4)
{
	QString *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QString *) RING_API_GETCPOINTER(1,"QString2");
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QStringList *pValue ; 
		pValue = new QStringList() ;
		*pValue = pObject->split(* (QRegularExpression   *) RING_API_GETCPOINTER(2,"QRegularExpression"), (Qt::SplitBehavior )  (int) RING_API_GETNUMBER(3));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QRegularExpression"));
		RING_API_RETMANAGEDCPOINTER(pValue,"QStringList",ring_QStringList_freefunc);
	}
}


RING_FUNC(ring_QString2_append)
{
	QString *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QString *) RING_API_GETCPOINTER(1,"QString2");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->append(RING_API_GETSTRING(2)).toStdString().c_str());
}


RING_FUNC(ring_QString2_append_2)
{
	QString *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QString *) RING_API_GETCPOINTER(1,"QString2");
	RING_API_RETSTRING(pObject->append(* (QChar  *) RING_API_GETCPOINTER(2,"QChar")).toStdString().c_str());
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QChar"));
}


RING_FUNC(ring_QString2_toUtf8)
{
	QString *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QString *) RING_API_GETCPOINTER(1,"QString2");
	{
		QByteArray *pValue ; 
		pValue = new QByteArray() ;
		*pValue = pObject->toUtf8();
		RING_API_RETMANAGEDCPOINTER(pValue,"QByteArray",ring_QByteArray_freefunc);
	}
}


RING_FUNC(ring_QString2_toLatin1)
{
	QString *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QString *) RING_API_GETCPOINTER(1,"QString2");
	{
		QByteArray *pValue ; 
		pValue = new QByteArray() ;
		*pValue = pObject->toLatin1();
		RING_API_RETMANAGEDCPOINTER(pValue,"QByteArray",ring_QByteArray_freefunc);
	}
}


RING_FUNC(ring_QString2_toLocal8Bit)
{
	QString *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QString *) RING_API_GETCPOINTER(1,"QString2");
	{
		QByteArray *pValue ; 
		pValue = new QByteArray() ;
		*pValue = pObject->toLocal8Bit();
		RING_API_RETMANAGEDCPOINTER(pValue,"QByteArray",ring_QByteArray_freefunc);
	}
}


RING_FUNC(ring_QString2_unicode)
{
	QString *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QString *) RING_API_GETCPOINTER(1,"QString2");
	RING_API_RETCPOINTER(pObject->unicode(),"QChar");
}


RING_FUNC(ring_QString2_number)
{
	QString *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QString *) RING_API_GETCPOINTER(1,"QString2");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->number( (ulong ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3)).toStdString().c_str());
}


RING_FUNC(ring_QString2_count)
{
	QString *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QString *) RING_API_GETCPOINTER(1,"QString2");
	RING_API_RETNUMBER(pObject->count());
}


RING_FUNC(ring_QString2_left)
{
	QString *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QString *) RING_API_GETCPOINTER(1,"QString2");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->left( (int ) RING_API_GETNUMBER(2)).toStdString().c_str());
}


RING_FUNC(ring_QString2_mid)
{
	QString *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QString *) RING_API_GETCPOINTER(1,"QString2");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->mid( (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3)).toStdString().c_str());
}


RING_FUNC(ring_QString2_right)
{
	QString *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QString *) RING_API_GETCPOINTER(1,"QString2");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->right( (int ) RING_API_GETNUMBER(2)).toStdString().c_str());
}


RING_FUNC(ring_QString2_compare)
{
	QString *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QString *) RING_API_GETCPOINTER(1,"QString2");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->compare(RING_API_GETSTRING(2), (Qt::CaseSensitivity )  (int) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_QString2_contains)
{
	QString *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QString *) RING_API_GETCPOINTER(1,"QString2");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->contains(RING_API_GETSTRING(2), (Qt::CaseSensitivity )  (int) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_QString2_indexOf)
{
	QString *pObject ;
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QString *) RING_API_GETCPOINTER(1,"QString2");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->indexOf(RING_API_GETSTRING(2), (int ) RING_API_GETNUMBER(3), (Qt::CaseSensitivity )  (int) RING_API_GETNUMBER(4)));
}


RING_FUNC(ring_QString2_lastIndexOf)
{
	QString *pObject ;
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QString *) RING_API_GETCPOINTER(1,"QString2");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->lastIndexOf(RING_API_GETSTRING(2), (int ) RING_API_GETNUMBER(3), (Qt::CaseSensitivity )  (int) RING_API_GETNUMBER(4)));
}


RING_FUNC(ring_QString2_insert)
{
	QString *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QString *) RING_API_GETCPOINTER(1,"QString2");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->insert( (int ) RING_API_GETNUMBER(2),RING_API_GETSTRING(3)).toStdString().c_str());
}


RING_FUNC(ring_QString2_isRightToLeft)
{
	QString *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QString *) RING_API_GETCPOINTER(1,"QString2");
	RING_API_RETNUMBER(pObject->isRightToLeft());
}


RING_FUNC(ring_QString2_repeated)
{
	QString *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QString *) RING_API_GETCPOINTER(1,"QString2");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->repeated( (int ) RING_API_GETNUMBER(2)).toStdString().c_str());
}


RING_FUNC(ring_QString2_replace)
{
	QString *pObject ;
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QString *) RING_API_GETCPOINTER(1,"QString2");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->replace( (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3),RING_API_GETSTRING(4)).toStdString().c_str());
}


RING_FUNC(ring_QString2_replace_2)
{
	QString *pObject ;
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QString *) RING_API_GETCPOINTER(1,"QString2");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->replace(RING_API_GETSTRING(2),RING_API_GETSTRING(3), (Qt::CaseSensitivity)  (int) RING_API_GETNUMBER(4)).toStdString().c_str());
}


RING_FUNC(ring_QString2_startsWith)
{
	QString *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QString *) RING_API_GETCPOINTER(1,"QString2");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->startsWith(RING_API_GETSTRING(2), (Qt::CaseSensitivity )  (int) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_QString2_endsWith)
{
	QString *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QString *) RING_API_GETCPOINTER(1,"QString2");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->endsWith(RING_API_GETSTRING(2), (Qt::CaseSensitivity )  (int) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_QString2_toHtmlEscaped)
{
	QString *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QString *) RING_API_GETCPOINTER(1,"QString2");
	RING_API_RETSTRING(pObject->toHtmlEscaped().toStdString().c_str());
}


RING_FUNC(ring_QString2_clear)
{
	QString *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QString *) RING_API_GETCPOINTER(1,"QString2");
	pObject->clear();
}


RING_FUNC(ring_QString2_isNull)
{
	QString *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QString *) RING_API_GETCPOINTER(1,"QString2");
	RING_API_RETNUMBER(pObject->isNull());
}


RING_FUNC(ring_QString2_resize)
{
	QString *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QString *) RING_API_GETCPOINTER(1,"QString2");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->resize( (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QString2_fill)
{
	QString *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QString *) RING_API_GETCPOINTER(1,"QString2");
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->fill(* (QChar  *) RING_API_GETCPOINTER(2,"QChar"), (int ) RING_API_GETNUMBER(3)).toStdString().c_str());
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QChar"));
}


RING_FUNC(ring_QString2_localeAwareCompare)
{
	QString *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QString *) RING_API_GETCPOINTER(1,"QString2");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->localeAwareCompare(RING_API_GETSTRING(2)));
}


RING_FUNC(ring_QString2_leftJustified)
{
	QString *pObject ;
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QString *) RING_API_GETCPOINTER(1,"QString2");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->leftJustified( (int ) RING_API_GETNUMBER(2),* (QChar  *) RING_API_GETCPOINTER(3,"QChar"), (bool ) RING_API_GETNUMBER(4)).toStdString().c_str());
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"QChar"));
}


RING_FUNC(ring_QString2_rightJustified)
{
	QString *pObject ;
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QString *) RING_API_GETCPOINTER(1,"QString2");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->rightJustified( (int ) RING_API_GETNUMBER(2),* (QChar  *) RING_API_GETCPOINTER(3,"QChar"), (bool ) RING_API_GETNUMBER(4)).toStdString().c_str());
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"QChar"));
}


RING_FUNC(ring_QString2_section_1)
{
	QString *pObject ;
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QString *) RING_API_GETCPOINTER(1,"QString2");
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->section(* (QChar  *) RING_API_GETCPOINTER(2,"QChar"), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4),* (QString::SectionFlags  *) RING_API_GETCPOINTER(5,"QString::SectionFlags")).toStdString().c_str());
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QChar"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		RING_API_FREE(RING_API_GETCPOINTER(5,"QString::SectionFlags"));
}


RING_FUNC(ring_QString2_section_2)
{
	QString *pObject ;
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QString *) RING_API_GETCPOINTER(1,"QString2");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->section(RING_API_GETSTRING(2), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4),* (QString::SectionFlags  *) RING_API_GETCPOINTER(5,"QString::SectionFlags")).toStdString().c_str());
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		RING_API_FREE(RING_API_GETCPOINTER(5,"QString::SectionFlags"));
}


RING_FUNC(ring_QString2_section_4)
{
	QString *pObject ;
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QString *) RING_API_GETCPOINTER(1,"QString2");
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->section(* (QRegularExpression  *) RING_API_GETCPOINTER(2,"QRegularExpression"), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4),* (QString::SectionFlags  *) RING_API_GETCPOINTER(5,"QString::SectionFlags")).toStdString().c_str());
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QRegularExpression"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		RING_API_FREE(RING_API_GETCPOINTER(5,"QString::SectionFlags"));
}


RING_FUNC(ring_QString2_simplified)
{
	QString *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QString *) RING_API_GETCPOINTER(1,"QString2");
	RING_API_RETSTRING(pObject->simplified().toStdString().c_str());
}


RING_FUNC(ring_QString2_toCaseFolded)
{
	QString *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QString *) RING_API_GETCPOINTER(1,"QString2");
	RING_API_RETSTRING(pObject->toCaseFolded().toStdString().c_str());
}


RING_FUNC(ring_QString2_trimmed)
{
	QString *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QString *) RING_API_GETCPOINTER(1,"QString2");
	RING_API_RETSTRING(pObject->trimmed().toStdString().c_str());
}


RING_FUNC(ring_QString2_truncate)
{
	QString *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QString *) RING_API_GETCPOINTER(1,"QString2");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->truncate( (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QString2_length)
{
	QString *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QString *) RING_API_GETCPOINTER(1,"QString2");
	RING_API_RETNUMBER(pObject->length());
}


RING_FUNC(ring_QString2_size)
{
	QString *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QString *) RING_API_GETCPOINTER(1,"QString2");
	RING_API_RETNUMBER(pObject->size());
}


RING_FUNC(ring_QBuffer_buffer)
{
	QBuffer *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QBuffer *) RING_API_GETCPOINTER(1,"QBuffer");
	{
		QByteArray *pValue ; 
		pValue = new QByteArray() ;
		*pValue = pObject->buffer();
		RING_API_RETMANAGEDCPOINTER(pValue,"QByteArray",ring_QByteArray_freefunc);
	}
}


RING_FUNC(ring_QBuffer_data)
{
	QBuffer *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QBuffer *) RING_API_GETCPOINTER(1,"QBuffer");
	{
		QByteArray *pValue ; 
		pValue = new QByteArray() ;
		*pValue = pObject->data();
		RING_API_RETMANAGEDCPOINTER(pValue,"QByteArray",ring_QByteArray_freefunc);
	}
}


RING_FUNC(ring_QBuffer_setBuffer)
{
	QBuffer *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QBuffer *) RING_API_GETCPOINTER(1,"QBuffer");
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setBuffer((QByteArray *) RING_API_GETCPOINTER(2,"QByteArray"));
}


RING_FUNC(ring_QBuffer_setData)
{
	QBuffer *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QBuffer *) RING_API_GETCPOINTER(1,"QBuffer");
	pObject->setData(* (QByteArray  *) RING_API_GETCPOINTER(2,"QByteArray"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QByteArray"));
}


RING_FUNC(ring_QBuffer_setData_2)
{
	QBuffer *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QBuffer *) RING_API_GETCPOINTER(1,"QBuffer");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setData(RING_API_GETSTRING(2), (int ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_QDateTime_addDays)
{
	QDateTime *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDateTime *) RING_API_GETCPOINTER(1,"QDateTime");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QDateTime *pValue ; 
		pValue = new QDateTime() ;
		*pValue = pObject->addDays( (int ) RING_API_GETNUMBER(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"QDateTime",ring_QDateTime_freefunc);
	}
}


RING_FUNC(ring_QDateTime_addMSecs)
{
	QDateTime *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDateTime *) RING_API_GETCPOINTER(1,"QDateTime");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QDateTime *pValue ; 
		pValue = new QDateTime() ;
		*pValue = pObject->addMSecs( (qint64 ) RING_API_GETNUMBER(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"QDateTime",ring_QDateTime_freefunc);
	}
}


RING_FUNC(ring_QDateTime_addMonths)
{
	QDateTime *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDateTime *) RING_API_GETCPOINTER(1,"QDateTime");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QDateTime *pValue ; 
		pValue = new QDateTime() ;
		*pValue = pObject->addMonths( (int ) RING_API_GETNUMBER(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"QDateTime",ring_QDateTime_freefunc);
	}
}


RING_FUNC(ring_QDateTime_addSecs)
{
	QDateTime *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDateTime *) RING_API_GETCPOINTER(1,"QDateTime");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QDateTime *pValue ; 
		pValue = new QDateTime() ;
		*pValue = pObject->addSecs( (int ) RING_API_GETNUMBER(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"QDateTime",ring_QDateTime_freefunc);
	}
}


RING_FUNC(ring_QDateTime_addYears)
{
	QDateTime *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDateTime *) RING_API_GETCPOINTER(1,"QDateTime");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QDateTime *pValue ; 
		pValue = new QDateTime() ;
		*pValue = pObject->addYears( (int ) RING_API_GETNUMBER(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"QDateTime",ring_QDateTime_freefunc);
	}
}


RING_FUNC(ring_QDateTime_date)
{
	QDateTime *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDateTime *) RING_API_GETCPOINTER(1,"QDateTime");
	{
		QDate *pValue ; 
		pValue = new QDate() ;
		*pValue = pObject->date();
		RING_API_RETMANAGEDCPOINTER(pValue,"QDate",ring_QDate_freefunc);
	}
}


RING_FUNC(ring_QDateTime_daysTo)
{
	QDateTime *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDateTime *) RING_API_GETCPOINTER(1,"QDateTime");
	RING_API_RETNUMBER(pObject->daysTo(* (QDateTime  *) RING_API_GETCPOINTER(2,"QDateTime")));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QDateTime"));
}


RING_FUNC(ring_QDateTime_isNull)
{
	QDateTime *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDateTime *) RING_API_GETCPOINTER(1,"QDateTime");
	RING_API_RETNUMBER(pObject->isNull());
}


RING_FUNC(ring_QDateTime_isValid)
{
	QDateTime *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDateTime *) RING_API_GETCPOINTER(1,"QDateTime");
	RING_API_RETNUMBER(pObject->isValid());
}


RING_FUNC(ring_QDateTime_msecsTo)
{
	QDateTime *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDateTime *) RING_API_GETCPOINTER(1,"QDateTime");
	RING_API_RETNUMBER(pObject->msecsTo(* (QDateTime  *) RING_API_GETCPOINTER(2,"QDateTime")));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QDateTime"));
}


RING_FUNC(ring_QDateTime_secsTo)
{
	QDateTime *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDateTime *) RING_API_GETCPOINTER(1,"QDateTime");
	RING_API_RETNUMBER(pObject->secsTo(* (QDateTime  *) RING_API_GETCPOINTER(2,"QDateTime")));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QDateTime"));
}


RING_FUNC(ring_QDateTime_setDate)
{
	QDateTime *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDateTime *) RING_API_GETCPOINTER(1,"QDateTime");
	pObject->setDate(* (QDate  *) RING_API_GETCPOINTER(2,"QDate"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QDate"));
}


RING_FUNC(ring_QDateTime_setMSecsSinceEpoch)
{
	QDateTime *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDateTime *) RING_API_GETCPOINTER(1,"QDateTime");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setMSecsSinceEpoch( (qint64 ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QDateTime_setTime)
{
	QDateTime *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDateTime *) RING_API_GETCPOINTER(1,"QDateTime");
	pObject->setTime(* (QTime  *) RING_API_GETCPOINTER(2,"QTime"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QTime"));
}


RING_FUNC(ring_QDateTime_setTimeSpec)
{
	QDateTime *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDateTime *) RING_API_GETCPOINTER(1,"QDateTime");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setTimeSpec( (Qt::TimeSpec )  (int) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QDateTime_time)
{
	QDateTime *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDateTime *) RING_API_GETCPOINTER(1,"QDateTime");
	{
		QTime *pValue ; 
		pValue = new QTime() ;
		*pValue = pObject->time();
		RING_API_RETMANAGEDCPOINTER(pValue,"QTime",ring_QTime_freefunc);
	}
}


RING_FUNC(ring_QDateTime_timeSpec)
{
	QDateTime *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDateTime *) RING_API_GETCPOINTER(1,"QDateTime");
	RING_API_RETNUMBER(pObject->timeSpec());
}


RING_FUNC(ring_QDateTime_toLocalTime)
{
	QDateTime *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDateTime *) RING_API_GETCPOINTER(1,"QDateTime");
	{
		QDateTime *pValue ; 
		pValue = new QDateTime() ;
		*pValue = pObject->toLocalTime();
		RING_API_RETMANAGEDCPOINTER(pValue,"QDateTime",ring_QDateTime_freefunc);
	}
}


RING_FUNC(ring_QDateTime_toMSecsSinceEpoch)
{
	QDateTime *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDateTime *) RING_API_GETCPOINTER(1,"QDateTime");
	RING_API_RETNUMBER(pObject->toMSecsSinceEpoch());
}


RING_FUNC(ring_QDateTime_toString)
{
	QDateTime *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDateTime *) RING_API_GETCPOINTER(1,"QDateTime");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->toString(RING_API_GETSTRING(2)).toStdString().c_str());
}


RING_FUNC(ring_QDateTime_toString_2)
{
	QDateTime *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDateTime *) RING_API_GETCPOINTER(1,"QDateTime");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->toString( (Qt::DateFormat )  (int) RING_API_GETNUMBER(2)).toStdString().c_str());
}


RING_FUNC(ring_QDateTime_toTimeSpec)
{
	QDateTime *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDateTime *) RING_API_GETCPOINTER(1,"QDateTime");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QDateTime *pValue ; 
		pValue = new QDateTime() ;
		*pValue = pObject->toTimeSpec( (Qt::TimeSpec )  (int) RING_API_GETNUMBER(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"QDateTime",ring_QDateTime_freefunc);
	}
}


RING_FUNC(ring_QDateTime_toUTC)
{
	QDateTime *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDateTime *) RING_API_GETCPOINTER(1,"QDateTime");
	{
		QDateTime *pValue ; 
		pValue = new QDateTime() ;
		*pValue = pObject->toUTC();
		RING_API_RETMANAGEDCPOINTER(pValue,"QDateTime",ring_QDateTime_freefunc);
	}
}


RING_FUNC(ring_QDateTime_currentDateTime)
{
	QDateTime *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDateTime *) RING_API_GETCPOINTER(1,"QDateTime");
	{
		QDateTime *pValue ; 
		pValue = new QDateTime() ;
		*pValue = pObject->currentDateTime();
		RING_API_RETMANAGEDCPOINTER(pValue,"QDateTime",ring_QDateTime_freefunc);
	}
}


RING_FUNC(ring_QDateTime_currentDateTimeUtc)
{
	QDateTime *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDateTime *) RING_API_GETCPOINTER(1,"QDateTime");
	{
		QDateTime *pValue ; 
		pValue = new QDateTime() ;
		*pValue = pObject->currentDateTimeUtc();
		RING_API_RETMANAGEDCPOINTER(pValue,"QDateTime",ring_QDateTime_freefunc);
	}
}


RING_FUNC(ring_QDateTime_currentMSecsSinceEpoch)
{
	QDateTime *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDateTime *) RING_API_GETCPOINTER(1,"QDateTime");
	RING_API_RETNUMBER(pObject->currentMSecsSinceEpoch());
}


RING_FUNC(ring_QDateTime_fromMSecsSinceEpoch)
{
	QDateTime *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDateTime *) RING_API_GETCPOINTER(1,"QDateTime");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QDateTime *pValue ; 
		pValue = new QDateTime() ;
		*pValue = pObject->fromMSecsSinceEpoch( (qint64 ) RING_API_GETNUMBER(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"QDateTime",ring_QDateTime_freefunc);
	}
}


RING_FUNC(ring_QDateTime_fromString)
{
	QDateTime *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDateTime *) RING_API_GETCPOINTER(1,"QDateTime");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QDateTime *pValue ; 
		pValue = new QDateTime() ;
		*pValue = pObject->fromString(RING_API_GETSTRING(2), (Qt::DateFormat )  (int) RING_API_GETNUMBER(3));
		RING_API_RETMANAGEDCPOINTER(pValue,"QDateTime",ring_QDateTime_freefunc);
	}
}


RING_FUNC(ring_QDateTime_fromString_2)
{
	QDateTime *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDateTime *) RING_API_GETCPOINTER(1,"QDateTime");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QDateTime *pValue ; 
		pValue = new QDateTime() ;
		*pValue = pObject->fromString(RING_API_GETSTRING(2),RING_API_GETSTRING(3));
		RING_API_RETMANAGEDCPOINTER(pValue,"QDateTime",ring_QDateTime_freefunc);
	}
}


RING_FUNC(ring_QCoreApplication_installNativeEventFilter)
{
	QCoreApplication *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QCoreApplication *) RING_API_GETCPOINTER(1,"QCoreApplication");
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->installNativeEventFilter((QAbstractNativeEventFilter *) RING_API_GETCPOINTER(2,"QAbstractNativeEventFilter"));
}


RING_FUNC(ring_QCoreApplication_removeNativeEventFilter)
{
	QCoreApplication *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QCoreApplication *) RING_API_GETCPOINTER(1,"QCoreApplication");
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->removeNativeEventFilter((QAbstractNativeEventFilter *) RING_API_GETCPOINTER(2,"QAbstractNativeEventFilter"));
}


RING_FUNC(ring_QCoreApplication_quit)
{
	QCoreApplication *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QCoreApplication *) RING_API_GETCPOINTER(1,"QCoreApplication");
	pObject->quit();
}


RING_FUNC(ring_QCoreApplication_addLibraryPath)
{
	QCoreApplication *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QCoreApplication *) RING_API_GETCPOINTER(1,"QCoreApplication");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->addLibraryPath(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QCoreApplication_applicationDirPath)
{
	QCoreApplication *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QCoreApplication *) RING_API_GETCPOINTER(1,"QCoreApplication");
	RING_API_RETSTRING(pObject->applicationDirPath().toStdString().c_str());
}


RING_FUNC(ring_QCoreApplication_applicationFilePath)
{
	QCoreApplication *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QCoreApplication *) RING_API_GETCPOINTER(1,"QCoreApplication");
	RING_API_RETSTRING(pObject->applicationFilePath().toStdString().c_str());
}


RING_FUNC(ring_QCoreApplication_applicationName)
{
	QCoreApplication *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QCoreApplication *) RING_API_GETCPOINTER(1,"QCoreApplication");
	RING_API_RETSTRING(pObject->applicationName().toStdString().c_str());
}


RING_FUNC(ring_QCoreApplication_applicationPid)
{
	QCoreApplication *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QCoreApplication *) RING_API_GETCPOINTER(1,"QCoreApplication");
	RING_API_RETNUMBER(pObject->applicationPid());
}


RING_FUNC(ring_QCoreApplication_applicationVersion)
{
	QCoreApplication *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QCoreApplication *) RING_API_GETCPOINTER(1,"QCoreApplication");
	RING_API_RETSTRING(pObject->applicationVersion().toStdString().c_str());
}


RING_FUNC(ring_QCoreApplication_arguments)
{
	QCoreApplication *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QCoreApplication *) RING_API_GETCPOINTER(1,"QCoreApplication");
	{
		QStringList *pValue ; 
		pValue = new QStringList() ;
		*pValue = pObject->arguments();
		RING_API_RETMANAGEDCPOINTER(pValue,"QStringList",ring_QStringList_freefunc);
	}
}


RING_FUNC(ring_QCoreApplication_closingDown)
{
	QCoreApplication *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QCoreApplication *) RING_API_GETCPOINTER(1,"QCoreApplication");
	RING_API_RETNUMBER(pObject->closingDown());
}


RING_FUNC(ring_QCoreApplication_eventDispatcher)
{
	QCoreApplication *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QCoreApplication *) RING_API_GETCPOINTER(1,"QCoreApplication");
	RING_API_RETCPOINTER(pObject->eventDispatcher(),"QAbstractEventDispatcher");
}


RING_FUNC(ring_QCoreApplication_exec)
{
	QCoreApplication *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QCoreApplication *) RING_API_GETCPOINTER(1,"QCoreApplication");
	RING_API_RETNUMBER(pObject->exec());
}


RING_FUNC(ring_QCoreApplication_exit)
{
	QCoreApplication *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QCoreApplication *) RING_API_GETCPOINTER(1,"QCoreApplication");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->exit( (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QCoreApplication_installTranslator)
{
	QCoreApplication *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QCoreApplication *) RING_API_GETCPOINTER(1,"QCoreApplication");
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->installTranslator((QTranslator *) RING_API_GETCPOINTER(2,"QTranslator")));
}


RING_FUNC(ring_QCoreApplication_instance)
{
	QCoreApplication *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QCoreApplication *) RING_API_GETCPOINTER(1,"QCoreApplication");
	RING_API_RETCPOINTER(pObject->instance(),"QCoreApplication");
}


RING_FUNC(ring_QCoreApplication_isQuitLockEnabled)
{
	QCoreApplication *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QCoreApplication *) RING_API_GETCPOINTER(1,"QCoreApplication");
	RING_API_RETNUMBER(pObject->isQuitLockEnabled());
}


RING_FUNC(ring_QCoreApplication_libraryPaths)
{
	QCoreApplication *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QCoreApplication *) RING_API_GETCPOINTER(1,"QCoreApplication");
	{
		QStringList *pValue ; 
		pValue = new QStringList() ;
		*pValue = pObject->libraryPaths();
		RING_API_RETMANAGEDCPOINTER(pValue,"QStringList",ring_QStringList_freefunc);
	}
}


RING_FUNC(ring_QCoreApplication_organizationDomain)
{
	QCoreApplication *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QCoreApplication *) RING_API_GETCPOINTER(1,"QCoreApplication");
	RING_API_RETSTRING(pObject->organizationDomain().toStdString().c_str());
}


RING_FUNC(ring_QCoreApplication_organizationName)
{
	QCoreApplication *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QCoreApplication *) RING_API_GETCPOINTER(1,"QCoreApplication");
	RING_API_RETSTRING(pObject->organizationName().toStdString().c_str());
}


RING_FUNC(ring_QCoreApplication_postEvent)
{
	QCoreApplication *pObject ;
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QCoreApplication *) RING_API_GETCPOINTER(1,"QCoreApplication");
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->postEvent((QObject *) RING_API_GETCPOINTER(2,"QObject"),(QEvent *) RING_API_GETCPOINTER(3,"QEvent"), (int ) RING_API_GETNUMBER(4));
}


RING_FUNC(ring_QCoreApplication_processEvents)
{
	QCoreApplication *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QCoreApplication *) RING_API_GETCPOINTER(1,"QCoreApplication");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->processEvents( (QEventLoop::ProcessEventsFlags )  (int) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QCoreApplication_processEvents_2)
{
	QCoreApplication *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QCoreApplication *) RING_API_GETCPOINTER(1,"QCoreApplication");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->processEvents( (QEventLoop::ProcessEventsFlags )  (int) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_QCoreApplication_removeLibraryPath)
{
	QCoreApplication *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QCoreApplication *) RING_API_GETCPOINTER(1,"QCoreApplication");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->removeLibraryPath(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QCoreApplication_removePostedEvents)
{
	QCoreApplication *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QCoreApplication *) RING_API_GETCPOINTER(1,"QCoreApplication");
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->removePostedEvents((QObject *) RING_API_GETCPOINTER(2,"QObject"), (int ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_QCoreApplication_removeTranslator)
{
	QCoreApplication *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QCoreApplication *) RING_API_GETCPOINTER(1,"QCoreApplication");
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->removeTranslator((QTranslator *) RING_API_GETCPOINTER(2,"QTranslator")));
}


RING_FUNC(ring_QCoreApplication_sendEvent)
{
	QCoreApplication *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QCoreApplication *) RING_API_GETCPOINTER(1,"QCoreApplication");
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->sendEvent((QObject *) RING_API_GETCPOINTER(2,"QObject"),(QEvent *) RING_API_GETCPOINTER(3,"QEvent")));
}


RING_FUNC(ring_QCoreApplication_sendPostedEvents)
{
	QCoreApplication *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QCoreApplication *) RING_API_GETCPOINTER(1,"QCoreApplication");
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->sendPostedEvents((QObject *) RING_API_GETCPOINTER(2,"QObject"), (int ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_QCoreApplication_setApplicationName)
{
	QCoreApplication *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QCoreApplication *) RING_API_GETCPOINTER(1,"QCoreApplication");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setApplicationName(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QCoreApplication_setApplicationVersion)
{
	QCoreApplication *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QCoreApplication *) RING_API_GETCPOINTER(1,"QCoreApplication");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setApplicationVersion(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QCoreApplication_setAttribute)
{
	QCoreApplication *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QCoreApplication *) RING_API_GETCPOINTER(1,"QCoreApplication");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setAttribute( (Qt::ApplicationAttribute )  (int) RING_API_GETNUMBER(2), (bool ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_QCoreApplication_setEventDispatcher)
{
	QCoreApplication *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QCoreApplication *) RING_API_GETCPOINTER(1,"QCoreApplication");
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setEventDispatcher((QAbstractEventDispatcher *) RING_API_GETCPOINTER(2,"QAbstractEventDispatcher"));
}


RING_FUNC(ring_QCoreApplication_setLibraryPaths)
{
	QCoreApplication *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QCoreApplication *) RING_API_GETCPOINTER(1,"QCoreApplication");
	pObject->setLibraryPaths(* (QStringList  *) RING_API_GETCPOINTER(2,"QStringList"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QStringList"));
}


RING_FUNC(ring_QCoreApplication_setOrganizationDomain)
{
	QCoreApplication *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QCoreApplication *) RING_API_GETCPOINTER(1,"QCoreApplication");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setOrganizationDomain(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QCoreApplication_setOrganizationName)
{
	QCoreApplication *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QCoreApplication *) RING_API_GETCPOINTER(1,"QCoreApplication");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setOrganizationName(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QCoreApplication_setQuitLockEnabled)
{
	QCoreApplication *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QCoreApplication *) RING_API_GETCPOINTER(1,"QCoreApplication");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setQuitLockEnabled( (bool ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QCoreApplication_startingUp)
{
	QCoreApplication *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QCoreApplication *) RING_API_GETCPOINTER(1,"QCoreApplication");
	RING_API_RETNUMBER(pObject->startingUp());
}


RING_FUNC(ring_QCoreApplication_testAttribute)
{
	QCoreApplication *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QCoreApplication *) RING_API_GETCPOINTER(1,"QCoreApplication");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->testAttribute( (Qt::ApplicationAttribute )  (int) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QCoreApplication_translate)
{
	QCoreApplication *pObject ;
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QCoreApplication *) RING_API_GETCPOINTER(1,"QCoreApplication");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->translate(RING_API_GETSTRING(2),RING_API_GETSTRING(3),RING_API_GETSTRING(4), (int ) RING_API_GETNUMBER(5)).toStdString().c_str());
}


RING_FUNC(ring_QFile_copy)
{
	QFile *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFile *) RING_API_GETCPOINTER(1,"QFile");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->copy(RING_API_GETSTRING(2)));
}


RING_FUNC(ring_QFile_exists)
{
	QFile *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFile *) RING_API_GETCPOINTER(1,"QFile");
	RING_API_RETNUMBER(pObject->exists());
}


RING_FUNC(ring_QFile_link)
{
	QFile *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFile *) RING_API_GETCPOINTER(1,"QFile");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->link(RING_API_GETSTRING(2)));
}


RING_FUNC(ring_QFile_open)
{
	QFile *pObject ;
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFile *) RING_API_GETCPOINTER(1,"QFile");
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->open((FILE *) RING_API_GETCPOINTER(2,"FILE"), (QIODevice::OpenMode )  (int) RING_API_GETNUMBER(3), (QFile::FileHandleFlags )  (int) RING_API_GETNUMBER(4)));
}


RING_FUNC(ring_QFile_open_2)
{
	QFile *pObject ;
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFile *) RING_API_GETCPOINTER(1,"QFile");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->open( (int ) RING_API_GETNUMBER(2), (QIODevice::OpenMode )  (int) RING_API_GETNUMBER(3), (QFile::FileHandleFlags )  (int) RING_API_GETNUMBER(4)));
}


RING_FUNC(ring_QFile_open_3)
{
	QFile *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFile *) RING_API_GETCPOINTER(1,"QFile");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->open( (QIODevice::OpenMode )  (int) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QFile_remove)
{
	QFile *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFile *) RING_API_GETCPOINTER(1,"QFile");
	RING_API_RETNUMBER(pObject->remove());
}


RING_FUNC(ring_QFile_rename)
{
	QFile *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFile *) RING_API_GETCPOINTER(1,"QFile");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->rename(RING_API_GETSTRING(2)));
}


RING_FUNC(ring_QFile_setFileName)
{
	QFile *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFile *) RING_API_GETCPOINTER(1,"QFile");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setFileName(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QFile_symLinkTarget)
{
	QFile *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFile *) RING_API_GETCPOINTER(1,"QFile");
	RING_API_RETSTRING(pObject->symLinkTarget().toStdString().c_str());
}


RING_FUNC(ring_QFile_copy_2)
{
	QFile *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFile *) RING_API_GETCPOINTER(1,"QFile");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->copy(RING_API_GETSTRING(2),RING_API_GETSTRING(3)));
}


RING_FUNC(ring_QFile_decodeName)
{
	QFile *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFile *) RING_API_GETCPOINTER(1,"QFile");
	RING_API_RETSTRING(pObject->decodeName(* (QByteArray  *) RING_API_GETCPOINTER(2,"QByteArray")).toStdString().c_str());
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QByteArray"));
}


RING_FUNC(ring_QFile_decodeName_2)
{
	QFile *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFile *) RING_API_GETCPOINTER(1,"QFile");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->decodeName(RING_API_GETSTRING(2)).toStdString().c_str());
}


RING_FUNC(ring_QFile_encodeName)
{
	QFile *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFile *) RING_API_GETCPOINTER(1,"QFile");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QByteArray *pValue ; 
		pValue = new QByteArray() ;
		*pValue = pObject->encodeName(RING_API_GETSTRING(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"QByteArray",ring_QByteArray_freefunc);
	}
}


RING_FUNC(ring_QFile_exists_2)
{
	QFile *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFile *) RING_API_GETCPOINTER(1,"QFile");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->exists(RING_API_GETSTRING(2)));
}


RING_FUNC(ring_QFile_link_2)
{
	QFile *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFile *) RING_API_GETCPOINTER(1,"QFile");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->link(RING_API_GETSTRING(2),RING_API_GETSTRING(3)));
}


RING_FUNC(ring_QFile_permissions)
{
	QFile *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFile *) RING_API_GETCPOINTER(1,"QFile");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->permissions(RING_API_GETSTRING(2)));
}


RING_FUNC(ring_QFile_remove_2)
{
	QFile *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFile *) RING_API_GETCPOINTER(1,"QFile");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->remove(RING_API_GETSTRING(2)));
}


RING_FUNC(ring_QFile_rename_2)
{
	QFile *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFile *) RING_API_GETCPOINTER(1,"QFile");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->rename(RING_API_GETSTRING(2),RING_API_GETSTRING(3)));
}


RING_FUNC(ring_QFile_resize)
{
	QFile *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFile *) RING_API_GETCPOINTER(1,"QFile");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->resize(RING_API_GETSTRING(2), (qint64 ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_QFile_setPermissions)
{
	QFile *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFile *) RING_API_GETCPOINTER(1,"QFile");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->setPermissions(RING_API_GETSTRING(2), (QFile::Permissions )  (int) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_QFile_symLinkTarget_2)
{
	QFile *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFile *) RING_API_GETCPOINTER(1,"QFile");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->symLinkTarget(RING_API_GETSTRING(2)).toStdString().c_str());
}


RING_FUNC(ring_QFileDevice_error)
{
	QFileDevice *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileDevice *) RING_API_GETCPOINTER(1,"QFileDevice");
	RING_API_RETNUMBER(pObject->error());
}


RING_FUNC(ring_QFileDevice_flush)
{
	QFileDevice *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileDevice *) RING_API_GETCPOINTER(1,"QFileDevice");
	RING_API_RETNUMBER(pObject->flush());
}


RING_FUNC(ring_QFileDevice_handle)
{
	QFileDevice *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileDevice *) RING_API_GETCPOINTER(1,"QFileDevice");
	RING_API_RETNUMBER(pObject->handle());
}


RING_FUNC(ring_QFileDevice_map)
{
	QFileDevice *pObject ;
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileDevice *) RING_API_GETCPOINTER(1,"QFileDevice");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(pObject->map( (qint64 ) RING_API_GETNUMBER(2), (qint64 ) RING_API_GETNUMBER(3), (QFileDevice::MemoryMapFlags )  (int) RING_API_GETNUMBER(4)),"uchar");
}


RING_FUNC(ring_QFileDevice_permissions)
{
	QFileDevice *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileDevice *) RING_API_GETCPOINTER(1,"QFileDevice");
	RING_API_RETNUMBER(pObject->permissions());
}


RING_FUNC(ring_QFileDevice_resize)
{
	QFileDevice *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileDevice *) RING_API_GETCPOINTER(1,"QFileDevice");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->resize( (qint64 ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QFileDevice_fileName)
{
	QFileDevice *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileDevice *) RING_API_GETCPOINTER(1,"QFileDevice");
	RING_API_RETSTRING(pObject->fileName().toStdString().c_str());
}


RING_FUNC(ring_QFileDevice_setPermissions)
{
	QFileDevice *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileDevice *) RING_API_GETCPOINTER(1,"QFileDevice");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->setPermissions( (QFileDevice::Permissions )  (int) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QFileDevice_unmap)
{
	QFileDevice *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileDevice *) RING_API_GETCPOINTER(1,"QFileDevice");
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->unmap((uchar *) RING_API_GETCPOINTER(2,"uchar")));
}


RING_FUNC(ring_QFileDevice_unsetError)
{
	QFileDevice *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileDevice *) RING_API_GETCPOINTER(1,"QFileDevice");
	pObject->unsetError();
}


RING_FUNC(ring_QStandardPaths_displayName)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(QStandardPaths::displayName( (QStandardPaths::StandardLocation )  (int) RING_API_GETNUMBER(1)).toStdString().c_str());
}


RING_FUNC(ring_QStandardPaths_findExecutable)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(QStandardPaths::findExecutable(RING_API_GETSTRING(1),* (QStringList  *) RING_API_GETCPOINTER(2,"QStringList")).toStdString().c_str());
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"QStringList"));
}


RING_FUNC(ring_QStandardPaths_locate)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(QStandardPaths::locate( (QStandardPaths::StandardLocation )  (int) RING_API_GETNUMBER(1),RING_API_GETSTRING(2), (QStandardPaths::LocateOptions )  (int) RING_API_GETNUMBER(3)).toStdString().c_str());
}


RING_FUNC(ring_QStandardPaths_locateAll)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QStringList *pValue ; 
		pValue = new QStringList() ;
		*pValue = QStandardPaths::locateAll( (QStandardPaths::StandardLocation )  (int) RING_API_GETNUMBER(1),RING_API_GETSTRING(2), (QStandardPaths::LocateOptions )  (int) RING_API_GETNUMBER(3));
		RING_API_RETMANAGEDCPOINTER(pValue,"QStringList",ring_QStringList_freefunc);
	}
}


RING_FUNC(ring_QStandardPaths_setTestModeEnabled)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	QStandardPaths::setTestModeEnabled( (bool ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_QStandardPaths_standardLocations)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QStringList *pValue ; 
		pValue = new QStringList() ;
		*pValue = QStandardPaths::standardLocations( (QStandardPaths::StandardLocation )  (int) RING_API_GETNUMBER(1));
		RING_API_RETMANAGEDCPOINTER(pValue,"QStringList",ring_QStringList_freefunc);
	}
}


RING_FUNC(ring_QStandardPaths_writableLocation)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(QStandardPaths::writableLocation( (QStandardPaths::StandardLocation )  (int) RING_API_GETNUMBER(1)).toStdString().c_str());
}


RING_FUNC(ring_QMimeData_clear)
{
	QMimeData *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QMimeData *) RING_API_GETCPOINTER(1,"QMimeData");
	pObject->clear();
}


RING_FUNC(ring_QMimeData_colorData)
{
	QMimeData *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QMimeData *) RING_API_GETCPOINTER(1,"QMimeData");
	{
		QVariant *pValue ; 
		pValue = new QVariant() ;
		*pValue = pObject->colorData();
		RING_API_RETMANAGEDCPOINTER(pValue,"QVariant",ring_QVariant_freefunc);
	}
}


RING_FUNC(ring_QMimeData_data)
{
	QMimeData *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QMimeData *) RING_API_GETCPOINTER(1,"QMimeData");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QByteArray *pValue ; 
		pValue = new QByteArray() ;
		*pValue = pObject->data(RING_API_GETSTRING(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"QByteArray",ring_QByteArray_freefunc);
	}
}


RING_FUNC(ring_QMimeData_formats)
{
	QMimeData *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QMimeData *) RING_API_GETCPOINTER(1,"QMimeData");
	{
		QStringList *pValue ; 
		pValue = new QStringList() ;
		*pValue = pObject->formats();
		RING_API_RETMANAGEDCPOINTER(pValue,"QStringList",ring_QStringList_freefunc);
	}
}


RING_FUNC(ring_QMimeData_hasColor)
{
	QMimeData *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QMimeData *) RING_API_GETCPOINTER(1,"QMimeData");
	RING_API_RETNUMBER(pObject->hasColor());
}


RING_FUNC(ring_QMimeData_hasFormat)
{
	QMimeData *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QMimeData *) RING_API_GETCPOINTER(1,"QMimeData");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->hasFormat(RING_API_GETSTRING(2)));
}


RING_FUNC(ring_QMimeData_hasHtml)
{
	QMimeData *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QMimeData *) RING_API_GETCPOINTER(1,"QMimeData");
	RING_API_RETNUMBER(pObject->hasHtml());
}


RING_FUNC(ring_QMimeData_hasImage)
{
	QMimeData *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QMimeData *) RING_API_GETCPOINTER(1,"QMimeData");
	RING_API_RETNUMBER(pObject->hasImage());
}


RING_FUNC(ring_QMimeData_hasText)
{
	QMimeData *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QMimeData *) RING_API_GETCPOINTER(1,"QMimeData");
	RING_API_RETNUMBER(pObject->hasText());
}


RING_FUNC(ring_QMimeData_hasUrls)
{
	QMimeData *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QMimeData *) RING_API_GETCPOINTER(1,"QMimeData");
	RING_API_RETNUMBER(pObject->hasUrls());
}


RING_FUNC(ring_QMimeData_html)
{
	QMimeData *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QMimeData *) RING_API_GETCPOINTER(1,"QMimeData");
	RING_API_RETSTRING(pObject->html().toStdString().c_str());
}


RING_FUNC(ring_QMimeData_imageData)
{
	QMimeData *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QMimeData *) RING_API_GETCPOINTER(1,"QMimeData");
	{
		QVariant *pValue ; 
		pValue = new QVariant() ;
		*pValue = pObject->imageData();
		RING_API_RETMANAGEDCPOINTER(pValue,"QVariant",ring_QVariant_freefunc);
	}
}


RING_FUNC(ring_QMimeData_removeFormat)
{
	QMimeData *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QMimeData *) RING_API_GETCPOINTER(1,"QMimeData");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->removeFormat(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QMimeData_setColorData)
{
	QMimeData *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QMimeData *) RING_API_GETCPOINTER(1,"QMimeData");
	pObject->setColorData(* (QVariant  *) RING_API_GETCPOINTER(2,"QVariant"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QVariant"));
}


RING_FUNC(ring_QMimeData_setData)
{
	QMimeData *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QMimeData *) RING_API_GETCPOINTER(1,"QMimeData");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setData(RING_API_GETSTRING(2),* (QByteArray  *) RING_API_GETCPOINTER(3,"QByteArray"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"QByteArray"));
}


RING_FUNC(ring_QMimeData_setHtml)
{
	QMimeData *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QMimeData *) RING_API_GETCPOINTER(1,"QMimeData");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setHtml(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QMimeData_setImageData)
{
	QMimeData *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QMimeData *) RING_API_GETCPOINTER(1,"QMimeData");
	pObject->setImageData(* (QVariant  *) RING_API_GETCPOINTER(2,"QVariant"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QVariant"));
}


RING_FUNC(ring_QMimeData_setText)
{
	QMimeData *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QMimeData *) RING_API_GETCPOINTER(1,"QMimeData");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setText(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QMimeData_setUrls)
{
	QMimeData *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QMimeData *) RING_API_GETCPOINTER(1,"QMimeData");
	pObject->setUrls(* (QList<QUrl>  *) RING_API_GETCPOINTER(2,"QList<QUrl>"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QList<QUrl>"));
}


RING_FUNC(ring_QMimeData_text)
{
	QMimeData *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QMimeData *) RING_API_GETCPOINTER(1,"QMimeData");
	RING_API_RETSTRING(pObject->text().toStdString().c_str());
}


RING_FUNC(ring_QMimeData_urls)
{
	QMimeData *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QMimeData *) RING_API_GETCPOINTER(1,"QMimeData");
	{
		QList<QUrl> *pValue ; 
		pValue = (QList<QUrl> *) RING_API_MALLOC(sizeof(QList<QUrl>)) ;
		*pValue = pObject->urls();
		RING_API_RETMANAGEDCPOINTER(pValue,"QList<QUrl>",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QChar_category)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	RING_API_RETNUMBER(pObject->category());
}


RING_FUNC(ring_QChar_cell)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	{
		uchar *pValue ; 
		pValue = (uchar *) RING_API_MALLOC(sizeof(uchar)) ;
		*pValue = pObject->cell();
		RING_API_RETMANAGEDCPOINTER(pValue,"uchar",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QChar_combiningClass)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	RING_API_RETNUMBER(pObject->combiningClass());
}


RING_FUNC(ring_QChar_decomposition)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	RING_API_RETSTRING(pObject->decomposition().toStdString().c_str());
}


RING_FUNC(ring_QChar_decompositionTag)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	RING_API_RETNUMBER(pObject->decompositionTag());
}


RING_FUNC(ring_QChar_digitValue)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	RING_API_RETNUMBER(pObject->digitValue());
}


RING_FUNC(ring_QChar_direction)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	RING_API_RETNUMBER(pObject->direction());
}


RING_FUNC(ring_QChar_hasMirrored)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	RING_API_RETNUMBER(pObject->hasMirrored());
}


RING_FUNC(ring_QChar_isDigit)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	RING_API_RETNUMBER(pObject->isDigit());
}


RING_FUNC(ring_QChar_isHighSurrogate)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	RING_API_RETNUMBER(pObject->isHighSurrogate());
}


RING_FUNC(ring_QChar_isLetter)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	RING_API_RETNUMBER(pObject->isLetter());
}


RING_FUNC(ring_QChar_isLetterOrNumber)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	RING_API_RETNUMBER(pObject->isLetterOrNumber());
}


RING_FUNC(ring_QChar_isLowSurrogate)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	RING_API_RETNUMBER(pObject->isLowSurrogate());
}


RING_FUNC(ring_QChar_isLower)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	RING_API_RETNUMBER(pObject->isLower());
}


RING_FUNC(ring_QChar_isMark)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	RING_API_RETNUMBER(pObject->isMark());
}


RING_FUNC(ring_QChar_isNonCharacter)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	RING_API_RETNUMBER(pObject->isNonCharacter());
}


RING_FUNC(ring_QChar_isNull)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	RING_API_RETNUMBER(pObject->isNull());
}


RING_FUNC(ring_QChar_isNumber)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	RING_API_RETNUMBER(pObject->isNumber());
}


RING_FUNC(ring_QChar_isPrint)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	RING_API_RETNUMBER(pObject->isPrint());
}


RING_FUNC(ring_QChar_isPunct)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	RING_API_RETNUMBER(pObject->isPunct());
}


RING_FUNC(ring_QChar_isSpace)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	RING_API_RETNUMBER(pObject->isSpace());
}


RING_FUNC(ring_QChar_isSurrogate)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	RING_API_RETNUMBER(pObject->isSurrogate());
}


RING_FUNC(ring_QChar_isSymbol)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	RING_API_RETNUMBER(pObject->isSymbol());
}


RING_FUNC(ring_QChar_isTitleCase)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	RING_API_RETNUMBER(pObject->isTitleCase());
}


RING_FUNC(ring_QChar_isUpper)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	RING_API_RETNUMBER(pObject->isUpper());
}


RING_FUNC(ring_QChar_mirroredChar)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	{
		QChar *pValue ; 
		pValue = new QChar() ;
		*pValue = pObject->mirroredChar();
		RING_API_RETMANAGEDCPOINTER(pValue,"QChar",ring_QChar_freefunc);
	}
}


RING_FUNC(ring_QChar_row)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	{
		uchar *pValue ; 
		pValue = (uchar *) RING_API_MALLOC(sizeof(uchar)) ;
		*pValue = pObject->row();
		RING_API_RETMANAGEDCPOINTER(pValue,"uchar",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QChar_script)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	RING_API_RETNUMBER(pObject->script());
}


RING_FUNC(ring_QChar_toCaseFolded)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	{
		QChar *pValue ; 
		pValue = new QChar() ;
		*pValue = pObject->toCaseFolded();
		RING_API_RETMANAGEDCPOINTER(pValue,"QChar",ring_QChar_freefunc);
	}
}


RING_FUNC(ring_QChar_toLatin1)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	RING_API_RETNUMBER(pObject->toLatin1());
}


RING_FUNC(ring_QChar_toLower)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	{
		QChar *pValue ; 
		pValue = new QChar() ;
		*pValue = pObject->toLower();
		RING_API_RETMANAGEDCPOINTER(pValue,"QChar",ring_QChar_freefunc);
	}
}


RING_FUNC(ring_QChar_toTitleCase)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	{
		QChar *pValue ; 
		pValue = new QChar() ;
		*pValue = pObject->toTitleCase();
		RING_API_RETMANAGEDCPOINTER(pValue,"QChar",ring_QChar_freefunc);
	}
}


RING_FUNC(ring_QChar_toUpper)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	{
		QChar *pValue ; 
		pValue = new QChar() ;
		*pValue = pObject->toUpper();
		RING_API_RETMANAGEDCPOINTER(pValue,"QChar",ring_QChar_freefunc);
	}
}


RING_FUNC(ring_QChar_unicode)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	RING_API_RETNUMBER(pObject->unicode());
}


RING_FUNC(ring_QChar_unicode_2)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	RING_API_RETNUMBER(pObject->unicode());
}


RING_FUNC(ring_QChar_unicodeVersion)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	RING_API_RETNUMBER(pObject->unicodeVersion());
}


RING_FUNC(ring_QChar_category_2)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->category( (uint ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QChar_combiningClass_2)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->combiningClass( (uint ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QChar_currentUnicodeVersion)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	RING_API_RETNUMBER(pObject->currentUnicodeVersion());
}


RING_FUNC(ring_QChar_decomposition_2)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->decomposition( (uint ) RING_API_GETNUMBER(2)).toStdString().c_str());
}


RING_FUNC(ring_QChar_decompositionTag_2)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->decompositionTag( (uint ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QChar_digitValue_2)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->digitValue( (uint ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QChar_direction_2)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->direction( (uint ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QChar_fromLatin1)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QChar *pValue ; 
		pValue = new QChar() ;
		*pValue = pObject->fromLatin1( (char ) RING_API_GETNUMBER(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"QChar",ring_QChar_freefunc);
	}
}


RING_FUNC(ring_QChar_hasMirrored_2)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->hasMirrored( (uint ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QChar_highSurrogate)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->highSurrogate( (uint ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QChar_isDigit_2)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->isDigit( (uint ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QChar_isHighSurrogate_2)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->isHighSurrogate( (uint ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QChar_isLetter_2)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->isLetter( (uint ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QChar_isLetterOrNumber_2)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->isLetterOrNumber( (uint ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QChar_isLowSurrogate_2)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->isLowSurrogate( (uint ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QChar_isLower_2)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->isLower( (uint ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QChar_isMark_2)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->isMark( (uint ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QChar_isNonCharacter_2)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->isNonCharacter( (uint ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QChar_isNumber_2)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->isNumber( (uint ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QChar_isPrint_2)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->isPrint( (uint ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QChar_isPunct_2)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->isPunct( (uint ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QChar_isSpace_2)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->isSpace( (uint ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QChar_isSurrogate_2)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->isSurrogate( (uint ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QChar_isSymbol_2)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->isSymbol( (uint ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QChar_isTitleCase_2)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->isTitleCase( (uint ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QChar_isUpper_2)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->isUpper( (uint ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QChar_lowSurrogate)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->lowSurrogate( (uint ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QChar_mirroredChar_2)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->mirroredChar( (uint ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QChar_requiresSurrogates)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->requiresSurrogates( (uint ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QChar_script_2)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->script( (uint ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QChar_surrogateToUcs4)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->surrogateToUcs4( (ushort ) RING_API_GETNUMBER(2), (ushort ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_QChar_surrogateToUcs4_2)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	RING_API_RETNUMBER(pObject->surrogateToUcs4(* (QChar  *) RING_API_GETCPOINTER(2,"QChar"),* (QChar  *) RING_API_GETCPOINTER(3,"QChar")));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QChar"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"QChar"));
}


RING_FUNC(ring_QChar_toCaseFolded_2)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->toCaseFolded( (uint ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QChar_toLower_2)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->toLower( (uint ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QChar_toTitleCase_2)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->toTitleCase( (uint ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QChar_toUpper_2)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->toUpper( (uint ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QChar_unicodeVersion_2)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->unicodeVersion( (uint ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QChildEvent_added)
{
	QChildEvent *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChildEvent *) RING_API_GETCPOINTER(1,"QChildEvent");
	RING_API_RETNUMBER(pObject->added());
}


RING_FUNC(ring_QChildEvent_child)
{
	QChildEvent *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChildEvent *) RING_API_GETCPOINTER(1,"QChildEvent");
	RING_API_RETCPOINTER(pObject->child(),"QObject");
}


RING_FUNC(ring_QChildEvent_polished)
{
	QChildEvent *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChildEvent *) RING_API_GETCPOINTER(1,"QChildEvent");
	RING_API_RETNUMBER(pObject->polished());
}


RING_FUNC(ring_QChildEvent_removed)
{
	QChildEvent *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChildEvent *) RING_API_GETCPOINTER(1,"QChildEvent");
	RING_API_RETNUMBER(pObject->removed());
}


RING_FUNC(ring_QLocale_amText)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	RING_API_RETSTRING(pObject->amText().toStdString().c_str());
}


RING_FUNC(ring_QLocale_bcp47Name)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	RING_API_RETSTRING(pObject->bcp47Name().toStdString().c_str());
}


RING_FUNC(ring_QLocale_country)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	RING_API_RETNUMBER(pObject->country());
}


RING_FUNC(ring_QLocale_createSeparatedList)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	RING_API_RETSTRING(pObject->createSeparatedList(* (QStringList  *) RING_API_GETCPOINTER(2,"QStringList")).toStdString().c_str());
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QStringList"));
}


RING_FUNC(ring_QLocale_currencySymbol)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->currencySymbol( (QLocale::CurrencySymbolFormat )  (int) RING_API_GETNUMBER(2)).toStdString().c_str());
}


RING_FUNC(ring_QLocale_dateFormat)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->dateFormat( (QLocale::FormatType )  (int) RING_API_GETNUMBER(2)).toStdString().c_str());
}


RING_FUNC(ring_QLocale_dateTimeFormat)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->dateTimeFormat( (QLocale::FormatType )  (int) RING_API_GETNUMBER(2)).toStdString().c_str());
}


RING_FUNC(ring_QLocale_dayName)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->dayName( (int ) RING_API_GETNUMBER(2), (QLocale::FormatType )  (int) RING_API_GETNUMBER(3)).toStdString().c_str());
}


RING_FUNC(ring_QLocale_decimalPoint)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	RING_API_RETSTRING(pObject->decimalPoint().toStdString().c_str());
}


RING_FUNC(ring_QLocale_exponential)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	RING_API_RETSTRING(pObject->exponential().toStdString().c_str());
}


RING_FUNC(ring_QLocale_firstDayOfWeek)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	{
		Qt::DayOfWeek *pValue ; 
		pValue = (Qt::DayOfWeek *) RING_API_MALLOC(sizeof(Qt::DayOfWeek)) ;
		*pValue = pObject->firstDayOfWeek();
		RING_API_RETMANAGEDCPOINTER(pValue,"Qt::DayOfWeek",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QLocale_groupSeparator)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	RING_API_RETSTRING(pObject->groupSeparator().toStdString().c_str());
}


RING_FUNC(ring_QLocale_language)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	RING_API_RETNUMBER(pObject->language());
}


RING_FUNC(ring_QLocale_measurementSystem)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	RING_API_RETNUMBER(pObject->measurementSystem());
}


RING_FUNC(ring_QLocale_monthName)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->monthName( (int ) RING_API_GETNUMBER(2), (QLocale::FormatType )  (int) RING_API_GETNUMBER(3)).toStdString().c_str());
}


RING_FUNC(ring_QLocale_name)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	RING_API_RETSTRING(pObject->name().toStdString().c_str());
}


RING_FUNC(ring_QLocale_nativeCountryName)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	RING_API_RETSTRING(pObject->nativeCountryName().toStdString().c_str());
}


RING_FUNC(ring_QLocale_nativeLanguageName)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	RING_API_RETSTRING(pObject->nativeLanguageName().toStdString().c_str());
}


RING_FUNC(ring_QLocale_negativeSign)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	RING_API_RETSTRING(pObject->negativeSign().toStdString().c_str());
}


RING_FUNC(ring_QLocale_numberOptions)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	RING_API_RETNUMBER(pObject->numberOptions());
}


RING_FUNC(ring_QLocale_percent)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	RING_API_RETSTRING(pObject->percent().toStdString().c_str());
}


RING_FUNC(ring_QLocale_pmText)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	RING_API_RETSTRING(pObject->pmText().toStdString().c_str());
}


RING_FUNC(ring_QLocale_positiveSign)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	RING_API_RETSTRING(pObject->positiveSign().toStdString().c_str());
}


RING_FUNC(ring_QLocale_quoteString)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->quoteString(RING_API_GETSTRING(2), (QLocale::QuotationStyle )  (int) RING_API_GETNUMBER(3)).toStdString().c_str());
}


RING_FUNC(ring_QLocale_script)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	RING_API_RETNUMBER(pObject->script());
}


RING_FUNC(ring_QLocale_setNumberOptions)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setNumberOptions( (QLocale::NumberOptions )  (int) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QLocale_standaloneDayName)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->standaloneDayName( (int ) RING_API_GETNUMBER(2), (QLocale::FormatType )  (int) RING_API_GETNUMBER(3)).toStdString().c_str());
}


RING_FUNC(ring_QLocale_standaloneMonthName)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->standaloneMonthName( (int ) RING_API_GETNUMBER(2), (QLocale::FormatType )  (int) RING_API_GETNUMBER(3)).toStdString().c_str());
}


RING_FUNC(ring_QLocale_textDirection)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	RING_API_RETNUMBER(pObject->textDirection());
}


RING_FUNC(ring_QLocale_timeFormat)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->timeFormat( (QLocale::FormatType )  (int) RING_API_GETNUMBER(2)).toStdString().c_str());
}


RING_FUNC(ring_QLocale_toDouble)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->toDouble(RING_API_GETSTRING(2),(bool *) RING_API_GETCPOINTER(3,"bool")));
}


RING_FUNC(ring_QLocale_toFloat)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->toFloat(RING_API_GETSTRING(2),(bool *) RING_API_GETCPOINTER(3,"bool")));
}


RING_FUNC(ring_QLocale_toInt)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->toInt(RING_API_GETSTRING(2),(bool *) RING_API_GETCPOINTER(3,"bool")));
}


RING_FUNC(ring_QLocale_toLongLong)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		qlonglong *pValue ; 
		pValue = (qlonglong *) RING_API_MALLOC(sizeof(qlonglong)) ;
		*pValue = pObject->toLongLong(RING_API_GETSTRING(2),(bool *) RING_API_GETCPOINTER(3,"bool"));
		RING_API_RETMANAGEDCPOINTER(pValue,"qlonglong",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QLocale_toLower)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->toLower(RING_API_GETSTRING(2)).toStdString().c_str());
}


RING_FUNC(ring_QLocale_toShort)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		short *pValue ; 
		pValue = (short *) RING_API_MALLOC(sizeof(short)) ;
		*pValue = pObject->toShort(RING_API_GETSTRING(2),(bool *) RING_API_GETCPOINTER(3,"bool"));
		RING_API_RETMANAGEDCPOINTER(pValue,"short",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QLocale_toString)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	RING_API_RETSTRING(pObject->toString(* (qlonglong  *) RING_API_GETCPOINTER(2,"qlonglong")).toStdString().c_str());
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"qlonglong"));
}


RING_FUNC(ring_QLocale_toString_2)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	RING_API_RETSTRING(pObject->toString(* (qulonglong  *) RING_API_GETCPOINTER(2,"qulonglong")).toStdString().c_str());
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"qulonglong"));
}


RING_FUNC(ring_QLocale_toString_4)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	RING_API_RETSTRING(pObject->toString(* (short  *) RING_API_GETCPOINTER(2,"short")).toStdString().c_str());
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"short"));
}


RING_FUNC(ring_QLocale_toString_5)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->toString( (ushort ) RING_API_GETNUMBER(2)).toStdString().c_str());
}


RING_FUNC(ring_QLocale_toString_6)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->toString( (int ) RING_API_GETNUMBER(2)).toStdString().c_str());
}


RING_FUNC(ring_QLocale_toString_7)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->toString( (uint ) RING_API_GETNUMBER(2)).toStdString().c_str());
}


RING_FUNC(ring_QLocale_toString_8)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->toString( (double ) RING_API_GETNUMBER(2), (char ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4)).toStdString().c_str());
}


RING_FUNC(ring_QLocale_toString_9)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->toString( (float ) RING_API_GETNUMBER(2), (char ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4)).toStdString().c_str());
}


RING_FUNC(ring_QLocale_toString_10)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->toString(* (QDate  *) RING_API_GETCPOINTER(2,"QDate"),RING_API_GETSTRING(3)).toStdString().c_str());
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QDate"));
}


RING_FUNC(ring_QLocale_toString_11)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->toString(* (QTime  *) RING_API_GETCPOINTER(2,"QTime"),RING_API_GETSTRING(3)).toStdString().c_str());
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QTime"));
}


RING_FUNC(ring_QLocale_toString_12)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->toString(* (QDateTime  *) RING_API_GETCPOINTER(2,"QDateTime"),RING_API_GETSTRING(3)).toStdString().c_str());
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QDateTime"));
}


RING_FUNC(ring_QLocale_toString_13)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->toString(* (QDate  *) RING_API_GETCPOINTER(2,"QDate"), (QLocale::FormatType )  (int) RING_API_GETNUMBER(3)).toStdString().c_str());
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QDate"));
}


RING_FUNC(ring_QLocale_toString_14)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->toString(* (QTime  *) RING_API_GETCPOINTER(2,"QTime"), (QLocale::FormatType )  (int) RING_API_GETNUMBER(3)).toStdString().c_str());
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QTime"));
}


RING_FUNC(ring_QLocale_toString_15)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->toString(* (QDateTime  *) RING_API_GETCPOINTER(2,"QDateTime"), (QLocale::FormatType )  (int) RING_API_GETNUMBER(3)).toStdString().c_str());
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QDateTime"));
}


RING_FUNC(ring_QLocale_toTime)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QTime *pValue ; 
		pValue = new QTime() ;
		*pValue = pObject->toTime(RING_API_GETSTRING(2), (QLocale::FormatType )  (int) RING_API_GETNUMBER(3));
		RING_API_RETMANAGEDCPOINTER(pValue,"QTime",ring_QTime_freefunc);
	}
}


RING_FUNC(ring_QLocale_toTime_2)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QTime *pValue ; 
		pValue = new QTime() ;
		*pValue = pObject->toTime(RING_API_GETSTRING(2),RING_API_GETSTRING(3));
		RING_API_RETMANAGEDCPOINTER(pValue,"QTime",ring_QTime_freefunc);
	}
}


RING_FUNC(ring_QLocale_toUInt)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->toUInt(RING_API_GETSTRING(2),(bool *) RING_API_GETCPOINTER(3,"bool")));
}


RING_FUNC(ring_QLocale_toULongLong)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		qulonglong *pValue ; 
		pValue = (qulonglong *) RING_API_MALLOC(sizeof(qulonglong)) ;
		*pValue = pObject->toULongLong(RING_API_GETSTRING(2),(bool *) RING_API_GETCPOINTER(3,"bool"));
		RING_API_RETMANAGEDCPOINTER(pValue,"qulonglong",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QLocale_toUShort)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->toUShort(RING_API_GETSTRING(2),(bool *) RING_API_GETCPOINTER(3,"bool")));
}


RING_FUNC(ring_QLocale_toUpper)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->toUpper(RING_API_GETSTRING(2)).toStdString().c_str());
}


RING_FUNC(ring_QLocale_uiLanguages)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	{
		QStringList *pValue ; 
		pValue = new QStringList() ;
		*pValue = pObject->uiLanguages();
		RING_API_RETMANAGEDCPOINTER(pValue,"QStringList",ring_QStringList_freefunc);
	}
}


RING_FUNC(ring_QLocale_weekdays)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	{
		QList<Qt::DayOfWeek> *pValue ; 
		pValue = (QList<Qt::DayOfWeek> *) RING_API_MALLOC(sizeof(QList<Qt::DayOfWeek>)) ;
		*pValue = pObject->weekdays();
		RING_API_RETMANAGEDCPOINTER(pValue,"QList<Qt::DayOfWeek>",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QLocale_zeroDigit)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	RING_API_RETSTRING(pObject->zeroDigit().toStdString().c_str());
}


RING_FUNC(ring_QLocale_c)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	{
		QLocale *pValue ; 
		pValue = new QLocale() ;
		*pValue = pObject->c();
		RING_API_RETMANAGEDCPOINTER(pValue,"QLocale",ring_QLocale_freefunc);
	}
}


RING_FUNC(ring_QLocale_countryToString)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->countryToString( (QLocale::Country )  (int) RING_API_GETNUMBER(2)).toStdString().c_str());
}


RING_FUNC(ring_QLocale_languageToString)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->languageToString( (QLocale::Language )  (int) RING_API_GETNUMBER(2)).toStdString().c_str());
}


RING_FUNC(ring_QLocale_matchingLocales)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QList<QLocale> *pValue ; 
		pValue = (QList<QLocale> *) RING_API_MALLOC(sizeof(QList<QLocale>)) ;
		*pValue = pObject->matchingLocales( (QLocale::Language )  (int) RING_API_GETNUMBER(2), (QLocale::Script )  (int) RING_API_GETNUMBER(3), (QLocale::Country )  (int) RING_API_GETNUMBER(4));
		RING_API_RETMANAGEDCPOINTER(pValue,"QList<QLocale>",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QLocale_scriptToString)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->scriptToString( (QLocale::Script )  (int) RING_API_GETNUMBER(2)).toStdString().c_str());
}


RING_FUNC(ring_QLocale_setDefault)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	pObject->setDefault(* (QLocale  *) RING_API_GETCPOINTER(2,"QLocale"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QLocale"));
}


RING_FUNC(ring_QLocale_system)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	{
		QLocale *pValue ; 
		pValue = new QLocale() ;
		*pValue = pObject->system();
		RING_API_RETMANAGEDCPOINTER(pValue,"QLocale",ring_QLocale_freefunc);
	}
}


RING_FUNC(ring_QThread_eventDispatcher)
{
	GThread *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GThread *) RING_API_GETCPOINTER(1,"QThread");
	RING_API_RETCPOINTER(pObject->eventDispatcher(),"QAbstractEventDispatcher");
}


RING_FUNC(ring_QThread_exit)
{
	GThread *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GThread *) RING_API_GETCPOINTER(1,"QThread");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->exit( (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QThread_isFinished)
{
	GThread *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GThread *) RING_API_GETCPOINTER(1,"QThread");
	RING_API_RETNUMBER(pObject->isFinished());
}


RING_FUNC(ring_QThread_isInterruptionRequested)
{
	GThread *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GThread *) RING_API_GETCPOINTER(1,"QThread");
	RING_API_RETNUMBER(pObject->isInterruptionRequested());
}


RING_FUNC(ring_QThread_isRunning)
{
	GThread *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GThread *) RING_API_GETCPOINTER(1,"QThread");
	RING_API_RETNUMBER(pObject->isRunning());
}


RING_FUNC(ring_QThread_priority)
{
	GThread *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GThread *) RING_API_GETCPOINTER(1,"QThread");
	RING_API_RETNUMBER(pObject->priority());
}


RING_FUNC(ring_QThread_requestInterruption)
{
	GThread *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GThread *) RING_API_GETCPOINTER(1,"QThread");
	pObject->requestInterruption();
}


RING_FUNC(ring_QThread_setEventDispatcher)
{
	GThread *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GThread *) RING_API_GETCPOINTER(1,"QThread");
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setEventDispatcher((QAbstractEventDispatcher *) RING_API_GETCPOINTER(2,"QAbstractEventDispatcher"));
}


RING_FUNC(ring_QThread_setPriority)
{
	GThread *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GThread *) RING_API_GETCPOINTER(1,"QThread");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setPriority( (QThread::Priority )  (int) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QThread_setStackSize)
{
	GThread *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GThread *) RING_API_GETCPOINTER(1,"QThread");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setStackSize( (uint ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QThread_stackSize)
{
	GThread *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GThread *) RING_API_GETCPOINTER(1,"QThread");
	RING_API_RETNUMBER(pObject->stackSize());
}


RING_FUNC(ring_QThread_wait)
{
	GThread *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GThread *) RING_API_GETCPOINTER(1,"QThread");
	RING_API_RETNUMBER(pObject->wait(* (unsigned long  *) RING_API_GETCPOINTER(2,"unsigned long")));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"unsigned long"));
}


RING_FUNC(ring_QThread_quit)
{
	GThread *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GThread *) RING_API_GETCPOINTER(1,"QThread");
	pObject->quit();
}


RING_FUNC(ring_QThread_start)
{
	GThread *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GThread *) RING_API_GETCPOINTER(1,"QThread");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->start( (QThread::Priority )  (int) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QThread_terminate)
{
	GThread *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GThread *) RING_API_GETCPOINTER(1,"QThread");
	pObject->terminate();
}


RING_FUNC(ring_QThread_currentThread)
{
	GThread *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GThread *) RING_API_GETCPOINTER(1,"QThread");
	RING_API_RETCPOINTER(pObject->currentThread(),"QThread");
}


RING_FUNC(ring_QThread_currentThreadId)
{
	GThread *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GThread *) RING_API_GETCPOINTER(1,"QThread");
	{
		Qt::HANDLE *pValue ; 
		pValue = (Qt::HANDLE *) RING_API_MALLOC(sizeof(Qt::HANDLE)) ;
		*pValue = pObject->currentThreadId();
		RING_API_RETMANAGEDCPOINTER(pValue,"Qt::HANDLE",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QThread_idealThreadCount)
{
	GThread *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GThread *) RING_API_GETCPOINTER(1,"QThread");
	RING_API_RETNUMBER(pObject->idealThreadCount());
}


RING_FUNC(ring_QThread_msleep)
{
	GThread *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GThread *) RING_API_GETCPOINTER(1,"QThread");
	pObject->msleep(* (unsigned long  *) RING_API_GETCPOINTER(2,"unsigned long"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"unsigned long"));
}


RING_FUNC(ring_QThread_sleep)
{
	GThread *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GThread *) RING_API_GETCPOINTER(1,"QThread");
	pObject->sleep(* (unsigned long  *) RING_API_GETCPOINTER(2,"unsigned long"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"unsigned long"));
}


RING_FUNC(ring_QThread_usleep)
{
	GThread *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GThread *) RING_API_GETCPOINTER(1,"QThread");
	pObject->usleep(* (unsigned long  *) RING_API_GETCPOINTER(2,"unsigned long"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"unsigned long"));
}


RING_FUNC(ring_QThread_yieldCurrentThread)
{
	GThread *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GThread *) RING_API_GETCPOINTER(1,"QThread");
	pObject->yieldCurrentThread();
}


RING_FUNC(ring_QThread_setStartedEvent)
{
	GThread *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GThread *) RING_API_GETCPOINTER(1,"QThread");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setStartedEvent(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QThread_setFinishedEvent)
{
	GThread *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GThread *) RING_API_GETCPOINTER(1,"QThread");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setFinishedEvent(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QThread_getStartedEvent)
{
	GThread *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GThread *) RING_API_GETCPOINTER(1,"QThread");
	RING_API_RETSTRING(pObject->getStartedEvent());
}


RING_FUNC(ring_QThread_getFinishedEvent)
{
	GThread *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GThread *) RING_API_GETCPOINTER(1,"QThread");
	RING_API_RETSTRING(pObject->getFinishedEvent());
}


RING_FUNC(ring_QThreadPool_activeThreadCount)
{
	QThreadPool *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QThreadPool *) RING_API_GETCPOINTER(1,"QThreadPool");
	RING_API_RETNUMBER(pObject->activeThreadCount());
}


RING_FUNC(ring_QThreadPool_clear)
{
	QThreadPool *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QThreadPool *) RING_API_GETCPOINTER(1,"QThreadPool");
	pObject->clear();
}


RING_FUNC(ring_QThreadPool_expiryTimeout)
{
	QThreadPool *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QThreadPool *) RING_API_GETCPOINTER(1,"QThreadPool");
	RING_API_RETNUMBER(pObject->expiryTimeout());
}


RING_FUNC(ring_QThreadPool_maxThreadCount)
{
	QThreadPool *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QThreadPool *) RING_API_GETCPOINTER(1,"QThreadPool");
	RING_API_RETNUMBER(pObject->maxThreadCount());
}


RING_FUNC(ring_QThreadPool_releaseThread)
{
	QThreadPool *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QThreadPool *) RING_API_GETCPOINTER(1,"QThreadPool");
	pObject->releaseThread();
}


RING_FUNC(ring_QThreadPool_reserveThread)
{
	QThreadPool *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QThreadPool *) RING_API_GETCPOINTER(1,"QThreadPool");
	pObject->reserveThread();
}


RING_FUNC(ring_QThreadPool_setExpiryTimeout)
{
	QThreadPool *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QThreadPool *) RING_API_GETCPOINTER(1,"QThreadPool");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setExpiryTimeout( (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QThreadPool_setMaxThreadCount)
{
	QThreadPool *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QThreadPool *) RING_API_GETCPOINTER(1,"QThreadPool");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setMaxThreadCount( (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QThreadPool_start)
{
	QThreadPool *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QThreadPool *) RING_API_GETCPOINTER(1,"QThreadPool");
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->start((QRunnable *) RING_API_GETCPOINTER(2,"QRunnable"), (int ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_QThreadPool_tryStart)
{
	QThreadPool *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QThreadPool *) RING_API_GETCPOINTER(1,"QThreadPool");
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->tryStart((QRunnable *) RING_API_GETCPOINTER(2,"QRunnable")));
}


RING_FUNC(ring_QThreadPool_waitForDone)
{
	QThreadPool *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QThreadPool *) RING_API_GETCPOINTER(1,"QThreadPool");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->waitForDone( (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QThreadPool_globalInstance)
{
	QThreadPool *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QThreadPool *) RING_API_GETCPOINTER(1,"QThreadPool");
	RING_API_RETCPOINTER(pObject->globalInstance(),"QThreadPool");
}


RING_FUNC(ring_QProcess_arguments)
{
	GProcess *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GProcess *) RING_API_GETCPOINTER(1,"QProcess");
	{
		QStringList *pValue ; 
		pValue = new QStringList() ;
		*pValue = pObject->arguments();
		RING_API_RETMANAGEDCPOINTER(pValue,"QStringList",ring_QStringList_freefunc);
	}
}


RING_FUNC(ring_QProcess_closeReadChannel)
{
	GProcess *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GProcess *) RING_API_GETCPOINTER(1,"QProcess");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->closeReadChannel( (QProcess::ProcessChannel )  (int) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QProcess_closeWriteChannel)
{
	GProcess *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GProcess *) RING_API_GETCPOINTER(1,"QProcess");
	pObject->closeWriteChannel();
}


RING_FUNC(ring_QProcess_error)
{
	GProcess *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GProcess *) RING_API_GETCPOINTER(1,"QProcess");
	RING_API_RETNUMBER(pObject->error());
}


RING_FUNC(ring_QProcess_exitCode)
{
	GProcess *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GProcess *) RING_API_GETCPOINTER(1,"QProcess");
	RING_API_RETNUMBER(pObject->exitCode());
}


RING_FUNC(ring_QProcess_exitStatus)
{
	GProcess *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GProcess *) RING_API_GETCPOINTER(1,"QProcess");
	RING_API_RETNUMBER(pObject->exitStatus());
}


RING_FUNC(ring_QProcess_inputChannelMode)
{
	GProcess *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GProcess *) RING_API_GETCPOINTER(1,"QProcess");
	RING_API_RETNUMBER(pObject->inputChannelMode());
}


RING_FUNC(ring_QProcess_processChannelMode)
{
	GProcess *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GProcess *) RING_API_GETCPOINTER(1,"QProcess");
	RING_API_RETNUMBER(pObject->processChannelMode());
}


RING_FUNC(ring_QProcess_processEnvironment)
{
	GProcess *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GProcess *) RING_API_GETCPOINTER(1,"QProcess");
	{
		QProcessEnvironment *pValue ; 
		pValue = (QProcessEnvironment *) RING_API_MALLOC(sizeof(QProcessEnvironment)) ;
		*pValue = pObject->processEnvironment();
		RING_API_RETMANAGEDCPOINTER(pValue,"QProcessEnvironment",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QProcess_program)
{
	GProcess *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GProcess *) RING_API_GETCPOINTER(1,"QProcess");
	RING_API_RETSTRING(pObject->program().toStdString().c_str());
}


RING_FUNC(ring_QProcess_readAllStandardError)
{
	GProcess *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GProcess *) RING_API_GETCPOINTER(1,"QProcess");
	{
		QByteArray *pValue ; 
		pValue = new QByteArray() ;
		*pValue = pObject->readAllStandardError();
		RING_API_RETMANAGEDCPOINTER(pValue,"QByteArray",ring_QByteArray_freefunc);
	}
}


RING_FUNC(ring_QProcess_readAllStandardOutput)
{
	GProcess *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GProcess *) RING_API_GETCPOINTER(1,"QProcess");
	{
		QByteArray *pValue ; 
		pValue = new QByteArray() ;
		*pValue = pObject->readAllStandardOutput();
		RING_API_RETMANAGEDCPOINTER(pValue,"QByteArray",ring_QByteArray_freefunc);
	}
}


RING_FUNC(ring_QProcess_readChannel)
{
	GProcess *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GProcess *) RING_API_GETCPOINTER(1,"QProcess");
	RING_API_RETNUMBER(pObject->readChannel());
}


RING_FUNC(ring_QProcess_setArguments)
{
	GProcess *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GProcess *) RING_API_GETCPOINTER(1,"QProcess");
	pObject->setArguments(* (QStringList   *) RING_API_GETCPOINTER(2,"QStringList"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QStringList"));
}


RING_FUNC(ring_QProcess_setInputChannelMode)
{
	GProcess *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GProcess *) RING_API_GETCPOINTER(1,"QProcess");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setInputChannelMode( (QProcess::InputChannelMode )  (int) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QProcess_setProcessChannelMode)
{
	GProcess *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GProcess *) RING_API_GETCPOINTER(1,"QProcess");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setProcessChannelMode( (QProcess::ProcessChannelMode )  (int) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QProcess_setProcessEnvironment)
{
	GProcess *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GProcess *) RING_API_GETCPOINTER(1,"QProcess");
	pObject->setProcessEnvironment(* (QProcessEnvironment   *) RING_API_GETCPOINTER(2,"QProcessEnvironment"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QProcessEnvironment"));
}


RING_FUNC(ring_QProcess_setProgram)
{
	GProcess *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GProcess *) RING_API_GETCPOINTER(1,"QProcess");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setProgram(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QProcess_setReadChannel)
{
	GProcess *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GProcess *) RING_API_GETCPOINTER(1,"QProcess");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setReadChannel( (QProcess::ProcessChannel )  (int) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QProcess_setStandardErrorFile)
{
	GProcess *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GProcess *) RING_API_GETCPOINTER(1,"QProcess");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setStandardErrorFile(RING_API_GETSTRING(2), (QIODevice::OpenMode )  (int) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_QProcess_setStandardInputFile)
{
	GProcess *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GProcess *) RING_API_GETCPOINTER(1,"QProcess");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setStandardInputFile(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QProcess_setStandardOutputFile)
{
	GProcess *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GProcess *) RING_API_GETCPOINTER(1,"QProcess");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setStandardOutputFile(RING_API_GETSTRING(2), (QIODevice::OpenMode )  (int) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_QProcess_setStandardOutputProcess)
{
	GProcess *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GProcess *) RING_API_GETCPOINTER(1,"QProcess");
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setStandardOutputProcess((QProcess *) RING_API_GETCPOINTER(2,"QProcess"));
}


RING_FUNC(ring_QProcess_setWorkingDirectory)
{
	GProcess *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GProcess *) RING_API_GETCPOINTER(1,"QProcess");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setWorkingDirectory(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QProcess_start)
{
	GProcess *pObject ;
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GProcess *) RING_API_GETCPOINTER(1,"QProcess");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->start(RING_API_GETSTRING(2),* (QStringList   *) RING_API_GETCPOINTER(3,"QStringList"), (QIODevice::OpenMode )  (int) RING_API_GETNUMBER(4));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"QStringList"));
}


RING_FUNC(ring_QProcess_start_3)
{
	GProcess *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GProcess *) RING_API_GETCPOINTER(1,"QProcess");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->start( (QIODevice::OpenMode )  (int) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QProcess_state)
{
	GProcess *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GProcess *) RING_API_GETCPOINTER(1,"QProcess");
	RING_API_RETNUMBER(pObject->state());
}


RING_FUNC(ring_QProcess_waitForFinished)
{
	GProcess *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GProcess *) RING_API_GETCPOINTER(1,"QProcess");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->waitForFinished( (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QProcess_waitForStarted)
{
	GProcess *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GProcess *) RING_API_GETCPOINTER(1,"QProcess");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->waitForStarted( (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QProcess_workingDirectory)
{
	GProcess *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GProcess *) RING_API_GETCPOINTER(1,"QProcess");
	RING_API_RETSTRING(pObject->workingDirectory().toStdString().c_str());
}


RING_FUNC(ring_QProcess_kill)
{
	GProcess *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GProcess *) RING_API_GETCPOINTER(1,"QProcess");
	pObject->kill();
}


RING_FUNC(ring_QProcess_terminate)
{
	GProcess *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GProcess *) RING_API_GETCPOINTER(1,"QProcess");
	pObject->terminate();
}


RING_FUNC(ring_QProcess_setreadyReadStandardErrorEvent)
{
	GProcess *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GProcess *) RING_API_GETCPOINTER(1,"QProcess");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setreadyReadStandardErrorEvent(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QProcess_setreadyReadStandardOutputEvent)
{
	GProcess *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GProcess *) RING_API_GETCPOINTER(1,"QProcess");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setreadyReadStandardOutputEvent(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QProcess_getreadyReadStandardErrorEvent)
{
	GProcess *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GProcess *) RING_API_GETCPOINTER(1,"QProcess");
	RING_API_RETSTRING(pObject->getreadyReadStandardErrorEvent());
}


RING_FUNC(ring_QProcess_getreadyReadStandardOutputEvent)
{
	GProcess *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GProcess *) RING_API_GETCPOINTER(1,"QProcess");
	RING_API_RETSTRING(pObject->getreadyReadStandardOutputEvent());
}


RING_FUNC(ring_QUuid_toString)
{
	QUuid *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QUuid *) RING_API_GETCPOINTER(1,"QUuid");
	RING_API_RETSTRING(pObject->toString().toStdString().c_str());
}


RING_FUNC(ring_QMutex_lock)
{
	QMutex *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QMutex *) RING_API_GETCPOINTER(1,"QMutex");
	pObject->lock();
}


RING_FUNC(ring_QMutex_unlock)
{
	QMutex *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QMutex *) RING_API_GETCPOINTER(1,"QMutex");
	pObject->unlock();
}

RING_FUNC(ring_QMutex_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	QMutex *pObject = new QMutex();
	RING_API_RETCPOINTER(pObject,"QMutex");
}

RING_FUNC(ring_QMutexLocker_mutex)
{
	QMutexLocker<QMutex> *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QMutexLocker<QMutex> *) RING_API_GETCPOINTER(1,"QMutexLocker");
	RING_API_RETCPOINTER(pObject->mutex(),"QMutex");
}


RING_FUNC(ring_QMutexLocker_relock)
{
	QMutexLocker<QMutex> *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QMutexLocker<QMutex> *) RING_API_GETCPOINTER(1,"QMutexLocker");
	pObject->relock();
}


RING_FUNC(ring_QMutexLocker_unlock)
{
	QMutexLocker<QMutex> *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QMutexLocker<QMutex> *) RING_API_GETCPOINTER(1,"QMutexLocker");
	pObject->unlock();
}


RING_FUNC(ring_QVersionNumber_isNormalized)
{
	QVersionNumber *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QVersionNumber *) RING_API_GETCPOINTER(1,"QVersionNumber");
	RING_API_RETNUMBER(pObject->isNormalized());
}


RING_FUNC(ring_QVersionNumber_isNull)
{
	QVersionNumber *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QVersionNumber *) RING_API_GETCPOINTER(1,"QVersionNumber");
	RING_API_RETNUMBER(pObject->isNull());
}


RING_FUNC(ring_QVersionNumber_isPrefixOf)
{
	QVersionNumber *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QVersionNumber *) RING_API_GETCPOINTER(1,"QVersionNumber");
	RING_API_RETNUMBER(pObject->isPrefixOf(* (QVersionNumber  *) RING_API_GETCPOINTER(2,"QVersionNumber")));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QVersionNumber"));
}


RING_FUNC(ring_QVersionNumber_majorVersion)
{
	QVersionNumber *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QVersionNumber *) RING_API_GETCPOINTER(1,"QVersionNumber");
	RING_API_RETNUMBER(pObject->majorVersion());
}


RING_FUNC(ring_QVersionNumber_microVersion)
{
	QVersionNumber *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QVersionNumber *) RING_API_GETCPOINTER(1,"QVersionNumber");
	RING_API_RETNUMBER(pObject->microVersion());
}


RING_FUNC(ring_QVersionNumber_minorVersion)
{
	QVersionNumber *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QVersionNumber *) RING_API_GETCPOINTER(1,"QVersionNumber");
	RING_API_RETNUMBER(pObject->minorVersion());
}


RING_FUNC(ring_QVersionNumber_normalized)
{
	QVersionNumber *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QVersionNumber *) RING_API_GETCPOINTER(1,"QVersionNumber");
	{
		QVersionNumber *pValue ; 
		pValue = new QVersionNumber() ;
		*pValue = pObject->normalized();
		RING_API_RETMANAGEDCPOINTER(pValue,"QVersionNumber",ring_QVersionNumber_freefunc);
	}
}


RING_FUNC(ring_QVersionNumber_segmentAt)
{
	QVersionNumber *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QVersionNumber *) RING_API_GETCPOINTER(1,"QVersionNumber");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->segmentAt( (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QVersionNumber_segmentCount)
{
	QVersionNumber *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QVersionNumber *) RING_API_GETCPOINTER(1,"QVersionNumber");
	RING_API_RETNUMBER(pObject->segmentCount());
}


RING_FUNC(ring_QVersionNumber_segments)
{
	QVersionNumber *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QVersionNumber *) RING_API_GETCPOINTER(1,"QVersionNumber");
	{
		QVector<int> *pValue ; 
		pValue = (QVector<int> *) RING_API_MALLOC(sizeof(QVector<int>)) ;
		*pValue = pObject->segments();
		RING_API_RETMANAGEDCPOINTER(pValue,"QVector<int>",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QVersionNumber_toString)
{
	QVersionNumber *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QVersionNumber *) RING_API_GETCPOINTER(1,"QVersionNumber");
	RING_API_RETSTRING(pObject->toString().toStdString().c_str());
}


RING_FUNC(ring_QLibraryInfo_isDebugBuild)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETNUMBER(QLibraryInfo::isDebugBuild());
}


RING_FUNC(ring_QLibraryInfo_version)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	{
		QVersionNumber *pValue ; 
		pValue = new QVersionNumber() ;
		*pValue = QLibraryInfo::version();
		RING_API_RETMANAGEDCPOINTER(pValue,"QVersionNumber",ring_QVersionNumber_freefunc);
	}
}


RING_FUNC(ring_QPixmap_transformed)
{
	QPixmap *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QPixmap *) RING_API_GETCPOINTER(1,"QPixmap");
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QPixmap *pValue ; 
		pValue = new QPixmap() ;
		*pValue = pObject->transformed(* (QTransform  *) RING_API_GETCPOINTER(2,"QTransform"), (Qt::TransformationMode )  (int) RING_API_GETNUMBER(3));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QTransform"));
		RING_API_RETMANAGEDCPOINTER(pValue,"QPixmap",ring_QPixmap_freefunc);
	}
}


RING_FUNC(ring_QPixmap_copy)
{
	QPixmap *pObject ;
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QPixmap *) RING_API_GETCPOINTER(1,"QPixmap");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QPixmap *pValue ; 
		pValue = new QPixmap() ;
		*pValue = pObject->copy( (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4), (int ) RING_API_GETNUMBER(5));
		RING_API_RETMANAGEDCPOINTER(pValue,"QPixmap",ring_QPixmap_freefunc);
	}
}


RING_FUNC(ring_QPixmap_scaled)
{
	QPixmap *pObject ;
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QPixmap *) RING_API_GETCPOINTER(1,"QPixmap");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QPixmap *pValue ; 
		pValue = new QPixmap() ;
		*pValue = pObject->scaled( (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3), (Qt::AspectRatioMode )  (int) RING_API_GETNUMBER(4), (Qt::TransformationMode )  (int) RING_API_GETNUMBER(5));
		RING_API_RETMANAGEDCPOINTER(pValue,"QPixmap",ring_QPixmap_freefunc);
	}
}


RING_FUNC(ring_QPixmap_width)
{
	QPixmap *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QPixmap *) RING_API_GETCPOINTER(1,"QPixmap");
	RING_API_RETNUMBER(pObject->width());
}


RING_FUNC(ring_QPixmap_height)
{
	QPixmap *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QPixmap *) RING_API_GETCPOINTER(1,"QPixmap");
	RING_API_RETNUMBER(pObject->height());
}


RING_FUNC(ring_QPixmap_createMaskFromColor)
{
	QPixmap *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QPixmap *) RING_API_GETCPOINTER(1,"QPixmap");
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QBitmap *pValue ; 
		pValue = (QBitmap *) RING_API_MALLOC(sizeof(QBitmap)) ;
		*pValue = pObject->createMaskFromColor(* (QColor *) RING_API_GETCPOINTER(2,"QColor"), (Qt::MaskMode)  (int) RING_API_GETNUMBER(3));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QColor"));
		RING_API_RETMANAGEDCPOINTER(pValue,"QBitmap",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QPixmap_mask)
{
	QPixmap *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QPixmap *) RING_API_GETCPOINTER(1,"QPixmap");
	{
		QBitmap *pValue ; 
		pValue = (QBitmap *) RING_API_MALLOC(sizeof(QBitmap)) ;
		*pValue = pObject->mask();
		RING_API_RETMANAGEDCPOINTER(pValue,"QBitmap",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QPixmap_setMask)
{
	QPixmap *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QPixmap *) RING_API_GETCPOINTER(1,"QPixmap");
	pObject->setMask(* (QBitmap *) RING_API_GETCPOINTER(2,"QBitmap"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QBitmap"));
}


RING_FUNC(ring_QPixmap_fill)
{
	QPixmap *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QPixmap *) RING_API_GETCPOINTER(1,"QPixmap");
	pObject->fill(* (QColor *) RING_API_GETCPOINTER(2,"QColor"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QColor"));
}


RING_FUNC(ring_QPixmap_fromImage)
{
	QPixmap *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QPixmap *) RING_API_GETCPOINTER(1,"QPixmap");
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QPixmap *pValue ; 
		pValue = new QPixmap() ;
		*pValue = pObject->fromImage(* (QImage *) RING_API_GETCPOINTER(2,"QImage"), (Qt::ImageConversionFlags)  (int) RING_API_GETNUMBER(3));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QImage"));
		RING_API_RETMANAGEDCPOINTER(pValue,"QPixmap",ring_QPixmap_freefunc);
	}
}


RING_FUNC(ring_QPixmap_load)
{
	QPixmap *pObject ;
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QPixmap *) RING_API_GETCPOINTER(1,"QPixmap");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->load(RING_API_GETSTRING(2),RING_API_GETSTRING(3), (Qt::ImageConversionFlags)  (int) RING_API_GETNUMBER(4)));
}


RING_FUNC(ring_QPixmap_cacheKey)
{
	QPixmap *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QPixmap *) RING_API_GETCPOINTER(1,"QPixmap");
	RING_API_RETNUMBER(pObject->cacheKey());
}


RING_FUNC(ring_QPixmap_convertFromImage)
{
	QPixmap *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QPixmap *) RING_API_GETCPOINTER(1,"QPixmap");
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->convertFromImage(* (QImage  *) RING_API_GETCPOINTER(2,"QImage"), (Qt::ImageConversionFlags )  (int) RING_API_GETNUMBER(3)));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QImage"));
}


RING_FUNC(ring_QPixmap_copy_2)
{
	QPixmap *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QPixmap *) RING_API_GETCPOINTER(1,"QPixmap");
	{
		QPixmap *pValue ; 
		pValue = new QPixmap() ;
		*pValue = pObject->copy(* (QRect  *) RING_API_GETCPOINTER(2,"QRect"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QRect"));
		RING_API_RETMANAGEDCPOINTER(pValue,"QPixmap",ring_QPixmap_freefunc);
	}
}


RING_FUNC(ring_QPixmap_createHeuristicMask)
{
	QPixmap *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QPixmap *) RING_API_GETCPOINTER(1,"QPixmap");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QBitmap *pValue ; 
		pValue = (QBitmap *) RING_API_MALLOC(sizeof(QBitmap)) ;
		*pValue = pObject->createHeuristicMask( (bool ) RING_API_GETNUMBER(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"QBitmap",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QPixmap_depth)
{
	QPixmap *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QPixmap *) RING_API_GETCPOINTER(1,"QPixmap");
	RING_API_RETNUMBER(pObject->depth());
}


RING_FUNC(ring_QPixmap_detach)
{
	QPixmap *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QPixmap *) RING_API_GETCPOINTER(1,"QPixmap");
	pObject->detach();
}


RING_FUNC(ring_QPixmap_devicePixelRatio)
{
	QPixmap *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QPixmap *) RING_API_GETCPOINTER(1,"QPixmap");
	RING_API_RETNUMBER(pObject->devicePixelRatio());
}


RING_FUNC(ring_QPixmap_hasAlpha)
{
	QPixmap *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QPixmap *) RING_API_GETCPOINTER(1,"QPixmap");
	RING_API_RETNUMBER(pObject->hasAlpha());
}


RING_FUNC(ring_QPixmap_hasAlphaChannel)
{
	QPixmap *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QPixmap *) RING_API_GETCPOINTER(1,"QPixmap");
	RING_API_RETNUMBER(pObject->hasAlphaChannel());
}


RING_FUNC(ring_QPixmap_isNull)
{
	QPixmap *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QPixmap *) RING_API_GETCPOINTER(1,"QPixmap");
	RING_API_RETNUMBER(pObject->isNull());
}


RING_FUNC(ring_QPixmap_isQBitmap)
{
	QPixmap *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QPixmap *) RING_API_GETCPOINTER(1,"QPixmap");
	RING_API_RETNUMBER(pObject->isQBitmap());
}


RING_FUNC(ring_QPixmap_loadFromData)
{
	QPixmap *pObject ;
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QPixmap *) RING_API_GETCPOINTER(1,"QPixmap");
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->loadFromData((uchar *) RING_API_GETCPOINTER(2,"uchar"), (uint ) RING_API_GETNUMBER(3),RING_API_GETSTRING(4), (Qt::ImageConversionFlags )  (int) RING_API_GETNUMBER(5)));
}


RING_FUNC(ring_QPixmap_loadFromData_2)
{
	QPixmap *pObject ;
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QPixmap *) RING_API_GETCPOINTER(1,"QPixmap");
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->loadFromData(* (QByteArray  *) RING_API_GETCPOINTER(2,"QByteArray"),RING_API_GETSTRING(3), (Qt::ImageConversionFlags )  (int) RING_API_GETNUMBER(4)));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QByteArray"));
}


RING_FUNC(ring_QPixmap_rect)
{
	QPixmap *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QPixmap *) RING_API_GETCPOINTER(1,"QPixmap");
	{
		QRect *pValue ; 
		pValue = (QRect *) RING_API_MALLOC(sizeof(QRect)) ;
		*pValue = pObject->rect();
		RING_API_RETMANAGEDCPOINTER(pValue,"QRect",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QPixmap_save)
{
	QPixmap *pObject ;
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QPixmap *) RING_API_GETCPOINTER(1,"QPixmap");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->save(RING_API_GETSTRING(2),RING_API_GETSTRING(3), (int ) RING_API_GETNUMBER(4)));
}


RING_FUNC(ring_QPixmap_save_2)
{
	QPixmap *pObject ;
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QPixmap *) RING_API_GETCPOINTER(1,"QPixmap");
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->save((QIODevice *) RING_API_GETCPOINTER(2,"QIODevice"),RING_API_GETSTRING(3), (int ) RING_API_GETNUMBER(4)));
}


RING_FUNC(ring_QPixmap_scaled_2)
{
	QPixmap *pObject ;
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QPixmap *) RING_API_GETCPOINTER(1,"QPixmap");
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QPixmap *pValue ; 
		pValue = new QPixmap() ;
		*pValue = pObject->scaled(* (QSize  *) RING_API_GETCPOINTER(2,"QSize"), (Qt::AspectRatioMode )  (int) RING_API_GETNUMBER(3), (Qt::TransformationMode )  (int) RING_API_GETNUMBER(4));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QSize"));
		RING_API_RETMANAGEDCPOINTER(pValue,"QPixmap",ring_QPixmap_freefunc);
	}
}


RING_FUNC(ring_QPixmap_scaledToHeight)
{
	QPixmap *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QPixmap *) RING_API_GETCPOINTER(1,"QPixmap");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QPixmap *pValue ; 
		pValue = new QPixmap() ;
		*pValue = pObject->scaledToHeight( (int ) RING_API_GETNUMBER(2), (Qt::TransformationMode )  (int) RING_API_GETNUMBER(3));
		RING_API_RETMANAGEDCPOINTER(pValue,"QPixmap",ring_QPixmap_freefunc);
	}
}


RING_FUNC(ring_QPixmap_scaledToWidth)
{
	QPixmap *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QPixmap *) RING_API_GETCPOINTER(1,"QPixmap");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QPixmap *pValue ; 
		pValue = new QPixmap() ;
		*pValue = pObject->scaledToWidth( (int ) RING_API_GETNUMBER(2), (Qt::TransformationMode )  (int) RING_API_GETNUMBER(3));
		RING_API_RETMANAGEDCPOINTER(pValue,"QPixmap",ring_QPixmap_freefunc);
	}
}


RING_FUNC(ring_QPixmap_scroll)
{
	QPixmap *pObject ;
	if ( RING_API_PARACOUNT != 8 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QPixmap *) RING_API_GETCPOINTER(1,"QPixmap");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(7) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(8) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->scroll( (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4), (int ) RING_API_GETNUMBER(5), (int ) RING_API_GETNUMBER(6), (int ) RING_API_GETNUMBER(7),(QRegion *) RING_API_GETCPOINTER(8,"QRegion"));
}


RING_FUNC(ring_QPixmap_scroll_2)
{
	QPixmap *pObject ;
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QPixmap *) RING_API_GETCPOINTER(1,"QPixmap");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->scroll( (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3),* (QRect  *) RING_API_GETCPOINTER(4,"QRect"),(QRegion *) RING_API_GETCPOINTER(5,"QRegion"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"QRect"));
}


RING_FUNC(ring_QPixmap_setDevicePixelRatio)
{
	QPixmap *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QPixmap *) RING_API_GETCPOINTER(1,"QPixmap");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setDevicePixelRatio( (qreal ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QPixmap_size)
{
	QPixmap *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QPixmap *) RING_API_GETCPOINTER(1,"QPixmap");
	{
		QSize *pValue ; 
		pValue = new QSize() ;
		*pValue = pObject->size();
		RING_API_RETMANAGEDCPOINTER(pValue,"QSize",ring_QSize_freefunc);
	}
}


RING_FUNC(ring_QPixmap_swap)
{
	QPixmap *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QPixmap *) RING_API_GETCPOINTER(1,"QPixmap");
	pObject->swap(* (QPixmap  *) RING_API_GETCPOINTER(2,"QPixmap"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QPixmap"));
}


RING_FUNC(ring_QPixmap_toImage)
{
	QPixmap *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QPixmap *) RING_API_GETCPOINTER(1,"QPixmap");
	{
		QImage *pValue ; 
		pValue = new QImage() ;
		*pValue = pObject->toImage();
		RING_API_RETMANAGEDCPOINTER(pValue,"QImage",ring_QImage_freefunc);
	}
}


RING_FUNC(ring_QPixmap_transformed_2)
{
	QPixmap *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QPixmap *) RING_API_GETCPOINTER(1,"QPixmap");
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QPixmap *pValue ; 
		pValue = new QPixmap() ;
		*pValue = pObject->transformed(* (QTransform  *) RING_API_GETCPOINTER(2,"QTransform"), (Qt::TransformationMode )  (int) RING_API_GETNUMBER(3));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QTransform"));
		RING_API_RETMANAGEDCPOINTER(pValue,"QPixmap",ring_QPixmap_freefunc);
	}
}


RING_FUNC(ring_QPixmap_defaultDepth)
{
	QPixmap *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QPixmap *) RING_API_GETCPOINTER(1,"QPixmap");
	RING_API_RETNUMBER(pObject->defaultDepth());
}


RING_FUNC(ring_QPixmap_fromImage_2)
{
	QPixmap *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QPixmap *) RING_API_GETCPOINTER(1,"QPixmap");
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QPixmap *pValue ; 
		pValue = new QPixmap() ;
		*pValue = pObject->fromImage(* (QImage  *) RING_API_GETCPOINTER(2,"QImage"), (Qt::ImageConversionFlags )  (int) RING_API_GETNUMBER(3));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QImage"));
		RING_API_RETMANAGEDCPOINTER(pValue,"QPixmap",ring_QPixmap_freefunc);
	}
}


RING_FUNC(ring_QPixmap_fromImageReader)
{
	QPixmap *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QPixmap *) RING_API_GETCPOINTER(1,"QPixmap");
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QPixmap *pValue ; 
		pValue = new QPixmap() ;
		*pValue = pObject->fromImageReader((QImageReader *) RING_API_GETCPOINTER(2,"QImageReader"), (Qt::ImageConversionFlags )  (int) RING_API_GETNUMBER(3));
		RING_API_RETMANAGEDCPOINTER(pValue,"QPixmap",ring_QPixmap_freefunc);
	}
}


RING_FUNC(ring_QPixmap_trueMatrix)
{
	QPixmap *pObject ;
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QPixmap *) RING_API_GETCPOINTER(1,"QPixmap");
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QTransform *pValue ; 
		pValue = (QTransform *) RING_API_MALLOC(sizeof(QTransform)) ;
		*pValue = pObject->trueMatrix(* (QTransform  *) RING_API_GETCPOINTER(2,"QTransform"), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QTransform"));
		RING_API_RETMANAGEDCPOINTER(pValue,"QTransform",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QPicture_boundingRect)
{
	QPicture *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QPicture *) RING_API_GETCPOINTER(1,"QPicture");
	{
		QRect *pValue ; 
		pValue = (QRect *) RING_API_MALLOC(sizeof(QRect)) ;
		*pValue = pObject->boundingRect();
		RING_API_RETMANAGEDCPOINTER(pValue,"QRect",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QPicture_data)
{
	QPicture *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QPicture *) RING_API_GETCPOINTER(1,"QPicture");
	RING_API_RETSTRING(pObject->data());
}


RING_FUNC(ring_QPicture_isNull)
{
	QPicture *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QPicture *) RING_API_GETCPOINTER(1,"QPicture");
	RING_API_RETNUMBER(pObject->isNull());
}


RING_FUNC(ring_QPicture_load)
{
	QPicture *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QPicture *) RING_API_GETCPOINTER(1,"QPicture");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->load(RING_API_GETSTRING(2)));
}


RING_FUNC(ring_QPicture_play)
{
	QPicture *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QPicture *) RING_API_GETCPOINTER(1,"QPicture");
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->play((QPainter *) RING_API_GETCPOINTER(2,"QPainter")));
}


RING_FUNC(ring_QPicture_save)
{
	QPicture *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QPicture *) RING_API_GETCPOINTER(1,"QPicture");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->save(RING_API_GETSTRING(2)));
}


RING_FUNC(ring_QPicture_setBoundingRect)
{
	QPicture *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QPicture *) RING_API_GETCPOINTER(1,"QPicture");
	pObject->setBoundingRect(* (QRect *) RING_API_GETCPOINTER(2,"QRect"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QRect"));
}


RING_FUNC(ring_QPicture_size)
{
	QPicture *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QPicture *) RING_API_GETCPOINTER(1,"QPicture");
	RING_API_RETNUMBER(pObject->size());
}


RING_FUNC(ring_QPicture_swap)
{
	QPicture *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QPicture *) RING_API_GETCPOINTER(1,"QPicture");
	pObject->swap(* (QPicture *) RING_API_GETCPOINTER(2,"QPicture"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QPicture"));
}


RING_FUNC(ring_QFont_bold)
{
	QFont *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFont *) RING_API_GETCPOINTER(1,"QFont");
	RING_API_RETNUMBER(pObject->bold());
}


RING_FUNC(ring_QFont_capitalization)
{
	QFont *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFont *) RING_API_GETCPOINTER(1,"QFont");
	RING_API_RETNUMBER(pObject->capitalization());
}


RING_FUNC(ring_QFont_defaultFamily)
{
	QFont *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFont *) RING_API_GETCPOINTER(1,"QFont");
	RING_API_RETSTRING(pObject->defaultFamily().toStdString().c_str());
}


RING_FUNC(ring_QFont_exactMatch)
{
	QFont *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFont *) RING_API_GETCPOINTER(1,"QFont");
	RING_API_RETNUMBER(pObject->exactMatch());
}


RING_FUNC(ring_QFont_family)
{
	QFont *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFont *) RING_API_GETCPOINTER(1,"QFont");
	RING_API_RETSTRING(pObject->family().toStdString().c_str());
}


RING_FUNC(ring_QFont_fixedPitch)
{
	QFont *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFont *) RING_API_GETCPOINTER(1,"QFont");
	RING_API_RETNUMBER(pObject->fixedPitch());
}


RING_FUNC(ring_QFont_fromString)
{
	QFont *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFont *) RING_API_GETCPOINTER(1,"QFont");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->fromString(RING_API_GETSTRING(2)));
}


RING_FUNC(ring_QFont_hintingPreference)
{
	QFont *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFont *) RING_API_GETCPOINTER(1,"QFont");
	RING_API_RETNUMBER(pObject->hintingPreference());
}


RING_FUNC(ring_QFont_isCopyOf)
{
	QFont *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFont *) RING_API_GETCPOINTER(1,"QFont");
	RING_API_RETNUMBER(pObject->isCopyOf(* (QFont *) RING_API_GETCPOINTER(2,"QFont")));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QFont"));
}


RING_FUNC(ring_QFont_italic)
{
	QFont *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFont *) RING_API_GETCPOINTER(1,"QFont");
	RING_API_RETNUMBER(pObject->italic());
}


RING_FUNC(ring_QFont_kerning)
{
	QFont *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFont *) RING_API_GETCPOINTER(1,"QFont");
	RING_API_RETNUMBER(pObject->kerning());
}


RING_FUNC(ring_QFont_key)
{
	QFont *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFont *) RING_API_GETCPOINTER(1,"QFont");
	RING_API_RETSTRING(pObject->key().toStdString().c_str());
}


RING_FUNC(ring_QFont_letterSpacing)
{
	QFont *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFont *) RING_API_GETCPOINTER(1,"QFont");
	RING_API_RETNUMBER(pObject->letterSpacing());
}


RING_FUNC(ring_QFont_letterSpacingType)
{
	QFont *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFont *) RING_API_GETCPOINTER(1,"QFont");
	RING_API_RETNUMBER(pObject->letterSpacingType());
}


RING_FUNC(ring_QFont_overline)
{
	QFont *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFont *) RING_API_GETCPOINTER(1,"QFont");
	RING_API_RETNUMBER(pObject->overline());
}


RING_FUNC(ring_QFont_pixelSize)
{
	QFont *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFont *) RING_API_GETCPOINTER(1,"QFont");
	RING_API_RETNUMBER(pObject->pixelSize());
}


RING_FUNC(ring_QFont_pointSize)
{
	QFont *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFont *) RING_API_GETCPOINTER(1,"QFont");
	RING_API_RETNUMBER(pObject->pointSize());
}


RING_FUNC(ring_QFont_pointSizeF)
{
	QFont *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFont *) RING_API_GETCPOINTER(1,"QFont");
	RING_API_RETNUMBER(pObject->pointSizeF());
}


RING_FUNC(ring_QFont_resolve)
{
	QFont *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFont *) RING_API_GETCPOINTER(1,"QFont");
	{
		QFont *pValue ; 
		pValue = new QFont() ;
		*pValue = pObject->resolve(* (QFont *) RING_API_GETCPOINTER(2,"QFont"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QFont"));
		RING_API_RETMANAGEDCPOINTER(pValue,"QFont",ring_QFont_freefunc);
	}
}


RING_FUNC(ring_QFont_setBold)
{
	QFont *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFont *) RING_API_GETCPOINTER(1,"QFont");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setBold( (bool ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QFont_setCapitalization)
{
	QFont *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFont *) RING_API_GETCPOINTER(1,"QFont");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setCapitalization( (QFont::Capitalization )  (int) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QFont_setFamily)
{
	QFont *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFont *) RING_API_GETCPOINTER(1,"QFont");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setFamily(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QFont_setFixedPitch)
{
	QFont *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFont *) RING_API_GETCPOINTER(1,"QFont");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setFixedPitch( (bool ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QFont_setHintingPreference)
{
	QFont *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFont *) RING_API_GETCPOINTER(1,"QFont");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setHintingPreference( (QFont::HintingPreference )  (int) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QFont_setItalic)
{
	QFont *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFont *) RING_API_GETCPOINTER(1,"QFont");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setItalic( (bool ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QFont_setKerning)
{
	QFont *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFont *) RING_API_GETCPOINTER(1,"QFont");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setKerning( (bool ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QFont_setLetterSpacing)
{
	QFont *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFont *) RING_API_GETCPOINTER(1,"QFont");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setLetterSpacing( (QFont::SpacingType )  (int) RING_API_GETNUMBER(2), (double ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_QFont_setOverline)
{
	QFont *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFont *) RING_API_GETCPOINTER(1,"QFont");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setOverline( (bool ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QFont_setPixelSize)
{
	QFont *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFont *) RING_API_GETCPOINTER(1,"QFont");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setPixelSize( (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QFont_setPointSize)
{
	QFont *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFont *) RING_API_GETCPOINTER(1,"QFont");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setPointSize( (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QFont_setPointSizeF)
{
	QFont *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFont *) RING_API_GETCPOINTER(1,"QFont");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setPointSizeF( (double ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QFont_setStretch)
{
	QFont *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFont *) RING_API_GETCPOINTER(1,"QFont");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setStretch( (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QFont_setStrikeOut)
{
	QFont *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFont *) RING_API_GETCPOINTER(1,"QFont");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setStrikeOut( (bool ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QFont_setStyle)
{
	QFont *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFont *) RING_API_GETCPOINTER(1,"QFont");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setStyle( (QFont::Style )  (int) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QFont_setStyleHint)
{
	QFont *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFont *) RING_API_GETCPOINTER(1,"QFont");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setStyleHint( (QFont::StyleHint )  (int) RING_API_GETNUMBER(2), (QFont::StyleStrategy )  (int) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_QFont_setStyleName)
{
	QFont *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFont *) RING_API_GETCPOINTER(1,"QFont");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setStyleName(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QFont_setStyleStrategy)
{
	QFont *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFont *) RING_API_GETCPOINTER(1,"QFont");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setStyleStrategy( (QFont::StyleStrategy )  (int) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QFont_setUnderline)
{
	QFont *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFont *) RING_API_GETCPOINTER(1,"QFont");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setUnderline( (bool ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QFont_setWeight)
{
	QFont *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFont *) RING_API_GETCPOINTER(1,"QFont");
	pObject->setWeight(* (QFont::Weight  *) RING_API_GETCPOINTER(2,"QFont::Weight"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QFont::Weight"));
}


RING_FUNC(ring_QFont_setWordSpacing)
{
	QFont *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFont *) RING_API_GETCPOINTER(1,"QFont");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setWordSpacing( (double ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QFont_stretch)
{
	QFont *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFont *) RING_API_GETCPOINTER(1,"QFont");
	RING_API_RETNUMBER(pObject->stretch());
}


RING_FUNC(ring_QFont_strikeOut)
{
	QFont *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFont *) RING_API_GETCPOINTER(1,"QFont");
	RING_API_RETNUMBER(pObject->strikeOut());
}


RING_FUNC(ring_QFont_style)
{
	QFont *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFont *) RING_API_GETCPOINTER(1,"QFont");
	RING_API_RETNUMBER(pObject->style());
}


RING_FUNC(ring_QFont_styleHint)
{
	QFont *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFont *) RING_API_GETCPOINTER(1,"QFont");
	RING_API_RETNUMBER(pObject->styleHint());
}


RING_FUNC(ring_QFont_styleName)
{
	QFont *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFont *) RING_API_GETCPOINTER(1,"QFont");
	RING_API_RETSTRING(pObject->styleName().toStdString().c_str());
}


RING_FUNC(ring_QFont_styleStrategy)
{
	QFont *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFont *) RING_API_GETCPOINTER(1,"QFont");
	RING_API_RETNUMBER(pObject->styleStrategy());
}


RING_FUNC(ring_QFont_toString)
{
	QFont *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFont *) RING_API_GETCPOINTER(1,"QFont");
	RING_API_RETSTRING(pObject->toString().toStdString().c_str());
}


RING_FUNC(ring_QFont_underline)
{
	QFont *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFont *) RING_API_GETCPOINTER(1,"QFont");
	RING_API_RETNUMBER(pObject->underline());
}


RING_FUNC(ring_QFont_weight)
{
	QFont *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFont *) RING_API_GETCPOINTER(1,"QFont");
	RING_API_RETNUMBER(pObject->weight());
}


RING_FUNC(ring_QFont_wordSpacing)
{
	QFont *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFont *) RING_API_GETCPOINTER(1,"QFont");
	RING_API_RETNUMBER(pObject->wordSpacing());
}


RING_FUNC(ring_QFont_insertSubstitution)
{
	QFont *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFont *) RING_API_GETCPOINTER(1,"QFont");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->insertSubstitution(RING_API_GETSTRING(2),RING_API_GETSTRING(3));
}


RING_FUNC(ring_QFont_insertSubstitutions)
{
	QFont *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFont *) RING_API_GETCPOINTER(1,"QFont");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->insertSubstitutions(RING_API_GETSTRING(2),* (QStringList *) RING_API_GETCPOINTER(3,"QStringList"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"QStringList"));
}


RING_FUNC(ring_QFont_substitute)
{
	QFont *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFont *) RING_API_GETCPOINTER(1,"QFont");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->substitute(RING_API_GETSTRING(2)).toStdString().c_str());
}


RING_FUNC(ring_QFont_substitutes)
{
	QFont *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFont *) RING_API_GETCPOINTER(1,"QFont");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QStringList *pValue ; 
		pValue = new QStringList() ;
		*pValue = pObject->substitutes(RING_API_GETSTRING(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"QStringList",ring_QStringList_freefunc);
	}
}


RING_FUNC(ring_QFont_substitutions)
{
	QFont *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFont *) RING_API_GETCPOINTER(1,"QFont");
	{
		QStringList *pValue ; 
		pValue = new QStringList() ;
		*pValue = pObject->substitutions();
		RING_API_RETMANAGEDCPOINTER(pValue,"QStringList",ring_QStringList_freefunc);
	}
}


RING_FUNC(ring_QImage_allGray)
{
	QImage *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QImage *) RING_API_GETCPOINTER(1,"QImage");
	RING_API_RETNUMBER(pObject->allGray());
}


RING_FUNC(ring_QImage_bitPlaneCount)
{
	QImage *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QImage *) RING_API_GETCPOINTER(1,"QImage");
	RING_API_RETNUMBER(pObject->bitPlaneCount());
}


RING_FUNC(ring_QImage_bits)
{
	QImage *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QImage *) RING_API_GETCPOINTER(1,"QImage");
	RING_API_RETCPOINTER(pObject->bits(),"uchar");
}


RING_FUNC(ring_QImage_bytesPerLine)
{
	QImage *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QImage *) RING_API_GETCPOINTER(1,"QImage");
	RING_API_RETNUMBER(pObject->bytesPerLine());
}


RING_FUNC(ring_QImage_cacheKey)
{
	QImage *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QImage *) RING_API_GETCPOINTER(1,"QImage");
	RING_API_RETNUMBER(pObject->cacheKey());
}


RING_FUNC(ring_QImage_color)
{
	QImage *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QImage *) RING_API_GETCPOINTER(1,"QImage");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QRgb *pValue ; 
		pValue = (QRgb *) RING_API_MALLOC(sizeof(QRgb)) ;
		*pValue = pObject->color( (int ) RING_API_GETNUMBER(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"QRgb",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QImage_colorCount)
{
	QImage *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QImage *) RING_API_GETCPOINTER(1,"QImage");
	RING_API_RETNUMBER(pObject->colorCount());
}


RING_FUNC(ring_QImage_constBits)
{
	QImage *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QImage *) RING_API_GETCPOINTER(1,"QImage");
	RING_API_RETCPOINTER(pObject->constBits(),"uchar");
}


RING_FUNC(ring_QImage_constScanLine)
{
	QImage *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QImage *) RING_API_GETCPOINTER(1,"QImage");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(pObject->constScanLine( (int ) RING_API_GETNUMBER(2)),"uchar");
}


RING_FUNC(ring_QImage_convertToFormat)
{
	QImage *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QImage *) RING_API_GETCPOINTER(1,"QImage");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QImage *pValue ; 
		pValue = new QImage() ;
		*pValue = pObject->convertToFormat( (QImage::Format )  (int) RING_API_GETNUMBER(2), (Qt::ImageConversionFlags )  (int) RING_API_GETNUMBER(3));
		RING_API_RETMANAGEDCPOINTER(pValue,"QImage",ring_QImage_freefunc);
	}
}


RING_FUNC(ring_QImage_copy)
{
	QImage *pObject ;
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QImage *) RING_API_GETCPOINTER(1,"QImage");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QImage *pValue ; 
		pValue = new QImage() ;
		*pValue = pObject->copy( (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4), (int ) RING_API_GETNUMBER(5));
		RING_API_RETMANAGEDCPOINTER(pValue,"QImage",ring_QImage_freefunc);
	}
}


RING_FUNC(ring_QImage_createAlphaMask)
{
	QImage *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QImage *) RING_API_GETCPOINTER(1,"QImage");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QImage *pValue ; 
		pValue = new QImage() ;
		*pValue = pObject->createAlphaMask( (Qt::ImageConversionFlags )  (int) RING_API_GETNUMBER(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"QImage",ring_QImage_freefunc);
	}
}


RING_FUNC(ring_QImage_createHeuristicMask)
{
	QImage *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QImage *) RING_API_GETCPOINTER(1,"QImage");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QImage *pValue ; 
		pValue = new QImage() ;
		*pValue = pObject->createHeuristicMask( (bool ) RING_API_GETNUMBER(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"QImage",ring_QImage_freefunc);
	}
}


RING_FUNC(ring_QImage_createMaskFromColor)
{
	QImage *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QImage *) RING_API_GETCPOINTER(1,"QImage");
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QImage *pValue ; 
		pValue = new QImage() ;
		*pValue = pObject->createMaskFromColor(* (QRgb  *) RING_API_GETCPOINTER(2,"QRgb"), (Qt::MaskMode )  (int) RING_API_GETNUMBER(3));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QRgb"));
		RING_API_RETMANAGEDCPOINTER(pValue,"QImage",ring_QImage_freefunc);
	}
}


RING_FUNC(ring_QImage_depth)
{
	QImage *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QImage *) RING_API_GETCPOINTER(1,"QImage");
	RING_API_RETNUMBER(pObject->depth());
}


RING_FUNC(ring_QImage_dotsPerMeterX)
{
	QImage *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QImage *) RING_API_GETCPOINTER(1,"QImage");
	RING_API_RETNUMBER(pObject->dotsPerMeterX());
}


RING_FUNC(ring_QImage_dotsPerMeterY)
{
	QImage *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QImage *) RING_API_GETCPOINTER(1,"QImage");
	RING_API_RETNUMBER(pObject->dotsPerMeterY());
}


RING_FUNC(ring_QImage_fill)
{
	QImage *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QImage *) RING_API_GETCPOINTER(1,"QImage");
	pObject->fill(* (QColor *) RING_API_GETCPOINTER(2,"QColor"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QColor"));
}


RING_FUNC(ring_QImage_format)
{
	QImage *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QImage *) RING_API_GETCPOINTER(1,"QImage");
	RING_API_RETNUMBER(pObject->format());
}


RING_FUNC(ring_QImage_hasAlphaChannel)
{
	QImage *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QImage *) RING_API_GETCPOINTER(1,"QImage");
	RING_API_RETNUMBER(pObject->hasAlphaChannel());
}


RING_FUNC(ring_QImage_height)
{
	QImage *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QImage *) RING_API_GETCPOINTER(1,"QImage");
	RING_API_RETNUMBER(pObject->height());
}


RING_FUNC(ring_QImage_invertPixels)
{
	QImage *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QImage *) RING_API_GETCPOINTER(1,"QImage");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->invertPixels( (QImage::InvertMode )  (int) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QImage_isGrayscale)
{
	QImage *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QImage *) RING_API_GETCPOINTER(1,"QImage");
	RING_API_RETNUMBER(pObject->isGrayscale());
}


RING_FUNC(ring_QImage_isNull)
{
	QImage *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QImage *) RING_API_GETCPOINTER(1,"QImage");
	RING_API_RETNUMBER(pObject->isNull());
}


RING_FUNC(ring_QImage_load)
{
	QImage *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QImage *) RING_API_GETCPOINTER(1,"QImage");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->load(RING_API_GETSTRING(2),RING_API_GETSTRING(3)));
}


RING_FUNC(ring_QImage_loadFromData)
{
	QImage *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QImage *) RING_API_GETCPOINTER(1,"QImage");
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->loadFromData(* (QByteArray *) RING_API_GETCPOINTER(2,"QByteArray"),RING_API_GETSTRING(3)));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QByteArray"));
}


RING_FUNC(ring_QImage_mirrored)
{
	QImage *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QImage *) RING_API_GETCPOINTER(1,"QImage");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QImage *pValue ; 
		pValue = new QImage() ;
		*pValue = pObject->mirrored( (bool ) RING_API_GETNUMBER(2), (bool ) RING_API_GETNUMBER(3));
		RING_API_RETMANAGEDCPOINTER(pValue,"QImage",ring_QImage_freefunc);
	}
}


RING_FUNC(ring_QImage_offset)
{
	QImage *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QImage *) RING_API_GETCPOINTER(1,"QImage");
	{
		QPoint *pValue ; 
		pValue = (QPoint *) RING_API_MALLOC(sizeof(QPoint)) ;
		*pValue = pObject->offset();
		RING_API_RETMANAGEDCPOINTER(pValue,"QPoint",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QImage_pixel)
{
	QImage *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QImage *) RING_API_GETCPOINTER(1,"QImage");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QRgb *pValue ; 
		pValue = (QRgb *) RING_API_MALLOC(sizeof(QRgb)) ;
		*pValue = pObject->pixel( (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3));
		RING_API_RETMANAGEDCPOINTER(pValue,"QRgb",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QImage_pixelIndex)
{
	QImage *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QImage *) RING_API_GETCPOINTER(1,"QImage");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->pixelIndex( (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_QImage_rect)
{
	QImage *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QImage *) RING_API_GETCPOINTER(1,"QImage");
	{
		QRect *pValue ; 
		pValue = (QRect *) RING_API_MALLOC(sizeof(QRect)) ;
		*pValue = pObject->rect();
		RING_API_RETMANAGEDCPOINTER(pValue,"QRect",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QImage_rgbSwapped)
{
	QImage *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QImage *) RING_API_GETCPOINTER(1,"QImage");
	{
		QImage *pValue ; 
		pValue = new QImage() ;
		*pValue = pObject->rgbSwapped();
		RING_API_RETMANAGEDCPOINTER(pValue,"QImage",ring_QImage_freefunc);
	}
}


RING_FUNC(ring_QImage_save)
{
	QImage *pObject ;
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QImage *) RING_API_GETCPOINTER(1,"QImage");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->save(RING_API_GETSTRING(2),RING_API_GETSTRING(3), (int ) RING_API_GETNUMBER(4)));
}


RING_FUNC(ring_QImage_scaled)
{
	QImage *pObject ;
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QImage *) RING_API_GETCPOINTER(1,"QImage");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QImage *pValue ; 
		pValue = new QImage() ;
		*pValue = pObject->scaled( (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3), (Qt::AspectRatioMode )  (int) RING_API_GETNUMBER(4), (Qt::TransformationMode )  (int) RING_API_GETNUMBER(5));
		RING_API_RETMANAGEDCPOINTER(pValue,"QImage",ring_QImage_freefunc);
	}
}


RING_FUNC(ring_QImage_scaledToHeight)
{
	QImage *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QImage *) RING_API_GETCPOINTER(1,"QImage");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QImage *pValue ; 
		pValue = new QImage() ;
		*pValue = pObject->scaledToHeight( (int ) RING_API_GETNUMBER(2), (Qt::TransformationMode )  (int) RING_API_GETNUMBER(3));
		RING_API_RETMANAGEDCPOINTER(pValue,"QImage",ring_QImage_freefunc);
	}
}


RING_FUNC(ring_QImage_scaledToWidth)
{
	QImage *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QImage *) RING_API_GETCPOINTER(1,"QImage");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QImage *pValue ; 
		pValue = new QImage() ;
		*pValue = pObject->scaledToWidth( (int ) RING_API_GETNUMBER(2), (Qt::TransformationMode )  (int) RING_API_GETNUMBER(3));
		RING_API_RETMANAGEDCPOINTER(pValue,"QImage",ring_QImage_freefunc);
	}
}


RING_FUNC(ring_QImage_scanLine)
{
	QImage *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QImage *) RING_API_GETCPOINTER(1,"QImage");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(pObject->scanLine( (int ) RING_API_GETNUMBER(2)),"uchar");
}


RING_FUNC(ring_QImage_setColor)
{
	QImage *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QImage *) RING_API_GETCPOINTER(1,"QImage");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setColor( (int ) RING_API_GETNUMBER(2),* (QRgb  *) RING_API_GETCPOINTER(3,"QRgb"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"QRgb"));
}


RING_FUNC(ring_QImage_setColorCount)
{
	QImage *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QImage *) RING_API_GETCPOINTER(1,"QImage");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setColorCount( (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QImage_setDotsPerMeterX)
{
	QImage *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QImage *) RING_API_GETCPOINTER(1,"QImage");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setDotsPerMeterX( (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QImage_setDotsPerMeterY)
{
	QImage *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QImage *) RING_API_GETCPOINTER(1,"QImage");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setDotsPerMeterY( (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QImage_setOffset)
{
	QImage *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QImage *) RING_API_GETCPOINTER(1,"QImage");
	pObject->setOffset(* (QPoint *) RING_API_GETCPOINTER(2,"QPoint"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QPoint"));
}


RING_FUNC(ring_QImage_setPixel)
{
	QImage *pObject ;
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QImage *) RING_API_GETCPOINTER(1,"QImage");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setPixel( (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3), (uint ) RING_API_GETNUMBER(4));
}


RING_FUNC(ring_QImage_setText)
{
	QImage *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QImage *) RING_API_GETCPOINTER(1,"QImage");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setText(RING_API_GETSTRING(2),RING_API_GETSTRING(3));
}


RING_FUNC(ring_QImage_size)
{
	QImage *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QImage *) RING_API_GETCPOINTER(1,"QImage");
	{
		QSize *pValue ; 
		pValue = new QSize() ;
		*pValue = pObject->size();
		RING_API_RETMANAGEDCPOINTER(pValue,"QSize",ring_QSize_freefunc);
	}
}


RING_FUNC(ring_QImage_swap)
{
	QImage *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QImage *) RING_API_GETCPOINTER(1,"QImage");
	pObject->swap(* (QImage *) RING_API_GETCPOINTER(2,"QImage"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QImage"));
}


RING_FUNC(ring_QImage_text)
{
	QImage *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QImage *) RING_API_GETCPOINTER(1,"QImage");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->text(RING_API_GETSTRING(2)).toStdString().c_str());
}


RING_FUNC(ring_QImage_textKeys)
{
	QImage *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QImage *) RING_API_GETCPOINTER(1,"QImage");
	{
		QStringList *pValue ; 
		pValue = new QStringList() ;
		*pValue = pObject->textKeys();
		RING_API_RETMANAGEDCPOINTER(pValue,"QStringList",ring_QStringList_freefunc);
	}
}


RING_FUNC(ring_QImage_valid)
{
	QImage *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QImage *) RING_API_GETCPOINTER(1,"QImage");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->valid( (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_QImage_width)
{
	QImage *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QImage *) RING_API_GETCPOINTER(1,"QImage");
	RING_API_RETNUMBER(pObject->width());
}


RING_FUNC(ring_QWindow_baseSize)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	{
		QSize *pValue ; 
		pValue = new QSize() ;
		*pValue = pObject->baseSize();
		RING_API_RETMANAGEDCPOINTER(pValue,"QSize",ring_QSize_freefunc);
	}
}


RING_FUNC(ring_QWindow_contentOrientation)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	{
		Qt::ScreenOrientation *pValue ; 
		pValue = (Qt::ScreenOrientation *) RING_API_MALLOC(sizeof(Qt::ScreenOrientation)) ;
		*pValue = pObject->contentOrientation();
		RING_API_RETMANAGEDCPOINTER(pValue,"Qt::ScreenOrientation",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QWindow_create)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	pObject->create();
}


RING_FUNC(ring_QWindow_cursor)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	{
		QCursor *pValue ; 
		pValue = (QCursor *) RING_API_MALLOC(sizeof(QCursor)) ;
		*pValue = pObject->cursor();
		RING_API_RETMANAGEDCPOINTER(pValue,"QCursor",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QWindow_destroy)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	pObject->destroy();
}


RING_FUNC(ring_QWindow_devicePixelRatio)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	RING_API_RETNUMBER(pObject->devicePixelRatio());
}


RING_FUNC(ring_QWindow_filePath)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	RING_API_RETSTRING(pObject->filePath().toStdString().c_str());
}


RING_FUNC(ring_QWindow_flags)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	RING_API_RETNUMBER(pObject->flags());
}


RING_FUNC(ring_QWindow_focusObject)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	RING_API_RETCPOINTER(pObject->focusObject(),"QObject");
}


RING_FUNC(ring_QWindow_frameGeometry)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	{
		QRect *pValue ; 
		pValue = (QRect *) RING_API_MALLOC(sizeof(QRect)) ;
		*pValue = pObject->frameGeometry();
		RING_API_RETMANAGEDCPOINTER(pValue,"QRect",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QWindow_frameMargins)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	{
		QMargins *pValue ; 
		pValue = (QMargins *) RING_API_MALLOC(sizeof(QMargins)) ;
		*pValue = pObject->frameMargins();
		RING_API_RETMANAGEDCPOINTER(pValue,"QMargins",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QWindow_framePosition)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	{
		QPoint *pValue ; 
		pValue = (QPoint *) RING_API_MALLOC(sizeof(QPoint)) ;
		*pValue = pObject->framePosition();
		RING_API_RETMANAGEDCPOINTER(pValue,"QPoint",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QWindow_geometry)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	{
		QRect *pValue ; 
		pValue = (QRect *) RING_API_MALLOC(sizeof(QRect)) ;
		*pValue = pObject->geometry();
		RING_API_RETMANAGEDCPOINTER(pValue,"QRect",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QWindow_height)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	RING_API_RETNUMBER(pObject->height());
}


RING_FUNC(ring_QWindow_icon)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	{
		QIcon *pValue ; 
		pValue = new QIcon() ;
		*pValue = pObject->icon();
		RING_API_RETMANAGEDCPOINTER(pValue,"QIcon",ring_QIcon_freefunc);
	}
}


RING_FUNC(ring_QWindow_isActive)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	RING_API_RETNUMBER(pObject->isActive());
}


RING_FUNC(ring_QWindow_isAncestorOf)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->isAncestorOf((QWindow *) RING_API_GETCPOINTER(2,"QWindow"), (QWindow::AncestorMode )  (int) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_QWindow_isExposed)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	RING_API_RETNUMBER(pObject->isExposed());
}


RING_FUNC(ring_QWindow_isModal)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	RING_API_RETNUMBER(pObject->isModal());
}


RING_FUNC(ring_QWindow_isTopLevel)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	RING_API_RETNUMBER(pObject->isTopLevel());
}


RING_FUNC(ring_QWindow_isVisible)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	RING_API_RETNUMBER(pObject->isVisible());
}


RING_FUNC(ring_QWindow_mapFromGlobal)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	{
		QPoint *pValue ; 
		pValue = (QPoint *) RING_API_MALLOC(sizeof(QPoint)) ;
		*pValue = pObject->mapFromGlobal(* (QPoint  *) RING_API_GETCPOINTER(2,"QPoint"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QPoint"));
		RING_API_RETMANAGEDCPOINTER(pValue,"QPoint",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QWindow_mapToGlobal)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	{
		QPoint *pValue ; 
		pValue = (QPoint *) RING_API_MALLOC(sizeof(QPoint)) ;
		*pValue = pObject->mapToGlobal(* (QPoint  *) RING_API_GETCPOINTER(2,"QPoint"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QPoint"));
		RING_API_RETMANAGEDCPOINTER(pValue,"QPoint",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QWindow_mask)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	{
		QRegion *pValue ; 
		pValue = (QRegion *) RING_API_MALLOC(sizeof(QRegion)) ;
		*pValue = pObject->mask();
		RING_API_RETMANAGEDCPOINTER(pValue,"QRegion",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QWindow_maximumHeight)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	RING_API_RETNUMBER(pObject->maximumHeight());
}


RING_FUNC(ring_QWindow_maximumSize)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	{
		QSize *pValue ; 
		pValue = new QSize() ;
		*pValue = pObject->maximumSize();
		RING_API_RETMANAGEDCPOINTER(pValue,"QSize",ring_QSize_freefunc);
	}
}


RING_FUNC(ring_QWindow_maximumWidth)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	RING_API_RETNUMBER(pObject->maximumWidth());
}


RING_FUNC(ring_QWindow_minimumHeight)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	RING_API_RETNUMBER(pObject->minimumHeight());
}


RING_FUNC(ring_QWindow_minimumSize)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	{
		QSize *pValue ; 
		pValue = new QSize() ;
		*pValue = pObject->minimumSize();
		RING_API_RETMANAGEDCPOINTER(pValue,"QSize",ring_QSize_freefunc);
	}
}


RING_FUNC(ring_QWindow_minimumWidth)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	RING_API_RETNUMBER(pObject->minimumWidth());
}


RING_FUNC(ring_QWindow_modality)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	RING_API_RETNUMBER(pObject->modality());
}


RING_FUNC(ring_QWindow_opacity)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	RING_API_RETNUMBER(pObject->opacity());
}


RING_FUNC(ring_QWindow_position)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	{
		QPoint *pValue ; 
		pValue = (QPoint *) RING_API_MALLOC(sizeof(QPoint)) ;
		*pValue = pObject->position();
		RING_API_RETMANAGEDCPOINTER(pValue,"QPoint",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QWindow_reportContentOrientationChange)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	pObject->reportContentOrientationChange(* (Qt::ScreenOrientation  *) RING_API_GETCPOINTER(2,"Qt::ScreenOrientation"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Qt::ScreenOrientation"));
}


RING_FUNC(ring_QWindow_requestedFormat)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	{
		QSurfaceFormat *pValue ; 
		pValue = (QSurfaceFormat *) RING_API_MALLOC(sizeof(QSurfaceFormat)) ;
		*pValue = pObject->requestedFormat();
		RING_API_RETMANAGEDCPOINTER(pValue,"QSurfaceFormat",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QWindow_resize)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	pObject->resize(* (QSize  *) RING_API_GETCPOINTER(2,"QSize"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QSize"));
}


RING_FUNC(ring_QWindow_resize_2)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->resize( (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_QWindow_screen)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	RING_API_RETCPOINTER(pObject->screen(),"QScreen");
}


RING_FUNC(ring_QWindow_setBaseSize)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	pObject->setBaseSize(* (QSize  *) RING_API_GETCPOINTER(2,"QSize"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QSize"));
}


RING_FUNC(ring_QWindow_setCursor)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	pObject->setCursor(* (QCursor  *) RING_API_GETCPOINTER(2,"QCursor"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QCursor"));
}


RING_FUNC(ring_QWindow_setFilePath)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setFilePath(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QWindow_setFlags)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setFlags( (Qt::WindowFlags )  (int) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QWindow_setFormat)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	pObject->setFormat(* (QSurfaceFormat  *) RING_API_GETCPOINTER(2,"QSurfaceFormat"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QSurfaceFormat"));
}


RING_FUNC(ring_QWindow_setFramePosition)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	pObject->setFramePosition(* (QPoint  *) RING_API_GETCPOINTER(2,"QPoint"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QPoint"));
}


RING_FUNC(ring_QWindow_setGeometry)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setGeometry( (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4), (int ) RING_API_GETNUMBER(5));
}


RING_FUNC(ring_QWindow_setGeometry_2)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	pObject->setGeometry(* (QRect  *) RING_API_GETCPOINTER(2,"QRect"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QRect"));
}


RING_FUNC(ring_QWindow_setIcon)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	pObject->setIcon(* (QIcon  *) RING_API_GETCPOINTER(2,"QIcon"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QIcon"));
}


RING_FUNC(ring_QWindow_setKeyboardGrabEnabled)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->setKeyboardGrabEnabled( (bool ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QWindow_setMask)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	pObject->setMask(* (QRegion  *) RING_API_GETCPOINTER(2,"QRegion"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QRegion"));
}


RING_FUNC(ring_QWindow_setMaximumSize)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	pObject->setMaximumSize(* (QSize  *) RING_API_GETCPOINTER(2,"QSize"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QSize"));
}


RING_FUNC(ring_QWindow_setMinimumSize)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	pObject->setMinimumSize(* (QSize  *) RING_API_GETCPOINTER(2,"QSize"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QSize"));
}


RING_FUNC(ring_QWindow_setModality)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setModality( (Qt::WindowModality )  (int) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QWindow_setMouseGrabEnabled)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->setMouseGrabEnabled( (bool ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QWindow_setOpacity)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setOpacity( (qreal ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QWindow_setParent)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setParent((QWindow *) RING_API_GETCPOINTER(2,"QWindow"));
}


RING_FUNC(ring_QWindow_setPosition)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	pObject->setPosition(* (QPoint  *) RING_API_GETCPOINTER(2,"QPoint"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QPoint"));
}


RING_FUNC(ring_QWindow_setPosition_2)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setPosition( (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_QWindow_setScreen)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setScreen((QScreen *) RING_API_GETCPOINTER(2,"QScreen"));
}


RING_FUNC(ring_QWindow_setSizeIncrement)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	pObject->setSizeIncrement(* (QSize  *) RING_API_GETCPOINTER(2,"QSize"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QSize"));
}


RING_FUNC(ring_QWindow_setTransientParent)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setTransientParent((QWindow *) RING_API_GETCPOINTER(2,"QWindow"));
}


RING_FUNC(ring_QWindow_setVisibility)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setVisibility( (QWindow::Visibility )  (int) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QWindow_setWindowState)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setWindowState( (Qt::WindowState )  (int) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QWindow_sizeIncrement)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	{
		QSize *pValue ; 
		pValue = new QSize() ;
		*pValue = pObject->sizeIncrement();
		RING_API_RETMANAGEDCPOINTER(pValue,"QSize",ring_QSize_freefunc);
	}
}


RING_FUNC(ring_QWindow_title)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	RING_API_RETSTRING(pObject->title().toStdString().c_str());
}


RING_FUNC(ring_QWindow_transientParent)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	RING_API_RETCPOINTER(pObject->transientParent(),"QWindow");
}


RING_FUNC(ring_QWindow_type)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	RING_API_RETNUMBER(pObject->type());
}


RING_FUNC(ring_QWindow_unsetCursor)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	pObject->unsetCursor();
}


RING_FUNC(ring_QWindow_visibility)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	RING_API_RETNUMBER(pObject->visibility());
}


RING_FUNC(ring_QWindow_width)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	RING_API_RETNUMBER(pObject->width());
}


RING_FUNC(ring_QWindow_winId)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	{
		WId *pValue ; 
		pValue = (WId *) RING_API_MALLOC(sizeof(WId)) ;
		*pValue = pObject->winId();
		RING_API_RETMANAGEDCPOINTER(pValue,"WId",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QWindow_windowState)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	RING_API_RETNUMBER(pObject->windowState());
}


RING_FUNC(ring_QWindow_x)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	RING_API_RETNUMBER(pObject->x());
}


RING_FUNC(ring_QWindow_y)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	RING_API_RETNUMBER(pObject->y());
}


RING_FUNC(ring_QWindow_alert)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->alert( (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QWindow_close)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	RING_API_RETNUMBER(pObject->close());
}


RING_FUNC(ring_QWindow_hide)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	pObject->hide();
}


RING_FUNC(ring_QWindow_lower)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	pObject->lower();
}


RING_FUNC(ring_QWindow_raise)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	pObject->raise();
}


RING_FUNC(ring_QWindow_requestActivate)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	pObject->requestActivate();
}


RING_FUNC(ring_QWindow_setHeight)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setHeight( (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QWindow_setMaximumHeight)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setMaximumHeight( (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QWindow_setMaximumWidth)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setMaximumWidth( (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QWindow_setMinimumHeight)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setMinimumHeight( (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QWindow_setMinimumWidth)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setMinimumWidth( (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QWindow_setTitle)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setTitle(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QWindow_setVisible)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setVisible( (bool ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QWindow_setWidth)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setWidth( (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QWindow_setX)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setX( (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QWindow_setY)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setY( (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QWindow_show)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	pObject->show();
}


RING_FUNC(ring_QWindow_showFullScreen)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	pObject->showFullScreen();
}


RING_FUNC(ring_QWindow_showMaximized)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	pObject->showMaximized();
}


RING_FUNC(ring_QWindow_showMinimized)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	pObject->showMinimized();
}


RING_FUNC(ring_QWindow_showNormal)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	pObject->showNormal();
}


RING_FUNC(ring_QWindow_fromWinId)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	RING_API_RETCPOINTER(pObject->fromWinId(* (WId  *) RING_API_GETCPOINTER(2,"WId")),"QWindow");
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"WId"));
}


RING_FUNC(ring_QWindow_setactiveChangedEvent)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setactiveChangedEvent(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QWindow_setcontentOrientationChangedEvent)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setcontentOrientationChangedEvent(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QWindow_setfocusObjectChangedEvent)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setfocusObjectChangedEvent(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QWindow_setheightChangedEvent)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setheightChangedEvent(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QWindow_setmaximumHeightChangedEvent)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setmaximumHeightChangedEvent(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QWindow_setmaximumWidthChangedEvent)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setmaximumWidthChangedEvent(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QWindow_setminimumHeightChangedEvent)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setminimumHeightChangedEvent(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QWindow_setminimumWidthChangedEvent)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setminimumWidthChangedEvent(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QWindow_setmodalityChangedEvent)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setmodalityChangedEvent(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QWindow_setopacityChangedEvent)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setopacityChangedEvent(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QWindow_setscreenChangedEvent)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setscreenChangedEvent(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QWindow_setvisibilityChangedEvent)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setvisibilityChangedEvent(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QWindow_setvisibleChangedEvent)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setvisibleChangedEvent(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QWindow_setwidthChangedEvent)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setwidthChangedEvent(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QWindow_setwindowStateChangedEvent)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setwindowStateChangedEvent(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QWindow_setwindowTitleChangedEvent)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setwindowTitleChangedEvent(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QWindow_setxChangedEvent)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setxChangedEvent(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QWindow_setyChangedEvent)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setyChangedEvent(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QWindow_getactiveChangedEvent)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	RING_API_RETSTRING(pObject->getactiveChangedEvent());
}


RING_FUNC(ring_QWindow_getcontentOrientationChangedEvent)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	RING_API_RETSTRING(pObject->getcontentOrientationChangedEvent());
}


RING_FUNC(ring_QWindow_getfocusObjectChangedEvent)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	RING_API_RETSTRING(pObject->getfocusObjectChangedEvent());
}


RING_FUNC(ring_QWindow_getheightChangedEvent)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	RING_API_RETSTRING(pObject->getheightChangedEvent());
}


RING_FUNC(ring_QWindow_getmaximumHeightChangedEvent)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	RING_API_RETSTRING(pObject->getmaximumHeightChangedEvent());
}


RING_FUNC(ring_QWindow_getmaximumWidthChangedEvent)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	RING_API_RETSTRING(pObject->getmaximumWidthChangedEvent());
}


RING_FUNC(ring_QWindow_getminimumHeightChangedEvent)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	RING_API_RETSTRING(pObject->getminimumHeightChangedEvent());
}


RING_FUNC(ring_QWindow_getminimumWidthChangedEvent)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	RING_API_RETSTRING(pObject->getminimumWidthChangedEvent());
}


RING_FUNC(ring_QWindow_getmodalityChangedEvent)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	RING_API_RETSTRING(pObject->getmodalityChangedEvent());
}


RING_FUNC(ring_QWindow_getopacityChangedEvent)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	RING_API_RETSTRING(pObject->getopacityChangedEvent());
}


RING_FUNC(ring_QWindow_getscreenChangedEvent)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	RING_API_RETSTRING(pObject->getscreenChangedEvent());
}


RING_FUNC(ring_QWindow_getvisibilityChangedEvent)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	RING_API_RETSTRING(pObject->getvisibilityChangedEvent());
}


RING_FUNC(ring_QWindow_getvisibleChangedEvent)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	RING_API_RETSTRING(pObject->getvisibleChangedEvent());
}


RING_FUNC(ring_QWindow_getwidthChangedEvent)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	RING_API_RETSTRING(pObject->getwidthChangedEvent());
}


RING_FUNC(ring_QWindow_getwindowStateChangedEvent)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	RING_API_RETSTRING(pObject->getwindowStateChangedEvent());
}


RING_FUNC(ring_QWindow_getwindowTitleChangedEvent)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	RING_API_RETSTRING(pObject->getwindowTitleChangedEvent());
}


RING_FUNC(ring_QWindow_getxChangedEvent)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	RING_API_RETSTRING(pObject->getxChangedEvent());
}


RING_FUNC(ring_QWindow_getyChangedEvent)
{
	GWindow *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GWindow *) RING_API_GETCPOINTER(1,"QWindow");
	RING_API_RETSTRING(pObject->getyChangedEvent());
}


RING_FUNC(ring_QGuiApplication_devicePixelRatio)
{
	GGuiApplication *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GGuiApplication *) RING_API_GETCPOINTER(1,"QGuiApplication");
	RING_API_RETNUMBER(pObject->devicePixelRatio());
}


RING_FUNC(ring_QGuiApplication_isSavingSession)
{
	GGuiApplication *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GGuiApplication *) RING_API_GETCPOINTER(1,"QGuiApplication");
	RING_API_RETNUMBER(pObject->isSavingSession());
}


RING_FUNC(ring_QGuiApplication_isSessionRestored)
{
	GGuiApplication *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GGuiApplication *) RING_API_GETCPOINTER(1,"QGuiApplication");
	RING_API_RETNUMBER(pObject->isSessionRestored());
}


RING_FUNC(ring_QGuiApplication_sessionId)
{
	GGuiApplication *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GGuiApplication *) RING_API_GETCPOINTER(1,"QGuiApplication");
	RING_API_RETSTRING(pObject->sessionId().toStdString().c_str());
}


RING_FUNC(ring_QGuiApplication_sessionKey)
{
	GGuiApplication *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GGuiApplication *) RING_API_GETCPOINTER(1,"QGuiApplication");
	RING_API_RETSTRING(pObject->sessionKey().toStdString().c_str());
}


RING_FUNC(ring_QGuiApplication_allWindows)
{
	GGuiApplication *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GGuiApplication *) RING_API_GETCPOINTER(1,"QGuiApplication");
	{
		QWindowList *pValue ; 
		pValue = (QWindowList *) RING_API_MALLOC(sizeof(QWindowList)) ;
		*pValue = pObject->allWindows();
		RING_API_RETMANAGEDCPOINTER(pValue,"QWindowList",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QGuiApplication_applicationDisplayName)
{
	GGuiApplication *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GGuiApplication *) RING_API_GETCPOINTER(1,"QGuiApplication");
	RING_API_RETSTRING(pObject->applicationDisplayName().toStdString().c_str());
}


RING_FUNC(ring_QGuiApplication_applicationState)
{
	GGuiApplication *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GGuiApplication *) RING_API_GETCPOINTER(1,"QGuiApplication");
	{
		Qt::ApplicationState *pValue ; 
		pValue = (Qt::ApplicationState *) RING_API_MALLOC(sizeof(Qt::ApplicationState)) ;
		*pValue = pObject->applicationState();
		RING_API_RETMANAGEDCPOINTER(pValue,"Qt::ApplicationState",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QGuiApplication_changeOverrideCursor)
{
	GGuiApplication *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GGuiApplication *) RING_API_GETCPOINTER(1,"QGuiApplication");
	pObject->changeOverrideCursor(* (QCursor  *) RING_API_GETCPOINTER(2,"QCursor"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QCursor"));
}


RING_FUNC(ring_QGuiApplication_clipboard)
{
	GGuiApplication *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GGuiApplication *) RING_API_GETCPOINTER(1,"QGuiApplication");
	RING_API_RETCPOINTER(pObject->clipboard(),"QClipboard");
}


RING_FUNC(ring_QGuiApplication_desktopSettingsAware)
{
	GGuiApplication *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GGuiApplication *) RING_API_GETCPOINTER(1,"QGuiApplication");
	RING_API_RETNUMBER(pObject->desktopSettingsAware());
}


RING_FUNC(ring_QGuiApplication_exec)
{
	GGuiApplication *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GGuiApplication *) RING_API_GETCPOINTER(1,"QGuiApplication");
	RING_API_RETNUMBER(pObject->exec());
}


RING_FUNC(ring_QGuiApplication_focusObject)
{
	GGuiApplication *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GGuiApplication *) RING_API_GETCPOINTER(1,"QGuiApplication");
	RING_API_RETCPOINTER(pObject->focusObject(),"QObject");
}


RING_FUNC(ring_QGuiApplication_focusWindow)
{
	GGuiApplication *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GGuiApplication *) RING_API_GETCPOINTER(1,"QGuiApplication");
	RING_API_RETCPOINTER(pObject->focusWindow(),"QWindow");
}


RING_FUNC(ring_QGuiApplication_font)
{
	GGuiApplication *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GGuiApplication *) RING_API_GETCPOINTER(1,"QGuiApplication");
	{
		QFont *pValue ; 
		pValue = new QFont() ;
		*pValue = pObject->font();
		RING_API_RETMANAGEDCPOINTER(pValue,"QFont",ring_QFont_freefunc);
	}
}


RING_FUNC(ring_QGuiApplication_inputMethod)
{
	GGuiApplication *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GGuiApplication *) RING_API_GETCPOINTER(1,"QGuiApplication");
	RING_API_RETCPOINTER(pObject->inputMethod(),"QInputMethod");
}


RING_FUNC(ring_QGuiApplication_isLeftToRight)
{
	GGuiApplication *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GGuiApplication *) RING_API_GETCPOINTER(1,"QGuiApplication");
	RING_API_RETNUMBER(pObject->isLeftToRight());
}


RING_FUNC(ring_QGuiApplication_isRightToLeft)
{
	GGuiApplication *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GGuiApplication *) RING_API_GETCPOINTER(1,"QGuiApplication");
	RING_API_RETNUMBER(pObject->isRightToLeft());
}


RING_FUNC(ring_QGuiApplication_keyboardModifiers)
{
	GGuiApplication *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GGuiApplication *) RING_API_GETCPOINTER(1,"QGuiApplication");
	RING_API_RETNUMBER(pObject->keyboardModifiers());
}


RING_FUNC(ring_QGuiApplication_layoutDirection)
{
	GGuiApplication *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GGuiApplication *) RING_API_GETCPOINTER(1,"QGuiApplication");
	RING_API_RETNUMBER(pObject->layoutDirection());
}


RING_FUNC(ring_QGuiApplication_modalWindow)
{
	GGuiApplication *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GGuiApplication *) RING_API_GETCPOINTER(1,"QGuiApplication");
	RING_API_RETCPOINTER(pObject->modalWindow(),"QWindow");
}


RING_FUNC(ring_QGuiApplication_mouseButtons)
{
	GGuiApplication *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GGuiApplication *) RING_API_GETCPOINTER(1,"QGuiApplication");
	RING_API_RETNUMBER(pObject->mouseButtons());
}


RING_FUNC(ring_QGuiApplication_overrideCursor)
{
	GGuiApplication *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GGuiApplication *) RING_API_GETCPOINTER(1,"QGuiApplication");
	RING_API_RETCPOINTER(pObject->overrideCursor(),"QCursor");
}


RING_FUNC(ring_QGuiApplication_palette)
{
	GGuiApplication *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GGuiApplication *) RING_API_GETCPOINTER(1,"QGuiApplication");
	{
		QPalette *pValue ; 
		pValue = (QPalette *) RING_API_MALLOC(sizeof(QPalette)) ;
		*pValue = pObject->palette();
		RING_API_RETMANAGEDCPOINTER(pValue,"QPalette",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QGuiApplication_platformName)
{
	GGuiApplication *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GGuiApplication *) RING_API_GETCPOINTER(1,"QGuiApplication");
	RING_API_RETSTRING(pObject->platformName().toStdString().c_str());
}


RING_FUNC(ring_QGuiApplication_platformNativeInterface)
{
	GGuiApplication *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GGuiApplication *) RING_API_GETCPOINTER(1,"QGuiApplication");
	RING_API_RETCPOINTER(pObject->platformNativeInterface(),"QPlatformNativeInterface");
}


RING_FUNC(ring_QGuiApplication_primaryScreen)
{
	GGuiApplication *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GGuiApplication *) RING_API_GETCPOINTER(1,"QGuiApplication");
	RING_API_RETCPOINTER(pObject->primaryScreen(),"QScreen");
}


RING_FUNC(ring_QGuiApplication_queryKeyboardModifiers)
{
	GGuiApplication *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GGuiApplication *) RING_API_GETCPOINTER(1,"QGuiApplication");
	RING_API_RETNUMBER(pObject->queryKeyboardModifiers());
}


RING_FUNC(ring_QGuiApplication_quitOnLastWindowClosed)
{
	GGuiApplication *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GGuiApplication *) RING_API_GETCPOINTER(1,"QGuiApplication");
	RING_API_RETNUMBER(pObject->quitOnLastWindowClosed());
}


RING_FUNC(ring_QGuiApplication_restoreOverrideCursor)
{
	GGuiApplication *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GGuiApplication *) RING_API_GETCPOINTER(1,"QGuiApplication");
	pObject->restoreOverrideCursor();
}


RING_FUNC(ring_QGuiApplication_screens)
{
	GGuiApplication *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GGuiApplication *) RING_API_GETCPOINTER(1,"QGuiApplication");
	{
		QList<QScreen *> *pValue ; 
		pValue = (QList<QScreen *> *) RING_API_MALLOC(sizeof(QList<QScreen *>)) ;
		*pValue = pObject->screens();
		RING_API_RETMANAGEDCPOINTER(pValue,"QList<QScreen *>",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QGuiApplication_setApplicationDisplayName)
{
	GGuiApplication *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GGuiApplication *) RING_API_GETCPOINTER(1,"QGuiApplication");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setApplicationDisplayName(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QGuiApplication_setDesktopSettingsAware)
{
	GGuiApplication *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GGuiApplication *) RING_API_GETCPOINTER(1,"QGuiApplication");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setDesktopSettingsAware( (bool ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QGuiApplication_setFont)
{
	GGuiApplication *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GGuiApplication *) RING_API_GETCPOINTER(1,"QGuiApplication");
	pObject->setFont(* (QFont  *) RING_API_GETCPOINTER(2,"QFont"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QFont"));
}


RING_FUNC(ring_QGuiApplication_setLayoutDirection)
{
	GGuiApplication *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GGuiApplication *) RING_API_GETCPOINTER(1,"QGuiApplication");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setLayoutDirection( (Qt::LayoutDirection )  (int) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QGuiApplication_setOverrideCursor)
{
	GGuiApplication *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GGuiApplication *) RING_API_GETCPOINTER(1,"QGuiApplication");
	pObject->setOverrideCursor(* (QCursor  *) RING_API_GETCPOINTER(2,"QCursor"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QCursor"));
}


RING_FUNC(ring_QGuiApplication_setPalette)
{
	GGuiApplication *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GGuiApplication *) RING_API_GETCPOINTER(1,"QGuiApplication");
	pObject->setPalette(* (QPalette  *) RING_API_GETCPOINTER(2,"QPalette"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QPalette"));
}


RING_FUNC(ring_QGuiApplication_setQuitOnLastWindowClosed)
{
	GGuiApplication *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GGuiApplication *) RING_API_GETCPOINTER(1,"QGuiApplication");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setQuitOnLastWindowClosed( (bool ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QGuiApplication_styleHints)
{
	GGuiApplication *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GGuiApplication *) RING_API_GETCPOINTER(1,"QGuiApplication");
	RING_API_RETCPOINTER(pObject->styleHints(),"QStyleHints");
}


RING_FUNC(ring_QGuiApplication_sync)
{
	GGuiApplication *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GGuiApplication *) RING_API_GETCPOINTER(1,"QGuiApplication");
	pObject->sync();
}


RING_FUNC(ring_QGuiApplication_topLevelAt)
{
	GGuiApplication *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GGuiApplication *) RING_API_GETCPOINTER(1,"QGuiApplication");
	RING_API_RETCPOINTER(pObject->topLevelAt(* (QPoint  *) RING_API_GETCPOINTER(2,"QPoint")),"QWindow");
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QPoint"));
}


RING_FUNC(ring_QGuiApplication_topLevelWindows)
{
	GGuiApplication *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GGuiApplication *) RING_API_GETCPOINTER(1,"QGuiApplication");
	{
		QWindowList *pValue ; 
		pValue = (QWindowList *) RING_API_MALLOC(sizeof(QWindowList)) ;
		*pValue = pObject->topLevelWindows();
		RING_API_RETMANAGEDCPOINTER(pValue,"QWindowList",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QGuiApplication_setapplicationDisplayNameChangedEvent)
{
	GGuiApplication *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GGuiApplication *) RING_API_GETCPOINTER(1,"QGuiApplication");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setapplicationDisplayNameChangedEvent(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QGuiApplication_setapplicationStateChangedEvent)
{
	GGuiApplication *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GGuiApplication *) RING_API_GETCPOINTER(1,"QGuiApplication");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setapplicationStateChangedEvent(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QGuiApplication_setcommitDataRequestEvent)
{
	GGuiApplication *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GGuiApplication *) RING_API_GETCPOINTER(1,"QGuiApplication");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setcommitDataRequestEvent(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QGuiApplication_setfocusObjectChangedEvent)
{
	GGuiApplication *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GGuiApplication *) RING_API_GETCPOINTER(1,"QGuiApplication");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setfocusObjectChangedEvent(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QGuiApplication_setfocusWindowChangedEvent)
{
	GGuiApplication *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GGuiApplication *) RING_API_GETCPOINTER(1,"QGuiApplication");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setfocusWindowChangedEvent(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QGuiApplication_setfontDatabaseChangedEvent)
{
	GGuiApplication *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GGuiApplication *) RING_API_GETCPOINTER(1,"QGuiApplication");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setfontDatabaseChangedEvent(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QGuiApplication_setlastWindowClosedEvent)
{
	GGuiApplication *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GGuiApplication *) RING_API_GETCPOINTER(1,"QGuiApplication");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setlastWindowClosedEvent(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QGuiApplication_setlayoutDirectionChangedEvent)
{
	GGuiApplication *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GGuiApplication *) RING_API_GETCPOINTER(1,"QGuiApplication");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setlayoutDirectionChangedEvent(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QGuiApplication_setpaletteChangedEvent)
{
	GGuiApplication *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GGuiApplication *) RING_API_GETCPOINTER(1,"QGuiApplication");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setpaletteChangedEvent(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QGuiApplication_setprimaryScreenChangedEvent)
{
	GGuiApplication *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GGuiApplication *) RING_API_GETCPOINTER(1,"QGuiApplication");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setprimaryScreenChangedEvent(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QGuiApplication_setsaveStateRequestEvent)
{
	GGuiApplication *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GGuiApplication *) RING_API_GETCPOINTER(1,"QGuiApplication");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setsaveStateRequestEvent(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QGuiApplication_setscreenAddedEvent)
{
	GGuiApplication *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GGuiApplication *) RING_API_GETCPOINTER(1,"QGuiApplication");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setscreenAddedEvent(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QGuiApplication_setscreenRemovedEvent)
{
	GGuiApplication *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GGuiApplication *) RING_API_GETCPOINTER(1,"QGuiApplication");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setscreenRemovedEvent(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QGuiApplication_getapplicationDisplayNameChangedEvent)
{
	GGuiApplication *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GGuiApplication *) RING_API_GETCPOINTER(1,"QGuiApplication");
	RING_API_RETSTRING(pObject->getapplicationDisplayNameChangedEvent());
}


RING_FUNC(ring_QGuiApplication_getapplicationStateChangedEvent)
{
	GGuiApplication *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GGuiApplication *) RING_API_GETCPOINTER(1,"QGuiApplication");
	RING_API_RETSTRING(pObject->getapplicationStateChangedEvent());
}


RING_FUNC(ring_QGuiApplication_getcommitDataRequestEvent)
{
	GGuiApplication *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GGuiApplication *) RING_API_GETCPOINTER(1,"QGuiApplication");
	RING_API_RETSTRING(pObject->getcommitDataRequestEvent());
}


RING_FUNC(ring_QGuiApplication_getfocusObjectChangedEvent)
{
	GGuiApplication *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GGuiApplication *) RING_API_GETCPOINTER(1,"QGuiApplication");
	RING_API_RETSTRING(pObject->getfocusObjectChangedEvent());
}


RING_FUNC(ring_QGuiApplication_getfocusWindowChangedEvent)
{
	GGuiApplication *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GGuiApplication *) RING_API_GETCPOINTER(1,"QGuiApplication");
	RING_API_RETSTRING(pObject->getfocusWindowChangedEvent());
}


RING_FUNC(ring_QGuiApplication_getfontDatabaseChangedEvent)
{
	GGuiApplication *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GGuiApplication *) RING_API_GETCPOINTER(1,"QGuiApplication");
	RING_API_RETSTRING(pObject->getfontDatabaseChangedEvent());
}


RING_FUNC(ring_QGuiApplication_getlastWindowClosedEvent)
{
	GGuiApplication *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GGuiApplication *) RING_API_GETCPOINTER(1,"QGuiApplication");
	RING_API_RETSTRING(pObject->getlastWindowClosedEvent());
}


RING_FUNC(ring_QGuiApplication_getlayoutDirectionChangedEvent)
{
	GGuiApplication *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GGuiApplication *) RING_API_GETCPOINTER(1,"QGuiApplication");
	RING_API_RETSTRING(pObject->getlayoutDirectionChangedEvent());
}


RING_FUNC(ring_QGuiApplication_getpaletteChangedEvent)
{
	GGuiApplication *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GGuiApplication *) RING_API_GETCPOINTER(1,"QGuiApplication");
	RING_API_RETSTRING(pObject->getpaletteChangedEvent());
}


RING_FUNC(ring_QGuiApplication_getprimaryScreenChangedEvent)
{
	GGuiApplication *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GGuiApplication *) RING_API_GETCPOINTER(1,"QGuiApplication");
	RING_API_RETSTRING(pObject->getprimaryScreenChangedEvent());
}


RING_FUNC(ring_QGuiApplication_getsaveStateRequestEvent)
{
	GGuiApplication *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GGuiApplication *) RING_API_GETCPOINTER(1,"QGuiApplication");
	RING_API_RETSTRING(pObject->getsaveStateRequestEvent());
}


RING_FUNC(ring_QGuiApplication_getscreenAddedEvent)
{
	GGuiApplication *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GGuiApplication *) RING_API_GETCPOINTER(1,"QGuiApplication");
	RING_API_RETSTRING(pObject->getscreenAddedEvent());
}


RING_FUNC(ring_QGuiApplication_getscreenRemovedEvent)
{
	GGuiApplication *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GGuiApplication *) RING_API_GETCPOINTER(1,"QGuiApplication");
	RING_API_RETSTRING(pObject->getscreenRemovedEvent());
}


RING_FUNC(ring_QClipboard_clear)
{
	QClipboard *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QClipboard *) RING_API_GETCPOINTER(1,"QClipboard");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->clear( (QClipboard::Mode )  (int) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QClipboard_image)
{
	QClipboard *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QClipboard *) RING_API_GETCPOINTER(1,"QClipboard");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QImage *pValue ; 
		pValue = new QImage() ;
		*pValue = pObject->image( (QClipboard::Mode )  (int) RING_API_GETNUMBER(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"QImage",ring_QImage_freefunc);
	}
}


RING_FUNC(ring_QClipboard_mimeData)
{
	QClipboard *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QClipboard *) RING_API_GETCPOINTER(1,"QClipboard");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(pObject->mimeData( (QClipboard::Mode )  (int) RING_API_GETNUMBER(2)),"QMimeData");
}


RING_FUNC(ring_QClipboard_ownsClipboard)
{
	QClipboard *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QClipboard *) RING_API_GETCPOINTER(1,"QClipboard");
	RING_API_RETNUMBER(pObject->ownsClipboard());
}


RING_FUNC(ring_QClipboard_ownsFindBuffer)
{
	QClipboard *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QClipboard *) RING_API_GETCPOINTER(1,"QClipboard");
	RING_API_RETNUMBER(pObject->ownsFindBuffer());
}


RING_FUNC(ring_QClipboard_ownsSelection)
{
	QClipboard *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QClipboard *) RING_API_GETCPOINTER(1,"QClipboard");
	RING_API_RETNUMBER(pObject->ownsSelection());
}


RING_FUNC(ring_QClipboard_pixmap)
{
	QClipboard *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QClipboard *) RING_API_GETCPOINTER(1,"QClipboard");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QPixmap *pValue ; 
		pValue = new QPixmap() ;
		*pValue = pObject->pixmap( (QClipboard::Mode )  (int) RING_API_GETNUMBER(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"QPixmap",ring_QPixmap_freefunc);
	}
}


RING_FUNC(ring_QClipboard_setImage)
{
	QClipboard *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QClipboard *) RING_API_GETCPOINTER(1,"QClipboard");
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setImage(* (QImage  *) RING_API_GETCPOINTER(2,"QImage"), (QClipboard::Mode )  (int) RING_API_GETNUMBER(3));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QImage"));
}


RING_FUNC(ring_QClipboard_setMimeData)
{
	QClipboard *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QClipboard *) RING_API_GETCPOINTER(1,"QClipboard");
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setMimeData((QMimeData *) RING_API_GETCPOINTER(2,"QMimeData"), (QClipboard::Mode )  (int) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_QClipboard_setPixmap)
{
	QClipboard *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QClipboard *) RING_API_GETCPOINTER(1,"QClipboard");
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setPixmap(* (QPixmap  *) RING_API_GETCPOINTER(2,"QPixmap"), (QClipboard::Mode )  (int) RING_API_GETNUMBER(3));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QPixmap"));
}


RING_FUNC(ring_QClipboard_setText)
{
	QClipboard *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QClipboard *) RING_API_GETCPOINTER(1,"QClipboard");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setText(RING_API_GETSTRING(2), (QClipboard::Mode )  (int) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_QClipboard_supportsFindBuffer)
{
	QClipboard *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QClipboard *) RING_API_GETCPOINTER(1,"QClipboard");
	RING_API_RETNUMBER(pObject->supportsFindBuffer());
}


RING_FUNC(ring_QClipboard_supportsSelection)
{
	QClipboard *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QClipboard *) RING_API_GETCPOINTER(1,"QClipboard");
	RING_API_RETNUMBER(pObject->supportsSelection());
}


RING_FUNC(ring_QClipboard_text)
{
	QClipboard *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QClipboard *) RING_API_GETCPOINTER(1,"QClipboard");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->text( (QClipboard::Mode )  (int) RING_API_GETNUMBER(2)).toStdString().c_str());
}


RING_FUNC(ring_QFontDatabase_bold)
{
	QFontDatabase *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFontDatabase *) RING_API_GETCPOINTER(1,"QFontDatabase");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->bold(RING_API_GETSTRING(2),RING_API_GETSTRING(3)));
}


RING_FUNC(ring_QFontDatabase_families)
{
	QFontDatabase *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFontDatabase *) RING_API_GETCPOINTER(1,"QFontDatabase");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QStringList *pValue ; 
		pValue = new QStringList() ;
		*pValue = pObject->families( (QFontDatabase::WritingSystem )  (int) RING_API_GETNUMBER(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"QStringList",ring_QStringList_freefunc);
	}
}


RING_FUNC(ring_QFontDatabase_font)
{
	QFontDatabase *pObject ;
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFontDatabase *) RING_API_GETCPOINTER(1,"QFontDatabase");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QFont *pValue ; 
		pValue = new QFont() ;
		*pValue = pObject->font(RING_API_GETSTRING(2),RING_API_GETSTRING(3), (int ) RING_API_GETNUMBER(4));
		RING_API_RETMANAGEDCPOINTER(pValue,"QFont",ring_QFont_freefunc);
	}
}


RING_FUNC(ring_QFontDatabase_isBitmapScalable)
{
	QFontDatabase *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFontDatabase *) RING_API_GETCPOINTER(1,"QFontDatabase");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->isBitmapScalable(RING_API_GETSTRING(2),RING_API_GETSTRING(3)));
}


RING_FUNC(ring_QFontDatabase_isFixedPitch)
{
	QFontDatabase *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFontDatabase *) RING_API_GETCPOINTER(1,"QFontDatabase");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->isFixedPitch(RING_API_GETSTRING(2),RING_API_GETSTRING(3)));
}


RING_FUNC(ring_QFontDatabase_isPrivateFamily)
{
	QFontDatabase *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFontDatabase *) RING_API_GETCPOINTER(1,"QFontDatabase");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->isPrivateFamily(RING_API_GETSTRING(2)));
}


RING_FUNC(ring_QFontDatabase_isScalable)
{
	QFontDatabase *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFontDatabase *) RING_API_GETCPOINTER(1,"QFontDatabase");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->isScalable(RING_API_GETSTRING(2),RING_API_GETSTRING(3)));
}


RING_FUNC(ring_QFontDatabase_isSmoothlyScalable)
{
	QFontDatabase *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFontDatabase *) RING_API_GETCPOINTER(1,"QFontDatabase");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->isSmoothlyScalable(RING_API_GETSTRING(2),RING_API_GETSTRING(3)));
}


RING_FUNC(ring_QFontDatabase_italic)
{
	QFontDatabase *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFontDatabase *) RING_API_GETCPOINTER(1,"QFontDatabase");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->italic(RING_API_GETSTRING(2),RING_API_GETSTRING(3)));
}


RING_FUNC(ring_QFontDatabase_pointSizes)
{
	QFontDatabase *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFontDatabase *) RING_API_GETCPOINTER(1,"QFontDatabase");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QList<int> *pValue ; 
		pValue = (QList<int> *) RING_API_MALLOC(sizeof(QList<int>)) ;
		*pValue = pObject->pointSizes(RING_API_GETSTRING(2),RING_API_GETSTRING(3));
		RING_API_RETMANAGEDCPOINTER(pValue,"QList<int>",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QFontDatabase_smoothSizes)
{
	QFontDatabase *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFontDatabase *) RING_API_GETCPOINTER(1,"QFontDatabase");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QList<int> *pValue ; 
		pValue = (QList<int> *) RING_API_MALLOC(sizeof(QList<int>)) ;
		*pValue = pObject->smoothSizes(RING_API_GETSTRING(2),RING_API_GETSTRING(3));
		RING_API_RETMANAGEDCPOINTER(pValue,"QList<int>",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QFontDatabase_styleString)
{
	QFontDatabase *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFontDatabase *) RING_API_GETCPOINTER(1,"QFontDatabase");
	RING_API_RETSTRING(pObject->styleString(* (QFont  *) RING_API_GETCPOINTER(2,"QFont")).toStdString().c_str());
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QFont"));
}


RING_FUNC(ring_QFontDatabase_styleString_2)
{
	QFontDatabase *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFontDatabase *) RING_API_GETCPOINTER(1,"QFontDatabase");
	RING_API_RETSTRING(pObject->styleString(* (QFontInfo  *) RING_API_GETCPOINTER(2,"QFontInfo")).toStdString().c_str());
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QFontInfo"));
}


RING_FUNC(ring_QFontDatabase_styles)
{
	QFontDatabase *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFontDatabase *) RING_API_GETCPOINTER(1,"QFontDatabase");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QStringList *pValue ; 
		pValue = new QStringList() ;
		*pValue = pObject->styles(RING_API_GETSTRING(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"QStringList",ring_QStringList_freefunc);
	}
}


RING_FUNC(ring_QFontDatabase_weight)
{
	QFontDatabase *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFontDatabase *) RING_API_GETCPOINTER(1,"QFontDatabase");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->weight(RING_API_GETSTRING(2),RING_API_GETSTRING(3)));
}


RING_FUNC(ring_QFontDatabase_writingSystems)
{
	QFontDatabase *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFontDatabase *) RING_API_GETCPOINTER(1,"QFontDatabase");
	{
		QList<QFontDatabase::WritingSystem> *pValue ; 
		pValue = (QList<QFontDatabase::WritingSystem> *) RING_API_MALLOC(sizeof(QList<QFontDatabase::WritingSystem>)) ;
		*pValue = pObject->writingSystems();
		RING_API_RETMANAGEDCPOINTER(pValue,"QList<QFontDatabase::WritingSystem>",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QFontDatabase_writingSystems_2)
{
	QFontDatabase *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFontDatabase *) RING_API_GETCPOINTER(1,"QFontDatabase");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QList<QFontDatabase::WritingSystem> *pValue ; 
		pValue = (QList<QFontDatabase::WritingSystem> *) RING_API_MALLOC(sizeof(QList<QFontDatabase::WritingSystem>)) ;
		*pValue = pObject->writingSystems(RING_API_GETSTRING(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"QList<QFontDatabase::WritingSystem>",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QFontDatabase_addApplicationFont)
{
	QFontDatabase *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFontDatabase *) RING_API_GETCPOINTER(1,"QFontDatabase");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->addApplicationFont(RING_API_GETSTRING(2)));
}


RING_FUNC(ring_QFontDatabase_addApplicationFontFromData)
{
	QFontDatabase *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFontDatabase *) RING_API_GETCPOINTER(1,"QFontDatabase");
	RING_API_RETNUMBER(pObject->addApplicationFontFromData(* (QByteArray  *) RING_API_GETCPOINTER(2,"QByteArray")));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QByteArray"));
}


RING_FUNC(ring_QFontDatabase_applicationFontFamilies)
{
	QFontDatabase *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFontDatabase *) RING_API_GETCPOINTER(1,"QFontDatabase");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QStringList *pValue ; 
		pValue = new QStringList() ;
		*pValue = pObject->applicationFontFamilies( (int ) RING_API_GETNUMBER(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"QStringList",ring_QStringList_freefunc);
	}
}


RING_FUNC(ring_QFontDatabase_removeAllApplicationFonts)
{
	QFontDatabase *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFontDatabase *) RING_API_GETCPOINTER(1,"QFontDatabase");
	RING_API_RETNUMBER(pObject->removeAllApplicationFonts());
}


RING_FUNC(ring_QFontDatabase_removeApplicationFont)
{
	QFontDatabase *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFontDatabase *) RING_API_GETCPOINTER(1,"QFontDatabase");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->removeApplicationFont( (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QFontDatabase_standardSizes)
{
	QFontDatabase *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFontDatabase *) RING_API_GETCPOINTER(1,"QFontDatabase");
	{
		QList<int> *pValue ; 
		pValue = (QList<int> *) RING_API_MALLOC(sizeof(QList<int>)) ;
		*pValue = pObject->standardSizes();
		RING_API_RETMANAGEDCPOINTER(pValue,"QList<int>",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QFontDatabase_systemFont)
{
	QFontDatabase *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFontDatabase *) RING_API_GETCPOINTER(1,"QFontDatabase");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QFont *pValue ; 
		pValue = new QFont() ;
		*pValue = pObject->systemFont( (QFontDatabase::SystemFont )  (int) RING_API_GETNUMBER(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"QFont",ring_QFont_freefunc);
	}
}


RING_FUNC(ring_QFontDatabase_writingSystemName)
{
	QFontDatabase *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFontDatabase *) RING_API_GETCPOINTER(1,"QFontDatabase");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->writingSystemName( (QFontDatabase::WritingSystem )  (int) RING_API_GETNUMBER(2)).toStdString().c_str());
}


RING_FUNC(ring_QFontDatabase_writingSystemSample)
{
	QFontDatabase *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFontDatabase *) RING_API_GETCPOINTER(1,"QFontDatabase");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->writingSystemSample( (QFontDatabase::WritingSystem )  (int) RING_API_GETNUMBER(2)).toStdString().c_str());
}

#include <QStyle>
#include <QStyleFactory>

RING_FUNC(ring_QApp_quit)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	qApp->quit();
	exit(0);
}

RING_FUNC(ring_QApp_exec)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	qApp->exec();
}

RING_FUNC(ring_QApp_styleWindows)
{
	qApp->setStyle(QStyleFactory::create("windows"));
	qApp->setPalette(qApp->style()->standardPalette());
}

RING_FUNC(ring_QApp_styleWindowsVista)
{
	qApp->setStyle(QStyleFactory::create("windowsvista"));
	qApp->setPalette(qApp->style()->standardPalette());
}

RING_FUNC(ring_QApp_styleFusion)
{
	qApp->setStyle(QStyleFactory::create("fusion"));
	qApp->setPalette(qApp->style()->standardPalette());
}

RING_FUNC(ring_QApp_styleFusionBlack)
{
	qApp->setStyle(QStyleFactory::create("fusion"));
	QPalette palette;
	palette.setColor(QPalette::Window, QColor(53,53,53));
	palette.setColor(QPalette::WindowText, Qt::white);
	palette.setColor(QPalette::Base, QColor(15,15,15));
	palette.setColor(QPalette::AlternateBase, QColor(53,53,53));
	palette.setColor(QPalette::ToolTipBase, Qt::white);
	palette.setColor(QPalette::ToolTipText, Qt::white);
	palette.setColor(QPalette::Text, Qt::white);
	palette.setColor(QPalette::Button, QColor(53,53,53));
	palette.setColor(QPalette::ButtonText, Qt::white);
	palette.setColor(QPalette::BrightText, Qt::red);

	palette.setColor(QPalette::Highlight, QColor(142,45,197).lighter());
	palette.setColor(QPalette::HighlightedText, Qt::black);

	palette.setColor(QPalette::Disabled, QPalette::Text, Qt::darkGray);
	palette.setColor(QPalette::Disabled, QPalette::ButtonText, Qt::darkGray);

	qApp->setPalette(palette);
}

RING_FUNC(ring_QApp_styleFusionCustom)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 12 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( (! RING_API_ISPOINTER(1)) || (! RING_API_ISPOINTER(2)) ||
		(! RING_API_ISPOINTER(3)) || (! RING_API_ISPOINTER(4)) ||
		(! RING_API_ISPOINTER(5)) || (! RING_API_ISPOINTER(6)) ||
		(! RING_API_ISPOINTER(7)) || (! RING_API_ISPOINTER(8)) ||
		(! RING_API_ISPOINTER(9)) || (! RING_API_ISPOINTER(10)) ||
		(! RING_API_ISPOINTER(11)) || (! RING_API_ISPOINTER(12)) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	qApp->setStyle(QStyleFactory::create("fusion"));
	QPalette palette;
	palette.setColor(QPalette::Window, 		* (QColor *) RING_API_GETCPOINTER(1,"QColor") );
	palette.setColor(QPalette::WindowText, 		* (QColor *) RING_API_GETCPOINTER(2,"QColor") );
	palette.setColor(QPalette::Base, 		* (QColor *) RING_API_GETCPOINTER(3,"QColor") );
	palette.setColor(QPalette::AlternateBase, 	* (QColor *) RING_API_GETCPOINTER(4,"QColor") );
	palette.setColor(QPalette::ToolTipBase, 	* (QColor *) RING_API_GETCPOINTER(5,"QColor") );
	palette.setColor(QPalette::ToolTipText, 	* (QColor *) RING_API_GETCPOINTER(6,"QColor") );
	palette.setColor(QPalette::Text,		* (QColor *) RING_API_GETCPOINTER(7,"QColor") );
	palette.setColor(QPalette::Button, 		* (QColor *) RING_API_GETCPOINTER(8,"QColor") );
	palette.setColor(QPalette::ButtonText, 		* (QColor *) RING_API_GETCPOINTER(9,"QColor") );
	palette.setColor(QPalette::BrightText, 		* (QColor *) RING_API_GETCPOINTER(10,"QColor") );
	palette.setColor(QPalette::Highlight, 		* (QColor *) RING_API_GETCPOINTER(11,"QColor") );
	palette.setColor(QPalette::HighlightedText, 	* (QColor *) RING_API_GETCPOINTER(12,"QColor") );
	qApp->setPalette(palette);
}


RING_FUNC(ring_QApp_processEvents)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	qApp->processEvents();
}

RING_FUNC(ring_QApp_closeAllWindows)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	qApp->closeAllWindows();
}

RING_FUNC(ring_QApp_keyboardModifiers)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER( (double) qApp->keyboardModifiers() );
}

RING_FUNC(ring_QApp_clipboard)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETCPOINTER(qApp->clipboard(),"QClipboard");
}

RING_FUNC(ring_QApp_style)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETCPOINTER(qApp->style(),"QStyle");
}

RING_FUNC(ring_QApp_aboutQt)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	qApp->aboutQt();
}

RING_FUNC(ring_QApp_activeModalWidget)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETCPOINTER(qApp->activeModalWidget(),"QWidget");
}

RING_FUNC(ring_QApp_activePopupWidget)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETCPOINTER(qApp->activePopupWidget(),"QWidget");
}

RING_FUNC(ring_QApp_activeWindow)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETCPOINTER(qApp->activeWindow(),"QWidget");
}

RING_FUNC(ring_QApp_focusWidget)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETCPOINTER(qApp->focusWidget(),"QWidget");
}

RING_FUNC(ring_QApp_titlebarHeight)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(qApp->style()->pixelMetric(QStyle::PM_TitleBarHeight));
}


RING_FUNC(ring_QAllEvents_accept)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	pObject->accept();
}


RING_FUNC(ring_QAllEvents_ignore)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	pObject->ignore();
}


RING_FUNC(ring_QAllEvents_getKeyCode)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	RING_API_RETNUMBER(pObject->getKeyCode());
}


RING_FUNC(ring_QAllEvents_getKeyText)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	RING_API_RETSTRING(pObject->getKeyText().toStdString().c_str());
}


RING_FUNC(ring_QAllEvents_getModifiers)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	RING_API_RETNUMBER(pObject->getModifiers());
}


RING_FUNC(ring_QAllEvents_getx)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	RING_API_RETNUMBER(pObject->getx());
}


RING_FUNC(ring_QAllEvents_gety)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	RING_API_RETNUMBER(pObject->gety());
}


RING_FUNC(ring_QAllEvents_getglobalx)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	RING_API_RETNUMBER(pObject->getglobalx());
}


RING_FUNC(ring_QAllEvents_getglobaly)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	RING_API_RETNUMBER(pObject->getglobaly());
}


RING_FUNC(ring_QAllEvents_getbutton)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	RING_API_RETNUMBER(pObject->getbutton());
}


RING_FUNC(ring_QAllEvents_getbuttons)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	RING_API_RETNUMBER(pObject->getbuttons());
}


RING_FUNC(ring_QAllEvents_setKeyPressEvent)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setKeyPressEvent(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QAllEvents_setMouseButtonPressEvent)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setMouseButtonPressEvent(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QAllEvents_setMouseButtonReleaseEvent)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setMouseButtonReleaseEvent(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QAllEvents_setMouseButtonDblClickEvent)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setMouseButtonDblClickEvent(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QAllEvents_setMouseMoveEvent)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setMouseMoveEvent(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QAllEvents_setCloseEvent)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setCloseEvent(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QAllEvents_setContextMenuEvent)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setContextMenuEvent(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QAllEvents_setDragEnterEvent)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setDragEnterEvent(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QAllEvents_setDragLeaveEvent)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setDragLeaveEvent(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QAllEvents_setDragMoveEvent)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setDragMoveEvent(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QAllEvents_setDropEvent)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setDropEvent(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QAllEvents_setEnterEvent)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setEnterEvent(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QAllEvents_setFocusInEvent)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setFocusInEvent(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QAllEvents_setFocusOutEvent)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setFocusOutEvent(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QAllEvents_setKeyReleaseEvent)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setKeyReleaseEvent(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QAllEvents_setLeaveEvent)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setLeaveEvent(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QAllEvents_setNonClientAreaMouseButtonDblClickEvent)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setNonClientAreaMouseButtonDblClickEvent(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QAllEvents_setNonClientAreaMouseButtonPressEvent)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setNonClientAreaMouseButtonPressEvent(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QAllEvents_setNonClientAreaMouseButtonReleaseEvent)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setNonClientAreaMouseButtonReleaseEvent(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QAllEvents_setNonClientAreaMouseMoveEvent)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setNonClientAreaMouseMoveEvent(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QAllEvents_setMoveEvent)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setMoveEvent(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QAllEvents_setResizeEvent)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setResizeEvent(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QAllEvents_setWindowActivateEvent)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setWindowActivateEvent(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QAllEvents_setWindowBlockedEvent)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setWindowBlockedEvent(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QAllEvents_setWindowDeactivateEvent)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setWindowDeactivateEvent(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QAllEvents_setWindowStateChangeEvent)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setWindowStateChangeEvent(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QAllEvents_setWindowUnblockedEvent)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setWindowUnblockedEvent(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QAllEvents_setPaintEvent)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setPaintEvent(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QAllEvents_setChildAddedEvent)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setChildAddedEvent(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QAllEvents_setChildPolishedEvent)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setChildPolishedEvent(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QAllEvents_setChildRemovedEvent)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setChildRemovedEvent(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QAllEvents_getKeyPressEvent)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	RING_API_RETSTRING(pObject->getKeyPressEvent());
}


RING_FUNC(ring_QAllEvents_getMouseButtonPressEvent)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	RING_API_RETSTRING(pObject->getMouseButtonPressEvent());
}


RING_FUNC(ring_QAllEvents_getMouseButtonReleaseEvent)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	RING_API_RETSTRING(pObject->getMouseButtonReleaseEvent());
}


RING_FUNC(ring_QAllEvents_getMouseButtonDblClickEvent)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	RING_API_RETSTRING(pObject->getMouseButtonDblClickEvent());
}


RING_FUNC(ring_QAllEvents_getMouseMoveEvent)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	RING_API_RETSTRING(pObject->getMouseMoveEvent());
}


RING_FUNC(ring_QAllEvents_getCloseEvent)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	RING_API_RETSTRING(pObject->getCloseEvent());
}


RING_FUNC(ring_QAllEvents_getContextMenuEvent)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	RING_API_RETSTRING(pObject->getContextMenuEvent());
}


RING_FUNC(ring_QAllEvents_getDragEnterEvent)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	RING_API_RETSTRING(pObject->getDragEnterEvent());
}


RING_FUNC(ring_QAllEvents_getDragLeaveEvent)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	RING_API_RETSTRING(pObject->getDragLeaveEvent());
}


RING_FUNC(ring_QAllEvents_getDragMoveEvent)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	RING_API_RETSTRING(pObject->getDragMoveEvent());
}


RING_FUNC(ring_QAllEvents_getDropEvent)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	RING_API_RETSTRING(pObject->getDropEvent());
}


RING_FUNC(ring_QAllEvents_getEnterEvent)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	RING_API_RETSTRING(pObject->getEnterEvent());
}


RING_FUNC(ring_QAllEvents_getFocusInEvent)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	RING_API_RETSTRING(pObject->getFocusInEvent());
}


RING_FUNC(ring_QAllEvents_getFocusOutEvent)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	RING_API_RETSTRING(pObject->getFocusOutEvent());
}


RING_FUNC(ring_QAllEvents_getKeyReleaseEvent)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	RING_API_RETSTRING(pObject->getKeyReleaseEvent());
}


RING_FUNC(ring_QAllEvents_getLeaveEvent)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	RING_API_RETSTRING(pObject->getLeaveEvent());
}


RING_FUNC(ring_QAllEvents_getNonClientAreaMouseButtonDblClickEvent)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	RING_API_RETSTRING(pObject->getNonClientAreaMouseButtonDblClickEvent());
}


RING_FUNC(ring_QAllEvents_getNonClientAreaMouseButtonPressEvent)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	RING_API_RETSTRING(pObject->getNonClientAreaMouseButtonPressEvent());
}


RING_FUNC(ring_QAllEvents_getNonClientAreaMouseButtonReleaseEvent)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	RING_API_RETSTRING(pObject->getNonClientAreaMouseButtonReleaseEvent());
}


RING_FUNC(ring_QAllEvents_getNonClientAreaMouseMoveEvent)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	RING_API_RETSTRING(pObject->getNonClientAreaMouseMoveEvent());
}


RING_FUNC(ring_QAllEvents_getMoveEvent)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	RING_API_RETSTRING(pObject->getMoveEvent());
}


RING_FUNC(ring_QAllEvents_getResizeEvent)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	RING_API_RETSTRING(pObject->getResizeEvent());
}


RING_FUNC(ring_QAllEvents_getWindowActivateEvent)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	RING_API_RETSTRING(pObject->getWindowActivateEvent());
}


RING_FUNC(ring_QAllEvents_getWindowBlockedEvent)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	RING_API_RETSTRING(pObject->getWindowBlockedEvent());
}


RING_FUNC(ring_QAllEvents_getWindowDeactivateEvent)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	RING_API_RETSTRING(pObject->getWindowDeactivateEvent());
}


RING_FUNC(ring_QAllEvents_getWindowStateChangeEvent)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	RING_API_RETSTRING(pObject->getWindowStateChangeEvent());
}


RING_FUNC(ring_QAllEvents_getWindowUnblockedEvent)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	RING_API_RETSTRING(pObject->getWindowUnblockedEvent());
}


RING_FUNC(ring_QAllEvents_getPaintEvent)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	RING_API_RETSTRING(pObject->getPaintEvent());
}


RING_FUNC(ring_QAllEvents_getChildAddedEvent)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	RING_API_RETSTRING(pObject->getChildAddedEvent());
}


RING_FUNC(ring_QAllEvents_getChildPolishedEvent)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	RING_API_RETSTRING(pObject->getChildPolishedEvent());
}


RING_FUNC(ring_QAllEvents_getChildRemovedEvent)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	RING_API_RETSTRING(pObject->getChildRemovedEvent());
}


RING_FUNC(ring_QAllEvents_setEventOutput)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setEventOutput( (bool ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QAllEvents_getParentObject)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	RING_API_RETCPOINTER(pObject->getParentObject(),"QObject");
}


RING_FUNC(ring_QAllEvents_getParentWidget)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	RING_API_RETCPOINTER(pObject->getParentWidget(),"QWidget");
}


RING_FUNC(ring_QAllEvents_setKeyPressFunc)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setKeyPressFunc(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QAllEvents_setMouseButtonPressFunc)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setMouseButtonPressFunc(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QAllEvents_setMouseButtonReleaseFunc)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setMouseButtonReleaseFunc(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QAllEvents_setMouseButtonDblClickFunc)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setMouseButtonDblClickFunc(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QAllEvents_setMouseMoveFunc)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setMouseMoveFunc(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QAllEvents_setCloseFunc)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setCloseFunc(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QAllEvents_setContextMenuFunc)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setContextMenuFunc(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QAllEvents_setDragEnterFunc)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setDragEnterFunc(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QAllEvents_setDragLeaveFunc)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setDragLeaveFunc(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QAllEvents_setDragMoveFunc)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setDragMoveFunc(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QAllEvents_setDropFunc)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setDropFunc(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QAllEvents_setEnterFunc)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setEnterFunc(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QAllEvents_setFocusInFunc)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setFocusInFunc(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QAllEvents_setFocusOutFunc)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setFocusOutFunc(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QAllEvents_setKeyReleaseFunc)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setKeyReleaseFunc(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QAllEvents_setLeaveFunc)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setLeaveFunc(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QAllEvents_setNonClientAreaMouseButtonDblClickFunc)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setNonClientAreaMouseButtonDblClickFunc(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QAllEvents_setNonClientAreaMouseButtonPressFunc)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setNonClientAreaMouseButtonPressFunc(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QAllEvents_setNonClientAreaMouseButtonReleaseFunc)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setNonClientAreaMouseButtonReleaseFunc(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QAllEvents_setNonClientAreaMouseMoveFunc)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setNonClientAreaMouseMoveFunc(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QAllEvents_setMoveFunc)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setMoveFunc(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QAllEvents_setResizeFunc)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setResizeFunc(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QAllEvents_setWindowActivateFunc)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setWindowActivateFunc(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QAllEvents_setWindowBlockedFunc)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setWindowBlockedFunc(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QAllEvents_setWindowDeactivateFunc)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setWindowDeactivateFunc(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QAllEvents_setWindowStateChangeFunc)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setWindowStateChangeFunc(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QAllEvents_setWindowUnblockedFunc)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setWindowUnblockedFunc(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QAllEvents_setPaintFunc)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setPaintFunc(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QAllEvents_setChildAddedFunc)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setChildAddedFunc(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QAllEvents_setChildPolishedFunc)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setChildPolishedFunc(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QAllEvents_setChildRemovedFunc)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setChildRemovedFunc(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QAllEvents_getKeyPressFunc)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	RING_API_RETSTRING(pObject->getKeyPressFunc());
}


RING_FUNC(ring_QAllEvents_getMouseButtonPressFunc)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	RING_API_RETSTRING(pObject->getMouseButtonPressFunc());
}


RING_FUNC(ring_QAllEvents_getMouseButtonReleaseFunc)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	RING_API_RETSTRING(pObject->getMouseButtonReleaseFunc());
}


RING_FUNC(ring_QAllEvents_getMouseButtonDblClickFunc)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	RING_API_RETSTRING(pObject->getMouseButtonDblClickFunc());
}


RING_FUNC(ring_QAllEvents_getMouseMoveFunc)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	RING_API_RETSTRING(pObject->getMouseMoveFunc());
}


RING_FUNC(ring_QAllEvents_getCloseFunc)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	RING_API_RETSTRING(pObject->getCloseFunc());
}


RING_FUNC(ring_QAllEvents_getContextMenuFunc)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	RING_API_RETSTRING(pObject->getContextMenuFunc());
}


RING_FUNC(ring_QAllEvents_getDragEnterFunc)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	RING_API_RETSTRING(pObject->getDragEnterFunc());
}


RING_FUNC(ring_QAllEvents_getDragLeaveFunc)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	RING_API_RETSTRING(pObject->getDragLeaveFunc());
}


RING_FUNC(ring_QAllEvents_getDragMoveFunc)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	RING_API_RETSTRING(pObject->getDragMoveFunc());
}


RING_FUNC(ring_QAllEvents_getDropFunc)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	RING_API_RETSTRING(pObject->getDropFunc());
}


RING_FUNC(ring_QAllEvents_getEnterFunc)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	RING_API_RETSTRING(pObject->getEnterFunc());
}


RING_FUNC(ring_QAllEvents_getFocusInFunc)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	RING_API_RETSTRING(pObject->getFocusInFunc());
}


RING_FUNC(ring_QAllEvents_getFocusOutFunc)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	RING_API_RETSTRING(pObject->getFocusOutFunc());
}


RING_FUNC(ring_QAllEvents_getKeyReleaseFunc)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	RING_API_RETSTRING(pObject->getKeyReleaseFunc());
}


RING_FUNC(ring_QAllEvents_getLeaveFunc)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	RING_API_RETSTRING(pObject->getLeaveFunc());
}


RING_FUNC(ring_QAllEvents_getNonClientAreaMouseButtonDblClickFunc)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	RING_API_RETSTRING(pObject->getNonClientAreaMouseButtonDblClickFunc());
}


RING_FUNC(ring_QAllEvents_getNonClientAreaMouseButtonPressFunc)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	RING_API_RETSTRING(pObject->getNonClientAreaMouseButtonPressFunc());
}


RING_FUNC(ring_QAllEvents_getNonClientAreaMouseButtonReleaseFunc)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	RING_API_RETSTRING(pObject->getNonClientAreaMouseButtonReleaseFunc());
}


RING_FUNC(ring_QAllEvents_getNonClientAreaMouseMoveFunc)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	RING_API_RETSTRING(pObject->getNonClientAreaMouseMoveFunc());
}


RING_FUNC(ring_QAllEvents_getMoveFunc)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	RING_API_RETSTRING(pObject->getMoveFunc());
}


RING_FUNC(ring_QAllEvents_getResizeFunc)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	RING_API_RETSTRING(pObject->getResizeFunc());
}


RING_FUNC(ring_QAllEvents_getWindowActivateFunc)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	RING_API_RETSTRING(pObject->getWindowActivateFunc());
}


RING_FUNC(ring_QAllEvents_getWindowBlockedFunc)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	RING_API_RETSTRING(pObject->getWindowBlockedFunc());
}


RING_FUNC(ring_QAllEvents_getWindowDeactivateFunc)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	RING_API_RETSTRING(pObject->getWindowDeactivateFunc());
}


RING_FUNC(ring_QAllEvents_getWindowStateChangeFunc)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	RING_API_RETSTRING(pObject->getWindowStateChangeFunc());
}


RING_FUNC(ring_QAllEvents_getWindowUnblockedFunc)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	RING_API_RETSTRING(pObject->getWindowUnblockedFunc());
}


RING_FUNC(ring_QAllEvents_getPaintFunc)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	RING_API_RETSTRING(pObject->getPaintFunc());
}


RING_FUNC(ring_QAllEvents_getChildAddedFunc)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	RING_API_RETSTRING(pObject->getChildAddedFunc());
}


RING_FUNC(ring_QAllEvents_getChildPolishedFunc)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	RING_API_RETSTRING(pObject->getChildPolishedFunc());
}


RING_FUNC(ring_QAllEvents_getChildRemovedFunc)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	RING_API_RETSTRING(pObject->getChildRemovedFunc());
}


RING_FUNC(ring_QAllEvents_getDropEventObject)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	RING_API_RETCPOINTER(pObject->getDropEventObject(),"QDropEvent");
}


RING_FUNC(ring_QAllEvents_getDragMoveEventObject)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	RING_API_RETCPOINTER(pObject->getDragMoveEventObject(),"QDragMoveEvent");
}


RING_FUNC(ring_QAllEvents_getDragEnterEventObject)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	RING_API_RETCPOINTER(pObject->getDragEnterEventObject(),"QDragEnterEvent");
}


RING_FUNC(ring_QAllEvents_getDragLeaveEventObject)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	RING_API_RETCPOINTER(pObject->getDragLeaveEventObject(),"QDragLeaveEvent");
}


RING_FUNC(ring_QAllEvents_getChildEventObject)
{
	GAllEvents *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"QAllEvents");
	RING_API_RETCPOINTER(pObject->getChildEventObject(),"QChildEvent");
}


RING_FUNC(ring_QAbstractSocket_abort)
{
	GAbstractSocket *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAbstractSocket *) RING_API_GETCPOINTER(1,"QAbstractSocket");
	pObject->abort();
}


RING_FUNC(ring_QAbstractSocket_bind)
{
	GAbstractSocket *pObject ;
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAbstractSocket *) RING_API_GETCPOINTER(1,"QAbstractSocket");
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->bind(* (QHostAddress  *) RING_API_GETCPOINTER(2,"QHostAddress"), (int ) RING_API_GETNUMBER(3), (QAbstractSocket::BindFlag )  (int) RING_API_GETNUMBER(4)));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QHostAddress"));
}


RING_FUNC(ring_QAbstractSocket_connectToHost)
{
	GAbstractSocket *pObject ;
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAbstractSocket *) RING_API_GETCPOINTER(1,"QAbstractSocket");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->connectToHost(RING_API_GETSTRING(2), (int ) RING_API_GETNUMBER(3), (QIODevice::OpenModeFlag )  (int) RING_API_GETNUMBER(4), (QAbstractSocket::NetworkLayerProtocol )  (int) RING_API_GETNUMBER(5));
}


RING_FUNC(ring_QAbstractSocket_disconnectFromHost)
{
	GAbstractSocket *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAbstractSocket *) RING_API_GETCPOINTER(1,"QAbstractSocket");
	pObject->disconnectFromHost();
}


RING_FUNC(ring_QAbstractSocket_error)
{
	GAbstractSocket *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAbstractSocket *) RING_API_GETCPOINTER(1,"QAbstractSocket");
	RING_API_RETNUMBER(pObject->error());
}


RING_FUNC(ring_QAbstractSocket_flush)
{
	GAbstractSocket *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAbstractSocket *) RING_API_GETCPOINTER(1,"QAbstractSocket");
	RING_API_RETNUMBER(pObject->flush());
}


RING_FUNC(ring_QAbstractSocket_isValid)
{
	GAbstractSocket *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAbstractSocket *) RING_API_GETCPOINTER(1,"QAbstractSocket");
	RING_API_RETNUMBER(pObject->isValid());
}


RING_FUNC(ring_QAbstractSocket_localAddress)
{
	GAbstractSocket *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAbstractSocket *) RING_API_GETCPOINTER(1,"QAbstractSocket");
	{
		QHostAddress *pValue ; 
		pValue = new QHostAddress() ;
		*pValue = pObject->localAddress();
		RING_API_RETMANAGEDCPOINTER(pValue,"QHostAddress",ring_QHostAddress_freefunc);
	}
}


RING_FUNC(ring_QAbstractSocket_localPort)
{
	GAbstractSocket *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAbstractSocket *) RING_API_GETCPOINTER(1,"QAbstractSocket");
	RING_API_RETNUMBER(pObject->localPort());
}


RING_FUNC(ring_QAbstractSocket_pauseMode)
{
	GAbstractSocket *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAbstractSocket *) RING_API_GETCPOINTER(1,"QAbstractSocket");
	RING_API_RETNUMBER(pObject->pauseMode());
}


RING_FUNC(ring_QAbstractSocket_peerAddress)
{
	GAbstractSocket *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAbstractSocket *) RING_API_GETCPOINTER(1,"QAbstractSocket");
	{
		QHostAddress *pValue ; 
		pValue = new QHostAddress() ;
		*pValue = pObject->peerAddress();
		RING_API_RETMANAGEDCPOINTER(pValue,"QHostAddress",ring_QHostAddress_freefunc);
	}
}


RING_FUNC(ring_QAbstractSocket_peerName)
{
	GAbstractSocket *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAbstractSocket *) RING_API_GETCPOINTER(1,"QAbstractSocket");
	RING_API_RETSTRING(pObject->peerName().toStdString().c_str());
}


RING_FUNC(ring_QAbstractSocket_peerPort)
{
	GAbstractSocket *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAbstractSocket *) RING_API_GETCPOINTER(1,"QAbstractSocket");
	RING_API_RETNUMBER(pObject->peerPort());
}


RING_FUNC(ring_QAbstractSocket_proxy)
{
	GAbstractSocket *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAbstractSocket *) RING_API_GETCPOINTER(1,"QAbstractSocket");
	{
		QNetworkProxy *pValue ; 
		pValue = new QNetworkProxy() ;
		*pValue = pObject->proxy();
		RING_API_RETMANAGEDCPOINTER(pValue,"QNetworkProxy",ring_QNetworkProxy_freefunc);
	}
}


RING_FUNC(ring_QAbstractSocket_readBufferSize)
{
	GAbstractSocket *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAbstractSocket *) RING_API_GETCPOINTER(1,"QAbstractSocket");
	RING_API_RETNUMBER(pObject->readBufferSize());
}


RING_FUNC(ring_QAbstractSocket_resume)
{
	GAbstractSocket *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAbstractSocket *) RING_API_GETCPOINTER(1,"QAbstractSocket");
	pObject->resume();
}


RING_FUNC(ring_QAbstractSocket_setPauseMode)
{
	GAbstractSocket *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAbstractSocket *) RING_API_GETCPOINTER(1,"QAbstractSocket");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setPauseMode( (QAbstractSocket::PauseMode )  (int) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QAbstractSocket_setProxy)
{
	GAbstractSocket *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAbstractSocket *) RING_API_GETCPOINTER(1,"QAbstractSocket");
	pObject->setProxy(* (QNetworkProxy   *) RING_API_GETCPOINTER(2,"QNetworkProxy"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QNetworkProxy"));
}


RING_FUNC(ring_QAbstractSocket_setReadBufferSize)
{
	GAbstractSocket *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAbstractSocket *) RING_API_GETCPOINTER(1,"QAbstractSocket");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setReadBufferSize( (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QAbstractSocket_setSocketDescriptor)
{
	GAbstractSocket *pObject ;
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAbstractSocket *) RING_API_GETCPOINTER(1,"QAbstractSocket");
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->setSocketDescriptor(* (qintptr  *) RING_API_GETCPOINTER(2,"qintptr"), (QAbstractSocket::SocketState )  (int) RING_API_GETNUMBER(3), (QIODevice::OpenModeFlag )  (int) RING_API_GETNUMBER(4)));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"qintptr"));
}


RING_FUNC(ring_QAbstractSocket_setSocketOption)
{
	GAbstractSocket *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAbstractSocket *) RING_API_GETCPOINTER(1,"QAbstractSocket");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setSocketOption( (QAbstractSocket::SocketOption )  (int) RING_API_GETNUMBER(2),* (QVariant   *) RING_API_GETCPOINTER(3,"QVariant"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"QVariant"));
}


RING_FUNC(ring_QAbstractSocket_socketDescriptor)
{
	GAbstractSocket *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAbstractSocket *) RING_API_GETCPOINTER(1,"QAbstractSocket");
	RING_API_RETCPOINTER(pObject->socketDescriptor(),"int");
}


RING_FUNC(ring_QAbstractSocket_socketOption)
{
	GAbstractSocket *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAbstractSocket *) RING_API_GETCPOINTER(1,"QAbstractSocket");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QVariant *pValue ; 
		pValue = new QVariant() ;
		*pValue = pObject->socketOption( (QAbstractSocket::SocketOption )  (int) RING_API_GETNUMBER(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"QVariant",ring_QVariant_freefunc);
	}
}


RING_FUNC(ring_QAbstractSocket_socketType)
{
	GAbstractSocket *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAbstractSocket *) RING_API_GETCPOINTER(1,"QAbstractSocket");
	RING_API_RETNUMBER(pObject->socketType());
}


RING_FUNC(ring_QAbstractSocket_state)
{
	GAbstractSocket *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAbstractSocket *) RING_API_GETCPOINTER(1,"QAbstractSocket");
	RING_API_RETNUMBER(pObject->state());
}


RING_FUNC(ring_QAbstractSocket_waitForConnected)
{
	GAbstractSocket *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAbstractSocket *) RING_API_GETCPOINTER(1,"QAbstractSocket");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->waitForConnected( (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QAbstractSocket_waitForDisconnected)
{
	GAbstractSocket *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAbstractSocket *) RING_API_GETCPOINTER(1,"QAbstractSocket");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->waitForDisconnected( (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QAbstractSocket_atEnd)
{
	GAbstractSocket *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAbstractSocket *) RING_API_GETCPOINTER(1,"QAbstractSocket");
	RING_API_RETNUMBER(pObject->atEnd());
}


RING_FUNC(ring_QAbstractSocket_bytesAvailable)
{
	GAbstractSocket *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAbstractSocket *) RING_API_GETCPOINTER(1,"QAbstractSocket");
	RING_API_RETNUMBER(pObject->bytesAvailable());
}


RING_FUNC(ring_QAbstractSocket_bytesToWrite)
{
	GAbstractSocket *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAbstractSocket *) RING_API_GETCPOINTER(1,"QAbstractSocket");
	RING_API_RETNUMBER(pObject->bytesToWrite());
}


RING_FUNC(ring_QAbstractSocket_canReadLine)
{
	GAbstractSocket *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAbstractSocket *) RING_API_GETCPOINTER(1,"QAbstractSocket");
	RING_API_RETNUMBER(pObject->canReadLine());
}


RING_FUNC(ring_QAbstractSocket_close)
{
	GAbstractSocket *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAbstractSocket *) RING_API_GETCPOINTER(1,"QAbstractSocket");
	pObject->close();
}


RING_FUNC(ring_QAbstractSocket_isSequential)
{
	GAbstractSocket *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAbstractSocket *) RING_API_GETCPOINTER(1,"QAbstractSocket");
	RING_API_RETNUMBER(pObject->isSequential());
}


RING_FUNC(ring_QAbstractSocket_waitForBytesWritten)
{
	GAbstractSocket *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAbstractSocket *) RING_API_GETCPOINTER(1,"QAbstractSocket");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->waitForBytesWritten( (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QAbstractSocket_waitForReadyRead)
{
	GAbstractSocket *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAbstractSocket *) RING_API_GETCPOINTER(1,"QAbstractSocket");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->waitForReadyRead( (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QAbstractSocket_setconnectedEvent)
{
	GAbstractSocket *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAbstractSocket *) RING_API_GETCPOINTER(1,"QAbstractSocket");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setconnectedEvent(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QAbstractSocket_setdisconnectedEvent)
{
	GAbstractSocket *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAbstractSocket *) RING_API_GETCPOINTER(1,"QAbstractSocket");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setdisconnectedEvent(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QAbstractSocket_seterrorEvent)
{
	GAbstractSocket *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAbstractSocket *) RING_API_GETCPOINTER(1,"QAbstractSocket");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->seterrorEvent(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QAbstractSocket_sethostFoundEvent)
{
	GAbstractSocket *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAbstractSocket *) RING_API_GETCPOINTER(1,"QAbstractSocket");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->sethostFoundEvent(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QAbstractSocket_setproxyAuthenticationRequiredEvent)
{
	GAbstractSocket *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAbstractSocket *) RING_API_GETCPOINTER(1,"QAbstractSocket");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setproxyAuthenticationRequiredEvent(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QAbstractSocket_setstateChangedEvent)
{
	GAbstractSocket *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAbstractSocket *) RING_API_GETCPOINTER(1,"QAbstractSocket");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setstateChangedEvent(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QAbstractSocket_getconnectedEvent)
{
	GAbstractSocket *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAbstractSocket *) RING_API_GETCPOINTER(1,"QAbstractSocket");
	RING_API_RETSTRING(pObject->getconnectedEvent());
}


RING_FUNC(ring_QAbstractSocket_getdisconnectedEvent)
{
	GAbstractSocket *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAbstractSocket *) RING_API_GETCPOINTER(1,"QAbstractSocket");
	RING_API_RETSTRING(pObject->getdisconnectedEvent());
}


RING_FUNC(ring_QAbstractSocket_geterrorEvent)
{
	GAbstractSocket *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAbstractSocket *) RING_API_GETCPOINTER(1,"QAbstractSocket");
	RING_API_RETSTRING(pObject->geterrorEvent());
}


RING_FUNC(ring_QAbstractSocket_gethostFoundEvent)
{
	GAbstractSocket *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAbstractSocket *) RING_API_GETCPOINTER(1,"QAbstractSocket");
	RING_API_RETSTRING(pObject->gethostFoundEvent());
}


RING_FUNC(ring_QAbstractSocket_getproxyAuthenticationRequiredEvent)
{
	GAbstractSocket *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAbstractSocket *) RING_API_GETCPOINTER(1,"QAbstractSocket");
	RING_API_RETSTRING(pObject->getproxyAuthenticationRequiredEvent());
}


RING_FUNC(ring_QAbstractSocket_getstateChangedEvent)
{
	GAbstractSocket *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GAbstractSocket *) RING_API_GETCPOINTER(1,"QAbstractSocket");
	RING_API_RETSTRING(pObject->getstateChangedEvent());
}


RING_FUNC(ring_QNetworkProxy_capabilities)
{
	QNetworkProxy *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QNetworkProxy *) RING_API_GETCPOINTER(1,"QNetworkProxy");
	RING_API_RETNUMBER(pObject->capabilities());
}


RING_FUNC(ring_QNetworkProxy_hasRawHeader)
{
	QNetworkProxy *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QNetworkProxy *) RING_API_GETCPOINTER(1,"QNetworkProxy");
	RING_API_RETNUMBER(pObject->hasRawHeader(* (QByteArray  *) RING_API_GETCPOINTER(2,"QByteArray")));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QByteArray"));
}


RING_FUNC(ring_QNetworkProxy_header)
{
	QNetworkProxy *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QNetworkProxy *) RING_API_GETCPOINTER(1,"QNetworkProxy");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QVariant *pValue ; 
		pValue = new QVariant() ;
		*pValue = pObject->header( (QNetworkRequest::KnownHeaders )  (int) RING_API_GETNUMBER(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"QVariant",ring_QVariant_freefunc);
	}
}


RING_FUNC(ring_QNetworkProxy_hostName)
{
	QNetworkProxy *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QNetworkProxy *) RING_API_GETCPOINTER(1,"QNetworkProxy");
	RING_API_RETSTRING(pObject->hostName().toStdString().c_str());
}


RING_FUNC(ring_QNetworkProxy_isCachingProxy)
{
	QNetworkProxy *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QNetworkProxy *) RING_API_GETCPOINTER(1,"QNetworkProxy");
	RING_API_RETNUMBER(pObject->isCachingProxy());
}


RING_FUNC(ring_QNetworkProxy_isTransparentProxy)
{
	QNetworkProxy *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QNetworkProxy *) RING_API_GETCPOINTER(1,"QNetworkProxy");
	RING_API_RETNUMBER(pObject->isTransparentProxy());
}


RING_FUNC(ring_QNetworkProxy_password)
{
	QNetworkProxy *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QNetworkProxy *) RING_API_GETCPOINTER(1,"QNetworkProxy");
	RING_API_RETSTRING(pObject->password().toStdString().c_str());
}


RING_FUNC(ring_QNetworkProxy_port)
{
	QNetworkProxy *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QNetworkProxy *) RING_API_GETCPOINTER(1,"QNetworkProxy");
	RING_API_RETNUMBER(pObject->port());
}


RING_FUNC(ring_QNetworkProxy_rawHeader)
{
	QNetworkProxy *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QNetworkProxy *) RING_API_GETCPOINTER(1,"QNetworkProxy");
	{
		QByteArray *pValue ; 
		pValue = new QByteArray() ;
		*pValue = pObject->rawHeader(* (QByteArray  *) RING_API_GETCPOINTER(2,"QByteArray"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QByteArray"));
		RING_API_RETMANAGEDCPOINTER(pValue,"QByteArray",ring_QByteArray_freefunc);
	}
}


RING_FUNC(ring_QNetworkProxy_setCapabilities)
{
	QNetworkProxy *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QNetworkProxy *) RING_API_GETCPOINTER(1,"QNetworkProxy");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setCapabilities( (QNetworkProxy::Capability )  (int) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QNetworkProxy_setHeader)
{
	QNetworkProxy *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QNetworkProxy *) RING_API_GETCPOINTER(1,"QNetworkProxy");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setHeader( (QNetworkRequest::KnownHeaders )  (int) RING_API_GETNUMBER(2),* (QVariant  *) RING_API_GETCPOINTER(3,"QVariant"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"QVariant"));
}


RING_FUNC(ring_QNetworkProxy_setHostName)
{
	QNetworkProxy *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QNetworkProxy *) RING_API_GETCPOINTER(1,"QNetworkProxy");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setHostName(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QNetworkProxy_setPassword)
{
	QNetworkProxy *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QNetworkProxy *) RING_API_GETCPOINTER(1,"QNetworkProxy");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setPassword(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QNetworkProxy_setPort)
{
	QNetworkProxy *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QNetworkProxy *) RING_API_GETCPOINTER(1,"QNetworkProxy");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setPort( (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QNetworkProxy_setRawHeader)
{
	QNetworkProxy *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QNetworkProxy *) RING_API_GETCPOINTER(1,"QNetworkProxy");
	pObject->setRawHeader(* (QByteArray  *) RING_API_GETCPOINTER(2,"QByteArray"),* (QByteArray  *) RING_API_GETCPOINTER(3,"QByteArray"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QByteArray"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"QByteArray"));
}


RING_FUNC(ring_QNetworkProxy_setType)
{
	QNetworkProxy *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QNetworkProxy *) RING_API_GETCPOINTER(1,"QNetworkProxy");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setType( (QNetworkProxy::ProxyType )  (int) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QNetworkProxy_setUser)
{
	QNetworkProxy *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QNetworkProxy *) RING_API_GETCPOINTER(1,"QNetworkProxy");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setUser(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QNetworkProxy_swap)
{
	QNetworkProxy *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QNetworkProxy *) RING_API_GETCPOINTER(1,"QNetworkProxy");
	pObject->swap(* (QNetworkProxy   *) RING_API_GETCPOINTER(2,"QNetworkProxy"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QNetworkProxy"));
}


RING_FUNC(ring_QNetworkProxy_type)
{
	QNetworkProxy *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QNetworkProxy *) RING_API_GETCPOINTER(1,"QNetworkProxy");
	RING_API_RETNUMBER(pObject->type());
}


RING_FUNC(ring_QNetworkProxy_user)
{
	QNetworkProxy *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QNetworkProxy *) RING_API_GETCPOINTER(1,"QNetworkProxy");
	RING_API_RETSTRING(pObject->user().toStdString().c_str());
}


RING_FUNC(ring_QNetworkProxy_applicationProxy)
{
	QNetworkProxy *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QNetworkProxy *) RING_API_GETCPOINTER(1,"QNetworkProxy");
	{
		QNetworkProxy *pValue ; 
		pValue = new QNetworkProxy() ;
		*pValue = pObject->applicationProxy();
		RING_API_RETMANAGEDCPOINTER(pValue,"QNetworkProxy",ring_QNetworkProxy_freefunc);
	}
}


RING_FUNC(ring_QNetworkProxy_setApplicationProxy)
{
	QNetworkProxy *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QNetworkProxy *) RING_API_GETCPOINTER(1,"QNetworkProxy");
	pObject->setApplicationProxy(* (QNetworkProxy   *) RING_API_GETCPOINTER(2,"QNetworkProxy"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QNetworkProxy"));
}


RING_FUNC(ring_QTcpSocket_setconnectedEvent)
{
	GTcpSocket *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GTcpSocket *) RING_API_GETCPOINTER(1,"QTcpSocket");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setconnectedEvent(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QTcpSocket_setdisconnectedEvent)
{
	GTcpSocket *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GTcpSocket *) RING_API_GETCPOINTER(1,"QTcpSocket");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setdisconnectedEvent(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QTcpSocket_seterrorEvent)
{
	GTcpSocket *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GTcpSocket *) RING_API_GETCPOINTER(1,"QTcpSocket");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->seterrorEvent(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QTcpSocket_sethostFoundEvent)
{
	GTcpSocket *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GTcpSocket *) RING_API_GETCPOINTER(1,"QTcpSocket");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->sethostFoundEvent(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QTcpSocket_setproxyAuthenticationRequiredEvent)
{
	GTcpSocket *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GTcpSocket *) RING_API_GETCPOINTER(1,"QTcpSocket");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setproxyAuthenticationRequiredEvent(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QTcpSocket_setstateChangedEvent)
{
	GTcpSocket *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GTcpSocket *) RING_API_GETCPOINTER(1,"QTcpSocket");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setstateChangedEvent(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QTcpSocket_setaboutToCloseEvent)
{
	GTcpSocket *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GTcpSocket *) RING_API_GETCPOINTER(1,"QTcpSocket");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setaboutToCloseEvent(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QTcpSocket_setbytesWrittenEvent)
{
	GTcpSocket *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GTcpSocket *) RING_API_GETCPOINTER(1,"QTcpSocket");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setbytesWrittenEvent(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QTcpSocket_setreadChannelFinishedEvent)
{
	GTcpSocket *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GTcpSocket *) RING_API_GETCPOINTER(1,"QTcpSocket");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setreadChannelFinishedEvent(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QTcpSocket_setreadyReadEvent)
{
	GTcpSocket *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GTcpSocket *) RING_API_GETCPOINTER(1,"QTcpSocket");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setreadyReadEvent(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QTcpSocket_getconnectedEvent)
{
	GTcpSocket *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GTcpSocket *) RING_API_GETCPOINTER(1,"QTcpSocket");
	RING_API_RETSTRING(pObject->getconnectedEvent());
}


RING_FUNC(ring_QTcpSocket_getdisconnectedEvent)
{
	GTcpSocket *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GTcpSocket *) RING_API_GETCPOINTER(1,"QTcpSocket");
	RING_API_RETSTRING(pObject->getdisconnectedEvent());
}


RING_FUNC(ring_QTcpSocket_geterrorEvent)
{
	GTcpSocket *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GTcpSocket *) RING_API_GETCPOINTER(1,"QTcpSocket");
	RING_API_RETSTRING(pObject->geterrorEvent());
}


RING_FUNC(ring_QTcpSocket_gethostFoundEvent)
{
	GTcpSocket *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GTcpSocket *) RING_API_GETCPOINTER(1,"QTcpSocket");
	RING_API_RETSTRING(pObject->gethostFoundEvent());
}


RING_FUNC(ring_QTcpSocket_getproxyAuthenticationRequiredEvent)
{
	GTcpSocket *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GTcpSocket *) RING_API_GETCPOINTER(1,"QTcpSocket");
	RING_API_RETSTRING(pObject->getproxyAuthenticationRequiredEvent());
}


RING_FUNC(ring_QTcpSocket_getstateChangedEvent)
{
	GTcpSocket *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GTcpSocket *) RING_API_GETCPOINTER(1,"QTcpSocket");
	RING_API_RETSTRING(pObject->getstateChangedEvent());
}


RING_FUNC(ring_QTcpSocket_getaboutToCloseEvent)
{
	GTcpSocket *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GTcpSocket *) RING_API_GETCPOINTER(1,"QTcpSocket");
	RING_API_RETSTRING(pObject->getaboutToCloseEvent());
}


RING_FUNC(ring_QTcpSocket_getbytesWrittenEvent)
{
	GTcpSocket *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GTcpSocket *) RING_API_GETCPOINTER(1,"QTcpSocket");
	RING_API_RETSTRING(pObject->getbytesWrittenEvent());
}


RING_FUNC(ring_QTcpSocket_getreadChannelFinishedEvent)
{
	GTcpSocket *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GTcpSocket *) RING_API_GETCPOINTER(1,"QTcpSocket");
	RING_API_RETSTRING(pObject->getreadChannelFinishedEvent());
}


RING_FUNC(ring_QTcpSocket_getreadyReadEvent)
{
	GTcpSocket *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GTcpSocket *) RING_API_GETCPOINTER(1,"QTcpSocket");
	RING_API_RETSTRING(pObject->getreadyReadEvent());
}


RING_FUNC(ring_QTcpServer_close)
{
	GTcpServer *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GTcpServer *) RING_API_GETCPOINTER(1,"QTcpServer");
	pObject->close();
}


RING_FUNC(ring_QTcpServer_errorString)
{
	GTcpServer *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GTcpServer *) RING_API_GETCPOINTER(1,"QTcpServer");
	RING_API_RETSTRING(pObject->errorString().toStdString().c_str());
}


RING_FUNC(ring_QTcpServer_hasPendingConnections)
{
	GTcpServer *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GTcpServer *) RING_API_GETCPOINTER(1,"QTcpServer");
	RING_API_RETNUMBER(pObject->hasPendingConnections());
}


RING_FUNC(ring_QTcpServer_isListening)
{
	GTcpServer *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GTcpServer *) RING_API_GETCPOINTER(1,"QTcpServer");
	RING_API_RETNUMBER(pObject->isListening());
}


RING_FUNC(ring_QTcpServer_listen)
{
	GTcpServer *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GTcpServer *) RING_API_GETCPOINTER(1,"QTcpServer");
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->listen(* (QHostAddress *) RING_API_GETCPOINTER(2,"QHostAddress"), (int ) RING_API_GETNUMBER(3)));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QHostAddress"));
}


RING_FUNC(ring_QTcpServer_maxPendingConnections)
{
	GTcpServer *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GTcpServer *) RING_API_GETCPOINTER(1,"QTcpServer");
	RING_API_RETNUMBER(pObject->maxPendingConnections());
}


RING_FUNC(ring_QTcpServer_nextPendingConnection)
{
	GTcpServer *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GTcpServer *) RING_API_GETCPOINTER(1,"QTcpServer");
	RING_API_RETCPOINTER(pObject->nextPendingConnection(),"QTcpSocket");
}


RING_FUNC(ring_QTcpServer_pauseAccepting)
{
	GTcpServer *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GTcpServer *) RING_API_GETCPOINTER(1,"QTcpServer");
	pObject->pauseAccepting();
}


RING_FUNC(ring_QTcpServer_proxy)
{
	GTcpServer *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GTcpServer *) RING_API_GETCPOINTER(1,"QTcpServer");
	{
		QNetworkProxy *pValue ; 
		pValue = new QNetworkProxy() ;
		*pValue = pObject->proxy();
		RING_API_RETMANAGEDCPOINTER(pValue,"QNetworkProxy",ring_QNetworkProxy_freefunc);
	}
}


RING_FUNC(ring_QTcpServer_resumeAccepting)
{
	GTcpServer *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GTcpServer *) RING_API_GETCPOINTER(1,"QTcpServer");
	pObject->resumeAccepting();
}


RING_FUNC(ring_QTcpServer_serverAddress)
{
	GTcpServer *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GTcpServer *) RING_API_GETCPOINTER(1,"QTcpServer");
	{
		QHostAddress *pValue ; 
		pValue = new QHostAddress() ;
		*pValue = pObject->serverAddress();
		RING_API_RETMANAGEDCPOINTER(pValue,"QHostAddress",ring_QHostAddress_freefunc);
	}
}


RING_FUNC(ring_QTcpServer_serverError)
{
	GTcpServer *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GTcpServer *) RING_API_GETCPOINTER(1,"QTcpServer");
	RING_API_RETNUMBER(pObject->serverError());
}


RING_FUNC(ring_QTcpServer_serverPort)
{
	GTcpServer *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GTcpServer *) RING_API_GETCPOINTER(1,"QTcpServer");
	RING_API_RETNUMBER(pObject->serverPort());
}


RING_FUNC(ring_QTcpServer_setMaxPendingConnections)
{
	GTcpServer *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GTcpServer *) RING_API_GETCPOINTER(1,"QTcpServer");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setMaxPendingConnections( (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QTcpServer_setProxy)
{
	GTcpServer *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GTcpServer *) RING_API_GETCPOINTER(1,"QTcpServer");
	pObject->setProxy(* (QNetworkProxy *) RING_API_GETCPOINTER(2,"QNetworkProxy"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QNetworkProxy"));
}


RING_FUNC(ring_QTcpServer_setSocketDescriptor)
{
	GTcpServer *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GTcpServer *) RING_API_GETCPOINTER(1,"QTcpServer");
	RING_API_RETNUMBER(pObject->setSocketDescriptor(* (qintptr  *) RING_API_GETCPOINTER(2,"qintptr")));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"qintptr"));
}


RING_FUNC(ring_QTcpServer_socketDescriptor)
{
	GTcpServer *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GTcpServer *) RING_API_GETCPOINTER(1,"QTcpServer");
	RING_API_RETCPOINTER(pObject->socketDescriptor(),"int");
}


RING_FUNC(ring_QTcpServer_waitForNewConnection)
{
	GTcpServer *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GTcpServer *) RING_API_GETCPOINTER(1,"QTcpServer");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->waitForNewConnection( (int ) RING_API_GETNUMBER(2),(bool *) RING_API_GETCPOINTER(3,"bool")));
}


RING_FUNC(ring_QTcpServer_setacceptErrorEvent)
{
	GTcpServer *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GTcpServer *) RING_API_GETCPOINTER(1,"QTcpServer");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setacceptErrorEvent(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QTcpServer_setnewConnectionEvent)
{
	GTcpServer *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GTcpServer *) RING_API_GETCPOINTER(1,"QTcpServer");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setnewConnectionEvent(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QTcpServer_getacceptErrorEvent)
{
	GTcpServer *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GTcpServer *) RING_API_GETCPOINTER(1,"QTcpServer");
	RING_API_RETSTRING(pObject->getacceptErrorEvent());
}


RING_FUNC(ring_QTcpServer_getnewConnectionEvent)
{
	GTcpServer *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GTcpServer *) RING_API_GETCPOINTER(1,"QTcpServer");
	RING_API_RETSTRING(pObject->getnewConnectionEvent());
}


RING_FUNC(ring_QHostAddress_clear)
{
	QHostAddress *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QHostAddress *) RING_API_GETCPOINTER(1,"QHostAddress");
	pObject->clear();
}


RING_FUNC(ring_QHostAddress_isInSubnet)
{
	QHostAddress *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QHostAddress *) RING_API_GETCPOINTER(1,"QHostAddress");
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->isInSubnet(* (QHostAddress *) RING_API_GETCPOINTER(2,"QHostAddress"), (int ) RING_API_GETNUMBER(3)));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QHostAddress"));
}


RING_FUNC(ring_QHostAddress_isNull)
{
	QHostAddress *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QHostAddress *) RING_API_GETCPOINTER(1,"QHostAddress");
	RING_API_RETNUMBER(pObject->isNull());
}


RING_FUNC(ring_QHostAddress_protocol)
{
	QHostAddress *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QHostAddress *) RING_API_GETCPOINTER(1,"QHostAddress");
	RING_API_RETNUMBER(pObject->protocol());
}


RING_FUNC(ring_QHostAddress_scopeId)
{
	QHostAddress *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QHostAddress *) RING_API_GETCPOINTER(1,"QHostAddress");
	RING_API_RETSTRING(pObject->scopeId().toStdString().c_str());
}


RING_FUNC(ring_QHostAddress_setAddress)
{
	QHostAddress *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QHostAddress *) RING_API_GETCPOINTER(1,"QHostAddress");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->setAddress(RING_API_GETSTRING(2)));
}


RING_FUNC(ring_QHostAddress_toIPv4Address)
{
	QHostAddress *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QHostAddress *) RING_API_GETCPOINTER(1,"QHostAddress");
	RING_API_RETNUMBER(pObject->toIPv4Address());
}


RING_FUNC(ring_QHostAddress_toIPv6Address)
{
	QHostAddress *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QHostAddress *) RING_API_GETCPOINTER(1,"QHostAddress");
	{
		Q_IPV6ADDR *pValue ; 
		pValue = (Q_IPV6ADDR *) RING_API_MALLOC(sizeof(Q_IPV6ADDR)) ;
		*pValue = pObject->toIPv6Address();
		RING_API_RETMANAGEDCPOINTER(pValue,"Q_IPV6ADDR",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QHostAddress_toString)
{
	QHostAddress *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QHostAddress *) RING_API_GETCPOINTER(1,"QHostAddress");
	RING_API_RETSTRING(pObject->toString().toStdString().c_str());
}


RING_FUNC(ring_QHostInfo_error)
{
	QHostInfo *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QHostInfo *) RING_API_GETCPOINTER(1,"QHostInfo");
	RING_API_RETNUMBER(pObject->error());
}


RING_FUNC(ring_QHostInfo_errorString)
{
	QHostInfo *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QHostInfo *) RING_API_GETCPOINTER(1,"QHostInfo");
	RING_API_RETSTRING(pObject->errorString().toStdString().c_str());
}


RING_FUNC(ring_QHostInfo_hostName)
{
	QHostInfo *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QHostInfo *) RING_API_GETCPOINTER(1,"QHostInfo");
	RING_API_RETSTRING(pObject->hostName().toStdString().c_str());
}


RING_FUNC(ring_QHostInfo_lookupId)
{
	QHostInfo *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QHostInfo *) RING_API_GETCPOINTER(1,"QHostInfo");
	RING_API_RETNUMBER(pObject->lookupId());
}


RING_FUNC(ring_QHostInfo_setError)
{
	QHostInfo *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QHostInfo *) RING_API_GETCPOINTER(1,"QHostInfo");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setError( (QHostInfo::HostInfoError )  (int) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QHostInfo_setErrorString)
{
	QHostInfo *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QHostInfo *) RING_API_GETCPOINTER(1,"QHostInfo");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setErrorString(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QHostInfo_setHostName)
{
	QHostInfo *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QHostInfo *) RING_API_GETCPOINTER(1,"QHostInfo");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setHostName(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QHostInfo_setLookupId)
{
	QHostInfo *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QHostInfo *) RING_API_GETCPOINTER(1,"QHostInfo");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setLookupId( (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QHostInfo_abortHostLookup)
{
	QHostInfo *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QHostInfo *) RING_API_GETCPOINTER(1,"QHostInfo");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->abortHostLookup( (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QHostInfo_fromName)
{
	QHostInfo *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QHostInfo *) RING_API_GETCPOINTER(1,"QHostInfo");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QHostInfo *pValue ; 
		pValue = new QHostInfo() ;
		*pValue = pObject->fromName(RING_API_GETSTRING(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"QHostInfo",ring_QHostInfo_freefunc);
	}
}


RING_FUNC(ring_QHostInfo_localDomainName)
{
	QHostInfo *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QHostInfo *) RING_API_GETCPOINTER(1,"QHostInfo");
	RING_API_RETSTRING(pObject->localDomainName().toStdString().c_str());
}


RING_FUNC(ring_QHostInfo_localHostName)
{
	QHostInfo *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QHostInfo *) RING_API_GETCPOINTER(1,"QHostInfo");
	RING_API_RETSTRING(pObject->localHostName().toStdString().c_str());
}


RING_FUNC(ring_QNetworkRequest_attribute)
{
	QNetworkRequest *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QNetworkRequest *) RING_API_GETCPOINTER(1,"QNetworkRequest");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QVariant *pValue ; 
		pValue = new QVariant() ;
		*pValue = pObject->attribute( (QNetworkRequest::Attribute)  (int) RING_API_GETNUMBER(2),* (QVariant *) RING_API_GETCPOINTER(3,"QVariant"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"QVariant"));
		RING_API_RETMANAGEDCPOINTER(pValue,"QVariant",ring_QVariant_freefunc);
	}
}


RING_FUNC(ring_QNetworkRequest_hasRawHeader)
{
	QNetworkRequest *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QNetworkRequest *) RING_API_GETCPOINTER(1,"QNetworkRequest");
	RING_API_RETNUMBER(pObject->hasRawHeader(* (QByteArray *) RING_API_GETCPOINTER(2,"QByteArray")));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QByteArray"));
}


RING_FUNC(ring_QNetworkRequest_header)
{
	QNetworkRequest *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QNetworkRequest *) RING_API_GETCPOINTER(1,"QNetworkRequest");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QVariant *pValue ; 
		pValue = new QVariant() ;
		*pValue = pObject->header( (QNetworkRequest::KnownHeaders)  (int) RING_API_GETNUMBER(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"QVariant",ring_QVariant_freefunc);
	}
}


RING_FUNC(ring_QNetworkRequest_originatingObject)
{
	QNetworkRequest *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QNetworkRequest *) RING_API_GETCPOINTER(1,"QNetworkRequest");
	RING_API_RETCPOINTER(pObject->originatingObject(),"QObject");
}


RING_FUNC(ring_QNetworkRequest_priority)
{
	QNetworkRequest *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QNetworkRequest *) RING_API_GETCPOINTER(1,"QNetworkRequest");
	RING_API_RETNUMBER(pObject->priority());
}


RING_FUNC(ring_QNetworkRequest_rawHeader)
{
	QNetworkRequest *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QNetworkRequest *) RING_API_GETCPOINTER(1,"QNetworkRequest");
	{
		QByteArray *pValue ; 
		pValue = new QByteArray() ;
		*pValue = pObject->rawHeader(* (QByteArray *) RING_API_GETCPOINTER(2,"QByteArray"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QByteArray"));
		RING_API_RETMANAGEDCPOINTER(pValue,"QByteArray",ring_QByteArray_freefunc);
	}
}


RING_FUNC(ring_QNetworkRequest_setAttribute)
{
	QNetworkRequest *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QNetworkRequest *) RING_API_GETCPOINTER(1,"QNetworkRequest");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setAttribute( (QNetworkRequest::Attribute)  (int) RING_API_GETNUMBER(2),* (QVariant *) RING_API_GETCPOINTER(3,"QVariant"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"QVariant"));
}


RING_FUNC(ring_QNetworkRequest_setHeader)
{
	QNetworkRequest *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QNetworkRequest *) RING_API_GETCPOINTER(1,"QNetworkRequest");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setHeader( (QNetworkRequest::KnownHeaders)  (int) RING_API_GETNUMBER(2),* (QVariant *) RING_API_GETCPOINTER(3,"QVariant"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"QVariant"));
}


RING_FUNC(ring_QNetworkRequest_setOriginatingObject)
{
	QNetworkRequest *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QNetworkRequest *) RING_API_GETCPOINTER(1,"QNetworkRequest");
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setOriginatingObject((QObject *) RING_API_GETCPOINTER(2,"QObject"));
}


RING_FUNC(ring_QNetworkRequest_setPriority)
{
	QNetworkRequest *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QNetworkRequest *) RING_API_GETCPOINTER(1,"QNetworkRequest");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setPriority( (QNetworkRequest::Priority )  (int) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QNetworkRequest_setRawHeader)
{
	QNetworkRequest *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QNetworkRequest *) RING_API_GETCPOINTER(1,"QNetworkRequest");
	pObject->setRawHeader(* (QByteArray *) RING_API_GETCPOINTER(2,"QByteArray"),* (QByteArray *) RING_API_GETCPOINTER(3,"QByteArray"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QByteArray"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"QByteArray"));
}


RING_FUNC(ring_QNetworkRequest_setUrl)
{
	QNetworkRequest *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QNetworkRequest *) RING_API_GETCPOINTER(1,"QNetworkRequest");
	pObject->setUrl(* (QUrl *) RING_API_GETCPOINTER(2,"QUrl"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QUrl"));
}


RING_FUNC(ring_QNetworkRequest_swap)
{
	QNetworkRequest *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QNetworkRequest *) RING_API_GETCPOINTER(1,"QNetworkRequest");
	pObject->swap(* (QNetworkRequest *) RING_API_GETCPOINTER(2,"QNetworkRequest"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QNetworkRequest"));
}


RING_FUNC(ring_QNetworkRequest_url)
{
	QNetworkRequest *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QNetworkRequest *) RING_API_GETCPOINTER(1,"QNetworkRequest");
	{
		QUrl *pValue ; 
		pValue = new QUrl() ;
		*pValue = pObject->url();
		RING_API_RETMANAGEDCPOINTER(pValue,"QUrl",ring_QUrl_freefunc);
	}
}


RING_FUNC(ring_QNetworkReply_attribute)
{
	QNetworkReply *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QNetworkReply *) RING_API_GETCPOINTER(1,"QNetworkReply");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QVariant *pValue ; 
		pValue = new QVariant() ;
		*pValue = pObject->attribute( (QNetworkRequest::Attribute )  (int) RING_API_GETNUMBER(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"QVariant",ring_QVariant_freefunc);
	}
}


RING_FUNC(ring_QNetworkReply_error)
{
	QNetworkReply *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QNetworkReply *) RING_API_GETCPOINTER(1,"QNetworkReply");
	RING_API_RETNUMBER(pObject->error());
}


RING_FUNC(ring_QNetworkReply_hasRawHeader)
{
	QNetworkReply *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QNetworkReply *) RING_API_GETCPOINTER(1,"QNetworkReply");
	RING_API_RETNUMBER(pObject->hasRawHeader(* (QByteArray *) RING_API_GETCPOINTER(2,"QByteArray")));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QByteArray"));
}


RING_FUNC(ring_QNetworkReply_header)
{
	QNetworkReply *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QNetworkReply *) RING_API_GETCPOINTER(1,"QNetworkReply");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QVariant *pValue ; 
		pValue = new QVariant() ;
		*pValue = pObject->header( (QNetworkRequest::KnownHeaders )  (int) RING_API_GETNUMBER(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"QVariant",ring_QVariant_freefunc);
	}
}


RING_FUNC(ring_QNetworkReply_isFinished)
{
	QNetworkReply *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QNetworkReply *) RING_API_GETCPOINTER(1,"QNetworkReply");
	RING_API_RETNUMBER(pObject->isFinished());
}


RING_FUNC(ring_QNetworkReply_isRunning)
{
	QNetworkReply *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QNetworkReply *) RING_API_GETCPOINTER(1,"QNetworkReply");
	RING_API_RETNUMBER(pObject->isRunning());
}


RING_FUNC(ring_QNetworkReply_manager)
{
	QNetworkReply *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QNetworkReply *) RING_API_GETCPOINTER(1,"QNetworkReply");
	RING_API_RETCPOINTER(pObject->manager(),"QNetworkAccessManager");
}


RING_FUNC(ring_QNetworkReply_operation)
{
	QNetworkReply *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QNetworkReply *) RING_API_GETCPOINTER(1,"QNetworkReply");
	{
		QNetworkAccessManager::Operation *pValue ; 
		pValue = (QNetworkAccessManager::Operation *) RING_API_MALLOC(sizeof(QNetworkAccessManager::Operation)) ;
		*pValue = pObject->operation();
		RING_API_RETMANAGEDCPOINTER(pValue,"QNetworkAccessManager::Operation",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QNetworkReply_rawHeader)
{
	QNetworkReply *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QNetworkReply *) RING_API_GETCPOINTER(1,"QNetworkReply");
	{
		QByteArray *pValue ; 
		pValue = new QByteArray() ;
		*pValue = pObject->rawHeader(* (QByteArray *) RING_API_GETCPOINTER(2,"QByteArray"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QByteArray"));
		RING_API_RETMANAGEDCPOINTER(pValue,"QByteArray",ring_QByteArray_freefunc);
	}
}


RING_FUNC(ring_QNetworkReply_readBufferSize)
{
	QNetworkReply *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QNetworkReply *) RING_API_GETCPOINTER(1,"QNetworkReply");
	RING_API_RETNUMBER(pObject->readBufferSize());
}


RING_FUNC(ring_QNetworkReply_request)
{
	QNetworkReply *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QNetworkReply *) RING_API_GETCPOINTER(1,"QNetworkReply");
	{
		QNetworkRequest *pValue ; 
		pValue = new QNetworkRequest() ;
		*pValue = pObject->request();
		RING_API_RETMANAGEDCPOINTER(pValue,"QNetworkRequest",ring_QNetworkRequest_freefunc);
	}
}


RING_FUNC(ring_QNetworkReply_url)
{
	QNetworkReply *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QNetworkReply *) RING_API_GETCPOINTER(1,"QNetworkReply");
	{
		QUrl *pValue ; 
		pValue = new QUrl() ;
		*pValue = pObject->url();
		RING_API_RETMANAGEDCPOINTER(pValue,"QUrl",ring_QUrl_freefunc);
	}
}


RING_FUNC(ring_QNetworkAccessManager_setfinishedEvent)
{
	GNetworkAccessManager *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GNetworkAccessManager *) RING_API_GETCPOINTER(1,"QNetworkAccessManager");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setfinishedEvent(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QNetworkAccessManager_getfinishedEvent)
{
	GNetworkAccessManager *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GNetworkAccessManager *) RING_API_GETCPOINTER(1,"QNetworkAccessManager");
	RING_API_RETSTRING(pObject->getfinishedEvent());
}


RING_FUNC(ring_QNetworkAccessManager_cache)
{
	GNetworkAccessManager *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GNetworkAccessManager *) RING_API_GETCPOINTER(1,"QNetworkAccessManager");
	RING_API_RETCPOINTER(pObject->cache(),"QAbstractNetworkCache");
}


RING_FUNC(ring_QNetworkAccessManager_clearAccessCache)
{
	GNetworkAccessManager *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GNetworkAccessManager *) RING_API_GETCPOINTER(1,"QNetworkAccessManager");
	pObject->clearAccessCache();
}


RING_FUNC(ring_QNetworkAccessManager_connectToHost)
{
	GNetworkAccessManager *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GNetworkAccessManager *) RING_API_GETCPOINTER(1,"QNetworkAccessManager");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->connectToHost(RING_API_GETSTRING(2), (quint16) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_QNetworkAccessManager_cookieJar)
{
	GNetworkAccessManager *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GNetworkAccessManager *) RING_API_GETCPOINTER(1,"QNetworkAccessManager");
	RING_API_RETCPOINTER(pObject->cookieJar(),"QNetworkCookieJar");
}


RING_FUNC(ring_QNetworkAccessManager_deleteResource)
{
	GNetworkAccessManager *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GNetworkAccessManager *) RING_API_GETCPOINTER(1,"QNetworkAccessManager");
	RING_API_RETCPOINTER(pObject->deleteResource(* (QNetworkRequest *) RING_API_GETCPOINTER(2,"QNetworkRequest")),"QNetworkReply");
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QNetworkRequest"));
}


RING_FUNC(ring_QNetworkAccessManager_get)
{
	GNetworkAccessManager *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GNetworkAccessManager *) RING_API_GETCPOINTER(1,"QNetworkAccessManager");
	RING_API_RETCPOINTER(pObject->get(* (QNetworkRequest *) RING_API_GETCPOINTER(2,"QNetworkRequest")),"QNetworkReply");
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QNetworkRequest"));
}


RING_FUNC(ring_QNetworkAccessManager_head)
{
	GNetworkAccessManager *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GNetworkAccessManager *) RING_API_GETCPOINTER(1,"QNetworkAccessManager");
	RING_API_RETCPOINTER(pObject->head(* (QNetworkRequest *) RING_API_GETCPOINTER(2,"QNetworkRequest")),"QNetworkReply");
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QNetworkRequest"));
}


RING_FUNC(ring_QNetworkAccessManager_post)
{
	GNetworkAccessManager *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GNetworkAccessManager *) RING_API_GETCPOINTER(1,"QNetworkAccessManager");
	RING_API_RETCPOINTER(pObject->post(* (QNetworkRequest *) RING_API_GETCPOINTER(2,"QNetworkRequest"),* (QByteArray *) RING_API_GETCPOINTER(3,"QByteArray")),"QNetworkReply");
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QNetworkRequest"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"QByteArray"));
}


RING_FUNC(ring_QNetworkAccessManager_proxy)
{
	GNetworkAccessManager *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GNetworkAccessManager *) RING_API_GETCPOINTER(1,"QNetworkAccessManager");
	{
		QNetworkProxy *pValue ; 
		pValue = new QNetworkProxy() ;
		*pValue = pObject->proxy();
		RING_API_RETMANAGEDCPOINTER(pValue,"QNetworkProxy",ring_QNetworkProxy_freefunc);
	}
}


RING_FUNC(ring_QNetworkAccessManager_proxyFactory)
{
	GNetworkAccessManager *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GNetworkAccessManager *) RING_API_GETCPOINTER(1,"QNetworkAccessManager");
	RING_API_RETCPOINTER(pObject->proxyFactory(),"QNetworkProxyFactory");
}


RING_FUNC(ring_QNetworkAccessManager_put)
{
	GNetworkAccessManager *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GNetworkAccessManager *) RING_API_GETCPOINTER(1,"QNetworkAccessManager");
	RING_API_RETCPOINTER(pObject->put(* (QNetworkRequest *) RING_API_GETCPOINTER(2,"QNetworkRequest"),* (QByteArray *) RING_API_GETCPOINTER(3,"QByteArray")),"QNetworkReply");
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QNetworkRequest"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"QByteArray"));
}


RING_FUNC(ring_QNetworkAccessManager_sendCustomRequest)
{
	GNetworkAccessManager *pObject ;
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GNetworkAccessManager *) RING_API_GETCPOINTER(1,"QNetworkAccessManager");
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(pObject->sendCustomRequest(* (QNetworkRequest *) RING_API_GETCPOINTER(2,"QNetworkRequest"),* (QByteArray *) RING_API_GETCPOINTER(3,"QByteArray"),(QIODevice *) RING_API_GETCPOINTER(4,"QIODevice")),"QNetworkReply");
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QNetworkRequest"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"QByteArray"));
}


RING_FUNC(ring_QNetworkAccessManager_setCache)
{
	GNetworkAccessManager *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GNetworkAccessManager *) RING_API_GETCPOINTER(1,"QNetworkAccessManager");
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setCache((QAbstractNetworkCache *) RING_API_GETCPOINTER(2,"QAbstractNetworkCache"));
}


RING_FUNC(ring_QNetworkAccessManager_setCookieJar)
{
	GNetworkAccessManager *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GNetworkAccessManager *) RING_API_GETCPOINTER(1,"QNetworkAccessManager");
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setCookieJar((QNetworkCookieJar *) RING_API_GETCPOINTER(2,"QNetworkCookieJar"));
}


RING_FUNC(ring_QNetworkAccessManager_setProxy)
{
	GNetworkAccessManager *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GNetworkAccessManager *) RING_API_GETCPOINTER(1,"QNetworkAccessManager");
	pObject->setProxy(* (QNetworkProxy *) RING_API_GETCPOINTER(2,"QNetworkProxy"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QNetworkProxy"));
}


RING_FUNC(ring_QNetworkAccessManager_setProxyFactory)
{
	GNetworkAccessManager *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GNetworkAccessManager *) RING_API_GETCPOINTER(1,"QNetworkAccessManager");
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setProxyFactory((QNetworkProxyFactory *) RING_API_GETCPOINTER(2,"QNetworkProxyFactory"));
}


RING_FUNC(ring_QNetworkAccessManager_supportedSchemes)
{
	GNetworkAccessManager *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GNetworkAccessManager *) RING_API_GETCPOINTER(1,"QNetworkAccessManager");
	{
		QStringList *pValue ; 
		pValue = new QStringList() ;
		*pValue = pObject->supportedSchemes();
		RING_API_RETMANAGEDCPOINTER(pValue,"QStringList",ring_QStringList_freefunc);
	}
}


RING_FUNC(ring_QNetworkAccessManager_geteventparameters)
{
	GNetworkAccessManager *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GNetworkAccessManager *) RING_API_GETCPOINTER(1,"QNetworkAccessManager");
	pObject->geteventparameters();
}


RING_FUNC(ring_QQmlError_column)
{
	QQmlError *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QQmlError *) RING_API_GETCPOINTER(1,"QQmlError");
	RING_API_RETNUMBER(pObject->column());
}


RING_FUNC(ring_QQmlError_description)
{
	QQmlError *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QQmlError *) RING_API_GETCPOINTER(1,"QQmlError");
	RING_API_RETSTRING(pObject->description().toStdString().c_str());
}


RING_FUNC(ring_QQmlError_isValid)
{
	QQmlError *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QQmlError *) RING_API_GETCPOINTER(1,"QQmlError");
	RING_API_RETNUMBER(pObject->isValid());
}


RING_FUNC(ring_QQmlError_line)
{
	QQmlError *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QQmlError *) RING_API_GETCPOINTER(1,"QQmlError");
	RING_API_RETNUMBER(pObject->line());
}


RING_FUNC(ring_QQmlError_object)
{
	QQmlError *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QQmlError *) RING_API_GETCPOINTER(1,"QQmlError");
	RING_API_RETCPOINTER(pObject->object(),"QObject");
}


RING_FUNC(ring_QQmlError_setColumn)
{
	QQmlError *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QQmlError *) RING_API_GETCPOINTER(1,"QQmlError");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setColumn( (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QQmlError_setDescription)
{
	QQmlError *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QQmlError *) RING_API_GETCPOINTER(1,"QQmlError");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setDescription(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QQmlError_setLine)
{
	QQmlError *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QQmlError *) RING_API_GETCPOINTER(1,"QQmlError");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setLine( (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QQmlError_setObject)
{
	QQmlError *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QQmlError *) RING_API_GETCPOINTER(1,"QQmlError");
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setObject((QObject *) RING_API_GETCPOINTER(2,"QObject"));
}


RING_FUNC(ring_QQmlError_setUrl)
{
	QQmlError *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QQmlError *) RING_API_GETCPOINTER(1,"QQmlError");
	pObject->setUrl(* (QUrl  *) RING_API_GETCPOINTER(2,"QUrl"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QUrl"));
}


RING_FUNC(ring_QQmlError_toString)
{
	QQmlError *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QQmlError *) RING_API_GETCPOINTER(1,"QQmlError");
	RING_API_RETSTRING(pObject->toString().toStdString().c_str());
}


RING_FUNC(ring_QQmlError_url)
{
	QQmlError *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QQmlError *) RING_API_GETCPOINTER(1,"QQmlError");
	{
		QUrl *pValue ; 
		pValue = new QUrl() ;
		*pValue = pObject->url();
		RING_API_RETMANAGEDCPOINTER(pValue,"QUrl",ring_QUrl_freefunc);
	}
}


RING_FUNC(ring_QQmlEngine_addImageProvider)
{
	QQmlEngine *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QQmlEngine *) RING_API_GETCPOINTER(1,"QQmlEngine");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->addImageProvider(RING_API_GETSTRING(2),(QQmlImageProviderBase *) RING_API_GETCPOINTER(3,"QQmlImageProviderBase"));
}


RING_FUNC(ring_QQmlEngine_addImportPath)
{
	QQmlEngine *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QQmlEngine *) RING_API_GETCPOINTER(1,"QQmlEngine");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->addImportPath(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QQmlEngine_addPluginPath)
{
	QQmlEngine *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QQmlEngine *) RING_API_GETCPOINTER(1,"QQmlEngine");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->addPluginPath(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QQmlEngine_baseUrl)
{
	QQmlEngine *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QQmlEngine *) RING_API_GETCPOINTER(1,"QQmlEngine");
	{
		QUrl *pValue ; 
		pValue = new QUrl() ;
		*pValue = pObject->baseUrl();
		RING_API_RETMANAGEDCPOINTER(pValue,"QUrl",ring_QUrl_freefunc);
	}
}


RING_FUNC(ring_QQmlEngine_clearComponentCache)
{
	QQmlEngine *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QQmlEngine *) RING_API_GETCPOINTER(1,"QQmlEngine");
	pObject->clearComponentCache();
}


RING_FUNC(ring_QQmlEngine_imageProvider)
{
	QQmlEngine *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QQmlEngine *) RING_API_GETCPOINTER(1,"QQmlEngine");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(pObject->imageProvider(RING_API_GETSTRING(2)),"QQmlImageProviderBase");
}


RING_FUNC(ring_QQmlEngine_importPathList)
{
	QQmlEngine *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QQmlEngine *) RING_API_GETCPOINTER(1,"QQmlEngine");
	{
		QStringList *pValue ; 
		pValue = new QStringList() ;
		*pValue = pObject->importPathList();
		RING_API_RETMANAGEDCPOINTER(pValue,"QStringList",ring_QStringList_freefunc);
	}
}


RING_FUNC(ring_QQmlEngine_importPlugin)
{
	QQmlEngine *pObject ;
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QQmlEngine *) RING_API_GETCPOINTER(1,"QQmlEngine");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->importPlugin(RING_API_GETSTRING(2),RING_API_GETSTRING(3),(QList<QQmlError> *) RING_API_GETCPOINTER(4,"QList<QQmlError>")));
}


RING_FUNC(ring_QQmlEngine_incubationController)
{
	QQmlEngine *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QQmlEngine *) RING_API_GETCPOINTER(1,"QQmlEngine");
	RING_API_RETCPOINTER(pObject->incubationController(),"QQmlIncubationController");
}


RING_FUNC(ring_QQmlEngine_networkAccessManager)
{
	QQmlEngine *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QQmlEngine *) RING_API_GETCPOINTER(1,"QQmlEngine");
	RING_API_RETCPOINTER(pObject->networkAccessManager(),"QNetworkAccessManager");
}


RING_FUNC(ring_QQmlEngine_networkAccessManagerFactory)
{
	QQmlEngine *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QQmlEngine *) RING_API_GETCPOINTER(1,"QQmlEngine");
	RING_API_RETCPOINTER(pObject->networkAccessManagerFactory(),"QQmlNetworkAccessManagerFactory");
}


RING_FUNC(ring_QQmlEngine_offlineStorageDatabaseFilePath)
{
	QQmlEngine *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QQmlEngine *) RING_API_GETCPOINTER(1,"QQmlEngine");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->offlineStorageDatabaseFilePath(RING_API_GETSTRING(2)).toStdString().c_str());
}


RING_FUNC(ring_QQmlEngine_offlineStoragePath)
{
	QQmlEngine *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QQmlEngine *) RING_API_GETCPOINTER(1,"QQmlEngine");
	RING_API_RETSTRING(pObject->offlineStoragePath().toStdString().c_str());
}


RING_FUNC(ring_QQmlEngine_outputWarningsToStandardError)
{
	QQmlEngine *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QQmlEngine *) RING_API_GETCPOINTER(1,"QQmlEngine");
	RING_API_RETNUMBER(pObject->outputWarningsToStandardError());
}


RING_FUNC(ring_QQmlEngine_pluginPathList)
{
	QQmlEngine *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QQmlEngine *) RING_API_GETCPOINTER(1,"QQmlEngine");
	{
		QStringList *pValue ; 
		pValue = new QStringList() ;
		*pValue = pObject->pluginPathList();
		RING_API_RETMANAGEDCPOINTER(pValue,"QStringList",ring_QStringList_freefunc);
	}
}


RING_FUNC(ring_QQmlEngine_removeImageProvider)
{
	QQmlEngine *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QQmlEngine *) RING_API_GETCPOINTER(1,"QQmlEngine");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->removeImageProvider(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QQmlEngine_rootContext)
{
	QQmlEngine *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QQmlEngine *) RING_API_GETCPOINTER(1,"QQmlEngine");
	RING_API_RETCPOINTER(pObject->rootContext(),"QQmlContext");
}


RING_FUNC(ring_QQmlEngine_setBaseUrl)
{
	QQmlEngine *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QQmlEngine *) RING_API_GETCPOINTER(1,"QQmlEngine");
	pObject->setBaseUrl(* (QUrl  *) RING_API_GETCPOINTER(2,"QUrl"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QUrl"));
}


RING_FUNC(ring_QQmlEngine_setImportPathList)
{
	QQmlEngine *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QQmlEngine *) RING_API_GETCPOINTER(1,"QQmlEngine");
	pObject->setImportPathList(* (QStringList  *) RING_API_GETCPOINTER(2,"QStringList"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QStringList"));
}


RING_FUNC(ring_QQmlEngine_setIncubationController)
{
	QQmlEngine *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QQmlEngine *) RING_API_GETCPOINTER(1,"QQmlEngine");
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setIncubationController((QQmlIncubationController *) RING_API_GETCPOINTER(2,"QQmlIncubationController"));
}


RING_FUNC(ring_QQmlEngine_setNetworkAccessManagerFactory)
{
	QQmlEngine *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QQmlEngine *) RING_API_GETCPOINTER(1,"QQmlEngine");
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setNetworkAccessManagerFactory((QQmlNetworkAccessManagerFactory *) RING_API_GETCPOINTER(2,"QQmlNetworkAccessManagerFactory"));
}


RING_FUNC(ring_QQmlEngine_setOfflineStoragePath)
{
	QQmlEngine *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QQmlEngine *) RING_API_GETCPOINTER(1,"QQmlEngine");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setOfflineStoragePath(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QQmlEngine_setOutputWarningsToStandardError)
{
	QQmlEngine *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QQmlEngine *) RING_API_GETCPOINTER(1,"QQmlEngine");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setOutputWarningsToStandardError( (bool ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QQmlEngine_setPluginPathList)
{
	QQmlEngine *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QQmlEngine *) RING_API_GETCPOINTER(1,"QQmlEngine");
	pObject->setPluginPathList(* (QStringList  *) RING_API_GETCPOINTER(2,"QStringList"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QStringList"));
}


RING_FUNC(ring_QQmlEngine_trimComponentCache)
{
	QQmlEngine *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QQmlEngine *) RING_API_GETCPOINTER(1,"QQmlEngine");
	pObject->trimComponentCache();
}


RING_FUNC(ring_QQmlEngine_retranslate)
{
	QQmlEngine *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QQmlEngine *) RING_API_GETCPOINTER(1,"QQmlEngine");
	pObject->retranslate();
}


RING_FUNC(ring_QQmlEngine_contextForObject)
{
	QQmlEngine *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QQmlEngine *) RING_API_GETCPOINTER(1,"QQmlEngine");
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(pObject->contextForObject((QObject *) RING_API_GETCPOINTER(2,"QObject")),"QQmlContext");
}


RING_FUNC(ring_QQmlEngine_objectOwnership)
{
	QQmlEngine *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QQmlEngine *) RING_API_GETCPOINTER(1,"QQmlEngine");
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->objectOwnership((QObject *) RING_API_GETCPOINTER(2,"QObject")));
}


RING_FUNC(ring_QQmlEngine_setContextForObject)
{
	QQmlEngine *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QQmlEngine *) RING_API_GETCPOINTER(1,"QQmlEngine");
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setContextForObject((QObject *) RING_API_GETCPOINTER(2,"QObject"),(QQmlContext *) RING_API_GETCPOINTER(3,"QQmlContext"));
}


RING_FUNC(ring_QQmlEngine_setObjectOwnership)
{
	QQmlEngine *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QQmlEngine *) RING_API_GETCPOINTER(1,"QQmlEngine");
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setObjectOwnership((QObject *) RING_API_GETCPOINTER(2,"QObject"), (QQmlEngine::ObjectOwnership )  (int) RING_API_GETNUMBER(3));
}

RING_FUNC(ring_QObject_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	QObject *pObject = new QObject();
	RING_API_RETCPOINTER(pObject,"QObject");
}

RING_FUNC(ring_QSize_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	QSize *pObject = new QSize((int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2));
	RING_API_RETMANAGEDCPOINTER(pObject,"QSize",ring_QSize_freefunc);
}

RING_FUNC(ring_QDir_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	QDir *pObject = new QDir();
	RING_API_RETMANAGEDCPOINTER(pObject,"QDir",ring_QDir_freefunc);
}

RING_FUNC(ring_QUrl_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	QUrl *pObject = new QUrl(RING_API_GETSTRING(1));
	RING_API_RETCPOINTER(pObject,"QUrl");
}

RING_FUNC(ring_QEvent_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	QEvent *pObject = new QEvent((QEvent::Type )  (int) RING_API_GETNUMBER(1));
	RING_API_RETCPOINTER(pObject,"QEvent");
}

RING_FUNC(ring_QTimer_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	GTimer *pObject = new GTimer((QObject *) RING_API_GETCPOINTER(1,"QObject"), (VM *) pPointer);
	RING_API_RETCPOINTER(pObject,"QTimer");
}

RING_FUNC(ring_QByteArray_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	QByteArray *pObject = new QByteArray();
	RING_API_RETCPOINTER(pObject,"QByteArray");
}

RING_FUNC(ring_QFileInfo_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	QFileInfo *pObject = new QFileInfo();
	RING_API_RETCPOINTER(pObject,"QFileInfo");
}

RING_FUNC(ring_QStringList_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	QStringList *pObject = new QStringList();
	RING_API_RETMANAGEDCPOINTER(pObject,"QStringList",ring_QStringList_freefunc);
}

RING_FUNC(ring_QTime_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	QTime *pObject = new QTime();
	RING_API_RETCPOINTER(pObject,"QTime");
}

RING_FUNC(ring_QDate_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	QDate *pObject = new QDate();
	RING_API_RETCPOINTER(pObject,"QDate");
}

RING_FUNC(ring_QVariant_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	QVariant *pObject = new QVariant();
	RING_API_RETCPOINTER(pObject,"QVariant");
}

RING_FUNC(ring_QVariant2_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	QVariant *pObject = new QVariant((int) RING_API_GETNUMBER(1));
	RING_API_RETCPOINTER(pObject,"QVariant2");
}

RING_FUNC(ring_QVariant3_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	QVariant *pObject = new QVariant((float) RING_API_GETNUMBER(1));
	RING_API_RETCPOINTER(pObject,"QVariant3");
}

RING_FUNC(ring_QVariant4_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	QVariant *pObject = new QVariant((double) RING_API_GETNUMBER(1));
	RING_API_RETCPOINTER(pObject,"QVariant4");
}

RING_FUNC(ring_QVariantInt_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	QVariant *pObject = new QVariant((int) RING_API_GETNUMBER(1));
	RING_API_RETCPOINTER(pObject,"QVariantInt");
}

RING_FUNC(ring_QVariantFloat_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	QVariant *pObject = new QVariant((float) RING_API_GETNUMBER(1));
	RING_API_RETCPOINTER(pObject,"QVariantFloat");
}

RING_FUNC(ring_QVariantDouble_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	QVariant *pObject = new QVariant((double) RING_API_GETNUMBER(1));
	RING_API_RETCPOINTER(pObject,"QVariantDouble");
}

RING_FUNC(ring_QJsonArray_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	QJsonArray *pObject = new QJsonArray();
	RING_API_RETCPOINTER(pObject,"QJsonArray");
}

RING_FUNC(ring_QJsonDocument_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	QJsonDocument *pObject = new QJsonDocument();
	RING_API_RETCPOINTER(pObject,"QJsonDocument");
}

RING_FUNC(ring_QJsonObject_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	QJsonObject *pObject = new QJsonObject();
	RING_API_RETCPOINTER(pObject,"QJsonObject");
}

RING_FUNC(ring_QJsonParseError_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	QJsonParseError *pObject = new QJsonParseError();
	RING_API_RETCPOINTER(pObject,"QJsonParseError");
}

RING_FUNC(ring_QJsonValue_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	QJsonValue *pObject = new QJsonValue();
	RING_API_RETCPOINTER(pObject,"QJsonValue");
}

RING_FUNC(ring_QString2_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	QString *pObject = new QString();
	RING_API_RETMANAGEDCPOINTER(pObject,"QString2",ring_QString2_freefunc);
}

RING_FUNC(ring_QBuffer_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	QBuffer *pObject = new QBuffer((QObject *) RING_API_GETCPOINTER(1,"QObject"));
	RING_API_RETCPOINTER(pObject,"QBuffer");
}

RING_FUNC(ring_QDateTime_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	QDateTime *pObject = new QDateTime();
	RING_API_RETCPOINTER(pObject,"QDateTime");
}

RING_FUNC(ring_QFile_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	QFile *pObject = new QFile();
	RING_API_RETCPOINTER(pObject,"QFile");
}

RING_FUNC(ring_QFile2_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	QFile *pObject = new QFile(RING_API_GETSTRING(1));
	RING_API_RETCPOINTER(pObject,"QFile2");
}

RING_FUNC(ring_QMimeData_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	QMimeData *pObject = new QMimeData();
	RING_API_RETCPOINTER(pObject,"QMimeData");
}

RING_FUNC(ring_QChar_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	QChar *pObject = new QChar((int) RING_API_GETNUMBER(1));
	RING_API_RETCPOINTER(pObject,"QChar");
}

RING_FUNC(ring_QChildEvent_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	QChildEvent *pObject = new QChildEvent((QEvent::Type)  (int) RING_API_GETNUMBER(1),(QObject *) RING_API_GETCPOINTER(2,"QObject"));
	RING_API_RETCPOINTER(pObject,"QChildEvent");
}

RING_FUNC(ring_QLocale_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	QLocale *pObject = new QLocale(RING_API_GETSTRING(1));
	RING_API_RETCPOINTER(pObject,"QLocale");
}

RING_FUNC(ring_QThread_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	GThread *pObject = new GThread((QObject *) RING_API_GETCPOINTER(1,"QObject"), (VM *) pPointer);
	RING_API_RETCPOINTER(pObject,"QThread");
}

RING_FUNC(ring_QThreadPool_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	QThreadPool *pObject = new QThreadPool();
	RING_API_RETCPOINTER(pObject,"QThreadPool");
}

RING_FUNC(ring_QProcess_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	GProcess *pObject = new GProcess((QObject *) RING_API_GETCPOINTER(1,"QObject"), (VM *) pPointer);
	RING_API_RETCPOINTER(pObject,"QProcess");
}

RING_FUNC(ring_QUuid_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	QUuid *pObject = new QUuid();
	RING_API_RETCPOINTER(pObject,"QUuid");
}

RING_FUNC(ring_QMutexLocker_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	QMutexLocker<QMutex> *pObject = new QMutexLocker<QMutex>((QMutex *) RING_API_GETCPOINTER(1,"QMutex"));
	RING_API_RETCPOINTER(pObject,"QMutexLocker");
}

RING_FUNC(ring_QVersionNumber_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	QVersionNumber *pObject = new QVersionNumber();
	RING_API_RETCPOINTER(pObject,"QVersionNumber");
}

RING_FUNC(ring_QPixmap_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	QPixmap *pObject = new QPixmap(RING_API_GETSTRING(1));
	RING_API_RETCPOINTER(pObject,"QPixmap");
}

RING_FUNC(ring_QPixmap2_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	QPixmap *pObject = new QPixmap((int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2));
	RING_API_RETCPOINTER(pObject,"QPixmap2");
}

RING_FUNC(ring_QIcon_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	QIcon *pObject = new QIcon(* (QPixmap *) RING_API_GETCPOINTER(1,"QPixmap"));
	RING_API_RETMANAGEDCPOINTER(pObject,"QIcon",ring_QIcon_freefunc);
}

RING_FUNC(ring_QPicture_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	QPicture *pObject = new QPicture();
	RING_API_RETCPOINTER(pObject,"QPicture");
}

RING_FUNC(ring_QFont_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	QFont *pObject = new QFont(RING_API_GETSTRING(1), (int) RING_API_GETNUMBER(2), (int) RING_API_GETNUMBER(3), (bool) RING_API_GETNUMBER(4));
	RING_API_RETMANAGEDCPOINTER(pObject,"QFont",ring_QFont_freefunc);
}

RING_FUNC(ring_QImage_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	QImage *pObject = new QImage();
	RING_API_RETCPOINTER(pObject,"QImage");
}

RING_FUNC(ring_QWindow_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	GWindow *pObject = new GWindow((QScreen *) RING_API_GETCPOINTER(1,"QScreen"), (VM *) pPointer);
	RING_API_RETCPOINTER(pObject,"QWindow");
}

RING_FUNC(ring_QGuiApplication_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	GGuiApplication *pObject = new GGuiApplication((int) RING_API_GETNUMBER(1),(char **) RING_API_GETCPOINTER2POINTER(2,"char"), (VM *) pPointer);
	RING_API_RETCPOINTER(pObject,"QGuiApplication");
}

RING_FUNC(ring_QFontDatabase_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	QFontDatabase *pObject = new QFontDatabase();
	RING_API_RETCPOINTER(pObject,"QFontDatabase");
}

RING_FUNC(ring_QAllEvents_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	GAllEvents *pObject = new GAllEvents((QWidget *) RING_API_GETCPOINTER(1,"QWidget"), (VM *) pPointer);
	RING_API_RETCPOINTER(pObject,"QAllEvents");
}

RING_FUNC(ring_QNetworkProxy_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	QNetworkProxy *pObject = new QNetworkProxy();
	RING_API_RETCPOINTER(pObject,"QNetworkProxy");
}

RING_FUNC(ring_QTcpSocket_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	GTcpSocket *pObject = new GTcpSocket((QObject *) RING_API_GETCPOINTER(1,"QObject"), (VM *) pPointer);
	RING_API_RETCPOINTER(pObject,"QTcpSocket");
}

RING_FUNC(ring_QTcpServer_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	GTcpServer *pObject = new GTcpServer((QWidget *) RING_API_GETCPOINTER(1,"QWidget"), (VM *) pPointer);
	RING_API_RETCPOINTER(pObject,"QTcpServer");
}

RING_FUNC(ring_QHostAddress_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	QHostAddress *pObject = new QHostAddress();
	RING_API_RETCPOINTER(pObject,"QHostAddress");
}

RING_FUNC(ring_QHostInfo_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	QHostInfo *pObject = new QHostInfo();
	RING_API_RETCPOINTER(pObject,"QHostInfo");
}

RING_FUNC(ring_QNetworkRequest_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	QNetworkRequest *pObject = new QNetworkRequest(* (QUrl *) RING_API_GETCPOINTER(1,"QUrl"));
	RING_API_RETCPOINTER(pObject,"QNetworkRequest");
}

RING_FUNC(ring_QNetworkAccessManager_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	GNetworkAccessManager *pObject = new GNetworkAccessManager((QObject *) RING_API_GETCPOINTER(1,"QObject"), (VM *) pPointer);
	RING_API_RETCPOINTER(pObject,"QNetworkAccessManager");
}

RING_FUNC(ring_QQmlError_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	QQmlError *pObject = new QQmlError();
	RING_API_RETCPOINTER(pObject,"QQmlError");
}

RING_FUNC(ring_QQmlEngine_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	QQmlEngine *pObject = new QQmlEngine((QObject *) RING_API_GETCPOINTER(1,"QObject"));
	RING_API_RETCPOINTER(pObject,"QQmlEngine");
}

RING_FUNC(ring_QObject_delete)
{
	QObject *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QObject *) RING_API_GETCPOINTER(1,"QObject");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QSize_delete)
{
	QSize *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QSize *) RING_API_GETCPOINTER(1,"QSize");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QDir_delete)
{
	QDir *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QUrl_delete)
{
	QUrl *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QUrl *) RING_API_GETCPOINTER(1,"QUrl");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QEvent_delete)
{
	QEvent *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QEvent *) RING_API_GETCPOINTER(1,"QEvent");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QTimer_delete)
{
	GTimer *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (GTimer *) RING_API_GETCPOINTER(1,"GTimer");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QByteArray_delete)
{
	QByteArray *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QFileInfo_delete)
{
	QFileInfo *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QFileInfo *) RING_API_GETCPOINTER(1,"QFileInfo");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QStringList_delete)
{
	QStringList *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QStringList *) RING_API_GETCPOINTER(1,"QStringList");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QTime_delete)
{
	QTime *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QTime *) RING_API_GETCPOINTER(1,"QTime");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QDate_delete)
{
	QDate *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QDate *) RING_API_GETCPOINTER(1,"QDate");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QVariant_delete)
{
	QVariant *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QVariant *) RING_API_GETCPOINTER(1,"QVariant");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QVariant2_delete)
{
	QVariant *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QVariant *) RING_API_GETCPOINTER(1,"QVariant");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QVariant3_delete)
{
	QVariant *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QVariant *) RING_API_GETCPOINTER(1,"QVariant");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QVariant4_delete)
{
	QVariant *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QVariant *) RING_API_GETCPOINTER(1,"QVariant");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QVariantInt_delete)
{
	QVariant *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QVariant *) RING_API_GETCPOINTER(1,"QVariant");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QVariantFloat_delete)
{
	QVariant *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QVariant *) RING_API_GETCPOINTER(1,"QVariant");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QVariantDouble_delete)
{
	QVariant *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QVariant *) RING_API_GETCPOINTER(1,"QVariant");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QJsonArray_delete)
{
	QJsonArray *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QJsonArray *) RING_API_GETCPOINTER(1,"QJsonArray");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QJsonDocument_delete)
{
	QJsonDocument *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QJsonDocument *) RING_API_GETCPOINTER(1,"QJsonDocument");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QJsonObject_delete)
{
	QJsonObject *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QJsonObject *) RING_API_GETCPOINTER(1,"QJsonObject");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QJsonParseError_delete)
{
	QJsonParseError *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QJsonParseError *) RING_API_GETCPOINTER(1,"QJsonParseError");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QJsonValue_delete)
{
	QJsonValue *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QJsonValue *) RING_API_GETCPOINTER(1,"QJsonValue");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QString2_delete)
{
	QString *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QString *) RING_API_GETCPOINTER(1,"QString");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QBuffer_delete)
{
	QBuffer *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QBuffer *) RING_API_GETCPOINTER(1,"QBuffer");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QDateTime_delete)
{
	QDateTime *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QDateTime *) RING_API_GETCPOINTER(1,"QDateTime");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QFile_delete)
{
	QFile *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QFile *) RING_API_GETCPOINTER(1,"QFile");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QFile2_delete)
{
	QFile *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QFile *) RING_API_GETCPOINTER(1,"QFile");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QMimeData_delete)
{
	QMimeData *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QMimeData *) RING_API_GETCPOINTER(1,"QMimeData");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QChar_delete)
{
	QChar *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QChildEvent_delete)
{
	QChildEvent *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QChildEvent *) RING_API_GETCPOINTER(1,"QChildEvent");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QLocale_delete)
{
	QLocale *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QThread_delete)
{
	GThread *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (GThread *) RING_API_GETCPOINTER(1,"GThread");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QThreadPool_delete)
{
	QThreadPool *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QThreadPool *) RING_API_GETCPOINTER(1,"QThreadPool");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QProcess_delete)
{
	GProcess *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (GProcess *) RING_API_GETCPOINTER(1,"GProcess");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QUuid_delete)
{
	QUuid *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QUuid *) RING_API_GETCPOINTER(1,"QUuid");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QMutexLocker_delete)
{
	QMutexLocker<QMutex> *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QMutexLocker<QMutex> *) RING_API_GETCPOINTER(1,"QMutexLocker<QMutex>");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QVersionNumber_delete)
{
	QVersionNumber *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QVersionNumber *) RING_API_GETCPOINTER(1,"QVersionNumber");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QPixmap_delete)
{
	QPixmap *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QPixmap *) RING_API_GETCPOINTER(1,"QPixmap");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QPixmap2_delete)
{
	QPixmap *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QPixmap *) RING_API_GETCPOINTER(1,"QPixmap");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QIcon_delete)
{
	QIcon *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QIcon *) RING_API_GETCPOINTER(1,"QIcon");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QPicture_delete)
{
	QPicture *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QPicture *) RING_API_GETCPOINTER(1,"QPicture");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QFont_delete)
{
	QFont *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QFont *) RING_API_GETCPOINTER(1,"QFont");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QImage_delete)
{
	QImage *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QImage *) RING_API_GETCPOINTER(1,"QImage");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QWindow_delete)
{
	GWindow *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (GWindow *) RING_API_GETCPOINTER(1,"GWindow");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QGuiApplication_delete)
{
	GGuiApplication *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (GGuiApplication *) RING_API_GETCPOINTER(1,"GGuiApplication");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QFontDatabase_delete)
{
	QFontDatabase *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QFontDatabase *) RING_API_GETCPOINTER(1,"QFontDatabase");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QAllEvents_delete)
{
	GAllEvents *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (GAllEvents *) RING_API_GETCPOINTER(1,"GAllEvents");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QNetworkProxy_delete)
{
	QNetworkProxy *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QNetworkProxy *) RING_API_GETCPOINTER(1,"QNetworkProxy");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QTcpSocket_delete)
{
	GTcpSocket *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (GTcpSocket *) RING_API_GETCPOINTER(1,"GTcpSocket");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QTcpServer_delete)
{
	GTcpServer *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (GTcpServer *) RING_API_GETCPOINTER(1,"GTcpServer");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QHostAddress_delete)
{
	QHostAddress *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QHostAddress *) RING_API_GETCPOINTER(1,"QHostAddress");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QHostInfo_delete)
{
	QHostInfo *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QHostInfo *) RING_API_GETCPOINTER(1,"QHostInfo");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QNetworkRequest_delete)
{
	QNetworkRequest *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QNetworkRequest *) RING_API_GETCPOINTER(1,"QNetworkRequest");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QNetworkAccessManager_delete)
{
	GNetworkAccessManager *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (GNetworkAccessManager *) RING_API_GETCPOINTER(1,"GNetworkAccessManager");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QQmlError_delete)
{
	QQmlError *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QQmlError *) RING_API_GETCPOINTER(1,"QQmlError");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QQmlEngine_delete)
{
	QQmlEngine *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QQmlEngine *) RING_API_GETCPOINTER(1,"QQmlEngine");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

void ring_QObject_freefunc(void *pState,void *pPointer)
{
	QObject *pObject ; 
	pObject = (QObject *) pPointer;
	delete pObject ;
}

void ring_QSize_freefunc(void *pState,void *pPointer)
{
	QSize *pObject ; 
	pObject = (QSize *) pPointer;
	delete pObject ;
}

void ring_QDir_freefunc(void *pState,void *pPointer)
{
	QDir *pObject ; 
	pObject = (QDir *) pPointer;
	delete pObject ;
}

void ring_QUrl_freefunc(void *pState,void *pPointer)
{
	QUrl *pObject ; 
	pObject = (QUrl *) pPointer;
	delete pObject ;
}

void ring_QEvent_freefunc(void *pState,void *pPointer)
{
	QEvent *pObject ; 
	pObject = (QEvent *) pPointer;
	delete pObject ;
}

void ring_QTimer_freefunc(void *pState,void *pPointer)
{
	GTimer *pObject ; 
	pObject = (GTimer *) pPointer;
	delete pObject ;
}

void ring_QByteArray_freefunc(void *pState,void *pPointer)
{
	QByteArray *pObject ; 
	pObject = (QByteArray *) pPointer;
	delete pObject ;
}

void ring_QFileInfo_freefunc(void *pState,void *pPointer)
{
	QFileInfo *pObject ; 
	pObject = (QFileInfo *) pPointer;
	delete pObject ;
}

void ring_QStringList_freefunc(void *pState,void *pPointer)
{
	QStringList *pObject ; 
	pObject = (QStringList *) pPointer;
	delete pObject ;
}

void ring_QTime_freefunc(void *pState,void *pPointer)
{
	QTime *pObject ; 
	pObject = (QTime *) pPointer;
	delete pObject ;
}

void ring_QDate_freefunc(void *pState,void *pPointer)
{
	QDate *pObject ; 
	pObject = (QDate *) pPointer;
	delete pObject ;
}

void ring_QVariant_freefunc(void *pState,void *pPointer)
{
	QVariant *pObject ; 
	pObject = (QVariant *) pPointer;
	delete pObject ;
}

void ring_QVariant2_freefunc(void *pState,void *pPointer)
{
	QVariant *pObject ; 
	pObject = (QVariant *) pPointer;
	delete pObject ;
}

void ring_QVariant3_freefunc(void *pState,void *pPointer)
{
	QVariant *pObject ; 
	pObject = (QVariant *) pPointer;
	delete pObject ;
}

void ring_QVariant4_freefunc(void *pState,void *pPointer)
{
	QVariant *pObject ; 
	pObject = (QVariant *) pPointer;
	delete pObject ;
}

void ring_QVariantInt_freefunc(void *pState,void *pPointer)
{
	QVariant *pObject ; 
	pObject = (QVariant *) pPointer;
	delete pObject ;
}

void ring_QVariantFloat_freefunc(void *pState,void *pPointer)
{
	QVariant *pObject ; 
	pObject = (QVariant *) pPointer;
	delete pObject ;
}

void ring_QVariantDouble_freefunc(void *pState,void *pPointer)
{
	QVariant *pObject ; 
	pObject = (QVariant *) pPointer;
	delete pObject ;
}

void ring_QJsonArray_freefunc(void *pState,void *pPointer)
{
	QJsonArray *pObject ; 
	pObject = (QJsonArray *) pPointer;
	delete pObject ;
}

void ring_QJsonDocument_freefunc(void *pState,void *pPointer)
{
	QJsonDocument *pObject ; 
	pObject = (QJsonDocument *) pPointer;
	delete pObject ;
}

void ring_QJsonObject_freefunc(void *pState,void *pPointer)
{
	QJsonObject *pObject ; 
	pObject = (QJsonObject *) pPointer;
	delete pObject ;
}

void ring_QJsonParseError_freefunc(void *pState,void *pPointer)
{
	QJsonParseError *pObject ; 
	pObject = (QJsonParseError *) pPointer;
	delete pObject ;
}

void ring_QJsonValue_freefunc(void *pState,void *pPointer)
{
	QJsonValue *pObject ; 
	pObject = (QJsonValue *) pPointer;
	delete pObject ;
}

void ring_QString2_freefunc(void *pState,void *pPointer)
{
	QString *pObject ; 
	pObject = (QString *) pPointer;
	delete pObject ;
}

void ring_QBuffer_freefunc(void *pState,void *pPointer)
{
	QBuffer *pObject ; 
	pObject = (QBuffer *) pPointer;
	delete pObject ;
}

void ring_QDateTime_freefunc(void *pState,void *pPointer)
{
	QDateTime *pObject ; 
	pObject = (QDateTime *) pPointer;
	delete pObject ;
}

void ring_QFile_freefunc(void *pState,void *pPointer)
{
	QFile *pObject ; 
	pObject = (QFile *) pPointer;
	delete pObject ;
}

void ring_QFile2_freefunc(void *pState,void *pPointer)
{
	QFile *pObject ; 
	pObject = (QFile *) pPointer;
	delete pObject ;
}

void ring_QMimeData_freefunc(void *pState,void *pPointer)
{
	QMimeData *pObject ; 
	pObject = (QMimeData *) pPointer;
	delete pObject ;
}

void ring_QChar_freefunc(void *pState,void *pPointer)
{
	QChar *pObject ; 
	pObject = (QChar *) pPointer;
	delete pObject ;
}

void ring_QChildEvent_freefunc(void *pState,void *pPointer)
{
	QChildEvent *pObject ; 
	pObject = (QChildEvent *) pPointer;
	delete pObject ;
}

void ring_QLocale_freefunc(void *pState,void *pPointer)
{
	QLocale *pObject ; 
	pObject = (QLocale *) pPointer;
	delete pObject ;
}

void ring_QThread_freefunc(void *pState,void *pPointer)
{
	GThread *pObject ; 
	pObject = (GThread *) pPointer;
	delete pObject ;
}

void ring_QThreadPool_freefunc(void *pState,void *pPointer)
{
	QThreadPool *pObject ; 
	pObject = (QThreadPool *) pPointer;
	delete pObject ;
}

void ring_QProcess_freefunc(void *pState,void *pPointer)
{
	GProcess *pObject ; 
	pObject = (GProcess *) pPointer;
	delete pObject ;
}

void ring_QUuid_freefunc(void *pState,void *pPointer)
{
	QUuid *pObject ; 
	pObject = (QUuid *) pPointer;
	delete pObject ;
}

void ring_QMutexLocker_freefunc(void *pState,void *pPointer)
{
	QMutexLocker<QMutex> *pObject ; 
	pObject = (QMutexLocker<QMutex> *) pPointer;
	delete pObject ;
}

void ring_QVersionNumber_freefunc(void *pState,void *pPointer)
{
	QVersionNumber *pObject ; 
	pObject = (QVersionNumber *) pPointer;
	delete pObject ;
}

void ring_QPixmap_freefunc(void *pState,void *pPointer)
{
	QPixmap *pObject ; 
	pObject = (QPixmap *) pPointer;
	delete pObject ;
}

void ring_QPixmap2_freefunc(void *pState,void *pPointer)
{
	QPixmap *pObject ; 
	pObject = (QPixmap *) pPointer;
	delete pObject ;
}

void ring_QIcon_freefunc(void *pState,void *pPointer)
{
	QIcon *pObject ; 
	pObject = (QIcon *) pPointer;
	delete pObject ;
}

void ring_QPicture_freefunc(void *pState,void *pPointer)
{
	QPicture *pObject ; 
	pObject = (QPicture *) pPointer;
	delete pObject ;
}

void ring_QFont_freefunc(void *pState,void *pPointer)
{
	QFont *pObject ; 
	pObject = (QFont *) pPointer;
	delete pObject ;
}

void ring_QImage_freefunc(void *pState,void *pPointer)
{
	QImage *pObject ; 
	pObject = (QImage *) pPointer;
	delete pObject ;
}

void ring_QWindow_freefunc(void *pState,void *pPointer)
{
	GWindow *pObject ; 
	pObject = (GWindow *) pPointer;
	delete pObject ;
}

void ring_QGuiApplication_freefunc(void *pState,void *pPointer)
{
	GGuiApplication *pObject ; 
	pObject = (GGuiApplication *) pPointer;
	delete pObject ;
}

void ring_QFontDatabase_freefunc(void *pState,void *pPointer)
{
	QFontDatabase *pObject ; 
	pObject = (QFontDatabase *) pPointer;
	delete pObject ;
}

void ring_QAllEvents_freefunc(void *pState,void *pPointer)
{
	GAllEvents *pObject ; 
	pObject = (GAllEvents *) pPointer;
	delete pObject ;
}

void ring_QNetworkProxy_freefunc(void *pState,void *pPointer)
{
	QNetworkProxy *pObject ; 
	pObject = (QNetworkProxy *) pPointer;
	delete pObject ;
}

void ring_QTcpSocket_freefunc(void *pState,void *pPointer)
{
	GTcpSocket *pObject ; 
	pObject = (GTcpSocket *) pPointer;
	delete pObject ;
}

void ring_QTcpServer_freefunc(void *pState,void *pPointer)
{
	GTcpServer *pObject ; 
	pObject = (GTcpServer *) pPointer;
	delete pObject ;
}

void ring_QHostAddress_freefunc(void *pState,void *pPointer)
{
	QHostAddress *pObject ; 
	pObject = (QHostAddress *) pPointer;
	delete pObject ;
}

void ring_QHostInfo_freefunc(void *pState,void *pPointer)
{
	QHostInfo *pObject ; 
	pObject = (QHostInfo *) pPointer;
	delete pObject ;
}

void ring_QNetworkRequest_freefunc(void *pState,void *pPointer)
{
	QNetworkRequest *pObject ; 
	pObject = (QNetworkRequest *) pPointer;
	delete pObject ;
}

void ring_QNetworkAccessManager_freefunc(void *pState,void *pPointer)
{
	GNetworkAccessManager *pObject ; 
	pObject = (GNetworkAccessManager *) pPointer;
	delete pObject ;
}

void ring_QQmlError_freefunc(void *pState,void *pPointer)
{
	QQmlError *pObject ; 
	pObject = (QQmlError *) pPointer;
	delete pObject ;
}

void ring_QQmlEngine_freefunc(void *pState,void *pPointer)
{
	QQmlEngine *pObject ; 
	pObject = (QQmlEngine *) pPointer;
	delete pObject ;
}

RING_API void ring_qt_start(RingState *pRingState)
{
	RING_API_REGISTER("qobject_blocksignals",ring_QObject_blockSignals);
	RING_API_REGISTER("qobject_children",ring_QObject_children);
	RING_API_REGISTER("qobject_dumpobjectinfo",ring_QObject_dumpObjectInfo);
	RING_API_REGISTER("qobject_dumpobjecttree",ring_QObject_dumpObjectTree);
	RING_API_REGISTER("qobject_inherits",ring_QObject_inherits);
	RING_API_REGISTER("qobject_installeventfilter",ring_QObject_installEventFilter);
	RING_API_REGISTER("qobject_iswidgettype",ring_QObject_isWidgetType);
	RING_API_REGISTER("qobject_killtimer",ring_QObject_killTimer);
	RING_API_REGISTER("qobject_movetothread",ring_QObject_moveToThread);
	RING_API_REGISTER("qobject_objectname",ring_QObject_objectName);
	RING_API_REGISTER("qobject_parent",ring_QObject_parent);
	RING_API_REGISTER("qobject_property",ring_QObject_property);
	RING_API_REGISTER("qobject_removeeventfilter",ring_QObject_removeEventFilter);
	RING_API_REGISTER("qobject_setobjectname",ring_QObject_setObjectName);
	RING_API_REGISTER("qobject_setparent",ring_QObject_setParent);
	RING_API_REGISTER("qobject_setproperty",ring_QObject_setProperty);
	RING_API_REGISTER("qobject_setproperty_2",ring_QObject_setProperty_2);
	RING_API_REGISTER("qobject_setproperty_3",ring_QObject_setProperty_3);
	RING_API_REGISTER("qobject_setproperty_4",ring_QObject_setProperty_4);
	RING_API_REGISTER("qobject_setproperty_int",ring_QObject_setProperty_int);
	RING_API_REGISTER("qobject_setproperty_float",ring_QObject_setProperty_float);
	RING_API_REGISTER("qobject_setproperty_double",ring_QObject_setProperty_double);
	RING_API_REGISTER("qobject_setproperty_5",ring_QObject_setProperty_5);
	RING_API_REGISTER("qobject_setproperty_string",ring_QObject_setProperty_string);
	RING_API_REGISTER("qobject_signalsblocked",ring_QObject_signalsBlocked);
	RING_API_REGISTER("qobject_starttimer",ring_QObject_startTimer);
	RING_API_REGISTER("qobject_thread",ring_QObject_thread);
	RING_API_REGISTER("qobject_deletelater",ring_QObject_deleteLater);
	RING_API_REGISTER("qdir_absolutefilepath",ring_QDir_absoluteFilePath);
	RING_API_REGISTER("qdir_absolutepath",ring_QDir_absolutePath);
	RING_API_REGISTER("qdir_canonicalpath",ring_QDir_canonicalPath);
	RING_API_REGISTER("qdir_cd",ring_QDir_cd);
	RING_API_REGISTER("qdir_cdup",ring_QDir_cdUp);
	RING_API_REGISTER("qdir_count",ring_QDir_count);
	RING_API_REGISTER("qdir_dirname",ring_QDir_dirName);
	RING_API_REGISTER("qdir_entryinfolist",ring_QDir_entryInfoList);
	RING_API_REGISTER("qdir_entryinfolist_2",ring_QDir_entryInfoList_2);
	RING_API_REGISTER("qdir_entrylist",ring_QDir_entryList);
	RING_API_REGISTER("qdir_entrylist_2",ring_QDir_entryList_2);
	RING_API_REGISTER("qdir_exists",ring_QDir_exists);
	RING_API_REGISTER("qdir_exists_2",ring_QDir_exists_2);
	RING_API_REGISTER("qdir_filepath",ring_QDir_filePath);
	RING_API_REGISTER("qdir_filter",ring_QDir_filter);
	RING_API_REGISTER("qdir_isabsolute",ring_QDir_isAbsolute);
	RING_API_REGISTER("qdir_isreadable",ring_QDir_isReadable);
	RING_API_REGISTER("qdir_isrelative",ring_QDir_isRelative);
	RING_API_REGISTER("qdir_isroot",ring_QDir_isRoot);
	RING_API_REGISTER("qdir_makeabsolute",ring_QDir_makeAbsolute);
	RING_API_REGISTER("qdir_mkdir",ring_QDir_mkdir);
	RING_API_REGISTER("qdir_mkpath",ring_QDir_mkpath);
	RING_API_REGISTER("qdir_namefilters",ring_QDir_nameFilters);
	RING_API_REGISTER("qdir_path",ring_QDir_path);
	RING_API_REGISTER("qdir_refresh",ring_QDir_refresh);
	RING_API_REGISTER("qdir_relativefilepath",ring_QDir_relativeFilePath);
	RING_API_REGISTER("qdir_remove",ring_QDir_remove);
	RING_API_REGISTER("qdir_removerecursively",ring_QDir_removeRecursively);
	RING_API_REGISTER("qdir_rename",ring_QDir_rename);
	RING_API_REGISTER("qdir_rmdir",ring_QDir_rmdir);
	RING_API_REGISTER("qdir_rmpath",ring_QDir_rmpath);
	RING_API_REGISTER("qdir_setfilter",ring_QDir_setFilter);
	RING_API_REGISTER("qdir_setnamefilters",ring_QDir_setNameFilters);
	RING_API_REGISTER("qdir_setpath",ring_QDir_setPath);
	RING_API_REGISTER("qdir_setsorting",ring_QDir_setSorting);
	RING_API_REGISTER("qdir_sorting",ring_QDir_sorting);
	RING_API_REGISTER("qdir_swap",ring_QDir_swap);
	RING_API_REGISTER("qdir_addsearchpath",ring_QDir_addSearchPath);
	RING_API_REGISTER("qdir_cleanpath",ring_QDir_cleanPath);
	RING_API_REGISTER("qdir_current",ring_QDir_current);
	RING_API_REGISTER("qdir_currentpath",ring_QDir_currentPath);
	RING_API_REGISTER("qdir_drives",ring_QDir_drives);
	RING_API_REGISTER("qdir_fromnativeseparators",ring_QDir_fromNativeSeparators);
	RING_API_REGISTER("qdir_home",ring_QDir_home);
	RING_API_REGISTER("qdir_homepath",ring_QDir_homePath);
	RING_API_REGISTER("qdir_isabsolutepath",ring_QDir_isAbsolutePath);
	RING_API_REGISTER("qdir_isrelativepath",ring_QDir_isRelativePath);
	RING_API_REGISTER("qdir_match",ring_QDir_match);
	RING_API_REGISTER("qdir_match_2",ring_QDir_match_2);
	RING_API_REGISTER("qdir_root",ring_QDir_root);
	RING_API_REGISTER("qdir_rootpath",ring_QDir_rootPath);
	RING_API_REGISTER("qdir_searchpaths",ring_QDir_searchPaths);
	RING_API_REGISTER("qdir_separator",ring_QDir_separator);
	RING_API_REGISTER("qdir_setcurrent",ring_QDir_setCurrent);
	RING_API_REGISTER("qdir_setsearchpaths",ring_QDir_setSearchPaths);
	RING_API_REGISTER("qdir_temp",ring_QDir_temp);
	RING_API_REGISTER("qdir_temppath",ring_QDir_tempPath);
	RING_API_REGISTER("qdir_tonativeseparators",ring_QDir_toNativeSeparators);
	RING_API_REGISTER("qurl_authority",ring_QUrl_authority);
	RING_API_REGISTER("qurl_clear",ring_QUrl_clear);
	RING_API_REGISTER("qurl_errorstring",ring_QUrl_errorString);
	RING_API_REGISTER("qurl_filename",ring_QUrl_fileName);
	RING_API_REGISTER("qurl_fragment",ring_QUrl_fragment);
	RING_API_REGISTER("qurl_hasfragment",ring_QUrl_hasFragment);
	RING_API_REGISTER("qurl_hasquery",ring_QUrl_hasQuery);
	RING_API_REGISTER("qurl_host",ring_QUrl_host);
	RING_API_REGISTER("qurl_isempty",ring_QUrl_isEmpty);
	RING_API_REGISTER("qurl_islocalfile",ring_QUrl_isLocalFile);
	RING_API_REGISTER("qurl_isparentof",ring_QUrl_isParentOf);
	RING_API_REGISTER("qurl_isrelative",ring_QUrl_isRelative);
	RING_API_REGISTER("qurl_isvalid",ring_QUrl_isValid);
	RING_API_REGISTER("qurl_password",ring_QUrl_password);
	RING_API_REGISTER("qurl_path",ring_QUrl_path);
	RING_API_REGISTER("qurl_port",ring_QUrl_port);
	RING_API_REGISTER("qurl_query",ring_QUrl_query);
	RING_API_REGISTER("qurl_resolved",ring_QUrl_resolved);
	RING_API_REGISTER("qurl_scheme",ring_QUrl_scheme);
	RING_API_REGISTER("qurl_setauthority",ring_QUrl_setAuthority);
	RING_API_REGISTER("qurl_setfragment",ring_QUrl_setFragment);
	RING_API_REGISTER("qurl_sethost",ring_QUrl_setHost);
	RING_API_REGISTER("qurl_setpassword",ring_QUrl_setPassword);
	RING_API_REGISTER("qurl_setpath",ring_QUrl_setPath);
	RING_API_REGISTER("qurl_setport",ring_QUrl_setPort);
	RING_API_REGISTER("qurl_setquery",ring_QUrl_setQuery);
	RING_API_REGISTER("qurl_setscheme",ring_QUrl_setScheme);
	RING_API_REGISTER("qurl_seturl",ring_QUrl_setUrl);
	RING_API_REGISTER("qurl_setuserinfo",ring_QUrl_setUserInfo);
	RING_API_REGISTER("qurl_setusername",ring_QUrl_setUserName);
	RING_API_REGISTER("qurl_swap",ring_QUrl_swap);
	RING_API_REGISTER("qurl_tolocalfile",ring_QUrl_toLocalFile);
	RING_API_REGISTER("qurl_userinfo",ring_QUrl_userInfo);
	RING_API_REGISTER("qurl_username",ring_QUrl_userName);
	RING_API_REGISTER("qurl_fromlocalfile",ring_QUrl_fromLocalFile);
	RING_API_REGISTER("qevent_accept",ring_QEvent_accept);
	RING_API_REGISTER("qevent_ignore",ring_QEvent_ignore);
	RING_API_REGISTER("qevent_isaccepted",ring_QEvent_isAccepted);
	RING_API_REGISTER("qevent_setaccepted",ring_QEvent_setAccepted);
	RING_API_REGISTER("qevent_spontaneous",ring_QEvent_spontaneous);
	RING_API_REGISTER("qevent_type",ring_QEvent_type);
	RING_API_REGISTER("qtimer_interval",ring_QTimer_interval);
	RING_API_REGISTER("qtimer_isactive",ring_QTimer_isActive);
	RING_API_REGISTER("qtimer_issingleshot",ring_QTimer_isSingleShot);
	RING_API_REGISTER("qtimer_setinterval",ring_QTimer_setInterval);
	RING_API_REGISTER("qtimer_setsingleshot",ring_QTimer_setSingleShot);
	RING_API_REGISTER("qtimer_timerid",ring_QTimer_timerId);
	RING_API_REGISTER("qtimer_start",ring_QTimer_start);
	RING_API_REGISTER("qtimer_stop",ring_QTimer_stop);
	RING_API_REGISTER("qtimer_settimeoutevent",ring_QTimer_settimeoutEvent);
	RING_API_REGISTER("qtimer_gettimeoutevent",ring_QTimer_gettimeoutEvent);
	RING_API_REGISTER("qbytearray_append",ring_QByteArray_append);
	RING_API_REGISTER("qbytearray_append_2",ring_QByteArray_append_2);
	RING_API_REGISTER("qbytearray_at",ring_QByteArray_at);
	RING_API_REGISTER("qbytearray_capacity",ring_QByteArray_capacity);
	RING_API_REGISTER("qbytearray_chop",ring_QByteArray_chop);
	RING_API_REGISTER("qbytearray_clear",ring_QByteArray_clear);
	RING_API_REGISTER("qbytearray_constdata",ring_QByteArray_constData);
	RING_API_REGISTER("qbytearray_contains",ring_QByteArray_contains);
	RING_API_REGISTER("qbytearray_count",ring_QByteArray_count);
	RING_API_REGISTER("qbytearray_data",ring_QByteArray_data);
	RING_API_REGISTER("qbytearray_endswith",ring_QByteArray_endsWith);
	RING_API_REGISTER("qbytearray_fill",ring_QByteArray_fill);
	RING_API_REGISTER("qbytearray_indexof",ring_QByteArray_indexOf);
	RING_API_REGISTER("qbytearray_insert",ring_QByteArray_insert);
	RING_API_REGISTER("qbytearray_isempty",ring_QByteArray_isEmpty);
	RING_API_REGISTER("qbytearray_isnull",ring_QByteArray_isNull);
	RING_API_REGISTER("qbytearray_lastindexof",ring_QByteArray_lastIndexOf);
	RING_API_REGISTER("qbytearray_left",ring_QByteArray_left);
	RING_API_REGISTER("qbytearray_leftjustified",ring_QByteArray_leftJustified);
	RING_API_REGISTER("qbytearray_length",ring_QByteArray_length);
	RING_API_REGISTER("qbytearray_mid",ring_QByteArray_mid);
	RING_API_REGISTER("qbytearray_prepend",ring_QByteArray_prepend);
	RING_API_REGISTER("qbytearray_push_back",ring_QByteArray_push_back);
	RING_API_REGISTER("qbytearray_push_front",ring_QByteArray_push_front);
	RING_API_REGISTER("qbytearray_remove",ring_QByteArray_remove);
	RING_API_REGISTER("qbytearray_repeated",ring_QByteArray_repeated);
	RING_API_REGISTER("qbytearray_replace",ring_QByteArray_replace);
	RING_API_REGISTER("qbytearray_replace_2",ring_QByteArray_replace_2);
	RING_API_REGISTER("qbytearray_replace_3",ring_QByteArray_replace_3);
	RING_API_REGISTER("qbytearray_replace_4",ring_QByteArray_replace_4);
	RING_API_REGISTER("qbytearray_replace_5",ring_QByteArray_replace_5);
	RING_API_REGISTER("qbytearray_replace_6",ring_QByteArray_replace_6);
	RING_API_REGISTER("qbytearray_replace_7",ring_QByteArray_replace_7);
	RING_API_REGISTER("qbytearray_replace_8",ring_QByteArray_replace_8);
	RING_API_REGISTER("qbytearray_replace_9",ring_QByteArray_replace_9);
	RING_API_REGISTER("qbytearray_replace_10",ring_QByteArray_replace_10);
	RING_API_REGISTER("qbytearray_replace_11",ring_QByteArray_replace_11);
	RING_API_REGISTER("qbytearray_reserve",ring_QByteArray_reserve);
	RING_API_REGISTER("qbytearray_resize",ring_QByteArray_resize);
	RING_API_REGISTER("qbytearray_right",ring_QByteArray_right);
	RING_API_REGISTER("qbytearray_rightjustified",ring_QByteArray_rightJustified);
	RING_API_REGISTER("qbytearray_setnum",ring_QByteArray_setNum);
	RING_API_REGISTER("qbytearray_setrawdata",ring_QByteArray_setRawData);
	RING_API_REGISTER("qbytearray_simplified",ring_QByteArray_simplified);
	RING_API_REGISTER("qbytearray_size",ring_QByteArray_size);
	RING_API_REGISTER("qbytearray_squeeze",ring_QByteArray_squeeze);
	RING_API_REGISTER("qbytearray_startswith",ring_QByteArray_startsWith);
	RING_API_REGISTER("qbytearray_swap",ring_QByteArray_swap);
	RING_API_REGISTER("qbytearray_tobase64",ring_QByteArray_toBase64);
	RING_API_REGISTER("qbytearray_todouble",ring_QByteArray_toDouble);
	RING_API_REGISTER("qbytearray_tofloat",ring_QByteArray_toFloat);
	RING_API_REGISTER("qbytearray_tohex",ring_QByteArray_toHex);
	RING_API_REGISTER("qbytearray_toint",ring_QByteArray_toInt);
	RING_API_REGISTER("qbytearray_tolong",ring_QByteArray_toLong);
	RING_API_REGISTER("qbytearray_tolonglong",ring_QByteArray_toLongLong);
	RING_API_REGISTER("qbytearray_tolower",ring_QByteArray_toLower);
	RING_API_REGISTER("qbytearray_topercentencoding",ring_QByteArray_toPercentEncoding);
	RING_API_REGISTER("qbytearray_toshort",ring_QByteArray_toShort);
	RING_API_REGISTER("qbytearray_touint",ring_QByteArray_toUInt);
	RING_API_REGISTER("qbytearray_toulong",ring_QByteArray_toULong);
	RING_API_REGISTER("qbytearray_toulonglong",ring_QByteArray_toULongLong);
	RING_API_REGISTER("qbytearray_toushort",ring_QByteArray_toUShort);
	RING_API_REGISTER("qbytearray_toupper",ring_QByteArray_toUpper);
	RING_API_REGISTER("qbytearray_trimmed",ring_QByteArray_trimmed);
	RING_API_REGISTER("qbytearray_truncate",ring_QByteArray_truncate);
	RING_API_REGISTER("qbytearray_frombase64",ring_QByteArray_fromBase64);
	RING_API_REGISTER("qbytearray_fromhex",ring_QByteArray_fromHex);
	RING_API_REGISTER("qbytearray_frompercentencoding",ring_QByteArray_fromPercentEncoding);
	RING_API_REGISTER("qbytearray_fromrawdata",ring_QByteArray_fromRawData);
	RING_API_REGISTER("qbytearray_number",ring_QByteArray_number);
	RING_API_REGISTER("qiodevice_errorstring",ring_QIODevice_errorString);
	RING_API_REGISTER("qiodevice_getchar",ring_QIODevice_getChar);
	RING_API_REGISTER("qiodevice_isopen",ring_QIODevice_isOpen);
	RING_API_REGISTER("qiodevice_isreadable",ring_QIODevice_isReadable);
	RING_API_REGISTER("qiodevice_istextmodeenabled",ring_QIODevice_isTextModeEnabled);
	RING_API_REGISTER("qiodevice_iswritable",ring_QIODevice_isWritable);
	RING_API_REGISTER("qiodevice_openmode",ring_QIODevice_openMode);
	RING_API_REGISTER("qiodevice_peek",ring_QIODevice_peek);
	RING_API_REGISTER("qiodevice_putchar",ring_QIODevice_putChar);
	RING_API_REGISTER("qiodevice_read",ring_QIODevice_read);
	RING_API_REGISTER("qiodevice_readall",ring_QIODevice_readAll);
	RING_API_REGISTER("qiodevice_readline",ring_QIODevice_readLine);
	RING_API_REGISTER("qiodevice_settextmodeenabled",ring_QIODevice_setTextModeEnabled);
	RING_API_REGISTER("qiodevice_ungetchar",ring_QIODevice_ungetChar);
	RING_API_REGISTER("qiodevice_write",ring_QIODevice_write);
	RING_API_REGISTER("qiodevice_atend",ring_QIODevice_atEnd);
	RING_API_REGISTER("qiodevice_canreadline",ring_QIODevice_canReadLine);
	RING_API_REGISTER("qiodevice_close",ring_QIODevice_close);
	RING_API_REGISTER("qiodevice_open",ring_QIODevice_open);
	RING_API_REGISTER("qiodevice_pos",ring_QIODevice_pos);
	RING_API_REGISTER("qiodevice_seek",ring_QIODevice_seek);
	RING_API_REGISTER("qiodevice_size",ring_QIODevice_size);
	RING_API_REGISTER("qiodevice_setabouttocloseevent",ring_QIODevice_setaboutToCloseEvent);
	RING_API_REGISTER("qiodevice_setbyteswrittenevent",ring_QIODevice_setbytesWrittenEvent);
	RING_API_REGISTER("qiodevice_setreadchannelfinishedevent",ring_QIODevice_setreadChannelFinishedEvent);
	RING_API_REGISTER("qiodevice_setreadyreadevent",ring_QIODevice_setreadyReadEvent);
	RING_API_REGISTER("qiodevice_getabouttocloseevent",ring_QIODevice_getaboutToCloseEvent);
	RING_API_REGISTER("qiodevice_getbyteswrittenevent",ring_QIODevice_getbytesWrittenEvent);
	RING_API_REGISTER("qiodevice_getreadchannelfinishedevent",ring_QIODevice_getreadChannelFinishedEvent);
	RING_API_REGISTER("qiodevice_getreadyreadevent",ring_QIODevice_getreadyReadEvent);
	RING_API_REGISTER("qfileinfo_absolutedir",ring_QFileInfo_absoluteDir);
	RING_API_REGISTER("qfileinfo_absolutefilepath",ring_QFileInfo_absoluteFilePath);
	RING_API_REGISTER("qfileinfo_absolutepath",ring_QFileInfo_absolutePath);
	RING_API_REGISTER("qfileinfo_basename",ring_QFileInfo_baseName);
	RING_API_REGISTER("qfileinfo_bundlename",ring_QFileInfo_bundleName);
	RING_API_REGISTER("qfileinfo_caching",ring_QFileInfo_caching);
	RING_API_REGISTER("qfileinfo_canonicalfilepath",ring_QFileInfo_canonicalFilePath);
	RING_API_REGISTER("qfileinfo_canonicalpath",ring_QFileInfo_canonicalPath);
	RING_API_REGISTER("qfileinfo_completebasename",ring_QFileInfo_completeBaseName);
	RING_API_REGISTER("qfileinfo_completesuffix",ring_QFileInfo_completeSuffix);
	RING_API_REGISTER("qfileinfo_dir",ring_QFileInfo_dir);
	RING_API_REGISTER("qfileinfo_exists",ring_QFileInfo_exists);
	RING_API_REGISTER("qfileinfo_filename",ring_QFileInfo_fileName);
	RING_API_REGISTER("qfileinfo_filepath",ring_QFileInfo_filePath);
	RING_API_REGISTER("qfileinfo_group",ring_QFileInfo_group);
	RING_API_REGISTER("qfileinfo_groupid",ring_QFileInfo_groupId);
	RING_API_REGISTER("qfileinfo_isabsolute",ring_QFileInfo_isAbsolute);
	RING_API_REGISTER("qfileinfo_isbundle",ring_QFileInfo_isBundle);
	RING_API_REGISTER("qfileinfo_isdir",ring_QFileInfo_isDir);
	RING_API_REGISTER("qfileinfo_isexecutable",ring_QFileInfo_isExecutable);
	RING_API_REGISTER("qfileinfo_isfile",ring_QFileInfo_isFile);
	RING_API_REGISTER("qfileinfo_ishidden",ring_QFileInfo_isHidden);
	RING_API_REGISTER("qfileinfo_isnativepath",ring_QFileInfo_isNativePath);
	RING_API_REGISTER("qfileinfo_isreadable",ring_QFileInfo_isReadable);
	RING_API_REGISTER("qfileinfo_isrelative",ring_QFileInfo_isRelative);
	RING_API_REGISTER("qfileinfo_isroot",ring_QFileInfo_isRoot);
	RING_API_REGISTER("qfileinfo_issymlink",ring_QFileInfo_isSymLink);
	RING_API_REGISTER("qfileinfo_iswritable",ring_QFileInfo_isWritable);
	RING_API_REGISTER("qfileinfo_lastmodified",ring_QFileInfo_lastModified);
	RING_API_REGISTER("qfileinfo_lastread",ring_QFileInfo_lastRead);
	RING_API_REGISTER("qfileinfo_makeabsolute",ring_QFileInfo_makeAbsolute);
	RING_API_REGISTER("qfileinfo_owner",ring_QFileInfo_owner);
	RING_API_REGISTER("qfileinfo_ownerid",ring_QFileInfo_ownerId);
	RING_API_REGISTER("qfileinfo_path",ring_QFileInfo_path);
	RING_API_REGISTER("qfileinfo_permission",ring_QFileInfo_permission);
	RING_API_REGISTER("qfileinfo_permissions",ring_QFileInfo_permissions);
	RING_API_REGISTER("qfileinfo_refresh",ring_QFileInfo_refresh);
	RING_API_REGISTER("qfileinfo_setcaching",ring_QFileInfo_setCaching);
	RING_API_REGISTER("qfileinfo_setfile",ring_QFileInfo_setFile);
	RING_API_REGISTER("qfileinfo_size",ring_QFileInfo_size);
	RING_API_REGISTER("qfileinfo_suffix",ring_QFileInfo_suffix);
	RING_API_REGISTER("qfileinfo_swap",ring_QFileInfo_swap);
	RING_API_REGISTER("qfileinfo_symlinktarget",ring_QFileInfo_symLinkTarget);
	RING_API_REGISTER("qstringlist_join",ring_QStringList_join);
	RING_API_REGISTER("qstringlist_sort",ring_QStringList_sort);
	RING_API_REGISTER("qstringlist_removeduplicates",ring_QStringList_removeDuplicates);
	RING_API_REGISTER("qstringlist_filter",ring_QStringList_filter);
	RING_API_REGISTER("qstringlist_replaceinstrings",ring_QStringList_replaceInStrings);
	RING_API_REGISTER("qstringlist_append",ring_QStringList_append);
	RING_API_REGISTER("qstringlist_at",ring_QStringList_at);
	RING_API_REGISTER("qstringlist_back",ring_QStringList_back);
	RING_API_REGISTER("qstringlist_clear",ring_QStringList_clear);
	RING_API_REGISTER("qstringlist_contains",ring_QStringList_contains);
	RING_API_REGISTER("qstringlist_count",ring_QStringList_count);
	RING_API_REGISTER("qstringlist_empty",ring_QStringList_empty);
	RING_API_REGISTER("qstringlist_endswith",ring_QStringList_endsWith);
	RING_API_REGISTER("qstringlist_first",ring_QStringList_first);
	RING_API_REGISTER("qstringlist_front",ring_QStringList_front);
	RING_API_REGISTER("qstringlist_indexof",ring_QStringList_indexOf);
	RING_API_REGISTER("qstringlist_insert",ring_QStringList_insert);
	RING_API_REGISTER("qstringlist_isempty",ring_QStringList_isEmpty);
	RING_API_REGISTER("qstringlist_last",ring_QStringList_last);
	RING_API_REGISTER("qstringlist_lastindexof",ring_QStringList_lastIndexOf);
	RING_API_REGISTER("qstringlist_length",ring_QStringList_length);
	RING_API_REGISTER("qstringlist_move",ring_QStringList_move);
	RING_API_REGISTER("qstringlist_pop_back",ring_QStringList_pop_back);
	RING_API_REGISTER("qstringlist_pop_front",ring_QStringList_pop_front);
	RING_API_REGISTER("qstringlist_prepend",ring_QStringList_prepend);
	RING_API_REGISTER("qstringlist_push_back",ring_QStringList_push_back);
	RING_API_REGISTER("qstringlist_push_front",ring_QStringList_push_front);
	RING_API_REGISTER("qstringlist_removeall",ring_QStringList_removeAll);
	RING_API_REGISTER("qstringlist_removeat",ring_QStringList_removeAt);
	RING_API_REGISTER("qstringlist_removefirst",ring_QStringList_removeFirst);
	RING_API_REGISTER("qstringlist_removelast",ring_QStringList_removeLast);
	RING_API_REGISTER("qstringlist_removeone",ring_QStringList_removeOne);
	RING_API_REGISTER("qstringlist_replace",ring_QStringList_replace);
	RING_API_REGISTER("qstringlist_reserve",ring_QStringList_reserve);
	RING_API_REGISTER("qstringlist_size",ring_QStringList_size);
	RING_API_REGISTER("qstringlist_startswith",ring_QStringList_startsWith);
	RING_API_REGISTER("qstringlist_takeat",ring_QStringList_takeAt);
	RING_API_REGISTER("qstringlist_takefirst",ring_QStringList_takeFirst);
	RING_API_REGISTER("qstringlist_takelast",ring_QStringList_takeLast);
	RING_API_REGISTER("qstringlist_value",ring_QStringList_value);
	RING_API_REGISTER("qtime_addmsecs",ring_QTime_addMSecs);
	RING_API_REGISTER("qtime_addsecs",ring_QTime_addSecs);
	RING_API_REGISTER("qtime_hour",ring_QTime_hour);
	RING_API_REGISTER("qtime_isnull",ring_QTime_isNull);
	RING_API_REGISTER("qtime_isvalid",ring_QTime_isValid);
	RING_API_REGISTER("qtime_minute",ring_QTime_minute);
	RING_API_REGISTER("qtime_msec",ring_QTime_msec);
	RING_API_REGISTER("qtime_msecssincestartofday",ring_QTime_msecsSinceStartOfDay);
	RING_API_REGISTER("qtime_msecsto",ring_QTime_msecsTo);
	RING_API_REGISTER("qtime_second",ring_QTime_second);
	RING_API_REGISTER("qtime_secsto",ring_QTime_secsTo);
	RING_API_REGISTER("qtime_sethms",ring_QTime_setHMS);
	RING_API_REGISTER("qtime_tostring",ring_QTime_toString);
	RING_API_REGISTER("qtime_currenttime",ring_QTime_currentTime);
	RING_API_REGISTER("qtime_frommsecssincestartofday",ring_QTime_fromMSecsSinceStartOfDay);
	RING_API_REGISTER("qtime_fromstring",ring_QTime_fromString);
	RING_API_REGISTER("qdate_adddays",ring_QDate_addDays);
	RING_API_REGISTER("qdate_addmonths",ring_QDate_addMonths);
	RING_API_REGISTER("qdate_addyears",ring_QDate_addYears);
	RING_API_REGISTER("qdate_day",ring_QDate_day);
	RING_API_REGISTER("qdate_dayofweek",ring_QDate_dayOfWeek);
	RING_API_REGISTER("qdate_dayofyear",ring_QDate_dayOfYear);
	RING_API_REGISTER("qdate_daysinmonth",ring_QDate_daysInMonth);
	RING_API_REGISTER("qdate_daysinyear",ring_QDate_daysInYear);
	RING_API_REGISTER("qdate_daysto",ring_QDate_daysTo);
	RING_API_REGISTER("qdate_getdate",ring_QDate_getDate);
	RING_API_REGISTER("qdate_isnull",ring_QDate_isNull);
	RING_API_REGISTER("qdate_isvalid",ring_QDate_isValid);
	RING_API_REGISTER("qdate_month",ring_QDate_month);
	RING_API_REGISTER("qdate_setdate",ring_QDate_setDate);
	RING_API_REGISTER("qdate_tojulianday",ring_QDate_toJulianDay);
	RING_API_REGISTER("qdate_tostring",ring_QDate_toString);
	RING_API_REGISTER("qdate_weeknumber",ring_QDate_weekNumber);
	RING_API_REGISTER("qdate_year",ring_QDate_year);
	RING_API_REGISTER("qdate_currentdate",ring_QDate_currentDate);
	RING_API_REGISTER("qdate_fromjulianday",ring_QDate_fromJulianDay);
	RING_API_REGISTER("qdate_fromstring",ring_QDate_fromString);
	RING_API_REGISTER("qdate_isleapyear",ring_QDate_isLeapYear);
	RING_API_REGISTER("qvariant_canconvert",ring_QVariant_canConvert);
	RING_API_REGISTER("qvariant_clear",ring_QVariant_clear);
	RING_API_REGISTER("qvariant_convert",ring_QVariant_convert);
	RING_API_REGISTER("qvariant_isnull",ring_QVariant_isNull);
	RING_API_REGISTER("qvariant_isvalid",ring_QVariant_isValid);
	RING_API_REGISTER("qvariant_swap",ring_QVariant_swap);
	RING_API_REGISTER("qvariant_tobitarray",ring_QVariant_toBitArray);
	RING_API_REGISTER("qvariant_tobool",ring_QVariant_toBool);
	RING_API_REGISTER("qvariant_tobytearray",ring_QVariant_toByteArray);
	RING_API_REGISTER("qvariant_tochar",ring_QVariant_toChar);
	RING_API_REGISTER("qvariant_todate",ring_QVariant_toDate);
	RING_API_REGISTER("qvariant_todatetime",ring_QVariant_toDateTime);
	RING_API_REGISTER("qvariant_todouble",ring_QVariant_toDouble);
	RING_API_REGISTER("qvariant_toeasingcurve",ring_QVariant_toEasingCurve);
	RING_API_REGISTER("qvariant_tofloat",ring_QVariant_toFloat);
	RING_API_REGISTER("qvariant_toint",ring_QVariant_toInt);
	RING_API_REGISTER("qvariant_tojsonarray",ring_QVariant_toJsonArray);
	RING_API_REGISTER("qvariant_tojsondocument",ring_QVariant_toJsonDocument);
	RING_API_REGISTER("qvariant_tojsonobject",ring_QVariant_toJsonObject);
	RING_API_REGISTER("qvariant_tojsonvalue",ring_QVariant_toJsonValue);
	RING_API_REGISTER("qvariant_toline",ring_QVariant_toLine);
	RING_API_REGISTER("qvariant_tolinef",ring_QVariant_toLineF);
	RING_API_REGISTER("qvariant_tolocale",ring_QVariant_toLocale);
	RING_API_REGISTER("qvariant_tolonglong",ring_QVariant_toLongLong);
	RING_API_REGISTER("qvariant_tomodelindex",ring_QVariant_toModelIndex);
	RING_API_REGISTER("qvariant_topoint",ring_QVariant_toPoint);
	RING_API_REGISTER("qvariant_topointf",ring_QVariant_toPointF);
	RING_API_REGISTER("qvariant_toreal",ring_QVariant_toReal);
	RING_API_REGISTER("qvariant_torect",ring_QVariant_toRect);
	RING_API_REGISTER("qvariant_torectf",ring_QVariant_toRectF);
	RING_API_REGISTER("qvariant_tosize",ring_QVariant_toSize);
	RING_API_REGISTER("qvariant_tosizef",ring_QVariant_toSizeF);
	RING_API_REGISTER("qvariant_tostringlist",ring_QVariant_toStringList);
	RING_API_REGISTER("qvariant_totime",ring_QVariant_toTime);
	RING_API_REGISTER("qvariant_touint",ring_QVariant_toUInt);
	RING_API_REGISTER("qvariant_toulonglong",ring_QVariant_toULongLong);
	RING_API_REGISTER("qvariant_tourl",ring_QVariant_toUrl);
	RING_API_REGISTER("qvariant_touuid",ring_QVariant_toUuid);
	RING_API_REGISTER("qvariant_type",ring_QVariant_type);
	RING_API_REGISTER("qvariant_typename",ring_QVariant_typeName);
	RING_API_REGISTER("qvariant_usertype",ring_QVariant_userType);
	RING_API_REGISTER("qvariant_tostring",ring_QVariant_toString);
	RING_API_REGISTER("qjsonarray_append",ring_QJsonArray_append);
	RING_API_REGISTER("qjsonarray_at",ring_QJsonArray_at);
	RING_API_REGISTER("qjsonarray_contains",ring_QJsonArray_contains);
	RING_API_REGISTER("qjsonarray_count",ring_QJsonArray_count);
	RING_API_REGISTER("qjsonarray_empty",ring_QJsonArray_empty);
	RING_API_REGISTER("qjsonarray_first",ring_QJsonArray_first);
	RING_API_REGISTER("qjsonarray_insert",ring_QJsonArray_insert);
	RING_API_REGISTER("qjsonarray_isempty",ring_QJsonArray_isEmpty);
	RING_API_REGISTER("qjsonarray_last",ring_QJsonArray_last);
	RING_API_REGISTER("qjsonarray_pop_back",ring_QJsonArray_pop_back);
	RING_API_REGISTER("qjsonarray_pop_front",ring_QJsonArray_pop_front);
	RING_API_REGISTER("qjsonarray_prepend",ring_QJsonArray_prepend);
	RING_API_REGISTER("qjsonarray_push_back",ring_QJsonArray_push_back);
	RING_API_REGISTER("qjsonarray_push_front",ring_QJsonArray_push_front);
	RING_API_REGISTER("qjsonarray_removeat",ring_QJsonArray_removeAt);
	RING_API_REGISTER("qjsonarray_removefirst",ring_QJsonArray_removeFirst);
	RING_API_REGISTER("qjsonarray_removelast",ring_QJsonArray_removeLast);
	RING_API_REGISTER("qjsonarray_replace",ring_QJsonArray_replace);
	RING_API_REGISTER("qjsonarray_size",ring_QJsonArray_size);
	RING_API_REGISTER("qjsonarray_takeat",ring_QJsonArray_takeAt);
	RING_API_REGISTER("qjsonarray_tovariantlist",ring_QJsonArray_toVariantList);
	RING_API_REGISTER("qjsonarray_fromstringlist",ring_QJsonArray_fromStringList);
	RING_API_REGISTER("qjsonarray_fromvariantlist",ring_QJsonArray_fromVariantList);
	RING_API_REGISTER("qjsondocument_array",ring_QJsonDocument_array);
	RING_API_REGISTER("qjsondocument_isarray",ring_QJsonDocument_isArray);
	RING_API_REGISTER("qjsondocument_isempty",ring_QJsonDocument_isEmpty);
	RING_API_REGISTER("qjsondocument_isnull",ring_QJsonDocument_isNull);
	RING_API_REGISTER("qjsondocument_isobject",ring_QJsonDocument_isObject);
	RING_API_REGISTER("qjsondocument_object",ring_QJsonDocument_object);
	RING_API_REGISTER("qjsondocument_setarray",ring_QJsonDocument_setArray);
	RING_API_REGISTER("qjsondocument_setobject",ring_QJsonDocument_setObject);
	RING_API_REGISTER("qjsondocument_tojson",ring_QJsonDocument_toJson);
	RING_API_REGISTER("qjsondocument_tovariant",ring_QJsonDocument_toVariant);
	RING_API_REGISTER("qjsondocument_fromjson",ring_QJsonDocument_fromJson);
	RING_API_REGISTER("qjsondocument_fromvariant",ring_QJsonDocument_fromVariant);
	RING_API_REGISTER("qjsonobject_contains",ring_QJsonObject_contains);
	RING_API_REGISTER("qjsonobject_count",ring_QJsonObject_count);
	RING_API_REGISTER("qjsonobject_empty",ring_QJsonObject_empty);
	RING_API_REGISTER("qjsonobject_isempty",ring_QJsonObject_isEmpty);
	RING_API_REGISTER("qjsonobject_keys",ring_QJsonObject_keys);
	RING_API_REGISTER("qjsonobject_length",ring_QJsonObject_length);
	RING_API_REGISTER("qjsonobject_remove",ring_QJsonObject_remove);
	RING_API_REGISTER("qjsonobject_size",ring_QJsonObject_size);
	RING_API_REGISTER("qjsonobject_take",ring_QJsonObject_take);
	RING_API_REGISTER("qjsonobject_tovariantmap",ring_QJsonObject_toVariantMap);
	RING_API_REGISTER("qjsonobject_value",ring_QJsonObject_value);
	RING_API_REGISTER("qjsonobject_fromvariantmap",ring_QJsonObject_fromVariantMap);
	RING_API_REGISTER("qjsonparseerror_errorstring",ring_QJsonParseError_errorString);
	RING_API_REGISTER("qjsonvalue_isarray",ring_QJsonValue_isArray);
	RING_API_REGISTER("qjsonvalue_isbool",ring_QJsonValue_isBool);
	RING_API_REGISTER("qjsonvalue_isdouble",ring_QJsonValue_isDouble);
	RING_API_REGISTER("qjsonvalue_isnull",ring_QJsonValue_isNull);
	RING_API_REGISTER("qjsonvalue_isobject",ring_QJsonValue_isObject);
	RING_API_REGISTER("qjsonvalue_isstring",ring_QJsonValue_isString);
	RING_API_REGISTER("qjsonvalue_isundefined",ring_QJsonValue_isUndefined);
	RING_API_REGISTER("qjsonvalue_toarray",ring_QJsonValue_toArray);
	RING_API_REGISTER("qjsonvalue_toarray_2",ring_QJsonValue_toArray_2);
	RING_API_REGISTER("qjsonvalue_tobool",ring_QJsonValue_toBool);
	RING_API_REGISTER("qjsonvalue_todouble",ring_QJsonValue_toDouble);
	RING_API_REGISTER("qjsonvalue_toint",ring_QJsonValue_toInt);
	RING_API_REGISTER("qjsonvalue_toobject",ring_QJsonValue_toObject);
	RING_API_REGISTER("qjsonvalue_toobject_2",ring_QJsonValue_toObject_2);
	RING_API_REGISTER("qjsonvalue_tostring",ring_QJsonValue_toString);
	RING_API_REGISTER("qjsonvalue_tovariant",ring_QJsonValue_toVariant);
	RING_API_REGISTER("qjsonvalue_type",ring_QJsonValue_type);
	RING_API_REGISTER("qjsonvalue_fromvariant",ring_QJsonValue_fromVariant);
	RING_API_REGISTER("qstring2_split",ring_QString2_split);
	RING_API_REGISTER("qstring2_split_2",ring_QString2_split_2);
	RING_API_REGISTER("qstring2_split_4",ring_QString2_split_4);
	RING_API_REGISTER("qstring2_append",ring_QString2_append);
	RING_API_REGISTER("qstring2_append_2",ring_QString2_append_2);
	RING_API_REGISTER("qstring2_toutf8",ring_QString2_toUtf8);
	RING_API_REGISTER("qstring2_tolatin1",ring_QString2_toLatin1);
	RING_API_REGISTER("qstring2_tolocal8bit",ring_QString2_toLocal8Bit);
	RING_API_REGISTER("qstring2_unicode",ring_QString2_unicode);
	RING_API_REGISTER("qstring2_number",ring_QString2_number);
	RING_API_REGISTER("qstring2_count",ring_QString2_count);
	RING_API_REGISTER("qstring2_left",ring_QString2_left);
	RING_API_REGISTER("qstring2_mid",ring_QString2_mid);
	RING_API_REGISTER("qstring2_right",ring_QString2_right);
	RING_API_REGISTER("qstring2_compare",ring_QString2_compare);
	RING_API_REGISTER("qstring2_contains",ring_QString2_contains);
	RING_API_REGISTER("qstring2_indexof",ring_QString2_indexOf);
	RING_API_REGISTER("qstring2_lastindexof",ring_QString2_lastIndexOf);
	RING_API_REGISTER("qstring2_insert",ring_QString2_insert);
	RING_API_REGISTER("qstring2_isrighttoleft",ring_QString2_isRightToLeft);
	RING_API_REGISTER("qstring2_repeated",ring_QString2_repeated);
	RING_API_REGISTER("qstring2_replace",ring_QString2_replace);
	RING_API_REGISTER("qstring2_replace_2",ring_QString2_replace_2);
	RING_API_REGISTER("qstring2_startswith",ring_QString2_startsWith);
	RING_API_REGISTER("qstring2_endswith",ring_QString2_endsWith);
	RING_API_REGISTER("qstring2_tohtmlescaped",ring_QString2_toHtmlEscaped);
	RING_API_REGISTER("qstring2_clear",ring_QString2_clear);
	RING_API_REGISTER("qstring2_isnull",ring_QString2_isNull);
	RING_API_REGISTER("qstring2_resize",ring_QString2_resize);
	RING_API_REGISTER("qstring2_fill",ring_QString2_fill);
	RING_API_REGISTER("qstring2_localeawarecompare",ring_QString2_localeAwareCompare);
	RING_API_REGISTER("qstring2_leftjustified",ring_QString2_leftJustified);
	RING_API_REGISTER("qstring2_rightjustified",ring_QString2_rightJustified);
	RING_API_REGISTER("qstring2_section_1",ring_QString2_section_1);
	RING_API_REGISTER("qstring2_section_2",ring_QString2_section_2);
	RING_API_REGISTER("qstring2_section_4",ring_QString2_section_4);
	RING_API_REGISTER("qstring2_simplified",ring_QString2_simplified);
	RING_API_REGISTER("qstring2_tocasefolded",ring_QString2_toCaseFolded);
	RING_API_REGISTER("qstring2_trimmed",ring_QString2_trimmed);
	RING_API_REGISTER("qstring2_truncate",ring_QString2_truncate);
	RING_API_REGISTER("qstring2_length",ring_QString2_length);
	RING_API_REGISTER("qstring2_size",ring_QString2_size);
	RING_API_REGISTER("qbuffer_buffer",ring_QBuffer_buffer);
	RING_API_REGISTER("qbuffer_data",ring_QBuffer_data);
	RING_API_REGISTER("qbuffer_setbuffer",ring_QBuffer_setBuffer);
	RING_API_REGISTER("qbuffer_setdata",ring_QBuffer_setData);
	RING_API_REGISTER("qbuffer_setdata_2",ring_QBuffer_setData_2);
	RING_API_REGISTER("qdatetime_adddays",ring_QDateTime_addDays);
	RING_API_REGISTER("qdatetime_addmsecs",ring_QDateTime_addMSecs);
	RING_API_REGISTER("qdatetime_addmonths",ring_QDateTime_addMonths);
	RING_API_REGISTER("qdatetime_addsecs",ring_QDateTime_addSecs);
	RING_API_REGISTER("qdatetime_addyears",ring_QDateTime_addYears);
	RING_API_REGISTER("qdatetime_date",ring_QDateTime_date);
	RING_API_REGISTER("qdatetime_daysto",ring_QDateTime_daysTo);
	RING_API_REGISTER("qdatetime_isnull",ring_QDateTime_isNull);
	RING_API_REGISTER("qdatetime_isvalid",ring_QDateTime_isValid);
	RING_API_REGISTER("qdatetime_msecsto",ring_QDateTime_msecsTo);
	RING_API_REGISTER("qdatetime_secsto",ring_QDateTime_secsTo);
	RING_API_REGISTER("qdatetime_setdate",ring_QDateTime_setDate);
	RING_API_REGISTER("qdatetime_setmsecssinceepoch",ring_QDateTime_setMSecsSinceEpoch);
	RING_API_REGISTER("qdatetime_settime",ring_QDateTime_setTime);
	RING_API_REGISTER("qdatetime_settimespec",ring_QDateTime_setTimeSpec);
	RING_API_REGISTER("qdatetime_time",ring_QDateTime_time);
	RING_API_REGISTER("qdatetime_timespec",ring_QDateTime_timeSpec);
	RING_API_REGISTER("qdatetime_tolocaltime",ring_QDateTime_toLocalTime);
	RING_API_REGISTER("qdatetime_tomsecssinceepoch",ring_QDateTime_toMSecsSinceEpoch);
	RING_API_REGISTER("qdatetime_tostring",ring_QDateTime_toString);
	RING_API_REGISTER("qdatetime_tostring_2",ring_QDateTime_toString_2);
	RING_API_REGISTER("qdatetime_totimespec",ring_QDateTime_toTimeSpec);
	RING_API_REGISTER("qdatetime_toutc",ring_QDateTime_toUTC);
	RING_API_REGISTER("qdatetime_currentdatetime",ring_QDateTime_currentDateTime);
	RING_API_REGISTER("qdatetime_currentdatetimeutc",ring_QDateTime_currentDateTimeUtc);
	RING_API_REGISTER("qdatetime_currentmsecssinceepoch",ring_QDateTime_currentMSecsSinceEpoch);
	RING_API_REGISTER("qdatetime_frommsecssinceepoch",ring_QDateTime_fromMSecsSinceEpoch);
	RING_API_REGISTER("qdatetime_fromstring",ring_QDateTime_fromString);
	RING_API_REGISTER("qdatetime_fromstring_2",ring_QDateTime_fromString_2);
	RING_API_REGISTER("qcoreapplication_installnativeeventfilter",ring_QCoreApplication_installNativeEventFilter);
	RING_API_REGISTER("qcoreapplication_removenativeeventfilter",ring_QCoreApplication_removeNativeEventFilter);
	RING_API_REGISTER("qcoreapplication_quit",ring_QCoreApplication_quit);
	RING_API_REGISTER("qcoreapplication_addlibrarypath",ring_QCoreApplication_addLibraryPath);
	RING_API_REGISTER("qcoreapplication_applicationdirpath",ring_QCoreApplication_applicationDirPath);
	RING_API_REGISTER("qcoreapplication_applicationfilepath",ring_QCoreApplication_applicationFilePath);
	RING_API_REGISTER("qcoreapplication_applicationname",ring_QCoreApplication_applicationName);
	RING_API_REGISTER("qcoreapplication_applicationpid",ring_QCoreApplication_applicationPid);
	RING_API_REGISTER("qcoreapplication_applicationversion",ring_QCoreApplication_applicationVersion);
	RING_API_REGISTER("qcoreapplication_arguments",ring_QCoreApplication_arguments);
	RING_API_REGISTER("qcoreapplication_closingdown",ring_QCoreApplication_closingDown);
	RING_API_REGISTER("qcoreapplication_eventdispatcher",ring_QCoreApplication_eventDispatcher);
	RING_API_REGISTER("qcoreapplication_exec",ring_QCoreApplication_exec);
	RING_API_REGISTER("qcoreapplication_exit",ring_QCoreApplication_exit);
	RING_API_REGISTER("qcoreapplication_installtranslator",ring_QCoreApplication_installTranslator);
	RING_API_REGISTER("qcoreapplication_instance",ring_QCoreApplication_instance);
	RING_API_REGISTER("qcoreapplication_isquitlockenabled",ring_QCoreApplication_isQuitLockEnabled);
	RING_API_REGISTER("qcoreapplication_librarypaths",ring_QCoreApplication_libraryPaths);
	RING_API_REGISTER("qcoreapplication_organizationdomain",ring_QCoreApplication_organizationDomain);
	RING_API_REGISTER("qcoreapplication_organizationname",ring_QCoreApplication_organizationName);
	RING_API_REGISTER("qcoreapplication_postevent",ring_QCoreApplication_postEvent);
	RING_API_REGISTER("qcoreapplication_processevents",ring_QCoreApplication_processEvents);
	RING_API_REGISTER("qcoreapplication_processevents_2",ring_QCoreApplication_processEvents_2);
	RING_API_REGISTER("qcoreapplication_removelibrarypath",ring_QCoreApplication_removeLibraryPath);
	RING_API_REGISTER("qcoreapplication_removepostedevents",ring_QCoreApplication_removePostedEvents);
	RING_API_REGISTER("qcoreapplication_removetranslator",ring_QCoreApplication_removeTranslator);
	RING_API_REGISTER("qcoreapplication_sendevent",ring_QCoreApplication_sendEvent);
	RING_API_REGISTER("qcoreapplication_sendpostedevents",ring_QCoreApplication_sendPostedEvents);
	RING_API_REGISTER("qcoreapplication_setapplicationname",ring_QCoreApplication_setApplicationName);
	RING_API_REGISTER("qcoreapplication_setapplicationversion",ring_QCoreApplication_setApplicationVersion);
	RING_API_REGISTER("qcoreapplication_setattribute",ring_QCoreApplication_setAttribute);
	RING_API_REGISTER("qcoreapplication_seteventdispatcher",ring_QCoreApplication_setEventDispatcher);
	RING_API_REGISTER("qcoreapplication_setlibrarypaths",ring_QCoreApplication_setLibraryPaths);
	RING_API_REGISTER("qcoreapplication_setorganizationdomain",ring_QCoreApplication_setOrganizationDomain);
	RING_API_REGISTER("qcoreapplication_setorganizationname",ring_QCoreApplication_setOrganizationName);
	RING_API_REGISTER("qcoreapplication_setquitlockenabled",ring_QCoreApplication_setQuitLockEnabled);
	RING_API_REGISTER("qcoreapplication_startingup",ring_QCoreApplication_startingUp);
	RING_API_REGISTER("qcoreapplication_testattribute",ring_QCoreApplication_testAttribute);
	RING_API_REGISTER("qcoreapplication_translate",ring_QCoreApplication_translate);
	RING_API_REGISTER("qfile_copy",ring_QFile_copy);
	RING_API_REGISTER("qfile_exists",ring_QFile_exists);
	RING_API_REGISTER("qfile_link",ring_QFile_link);
	RING_API_REGISTER("qfile_open",ring_QFile_open);
	RING_API_REGISTER("qfile_open_2",ring_QFile_open_2);
	RING_API_REGISTER("qfile_open_3",ring_QFile_open_3);
	RING_API_REGISTER("qfile_remove",ring_QFile_remove);
	RING_API_REGISTER("qfile_rename",ring_QFile_rename);
	RING_API_REGISTER("qfile_setfilename",ring_QFile_setFileName);
	RING_API_REGISTER("qfile_symlinktarget",ring_QFile_symLinkTarget);
	RING_API_REGISTER("qfile_copy_2",ring_QFile_copy_2);
	RING_API_REGISTER("qfile_decodename",ring_QFile_decodeName);
	RING_API_REGISTER("qfile_decodename_2",ring_QFile_decodeName_2);
	RING_API_REGISTER("qfile_encodename",ring_QFile_encodeName);
	RING_API_REGISTER("qfile_exists_2",ring_QFile_exists_2);
	RING_API_REGISTER("qfile_link_2",ring_QFile_link_2);
	RING_API_REGISTER("qfile_permissions",ring_QFile_permissions);
	RING_API_REGISTER("qfile_remove_2",ring_QFile_remove_2);
	RING_API_REGISTER("qfile_rename_2",ring_QFile_rename_2);
	RING_API_REGISTER("qfile_resize",ring_QFile_resize);
	RING_API_REGISTER("qfile_setpermissions",ring_QFile_setPermissions);
	RING_API_REGISTER("qfile_symlinktarget_2",ring_QFile_symLinkTarget_2);
	RING_API_REGISTER("qfiledevice_error",ring_QFileDevice_error);
	RING_API_REGISTER("qfiledevice_flush",ring_QFileDevice_flush);
	RING_API_REGISTER("qfiledevice_handle",ring_QFileDevice_handle);
	RING_API_REGISTER("qfiledevice_map",ring_QFileDevice_map);
	RING_API_REGISTER("qfiledevice_permissions",ring_QFileDevice_permissions);
	RING_API_REGISTER("qfiledevice_resize",ring_QFileDevice_resize);
	RING_API_REGISTER("qfiledevice_filename",ring_QFileDevice_fileName);
	RING_API_REGISTER("qfiledevice_setpermissions",ring_QFileDevice_setPermissions);
	RING_API_REGISTER("qfiledevice_unmap",ring_QFileDevice_unmap);
	RING_API_REGISTER("qfiledevice_unseterror",ring_QFileDevice_unsetError);
	RING_API_REGISTER("qstandardpaths_displayname",ring_QStandardPaths_displayName);
	RING_API_REGISTER("qstandardpaths_findexecutable",ring_QStandardPaths_findExecutable);
	RING_API_REGISTER("qstandardpaths_locate",ring_QStandardPaths_locate);
	RING_API_REGISTER("qstandardpaths_locateall",ring_QStandardPaths_locateAll);
	RING_API_REGISTER("qstandardpaths_settestmodeenabled",ring_QStandardPaths_setTestModeEnabled);
	RING_API_REGISTER("qstandardpaths_standardlocations",ring_QStandardPaths_standardLocations);
	RING_API_REGISTER("qstandardpaths_writablelocation",ring_QStandardPaths_writableLocation);
	RING_API_REGISTER("qmimedata_clear",ring_QMimeData_clear);
	RING_API_REGISTER("qmimedata_colordata",ring_QMimeData_colorData);
	RING_API_REGISTER("qmimedata_data",ring_QMimeData_data);
	RING_API_REGISTER("qmimedata_formats",ring_QMimeData_formats);
	RING_API_REGISTER("qmimedata_hascolor",ring_QMimeData_hasColor);
	RING_API_REGISTER("qmimedata_hasformat",ring_QMimeData_hasFormat);
	RING_API_REGISTER("qmimedata_hashtml",ring_QMimeData_hasHtml);
	RING_API_REGISTER("qmimedata_hasimage",ring_QMimeData_hasImage);
	RING_API_REGISTER("qmimedata_hastext",ring_QMimeData_hasText);
	RING_API_REGISTER("qmimedata_hasurls",ring_QMimeData_hasUrls);
	RING_API_REGISTER("qmimedata_html",ring_QMimeData_html);
	RING_API_REGISTER("qmimedata_imagedata",ring_QMimeData_imageData);
	RING_API_REGISTER("qmimedata_removeformat",ring_QMimeData_removeFormat);
	RING_API_REGISTER("qmimedata_setcolordata",ring_QMimeData_setColorData);
	RING_API_REGISTER("qmimedata_setdata",ring_QMimeData_setData);
	RING_API_REGISTER("qmimedata_sethtml",ring_QMimeData_setHtml);
	RING_API_REGISTER("qmimedata_setimagedata",ring_QMimeData_setImageData);
	RING_API_REGISTER("qmimedata_settext",ring_QMimeData_setText);
	RING_API_REGISTER("qmimedata_seturls",ring_QMimeData_setUrls);
	RING_API_REGISTER("qmimedata_text",ring_QMimeData_text);
	RING_API_REGISTER("qmimedata_urls",ring_QMimeData_urls);
	RING_API_REGISTER("qchar_category",ring_QChar_category);
	RING_API_REGISTER("qchar_cell",ring_QChar_cell);
	RING_API_REGISTER("qchar_combiningclass",ring_QChar_combiningClass);
	RING_API_REGISTER("qchar_decomposition",ring_QChar_decomposition);
	RING_API_REGISTER("qchar_decompositiontag",ring_QChar_decompositionTag);
	RING_API_REGISTER("qchar_digitvalue",ring_QChar_digitValue);
	RING_API_REGISTER("qchar_direction",ring_QChar_direction);
	RING_API_REGISTER("qchar_hasmirrored",ring_QChar_hasMirrored);
	RING_API_REGISTER("qchar_isdigit",ring_QChar_isDigit);
	RING_API_REGISTER("qchar_ishighsurrogate",ring_QChar_isHighSurrogate);
	RING_API_REGISTER("qchar_isletter",ring_QChar_isLetter);
	RING_API_REGISTER("qchar_isletterornumber",ring_QChar_isLetterOrNumber);
	RING_API_REGISTER("qchar_islowsurrogate",ring_QChar_isLowSurrogate);
	RING_API_REGISTER("qchar_islower",ring_QChar_isLower);
	RING_API_REGISTER("qchar_ismark",ring_QChar_isMark);
	RING_API_REGISTER("qchar_isnoncharacter",ring_QChar_isNonCharacter);
	RING_API_REGISTER("qchar_isnull",ring_QChar_isNull);
	RING_API_REGISTER("qchar_isnumber",ring_QChar_isNumber);
	RING_API_REGISTER("qchar_isprint",ring_QChar_isPrint);
	RING_API_REGISTER("qchar_ispunct",ring_QChar_isPunct);
	RING_API_REGISTER("qchar_isspace",ring_QChar_isSpace);
	RING_API_REGISTER("qchar_issurrogate",ring_QChar_isSurrogate);
	RING_API_REGISTER("qchar_issymbol",ring_QChar_isSymbol);
	RING_API_REGISTER("qchar_istitlecase",ring_QChar_isTitleCase);
	RING_API_REGISTER("qchar_isupper",ring_QChar_isUpper);
	RING_API_REGISTER("qchar_mirroredchar",ring_QChar_mirroredChar);
	RING_API_REGISTER("qchar_row",ring_QChar_row);
	RING_API_REGISTER("qchar_script",ring_QChar_script);
	RING_API_REGISTER("qchar_tocasefolded",ring_QChar_toCaseFolded);
	RING_API_REGISTER("qchar_tolatin1",ring_QChar_toLatin1);
	RING_API_REGISTER("qchar_tolower",ring_QChar_toLower);
	RING_API_REGISTER("qchar_totitlecase",ring_QChar_toTitleCase);
	RING_API_REGISTER("qchar_toupper",ring_QChar_toUpper);
	RING_API_REGISTER("qchar_unicode",ring_QChar_unicode);
	RING_API_REGISTER("qchar_unicode_2",ring_QChar_unicode_2);
	RING_API_REGISTER("qchar_unicodeversion",ring_QChar_unicodeVersion);
	RING_API_REGISTER("qchar_category_2",ring_QChar_category_2);
	RING_API_REGISTER("qchar_combiningclass_2",ring_QChar_combiningClass_2);
	RING_API_REGISTER("qchar_currentunicodeversion",ring_QChar_currentUnicodeVersion);
	RING_API_REGISTER("qchar_decomposition_2",ring_QChar_decomposition_2);
	RING_API_REGISTER("qchar_decompositiontag_2",ring_QChar_decompositionTag_2);
	RING_API_REGISTER("qchar_digitvalue_2",ring_QChar_digitValue_2);
	RING_API_REGISTER("qchar_direction_2",ring_QChar_direction_2);
	RING_API_REGISTER("qchar_fromlatin1",ring_QChar_fromLatin1);
	RING_API_REGISTER("qchar_hasmirrored_2",ring_QChar_hasMirrored_2);
	RING_API_REGISTER("qchar_highsurrogate",ring_QChar_highSurrogate);
	RING_API_REGISTER("qchar_isdigit_2",ring_QChar_isDigit_2);
	RING_API_REGISTER("qchar_ishighsurrogate_2",ring_QChar_isHighSurrogate_2);
	RING_API_REGISTER("qchar_isletter_2",ring_QChar_isLetter_2);
	RING_API_REGISTER("qchar_isletterornumber_2",ring_QChar_isLetterOrNumber_2);
	RING_API_REGISTER("qchar_islowsurrogate_2",ring_QChar_isLowSurrogate_2);
	RING_API_REGISTER("qchar_islower_2",ring_QChar_isLower_2);
	RING_API_REGISTER("qchar_ismark_2",ring_QChar_isMark_2);
	RING_API_REGISTER("qchar_isnoncharacter_2",ring_QChar_isNonCharacter_2);
	RING_API_REGISTER("qchar_isnumber_2",ring_QChar_isNumber_2);
	RING_API_REGISTER("qchar_isprint_2",ring_QChar_isPrint_2);
	RING_API_REGISTER("qchar_ispunct_2",ring_QChar_isPunct_2);
	RING_API_REGISTER("qchar_isspace_2",ring_QChar_isSpace_2);
	RING_API_REGISTER("qchar_issurrogate_2",ring_QChar_isSurrogate_2);
	RING_API_REGISTER("qchar_issymbol_2",ring_QChar_isSymbol_2);
	RING_API_REGISTER("qchar_istitlecase_2",ring_QChar_isTitleCase_2);
	RING_API_REGISTER("qchar_isupper_2",ring_QChar_isUpper_2);
	RING_API_REGISTER("qchar_lowsurrogate",ring_QChar_lowSurrogate);
	RING_API_REGISTER("qchar_mirroredchar_2",ring_QChar_mirroredChar_2);
	RING_API_REGISTER("qchar_requiressurrogates",ring_QChar_requiresSurrogates);
	RING_API_REGISTER("qchar_script_2",ring_QChar_script_2);
	RING_API_REGISTER("qchar_surrogatetoucs4",ring_QChar_surrogateToUcs4);
	RING_API_REGISTER("qchar_surrogatetoucs4_2",ring_QChar_surrogateToUcs4_2);
	RING_API_REGISTER("qchar_tocasefolded_2",ring_QChar_toCaseFolded_2);
	RING_API_REGISTER("qchar_tolower_2",ring_QChar_toLower_2);
	RING_API_REGISTER("qchar_totitlecase_2",ring_QChar_toTitleCase_2);
	RING_API_REGISTER("qchar_toupper_2",ring_QChar_toUpper_2);
	RING_API_REGISTER("qchar_unicodeversion_2",ring_QChar_unicodeVersion_2);
	RING_API_REGISTER("qchildevent_added",ring_QChildEvent_added);
	RING_API_REGISTER("qchildevent_child",ring_QChildEvent_child);
	RING_API_REGISTER("qchildevent_polished",ring_QChildEvent_polished);
	RING_API_REGISTER("qchildevent_removed",ring_QChildEvent_removed);
	RING_API_REGISTER("qlocale_amtext",ring_QLocale_amText);
	RING_API_REGISTER("qlocale_bcp47name",ring_QLocale_bcp47Name);
	RING_API_REGISTER("qlocale_country",ring_QLocale_country);
	RING_API_REGISTER("qlocale_createseparatedlist",ring_QLocale_createSeparatedList);
	RING_API_REGISTER("qlocale_currencysymbol",ring_QLocale_currencySymbol);
	RING_API_REGISTER("qlocale_dateformat",ring_QLocale_dateFormat);
	RING_API_REGISTER("qlocale_datetimeformat",ring_QLocale_dateTimeFormat);
	RING_API_REGISTER("qlocale_dayname",ring_QLocale_dayName);
	RING_API_REGISTER("qlocale_decimalpoint",ring_QLocale_decimalPoint);
	RING_API_REGISTER("qlocale_exponential",ring_QLocale_exponential);
	RING_API_REGISTER("qlocale_firstdayofweek",ring_QLocale_firstDayOfWeek);
	RING_API_REGISTER("qlocale_groupseparator",ring_QLocale_groupSeparator);
	RING_API_REGISTER("qlocale_language",ring_QLocale_language);
	RING_API_REGISTER("qlocale_measurementsystem",ring_QLocale_measurementSystem);
	RING_API_REGISTER("qlocale_monthname",ring_QLocale_monthName);
	RING_API_REGISTER("qlocale_name",ring_QLocale_name);
	RING_API_REGISTER("qlocale_nativecountryname",ring_QLocale_nativeCountryName);
	RING_API_REGISTER("qlocale_nativelanguagename",ring_QLocale_nativeLanguageName);
	RING_API_REGISTER("qlocale_negativesign",ring_QLocale_negativeSign);
	RING_API_REGISTER("qlocale_numberoptions",ring_QLocale_numberOptions);
	RING_API_REGISTER("qlocale_percent",ring_QLocale_percent);
	RING_API_REGISTER("qlocale_pmtext",ring_QLocale_pmText);
	RING_API_REGISTER("qlocale_positivesign",ring_QLocale_positiveSign);
	RING_API_REGISTER("qlocale_quotestring",ring_QLocale_quoteString);
	RING_API_REGISTER("qlocale_script",ring_QLocale_script);
	RING_API_REGISTER("qlocale_setnumberoptions",ring_QLocale_setNumberOptions);
	RING_API_REGISTER("qlocale_standalonedayname",ring_QLocale_standaloneDayName);
	RING_API_REGISTER("qlocale_standalonemonthname",ring_QLocale_standaloneMonthName);
	RING_API_REGISTER("qlocale_textdirection",ring_QLocale_textDirection);
	RING_API_REGISTER("qlocale_timeformat",ring_QLocale_timeFormat);
	RING_API_REGISTER("qlocale_todouble",ring_QLocale_toDouble);
	RING_API_REGISTER("qlocale_tofloat",ring_QLocale_toFloat);
	RING_API_REGISTER("qlocale_toint",ring_QLocale_toInt);
	RING_API_REGISTER("qlocale_tolonglong",ring_QLocale_toLongLong);
	RING_API_REGISTER("qlocale_tolower",ring_QLocale_toLower);
	RING_API_REGISTER("qlocale_toshort",ring_QLocale_toShort);
	RING_API_REGISTER("qlocale_tostring",ring_QLocale_toString);
	RING_API_REGISTER("qlocale_tostring_2",ring_QLocale_toString_2);
	RING_API_REGISTER("qlocale_tostring_4",ring_QLocale_toString_4);
	RING_API_REGISTER("qlocale_tostring_5",ring_QLocale_toString_5);
	RING_API_REGISTER("qlocale_tostring_6",ring_QLocale_toString_6);
	RING_API_REGISTER("qlocale_tostring_7",ring_QLocale_toString_7);
	RING_API_REGISTER("qlocale_tostring_8",ring_QLocale_toString_8);
	RING_API_REGISTER("qlocale_tostring_9",ring_QLocale_toString_9);
	RING_API_REGISTER("qlocale_tostring_10",ring_QLocale_toString_10);
	RING_API_REGISTER("qlocale_tostring_11",ring_QLocale_toString_11);
	RING_API_REGISTER("qlocale_tostring_12",ring_QLocale_toString_12);
	RING_API_REGISTER("qlocale_tostring_13",ring_QLocale_toString_13);
	RING_API_REGISTER("qlocale_tostring_14",ring_QLocale_toString_14);
	RING_API_REGISTER("qlocale_tostring_15",ring_QLocale_toString_15);
	RING_API_REGISTER("qlocale_totime",ring_QLocale_toTime);
	RING_API_REGISTER("qlocale_totime_2",ring_QLocale_toTime_2);
	RING_API_REGISTER("qlocale_touint",ring_QLocale_toUInt);
	RING_API_REGISTER("qlocale_toulonglong",ring_QLocale_toULongLong);
	RING_API_REGISTER("qlocale_toushort",ring_QLocale_toUShort);
	RING_API_REGISTER("qlocale_toupper",ring_QLocale_toUpper);
	RING_API_REGISTER("qlocale_uilanguages",ring_QLocale_uiLanguages);
	RING_API_REGISTER("qlocale_weekdays",ring_QLocale_weekdays);
	RING_API_REGISTER("qlocale_zerodigit",ring_QLocale_zeroDigit);
	RING_API_REGISTER("qlocale_c",ring_QLocale_c);
	RING_API_REGISTER("qlocale_countrytostring",ring_QLocale_countryToString);
	RING_API_REGISTER("qlocale_languagetostring",ring_QLocale_languageToString);
	RING_API_REGISTER("qlocale_matchinglocales",ring_QLocale_matchingLocales);
	RING_API_REGISTER("qlocale_scripttostring",ring_QLocale_scriptToString);
	RING_API_REGISTER("qlocale_setdefault",ring_QLocale_setDefault);
	RING_API_REGISTER("qlocale_system",ring_QLocale_system);
	RING_API_REGISTER("qthread_eventdispatcher",ring_QThread_eventDispatcher);
	RING_API_REGISTER("qthread_exit",ring_QThread_exit);
	RING_API_REGISTER("qthread_isfinished",ring_QThread_isFinished);
	RING_API_REGISTER("qthread_isinterruptionrequested",ring_QThread_isInterruptionRequested);
	RING_API_REGISTER("qthread_isrunning",ring_QThread_isRunning);
	RING_API_REGISTER("qthread_priority",ring_QThread_priority);
	RING_API_REGISTER("qthread_requestinterruption",ring_QThread_requestInterruption);
	RING_API_REGISTER("qthread_seteventdispatcher",ring_QThread_setEventDispatcher);
	RING_API_REGISTER("qthread_setpriority",ring_QThread_setPriority);
	RING_API_REGISTER("qthread_setstacksize",ring_QThread_setStackSize);
	RING_API_REGISTER("qthread_stacksize",ring_QThread_stackSize);
	RING_API_REGISTER("qthread_wait",ring_QThread_wait);
	RING_API_REGISTER("qthread_quit",ring_QThread_quit);
	RING_API_REGISTER("qthread_start",ring_QThread_start);
	RING_API_REGISTER("qthread_terminate",ring_QThread_terminate);
	RING_API_REGISTER("qthread_currentthread",ring_QThread_currentThread);
	RING_API_REGISTER("qthread_currentthreadid",ring_QThread_currentThreadId);
	RING_API_REGISTER("qthread_idealthreadcount",ring_QThread_idealThreadCount);
	RING_API_REGISTER("qthread_msleep",ring_QThread_msleep);
	RING_API_REGISTER("qthread_sleep",ring_QThread_sleep);
	RING_API_REGISTER("qthread_usleep",ring_QThread_usleep);
	RING_API_REGISTER("qthread_yieldcurrentthread",ring_QThread_yieldCurrentThread);
	RING_API_REGISTER("qthread_setstartedevent",ring_QThread_setStartedEvent);
	RING_API_REGISTER("qthread_setfinishedevent",ring_QThread_setFinishedEvent);
	RING_API_REGISTER("qthread_getstartedevent",ring_QThread_getStartedEvent);
	RING_API_REGISTER("qthread_getfinishedevent",ring_QThread_getFinishedEvent);
	RING_API_REGISTER("qthreadpool_activethreadcount",ring_QThreadPool_activeThreadCount);
	RING_API_REGISTER("qthreadpool_clear",ring_QThreadPool_clear);
	RING_API_REGISTER("qthreadpool_expirytimeout",ring_QThreadPool_expiryTimeout);
	RING_API_REGISTER("qthreadpool_maxthreadcount",ring_QThreadPool_maxThreadCount);
	RING_API_REGISTER("qthreadpool_releasethread",ring_QThreadPool_releaseThread);
	RING_API_REGISTER("qthreadpool_reservethread",ring_QThreadPool_reserveThread);
	RING_API_REGISTER("qthreadpool_setexpirytimeout",ring_QThreadPool_setExpiryTimeout);
	RING_API_REGISTER("qthreadpool_setmaxthreadcount",ring_QThreadPool_setMaxThreadCount);
	RING_API_REGISTER("qthreadpool_start",ring_QThreadPool_start);
	RING_API_REGISTER("qthreadpool_trystart",ring_QThreadPool_tryStart);
	RING_API_REGISTER("qthreadpool_waitfordone",ring_QThreadPool_waitForDone);
	RING_API_REGISTER("qthreadpool_globalinstance",ring_QThreadPool_globalInstance);
	RING_API_REGISTER("qprocess_arguments",ring_QProcess_arguments);
	RING_API_REGISTER("qprocess_closereadchannel",ring_QProcess_closeReadChannel);
	RING_API_REGISTER("qprocess_closewritechannel",ring_QProcess_closeWriteChannel);
	RING_API_REGISTER("qprocess_error",ring_QProcess_error);
	RING_API_REGISTER("qprocess_exitcode",ring_QProcess_exitCode);
	RING_API_REGISTER("qprocess_exitstatus",ring_QProcess_exitStatus);
	RING_API_REGISTER("qprocess_inputchannelmode",ring_QProcess_inputChannelMode);
	RING_API_REGISTER("qprocess_processchannelmode",ring_QProcess_processChannelMode);
	RING_API_REGISTER("qprocess_processenvironment",ring_QProcess_processEnvironment);
	RING_API_REGISTER("qprocess_program",ring_QProcess_program);
	RING_API_REGISTER("qprocess_readallstandarderror",ring_QProcess_readAllStandardError);
	RING_API_REGISTER("qprocess_readallstandardoutput",ring_QProcess_readAllStandardOutput);
	RING_API_REGISTER("qprocess_readchannel",ring_QProcess_readChannel);
	RING_API_REGISTER("qprocess_setarguments",ring_QProcess_setArguments);
	RING_API_REGISTER("qprocess_setinputchannelmode",ring_QProcess_setInputChannelMode);
	RING_API_REGISTER("qprocess_setprocesschannelmode",ring_QProcess_setProcessChannelMode);
	RING_API_REGISTER("qprocess_setprocessenvironment",ring_QProcess_setProcessEnvironment);
	RING_API_REGISTER("qprocess_setprogram",ring_QProcess_setProgram);
	RING_API_REGISTER("qprocess_setreadchannel",ring_QProcess_setReadChannel);
	RING_API_REGISTER("qprocess_setstandarderrorfile",ring_QProcess_setStandardErrorFile);
	RING_API_REGISTER("qprocess_setstandardinputfile",ring_QProcess_setStandardInputFile);
	RING_API_REGISTER("qprocess_setstandardoutputfile",ring_QProcess_setStandardOutputFile);
	RING_API_REGISTER("qprocess_setstandardoutputprocess",ring_QProcess_setStandardOutputProcess);
	RING_API_REGISTER("qprocess_setworkingdirectory",ring_QProcess_setWorkingDirectory);
	RING_API_REGISTER("qprocess_start",ring_QProcess_start);
	RING_API_REGISTER("qprocess_start_3",ring_QProcess_start_3);
	RING_API_REGISTER("qprocess_state",ring_QProcess_state);
	RING_API_REGISTER("qprocess_waitforfinished",ring_QProcess_waitForFinished);
	RING_API_REGISTER("qprocess_waitforstarted",ring_QProcess_waitForStarted);
	RING_API_REGISTER("qprocess_workingdirectory",ring_QProcess_workingDirectory);
	RING_API_REGISTER("qprocess_kill",ring_QProcess_kill);
	RING_API_REGISTER("qprocess_terminate",ring_QProcess_terminate);
	RING_API_REGISTER("qprocess_setreadyreadstandarderrorevent",ring_QProcess_setreadyReadStandardErrorEvent);
	RING_API_REGISTER("qprocess_setreadyreadstandardoutputevent",ring_QProcess_setreadyReadStandardOutputEvent);
	RING_API_REGISTER("qprocess_getreadyreadstandarderrorevent",ring_QProcess_getreadyReadStandardErrorEvent);
	RING_API_REGISTER("qprocess_getreadyreadstandardoutputevent",ring_QProcess_getreadyReadStandardOutputEvent);
	RING_API_REGISTER("quuid_tostring",ring_QUuid_toString);
	RING_API_REGISTER("qmutex_lock",ring_QMutex_lock);
	RING_API_REGISTER("qmutex_unlock",ring_QMutex_unlock);
	RING_API_REGISTER("qmutexlocker_mutex",ring_QMutexLocker_mutex);
	RING_API_REGISTER("qmutexlocker_relock",ring_QMutexLocker_relock);
	RING_API_REGISTER("qmutexlocker_unlock",ring_QMutexLocker_unlock);
	RING_API_REGISTER("qversionnumber_isnormalized",ring_QVersionNumber_isNormalized);
	RING_API_REGISTER("qversionnumber_isnull",ring_QVersionNumber_isNull);
	RING_API_REGISTER("qversionnumber_isprefixof",ring_QVersionNumber_isPrefixOf);
	RING_API_REGISTER("qversionnumber_majorversion",ring_QVersionNumber_majorVersion);
	RING_API_REGISTER("qversionnumber_microversion",ring_QVersionNumber_microVersion);
	RING_API_REGISTER("qversionnumber_minorversion",ring_QVersionNumber_minorVersion);
	RING_API_REGISTER("qversionnumber_normalized",ring_QVersionNumber_normalized);
	RING_API_REGISTER("qversionnumber_segmentat",ring_QVersionNumber_segmentAt);
	RING_API_REGISTER("qversionnumber_segmentcount",ring_QVersionNumber_segmentCount);
	RING_API_REGISTER("qversionnumber_segments",ring_QVersionNumber_segments);
	RING_API_REGISTER("qversionnumber_tostring",ring_QVersionNumber_toString);
	RING_API_REGISTER("qlibraryinfo_isdebugbuild",ring_QLibraryInfo_isDebugBuild);
	RING_API_REGISTER("qlibraryinfo_version",ring_QLibraryInfo_version);
	RING_API_REGISTER("qpixmap_transformed",ring_QPixmap_transformed);
	RING_API_REGISTER("qpixmap_copy",ring_QPixmap_copy);
	RING_API_REGISTER("qpixmap_scaled",ring_QPixmap_scaled);
	RING_API_REGISTER("qpixmap_width",ring_QPixmap_width);
	RING_API_REGISTER("qpixmap_height",ring_QPixmap_height);
	RING_API_REGISTER("qpixmap_createmaskfromcolor",ring_QPixmap_createMaskFromColor);
	RING_API_REGISTER("qpixmap_mask",ring_QPixmap_mask);
	RING_API_REGISTER("qpixmap_setmask",ring_QPixmap_setMask);
	RING_API_REGISTER("qpixmap_fill",ring_QPixmap_fill);
	RING_API_REGISTER("qpixmap_fromimage",ring_QPixmap_fromImage);
	RING_API_REGISTER("qpixmap_load",ring_QPixmap_load);
	RING_API_REGISTER("qpixmap_cachekey",ring_QPixmap_cacheKey);
	RING_API_REGISTER("qpixmap_convertfromimage",ring_QPixmap_convertFromImage);
	RING_API_REGISTER("qpixmap_copy_2",ring_QPixmap_copy_2);
	RING_API_REGISTER("qpixmap_createheuristicmask",ring_QPixmap_createHeuristicMask);
	RING_API_REGISTER("qpixmap_depth",ring_QPixmap_depth);
	RING_API_REGISTER("qpixmap_detach",ring_QPixmap_detach);
	RING_API_REGISTER("qpixmap_devicepixelratio",ring_QPixmap_devicePixelRatio);
	RING_API_REGISTER("qpixmap_hasalpha",ring_QPixmap_hasAlpha);
	RING_API_REGISTER("qpixmap_hasalphachannel",ring_QPixmap_hasAlphaChannel);
	RING_API_REGISTER("qpixmap_isnull",ring_QPixmap_isNull);
	RING_API_REGISTER("qpixmap_isqbitmap",ring_QPixmap_isQBitmap);
	RING_API_REGISTER("qpixmap_loadfromdata",ring_QPixmap_loadFromData);
	RING_API_REGISTER("qpixmap_loadfromdata_2",ring_QPixmap_loadFromData_2);
	RING_API_REGISTER("qpixmap_rect",ring_QPixmap_rect);
	RING_API_REGISTER("qpixmap_save",ring_QPixmap_save);
	RING_API_REGISTER("qpixmap_save_2",ring_QPixmap_save_2);
	RING_API_REGISTER("qpixmap_scaled_2",ring_QPixmap_scaled_2);
	RING_API_REGISTER("qpixmap_scaledtoheight",ring_QPixmap_scaledToHeight);
	RING_API_REGISTER("qpixmap_scaledtowidth",ring_QPixmap_scaledToWidth);
	RING_API_REGISTER("qpixmap_scroll",ring_QPixmap_scroll);
	RING_API_REGISTER("qpixmap_scroll_2",ring_QPixmap_scroll_2);
	RING_API_REGISTER("qpixmap_setdevicepixelratio",ring_QPixmap_setDevicePixelRatio);
	RING_API_REGISTER("qpixmap_size",ring_QPixmap_size);
	RING_API_REGISTER("qpixmap_swap",ring_QPixmap_swap);
	RING_API_REGISTER("qpixmap_toimage",ring_QPixmap_toImage);
	RING_API_REGISTER("qpixmap_transformed_2",ring_QPixmap_transformed_2);
	RING_API_REGISTER("qpixmap_defaultdepth",ring_QPixmap_defaultDepth);
	RING_API_REGISTER("qpixmap_fromimage_2",ring_QPixmap_fromImage_2);
	RING_API_REGISTER("qpixmap_fromimagereader",ring_QPixmap_fromImageReader);
	RING_API_REGISTER("qpixmap_truematrix",ring_QPixmap_trueMatrix);
	RING_API_REGISTER("qpicture_boundingrect",ring_QPicture_boundingRect);
	RING_API_REGISTER("qpicture_data",ring_QPicture_data);
	RING_API_REGISTER("qpicture_isnull",ring_QPicture_isNull);
	RING_API_REGISTER("qpicture_load",ring_QPicture_load);
	RING_API_REGISTER("qpicture_play",ring_QPicture_play);
	RING_API_REGISTER("qpicture_save",ring_QPicture_save);
	RING_API_REGISTER("qpicture_setboundingrect",ring_QPicture_setBoundingRect);
	RING_API_REGISTER("qpicture_size",ring_QPicture_size);
	RING_API_REGISTER("qpicture_swap",ring_QPicture_swap);
	RING_API_REGISTER("qfont_bold",ring_QFont_bold);
	RING_API_REGISTER("qfont_capitalization",ring_QFont_capitalization);
	RING_API_REGISTER("qfont_defaultfamily",ring_QFont_defaultFamily);
	RING_API_REGISTER("qfont_exactmatch",ring_QFont_exactMatch);
	RING_API_REGISTER("qfont_family",ring_QFont_family);
	RING_API_REGISTER("qfont_fixedpitch",ring_QFont_fixedPitch);
	RING_API_REGISTER("qfont_fromstring",ring_QFont_fromString);
	RING_API_REGISTER("qfont_hintingpreference",ring_QFont_hintingPreference);
	RING_API_REGISTER("qfont_iscopyof",ring_QFont_isCopyOf);
	RING_API_REGISTER("qfont_italic",ring_QFont_italic);
	RING_API_REGISTER("qfont_kerning",ring_QFont_kerning);
	RING_API_REGISTER("qfont_key",ring_QFont_key);
	RING_API_REGISTER("qfont_letterspacing",ring_QFont_letterSpacing);
	RING_API_REGISTER("qfont_letterspacingtype",ring_QFont_letterSpacingType);
	RING_API_REGISTER("qfont_overline",ring_QFont_overline);
	RING_API_REGISTER("qfont_pixelsize",ring_QFont_pixelSize);
	RING_API_REGISTER("qfont_pointsize",ring_QFont_pointSize);
	RING_API_REGISTER("qfont_pointsizef",ring_QFont_pointSizeF);
	RING_API_REGISTER("qfont_resolve",ring_QFont_resolve);
	RING_API_REGISTER("qfont_setbold",ring_QFont_setBold);
	RING_API_REGISTER("qfont_setcapitalization",ring_QFont_setCapitalization);
	RING_API_REGISTER("qfont_setfamily",ring_QFont_setFamily);
	RING_API_REGISTER("qfont_setfixedpitch",ring_QFont_setFixedPitch);
	RING_API_REGISTER("qfont_sethintingpreference",ring_QFont_setHintingPreference);
	RING_API_REGISTER("qfont_setitalic",ring_QFont_setItalic);
	RING_API_REGISTER("qfont_setkerning",ring_QFont_setKerning);
	RING_API_REGISTER("qfont_setletterspacing",ring_QFont_setLetterSpacing);
	RING_API_REGISTER("qfont_setoverline",ring_QFont_setOverline);
	RING_API_REGISTER("qfont_setpixelsize",ring_QFont_setPixelSize);
	RING_API_REGISTER("qfont_setpointsize",ring_QFont_setPointSize);
	RING_API_REGISTER("qfont_setpointsizef",ring_QFont_setPointSizeF);
	RING_API_REGISTER("qfont_setstretch",ring_QFont_setStretch);
	RING_API_REGISTER("qfont_setstrikeout",ring_QFont_setStrikeOut);
	RING_API_REGISTER("qfont_setstyle",ring_QFont_setStyle);
	RING_API_REGISTER("qfont_setstylehint",ring_QFont_setStyleHint);
	RING_API_REGISTER("qfont_setstylename",ring_QFont_setStyleName);
	RING_API_REGISTER("qfont_setstylestrategy",ring_QFont_setStyleStrategy);
	RING_API_REGISTER("qfont_setunderline",ring_QFont_setUnderline);
	RING_API_REGISTER("qfont_setweight",ring_QFont_setWeight);
	RING_API_REGISTER("qfont_setwordspacing",ring_QFont_setWordSpacing);
	RING_API_REGISTER("qfont_stretch",ring_QFont_stretch);
	RING_API_REGISTER("qfont_strikeout",ring_QFont_strikeOut);
	RING_API_REGISTER("qfont_style",ring_QFont_style);
	RING_API_REGISTER("qfont_stylehint",ring_QFont_styleHint);
	RING_API_REGISTER("qfont_stylename",ring_QFont_styleName);
	RING_API_REGISTER("qfont_stylestrategy",ring_QFont_styleStrategy);
	RING_API_REGISTER("qfont_tostring",ring_QFont_toString);
	RING_API_REGISTER("qfont_underline",ring_QFont_underline);
	RING_API_REGISTER("qfont_weight",ring_QFont_weight);
	RING_API_REGISTER("qfont_wordspacing",ring_QFont_wordSpacing);
	RING_API_REGISTER("qfont_insertsubstitution",ring_QFont_insertSubstitution);
	RING_API_REGISTER("qfont_insertsubstitutions",ring_QFont_insertSubstitutions);
	RING_API_REGISTER("qfont_substitute",ring_QFont_substitute);
	RING_API_REGISTER("qfont_substitutes",ring_QFont_substitutes);
	RING_API_REGISTER("qfont_substitutions",ring_QFont_substitutions);
	RING_API_REGISTER("qimage_allgray",ring_QImage_allGray);
	RING_API_REGISTER("qimage_bitplanecount",ring_QImage_bitPlaneCount);
	RING_API_REGISTER("qimage_bits",ring_QImage_bits);
	RING_API_REGISTER("qimage_bytesperline",ring_QImage_bytesPerLine);
	RING_API_REGISTER("qimage_cachekey",ring_QImage_cacheKey);
	RING_API_REGISTER("qimage_color",ring_QImage_color);
	RING_API_REGISTER("qimage_colorcount",ring_QImage_colorCount);
	RING_API_REGISTER("qimage_constbits",ring_QImage_constBits);
	RING_API_REGISTER("qimage_constscanline",ring_QImage_constScanLine);
	RING_API_REGISTER("qimage_converttoformat",ring_QImage_convertToFormat);
	RING_API_REGISTER("qimage_copy",ring_QImage_copy);
	RING_API_REGISTER("qimage_createalphamask",ring_QImage_createAlphaMask);
	RING_API_REGISTER("qimage_createheuristicmask",ring_QImage_createHeuristicMask);
	RING_API_REGISTER("qimage_createmaskfromcolor",ring_QImage_createMaskFromColor);
	RING_API_REGISTER("qimage_depth",ring_QImage_depth);
	RING_API_REGISTER("qimage_dotspermeterx",ring_QImage_dotsPerMeterX);
	RING_API_REGISTER("qimage_dotspermetery",ring_QImage_dotsPerMeterY);
	RING_API_REGISTER("qimage_fill",ring_QImage_fill);
	RING_API_REGISTER("qimage_format",ring_QImage_format);
	RING_API_REGISTER("qimage_hasalphachannel",ring_QImage_hasAlphaChannel);
	RING_API_REGISTER("qimage_height",ring_QImage_height);
	RING_API_REGISTER("qimage_invertpixels",ring_QImage_invertPixels);
	RING_API_REGISTER("qimage_isgrayscale",ring_QImage_isGrayscale);
	RING_API_REGISTER("qimage_isnull",ring_QImage_isNull);
	RING_API_REGISTER("qimage_load",ring_QImage_load);
	RING_API_REGISTER("qimage_loadfromdata",ring_QImage_loadFromData);
	RING_API_REGISTER("qimage_mirrored",ring_QImage_mirrored);
	RING_API_REGISTER("qimage_offset",ring_QImage_offset);
	RING_API_REGISTER("qimage_pixel",ring_QImage_pixel);
	RING_API_REGISTER("qimage_pixelindex",ring_QImage_pixelIndex);
	RING_API_REGISTER("qimage_rect",ring_QImage_rect);
	RING_API_REGISTER("qimage_rgbswapped",ring_QImage_rgbSwapped);
	RING_API_REGISTER("qimage_save",ring_QImage_save);
	RING_API_REGISTER("qimage_scaled",ring_QImage_scaled);
	RING_API_REGISTER("qimage_scaledtoheight",ring_QImage_scaledToHeight);
	RING_API_REGISTER("qimage_scaledtowidth",ring_QImage_scaledToWidth);
	RING_API_REGISTER("qimage_scanline",ring_QImage_scanLine);
	RING_API_REGISTER("qimage_setcolor",ring_QImage_setColor);
	RING_API_REGISTER("qimage_setcolorcount",ring_QImage_setColorCount);
	RING_API_REGISTER("qimage_setdotspermeterx",ring_QImage_setDotsPerMeterX);
	RING_API_REGISTER("qimage_setdotspermetery",ring_QImage_setDotsPerMeterY);
	RING_API_REGISTER("qimage_setoffset",ring_QImage_setOffset);
	RING_API_REGISTER("qimage_setpixel",ring_QImage_setPixel);
	RING_API_REGISTER("qimage_settext",ring_QImage_setText);
	RING_API_REGISTER("qimage_size",ring_QImage_size);
	RING_API_REGISTER("qimage_swap",ring_QImage_swap);
	RING_API_REGISTER("qimage_text",ring_QImage_text);
	RING_API_REGISTER("qimage_textkeys",ring_QImage_textKeys);
	RING_API_REGISTER("qimage_valid",ring_QImage_valid);
	RING_API_REGISTER("qimage_width",ring_QImage_width);
	RING_API_REGISTER("qwindow_basesize",ring_QWindow_baseSize);
	RING_API_REGISTER("qwindow_contentorientation",ring_QWindow_contentOrientation);
	RING_API_REGISTER("qwindow_create",ring_QWindow_create);
	RING_API_REGISTER("qwindow_cursor",ring_QWindow_cursor);
	RING_API_REGISTER("qwindow_destroy",ring_QWindow_destroy);
	RING_API_REGISTER("qwindow_devicepixelratio",ring_QWindow_devicePixelRatio);
	RING_API_REGISTER("qwindow_filepath",ring_QWindow_filePath);
	RING_API_REGISTER("qwindow_flags",ring_QWindow_flags);
	RING_API_REGISTER("qwindow_focusobject",ring_QWindow_focusObject);
	RING_API_REGISTER("qwindow_framegeometry",ring_QWindow_frameGeometry);
	RING_API_REGISTER("qwindow_framemargins",ring_QWindow_frameMargins);
	RING_API_REGISTER("qwindow_frameposition",ring_QWindow_framePosition);
	RING_API_REGISTER("qwindow_geometry",ring_QWindow_geometry);
	RING_API_REGISTER("qwindow_height",ring_QWindow_height);
	RING_API_REGISTER("qwindow_icon",ring_QWindow_icon);
	RING_API_REGISTER("qwindow_isactive",ring_QWindow_isActive);
	RING_API_REGISTER("qwindow_isancestorof",ring_QWindow_isAncestorOf);
	RING_API_REGISTER("qwindow_isexposed",ring_QWindow_isExposed);
	RING_API_REGISTER("qwindow_ismodal",ring_QWindow_isModal);
	RING_API_REGISTER("qwindow_istoplevel",ring_QWindow_isTopLevel);
	RING_API_REGISTER("qwindow_isvisible",ring_QWindow_isVisible);
	RING_API_REGISTER("qwindow_mapfromglobal",ring_QWindow_mapFromGlobal);
	RING_API_REGISTER("qwindow_maptoglobal",ring_QWindow_mapToGlobal);
	RING_API_REGISTER("qwindow_mask",ring_QWindow_mask);
	RING_API_REGISTER("qwindow_maximumheight",ring_QWindow_maximumHeight);
	RING_API_REGISTER("qwindow_maximumsize",ring_QWindow_maximumSize);
	RING_API_REGISTER("qwindow_maximumwidth",ring_QWindow_maximumWidth);
	RING_API_REGISTER("qwindow_minimumheight",ring_QWindow_minimumHeight);
	RING_API_REGISTER("qwindow_minimumsize",ring_QWindow_minimumSize);
	RING_API_REGISTER("qwindow_minimumwidth",ring_QWindow_minimumWidth);
	RING_API_REGISTER("qwindow_modality",ring_QWindow_modality);
	RING_API_REGISTER("qwindow_opacity",ring_QWindow_opacity);
	RING_API_REGISTER("qwindow_position",ring_QWindow_position);
	RING_API_REGISTER("qwindow_reportcontentorientationchange",ring_QWindow_reportContentOrientationChange);
	RING_API_REGISTER("qwindow_requestedformat",ring_QWindow_requestedFormat);
	RING_API_REGISTER("qwindow_resize",ring_QWindow_resize);
	RING_API_REGISTER("qwindow_resize_2",ring_QWindow_resize_2);
	RING_API_REGISTER("qwindow_screen",ring_QWindow_screen);
	RING_API_REGISTER("qwindow_setbasesize",ring_QWindow_setBaseSize);
	RING_API_REGISTER("qwindow_setcursor",ring_QWindow_setCursor);
	RING_API_REGISTER("qwindow_setfilepath",ring_QWindow_setFilePath);
	RING_API_REGISTER("qwindow_setflags",ring_QWindow_setFlags);
	RING_API_REGISTER("qwindow_setformat",ring_QWindow_setFormat);
	RING_API_REGISTER("qwindow_setframeposition",ring_QWindow_setFramePosition);
	RING_API_REGISTER("qwindow_setgeometry",ring_QWindow_setGeometry);
	RING_API_REGISTER("qwindow_setgeometry_2",ring_QWindow_setGeometry_2);
	RING_API_REGISTER("qwindow_seticon",ring_QWindow_setIcon);
	RING_API_REGISTER("qwindow_setkeyboardgrabenabled",ring_QWindow_setKeyboardGrabEnabled);
	RING_API_REGISTER("qwindow_setmask",ring_QWindow_setMask);
	RING_API_REGISTER("qwindow_setmaximumsize",ring_QWindow_setMaximumSize);
	RING_API_REGISTER("qwindow_setminimumsize",ring_QWindow_setMinimumSize);
	RING_API_REGISTER("qwindow_setmodality",ring_QWindow_setModality);
	RING_API_REGISTER("qwindow_setmousegrabenabled",ring_QWindow_setMouseGrabEnabled);
	RING_API_REGISTER("qwindow_setopacity",ring_QWindow_setOpacity);
	RING_API_REGISTER("qwindow_setparent",ring_QWindow_setParent);
	RING_API_REGISTER("qwindow_setposition",ring_QWindow_setPosition);
	RING_API_REGISTER("qwindow_setposition_2",ring_QWindow_setPosition_2);
	RING_API_REGISTER("qwindow_setscreen",ring_QWindow_setScreen);
	RING_API_REGISTER("qwindow_setsizeincrement",ring_QWindow_setSizeIncrement);
	RING_API_REGISTER("qwindow_settransientparent",ring_QWindow_setTransientParent);
	RING_API_REGISTER("qwindow_setvisibility",ring_QWindow_setVisibility);
	RING_API_REGISTER("qwindow_setwindowstate",ring_QWindow_setWindowState);
	RING_API_REGISTER("qwindow_sizeincrement",ring_QWindow_sizeIncrement);
	RING_API_REGISTER("qwindow_title",ring_QWindow_title);
	RING_API_REGISTER("qwindow_transientparent",ring_QWindow_transientParent);
	RING_API_REGISTER("qwindow_type",ring_QWindow_type);
	RING_API_REGISTER("qwindow_unsetcursor",ring_QWindow_unsetCursor);
	RING_API_REGISTER("qwindow_visibility",ring_QWindow_visibility);
	RING_API_REGISTER("qwindow_width",ring_QWindow_width);
	RING_API_REGISTER("qwindow_winid",ring_QWindow_winId);
	RING_API_REGISTER("qwindow_windowstate",ring_QWindow_windowState);
	RING_API_REGISTER("qwindow_x",ring_QWindow_x);
	RING_API_REGISTER("qwindow_y",ring_QWindow_y);
	RING_API_REGISTER("qwindow_alert",ring_QWindow_alert);
	RING_API_REGISTER("qwindow_close",ring_QWindow_close);
	RING_API_REGISTER("qwindow_hide",ring_QWindow_hide);
	RING_API_REGISTER("qwindow_lower",ring_QWindow_lower);
	RING_API_REGISTER("qwindow_raise",ring_QWindow_raise);
	RING_API_REGISTER("qwindow_requestactivate",ring_QWindow_requestActivate);
	RING_API_REGISTER("qwindow_setheight",ring_QWindow_setHeight);
	RING_API_REGISTER("qwindow_setmaximumheight",ring_QWindow_setMaximumHeight);
	RING_API_REGISTER("qwindow_setmaximumwidth",ring_QWindow_setMaximumWidth);
	RING_API_REGISTER("qwindow_setminimumheight",ring_QWindow_setMinimumHeight);
	RING_API_REGISTER("qwindow_setminimumwidth",ring_QWindow_setMinimumWidth);
	RING_API_REGISTER("qwindow_settitle",ring_QWindow_setTitle);
	RING_API_REGISTER("qwindow_setvisible",ring_QWindow_setVisible);
	RING_API_REGISTER("qwindow_setwidth",ring_QWindow_setWidth);
	RING_API_REGISTER("qwindow_setx",ring_QWindow_setX);
	RING_API_REGISTER("qwindow_sety",ring_QWindow_setY);
	RING_API_REGISTER("qwindow_show",ring_QWindow_show);
	RING_API_REGISTER("qwindow_showfullscreen",ring_QWindow_showFullScreen);
	RING_API_REGISTER("qwindow_showmaximized",ring_QWindow_showMaximized);
	RING_API_REGISTER("qwindow_showminimized",ring_QWindow_showMinimized);
	RING_API_REGISTER("qwindow_shownormal",ring_QWindow_showNormal);
	RING_API_REGISTER("qwindow_fromwinid",ring_QWindow_fromWinId);
	RING_API_REGISTER("qwindow_setactivechangedevent",ring_QWindow_setactiveChangedEvent);
	RING_API_REGISTER("qwindow_setcontentorientationchangedevent",ring_QWindow_setcontentOrientationChangedEvent);
	RING_API_REGISTER("qwindow_setfocusobjectchangedevent",ring_QWindow_setfocusObjectChangedEvent);
	RING_API_REGISTER("qwindow_setheightchangedevent",ring_QWindow_setheightChangedEvent);
	RING_API_REGISTER("qwindow_setmaximumheightchangedevent",ring_QWindow_setmaximumHeightChangedEvent);
	RING_API_REGISTER("qwindow_setmaximumwidthchangedevent",ring_QWindow_setmaximumWidthChangedEvent);
	RING_API_REGISTER("qwindow_setminimumheightchangedevent",ring_QWindow_setminimumHeightChangedEvent);
	RING_API_REGISTER("qwindow_setminimumwidthchangedevent",ring_QWindow_setminimumWidthChangedEvent);
	RING_API_REGISTER("qwindow_setmodalitychangedevent",ring_QWindow_setmodalityChangedEvent);
	RING_API_REGISTER("qwindow_setopacitychangedevent",ring_QWindow_setopacityChangedEvent);
	RING_API_REGISTER("qwindow_setscreenchangedevent",ring_QWindow_setscreenChangedEvent);
	RING_API_REGISTER("qwindow_setvisibilitychangedevent",ring_QWindow_setvisibilityChangedEvent);
	RING_API_REGISTER("qwindow_setvisiblechangedevent",ring_QWindow_setvisibleChangedEvent);
	RING_API_REGISTER("qwindow_setwidthchangedevent",ring_QWindow_setwidthChangedEvent);
	RING_API_REGISTER("qwindow_setwindowstatechangedevent",ring_QWindow_setwindowStateChangedEvent);
	RING_API_REGISTER("qwindow_setwindowtitlechangedevent",ring_QWindow_setwindowTitleChangedEvent);
	RING_API_REGISTER("qwindow_setxchangedevent",ring_QWindow_setxChangedEvent);
	RING_API_REGISTER("qwindow_setychangedevent",ring_QWindow_setyChangedEvent);
	RING_API_REGISTER("qwindow_getactivechangedevent",ring_QWindow_getactiveChangedEvent);
	RING_API_REGISTER("qwindow_getcontentorientationchangedevent",ring_QWindow_getcontentOrientationChangedEvent);
	RING_API_REGISTER("qwindow_getfocusobjectchangedevent",ring_QWindow_getfocusObjectChangedEvent);
	RING_API_REGISTER("qwindow_getheightchangedevent",ring_QWindow_getheightChangedEvent);
	RING_API_REGISTER("qwindow_getmaximumheightchangedevent",ring_QWindow_getmaximumHeightChangedEvent);
	RING_API_REGISTER("qwindow_getmaximumwidthchangedevent",ring_QWindow_getmaximumWidthChangedEvent);
	RING_API_REGISTER("qwindow_getminimumheightchangedevent",ring_QWindow_getminimumHeightChangedEvent);
	RING_API_REGISTER("qwindow_getminimumwidthchangedevent",ring_QWindow_getminimumWidthChangedEvent);
	RING_API_REGISTER("qwindow_getmodalitychangedevent",ring_QWindow_getmodalityChangedEvent);
	RING_API_REGISTER("qwindow_getopacitychangedevent",ring_QWindow_getopacityChangedEvent);
	RING_API_REGISTER("qwindow_getscreenchangedevent",ring_QWindow_getscreenChangedEvent);
	RING_API_REGISTER("qwindow_getvisibilitychangedevent",ring_QWindow_getvisibilityChangedEvent);
	RING_API_REGISTER("qwindow_getvisiblechangedevent",ring_QWindow_getvisibleChangedEvent);
	RING_API_REGISTER("qwindow_getwidthchangedevent",ring_QWindow_getwidthChangedEvent);
	RING_API_REGISTER("qwindow_getwindowstatechangedevent",ring_QWindow_getwindowStateChangedEvent);
	RING_API_REGISTER("qwindow_getwindowtitlechangedevent",ring_QWindow_getwindowTitleChangedEvent);
	RING_API_REGISTER("qwindow_getxchangedevent",ring_QWindow_getxChangedEvent);
	RING_API_REGISTER("qwindow_getychangedevent",ring_QWindow_getyChangedEvent);
	RING_API_REGISTER("qguiapplication_devicepixelratio",ring_QGuiApplication_devicePixelRatio);
	RING_API_REGISTER("qguiapplication_issavingsession",ring_QGuiApplication_isSavingSession);
	RING_API_REGISTER("qguiapplication_issessionrestored",ring_QGuiApplication_isSessionRestored);
	RING_API_REGISTER("qguiapplication_sessionid",ring_QGuiApplication_sessionId);
	RING_API_REGISTER("qguiapplication_sessionkey",ring_QGuiApplication_sessionKey);
	RING_API_REGISTER("qguiapplication_allwindows",ring_QGuiApplication_allWindows);
	RING_API_REGISTER("qguiapplication_applicationdisplayname",ring_QGuiApplication_applicationDisplayName);
	RING_API_REGISTER("qguiapplication_applicationstate",ring_QGuiApplication_applicationState);
	RING_API_REGISTER("qguiapplication_changeoverridecursor",ring_QGuiApplication_changeOverrideCursor);
	RING_API_REGISTER("qguiapplication_clipboard",ring_QGuiApplication_clipboard);
	RING_API_REGISTER("qguiapplication_desktopsettingsaware",ring_QGuiApplication_desktopSettingsAware);
	RING_API_REGISTER("qguiapplication_exec",ring_QGuiApplication_exec);
	RING_API_REGISTER("qguiapplication_focusobject",ring_QGuiApplication_focusObject);
	RING_API_REGISTER("qguiapplication_focuswindow",ring_QGuiApplication_focusWindow);
	RING_API_REGISTER("qguiapplication_font",ring_QGuiApplication_font);
	RING_API_REGISTER("qguiapplication_inputmethod",ring_QGuiApplication_inputMethod);
	RING_API_REGISTER("qguiapplication_islefttoright",ring_QGuiApplication_isLeftToRight);
	RING_API_REGISTER("qguiapplication_isrighttoleft",ring_QGuiApplication_isRightToLeft);
	RING_API_REGISTER("qguiapplication_keyboardmodifiers",ring_QGuiApplication_keyboardModifiers);
	RING_API_REGISTER("qguiapplication_layoutdirection",ring_QGuiApplication_layoutDirection);
	RING_API_REGISTER("qguiapplication_modalwindow",ring_QGuiApplication_modalWindow);
	RING_API_REGISTER("qguiapplication_mousebuttons",ring_QGuiApplication_mouseButtons);
	RING_API_REGISTER("qguiapplication_overridecursor",ring_QGuiApplication_overrideCursor);
	RING_API_REGISTER("qguiapplication_palette",ring_QGuiApplication_palette);
	RING_API_REGISTER("qguiapplication_platformname",ring_QGuiApplication_platformName);
	RING_API_REGISTER("qguiapplication_platformnativeinterface",ring_QGuiApplication_platformNativeInterface);
	RING_API_REGISTER("qguiapplication_primaryscreen",ring_QGuiApplication_primaryScreen);
	RING_API_REGISTER("qguiapplication_querykeyboardmodifiers",ring_QGuiApplication_queryKeyboardModifiers);
	RING_API_REGISTER("qguiapplication_quitonlastwindowclosed",ring_QGuiApplication_quitOnLastWindowClosed);
	RING_API_REGISTER("qguiapplication_restoreoverridecursor",ring_QGuiApplication_restoreOverrideCursor);
	RING_API_REGISTER("qguiapplication_screens",ring_QGuiApplication_screens);
	RING_API_REGISTER("qguiapplication_setapplicationdisplayname",ring_QGuiApplication_setApplicationDisplayName);
	RING_API_REGISTER("qguiapplication_setdesktopsettingsaware",ring_QGuiApplication_setDesktopSettingsAware);
	RING_API_REGISTER("qguiapplication_setfont",ring_QGuiApplication_setFont);
	RING_API_REGISTER("qguiapplication_setlayoutdirection",ring_QGuiApplication_setLayoutDirection);
	RING_API_REGISTER("qguiapplication_setoverridecursor",ring_QGuiApplication_setOverrideCursor);
	RING_API_REGISTER("qguiapplication_setpalette",ring_QGuiApplication_setPalette);
	RING_API_REGISTER("qguiapplication_setquitonlastwindowclosed",ring_QGuiApplication_setQuitOnLastWindowClosed);
	RING_API_REGISTER("qguiapplication_stylehints",ring_QGuiApplication_styleHints);
	RING_API_REGISTER("qguiapplication_sync",ring_QGuiApplication_sync);
	RING_API_REGISTER("qguiapplication_toplevelat",ring_QGuiApplication_topLevelAt);
	RING_API_REGISTER("qguiapplication_toplevelwindows",ring_QGuiApplication_topLevelWindows);
	RING_API_REGISTER("qguiapplication_setapplicationdisplaynamechangedevent",ring_QGuiApplication_setapplicationDisplayNameChangedEvent);
	RING_API_REGISTER("qguiapplication_setapplicationstatechangedevent",ring_QGuiApplication_setapplicationStateChangedEvent);
	RING_API_REGISTER("qguiapplication_setcommitdatarequestevent",ring_QGuiApplication_setcommitDataRequestEvent);
	RING_API_REGISTER("qguiapplication_setfocusobjectchangedevent",ring_QGuiApplication_setfocusObjectChangedEvent);
	RING_API_REGISTER("qguiapplication_setfocuswindowchangedevent",ring_QGuiApplication_setfocusWindowChangedEvent);
	RING_API_REGISTER("qguiapplication_setfontdatabasechangedevent",ring_QGuiApplication_setfontDatabaseChangedEvent);
	RING_API_REGISTER("qguiapplication_setlastwindowclosedevent",ring_QGuiApplication_setlastWindowClosedEvent);
	RING_API_REGISTER("qguiapplication_setlayoutdirectionchangedevent",ring_QGuiApplication_setlayoutDirectionChangedEvent);
	RING_API_REGISTER("qguiapplication_setpalettechangedevent",ring_QGuiApplication_setpaletteChangedEvent);
	RING_API_REGISTER("qguiapplication_setprimaryscreenchangedevent",ring_QGuiApplication_setprimaryScreenChangedEvent);
	RING_API_REGISTER("qguiapplication_setsavestaterequestevent",ring_QGuiApplication_setsaveStateRequestEvent);
	RING_API_REGISTER("qguiapplication_setscreenaddedevent",ring_QGuiApplication_setscreenAddedEvent);
	RING_API_REGISTER("qguiapplication_setscreenremovedevent",ring_QGuiApplication_setscreenRemovedEvent);
	RING_API_REGISTER("qguiapplication_getapplicationdisplaynamechangedevent",ring_QGuiApplication_getapplicationDisplayNameChangedEvent);
	RING_API_REGISTER("qguiapplication_getapplicationstatechangedevent",ring_QGuiApplication_getapplicationStateChangedEvent);
	RING_API_REGISTER("qguiapplication_getcommitdatarequestevent",ring_QGuiApplication_getcommitDataRequestEvent);
	RING_API_REGISTER("qguiapplication_getfocusobjectchangedevent",ring_QGuiApplication_getfocusObjectChangedEvent);
	RING_API_REGISTER("qguiapplication_getfocuswindowchangedevent",ring_QGuiApplication_getfocusWindowChangedEvent);
	RING_API_REGISTER("qguiapplication_getfontdatabasechangedevent",ring_QGuiApplication_getfontDatabaseChangedEvent);
	RING_API_REGISTER("qguiapplication_getlastwindowclosedevent",ring_QGuiApplication_getlastWindowClosedEvent);
	RING_API_REGISTER("qguiapplication_getlayoutdirectionchangedevent",ring_QGuiApplication_getlayoutDirectionChangedEvent);
	RING_API_REGISTER("qguiapplication_getpalettechangedevent",ring_QGuiApplication_getpaletteChangedEvent);
	RING_API_REGISTER("qguiapplication_getprimaryscreenchangedevent",ring_QGuiApplication_getprimaryScreenChangedEvent);
	RING_API_REGISTER("qguiapplication_getsavestaterequestevent",ring_QGuiApplication_getsaveStateRequestEvent);
	RING_API_REGISTER("qguiapplication_getscreenaddedevent",ring_QGuiApplication_getscreenAddedEvent);
	RING_API_REGISTER("qguiapplication_getscreenremovedevent",ring_QGuiApplication_getscreenRemovedEvent);
	RING_API_REGISTER("qclipboard_clear",ring_QClipboard_clear);
	RING_API_REGISTER("qclipboard_image",ring_QClipboard_image);
	RING_API_REGISTER("qclipboard_mimedata",ring_QClipboard_mimeData);
	RING_API_REGISTER("qclipboard_ownsclipboard",ring_QClipboard_ownsClipboard);
	RING_API_REGISTER("qclipboard_ownsfindbuffer",ring_QClipboard_ownsFindBuffer);
	RING_API_REGISTER("qclipboard_ownsselection",ring_QClipboard_ownsSelection);
	RING_API_REGISTER("qclipboard_pixmap",ring_QClipboard_pixmap);
	RING_API_REGISTER("qclipboard_setimage",ring_QClipboard_setImage);
	RING_API_REGISTER("qclipboard_setmimedata",ring_QClipboard_setMimeData);
	RING_API_REGISTER("qclipboard_setpixmap",ring_QClipboard_setPixmap);
	RING_API_REGISTER("qclipboard_settext",ring_QClipboard_setText);
	RING_API_REGISTER("qclipboard_supportsfindbuffer",ring_QClipboard_supportsFindBuffer);
	RING_API_REGISTER("qclipboard_supportsselection",ring_QClipboard_supportsSelection);
	RING_API_REGISTER("qclipboard_text",ring_QClipboard_text);
	RING_API_REGISTER("qfontdatabase_bold",ring_QFontDatabase_bold);
	RING_API_REGISTER("qfontdatabase_families",ring_QFontDatabase_families);
	RING_API_REGISTER("qfontdatabase_font",ring_QFontDatabase_font);
	RING_API_REGISTER("qfontdatabase_isbitmapscalable",ring_QFontDatabase_isBitmapScalable);
	RING_API_REGISTER("qfontdatabase_isfixedpitch",ring_QFontDatabase_isFixedPitch);
	RING_API_REGISTER("qfontdatabase_isprivatefamily",ring_QFontDatabase_isPrivateFamily);
	RING_API_REGISTER("qfontdatabase_isscalable",ring_QFontDatabase_isScalable);
	RING_API_REGISTER("qfontdatabase_issmoothlyscalable",ring_QFontDatabase_isSmoothlyScalable);
	RING_API_REGISTER("qfontdatabase_italic",ring_QFontDatabase_italic);
	RING_API_REGISTER("qfontdatabase_pointsizes",ring_QFontDatabase_pointSizes);
	RING_API_REGISTER("qfontdatabase_smoothsizes",ring_QFontDatabase_smoothSizes);
	RING_API_REGISTER("qfontdatabase_stylestring",ring_QFontDatabase_styleString);
	RING_API_REGISTER("qfontdatabase_stylestring_2",ring_QFontDatabase_styleString_2);
	RING_API_REGISTER("qfontdatabase_styles",ring_QFontDatabase_styles);
	RING_API_REGISTER("qfontdatabase_weight",ring_QFontDatabase_weight);
	RING_API_REGISTER("qfontdatabase_writingsystems",ring_QFontDatabase_writingSystems);
	RING_API_REGISTER("qfontdatabase_writingsystems_2",ring_QFontDatabase_writingSystems_2);
	RING_API_REGISTER("qfontdatabase_addapplicationfont",ring_QFontDatabase_addApplicationFont);
	RING_API_REGISTER("qfontdatabase_addapplicationfontfromdata",ring_QFontDatabase_addApplicationFontFromData);
	RING_API_REGISTER("qfontdatabase_applicationfontfamilies",ring_QFontDatabase_applicationFontFamilies);
	RING_API_REGISTER("qfontdatabase_removeallapplicationfonts",ring_QFontDatabase_removeAllApplicationFonts);
	RING_API_REGISTER("qfontdatabase_removeapplicationfont",ring_QFontDatabase_removeApplicationFont);
	RING_API_REGISTER("qfontdatabase_standardsizes",ring_QFontDatabase_standardSizes);
	RING_API_REGISTER("qfontdatabase_systemfont",ring_QFontDatabase_systemFont);
	RING_API_REGISTER("qfontdatabase_writingsystemname",ring_QFontDatabase_writingSystemName);
	RING_API_REGISTER("qfontdatabase_writingsystemsample",ring_QFontDatabase_writingSystemSample);
	RING_API_REGISTER("qapp_exec",ring_QApp_exec);
	RING_API_REGISTER("qapp_quit",ring_QApp_quit);
	RING_API_REGISTER("qapp_processevents",ring_QApp_processEvents);
	RING_API_REGISTER("qapp_stylewindows",ring_QApp_styleWindows);
	RING_API_REGISTER("qapp_stylewindowsvista",ring_QApp_styleWindowsVista);
	RING_API_REGISTER("qapp_stylefusion",ring_QApp_styleFusion);
	RING_API_REGISTER("qapp_stylefusionblack",ring_QApp_styleFusionBlack);
	RING_API_REGISTER("qapp_stylefusioncustom",ring_QApp_styleFusionCustom);
	RING_API_REGISTER("qapp_closeallwindows",ring_QApp_closeAllWindows);
	RING_API_REGISTER("qapp_keyboardmodifiers",ring_QApp_keyboardModifiers);
	RING_API_REGISTER("qapp_clipboard",ring_QApp_clipboard);
	RING_API_REGISTER("qapp_style",ring_QApp_style);
	RING_API_REGISTER("qapp_aboutqt",ring_QApp_aboutQt);
	RING_API_REGISTER("qapp_activemodalwidget",ring_QApp_activeModalWidget);
	RING_API_REGISTER("qapp_activepopupwidget",ring_QApp_activePopupWidget);
	RING_API_REGISTER("qapp_activewindow",ring_QApp_activeWindow);
	RING_API_REGISTER("qapp_focuswidget",ring_QApp_focusWidget);
	RING_API_REGISTER("qapp_titlebarheight",ring_QApp_titlebarHeight);
	RING_API_REGISTER("qallevents_accept",ring_QAllEvents_accept);
	RING_API_REGISTER("qallevents_ignore",ring_QAllEvents_ignore);
	RING_API_REGISTER("qallevents_getkeycode",ring_QAllEvents_getKeyCode);
	RING_API_REGISTER("qallevents_getkeytext",ring_QAllEvents_getKeyText);
	RING_API_REGISTER("qallevents_getmodifiers",ring_QAllEvents_getModifiers);
	RING_API_REGISTER("qallevents_getx",ring_QAllEvents_getx);
	RING_API_REGISTER("qallevents_gety",ring_QAllEvents_gety);
	RING_API_REGISTER("qallevents_getglobalx",ring_QAllEvents_getglobalx);
	RING_API_REGISTER("qallevents_getglobaly",ring_QAllEvents_getglobaly);
	RING_API_REGISTER("qallevents_getbutton",ring_QAllEvents_getbutton);
	RING_API_REGISTER("qallevents_getbuttons",ring_QAllEvents_getbuttons);
	RING_API_REGISTER("qallevents_setkeypressevent",ring_QAllEvents_setKeyPressEvent);
	RING_API_REGISTER("qallevents_setmousebuttonpressevent",ring_QAllEvents_setMouseButtonPressEvent);
	RING_API_REGISTER("qallevents_setmousebuttonreleaseevent",ring_QAllEvents_setMouseButtonReleaseEvent);
	RING_API_REGISTER("qallevents_setmousebuttondblclickevent",ring_QAllEvents_setMouseButtonDblClickEvent);
	RING_API_REGISTER("qallevents_setmousemoveevent",ring_QAllEvents_setMouseMoveEvent);
	RING_API_REGISTER("qallevents_setcloseevent",ring_QAllEvents_setCloseEvent);
	RING_API_REGISTER("qallevents_setcontextmenuevent",ring_QAllEvents_setContextMenuEvent);
	RING_API_REGISTER("qallevents_setdragenterevent",ring_QAllEvents_setDragEnterEvent);
	RING_API_REGISTER("qallevents_setdragleaveevent",ring_QAllEvents_setDragLeaveEvent);
	RING_API_REGISTER("qallevents_setdragmoveevent",ring_QAllEvents_setDragMoveEvent);
	RING_API_REGISTER("qallevents_setdropevent",ring_QAllEvents_setDropEvent);
	RING_API_REGISTER("qallevents_setenterevent",ring_QAllEvents_setEnterEvent);
	RING_API_REGISTER("qallevents_setfocusinevent",ring_QAllEvents_setFocusInEvent);
	RING_API_REGISTER("qallevents_setfocusoutevent",ring_QAllEvents_setFocusOutEvent);
	RING_API_REGISTER("qallevents_setkeyreleaseevent",ring_QAllEvents_setKeyReleaseEvent);
	RING_API_REGISTER("qallevents_setleaveevent",ring_QAllEvents_setLeaveEvent);
	RING_API_REGISTER("qallevents_setnonclientareamousebuttondblclickevent",ring_QAllEvents_setNonClientAreaMouseButtonDblClickEvent);
	RING_API_REGISTER("qallevents_setnonclientareamousebuttonpressevent",ring_QAllEvents_setNonClientAreaMouseButtonPressEvent);
	RING_API_REGISTER("qallevents_setnonclientareamousebuttonreleaseevent",ring_QAllEvents_setNonClientAreaMouseButtonReleaseEvent);
	RING_API_REGISTER("qallevents_setnonclientareamousemoveevent",ring_QAllEvents_setNonClientAreaMouseMoveEvent);
	RING_API_REGISTER("qallevents_setmoveevent",ring_QAllEvents_setMoveEvent);
	RING_API_REGISTER("qallevents_setresizeevent",ring_QAllEvents_setResizeEvent);
	RING_API_REGISTER("qallevents_setwindowactivateevent",ring_QAllEvents_setWindowActivateEvent);
	RING_API_REGISTER("qallevents_setwindowblockedevent",ring_QAllEvents_setWindowBlockedEvent);
	RING_API_REGISTER("qallevents_setwindowdeactivateevent",ring_QAllEvents_setWindowDeactivateEvent);
	RING_API_REGISTER("qallevents_setwindowstatechangeevent",ring_QAllEvents_setWindowStateChangeEvent);
	RING_API_REGISTER("qallevents_setwindowunblockedevent",ring_QAllEvents_setWindowUnblockedEvent);
	RING_API_REGISTER("qallevents_setpaintevent",ring_QAllEvents_setPaintEvent);
	RING_API_REGISTER("qallevents_setchildaddedevent",ring_QAllEvents_setChildAddedEvent);
	RING_API_REGISTER("qallevents_setchildpolishedevent",ring_QAllEvents_setChildPolishedEvent);
	RING_API_REGISTER("qallevents_setchildremovedevent",ring_QAllEvents_setChildRemovedEvent);
	RING_API_REGISTER("qallevents_getkeypressevent",ring_QAllEvents_getKeyPressEvent);
	RING_API_REGISTER("qallevents_getmousebuttonpressevent",ring_QAllEvents_getMouseButtonPressEvent);
	RING_API_REGISTER("qallevents_getmousebuttonreleaseevent",ring_QAllEvents_getMouseButtonReleaseEvent);
	RING_API_REGISTER("qallevents_getmousebuttondblclickevent",ring_QAllEvents_getMouseButtonDblClickEvent);
	RING_API_REGISTER("qallevents_getmousemoveevent",ring_QAllEvents_getMouseMoveEvent);
	RING_API_REGISTER("qallevents_getcloseevent",ring_QAllEvents_getCloseEvent);
	RING_API_REGISTER("qallevents_getcontextmenuevent",ring_QAllEvents_getContextMenuEvent);
	RING_API_REGISTER("qallevents_getdragenterevent",ring_QAllEvents_getDragEnterEvent);
	RING_API_REGISTER("qallevents_getdragleaveevent",ring_QAllEvents_getDragLeaveEvent);
	RING_API_REGISTER("qallevents_getdragmoveevent",ring_QAllEvents_getDragMoveEvent);
	RING_API_REGISTER("qallevents_getdropevent",ring_QAllEvents_getDropEvent);
	RING_API_REGISTER("qallevents_getenterevent",ring_QAllEvents_getEnterEvent);
	RING_API_REGISTER("qallevents_getfocusinevent",ring_QAllEvents_getFocusInEvent);
	RING_API_REGISTER("qallevents_getfocusoutevent",ring_QAllEvents_getFocusOutEvent);
	RING_API_REGISTER("qallevents_getkeyreleaseevent",ring_QAllEvents_getKeyReleaseEvent);
	RING_API_REGISTER("qallevents_getleaveevent",ring_QAllEvents_getLeaveEvent);
	RING_API_REGISTER("qallevents_getnonclientareamousebuttondblclickevent",ring_QAllEvents_getNonClientAreaMouseButtonDblClickEvent);
	RING_API_REGISTER("qallevents_getnonclientareamousebuttonpressevent",ring_QAllEvents_getNonClientAreaMouseButtonPressEvent);
	RING_API_REGISTER("qallevents_getnonclientareamousebuttonreleaseevent",ring_QAllEvents_getNonClientAreaMouseButtonReleaseEvent);
	RING_API_REGISTER("qallevents_getnonclientareamousemoveevent",ring_QAllEvents_getNonClientAreaMouseMoveEvent);
	RING_API_REGISTER("qallevents_getmoveevent",ring_QAllEvents_getMoveEvent);
	RING_API_REGISTER("qallevents_getresizeevent",ring_QAllEvents_getResizeEvent);
	RING_API_REGISTER("qallevents_getwindowactivateevent",ring_QAllEvents_getWindowActivateEvent);
	RING_API_REGISTER("qallevents_getwindowblockedevent",ring_QAllEvents_getWindowBlockedEvent);
	RING_API_REGISTER("qallevents_getwindowdeactivateevent",ring_QAllEvents_getWindowDeactivateEvent);
	RING_API_REGISTER("qallevents_getwindowstatechangeevent",ring_QAllEvents_getWindowStateChangeEvent);
	RING_API_REGISTER("qallevents_getwindowunblockedevent",ring_QAllEvents_getWindowUnblockedEvent);
	RING_API_REGISTER("qallevents_getpaintevent",ring_QAllEvents_getPaintEvent);
	RING_API_REGISTER("qallevents_getchildaddedevent",ring_QAllEvents_getChildAddedEvent);
	RING_API_REGISTER("qallevents_getchildpolishedevent",ring_QAllEvents_getChildPolishedEvent);
	RING_API_REGISTER("qallevents_getchildremovedevent",ring_QAllEvents_getChildRemovedEvent);
	RING_API_REGISTER("qallevents_seteventoutput",ring_QAllEvents_setEventOutput);
	RING_API_REGISTER("qallevents_getparentobject",ring_QAllEvents_getParentObject);
	RING_API_REGISTER("qallevents_getparentwidget",ring_QAllEvents_getParentWidget);
	RING_API_REGISTER("qallevents_setkeypressfunc",ring_QAllEvents_setKeyPressFunc);
	RING_API_REGISTER("qallevents_setmousebuttonpressfunc",ring_QAllEvents_setMouseButtonPressFunc);
	RING_API_REGISTER("qallevents_setmousebuttonreleasefunc",ring_QAllEvents_setMouseButtonReleaseFunc);
	RING_API_REGISTER("qallevents_setmousebuttondblclickfunc",ring_QAllEvents_setMouseButtonDblClickFunc);
	RING_API_REGISTER("qallevents_setmousemovefunc",ring_QAllEvents_setMouseMoveFunc);
	RING_API_REGISTER("qallevents_setclosefunc",ring_QAllEvents_setCloseFunc);
	RING_API_REGISTER("qallevents_setcontextmenufunc",ring_QAllEvents_setContextMenuFunc);
	RING_API_REGISTER("qallevents_setdragenterfunc",ring_QAllEvents_setDragEnterFunc);
	RING_API_REGISTER("qallevents_setdragleavefunc",ring_QAllEvents_setDragLeaveFunc);
	RING_API_REGISTER("qallevents_setdragmovefunc",ring_QAllEvents_setDragMoveFunc);
	RING_API_REGISTER("qallevents_setdropfunc",ring_QAllEvents_setDropFunc);
	RING_API_REGISTER("qallevents_setenterfunc",ring_QAllEvents_setEnterFunc);
	RING_API_REGISTER("qallevents_setfocusinfunc",ring_QAllEvents_setFocusInFunc);
	RING_API_REGISTER("qallevents_setfocusoutfunc",ring_QAllEvents_setFocusOutFunc);
	RING_API_REGISTER("qallevents_setkeyreleasefunc",ring_QAllEvents_setKeyReleaseFunc);
	RING_API_REGISTER("qallevents_setleavefunc",ring_QAllEvents_setLeaveFunc);
	RING_API_REGISTER("qallevents_setnonclientareamousebuttondblclickfunc",ring_QAllEvents_setNonClientAreaMouseButtonDblClickFunc);
	RING_API_REGISTER("qallevents_setnonclientareamousebuttonpressfunc",ring_QAllEvents_setNonClientAreaMouseButtonPressFunc);
	RING_API_REGISTER("qallevents_setnonclientareamousebuttonreleasefunc",ring_QAllEvents_setNonClientAreaMouseButtonReleaseFunc);
	RING_API_REGISTER("qallevents_setnonclientareamousemovefunc",ring_QAllEvents_setNonClientAreaMouseMoveFunc);
	RING_API_REGISTER("qallevents_setmovefunc",ring_QAllEvents_setMoveFunc);
	RING_API_REGISTER("qallevents_setresizefunc",ring_QAllEvents_setResizeFunc);
	RING_API_REGISTER("qallevents_setwindowactivatefunc",ring_QAllEvents_setWindowActivateFunc);
	RING_API_REGISTER("qallevents_setwindowblockedfunc",ring_QAllEvents_setWindowBlockedFunc);
	RING_API_REGISTER("qallevents_setwindowdeactivatefunc",ring_QAllEvents_setWindowDeactivateFunc);
	RING_API_REGISTER("qallevents_setwindowstatechangefunc",ring_QAllEvents_setWindowStateChangeFunc);
	RING_API_REGISTER("qallevents_setwindowunblockedfunc",ring_QAllEvents_setWindowUnblockedFunc);
	RING_API_REGISTER("qallevents_setpaintfunc",ring_QAllEvents_setPaintFunc);
	RING_API_REGISTER("qallevents_setchildaddedfunc",ring_QAllEvents_setChildAddedFunc);
	RING_API_REGISTER("qallevents_setchildpolishedfunc",ring_QAllEvents_setChildPolishedFunc);
	RING_API_REGISTER("qallevents_setchildremovedfunc",ring_QAllEvents_setChildRemovedFunc);
	RING_API_REGISTER("qallevents_getkeypressfunc",ring_QAllEvents_getKeyPressFunc);
	RING_API_REGISTER("qallevents_getmousebuttonpressfunc",ring_QAllEvents_getMouseButtonPressFunc);
	RING_API_REGISTER("qallevents_getmousebuttonreleasefunc",ring_QAllEvents_getMouseButtonReleaseFunc);
	RING_API_REGISTER("qallevents_getmousebuttondblclickfunc",ring_QAllEvents_getMouseButtonDblClickFunc);
	RING_API_REGISTER("qallevents_getmousemovefunc",ring_QAllEvents_getMouseMoveFunc);
	RING_API_REGISTER("qallevents_getclosefunc",ring_QAllEvents_getCloseFunc);
	RING_API_REGISTER("qallevents_getcontextmenufunc",ring_QAllEvents_getContextMenuFunc);
	RING_API_REGISTER("qallevents_getdragenterfunc",ring_QAllEvents_getDragEnterFunc);
	RING_API_REGISTER("qallevents_getdragleavefunc",ring_QAllEvents_getDragLeaveFunc);
	RING_API_REGISTER("qallevents_getdragmovefunc",ring_QAllEvents_getDragMoveFunc);
	RING_API_REGISTER("qallevents_getdropfunc",ring_QAllEvents_getDropFunc);
	RING_API_REGISTER("qallevents_getenterfunc",ring_QAllEvents_getEnterFunc);
	RING_API_REGISTER("qallevents_getfocusinfunc",ring_QAllEvents_getFocusInFunc);
	RING_API_REGISTER("qallevents_getfocusoutfunc",ring_QAllEvents_getFocusOutFunc);
	RING_API_REGISTER("qallevents_getkeyreleasefunc",ring_QAllEvents_getKeyReleaseFunc);
	RING_API_REGISTER("qallevents_getleavefunc",ring_QAllEvents_getLeaveFunc);
	RING_API_REGISTER("qallevents_getnonclientareamousebuttondblclickfunc",ring_QAllEvents_getNonClientAreaMouseButtonDblClickFunc);
	RING_API_REGISTER("qallevents_getnonclientareamousebuttonpressfunc",ring_QAllEvents_getNonClientAreaMouseButtonPressFunc);
	RING_API_REGISTER("qallevents_getnonclientareamousebuttonreleasefunc",ring_QAllEvents_getNonClientAreaMouseButtonReleaseFunc);
	RING_API_REGISTER("qallevents_getnonclientareamousemovefunc",ring_QAllEvents_getNonClientAreaMouseMoveFunc);
	RING_API_REGISTER("qallevents_getmovefunc",ring_QAllEvents_getMoveFunc);
	RING_API_REGISTER("qallevents_getresizefunc",ring_QAllEvents_getResizeFunc);
	RING_API_REGISTER("qallevents_getwindowactivatefunc",ring_QAllEvents_getWindowActivateFunc);
	RING_API_REGISTER("qallevents_getwindowblockedfunc",ring_QAllEvents_getWindowBlockedFunc);
	RING_API_REGISTER("qallevents_getwindowdeactivatefunc",ring_QAllEvents_getWindowDeactivateFunc);
	RING_API_REGISTER("qallevents_getwindowstatechangefunc",ring_QAllEvents_getWindowStateChangeFunc);
	RING_API_REGISTER("qallevents_getwindowunblockedfunc",ring_QAllEvents_getWindowUnblockedFunc);
	RING_API_REGISTER("qallevents_getpaintfunc",ring_QAllEvents_getPaintFunc);
	RING_API_REGISTER("qallevents_getchildaddedfunc",ring_QAllEvents_getChildAddedFunc);
	RING_API_REGISTER("qallevents_getchildpolishedfunc",ring_QAllEvents_getChildPolishedFunc);
	RING_API_REGISTER("qallevents_getchildremovedfunc",ring_QAllEvents_getChildRemovedFunc);
	RING_API_REGISTER("qallevents_getdropeventobject",ring_QAllEvents_getDropEventObject);
	RING_API_REGISTER("qallevents_getdragmoveeventobject",ring_QAllEvents_getDragMoveEventObject);
	RING_API_REGISTER("qallevents_getdragentereventobject",ring_QAllEvents_getDragEnterEventObject);
	RING_API_REGISTER("qallevents_getdragleaveeventobject",ring_QAllEvents_getDragLeaveEventObject);
	RING_API_REGISTER("qallevents_getchildeventobject",ring_QAllEvents_getChildEventObject);
	RING_API_REGISTER("qabstractsocket_abort",ring_QAbstractSocket_abort);
	RING_API_REGISTER("qabstractsocket_bind",ring_QAbstractSocket_bind);
	RING_API_REGISTER("qabstractsocket_connecttohost",ring_QAbstractSocket_connectToHost);
	RING_API_REGISTER("qabstractsocket_disconnectfromhost",ring_QAbstractSocket_disconnectFromHost);
	RING_API_REGISTER("qabstractsocket_error",ring_QAbstractSocket_error);
	RING_API_REGISTER("qabstractsocket_flush",ring_QAbstractSocket_flush);
	RING_API_REGISTER("qabstractsocket_isvalid",ring_QAbstractSocket_isValid);
	RING_API_REGISTER("qabstractsocket_localaddress",ring_QAbstractSocket_localAddress);
	RING_API_REGISTER("qabstractsocket_localport",ring_QAbstractSocket_localPort);
	RING_API_REGISTER("qabstractsocket_pausemode",ring_QAbstractSocket_pauseMode);
	RING_API_REGISTER("qabstractsocket_peeraddress",ring_QAbstractSocket_peerAddress);
	RING_API_REGISTER("qabstractsocket_peername",ring_QAbstractSocket_peerName);
	RING_API_REGISTER("qabstractsocket_peerport",ring_QAbstractSocket_peerPort);
	RING_API_REGISTER("qabstractsocket_proxy",ring_QAbstractSocket_proxy);
	RING_API_REGISTER("qabstractsocket_readbuffersize",ring_QAbstractSocket_readBufferSize);
	RING_API_REGISTER("qabstractsocket_resume",ring_QAbstractSocket_resume);
	RING_API_REGISTER("qabstractsocket_setpausemode",ring_QAbstractSocket_setPauseMode);
	RING_API_REGISTER("qabstractsocket_setproxy",ring_QAbstractSocket_setProxy);
	RING_API_REGISTER("qabstractsocket_setreadbuffersize",ring_QAbstractSocket_setReadBufferSize);
	RING_API_REGISTER("qabstractsocket_setsocketdescriptor",ring_QAbstractSocket_setSocketDescriptor);
	RING_API_REGISTER("qabstractsocket_setsocketoption",ring_QAbstractSocket_setSocketOption);
	RING_API_REGISTER("qabstractsocket_socketdescriptor",ring_QAbstractSocket_socketDescriptor);
	RING_API_REGISTER("qabstractsocket_socketoption",ring_QAbstractSocket_socketOption);
	RING_API_REGISTER("qabstractsocket_sockettype",ring_QAbstractSocket_socketType);
	RING_API_REGISTER("qabstractsocket_state",ring_QAbstractSocket_state);
	RING_API_REGISTER("qabstractsocket_waitforconnected",ring_QAbstractSocket_waitForConnected);
	RING_API_REGISTER("qabstractsocket_waitfordisconnected",ring_QAbstractSocket_waitForDisconnected);
	RING_API_REGISTER("qabstractsocket_atend",ring_QAbstractSocket_atEnd);
	RING_API_REGISTER("qabstractsocket_bytesavailable",ring_QAbstractSocket_bytesAvailable);
	RING_API_REGISTER("qabstractsocket_bytestowrite",ring_QAbstractSocket_bytesToWrite);
	RING_API_REGISTER("qabstractsocket_canreadline",ring_QAbstractSocket_canReadLine);
	RING_API_REGISTER("qabstractsocket_close",ring_QAbstractSocket_close);
	RING_API_REGISTER("qabstractsocket_issequential",ring_QAbstractSocket_isSequential);
	RING_API_REGISTER("qabstractsocket_waitforbyteswritten",ring_QAbstractSocket_waitForBytesWritten);
	RING_API_REGISTER("qabstractsocket_waitforreadyread",ring_QAbstractSocket_waitForReadyRead);
	RING_API_REGISTER("qabstractsocket_setconnectedevent",ring_QAbstractSocket_setconnectedEvent);
	RING_API_REGISTER("qabstractsocket_setdisconnectedevent",ring_QAbstractSocket_setdisconnectedEvent);
	RING_API_REGISTER("qabstractsocket_seterrorevent",ring_QAbstractSocket_seterrorEvent);
	RING_API_REGISTER("qabstractsocket_sethostfoundevent",ring_QAbstractSocket_sethostFoundEvent);
	RING_API_REGISTER("qabstractsocket_setproxyauthenticationrequiredevent",ring_QAbstractSocket_setproxyAuthenticationRequiredEvent);
	RING_API_REGISTER("qabstractsocket_setstatechangedevent",ring_QAbstractSocket_setstateChangedEvent);
	RING_API_REGISTER("qabstractsocket_getconnectedevent",ring_QAbstractSocket_getconnectedEvent);
	RING_API_REGISTER("qabstractsocket_getdisconnectedevent",ring_QAbstractSocket_getdisconnectedEvent);
	RING_API_REGISTER("qabstractsocket_geterrorevent",ring_QAbstractSocket_geterrorEvent);
	RING_API_REGISTER("qabstractsocket_gethostfoundevent",ring_QAbstractSocket_gethostFoundEvent);
	RING_API_REGISTER("qabstractsocket_getproxyauthenticationrequiredevent",ring_QAbstractSocket_getproxyAuthenticationRequiredEvent);
	RING_API_REGISTER("qabstractsocket_getstatechangedevent",ring_QAbstractSocket_getstateChangedEvent);
	RING_API_REGISTER("qnetworkproxy_capabilities",ring_QNetworkProxy_capabilities);
	RING_API_REGISTER("qnetworkproxy_hasrawheader",ring_QNetworkProxy_hasRawHeader);
	RING_API_REGISTER("qnetworkproxy_header",ring_QNetworkProxy_header);
	RING_API_REGISTER("qnetworkproxy_hostname",ring_QNetworkProxy_hostName);
	RING_API_REGISTER("qnetworkproxy_iscachingproxy",ring_QNetworkProxy_isCachingProxy);
	RING_API_REGISTER("qnetworkproxy_istransparentproxy",ring_QNetworkProxy_isTransparentProxy);
	RING_API_REGISTER("qnetworkproxy_password",ring_QNetworkProxy_password);
	RING_API_REGISTER("qnetworkproxy_port",ring_QNetworkProxy_port);
	RING_API_REGISTER("qnetworkproxy_rawheader",ring_QNetworkProxy_rawHeader);
	RING_API_REGISTER("qnetworkproxy_setcapabilities",ring_QNetworkProxy_setCapabilities);
	RING_API_REGISTER("qnetworkproxy_setheader",ring_QNetworkProxy_setHeader);
	RING_API_REGISTER("qnetworkproxy_sethostname",ring_QNetworkProxy_setHostName);
	RING_API_REGISTER("qnetworkproxy_setpassword",ring_QNetworkProxy_setPassword);
	RING_API_REGISTER("qnetworkproxy_setport",ring_QNetworkProxy_setPort);
	RING_API_REGISTER("qnetworkproxy_setrawheader",ring_QNetworkProxy_setRawHeader);
	RING_API_REGISTER("qnetworkproxy_settype",ring_QNetworkProxy_setType);
	RING_API_REGISTER("qnetworkproxy_setuser",ring_QNetworkProxy_setUser);
	RING_API_REGISTER("qnetworkproxy_swap",ring_QNetworkProxy_swap);
	RING_API_REGISTER("qnetworkproxy_type",ring_QNetworkProxy_type);
	RING_API_REGISTER("qnetworkproxy_user",ring_QNetworkProxy_user);
	RING_API_REGISTER("qnetworkproxy_applicationproxy",ring_QNetworkProxy_applicationProxy);
	RING_API_REGISTER("qnetworkproxy_setapplicationproxy",ring_QNetworkProxy_setApplicationProxy);
	RING_API_REGISTER("qtcpsocket_setconnectedevent",ring_QTcpSocket_setconnectedEvent);
	RING_API_REGISTER("qtcpsocket_setdisconnectedevent",ring_QTcpSocket_setdisconnectedEvent);
	RING_API_REGISTER("qtcpsocket_seterrorevent",ring_QTcpSocket_seterrorEvent);
	RING_API_REGISTER("qtcpsocket_sethostfoundevent",ring_QTcpSocket_sethostFoundEvent);
	RING_API_REGISTER("qtcpsocket_setproxyauthenticationrequiredevent",ring_QTcpSocket_setproxyAuthenticationRequiredEvent);
	RING_API_REGISTER("qtcpsocket_setstatechangedevent",ring_QTcpSocket_setstateChangedEvent);
	RING_API_REGISTER("qtcpsocket_setabouttocloseevent",ring_QTcpSocket_setaboutToCloseEvent);
	RING_API_REGISTER("qtcpsocket_setbyteswrittenevent",ring_QTcpSocket_setbytesWrittenEvent);
	RING_API_REGISTER("qtcpsocket_setreadchannelfinishedevent",ring_QTcpSocket_setreadChannelFinishedEvent);
	RING_API_REGISTER("qtcpsocket_setreadyreadevent",ring_QTcpSocket_setreadyReadEvent);
	RING_API_REGISTER("qtcpsocket_getconnectedevent",ring_QTcpSocket_getconnectedEvent);
	RING_API_REGISTER("qtcpsocket_getdisconnectedevent",ring_QTcpSocket_getdisconnectedEvent);
	RING_API_REGISTER("qtcpsocket_geterrorevent",ring_QTcpSocket_geterrorEvent);
	RING_API_REGISTER("qtcpsocket_gethostfoundevent",ring_QTcpSocket_gethostFoundEvent);
	RING_API_REGISTER("qtcpsocket_getproxyauthenticationrequiredevent",ring_QTcpSocket_getproxyAuthenticationRequiredEvent);
	RING_API_REGISTER("qtcpsocket_getstatechangedevent",ring_QTcpSocket_getstateChangedEvent);
	RING_API_REGISTER("qtcpsocket_getabouttocloseevent",ring_QTcpSocket_getaboutToCloseEvent);
	RING_API_REGISTER("qtcpsocket_getbyteswrittenevent",ring_QTcpSocket_getbytesWrittenEvent);
	RING_API_REGISTER("qtcpsocket_getreadchannelfinishedevent",ring_QTcpSocket_getreadChannelFinishedEvent);
	RING_API_REGISTER("qtcpsocket_getreadyreadevent",ring_QTcpSocket_getreadyReadEvent);
	RING_API_REGISTER("qtcpserver_close",ring_QTcpServer_close);
	RING_API_REGISTER("qtcpserver_errorstring",ring_QTcpServer_errorString);
	RING_API_REGISTER("qtcpserver_haspendingconnections",ring_QTcpServer_hasPendingConnections);
	RING_API_REGISTER("qtcpserver_islistening",ring_QTcpServer_isListening);
	RING_API_REGISTER("qtcpserver_listen",ring_QTcpServer_listen);
	RING_API_REGISTER("qtcpserver_maxpendingconnections",ring_QTcpServer_maxPendingConnections);
	RING_API_REGISTER("qtcpserver_nextpendingconnection",ring_QTcpServer_nextPendingConnection);
	RING_API_REGISTER("qtcpserver_pauseaccepting",ring_QTcpServer_pauseAccepting);
	RING_API_REGISTER("qtcpserver_proxy",ring_QTcpServer_proxy);
	RING_API_REGISTER("qtcpserver_resumeaccepting",ring_QTcpServer_resumeAccepting);
	RING_API_REGISTER("qtcpserver_serveraddress",ring_QTcpServer_serverAddress);
	RING_API_REGISTER("qtcpserver_servererror",ring_QTcpServer_serverError);
	RING_API_REGISTER("qtcpserver_serverport",ring_QTcpServer_serverPort);
	RING_API_REGISTER("qtcpserver_setmaxpendingconnections",ring_QTcpServer_setMaxPendingConnections);
	RING_API_REGISTER("qtcpserver_setproxy",ring_QTcpServer_setProxy);
	RING_API_REGISTER("qtcpserver_setsocketdescriptor",ring_QTcpServer_setSocketDescriptor);
	RING_API_REGISTER("qtcpserver_socketdescriptor",ring_QTcpServer_socketDescriptor);
	RING_API_REGISTER("qtcpserver_waitfornewconnection",ring_QTcpServer_waitForNewConnection);
	RING_API_REGISTER("qtcpserver_setaccepterrorevent",ring_QTcpServer_setacceptErrorEvent);
	RING_API_REGISTER("qtcpserver_setnewconnectionevent",ring_QTcpServer_setnewConnectionEvent);
	RING_API_REGISTER("qtcpserver_getaccepterrorevent",ring_QTcpServer_getacceptErrorEvent);
	RING_API_REGISTER("qtcpserver_getnewconnectionevent",ring_QTcpServer_getnewConnectionEvent);
	RING_API_REGISTER("qhostaddress_clear",ring_QHostAddress_clear);
	RING_API_REGISTER("qhostaddress_isinsubnet",ring_QHostAddress_isInSubnet);
	RING_API_REGISTER("qhostaddress_isnull",ring_QHostAddress_isNull);
	RING_API_REGISTER("qhostaddress_protocol",ring_QHostAddress_protocol);
	RING_API_REGISTER("qhostaddress_scopeid",ring_QHostAddress_scopeId);
	RING_API_REGISTER("qhostaddress_setaddress",ring_QHostAddress_setAddress);
	RING_API_REGISTER("qhostaddress_toipv4address",ring_QHostAddress_toIPv4Address);
	RING_API_REGISTER("qhostaddress_toipv6address",ring_QHostAddress_toIPv6Address);
	RING_API_REGISTER("qhostaddress_tostring",ring_QHostAddress_toString);
	RING_API_REGISTER("qhostinfo_error",ring_QHostInfo_error);
	RING_API_REGISTER("qhostinfo_errorstring",ring_QHostInfo_errorString);
	RING_API_REGISTER("qhostinfo_hostname",ring_QHostInfo_hostName);
	RING_API_REGISTER("qhostinfo_lookupid",ring_QHostInfo_lookupId);
	RING_API_REGISTER("qhostinfo_seterror",ring_QHostInfo_setError);
	RING_API_REGISTER("qhostinfo_seterrorstring",ring_QHostInfo_setErrorString);
	RING_API_REGISTER("qhostinfo_sethostname",ring_QHostInfo_setHostName);
	RING_API_REGISTER("qhostinfo_setlookupid",ring_QHostInfo_setLookupId);
	RING_API_REGISTER("qhostinfo_aborthostlookup",ring_QHostInfo_abortHostLookup);
	RING_API_REGISTER("qhostinfo_fromname",ring_QHostInfo_fromName);
	RING_API_REGISTER("qhostinfo_localdomainname",ring_QHostInfo_localDomainName);
	RING_API_REGISTER("qhostinfo_localhostname",ring_QHostInfo_localHostName);
	RING_API_REGISTER("qnetworkrequest_attribute",ring_QNetworkRequest_attribute);
	RING_API_REGISTER("qnetworkrequest_hasrawheader",ring_QNetworkRequest_hasRawHeader);
	RING_API_REGISTER("qnetworkrequest_header",ring_QNetworkRequest_header);
	RING_API_REGISTER("qnetworkrequest_originatingobject",ring_QNetworkRequest_originatingObject);
	RING_API_REGISTER("qnetworkrequest_priority",ring_QNetworkRequest_priority);
	RING_API_REGISTER("qnetworkrequest_rawheader",ring_QNetworkRequest_rawHeader);
	RING_API_REGISTER("qnetworkrequest_setattribute",ring_QNetworkRequest_setAttribute);
	RING_API_REGISTER("qnetworkrequest_setheader",ring_QNetworkRequest_setHeader);
	RING_API_REGISTER("qnetworkrequest_setoriginatingobject",ring_QNetworkRequest_setOriginatingObject);
	RING_API_REGISTER("qnetworkrequest_setpriority",ring_QNetworkRequest_setPriority);
	RING_API_REGISTER("qnetworkrequest_setrawheader",ring_QNetworkRequest_setRawHeader);
	RING_API_REGISTER("qnetworkrequest_seturl",ring_QNetworkRequest_setUrl);
	RING_API_REGISTER("qnetworkrequest_swap",ring_QNetworkRequest_swap);
	RING_API_REGISTER("qnetworkrequest_url",ring_QNetworkRequest_url);
	RING_API_REGISTER("qnetworkreply_attribute",ring_QNetworkReply_attribute);
	RING_API_REGISTER("qnetworkreply_error",ring_QNetworkReply_error);
	RING_API_REGISTER("qnetworkreply_hasrawheader",ring_QNetworkReply_hasRawHeader);
	RING_API_REGISTER("qnetworkreply_header",ring_QNetworkReply_header);
	RING_API_REGISTER("qnetworkreply_isfinished",ring_QNetworkReply_isFinished);
	RING_API_REGISTER("qnetworkreply_isrunning",ring_QNetworkReply_isRunning);
	RING_API_REGISTER("qnetworkreply_manager",ring_QNetworkReply_manager);
	RING_API_REGISTER("qnetworkreply_operation",ring_QNetworkReply_operation);
	RING_API_REGISTER("qnetworkreply_rawheader",ring_QNetworkReply_rawHeader);
	RING_API_REGISTER("qnetworkreply_readbuffersize",ring_QNetworkReply_readBufferSize);
	RING_API_REGISTER("qnetworkreply_request",ring_QNetworkReply_request);
	RING_API_REGISTER("qnetworkreply_url",ring_QNetworkReply_url);
	RING_API_REGISTER("qnetworkaccessmanager_setfinishedevent",ring_QNetworkAccessManager_setfinishedEvent);
	RING_API_REGISTER("qnetworkaccessmanager_getfinishedevent",ring_QNetworkAccessManager_getfinishedEvent);
	RING_API_REGISTER("qnetworkaccessmanager_cache",ring_QNetworkAccessManager_cache);
	RING_API_REGISTER("qnetworkaccessmanager_clearaccesscache",ring_QNetworkAccessManager_clearAccessCache);
	RING_API_REGISTER("qnetworkaccessmanager_connecttohost",ring_QNetworkAccessManager_connectToHost);
	RING_API_REGISTER("qnetworkaccessmanager_cookiejar",ring_QNetworkAccessManager_cookieJar);
	RING_API_REGISTER("qnetworkaccessmanager_deleteresource",ring_QNetworkAccessManager_deleteResource);
	RING_API_REGISTER("qnetworkaccessmanager_get",ring_QNetworkAccessManager_get);
	RING_API_REGISTER("qnetworkaccessmanager_head",ring_QNetworkAccessManager_head);
	RING_API_REGISTER("qnetworkaccessmanager_post",ring_QNetworkAccessManager_post);
	RING_API_REGISTER("qnetworkaccessmanager_proxy",ring_QNetworkAccessManager_proxy);
	RING_API_REGISTER("qnetworkaccessmanager_proxyfactory",ring_QNetworkAccessManager_proxyFactory);
	RING_API_REGISTER("qnetworkaccessmanager_put",ring_QNetworkAccessManager_put);
	RING_API_REGISTER("qnetworkaccessmanager_sendcustomrequest",ring_QNetworkAccessManager_sendCustomRequest);
	RING_API_REGISTER("qnetworkaccessmanager_setcache",ring_QNetworkAccessManager_setCache);
	RING_API_REGISTER("qnetworkaccessmanager_setcookiejar",ring_QNetworkAccessManager_setCookieJar);
	RING_API_REGISTER("qnetworkaccessmanager_setproxy",ring_QNetworkAccessManager_setProxy);
	RING_API_REGISTER("qnetworkaccessmanager_setproxyfactory",ring_QNetworkAccessManager_setProxyFactory);
	RING_API_REGISTER("qnetworkaccessmanager_supportedschemes",ring_QNetworkAccessManager_supportedSchemes);
	RING_API_REGISTER("qnetworkaccessmanager_geteventparameters",ring_QNetworkAccessManager_geteventparameters);
	RING_API_REGISTER("qqmlerror_column",ring_QQmlError_column);
	RING_API_REGISTER("qqmlerror_description",ring_QQmlError_description);
	RING_API_REGISTER("qqmlerror_isvalid",ring_QQmlError_isValid);
	RING_API_REGISTER("qqmlerror_line",ring_QQmlError_line);
	RING_API_REGISTER("qqmlerror_object",ring_QQmlError_object);
	RING_API_REGISTER("qqmlerror_setcolumn",ring_QQmlError_setColumn);
	RING_API_REGISTER("qqmlerror_setdescription",ring_QQmlError_setDescription);
	RING_API_REGISTER("qqmlerror_setline",ring_QQmlError_setLine);
	RING_API_REGISTER("qqmlerror_setobject",ring_QQmlError_setObject);
	RING_API_REGISTER("qqmlerror_seturl",ring_QQmlError_setUrl);
	RING_API_REGISTER("qqmlerror_tostring",ring_QQmlError_toString);
	RING_API_REGISTER("qqmlerror_url",ring_QQmlError_url);
	RING_API_REGISTER("qqmlengine_addimageprovider",ring_QQmlEngine_addImageProvider);
	RING_API_REGISTER("qqmlengine_addimportpath",ring_QQmlEngine_addImportPath);
	RING_API_REGISTER("qqmlengine_addpluginpath",ring_QQmlEngine_addPluginPath);
	RING_API_REGISTER("qqmlengine_baseurl",ring_QQmlEngine_baseUrl);
	RING_API_REGISTER("qqmlengine_clearcomponentcache",ring_QQmlEngine_clearComponentCache);
	RING_API_REGISTER("qqmlengine_imageprovider",ring_QQmlEngine_imageProvider);
	RING_API_REGISTER("qqmlengine_importpathlist",ring_QQmlEngine_importPathList);
	RING_API_REGISTER("qqmlengine_importplugin",ring_QQmlEngine_importPlugin);
	RING_API_REGISTER("qqmlengine_incubationcontroller",ring_QQmlEngine_incubationController);
	RING_API_REGISTER("qqmlengine_networkaccessmanager",ring_QQmlEngine_networkAccessManager);
	RING_API_REGISTER("qqmlengine_networkaccessmanagerfactory",ring_QQmlEngine_networkAccessManagerFactory);
	RING_API_REGISTER("qqmlengine_offlinestoragedatabasefilepath",ring_QQmlEngine_offlineStorageDatabaseFilePath);
	RING_API_REGISTER("qqmlengine_offlinestoragepath",ring_QQmlEngine_offlineStoragePath);
	RING_API_REGISTER("qqmlengine_outputwarningstostandarderror",ring_QQmlEngine_outputWarningsToStandardError);
	RING_API_REGISTER("qqmlengine_pluginpathlist",ring_QQmlEngine_pluginPathList);
	RING_API_REGISTER("qqmlengine_removeimageprovider",ring_QQmlEngine_removeImageProvider);
	RING_API_REGISTER("qqmlengine_rootcontext",ring_QQmlEngine_rootContext);
	RING_API_REGISTER("qqmlengine_setbaseurl",ring_QQmlEngine_setBaseUrl);
	RING_API_REGISTER("qqmlengine_setimportpathlist",ring_QQmlEngine_setImportPathList);
	RING_API_REGISTER("qqmlengine_setincubationcontroller",ring_QQmlEngine_setIncubationController);
	RING_API_REGISTER("qqmlengine_setnetworkaccessmanagerfactory",ring_QQmlEngine_setNetworkAccessManagerFactory);
	RING_API_REGISTER("qqmlengine_setofflinestoragepath",ring_QQmlEngine_setOfflineStoragePath);
	RING_API_REGISTER("qqmlengine_setoutputwarningstostandarderror",ring_QQmlEngine_setOutputWarningsToStandardError);
	RING_API_REGISTER("qqmlengine_setpluginpathlist",ring_QQmlEngine_setPluginPathList);
	RING_API_REGISTER("qqmlengine_trimcomponentcache",ring_QQmlEngine_trimComponentCache);
	RING_API_REGISTER("qqmlengine_retranslate",ring_QQmlEngine_retranslate);
	RING_API_REGISTER("qqmlengine_contextforobject",ring_QQmlEngine_contextForObject);
	RING_API_REGISTER("qqmlengine_objectownership",ring_QQmlEngine_objectOwnership);
	RING_API_REGISTER("qqmlengine_setcontextforobject",ring_QQmlEngine_setContextForObject);
	RING_API_REGISTER("qqmlengine_setobjectownership",ring_QQmlEngine_setObjectOwnership);
	RING_API_REGISTER("qobject_new",ring_QObject_new);
	RING_API_REGISTER("qsize_new",ring_QSize_new);
	RING_API_REGISTER("qdir_new",ring_QDir_new);
	RING_API_REGISTER("qurl_new",ring_QUrl_new);
	RING_API_REGISTER("qevent_new",ring_QEvent_new);
	RING_API_REGISTER("qtimer_new",ring_QTimer_new);
	RING_API_REGISTER("qbytearray_new",ring_QByteArray_new);
	RING_API_REGISTER("qfileinfo_new",ring_QFileInfo_new);
	RING_API_REGISTER("qstringlist_new",ring_QStringList_new);
	RING_API_REGISTER("qtime_new",ring_QTime_new);
	RING_API_REGISTER("qdate_new",ring_QDate_new);
	RING_API_REGISTER("qvariant_new",ring_QVariant_new);
	RING_API_REGISTER("qvariant2_new",ring_QVariant2_new);
	RING_API_REGISTER("qvariant3_new",ring_QVariant3_new);
	RING_API_REGISTER("qvariant4_new",ring_QVariant4_new);
	RING_API_REGISTER("qvariantint_new",ring_QVariantInt_new);
	RING_API_REGISTER("qvariantfloat_new",ring_QVariantFloat_new);
	RING_API_REGISTER("qvariantdouble_new",ring_QVariantDouble_new);
	RING_API_REGISTER("qjsonarray_new",ring_QJsonArray_new);
	RING_API_REGISTER("qjsondocument_new",ring_QJsonDocument_new);
	RING_API_REGISTER("qjsonobject_new",ring_QJsonObject_new);
	RING_API_REGISTER("qjsonparseerror_new",ring_QJsonParseError_new);
	RING_API_REGISTER("qjsonvalue_new",ring_QJsonValue_new);
	RING_API_REGISTER("qstring2_new",ring_QString2_new);
	RING_API_REGISTER("qbuffer_new",ring_QBuffer_new);
	RING_API_REGISTER("qdatetime_new",ring_QDateTime_new);
	RING_API_REGISTER("qfile_new",ring_QFile_new);
	RING_API_REGISTER("qfile2_new",ring_QFile2_new);
	RING_API_REGISTER("qmimedata_new",ring_QMimeData_new);
	RING_API_REGISTER("qchar_new",ring_QChar_new);
	RING_API_REGISTER("qchildevent_new",ring_QChildEvent_new);
	RING_API_REGISTER("qlocale_new",ring_QLocale_new);
	RING_API_REGISTER("qthread_new",ring_QThread_new);
	RING_API_REGISTER("qthreadpool_new",ring_QThreadPool_new);
	RING_API_REGISTER("qprocess_new",ring_QProcess_new);
	RING_API_REGISTER("quuid_new",ring_QUuid_new);
	RING_API_REGISTER("qmutexlocker_new",ring_QMutexLocker_new);
	RING_API_REGISTER("qversionnumber_new",ring_QVersionNumber_new);
	RING_API_REGISTER("qpixmap_new",ring_QPixmap_new);
	RING_API_REGISTER("qpixmap2_new",ring_QPixmap2_new);
	RING_API_REGISTER("qicon_new",ring_QIcon_new);
	RING_API_REGISTER("qpicture_new",ring_QPicture_new);
	RING_API_REGISTER("qfont_new",ring_QFont_new);
	RING_API_REGISTER("qimage_new",ring_QImage_new);
	RING_API_REGISTER("qwindow_new",ring_QWindow_new);
	RING_API_REGISTER("qguiapplication_new",ring_QGuiApplication_new);
	RING_API_REGISTER("qfontdatabase_new",ring_QFontDatabase_new);
	RING_API_REGISTER("qallevents_new",ring_QAllEvents_new);
	RING_API_REGISTER("qnetworkproxy_new",ring_QNetworkProxy_new);
	RING_API_REGISTER("qtcpsocket_new",ring_QTcpSocket_new);
	RING_API_REGISTER("qtcpserver_new",ring_QTcpServer_new);
	RING_API_REGISTER("qhostaddress_new",ring_QHostAddress_new);
	RING_API_REGISTER("qhostinfo_new",ring_QHostInfo_new);
	RING_API_REGISTER("qnetworkrequest_new",ring_QNetworkRequest_new);
	RING_API_REGISTER("qnetworkaccessmanager_new",ring_QNetworkAccessManager_new);
	RING_API_REGISTER("qqmlerror_new",ring_QQmlError_new);
	RING_API_REGISTER("qqmlengine_new",ring_QQmlEngine_new);
	RING_API_REGISTER("qobject_delete",ring_QObject_delete);
	RING_API_REGISTER("qsize_delete",ring_QSize_delete);
	RING_API_REGISTER("qdir_delete",ring_QDir_delete);
	RING_API_REGISTER("qurl_delete",ring_QUrl_delete);
	RING_API_REGISTER("qevent_delete",ring_QEvent_delete);
	RING_API_REGISTER("qtimer_delete",ring_QTimer_delete);
	RING_API_REGISTER("qbytearray_delete",ring_QByteArray_delete);
	RING_API_REGISTER("qfileinfo_delete",ring_QFileInfo_delete);
	RING_API_REGISTER("qstringlist_delete",ring_QStringList_delete);
	RING_API_REGISTER("qtime_delete",ring_QTime_delete);
	RING_API_REGISTER("qdate_delete",ring_QDate_delete);
	RING_API_REGISTER("qvariant_delete",ring_QVariant_delete);
	RING_API_REGISTER("qvariant2_delete",ring_QVariant2_delete);
	RING_API_REGISTER("qvariant3_delete",ring_QVariant3_delete);
	RING_API_REGISTER("qvariant4_delete",ring_QVariant4_delete);
	RING_API_REGISTER("qvariantint_delete",ring_QVariantInt_delete);
	RING_API_REGISTER("qvariantfloat_delete",ring_QVariantFloat_delete);
	RING_API_REGISTER("qvariantdouble_delete",ring_QVariantDouble_delete);
	RING_API_REGISTER("qjsonarray_delete",ring_QJsonArray_delete);
	RING_API_REGISTER("qjsondocument_delete",ring_QJsonDocument_delete);
	RING_API_REGISTER("qjsonobject_delete",ring_QJsonObject_delete);
	RING_API_REGISTER("qjsonparseerror_delete",ring_QJsonParseError_delete);
	RING_API_REGISTER("qjsonvalue_delete",ring_QJsonValue_delete);
	RING_API_REGISTER("qstring2_delete",ring_QString2_delete);
	RING_API_REGISTER("qbuffer_delete",ring_QBuffer_delete);
	RING_API_REGISTER("qdatetime_delete",ring_QDateTime_delete);
	RING_API_REGISTER("qfile_delete",ring_QFile_delete);
	RING_API_REGISTER("qfile2_delete",ring_QFile2_delete);
	RING_API_REGISTER("qmimedata_delete",ring_QMimeData_delete);
	RING_API_REGISTER("qchar_delete",ring_QChar_delete);
	RING_API_REGISTER("qchildevent_delete",ring_QChildEvent_delete);
	RING_API_REGISTER("qlocale_delete",ring_QLocale_delete);
	RING_API_REGISTER("qthread_delete",ring_QThread_delete);
	RING_API_REGISTER("qthreadpool_delete",ring_QThreadPool_delete);
	RING_API_REGISTER("qprocess_delete",ring_QProcess_delete);
	RING_API_REGISTER("quuid_delete",ring_QUuid_delete);
	RING_API_REGISTER("qmutexlocker_delete",ring_QMutexLocker_delete);
	RING_API_REGISTER("qversionnumber_delete",ring_QVersionNumber_delete);
	RING_API_REGISTER("qpixmap_delete",ring_QPixmap_delete);
	RING_API_REGISTER("qpixmap2_delete",ring_QPixmap2_delete);
	RING_API_REGISTER("qicon_delete",ring_QIcon_delete);
	RING_API_REGISTER("qpicture_delete",ring_QPicture_delete);
	RING_API_REGISTER("qfont_delete",ring_QFont_delete);
	RING_API_REGISTER("qimage_delete",ring_QImage_delete);
	RING_API_REGISTER("qwindow_delete",ring_QWindow_delete);
	RING_API_REGISTER("qguiapplication_delete",ring_QGuiApplication_delete);
	RING_API_REGISTER("qfontdatabase_delete",ring_QFontDatabase_delete);
	RING_API_REGISTER("qallevents_delete",ring_QAllEvents_delete);
	RING_API_REGISTER("qnetworkproxy_delete",ring_QNetworkProxy_delete);
	RING_API_REGISTER("qtcpsocket_delete",ring_QTcpSocket_delete);
	RING_API_REGISTER("qtcpserver_delete",ring_QTcpServer_delete);
	RING_API_REGISTER("qhostaddress_delete",ring_QHostAddress_delete);
	RING_API_REGISTER("qhostinfo_delete",ring_QHostInfo_delete);
	RING_API_REGISTER("qnetworkrequest_delete",ring_QNetworkRequest_delete);
	RING_API_REGISTER("qnetworkaccessmanager_delete",ring_QNetworkAccessManager_delete);
	RING_API_REGISTER("qqmlerror_delete",ring_QQmlError_delete);
	RING_API_REGISTER("qqmlengine_delete",ring_QQmlEngine_delete);
}
