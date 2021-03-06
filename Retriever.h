/*
 * Sukhdip Singh
 * 4806827
 * Assignment 1
 * Retrieve box Header
 */

#ifndef RETRIEVER_H
#define RETRIEVER_H

#include <QDialog>
#include <QFileDialog>

namespace Ui {
class retriever;
}

class retriever : public QDialog
{
    Q_OBJECT

public:
    explicit retriever(QWidget *parent = 0);
    ~retriever();
    QString get_name();
    QString get_directory();

private slots:
    void on_selectfile_clicked();

    void on_cancel_clicked();

    void on_OK_retrieve_clicked();



private:
    Ui::retriever *ui;
    QString retname;
    QString retrieveddir;

};

#endif // RETRIEVER_H
