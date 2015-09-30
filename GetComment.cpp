/*
 * Sukhdip Singh
 * 4806827
 * Assignment 1
 * Comment box file
 */

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

void GetComment::on_buttonBox_accepted()
{

    commentin = ui->textEdit->toPlainText();

}

QString GetComment::return_comment()
{
    return commentin;
}

