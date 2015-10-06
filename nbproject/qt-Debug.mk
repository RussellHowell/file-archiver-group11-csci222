#############################################################################
# Makefile for building: dist/Debug/GNU-Linux-x86/file-archiver-group11-csci222-master
# Generated by qmake (2.01a) (Qt 4.8.6) on: Tue Oct 6 18:39:41 2015
# Project:  nbproject/qt-Debug.pro
# Template: app
# Command: /usr/lib/x86_64-linux-gnu/qt4/bin/qmake VPATH=. -o qttmp-Debug.mk nbproject/qt-Debug.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -m64 -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -m64 -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++-64 -Inbproject -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4 -I/usr/include/boost/iostreams -I/usr/include/cppconn -I/usr/include/qt4 -I. -I. -Inbproject -I.
LINK          = g++
LFLAGS        = -m64
LIBS          = $(SUBLIBS)  -L/usr/lib/x86_64-linux-gnu -Wl,-rpath,/usr/lib /usr/lib/libmysqlcppconn.so -Wl,-rpath,/usr/lib/x86_64-linux-gnu /usr/lib/x86_64-linux-gnu/libQtCore.so -Wl,-rpath,/usr/lib/x86_64-linux-gnu /usr/lib/x86_64-linux-gnu/libQtGui.so -Wl,-rpath,/usr/lib/x86_64-linux-gnu /usr/lib/x86_64-linux-gnu/libboost_chrono.so -Wl,-rpath,/usr/lib/x86_64-linux-gnu /usr/lib/x86_64-linux-gnu/libboost_iostreams.so -Wl,-rpath,/usr/lib/x86_64-linux-gnu /usr/lib/x86_64-linux-gnu/libboost_system.so -Wl,-rpath,/usr/lib/x86_64-linux-gnu /usr/lib/x86_64-linux-gnu/libboost_date_time.so -lQtGui -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/lib/x86_64-linux-gnu/qt4/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = build/Debug/GNU-Linux-x86/

####### Files

SOURCES       = Archiver.cpp \
		GetComment.cpp \
		Retriever.cpp \
		main.cpp \
		FileArchiver.cpp \
		FileRec.cpp \
		VersionRec.cpp moc_Archiver.cpp \
		moc_GetComment.cpp \
		moc_Retriever.cpp
OBJECTS       = build/Debug/GNU-Linux-x86/Archiver.o \
		build/Debug/GNU-Linux-x86/GetComment.o \
		build/Debug/GNU-Linux-x86/Retriever.o \
		build/Debug/GNU-Linux-x86/main.o \
		build/Debug/GNU-Linux-x86/FileArchiver.o \
		build/Debug/GNU-Linux-x86/FileRec.o \
		build/Debug/GNU-Linux-x86/VersionRec.o \
		build/Debug/GNU-Linux-x86/moc_Archiver.o \
		build/Debug/GNU-Linux-x86/moc_GetComment.o \
		build/Debug/GNU-Linux-x86/moc_Retriever.o
DIST          = /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/debug.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/shared.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		nbproject/qt-Debug.pro
QMAKE_TARGET  = file-archiver-group11-csci222-master
DESTDIR       = dist/Debug/GNU-Linux-x86/
TARGET        = dist/Debug/GNU-Linux-x86/file-archiver-group11-csci222-master

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: qttmp-Debug.mk $(TARGET)

$(TARGET): ui_Archiver.h ui_GetComment.h ui_Retriever.h $(OBJECTS)  
	@$(CHK_DIR_EXISTS) dist/Debug/GNU-Linux-x86/ || $(MKDIR) dist/Debug/GNU-Linux-x86/ 
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)
	{ test -n "$(DESTDIR)" && DESTDIR="$(DESTDIR)" || DESTDIR=.; } && test $$(gdb --version | sed -e 's,[^0-9][^0-9]*\([0-9]\)\.\([0-9]\).*,\1\2,;q') -gt 72 && gdb --nx --batch --quiet -ex 'set confirm off' -ex "save gdb-index $$DESTDIR" -ex quit '$(TARGET)' && test -f $(TARGET).gdb-index && objcopy --add-section '.gdb_index=$(TARGET).gdb-index' --set-section-flags '.gdb_index=readonly' '$(TARGET)' '$(TARGET)' && rm -f $(TARGET).gdb-index || true

qttmp-Debug.mk: nbproject/qt-Debug.pro  /usr/share/qt4/mkspecs/linux-g++-64/qmake.conf /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/debug.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/shared.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		/usr/lib/x86_64-linux-gnu/libQtCore.prl \
		/usr/lib/x86_64-linux-gnu/libQtGui.prl
	$(QMAKE) VPATH=. -o qttmp-Debug.mk nbproject/qt-Debug.pro
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/common/gcc-base.conf:
/usr/share/qt4/mkspecs/common/gcc-base-unix.conf:
/usr/share/qt4/mkspecs/common/g++-base.conf:
/usr/share/qt4/mkspecs/common/g++-unix.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/debug.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/shared.prf:
/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/share/qt4/mkspecs/features/include_source_dir.prf:
/usr/lib/x86_64-linux-gnu/libQtCore.prl:
/usr/lib/x86_64-linux-gnu/libQtGui.prl:
qmake:  FORCE
	@$(QMAKE) VPATH=. -o qttmp-Debug.mk nbproject/qt-Debug.pro

