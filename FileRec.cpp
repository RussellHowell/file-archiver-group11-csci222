// *
// *
// * CSCI222
// * Group 11
// * 
// * Author(s): Jack Robert Humphreys
// * Last modified: September 28th, 2015
// * Description: 
// * Purpose:

#include "FileRec.h"
#include <boost/chrono.hpp>

const int BLOCKSIZE = 4000;

const char* NO_FILE = "File Open Failure! Operation failed. ";

FileRec::FileRec()
{
    
}

std::string FileRec::getFilename()
{
    
}

void FileRec::setFilename(std::string)
{
    
}

std::string FileRec::getCurhash()
{
    
}

void FileRec::setCurhash(std::string curhash)
{
    curhash_ = curhash;
}

std::string FileRec::getOvhash()
{
    return ovhash_;
}

void FileRec::setOvhash(std::string ovhash)
{
    ovhash_ = ovhash;
}

int FileRec::getCurrentversion()
{
    return currentversion_;
}

void FileRec::setCurrentversion(int currentversion)
{
    currentversion_ = currentversion;
}

int FileRec::getNversions()
{
    return nversions_;
}

void FileRec::setNversions(int nversions)
{
    nversions_ = nversions;
}

int FileRec::getLength()
{
    return length_;
}

void FileRec::setLength(int length)
{
    length_ = length;
}

int FileRec::getMtsec()
{
    return mtsec_;
}

void FileRec::setMtsec(int mtsec)
{
    mtsec_ = mtsec;
}

int FileRec::getMtnsec()
{
    return mtnsec_;
}

void FileRec::setMtnsec(int mtnsec)
{
    mtnsec_ = mtnsec;
}

std::string FileRec::getBlobtableTempname()
{
    return blobtable_tempname_;
}

void FileRec::setBlobtableTempname(std::string blobtable_tempname)
{
    blobtable_tempname_ = blobtable_tempname;
}

std::vector<std::string> FileRec::getBlktableHash()
{
    return blktable_hashval_;
}

void FileRec::setBlktableHash(std::vector<std::string> blktable_hashval)
{
    blktable_hashval_ = blktable_hashval;
}

std::vector<int> FileRec::getBlktableLength()
{
    return blktable_length_;
}

void FileRec::setBlktableLength(std::vector<int> blktable_length)
{
    blktable_length_ = blktable_length_;
}

std::vector<int> FileRec::getIdversionrec()
{
    return idversionrec_;
}

void FileRec::setIdversionrec(std::vector<int> idversionrec)
{
    idversionrec_ = idversionrec;
}

std::vector<std::string> FileRec::getCommenttxt()
{
    return commenttxt_;
}

void FileRec::setCommenttxt(std::vector<std::string> commenttxt)
{
    commenttxt_ = commenttxt;
}

void FileRec::getData(sql::Connection* conn, int file_name)
{
    sql::ResultSet *result = NULL;
    sql::PreparedStatement *prepared_statement = NULL;
    prepared_statement = conn->prepareStatement("SELECT * FROM filerec WHERE filename = ?");
    prepared_statement->setString(1, file_name);
    result = prepared_statement->executeQuery();
    while(result->next())
    {
        filename_ = result->getString(1);
        curhash_ = result->getString(2);
        ovhash_ = result->getString(3);
        currentversion_ = result->getInt(4);
        nversions_ = result->getInt(5);
        length_ = result->getInt(6);
        mtsec_ = result->getInt(7);
        mtnsec_ result->getInt(8);
    }
    prepared_statement = conn->prepareStatement("SELECT idversionrec FROM versionrec WHERE fileref = ?");
    prepared_statement->setString(1, filename_);
    result = prepared_statement->executeQuery();
    while(result->next())
    {
        idversionrec_.push_back(result->getString(1));
    }
    prepared_statement = conn->prepareStatement("SELECT commenttxt FROM commentstable WHERE fileref = ?");
    prepared_statement->setString(1, filename_);
    result = prepared_statement->executeQuery();
    while(result->next())
    {
        commenttxt_.push_back(result->getString(1));
    }
    prepared_statement = conn->prepareStatement("SELECT hashval, length FROM fileblkhashes WHERE fileref = ? ORDER BY blknum ASC");
    prepared_statement->setString(1, filename_);
    result = prepared_statement->executeQuery();
    while(result->next())
    {
        blktable_hashval_.push_back(result->getString(1));
        blktable_length_.push_back(result->getInt(2));
    }
    delete result;
    delete prepared_statement;
}

void FileRec::setData(sql::Connection* conn)
{
    sql::ResultSet *result = NULL;
    sql::PreparedStatement *prepared_statement = NULL;
    prepared_statement = conn->prepareStatement("INSERT INTO filerec VALUES(?, ?, ?, ?, ?, ?, ?, ?, ?)");
    prepared_statement->setString(1, filename_);
    prepared_statement->setString(2, curhash_);
    prepared_statement->setString(3, ovhash_);
    prepared_statement->setInt(4, currentversion_);
    prepared_statement->setInt(5, nversions_);
    prepared_statement->setInt(6, length_);
    prepared_statement->setInt(7, mtsec_);
    prepared_statement->setInt(8, mtsec_);
    prepared_statement->setString(9, blobtable_tempname_);
    prepared_statement->execute();
    int blknum = 0;
    std::vector<std::string>::iterator it2 = blktable_length_.begin();
    for(std::vector<std::string>::iterator it1 = blktable_hashval_.begin(); it1 != blktable_hashval_.end(); ++it1)
    {
        prepared_statement = conn->prepareStatement("INSERT INTO fileblkhashes VALUES(?, ?, ?)");
        prepared_statement->setString(1, filename_);
        prepared_statement->setInt(2, blknum);
        prepared_statement->setString(3, *it1);
        prepared_statement->setInt(4, *it2);
        prepared_statement->execute();
        ++blknum;
        ++it2;
    }
    delete result;
    delete prepared_statement;
}

void FileRec::createData(std::string file_name)
{
    QFile temp_file(file_name); 
    if(!temp_file.open(QFile::ReadOnly))
    {
        throw (NO_FILE);
    };
    
    boost::chrono::system_clock::time_point current_time = boost::chrono::system_clock::now();
    boost::chrono::seconds sec = current_time;
    boost::chrono::nanoseconds nanosec = current_time;
    mtsec_ = sec.count();
    mtnsec_ = nanosec.count() %  sec.count();
    
    length_ = temp_file.size();
    filename_ = temp_file.fileName();
    
    QCryptographicHash blk_crypto(QCryptographicHash::Md5);
    QCryptographicHash ov_crypto(QCryptographicHash::Md5);
    
    QByteArray buffer;
    
    while(!temp_file.atEnd())
    {   
        buffer = const_cast<QFile&>(temp_file).read(BLOCKSIZE);
        ov_crypto.addData(buffer);
        blktable_hashval_.push_back(blk_crypto.hash(buffer, QCryptographicHash::Md5));
    }
    curhash_ = ov_crypto.result();
    temp_file.close();
}

VersionRec FileRec::createVersionData(FileRec current_save)
{
    
}
