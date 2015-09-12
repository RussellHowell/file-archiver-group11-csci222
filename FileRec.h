// *
// *
// * CSCI222
// * Group 11
// * 
// * Author(s): Russell Howell 
// * Last modified: September 6th, 2015
// * Description:
// * Purpose:

#include <QtCore/QCoreApplication>
#include <QApplication>
#include <QFile>
#include <QDebug> 
#include <fstream>
#include <QByteArray>



#ifndef FILEREC_H
#define	FILEREC_H


class FileRec
{
private:
    QString file_name_;
    QString temp_name_; //name of BLOB record
    qint64 size_; //length of the file in bytes
    qint16 number_of_versions_; 
    
    struct modify_time
    {
        //timespec structure
    };
    
public:
    FileRec();
    QString getName();
    QString getModifyTime();
    qint64 getLength();
    qint16 getVersionCount();
    void createData(QString path);
    
};


#endif	/* FILEREC_H */

