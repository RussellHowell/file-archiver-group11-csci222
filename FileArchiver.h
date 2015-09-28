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

#include "mysql_connection.h"
#include "mysql_driver.h"
#include "cppconn/driver.h"
#include "cppconn/exception.h"
#include "cppconn/prepared_statement.h"

#include <vector>
#include <string>
#include <stdlib.h>

struct VersionInfo
{
    int id;
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
    void update(std::string, std::string);
    void retrieveVersion(int, std::string, std::string);
    
    std::string getComment(std::string, int);
    std::vector<VersionInfo> getVersionInfo(std::string);
    
    void setReference(std::string, int, std::string);

    
private:
    FileArchiver(const FileArchiver&);
    FileArchiver operator=(const FileArchiver&);
    
    FileRec getDetailsOfLastSaved(std::string);
    
    std::string createZipFile(std::string);
    std::string unzipFile(std::string);
    //blocks

    sql::Connection *conn_;
    sql::Driver *driver_;
    bool invalid_;
};



#endif

