/*
 * Sukhdip Singh
 * 4806827
 * Assignment 1
 * Comment Box Header
 */

#ifndef GETCOMMENT_H
#define GETCOMMENT_H

#include <QDialog>

namespace Ui {
class GetComment;
}

class GetComment : public QDialog
{
    Q_OBJECT

public:
    explicit GetComment(QWidget *parent = 0);
    QString return_comment();
    ~GetComment();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::GetComment *ui;
    QString commentin;
};

#endif // GETCOMMENT_H
