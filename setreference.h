#ifndef SETREFERENCE_H
/*
 * Sukhdip Singh
 * 4806827
 * Assignment 1
 * Reference Box Header
 */

#define SETREFERENCE_H

#include <QDialog>

namespace Ui {
class setreference;
}

class setreference : public QDialog
{
    Q_OBJECT

public:
    explicit setreference(QWidget *parent = 0);
    ~setreference();

private slots:

    void on_cancel_clicked();

private:
    Ui::setreference *ui;

};

#endif // SETREFERENCE_H
