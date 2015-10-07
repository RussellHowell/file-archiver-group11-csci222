/*
 * Sukhdip Singh
 * 4806827
 * Assignment 1
 * File Archiver Header
 */

#ifndef ARCHIVER_H
#define ARCHIVER_H

#include "FileArchiver.h"
#include <QMainWindow>
#include "GetComment.h"
#include "Retriever.h"
#include <QMessageBox>
#include <QStandardItemModel>

struct item
{
    QString version;
    QString time;
    QString size;
};



namespace Ui {
class Archiver;
}

class Archiver : public QMainWindow
{
    Q_OBJECT

public:
    explicit Archiver(QWidget *parent = 0);
    ~Archiver();

private slots:

    void on_file_button_clicked();

    void on_save_button_clicked();

    void on_retrieve_button_clicked();

    void on_reference_button_clicked();

    void on_comment_button_clicked();
    
    void clickedModel(QModelIndex index);

    //void on_fileviewer_activated(const QModelIndex &index);

    //void populate();

    void retrieveVersionDataForFile();

    void createFirstVersion();

private:
    Ui::Archiver *ui;
    FileArchiver file_archiver;
    QStandardItemModel *model;
    QString fileName;
    int version_number;



};


#endif // ARCHIVER_H
