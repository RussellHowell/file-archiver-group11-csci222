/*
 * File:   main.cpp
 * Author: russell
 *
 * Created on 3 September 2015, 12:06 AM
 */

#include <QApplication>
#include "FileRec.h"
#include "archiver.h"
#include "getcomment.h"
#include "retriever.h"
#include "setreference.h"


int main(int argc, char *argv[]) {
    // initialize resources, if needed
    // Q_INIT_RESOURCE(resfile);

    QApplication app(argc, argv);
    Archiver w;
    w.show();
  
    // create and show your widgets here

    return app.exec();
}
