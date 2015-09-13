// *
// *
// * CSCI222
// * Group 11
// * 
// * Author(s): Danielle Cerisier 
// * Last modified: September 9th, 2015
// * Description:
// * Purpose:
#include <QtCore/QCoreApplication>
#include <QApplication>
#include <QFile>
#include <QDebug> 

#include <vector>

#ifndef VERSIONREC_H
#define	VERSIONREC_H

 struct timestruc
 {
        //timespec structure, as in FileRec.h
 };
 
struct block_info
{
    qint64 block_num;
    char * hash;
    qint64 block_length;
    // byte array (compressed data for the file block)
    char * byte_array;
};

class VersionRec
{
    
private:
    QString version_ID; //generated primary key or "GENOID" in notes
    qint16 version_num;
    qint64 length; //number of elements in record_collections
    timestruc modify_time;
  
    char * hash;
    // hash member
    
    std::vector<block_info> blocks; 
    //collection of blocks different in this version
    
public:
    VersionRec();
    QString getVersionID();
    void setVersionID(QString);
    qint16 getVersionNum();
    void setVersionNum(qint16);
    qint64 getLength();
    void setLength(qint64);
    
    timestruc getModifyTime();
    void setModifyTime(timestruc);
    
    char * getHash();
    void setHash(char *);
    
    std::vector<block_info> getDiff();
    void setDiff(qint64, char*, qint64, char*); //add one block at a time, creates block_info structure within
    
    void transferToDB();
    void transferFromDB();
};


#endif	/* VERSIONREC_H */

