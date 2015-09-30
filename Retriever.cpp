/*
 * Sukhdip Singh
 * 4806827
 * Assignment 1
 * Version retrieve file
 */

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
    QString retrieveddir =  QFileDialog::getExistingDirectory(this, tr("Open Directory"), "/home",QFileDialog::ShowDirsOnly| QFileDialog::DontResolveSymlinks);

    ui->directoryedit->setText(retrieveddir);

    //Get name of file
    QString name = ui->nameedit->text();

    //FileArchiver::retrieveVersion(version_number,fileName,retrievedName);


}


void retriever::on_cancel_clicked()
{
    this->close();
}

void retriever::on_OK_retrieve_clicked()
{
    QString name = ui->nameedit->text();

    this->accept();
}
