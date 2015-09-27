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
    sql::PreparedStatement prepared_statement = conn_->prepareStatement("SELECT COUNT(*) FROM filerec WHERE filename = ?");
    prepared_statement->setString(1, file_name);
    result = prepared_statement->executeQuery();
    if(result->next())
    {
        count = result->getInt();
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
    sql::PreparedStatement prepared_statement = conn_->prepareStatement("SELECT curhash FROM filerec WHERE filename = ?");
    prepared_statement->setString(1, file_name);
    result = prepared_statement->executeQuery();
    std::string temp_hash(temp_file.getHash().data()), temp_result(result->getString(1));
    delete result;
    delete prepared_statement;
    return temp_hash == temp_result;
}


bool FileArchiver::insertNew(std::string file_name, std::string comment)
{
    if(invalid_)
    {
        throw (DB_EXCEPTION);
    }
    FileRec temp_file;
    temp_file.createData(file_name);
    if(!this->exists(file_name))
    {
        temp_file.addComment(comment);
        std::string zipped_file = createZipFile(file_name)
        sql::ResultSet *result = NULL;
        sql::PreparedStatement prepared_statement = conn_->prepareStatement("INSERT INTO blobtable VALUES(?)");
        std::ifstream blob_file(zipped_file, std::ios::binary);
        prepared_statement->setBlob(1, &blob_file);
        prepared_statement->execute();
        blob_file.close();
        prepared_statement = conn_->prepareStatement("SELECT LAST_INSERT_ID()");
        result = prepared_statement->execute();
        temp_file.setTempName(result.getInt(.getInt()));
        temp_file.setData(conn_);
        delete result;
        delete prepared_statement;

        //TODO shell << "rm " << zipped_file;
        return 0;
    }
    return 1;
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
    temp_info.id = temp_file.getRefID();
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
        if(result->next())
        {
            temp_info.id = *it;
            temp_info.length = result.getInt(1)
            temp_info.mtsec = result.getInt(2)
            temp_info.mtnsec = result.getInt(3)
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
    FileRec current_save = this->getDetailsOfLastSaved(file_name);
    FileRec temp_file;
    VersionRec temp_version = temp_file.createUpdateData(current_save);//algorithm within filerec VersionRec FileRec::createUpdateData(FileRec old);

    sql::ResultSet *result = NULL;
    sql::PreparedStatement prepared_statement = conn_->prepareStatement("INSERT INTO filerec VALUES(?, ?, ?, ?, ?, ?)");
    prepared_statement->setString(1, file_name);
    prepared_statement->setInt(2, temp_file.getVersions());//not +1 as first version is 0
    prepared_statement->setInt(3, temp_version.getLength());
    prepared_statement->setInt(4, temp_version.getMtsec());
    prepared_statement->setInt(5, temp_version.getMtnsec());
    prepared_statement->setInt(6, temp_version.getHash());
    prepared_statement->execute();
    prepared_statement = conn_->prepareStatement("SELECT LAST_INSERT_ID()");
    result = prepared_statement->execute();
    for(std::vector<BlockData>::iterator it1 = temp_version.getBlockData().begin(); it1 != temp_verion.getBlockData().end(); ++it1)
    {
        sql::PreparedStatement prepared_statement = conn_->prepareStatement("INSERT INTO blktable VALUES(?, ?, ?, ?, ?)");
        prepared_statement->setInt(1, result->getInt());
        prepared_statement->setInt(2, it1->number);
        prepared_statement->setInt(3, it1->length);
        prepared_statement->setInt(4, it1->hash);
        prepared_statement->setBlob(5, it1->data);
        prepared_statement->execute();
    }
    delete result;
    delete prepared_statement;
}


FileRec FileArchiver::getDetailsOfLastSaved(std::string file_name)
{
    if(invalid_)
    {
        throw (DB_EXCEPTION);
    }
    FileRec temp_file;
    VersionRec temp_version;
    temp_file.getData(conn_, file_name);
    std::vector<int> version_ids = temp_file.getVersions();
    for(std::vector<int>::iterator it1 = version_ids.begin(); it1 != version_ids.end(); ++it1)
    {
        temp_version.getData(conn_, file_name, *it1);
        for(std::vector<BlockData>::iterator it2 = temp_version.getBlockData().begin(); it2 != temp_verion.getBlockData().end(); ++it2)//not sure if correct, depends on filerec/versionrec
        {
            if(it2->number >= temp_file.getLength())//append
            {
                temp_file.setLength(temp_file.getLength() + 1);
                //temp_file.???push_back(it2->hash);
            }
            else if(it2->length == 0)//remove
            {
                temp_file.setLength(temp_file.getLength() - 1);
                //remove hashes[it2->number] from temp_version.
            }
            else//insert
            {
                temp_file.setLength(temp_file.getLength() + 1);
                //temp_file.???insert(it2->hash, --at position it2->number);
            }
        }
    }
    return temp_file;
}

std::string FileArchiver::retriveVersion(int version_num, std::string file_name, std::string target)
{
    if(invalid_)
    {
        throw (DB_EXCEPTION);
    }
    return target;
}

std::string FileArchiver::createZipFile(std::string file_name)
{
    //TODO shell << "gzip " << file_name; or zlib
    file_name += ".gz";
    return file_name;
}
