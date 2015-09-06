// *
// *
// * CSCI222
// * Group 11
// * 
// * Author(s): Russell Howell 
// * Last modified: September 5th, 2015
// * Description:
// * Purpose:
#include <QtCore/QCoreApplication>
#include <QApplication>
#include <QFile>
#include <QDebug> 

#ifndef FILEARCHIVER_H
#define	FILEARCHIVER_H

class FileArchiver
{
    
private:
   qint16 identifier;
public:
    FileArchiver();
    bool differs(QString file_name);
    bool exists(QString file_name);
    void insertNew(QString file_name, QString comment);
    void update(QString file_name, QString comment);
    //VersionRec retrieveVersion(int version_num, QString file_name, QString retrieve_to_filename);
    
};



#endif	/* FILEARCHIVER_H */

