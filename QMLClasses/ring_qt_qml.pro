

# ring_qt_qml


#-------------------------------------------------
#
# Project created by QtCreator 2014-10-19T17:41:04
#
#-------------------------------------------------

# QT       += core gui network multimedia multimediawidgets testlib printsupport widgets sql bluetooth quick quickwidgets qml positioning texttospeech 3dcore 3dextras 3drender 3dlogic charts svg quickcontrols2
QT       += gui core quick qml svg network widgets

QT += quickcontrols2
QT -= bluetooth positioning location

TARGET = ring_qt_qml
TEMPLATE = lib

DEFINES -= UNICODE

INCLUDEPATH += C:/ring/language/include
INCLUDEPATH += C:/ring/extensions/ringqt/cpp/include

HEADERS += \
    C:/ring/extensions/ringqt/cpp/include/gtimer.h \
    C:/ring/extensions/ringqt/cpp/include/giodevice.h \
    C:/ring/extensions/ringqt/cpp/include/gprocess.h \
    C:/ring/extensions/ringqt/cpp/include/gthread.h \
    C:/ring/extensions/ringqt/cpp/include/gwindow.h \
    C:/ring/extensions/ringqt/cpp/include/gallevents.h \
    # Gui
    C:/ring/extensions/ringqt/cpp/include/gguiapplication.h \
    # network
    C:/ring/extensions/ringqt/cpp/include/gabstractsocket.h \
    C:/ring/extensions/ringqt/cpp/include/gtcpsocket.h \
    C:/ring/extensions/ringqt/cpp/include/gnetworkaccessmanager.h \
    C:/ring/extensions/ringqt/cpp/include/gtcpserver.h 

SOURCES +=   \
    C:/ring/extensions/ringqt/cpp/src/gtimer.cpp \
    C:/ring/extensions/ringqt/cpp/src/giodevice.cpp \
    C:/ring/extensions/ringqt/cpp/src/gprocess.cpp \
    C:/ring/extensions/ringqt/cpp/src/gthread.cpp \
    C:/ring/extensions/ringqt/cpp/src/gwindow.cpp \
    C:/ring/extensions/ringqt/cpp/src/gallevents.cpp \
    # Gui
    C:/ring/extensions/ringqt/cpp/src/gguiapplication.cpp \
    # network
    C:/ring/extensions/ringqt/cpp/src/gabstractsocket.cpp \
    C:/ring/extensions/ringqt/cpp/src/gtcpsocket.cpp \
    C:/ring/extensions/ringqt/cpp/src/gnetworkaccessmanager.cpp \
    C:/ring/extensions/ringqt/cpp/src/gtcpserver.cpp \
    ring_qt_qml.cpp \

CONFIG += warn_off
CONFIG += -Wno-deprecated

win32-msvc* {
    LIBS += -L"C:/ring/lib" -lring
    PRE_TARGETDEPS += C:/ring/lib/ring.lib
} else {
    LIBS += -L"C:/ring/lib" -lring
}
