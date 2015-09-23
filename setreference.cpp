#include "setreference.h"
/*
 * Sukhdip Singh
 * 4806827
 * Assignment 1
 * Reference set file
 */

#include "ui_setreference.h"


setreference::setreference(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::setreference)
{
    ui->setupUi(this);
    this->setWindowTitle("Set Reference Version");
    QPixmap pic("D:/Users/Aaron/Documents/build-Archiver-Desktop_Qt_5_5_0_MinGW_32bit-Debug/question_mark.png");
    ui->picture->setPixmap(pic);
}

setreference::~setreference()
{
    delete ui;
}



void setreference::on_cancel_clicked()
{
    this->close();
}