dist: 
	@$(CHK_DIR_EXISTS) build/Debug/GNU-Linux-x86/file-archiver-group11-csci222-master1.0.0 || $(MKDIR) build/Debug/GNU-Linux-x86/file-archiver-group11-csci222-master1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) build/Debug/GNU-Linux-x86/file-archiver-group11-csci222-master1.0.0/ && $(COPY_FILE) --parents Archiver.h GetComment.h Retriever.h ui_Archiver.h ui_GetComment.h ui_Retriever.h FileArchiver.h FileRec.h VersionRec.h build/Debug/GNU-Linux-x86/file-archiver-group11-csci222-master1.0.0/ && $(COPY_FILE) --parents Archiver.cpp GetComment.cpp Retriever.cpp main.cpp FileArchiver.cpp FileRec.cpp VersionRec.cpp build/Debug/GNU-Linux-x86/file-archiver-group11-csci222-master1.0.0/ && $(COPY_FILE) --parents Archiver.ui GetComment.ui Retriever.ui build/Debug/GNU-Linux-x86/file-archiver-group11-csci222-master1.0.0/ && (cd `dirname build/Debug/GNU-Linux-x86/file-archiver-group11-csci222-master1.0.0` && $(TAR) file-archiver-group11-csci222-master1.0.0.tar file-archiver-group11-csci222-master1.0.0 && $(COMPRESS) file-archiver-group11-csci222-master1.0.0.tar) && $(MOVE) `dirname build/Debug/GNU-Linux-x86/file-archiver-group11-csci222-master1.0.0`/file-archiver-group11-csci222-master1.0.0.tar.gz . && $(DEL_FILE) -r build/Debug/GNU-Linux-x86/file-archiver-group11-csci222-master1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) qttmp-Debug.mk


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_Archiver.cpp moc_GetComment.cpp moc_Retriever.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_Archiver.cpp moc_GetComment.cpp moc_Retriever.cpp
moc_Archiver.cpp: FileArchiver.h \
		VersionRec.h \
		FileRec.h \
		GetComment.h \
		Retriever.h \
		Archiver.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) Archiver.h -o moc_Archiver.cpp

moc_GetComment.cpp: GetComment.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) GetComment.h -o moc_GetComment.cpp

moc_Retriever.cpp: Retriever.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) Retriever.h -o moc_Retriever.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_Archiver.h ui_GetComment.h ui_Retriever.h
compiler_uic_clean:
	-$(DEL_FILE) ui_Archiver.h ui_GetComment.h ui_Retriever.h
ui_Archiver.h: Archiver.ui
	/usr/lib/x86_64-linux-gnu/qt4/bin/uic Archiver.ui -o ui_Archiver.h

ui_GetComment.h: GetComment.ui
	/usr/lib/x86_64-linux-gnu/qt4/bin/uic GetComment.ui -o ui_GetComment.h

ui_Retriever.h: Retriever.ui
	/usr/lib/x86_64-linux-gnu/qt4/bin/uic Retriever.ui -o ui_Retriever.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_uic_clean 

####### Compile

build/Debug/GNU-Linux-x86/Archiver.o: Archiver.cpp Archiver.h \
		FileArchiver.h \
		VersionRec.h \
		FileRec.h \
		GetComment.h \
		Retriever.h \
		ui_Archiver.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/Archiver.o Archiver.cpp

build/Debug/GNU-Linux-x86/GetComment.o: GetComment.cpp GetComment.h \
		ui_GetComment.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/GetComment.o GetComment.cpp

build/Debug/GNU-Linux-x86/Retriever.o: Retriever.cpp Retriever.h \
		ui_Retriever.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/Retriever.o Retriever.cpp

build/Debug/GNU-Linux-x86/main.o: main.cpp Archiver.h \
		FileArchiver.h \
		VersionRec.h \
		FileRec.h \
		GetComment.h \
		Retriever.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/main.o main.cpp

build/Debug/GNU-Linux-x86/FileArchiver.o: FileArchiver.cpp FileArchiver.h \
		VersionRec.h \
		FileRec.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/FileArchiver.o FileArchiver.cpp

build/Debug/GNU-Linux-x86/FileRec.o: FileRec.cpp FileRec.h \
		VersionRec.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/FileRec.o FileRec.cpp

build/Debug/GNU-Linux-x86/VersionRec.o: VersionRec.cpp VersionRec.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/VersionRec.o VersionRec.cpp

build/Debug/GNU-Linux-x86/moc_Archiver.o: moc_Archiver.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/moc_Archiver.o moc_Archiver.cpp

build/Debug/GNU-Linux-x86/moc_GetComment.o: moc_GetComment.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/moc_GetComment.o moc_GetComment.cpp

build/Debug/GNU-Linux-x86/moc_Retriever.o: moc_Retriever.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/moc_Retriever.o moc_Retriever.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

