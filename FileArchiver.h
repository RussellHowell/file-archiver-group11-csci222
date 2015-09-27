// *
// *
// * CSCI222
// * Group 11
// * 
// * Author(s): Russell Howell 
// * Last modified: September 5th, 2015
// * Description:
// * Purpose:

#ifndef FILEARCHIVER_H
#define	FILEARCHIVER_H

#include "FileRec.h"
#include "mysql_connection.h"
#include "mysql_driver.h"

#include <string>

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

    bool exists(std::string);
    bool differs(std::string);
    void insertNew(std::string, std::string);
    void update(std::string, std::string);
    VersionRec retrieveVersion(int version_num, QString file_name, QString retrieve_to_filename);
    getCurrentVersion(std::string);
    getHashOfLastSaved(std::string);
    bool getComment(std::string, int, std::string&);
    getVersionInfo(std::string);
    setReference(std::string, in, std::string);

    bool good();
private:
    FileArchiver(const FileArchiver&);
    FileArchiver operator=(const FileArchiver&);

    sql::Connection *conn_;
    sql::Driver *driver_;
    bool invalid_;
};



#endif

