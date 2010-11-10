
TEMPLATE = app
TARGET =
QT = gui core
CONFIG += qt debug_and_release warn_on console

DESTDIR = bin
OBJECTS_DIR = build
MOC_DIR = build
UI_DIR = build

DEPENDPATH += . build src ui
INCLUDEPATH += . src build

include(TeXular.pri)

SOURCES += src/main.cpp \

