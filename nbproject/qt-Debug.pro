# This file is generated automatically. Do not edit.
# Use project properties -> Build -> Qt -> Expert -> Custom Definitions.
TEMPLATE = app
DESTDIR = dist/Debug/GNU-Linux-x86
TARGET = file-archiver-group11-csci222
VERSION = 1.0.0
CONFIG -= debug_and_release app_bundle lib_bundle
CONFIG += debug 
PKGCONFIG +=
QT = core gui widgets
SOURCES += Archiver.cpp FileArchiver.cpp FileRec.cpp GetComment.cpp Retriever.cpp VersionRec.cpp main.cpp
HEADERS += Archiver.h FileArchiver.h FileRec.h GetComment.h Retriever.h VersionRec.h ui_Archiver.h ui_GetComment.h ui_Retriever.h
FORMS += Archiver.ui GetComment.ui Retriever.ui
RESOURCES +=
TRANSLATIONS +=
OBJECTS_DIR = build/Debug/GNU-Linux-x86
MOC_DIR = 
RCC_DIR = 
UI_DIR = 
QMAKE_CC = gcc
QMAKE_CXX = g++
DEFINES += 
INCLUDEPATH += /usr/include/boost/iostreams /usr/include/cppconn /usr/include/qt4 
LIBS += -Wl,-rpath,/usr/lib /usr/lib/libmysqlcppconn.so -Wl,-rpath,/usr/lib/x86_64-linux-gnu /usr/lib/x86_64-linux-gnu/libQtCore.so -Wl,-rpath,/usr/lib/x86_64-linux-gnu /usr/lib/x86_64-linux-gnu/libQtGui.so -Wl,-rpath,/usr/lib/x86_64-linux-gnu /usr/lib/x86_64-linux-gnu/libboost_chrono.so -Wl,-rpath,/usr/lib/x86_64-linux-gnu /usr/lib/x86_64-linux-gnu/libboost_iostreams.so -Wl,-rpath,/usr/lib/x86_64-linux-gnu /usr/lib/x86_64-linux-gnu/libboost_system.so -Wl,-rpath,/usr/lib/x86_64-linux-gnu /usr/lib/x86_64-linux-gnu/libboost_date_time.so  
