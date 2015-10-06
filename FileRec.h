// *
// *
// * CSCI222
// * Group 11
// * 
// * Author(s): Jack Robert Humphreys
// * Last modified: September 28th, 2015
// * Description: 
// * Purpose:

#ifndef FILEREC_H
#define	FILEREC_H

#include "VersionRec.h"
#include <QFile> 
#include <QCryptographicHash>
#include <QString>
#include <fstream>

class FileRec
{
public:
    FileRec();
    std::string getFilename();
    void setFilename(std::string);
    std::string getCurhash();
    void setCurhash(std::string);
    std::string getOvhash();
    void setOvhash(std::string);
    int getCurrentversion();
    void setCurrentversion(int);
    int getNversions();
    void setNversions(int);
    int getLength();
    void setLength(int);
    int getMtsec();
    void setMtsec(int);
    int getMtnsec();
    void setMtnsec(int);
    int getBlobtableTempname();
    void setBlobtableTempname(int);
    std::vector<std::string> getBlktableHash();
    void setBlktableHash(std::vector<std::string>);
    std::vector<int> getBlktableLength();
    void setBlktableLength(std::vector<int>);
    std::vector<int> getIdversionrec();
    void setIdversionrec(std::vector<int>);
    std::vector<std::string> getCommenttxt();
    void setCommenttxt(std::vector<std::string>);
    
    void getData(sql::Connection*, std::string);
    void setData(sql::Connection*);
    
    void createData(std::string);
    VersionRec createVersionData(FileRec);
private:
    std::string filename_;
    std::string curhash_;
    std::string ovhash_;
    int currentversion_;
    int nversions_;
    int length_;
    int mtsec_;
    int mtnsec_;
    int blobtable_tempname_;
    std::vector<std::string> blktable_hashval_;
    std::vector<int> blktable_length_;
    std::vector<int> idversionrec_;
    std::vector<std::string> commenttxt_;
};

#endif
