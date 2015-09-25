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

const char* DB_EXCEPTION = "";
const char* DB_SERVER = "";
const char* DB_USERNAME = "";
const char* DB_PASSWORD = "";

FileArchiver::FileArchiver()
{
    invalid_ = true;
    driver_ = get_driver_instance();
    try
    {
        conn = driver_->connect(DB_SERVER, DB_USERNAME, DB_PASSWORD);
    }
    catch(sql::SQLException &e)
    {
        return;
    }
    conn_->setSchema("");
    invalid_ = false;
}

FileArchiver::~FileArchiver()
{
    if(!invalid_)
    {
        dbcon_->close();
        delete conn_;
    }
    invalid_ = true;
}

FileArchiver::FileArchiver(const FileArchiver& right_operand):conn_(right_operand.conn_), driver_(right_operand.driver_), invalid_(right_operand.invalid_)
{

}

FileArchiver& FileArchiver::operator=(const FileArchiver& right_operand)
{
    if(!right_operand->invalid_)
    {
        conn_ = right_operand.conn_;
        driver_ = right_operand.driver_;
        invalid_ = !right_operand.invalid_;
    }
    return *this;
}

bool FileArchiver::good()
{
    return (!this->invalid_);
}

bool FileArchiver::exists(std::string file_name)
{
    if(invalid_)
    {
        throw (DB_EXCEPTION);
    }
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
    if(invalid_)
    {
        throw (DB_EXCEPTION);
    }
    FileRec temp_file;
    temp_file.createData(file_name);
    sql::ResultSet *result = NULL;
    sql::PreparedStatement prepared_statement = conn_->prepareStatement("SELECT curhash FROM filerec WHERE filename = ?");
    prepared_statement->setString(1, file_name);
    result = prepared_statement->executeQuery();
    std::string temp_hash(temp_file.getHash().data()), temp_result(result->getString(1));
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
    temp_file.addComment(comment);
    //TODO gzip
    sql::ResultSet *result = NULL;
    sql::PreparedStatement prepared_statement = conn_->prepareStatement("INSERT INTO blobtable VALUES(?)");
    std::ifstream blob_file(/*TODO zipped*/file_name, std::ios::binary);
    prepared_statement->setBlob(1, &blob_file);
    result = prepared_statement->execute();
    blob_file.close();
    temp_file.setTempName(temp_name_);
    temp_file.setData(conn_);
    delete result;
    delete prepared_statement;

    //TODO delete gzip file
}

std::vector<VersionInfo> *getVersionInfo(std::string file_name)
{
    if(invalid_)
    {
        throw (DB_EXCEPTION);
    }
    FileRec temp_file;
    VersionInfo temp_info;
    temp_file.getData(conn_, file_name);
    std::vector<VersionInfo> *ptr = new std::vector<FileRec>();
    temp_info.length = temp_file.getLength();
    temp_info.mtsec = temp_file.getMtsec();
    temp_info.mtnsec = temp_file.getMtnsec();
    ptr->push_back(temp_info);

    std::vector<std::string> version_ids = temp_file.getVersions();
    sql::ResultSet *result = NULL;
    for(std::vector<std::string>::iterator it = version_ids.begin(); it != version_ids.end(); ++it)
    {
        sql::PreparedStatement prepared_statement = conn_->prepareStatement("SELECT length, mtsec, mtnsec FROM versionrec WHERE versionid = ?");
        prepared_statement->setString(1, *it);
        result = prepared_statement->execute();
        //TODO get data from result
        if(result->next())
        {
            temp_info.length = result.getLong(1)
            temp_info.mtsec = result.getLong(2)
            temp_info.mtnsec = result.getLong(3)
            ptr->push_back(temp_info);
        }
    }
    delete result;
    delete prepared_statement;
    return ptr;
}

void FileArchiver::update(std::string file_name)
{
    if(invalid_)
    {
        throw (DB_EXCEPTION);
    }
    FileRec temp_file = this->getDetailsOfLastSaved(file_name);
}


void FileArchiver::getDetailsOfLastSaved(std::string file_name)
{
    if(invalid_)
    {
        throw (DB_EXCEPTION);
    }
    FileRec temp_file;
    temp_file.getData(conn_, file_name);
}

FileRec FileArchiver::retriveVersion(std::string file_name, )
{
    if(invalid_)
    {
        throw (DB_EXCEPTION);
    }

}

