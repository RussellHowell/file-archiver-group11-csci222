/*
 * Sukhdip Singh
 * 4806827
 * Assignment 1
 * Program main window file
 */


#include <QtGui>
#include <QtCore>
#include "Archiver.h"
#include "ui_Archiver.h"
#include <QStandardItemModel>
#include <QFileDialog>
#include <QMessageBox>
#include <time.h>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/date_time/gregorian/gregorian_types.hpp>

Archiver::Archiver(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Archiver)
{
    version_number = -1;

    ui->setupUi(this);
    //set name of window
    this->setWindowTitle("MyWindow");


    //Create the version viewer table view

    model = new QStandardItemModel(0,3,this);
    //set 3 columns header and resize to fit
    model-> setHorizontalHeaderItem(0, new QStandardItem(QString("Version #")));
    model-> setHorizontalHeaderItem(1, new QStandardItem(QString("Date")));
    model-> setHorizontalHeaderItem(2, new QStandardItem(QString("Size")));

    ui->fileviewer->resizeColumnsToContents();

    QHeaderView* header = ui->fileviewer->horizontalHeader();
    header->setStretchLastSection(true);
    ui->fileviewer->setHorizontalHeader(header);
    
     connect(this,SIGNAL(clicked(QModelIndex)),this,SLOT(clickedModel(QModelIndex)));

/*
    //===============================================================================
    //      TESTING VECTOR INTO TABLEVIEW (REMOVE WHEN TESTING WITH ACTUAL DATA)
    this->populate();
    for(int i=0; i <3 ; i++)
    {
        QStandardItem *first1 = new QStandardItem(QString(vector[i].version));
        QStandardItem *first2 = new QStandardItem(QString(vector[i].time));
        QStandardItem *first3 = new QStandardItem(QString(vector[i].size));
        model->setItem(i,0,first1);
        model->setItem(i,1,first2);
        model->setItem(i,2,first3);
    }
    //===============================================================================
*/


    ui->fileviewer->setModel(model);

}

Archiver::~Archiver()
{
    delete ui;
}


void Archiver::on_file_button_clicked()
{
    //get the path of file
    fileName = QFileDialog::getOpenFileName(this,tr("Open File"), "/home");

    ui->fileEdit->setText(fileName);

    //this->retrieveVersionDataForFile();

    if(file_archiver.exists(fileName.toStdString()))
    {
        this->retrieveVersionDataForFile();
    }

    else
    {
        this->createFirstVersion();
    }
    
    


}

//choose saving of file
void Archiver::on_save_button_clicked()
{

    //bool saved = true;  // <------ to be removed once differ() works

    //if(saved)  // <------ to be removed once differ() works
    if(file_archiver.differs(fileName.toStdString()))
    {
        GetComment * comBox = new GetComment;

        comBox->setModal(true);
        comBox->exec();

        QString comment = comBox->return_comment();

        file_archiver.update(fileName.toStdString(),comment.toStdString());
        this->retrieveVersionDataForFile();
    }
    else
    {

        QMessageBox::information(this,"No changes", "There are NO changes made. No save is required.");
    }
}

//retrieve function
void Archiver::on_retrieve_button_clicked()
{

    //create retriever instance
    retriever retbox;

    retbox.setModal(true);
    retbox.exec();

    //get the retrieved file name and directory chosen from retriever instance
    QString retname = retbox.get_name();
    QString directory = retbox.get_directory();
    QString path = directory + "/" + retname;
    

    //validation if a row is chosen
    if(version_number>=0)
    {
        file_archiver.retrieveVersion(fileName.toStdString(),version_number,path.toStdString());
    }

}

void Archiver::on_reference_button_clicked()
{
    //Prompt QMessageBox for reference setting
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this,"Set reference","Set reference version",QMessageBox::Cancel | QMessageBox::Ok);

    //Carry out the reference setting if OK is chosen
    if(reply==QMessageBox::Ok)
    {
        GetComment * addComment = new GetComment;
        addComment->setModal(true);
        addComment->exec();

        QString comment = addComment->return_comment();

        //validation if there is a chosen version
        if(version_number>=0)
        {
            file_archiver.setReference(fileName.toStdString(),version_number,comment.toStdString());
            this->retrieveVersionDataForFile();
        }

        
    }

}

