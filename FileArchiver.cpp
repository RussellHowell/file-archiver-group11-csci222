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

bool FileArchiver::exists(std::string file_name)
{
    std::string exists_query = "SELECT COUNT(*) FROM filerec WHERE filename = ?";
    sql::PreparedStatement exists_tatement = conn->prepareStatement(exists_query);
    exists_statement->setString(1, file_name);
    exists_statement->

}

bool FileArchiver::differs(std::string file_name)
{

}

FileArchiver::FileArchiver()
{
    
};

void FileArchiver::insertNew(std::string file_name, std::string comment)
{
       
};

