/*
 * Sukhdip Singh
 * 4806827
 * Assignment 1
 * Main file
 */

#include "archiver.h"
#include "getcomment.h"
#include "retriever.h"
#include "setreference.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Archiver w;
    w.show();

    return a.exec();
}
