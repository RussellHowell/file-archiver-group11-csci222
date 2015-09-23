/*
 * Sukhdip Singh
 * 4806827
 * Assignment 1
 * Browser widget file
 */

#include "fileexplorer.h"
#include "ui_fileexplorer.h"


fileexplorer::fileexplorer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fileexplorer)
{
    ui->setupUi(this);

    QString sPath = "";
    dirmodel = new QFileSystemModel(this);
    dirmodel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs);
    dirmodel->setRootPath(sPath);

    ui->treeView->setModel(dirmodel);

    filemodel = new QFileSystemModel(this);
    filemodel->setFilter(QDir::NoDotAndDotDot | QDir::Files);
    filemodel->setRootPath(sPath);

    ui->tableView->setModel(filemodel);


}

fileexplorer::~fileexplorer()
{
    delete ui;
}

void fileexplorer::on_treeView_clicked(const QModelIndex &index)
{
    QString sPath = dirmodel->fileInfo(index).absoluteFilePath();
    ui->tableView->setRootIndex(filemodel->setRootPath(sPath));
}
