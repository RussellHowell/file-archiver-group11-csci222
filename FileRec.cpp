// *
// *
// * CSCI222
// * Group 11
// * 
// * Author(s): Russell Howell
// * Last modified: September 13th, 2015
// * Description: 
// * Purpose:

#include "FileRec.h"
#define BLOCKSIZE 4000


using namespace std;


//Default Constructor
FileRec::FileRec()
{
    number_of_versions_ = 0;
};


/* createData() takes a path to a file in the Unix system,
 * opens the file, sets the necessary data members, and calls readBlocks()
 */
void FileRec::createData(QString path)
{
    QFile m_file(path);
    time_t current_time;
 
    if(!m_file.open(QFile::ReadOnly))
    {
        qDebug()<<"The path or file specified does not exist";
        return;
    };
    
    //Populate timespec structure
    time(&current_time);
    struct tm *local_time;
    local_time = localtime( &current_time ); 
     
    timespec_.day = local_time->tm_mday;
    timespec_.month = local_time->tm_mon + 1;
    timespec_.year = local_time->tm_year + 1900;
    timespec_.hour = local_time->tm_hour;
    timespec_.minute = local_time->tm_min;
    timespec_.second = local_time->tm_sec;
    
    size_ = m_file.size();
    file_name_ = m_file.fileName(); //this will currently just assign the entire path to file_name
    ref_number_ = 0; 

    readBlocks(m_file);
    
    m_file.close();
};


/* readBlocks() opens a filestream, reads 4k blocks one at a time, hashes them,
 * stores hashes in an stl vector 
 * (MOVE HASHES AND BLOCKS TO PERSISTENT MEMORY HERE) */
void FileRec::readBlocks(const QFile& m_file)
{
    
    QCryptographicHash blk_crypto(QCryptographicHash::Md5);
    QCryptographicHash ov_crypto(QCryptographicHash::Md5);
    
    QByteArray buffer;
    
    while(!m_file.atEnd())
    {   
        buffer = const_cast<QFile &>(m_file).read(BLOCKSIZE);
        ov_crypto.addData(buffer); //add to overall hash
        block_hashes_.push_back(blk_crypto.hash(buffer, 
                QCryptographicHash::Md5)); //hash current block
    }
    
    file_hash_ = ov_crypto.result(); //complete overall hash
};

QByteArray FileRec::getFileHash()
{
    return file_hash_;
};


QString FileRec::getName()
{
    return file_name_;
};

qint64 FileRec::getLength()
{
    return size_;
};

qint16 FileRec::getVersionCount()
{
  return number_of_versions_;  
};

vector<QByteArray> FileRec::getBlockHashes()
{
    return block_hashes_;
};

vector<int> FileRec::getVersions()
{
    return version_ids_;
};

vector<string> FileRec::getComments()
{
    return comments_;
};

int FileRec::getRefNumber()
{
    return ref_number_;
}

//sql::Connection FileRec::operator<<(sql::Connection *conn, FileRec a);