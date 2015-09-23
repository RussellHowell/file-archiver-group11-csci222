/*
 * Sukhdip Singh
 * 4806827
 * Assignment 1
 * File Archiver Header
 */

#ifndef ARCHIVER_H
#define ARCHIVER_H

#include <QMainWindow>
#include "getcomment.h"
#include "retriever.h"
#include "setreference.h"
#include "fileexplorer.h"

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

private:
    Ui::Archiver *ui;
};

#endif // ARCHIVER_H
