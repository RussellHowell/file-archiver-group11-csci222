# This file is generated automatically. Do not edit.
# Use project properties -> Build -> Qt -> Expert -> Custom Definitions.
TEMPLATE = app
DESTDIR = dist/Release/GNU-Linux-x86
TARGET = file-archiver-group11-csci222
VERSION = 1.0.0
CONFIG -= debug_and_release app_bundle lib_bundle
CONFIG += release 
PKGCONFIG +=
QT = core gui widgets
SOURCES += Archiver.cpp FileArchiver.cpp FileRec.cpp GetComment.cpp Retriever.cpp VersionRec.cpp main.cpp
HEADERS += Archiver.h FileArchiver.h FileRec.h GetComment.h Retriever.h VersionRec.h ui_Archiver.h ui_GetComment.h ui_Retriever.h
FORMS += Archiver.ui GetComment.ui Retriever.ui
RESOURCES +=
TRANSLATIONS +=
OBJECTS_DIR = build/Release/GNU-Linux-x86
MOC_DIR = 
RCC_DIR = 
UI_DIR = 
QMAKE_CC = gcc
QMAKE_CXX = g++
DEFINES += 
INCLUDEPATH += 
LIBS += 
