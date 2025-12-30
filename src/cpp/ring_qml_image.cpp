/*
    Project      : RingQML library for Ring Programming Language
    Author       : Mohannad Azeez Al-Ayash 
    E-Mail       : mohannadazazalayash@gmail.com
    WebSite      : https://mohannad-aldulaimi.github.io
    File Purpose : SharedPixmapProvider Class implementation.
*/
//<FileStart>
#include "ring_qml_image.h"

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
//<FileEnd>