//display comment
void Archiver::on_comment_button_clicked()
{

    QString display;
    //if there is a chosen row (default value for non-chosen is -1)
    if(version_number>=0)
    {
        display = QString::fromStdString(file_archiver.getComment(fileName.toStdString(),version_number));
    }

    //prompt message box showing the comment
    QMessageBox::information(this,"Comment",display, QMessageBox::Ok);

}

//get the version_number based on clicked row's index
/*void Archiver::on_fileviewer_activated(const QModelIndex &index)
{

    std::vector<VersionInfo> x;
    x = file_archiver.getVersionInfo(fileName.toStdString());
    version_number = x[index.row()].versionnum;
    QStandardItem *first2 = new QStandardItem(QString("ASD"));
    model->setItem(1, 0, first2);
}*/

void Archiver::clickedModel(QModelIndex index)
{
    QMessageBox::information(NULL, "CLICKED",index.data().toString());

}





//get the versions and populate data based on vector from FileArchiver
void Archiver::retrieveVersionDataForFile()
{
    model->clear();

    std::vector<VersionInfo> x;
    x = file_archiver.getVersionInfo(fileName.toStdString());

    //set the table view
    model = new QStandardItemModel(0,3,this);

    //set 3 columns header and resize to fit
    model-> setHorizontalHeaderItem(0, new QStandardItem(QString("Version #")));
    model-> setHorizontalHeaderItem(1, new QStandardItem(QString("Date")));
    model-> setHorizontalHeaderItem(2, new QStandardItem(QString("Size")));

    //set columns to fit table
    ui->fileviewer->resizeColumnsToContents();

    QHeaderView* header = ui->fileviewer->horizontalHeader();
    header->setStretchLastSection(true);
    ui->fileviewer->setHorizontalHeader(header);
/*
    //============================================================
    // RANDOM TEST DATA (REMOVE THIS!)
    for(int i=0; i <2 ; i++)
    {
        QStandardItem *first1 = new QStandardItem(QString(vector[i].version));
        QStandardItem *first2 = new QStandardItem(QString(vector[i].time));
        QStandardItem *first3 = new QStandardItem(QString(vector[i].size));
        model->setItem(i,0,first1);
        model->setItem(i,1,first2);
        model->setItem(i,2,first3);
    }
    //============================================================
*/
    int i = 0;
    for(std::vector<VersionInfo>::iterator it = x.begin(); it != x.end(); ++it)
    {
        QStandardItem *first1 = new QStandardItem(QString(it->versionnum));

        int seconds = it->mtsec;
        int nano = it->mtnsec;

        boost::posix_time::ptime m_DateTime =  boost::posix_time::ptime( boost::gregorian::date(1970, 1, 1),  boost::posix_time::time_duration(0,0,0,  boost::posix_time::time_duration::ticks_per_second()
                                                    * ( boost::posix_time::time_duration::fractional_seconds_type)seconds));


        //convert the time here
        std::string time =  boost::posix_time::to_simple_string(m_DateTime);
        time += nano;
        QStandardItem *first2 = new QStandardItem(QString(time.c_str()));
        QStandardItem *first3 = new QStandardItem(QString(it->length));

        model->setItem(i,0,first1);
        model->setItem(i,1,first2);
        model->setItem(i,2,first3);
        ++i;
    }
    

    ui->fileviewer->setModel(model);
}

//create a new version
void Archiver::createFirstVersion()
{

    //prompt a GetComment form to attain the comment for the new version
    GetComment * addComment = new GetComment;
    addComment->setModal(true);
    addComment->exec();

    //get comment
    QString comment = addComment->return_comment();

    file_archiver.insertNew(fileName.toStdString(),comment.toStdString());
    this->retrieveVersionDataForFile();
}
