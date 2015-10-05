// *
// *
// * CSCI222
// * Group 11
// * 
// * Author(s): Jack Robert Humphreys
// * Last modified: September 28th, 2015
// * Description: 
// * Purpose:

#include "FileArchiver.h"
#include "cppconn/exception.h"
#include "cppconn/prepared_statement.h"
#include <boost/iostreams/filtering_streambuf.hpp>
#include <boost/iostreams/copy.hpp>
#include <boost/iostreams/filter/gzip.hpp>

#include <cstdio>
#include <iostream>
#include <fstream>
#include <cstring>

const char *DB_EXCEPTION = "Database Failure! Operation failed. ";
const char *DB_SERVER = "tcp://127.0.0.1:3306";
const char *DB_USERNAME = "student26";
const char *DB_PASSWORD = "XMg5w6gW";
const char *DB_SCHEMA = "student26";

FileArchiver::FileArchiver()
{
    invalid_ = true;
    driver_ = get_driver_instance();
    try
    {
        
        conn_ = driver_->connect(DB_SERVER, DB_USERNAME, DB_PASSWORD);
    }
    catch(sql::SQLException &e)
    {
        return;
    }
    conn_->setSchema(DB_SCHEMA);
    invalid_ = false;
}

FileArchiver::~FileArchiver()
{
    if(!invalid_)
    {
        conn_->close();
        delete conn_;
    }
    invalid_ = true;
}

FileArchiver::FileArchiver(const FileArchiver& right_operand):conn_(right_operand.conn_), driver_(right_operand.driver_), invalid_(right_operand.invalid_)
{

}

FileArchiver& FileArchiver::operator=(const FileArchiver& right_operand)
{
    if(!right_operand.invalid_)
    {
        conn_ = right_operand.conn_;
        driver_ = right_operand.driver_;
        invalid_ = !right_operand.invalid_;
    }
    return *this;
}

bool FileArchiver::good()
{
    return (!invalid_);
}

bool FileArchiver::exists(std::string file_name)
{
    if(invalid_)
    {
        throw (DB_EXCEPTION);
    }
    int count;
    sql::ResultSet *result = NULL;
    sql::PreparedStatement *prepared_statement = NULL;
    prepared_statement = conn_->prepareStatement("SELECT COUNT(*) FROM filerec WHERE filename = ?");
    prepared_statement->setString(1, file_name);
    result = prepared_statement->executeQuery();
    while(result->next())
    {
        count = result->getInt(1);
    }
    delete result;
    delete prepared_statement;
    return count == 1;
}

bool FileArchiver::differs(std::string file_name)
{
    if(invalid_)
    {
        throw (DB_EXCEPTION);
    }
    FileRec temp_file;
    temp_file.createData(file_name);
    sql::ResultSet *result = NULL;
    sql::PreparedStatement *prepared_statement = NULL;
    prepared_statement = conn_->prepareStatement("SELECT curhash FROM filerec WHERE filename = ?");
    prepared_statement->setString(1, file_name);
    result = prepared_statement->executeQuery();
    std::string temp_result, temp_hash(temp_file.getCurhash());
    while(result->next())
    {
        temp_result = result->getString(1);
    }
    delete result;
    delete prepared_statement;
    return temp_hash == temp_result;
}


void FileArchiver::insertNew(std::string file_name, std::string comment)
{
    if(invalid_)
    {
        throw (DB_EXCEPTION);
    }
    FileRec temp_file;
    temp_file.createData(file_name);
    std::vector<std::string> temp_commenttxt = temp_file.getCommenttxt();
    temp_commenttxt.push_back(comment);
    temp_file.setCommenttxt(temp_commenttxt);
    std::string zipped_file = createZipFile(file_name);
    sql::ResultSet *result = NULL;
    sql::PreparedStatement *prepared_statement = NULL;
    prepared_statement = conn_->prepareStatement("INSERT INTO blobtable VALUES(?)");
    std::ifstream blob_file;
    blob_file.open(zipped_file.c_str(), std::ios::in | std::ios::binary);
    prepared_statement->setBlob(1, &blob_file);
    prepared_statement->executeQuery();
    blob_file.close();
    prepared_statement = conn_->prepareStatement("SELECT LAST_INSERT_ID()");
    result = prepared_statement->executeQuery();
    while(result->next())
    {
        temp_file.setBlobtableTempname(result->getInt(1));
    }
    temp_file.setData(conn_);
    delete result;
    delete prepared_statement;

    std::remove(zipped_file.c_str());
}

