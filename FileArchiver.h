// *
// *
// * CSCI222
// * Group 11
// * 
// * Author(s): Jack Robert Humphreys
// * Last modified: September 28th, 2015
// * Description:
// * Purpose:

#ifndef FILEARCHIVER_H
#define	FILEARCHIVER_H

#include "VersionRec.h"
#include "FileRec.h"
#include "mysql_driver.h"
#include "cppconn/driver.h"

struct VersionInfo
{
    int versionnum;
    int length;
    int mtsec;
    int mtnsec;
};

class FileArchiver
{
public:
    FileArchiver();
    
    ~FileArchiver();
    
    bool good();
    
    bool exists(std::string);
    bool differs(std::string);
    
    void insertNew(std::string, std::string);
    void update(std::string);
    void retrieveVersion(std::string, int, std::string);
    
    std::string getComment(std::string, int);
    std::vector<VersionInfo> getVersionInfo(std::string);
    
    void setReference(std::string, int, std::string);
private:
    FileArchiver(const FileArchiver&);
    FileArchiver& operator=(const FileArchiver&);
    
    FileRec getDetailsOfLastSaved(std::string);
    
    std::string createZipFile(std::string);
    std::string unzipFile(std::string);

    sql::Connection *conn_;
    sql::Driver *driver_;
    bool invalid_;
};

#endif
