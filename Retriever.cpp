/*
 * Sukhdip Singh
 * 4806827
 * Assignment 1
 * Version retrieve file
 */


#include <QtGui>
#include <QtCore>
#include "Retriever.h"
#include "ui_Retriever.h"

retriever::retriever(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::retriever)
{
    ui->setupUi(this);
    this->setWindowTitle("RetrieveForm");
}

retriever::~retriever()
{
    delete ui;
}

void retriever::on_selectfile_clicked()
{
    //get the path of file
    retrieveddir =  QFileDialog::getExistingDirectory(this, tr("Open Directory"), "/home",QFileDialog::ShowDirsOnly| QFileDialog::DontResolveSymlinks);

    ui->directoryedit->setText(retrieveddir);

    //Get name of file
    retname = ui->nameedit->text();

}


void retriever::on_cancel_clicked()
{
    this->close();
}

void retriever::on_OK_retrieve_clicked()
{
    this->accept();
}

//return the retrieved name
QString retriever::get_name()
{
    return retname;
}

//return the retrieved directory
QString retriever::get_directory()
{
    return retrieveddir;

}
