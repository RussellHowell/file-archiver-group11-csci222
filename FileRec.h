// *
// *
// * CSCI222
// * Group 11
// * 
// * Author(s): Russell Howell 
// * Last modified: September 13th, 2015
// * Description:
// * Purpose:

#include <QtCore/QCoreApplication>
#include <QApplication>
#include <QFile>
#include <QDebug> 
#include <fstream>
#include <vector>
#include <ctime>
#include <QCryptographicHash>
#include <QString>
#include <QByteArray>



#ifndef FILEREC_H
#define	FILEREC_H


class FileRec
{
public:
   FileRec();
   
   void createData(QString path);
   
   QString getName();
   QString getModifyTime();
   qint64 getLength();
   qint16 getVersionCount();
   int getRefNumber();
   QByteArray getFileHash(); 
   std::vector<QByteArray> getBlockHashes();
   std::vector<int> getVersions();
   std::vector<std::string> getComments();
   
    
private:
    QString file_name_;
    QString temp_name_; //name of BLOB record
    QByteArray file_hash_;
    qint64 size_; //length of the file in bytes
    qint16 number_of_versions_; 
    int ref_number_;
     std::vector<QByteArray> block_hashes_; // store lengths also
     std::vector<int> version_ids_;
     std::vector<std::string> comments_;
    void readBlocks(const QFile&);
    
    struct modify_time_
    {
        int day, month, year, hour, minute, second;
    }timespec_;
    
    
};


#endif	/* FILEREC_H */

