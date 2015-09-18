/*
 * Sukhdip Singh
 * 4806827
 * Assignment 1
 * Retrieve box Header
 */

#ifndef RETRIEVER_H
#define RETRIEVER_H

#include <QDialog>

namespace Ui {
class retriever;
}

class retriever : public QDialog
{
    Q_OBJECT

public:
    explicit retriever(QWidget *parent = 0);
    ~retriever();

private:
    Ui::retriever *ui;
};

#endif // RETRIEVER_H
