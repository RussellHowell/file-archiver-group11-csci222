#ifndef FILEEXPLORER_H
/*
 * Sukhdip Singh
 * 4806827
 * Assignment 1
 * File Explorer Header
 */

#define FILEEXPLORER_H

#include <QDialog>
#include <QFileSystemModel>

namespace Ui {
class fileexplorer;
}

class fileexplorer : public QDialog
{
    Q_OBJECT

public:
    explicit fileexplorer(QWidget *parent = 0);
    ~fileexplorer();

private slots:
    void on_treeView_clicked(const QModelIndex &index);

private:
    Ui::fileexplorer *ui;
    QFileSystemModel *dirmodel;
    QFileSystemModel *filemodel;
};

#endif // FILEEXPLORER_H
