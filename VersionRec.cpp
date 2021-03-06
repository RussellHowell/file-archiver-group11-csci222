// *
// *
// * CSCI222
// * Group 11
// * 
// * Author(s): Jack Robert Humphreys
// * Last modified: September 28th, 2015
// * Description: 
// * Purpose:

#include "VersionRec.h"
#include "cppconn/prepared_statement.h"
#include "cppconn/connection.h"
#include "cppconn/resultset.h"
#include <sstream>

VersionRec::VersionRec()
{
    
}

int VersionRec::getIdversionrec()
{
    return idversionrec_;
}

void VersionRec::setIdversionrec(int idversionrec)
{
    idversionrec_ = idversionrec;
}

std::string VersionRec::getFileref()
{
    return fileref_;
}

void VersionRec::setFileref(std::string fileref)
{
    fileref_ = fileref;
}

int VersionRec::getVersionnum()
{
    return versionnum_;
}

void VersionRec::setVersionnum(int versionnum)
{
    versionnum_ = versionnum;
}

int VersionRec::getLength()
{
    return length_;
}

void VersionRec::setLength(int length)
{
    length_ = length;
}

long VersionRec::getMtsec()
{
    return mtsec_;
}

void VersionRec::setMtsec(long mtsec)
{
    mtsec_ = mtsec;
}

long VersionRec::getMtnsec()
{
    return idversionrec_;
}

void VersionRec::setMtnsec(long mtnsec)
{
    mtnsec_ = mtnsec;
}

std::string VersionRec::getOvhash()
{
    return ovhash_;
}

void VersionRec::setOvhash(std::string ovhash)
{
    ovhash_ = ovhash;
}

std::vector<BlkTable> VersionRec::getBlktable()
{
    return blktable_;
}

void VersionRec::setBlktable(std::vector<BlkTable> blktable)
{
    blktable_ = blktable;
}

void VersionRec::getData(sql::Connection* conn, int idversionrec)
{
    sql::ResultSet *result = NULL;
    sql::PreparedStatement *prepared_statement = NULL;
    prepared_statement = conn->prepareStatement("SELECT * FROM versionrec WHERE idversionrec = ?");
    prepared_statement->setInt(1, idversionrec);
    result = prepared_statement->executeQuery();
    while(result->next())
    {
        idversionrec_ = result->getInt(1);
        fileref_ = result->getString(2);
        versionnum_ = result->getInt(3);
        length_ = result->getInt(4);
        mtsec_ = result->getInt(5);
        mtnsec_ = result->getInt(6);
        ovhash_ = result->getString(7);
    }
    prepared_statement = conn->prepareStatement("SELECT blknum, length, hash, data FROM blktable WHERE version = ?");
    prepared_statement->setInt(1, idversionrec);
    result = prepared_statement->executeQuery();
    while(result->next())
    {
        BlkTable temp_blk_table;
        temp_blk_table.blknum = result->getInt(1);
        temp_blk_table.length = result->getInt(2);
        temp_blk_table.hash = result->getString(3);
        temp_blk_table.data = (const char *)result->getBlob(4);
        blktable_.push_back(temp_blk_table);
    }
    delete result;
    delete prepared_statement;
}

void VersionRec::setData(sql::Connection* conn)
{
    sql::ResultSet *result = NULL;
    sql::PreparedStatement *prepared_statement = NULL;
    prepared_statement = conn->prepareStatement("INSERT INTO versionrec VALUES(?, ?, ?, ?, ?, ?, ?)");
    prepared_statement->setInt(1, ++counter_);
    prepared_statement->setString(2, fileref_);
    prepared_statement->setInt(3, versionnum_);
    prepared_statement->setInt(4, length_);
    prepared_statement->setInt(5, mtsec_);
    prepared_statement->setInt(6, mtnsec_);
    prepared_statement->setString(7, ovhash_);
    prepared_statement->executeQuery();
    /*prepared_statement = conn->prepareStatement("SELECT LAST_INSERT_ID()");
    result = prepared_statement->executeQuery();
    int version_id;
    while(result->next())
    {
        version_id = result->getInt(1);
    }*/
    for(std::vector<BlkTable>::iterator it1 = blktable_.begin(); it1 != blktable_.end(); ++it1)
    {
        sql::PreparedStatement *prepared_statement = conn->prepareStatement("INSERT INTO blktable VALUES(?, ?, ?, ?, ?)");
        prepared_statement->setInt(1, counter_);
        prepared_statement->setInt(2, it1->blknum);
        prepared_statement->setInt(3, it1->length);
        prepared_statement->setString(4, it1->hash);
        std::istringstream iss((const char *)qCompress(it1->data));
        prepared_statement->setBlob(5, &iss);
        prepared_statement->executeQuery();
    }
    delete result;
    delete prepared_statement;
}