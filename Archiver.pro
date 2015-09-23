#-------------------------------------------------
#
# Project created by QtCreator 2015-09-16T15:08:23
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Archiver
TEMPLATE = app


SOURCES += main.cpp\
        archiver.cpp \
    getcomment.cpp \
    retriever.cpp \
    setreference.cpp \
    fileexplorer.cpp

HEADERS  += archiver.h \
    getcomment.h \
    retriever.h \
    setreference.h \
    fileexplorer.h

FORMS    += archiver.ui \
    getcomment.ui \
    retriever.ui \
    setreference.ui \
    fileexplorer.ui
