
TEMPLATE = app
TARGET = 
QT = gui core testlib
CONFIG += qt debug warn_on console

DESTDIR = bin/test
OBJECTS_DIR = build/test
MOC_DIR = build/test
UI_DIR = build/test

DEPENDPATH += . build/test build test src ui
INCLUDEPATH += . test src build/test build

include(./TeXular.pri)

SOURCES += ./test/main.cpp \
			./test/TestCellElement.cpp

HEADERS += ./test/TestCellElement.h
