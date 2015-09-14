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

std::vector<block_info> VersionRec::getDiff()
{
    return blocks;
};

void VersionRec::setDiff(qint64 num, char * hash, qint64 length, unsigned char * bytes)
{
    blocks.push_back(block_info());
    blocks[blocks.size()-1].block_num = num;
    blocks[blocks.size()-1].hash = hash;
    blocks[blocks.size()-1].block_length = length;
    blocks[blocks.size()-1].byte_array = bytes;
    
};

 // setDiff

void VersionRec::transferFromDB()
{
    
};

void VersionRec::transferToDB()
{
    
};