void FileArchiver::update(std::string file_name)
{
    FileRec current_save = getDetailsOfLastSaved(file_name);
    FileRec temp_file;
    VersionRec temp_version;
    temp_version = temp_file.createVersionData(current_save);
    if(invalid_)
    {
        throw (DB_EXCEPTION);
    }
    temp_version.setData(conn_);
    sql::PreparedStatement *prepared_statement = NULL;
    prepared_statement = conn_->prepareStatement("UPDATE filerec SET nversions = nversions + 1, curhash = ?, length = ? WHERE filename = ?");
    prepared_statement->setInt(1, temp_version.getOvhash());
    prepared_statement->setInt(2, temp_version.getLength());
    prepared_statement->setString(3, file_name);
    prepared_statement->executeQuery();
}

void FileArchiver::retrieveVersion(std::string file_name, int version_num, std::string target)
{
    if(invalid_)
    {
        throw (DB_EXCEPTION);
    }
    FileRec temp_file;
    temp_file.getData(conn_, file_name);
    std::vector<int> version_ids = temp_file.getIdversionrec();
    sql::ResultSet *result = NULL;
    sql::PreparedStatement *prepared_statement = NULL;
    prepared_statement = conn_->prepareStatement("SELECT blobtable_tempname, length FROM filerec WHERE filename = ?");
    prepared_statement->setString(1, file_name);
    result = prepared_statement->executeQuery();
    result->next();
    int length = result->getInt(2);
    prepared_statement = conn_->prepareStatement("SELECT filedata FROM blobtable WHERE tempname = ?");
    prepared_statement->setString(1, result->getString(1));
    result = prepared_statement->executeQuery();
    result->next();
    std::istream *blob;
    blob = result->getBlob(1);
    std::vector<char> buffer(length, '\0');
    blob->read(&buffer[0], buffer.size());  
    std::ofstream zipped_file;
    zipped_file.open((target + ".gz").c_str(), std::ios::out | std::ios::binary);
    zipped_file.write(&buffer[0], buffer.size());
    zipped_file.close();
    
    unzipFile(target + ".gz");
    std::remove((target + ".gz").c_str());
    
    VersionRec temp_version;
    std::ifstream old_file;
    std::ofstream new_file;
    int pos;
    for(std::vector<int>::iterator it1 = version_ids.begin(); *it1 != version_num; ++it1)
    {
        old_file.open(target.c_str(), std::ios::in | std::ios::binary);
        new_file.open("temp", std::ios::out | std::ios::binary);
        temp_version.getData(conn_, *it1);
        std::vector<int>::iterator posit = temp_file.getBlktableLength().begin();
        old_file.seekg(0, std::ios::beg);
        for(std::vector<BlkTable>::iterator it2 = temp_version.getBlktable().begin(); it2 != temp_version.getBlktable().end(); ++it2)
        {
            it2->data = qUncompress(it2->data);
            
            pos = 0;
            for(; posit != (temp_file.getBlktableLength().end() + it2->blknum); ++posit)
            {
                pos += *posit;
            }
            
            old_file.seekg(pos, std::ios::cur);

            if(it2->length != 0)
            {
                new_file.write(it2->data, it2->length);
                temp_file.setLength(temp_file.getLength() + 1);
                std::vector<std::string> temp_blktable_hash = temp_file.getBlktableHash();
                std::vector<int> temp_blktable_length = temp_file.getBlktableLength();
                temp_blktable_hash.insert((temp_blktable_hash.begin() + it2->blknum), it2->hash);
                temp_blktable_length.insert((temp_blktable_length.begin() + it2->blknum), it2->length);
                temp_file.setBlktableHash(temp_blktable_hash);
                temp_file.setBlktableLength(temp_blktable_length);
                for(std::vector<BlkTable>::iterator it3 = it2; it3 != temp_version.getBlktable().end(); ++it3)
                {
                    ++(it3->blknum);
                }
            }
            else
            {
                old_file.seekg(*posit, std::ios::cur);
                temp_file.setLength(temp_file.getLength() - 1);
                std::vector<std::string> temp_blktable_hash = temp_file.getBlktableHash();
                std::vector<int> temp_blktable_length = temp_file.getBlktableLength();
                temp_blktable_hash.erase(temp_blktable_hash.begin() + it2->blknum);
                temp_blktable_length.erase(temp_blktable_length.begin() + it2->blknum);
                temp_file.setBlktableHash(temp_blktable_hash);
                temp_file.setBlktableLength(temp_blktable_length);
                for(std::vector<BlkTable>::iterator it3 = it2; it3 != temp_version.getBlktable().end(); ++it3)
                {
                    --(it3->blknum);
                }
            }
            old_file.close();
            new_file.close();
            std::remove(target.c_str());
            std::rename("temp", target.c_str());
        }
    }
}

