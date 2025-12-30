/*
    Project      : RingQML library for Ring Programming Language
    Author       : Mohannad Azeez Al-Ayash 
    E-Mail       : mohannadazazalayash@gmail.com
    WebSite      : https://mohannad-aldulaimi.github.io
    File Purpose : SharedPixmapProvider Class Definition.
*/
//<FileStart>
#ifndef RING_QML_IMAGE_H
#define RING_QML_IMAGE_H
//<IncludeStart>
#include <QQuickImageProvider>
#include <QPixmap>
#include <QMap>
#include <QQmlEngine>
//<IncludeEnd>
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
//<FileEnd>