// *
// *
// * CSCI222
// * Group 11
// * 
// * Author(s): Danielle Cerisier 
// * Last modified: September 9th, 2015
// * Description:
// * Purpose:

#include "VersionRec.h"

VersionRec::VersionRec()
{
    
};

QString VersionRec::getVersionID()
{
    return version_ID;
};

void VersionRec::setVersionID(QString id)
{
    version_ID = id;
};

qint16 VersionRec::getVersionNum()
{
    return version_num;
};

void VersionRec::setVersionNum(qint16 num)
{
    version_num = num;
};

qint64 VersionRec::getLength()
{
    return length;
};
      
void VersionRec::setLength(qint64 len)
{
    length = len;
};

timestruc VersionRec::getModifyTime()
{
    return modify_time; //incomplete?
};

void VersionRec::setModifyTime(timestruc)
{
    // ...
};

char * VersionRec::getHash()
{
    return hash;
};

void VersionRec::setHash(char * in)
{
    hash = in;
};


 // getDiff
/*
std::vector<block_info> VersionRec::getDiff()
{
   
};*/

 // setDiff

void VersionRec::transferFromDB()
{
    
};

void VersionRec::transferToDB()
{
    
};