std::string FileArchiver::getComment(std::string file_name, int version_num)
{
    if(invalid_)
    {
        throw (DB_EXCEPTION);
    }
    sql::ResultSet *result = NULL;
    sql::PreparedStatement *prepared_statement = NULL;
    prepared_statement = conn_->prepareStatement("SELECT commenttext FROM commentsteble WHERE filename = ? AND commentnum = ?");
    prepared_statement->setString(1, file_name);
    prepared_statement->setInt(2, version_num);
    result = prepared_statement->executeQuery();
    std::string temp_comment;
    while(result->next())
    {
        temp_comment = result->getString(1);
    }
    delete result;
    delete prepared_statement;
    return temp_comment;
}

std::vector<VersionInfo> FileArchiver::getVersionInfo(std::string file_name)
{
    if(invalid_)
    {
        throw (DB_EXCEPTION);
    }
    FileRec temp_file;
    VersionInfo temp_info;
    temp_file.getData(conn_, file_name);
    std::vector<VersionInfo> info;
    temp_info.versionnum = 0;
    temp_info.length = temp_file.getLength();
    temp_info.mtsec = temp_file.getMtsec();
    temp_info.mtnsec = temp_file.getMtnsec();
    info.push_back(temp_info);

    std::vector<int> version_ids = temp_file.getIdversionrec();
    sql::ResultSet *result = NULL;
    sql::PreparedStatement *prepared_statement = NULL;
    for(std::vector<int>::iterator it = version_ids.begin(); it != version_ids.end(); ++it)
    {
        prepared_statement = conn_->prepareStatement("SELECT versionnum, length, mtsec, mtnsec FROM versionrec WHERE versionid = ?");
        prepared_statement->setInt(1, *it);
        result = prepared_statement->executeQuery();
        if(result->next())
        {
            temp_info.versionnum = result->getInt(1);
            temp_info.length = result->getInt(2);
            temp_info.mtsec = result->getInt(3);
            temp_info.mtnsec = result->getInt(4);
            info.push_back(temp_info);
        }
    }
    delete prepared_statement;
    delete result;
    return info;
}

