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
    QFile mFile(path);
    time_t current_time;
 
    if(!mFile.open(QFile::ReadOnly))
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
    
    size_ = mFile.size();
    file_name_ = mFile.fileName(); //this will currently just assign the entire path to file_name
     mFile.close();  
     
    readBlocks(path.toStdString());
        
};



/* readBlocks() opens a filestream, reads 4k blocks one at a time, hashes them,
 * stores hashes in an stl vector 
 * (MOVE HASHES AND BLOCKS TO PERSISTENT MEMORY HERE) */
void FileRec::readBlocks(string file_name)
{
    char *buffer = new char[BLOCKSIZE];
    int iter = 0;
    
    SHA256 sha256; //hashing object
    
    ifstream file(file_name.c_str(), ios::in | ios::binary | ios::ate);
   
    //How many times a *full* block will be read
    int read_count = size_ / BLOCKSIZE; 
    
    //This loop will terminate when all full possible blocks have been read 
    for(int i = 0; i < read_count; i++)
    {
        if(file.is_open())
        {
            file.seekg(iter, ios::beg);
            file.readsome(buffer, BLOCKSIZE);
            iter = iter + BLOCKSIZE; //Iterate through stream 4k at a time;
            
             block_hashes_.push_back(sha256(buffer, BLOCKSIZE));
        }
 
        //MOVE BLOCK TO PERSISTENT STOARAGE
    }
    
    //Calculate how many bytes of a partial block need to be read 
    read_count = size_ % BLOCKSIZE; 
    
    // Final block will more than likely not be exactly 4k bytes 
    if(read_count != 0)
    {
        if(file.is_open())
        {
            file.seekg(iter, ios::beg);
            file.readsome(buffer, read_count); //read read_count bytes into buffer
         
             block_hashes_.push_back(sha256(buffer, read_count));
        }
        
    }
    
    delete[] buffer; 
};