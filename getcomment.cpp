/*
 * Sukhdip Singh
 * 4806827
 * Assignment 1
 * Comment box file
 */

#include "getcomment.h"
#include "ui_getcomment.h"

GetComment::GetComment(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GetComment)
{
    ui->setupUi(this);
    this->setWindowTitle("GetCommentForm");
}

GetComment::~GetComment()
{
    delete ui;
}
