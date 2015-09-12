// *
// *
// * CSCI222
// * Group 11
// * 
// * Author(s): Russell Howell
// * Last modified: September 6th, 2015
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
 * opens the file, sets the necessary data members, and serializes the 
 * file. 
 */
void FileRec::createData(QString path)
{
    QFile mFile(path);
    
    if(!mFile.open(QFile::ReadOnly))
    {
        qDebug()<<"The path or file specified does not exist";
        return;
    };
    
    
    size_ = mFile.size();
    file_name_ = mFile.fileName(); //this will currently just assign the entire path to file_name
    qint64 iter = 0;
    
    
    //declare two buffers, hashing will be done on q_buffer
    char *buffer = new char[BLOCKSIZE];
    QByteArray q_buffer; 
   
    string string_file_name = path.toStdString();
    ifstream file(string_file_name.c_str(), ios::in | ios::binary | ios::ate);
    
    
    //How many times a *full* block will be read
    int read_count = size_ / BLOCKSIZE; 
    
    //This loop will terminate when all full possible blocks have been read 
    for(int i = 0; i < read_count; i++)
    {
        if(file.is_open())
        {
            file.seekg(iter, ios::beg);
            file.readsome(buffer, BLOCKSIZE);
            q_buffer.insert(0, buffer, BLOCKSIZE);
            iter = iter + BLOCKSIZE; //Iterate through stream 4k at a time;
        }
        
        
        //HASH BLOCK  
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
            q_buffer.insert(0, buffer, read_count); 
        }
        
        //HASH FINAL BLOCK
        //MOVE FINAL BLOCK TO PERSISTENT STORAGE
    }
    
    delete[] buffer; 
    mFile.close(); 
};