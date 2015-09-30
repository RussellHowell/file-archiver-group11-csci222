/*
 * Sukhdip Singh
 * 4806827
 * Assignment 1
 * Program main window file
 */

#include "Archiver.h"
//#include "FileArchiver.h"
#include "ui_Archiver.h"
#include <QStandardItemModel>
#include <QFileDialog>
#include <QMessageBox>

QVector<item> vector(3);


Archiver::Archiver(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Archiver)
{
    ui->setupUi(this);
    //set name of window
    this->setWindowTitle("MyWindow");


    //Create the version viewer table view

    model = new QStandardItemModel(3,3,this);
    //set 3 columns header and resize to fit
    model-> setHorizontalHeaderItem(0, new QStandardItem(QString("Version #")));
    model-> setHorizontalHeaderItem(1, new QStandardItem(QString("Date")));
    model-> setHorizontalHeaderItem(2, new QStandardItem(QString("Size")));

    ui->fileviewer->resizeColumnsToContents();

    QHeaderView* header = ui->fileviewer->horizontalHeader();
    header->setStretchLastSection(true);
    ui->fileviewer->setHorizontalHeader(header);

    //===============================================================================
    //                          TESTING VECTOR INTO TABLEVIEW

    this->populate();


    QStandardItem *first1 = new QStandardItem(QString(vector[0].version));
    QStandardItem *first2 = new QStandardItem(QString(vector[0].time));
    QStandardItem *first3 = new QStandardItem(QString(vector[0].size));

    model->setItem(0,0,first1);
    model->setItem(0,1,first2);
    model->setItem(0,2,first3);
    //===============================================================================



    ui->fileviewer->setModel(model);

}

Archiver::~Archiver()
{
    delete ui;
}


void Archiver::on_file_button_clicked()
{
    //get the path of file
    QString fileName = QFileDialog::getOpenFileName(this,tr("Open File"), "/home");

    ui->fileEdit->setText(fileName);

    this->retrieveVersionDataForFile();

    /*
    if(FileArchiver::exists(fileName))
    {
        this->retrieveVersionDataForFile(fileName);
    }

    else
    {
        this->createFirstVersion();
    }
    */
    


}

void Archiver::on_save_button_clicked()
{
    //assigned as false for testing purpose
    //will check based on differ()
    bool saved = true;

    //if(FileArchiver::differs(fileName))
    if(saved)
    {
        GetComment * comBox = new GetComment;

        comBox->setModal(true);
        comBox->exec();

        QString comment = comBox->return_comment();

        //FileArchiver::update(fileName,comment);
        //this->retrieveVersionDataForFile();


    }

    else
    {

        QMessageBox::information(this,"No changes", "There are NO changes made. No save is required.");
    }
}

void Archiver::on_retrieve_button_clicked()
{
    retriever retbox;

    retbox.setModal(true);
    retbox.exec();
}

void Archiver::on_reference_button_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this,"Set reference","Set reference version",QMessageBox::Cancel | QMessageBox::Ok);

    if(reply==QMessageBox::Ok)
    {
        GetComment * addComment = new GetComment;
        addComment->setModal(true);
        addComment->exec();

        QString comment = addComment->return_comment();

        //FileArchiver::setReference(fileName,version_number,comment);
        //this->retrieveVersionDataForFile();
        
    }

}

void Archiver::on_comment_button_clicked()
{

    QString display;
    //display = QString::fromStdString(FileArchiver::getComment(fileName,version_number));
    QMessageBox::information(this,"Comment",display, QMessageBox::Ok);

}

void Archiver::on_fileviewer_activated(const QModelIndex &index)
{
    QString chosen = ui->fileviewer->model()->data(index).toString();
}


void Archiver::populate()
{

    //item array[3];

    vector[0].time = "12.00pm";
    vector[0].version = "1";
    vector[0].size = "100";

    vector[1].time = "11.00pm";
    vector[1].version = "2";
    vector[1].size = "200";

    vector[2].time = "10.00pm";
    vector[2].version = "3";
    vector[2].size = "99";


}


void Archiver::retrieveVersionDataForFile()
{
    model->clear();

    //FileArchiver::getVersionInfo(filename);

    model = new QStandardItemModel(2,3,this);
    //set 3 columns header and resize to fit
    model-> setHorizontalHeaderItem(0, new QStandardItem(QString("Version #")));
    model-> setHorizontalHeaderItem(1, new QStandardItem(QString("Date")));
    model-> setHorizontalHeaderItem(2, new QStandardItem(QString("Size")));

    ui->fileviewer->resizeColumnsToContents();

    QHeaderView* header = ui->fileviewer->horizontalHeader();
    header->setStretchLastSection(true);
    ui->fileviewer->setHorizontalHeader(header);

    ui->fileviewer->setModel(model);
}

void Archiver::createFirstVersion()
{

    GetComment * addComment = new GetComment;
    addComment->setModal(true);
    addComment->exec();

    QString comment = addComment->return_comment();

    //FileArchiver::insertNew()
    this->retrieveVersionDataForFile();
}

