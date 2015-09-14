// *
// *
// * CSCI222
// * Group 11
// * 
// * Author(s): Russell Howell
// * Last modified: September 5th, 2015
// * Description: 
// * Purpose:

#include "FileArchiver.h"

FileArchiver::FileArchiver()
{
    driver_ = get_driver_instance();
    try
    {
        conn = driver_->connect("", "", "");
    }
    catch(sql::SQLException &e)
    {
        return;
    }
    conn_->setSchema("");
    increment_ = 0;

};

bool FileArchiver::exists(std::string file_name)
{
    int count;
    sql::ResultSet *result = NULL;
    sql::PreparedStatement exists_tatement = conn_->prepareStatement("SELECT COUNT(*) FROM filerec WHERE filename = ?");
    exists_statement->setString(1, file_name);
    result = exists_statement->executeQuery();
    if(result->next())
    {
        count = result->getInt();
    }
    delete result;
    delete exists_statement;
    return count == 1;
}

bool FileArchiver::differs(std::string file_name)
{
    FileRec temp_file;
    temp_file.createData(file_name);
    sql::ResultSet *result = NULL;
    sql::PreparedStatement differs_statement = conn_->prepareStatement("SELECT curhash FROM filerec WHERE filename = ?");
    differs_statement->setString(1, file_name);
    result = differs_statement->executeQuery();
    delete result;
    delete differs_statement;
    return temp_file.getHash() == result;
}


void FileArchiver::insertNew(std::string file_name, std::string comment)
{
    FileRec temp_file;
    temp_file.createData(file_name);
    file_name.addComment(comment);
    this->generateTempName();
    //TODO gzip
    conn_->prepareStatement("INSERT INTO blobtable VALUES(?, ?)");
    std::ifstream blob_file(file_name, std::ios::binary);
    prepared_statement->setString(1, temp_name_);
    prepared_statement->setBlob(2, &blob_file);
    prepared_statement->execute();
    blob_file.close();
    temp_file.setTempName(temp_name_);
    conn_ << temp_file;

    //TODO delete gzip
}


