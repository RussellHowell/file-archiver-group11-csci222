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

Qstring VersionRec::getVersionID()
{
    return version_ID;
};

void VersionRec::setVersionID(Qstring id)
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
}

 // getHash
 // setHash
 // getDiff
 // setDiff

VersionRec::transferFromDB()
{
    
};

VersionRec::transferToDB()
{
    
};


