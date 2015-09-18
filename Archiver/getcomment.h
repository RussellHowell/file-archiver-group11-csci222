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
    ~GetComment();

private:
    Ui::GetComment *ui;
};

#endif // GETCOMMENT_H
