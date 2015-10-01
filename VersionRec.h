// *
// *
// * CSCI222
// * Group 11
// * 
// * Author(s): Jack Robert Humphreys
// * Last modified: September 28th, 2015
// * Description: 
// * Purpose:

#ifndef VERSIONREC_H
#define	VERSIONREC_H

#include "mysql_connection.h"
#include "cppconn/connection.h"
//#include <QtCore/QCoreApplication>
#include <QByteArray>
#include <vector>
#include <string>
#include <cstdlib>
 
struct BlkTable
{
    int blknum;
    int length;
    std::string hash;
    QByteArray data;
};

class VersionRec
{
public:
    VersionRec();
    
    int getIdversionrec();
    void setIdversionrec(int);
    std::string getFileref();
    void setFileref(std::string);
    int getVersionnum();
    void setVersionnum(int);
    int getLength();
    void setLength(int);
    int getMtsec();
    void setMtsec(int);
    int getMtnsec();
    void setMtnsec(int);
    std::string getOvhash();
    void setOvhash(std::string);
    std::vector<BlkTable> getBlktable();
    void setBlktable(std::vector<BlkTable>);
    
    void getData(sql::Connection*, int);
    void setData(sql::Connection*);
private:
    int idversionrec_;
    std::string fileref_;
    int versionnum_;
    int length_;
    int mtsec_;
    int mtnsec_;
    std::string ovhash_;
    std::vector<BlkTable> blktable_;
};

#endif
