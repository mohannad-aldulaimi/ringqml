#-------------------------------------------------
# Project : RingQML
# Author  : Mohannad Al-Ayash
#-------------------------------------------------

QT       += qml widgets quick quickwidgets quickcontrols2
QT       += core gui network

TARGET = RingQML
TEMPLATE = lib

# Force Release Build only (prevents debug folders)
CONFIG += release
CONFIG -= debug_and_release

# Disable Unicode defines if Ring is built without them
DEFINES -= UNICODE

# Optimization and Warnings
CONFIG += c++11
# CONFIG += qtquickcompiler 

# Add local include directory to path
INCLUDEPATH += include

SOURCES += \
    cpp/ring_qml_api.cpp \
    cpp/ring_qml_utils.cpp \
    cpp/ring_qml_core.cpp \
    cpp/ring_qml_loader.cpp \
    cpp/ring_qml_image.cpp

HEADERS += \
    include/ring_qml_utils.h \
    include/ring_qml_core.h \
    include/ring_qml_loader.h \
    include/ring_qml_image.h

# Adjust this path to match your Ring installation
INCLUDEPATH += ../../../language/include

win32 {
    LIBS += ../../../lib/ring.lib
}

# --- Build Output Configuration ---

# 1. Put the compiled DLL directly in 'Build'
DESTDIR = Build

# 2. Put all intermediate files (Obj, Moc, etc) in 'Build/tmp'
#    This keeps your source folder clean (no 'release' or 'debug' folders in root)
MOC_DIR     = Build/tmp
OBJECTS_DIR = Build/tmp
RCC_DIR     = Build/tmp
UI_DIR      = Build/tmp