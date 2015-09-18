/*
 * Sukhdip Singh
 * 4806827
 * Assignment 1
 * Version retrieve fiel
 */

#include "retriever.h"
#include "ui_retriever.h"

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