FileRec FileArchiver::getDetailsOfLastSaved(std::string file_name)
{
    FileRec temp_file;
    VersionRec temp_version;
    if(invalid_)
    {
        throw (DB_EXCEPTION);
    }
    temp_file.getData(conn_, file_name);
    std::vector<int> version_ids = temp_file.getIdversionrec();
    for(std::vector<int>::iterator it1 = version_ids.begin(); it1 != version_ids.end(); ++it1)
    {
        temp_version.getData(conn_, *it1);
        for(std::vector<BlkTable>::iterator it2 = temp_version.getBlktable().begin(); it2 != temp_version.getBlktable().end(); ++it2)
        {
            if(it2->length == 0)
            {
                temp_file.setLength(temp_file.getLength() + 1);
                std::vector<std::string> temp_blktable_hash = temp_file.getBlktableHash();
                std::vector<int> temp_blktable_length = temp_file.getBlktableLength();
                temp_blktable_hash.insert((temp_blktable_hash.begin() + it2->blknum), it2->hash);
                temp_blktable_length.insert((temp_blktable_length.begin() + it2->blknum), it2->length);
                temp_file.setBlktableHash(temp_blktable_hash);
                temp_file.setBlktableLength(temp_blktable_length);
                for(std::vector<BlkTable>::iterator it3 = it2; it3 != temp_version.getBlktable().end(); ++it3)
                {
                    ++(it3->blknum);
                }
            }
            else
            {
                temp_file.setLength(temp_file.getLength() - 1);
                std::vector<std::string> temp_blktable_hash = temp_file.getBlktableHash();
                std::vector<int> temp_blktable_length = temp_file.getBlktableLength();
                temp_blktable_hash.erase(temp_blktable_hash.begin() + it2->blknum);
                temp_blktable_length.erase(temp_blktable_length.begin() + it2->blknum);
                temp_file.setBlktableHash(temp_blktable_hash);
                temp_file.setBlktableLength(temp_blktable_length);
                for(std::vector<BlkTable>::iterator it3 = it2; it3 != temp_version.getBlktable().end(); ++it3)
                {
                    --(it3->blknum);
                }
            }
        }
    }
    return temp_file;
}

void FileArchiver::setReference(std::string file_name, int versionnum, std::string comment)
{
    if(invalid_)
    {
        throw (DB_EXCEPTION);
    }
    retrieveVersion(file_name, versionnum, file_name + ".tmp");
    FileRec temp_file;
    temp_file.getData(conn_, file_name);
    std::vector<int> version_ids = temp_file.getIdversionrec();
    VersionRec temp_version;
    std::vector<VersionRec> versions;
    for(std::vector<int>::iterator it1 = version_ids.begin(); it1 != version_ids.end(); ++it1)
    {
        temp_version.getData(conn_, *it1);
        if(temp_version.getVersionnum() > versionnum)
        {
            versions.push_back(temp_version);
        }
    }
    sql::PreparedStatement *prepared_statement = NULL;
    prepared_statement = conn_->prepareStatement("DELETE FROM blobtable WHERE tempname = ?");
    prepared_statement->setInt(1, temp_file.getBlobtableTempname());
    prepared_statement->executeQuery();
    insertNew(file_name + ".tmp", comment);
    prepared_statement = conn_->prepareStatement("UPDATE filerec SET filename = ? WHERE filename = ?");
    prepared_statement->setString(1, file_name);
    prepared_statement->setString(2, file_name + ".tmp");
    prepared_statement->executeQuery();
    for(std::vector<VersionRec>::iterator it1 = versions.begin(); it1 != versions.end(); ++it1)
    {
        it1->setData(conn_);
    }
    std::remove((file_name + ".tmp").c_str());
}

std::string FileArchiver::createZipFile(std::string file_name)
{
    std::ifstream file;
    file.open(file_name.c_str(), std::ios::in | std::ios::binary);
    file.seekg(0, file.beg);
    boost::iostreams::filtering_streambuf<boost::iostreams::input> in;
    in.push(boost::iostreams::gzip_compressor());
    in.push(file);
    std::ofstream zipped_file;
    zipped_file.open((file_name + ".gz").c_str(), std::ios::out | std::ios::binary);
    boost::iostreams::copy(in, zipped_file);
    return file_name + ".gz";
}

std::string FileArchiver::unzipFile(std::string file_name)
{
    std::ifstream file;
    file.open(file_name.c_str(), std::ios::in | std::ios::binary);
    file.seekg(0, file.beg);
    boost::iostreams::filtering_streambuf<boost::iostreams::input> in;
    in.push(boost::iostreams::gzip_decompressor());
    in.push(file);
    int index = file_name.find_last_of("."); 
    std::ofstream unzipped_file;
    unzipped_file.open(file_name.substr(0, index).c_str(), std::ios::out | std::ios::binary);
    boost::iostreams::copy(in, unzipped_file);
    return file_name.substr(0, index);
}


