/*
 * Sukhdip Singh
 * 4806827
 * Assignment 1
 * Program main window file
 */

#include "archiver.h"
#include "ui_archiver.h"


Archiver::Archiver(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Archiver)
{
    ui->setupUi(this);
    this->setWindowTitle("MyWindow");
}

Archiver::~Archiver()
{
    delete ui;
}


void Archiver::on_file_button_clicked()
{
    fileexplorer exp;

    exp.setModal(true);
    exp.exec();
}

void Archiver::on_save_button_clicked()
{

}

void Archiver::on_retrieve_button_clicked()
{
    retriever retbox;

    retbox.setModal(true);
    retbox.exec();
}

void Archiver::on_reference_button_clicked()
{
    setreference refbox;
    refbox.setModal(true);
    refbox.exec();
}

void Archiver::on_comment_button_clicked()
{
    GetComment commentbox;

    commentbox.setModal(true);
    commentbox.exec();
}
