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

#ifndef VERSIONREC_H
#define	VERSIONREC_H

 struct timestruc
 {
        //timespec structure, as in FileRec.h
 };

class VersionRec
{
    
private:
    QString version_ID; //generated primary key or "GENOID" in notes
    qint16 version_num;
    qint64 length; //number of elements in record_collections
    timestruc modify_time;
  
    
    // hash member
    
    // STL collection of blocks
        // struct block
            // qint64 block_num
            // block hash
            // qint64 block_length
            // byte array (compressed data for the file block)
    
public:
    VersionRec();
    Qstring getVersionID();
    void setVersionID(Qstring);
    qint16 getVersionNum();
    void setVersionNum(qint16);
    qint64 getLength();
    void setLength(qint64);
    modify_time getModifyTime();
    void setModifyTime(timestruc);
    // getHash
    // setHash
    // getDiff
    // setDiff
    
    void transferToDB();
    void transferFromDB();
};


#endif	/* VERSIONREC_H */

