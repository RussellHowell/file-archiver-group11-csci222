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

//Default Constructor
FileRec::FileRec()
{
    number_of_versions_ = 0;
};


/* createData() takes a path to a file in the Unix system,
 * opens the file and sets the necessary data members FileRec
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
    
    mFile.close(); 
};