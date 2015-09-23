# This file is generated automatically. Do not edit.
# Use project properties -> Build -> Qt -> Expert -> Custom Definitions.
TEMPLATE = app
DESTDIR = dist/Debug/GNU-Linux-x86
TARGET = Archiver
VERSION = 1.0.0
CONFIG -= debug_and_release app_bundle lib_bundle
CONFIG += debug 
PKGCONFIG +=
QT = core gui widgets
SOURCES += FileArchiver.cpp FileRec.cpp MyTableModel.cpp VersionRec.cpp archiver.cpp fileexplorer.cpp getcomment.cpp main.cpp retriever.cpp setreference.cpp
HEADERS += FileArchiver.h FileRec.h MyTableModel.h VersionInfoRecord.h VersionRec.h archiver.h fileexplorer.h getcomment.h retriever.h setreference.h ui_archiver.h ui_fileexplorer.h ui_getcomment.h ui_retriever.h ui_setreference.h
FORMS += archiver.ui fileexplorer.ui getcomment.ui retriever.ui setreference.ui
RESOURCES +=
TRANSLATIONS +=
OBJECTS_DIR = build/Debug/GNU-Linux-x86
MOC_DIR = 
RCC_DIR = 
UI_DIR = 
QMAKE_CC = gcc
QMAKE_CXX = g++
DEFINES += 
INCLUDEPATH += 
LIBS += 
