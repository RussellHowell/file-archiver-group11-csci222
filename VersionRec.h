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
        //timespec structure to hold the data last modified, could be a string
 };
 
struct BlockInfo
{
    int number;
    char * hash;
    int length;
    // byte array (compressed data for the file block)
    unsigned char data[4000];
};

class VersionRec
{
    
private:
    QString version_id_; //generated primary key or "GENOID" in notes
    int version_num_;
    int length_; //number of elements in record_collections
    int mtsec_;
  
    char * hash;
    // hash member
    
    std::vector<BlockInfo> blocks; 
    //collection of blocks different in this version
    
public:
    VersionRec();
    std::string getVersionID();
    void setVersionID(QString);
    int getVersionNum();
    void setVersionNum(qint16);
    int getLength();
    void setLength(qint64);
    
    timestruc getModifyTime();
    void setModifyTime(timestruc);
    
    char * getHash();
    void setHash(char *);
    
    std::vector<block_info> getDiff();
    void setDiff(qint64, char*, qint64, unsigned char*); //add one block at a time, creates block_info structure within
    
    void transferToDB();
    void transferFromDB();
};


#endif	/* VERSIONREC_H */

