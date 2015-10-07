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
#include "cppconn/exception.h"
#include "cppconn/prepared_statement.h"
#include "cppconn/resultset.h"
#include <boost/chrono.hpp>
#include <utility>
#include <QDebug>

const int BLOCKSIZE = 4000;

const char* NO_FILE = "File Open Failure! Operation failed. ";

FileRec::FileRec()
{
    
}

std::string FileRec::getFilename()
{
    return filename_;
}

void FileRec::setFilename(std::string filename)
{
    filename_ = filename;
}

std::string FileRec::getCurhash()
{
    return curhash_;
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

int FileRec::getBlobtableTempname()
{
    return blobtable_tempname_;
}

void FileRec::setBlobtableTempname(int blobtable_tempname)
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
    blktable_length_ = blktable_length;
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

void FileRec::getData(sql::Connection* conn, std::string file_name)
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
        mtnsec_ = result->getInt(8);
        blobtable_tempname_ = result->getInt(9);
    }
    prepared_statement = conn->prepareStatement("SELECT idversionrec FROM versionrec WHERE fileref = ?");
    prepared_statement->setString(1, filename_);
    result = prepared_statement->executeQuery();
    while(result->next())
    {
        idversionrec_.push_back(result->getInt(1));
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
    prepared_statement->setInt(9, blobtable_tempname_);
    prepared_statement->executeQuery();
    int blknum = 0;
    
    if(!blktable_length_.empty())
    {
        std::vector<int>::iterator it2 = blktable_length_.begin();
        for(std::vector<std::string>::iterator it1 = blktable_hashval_.begin(); it1 != blktable_hashval_.end(); ++it1)
        {
            prepared_statement = conn->prepareStatement("INSERT INTO fileblkhashes VALUES(?, ?, ?, ?)");
            prepared_statement->setString(1, filename_);
            prepared_statement->setInt(2, blknum);
            prepared_statement->setString(3, *it1);
            prepared_statement->setInt(4, *it2);
            prepared_statement->executeQuery();
            ++blknum;
            ++it2;
        }
    }
    prepared_statement = conn->prepareStatement("INSERT INTO commentstable VALUES(?, ?, ?)");
    prepared_statement->setString(1, filename_);
    prepared_statement->setInt(2, 0);
    prepared_statement->setString(3, commenttxt_.front());
    prepared_statement->executeQuery();
    delete result;
    delete prepared_statement;
}

void FileRec::createData(std::string file_name)
{
    QFile temp_file(file_name.c_str()); 
    if(!temp_file.open(QFile::ReadOnly))
    {
        throw (NO_FILE);
    };
    
    boost::chrono::process_real_cpu_clock::time_point current_time = boost::chrono::process_real_cpu_clock::now();
    boost::chrono::seconds sec = boost::chrono::time_point_cast<boost::chrono::seconds> (current_time).time_since_epoch();
    boost::chrono::nanoseconds nanosec = current_time.time_since_epoch();
    mtsec_ = sec.count();
    mtnsec_ = nanosec.count() %  sec.count();
    
    length_ = temp_file.size();
    filename_ = temp_file.fileName().toStdString();
    
    QCryptographicHash blk_crypto(QCryptographicHash::Md5);
    QCryptographicHash ov_crypto(QCryptographicHash::Md5);
    
    QByteArray buffer;
    
    while(!temp_file.atEnd())
    {
        buffer = const_cast<QFile&>(temp_file).read(BLOCKSIZE);
        ov_crypto.addData(buffer);
        blktable_hashval_.push_back(blk_crypto.hash(buffer, QCryptographicHash::Md5).data());
        blktable_length_.push_back(buffer.length());
    }
    curhash_ = ov_crypto.result().data();
    ovhash_ = curhash_;
    temp_file.close();
}

VersionRec FileRec::createVersionData(FileRec current_save)//!!!!!!!!!!!!!!!!!!!!!!TODO!!!!!!!!!!!!!!!!!!!!!!!!!!!
{
    VersionRec update;
    std::vector<BlkTable> temp_blktable;
    BlkTable temp_blk;
    QFile temp_file(current_save.getFilename().c_str()); 
    if(!temp_file.open(QFile::ReadOnly))
    {
        throw (NO_FILE);
    };
    
    boost::chrono::system_clock::time_point current_time = boost::chrono::system_clock::now();
    boost::chrono::seconds sec = boost::chrono::time_point_cast<boost::chrono::seconds> (current_time).time_since_epoch();
    boost::chrono::nanoseconds nanosec = current_time.time_since_epoch();
    update.setMtsec(sec.count());
    update.setMtsec(nanosec.count() %  sec.count());
    
    update.setLength(temp_file.size());
    update.setFileref(temp_file.fileName().toStdString());
    
    update.setVersionnum(current_save.getNversions() + 1);
    
    QCryptographicHash blk_crypto(QCryptographicHash::Md5);
    QCryptographicHash ov_crypto(QCryptographicHash::Md5);
    
    QByteArray buffer;
    
    std::string hash;
    
    std::vector<std::pair<std::string, int> > hashes;
    //
    std::vector<int>::iterator length_it = current_save.getBlktableLength().begin();
    for(std::vector<std::string>::iterator it1 = current_save.getBlktableHash().begin(); it1 != current_save.getBlktableHash().end(); ++it1)
    {
        if(*length_it == BLOCKSIZE)
        {
            std::pair<std::string, int> temp_pair;
            temp_pair.first = *it1;
            temp_pair.second = *length_it;
            hashes.push_back(temp_pair);
        }
        else
        {
            temp_blk.blknum = it1 - current_save.getBlktableHash().begin();
            temp_blk.data = NULL;
            temp_blk.hash = *it1;
            temp_blk.length = 0;
            temp_blktable.push_back(temp_blk);
        }
        ++length_it;
    }
    int pos;
    for(std::vector<std::pair<std::string, int> >::iterator it1 = hashes.begin(); (it1 != hashes.end()) && (!temp_file.atEnd()); ++it1)     
    {
        buffer = const_cast<QFile&>(temp_file).read(BLOCKSIZE);
        ov_crypto.addData(buffer);
        hash = blk_crypto.hash(buffer, QCryptographicHash::Md5).data();
        if(it1->first != hash)
        {
            pos = temp_file.pos();
        }
        while(it1->second != pos)
        {
            temp_blk.blknum = it1->second;
            temp_blk.data = qCompress(buffer);
            temp_blk.hash = hash;
            temp_blk.length = buffer.size();
            temp_blktable.push_back(temp_blk);
        }
    }
    update.setBlktable(temp_blktable);
    update.setOvhash(ov_crypto.result().data());
    temp_file.close();
    return update;
}
