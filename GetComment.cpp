/*
 * Sukhdip Singh
 * 4806827
 * Assignment 1
 * Comment box file
 */


#include <QtGui>
#include <QtCore>
#include "GetComment.h"
#include "ui_GetComment.h"

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

//get comment from input
void GetComment::on_buttonBox_accepted()
{

    commentin = ui->textEdit->toPlainText();

}

//return comment
QString GetComment::return_comment()
{
    return commentin;
}

