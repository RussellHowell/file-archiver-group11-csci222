/********************************************************************************
** Form generated from reading UI file 'fileexplorer.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILEEXPLORER_H
#define UI_FILEEXPLORER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QTableView>
#include <QtGui/QTreeView>

QT_BEGIN_NAMESPACE

class Ui_fileexplorer
{
public:
    QTreeView *treeView;
    QTableView *tableView;

    void setupUi(QDialog *fileexplorer)
    {
        if (fileexplorer->objectName().isEmpty())
            fileexplorer->setObjectName(QString::fromUtf8("fileexplorer"));
        fileexplorer->resize(533, 273);
        treeView = new QTreeView(fileexplorer);
        treeView->setObjectName(QString::fromUtf8("treeView"));
        treeView->setGeometry(QRect(10, 10, 231, 251));
        tableView = new QTableView(fileexplorer);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(250, 10, 271, 251));

        retranslateUi(fileexplorer);

        QMetaObject::connectSlotsByName(fileexplorer);
    } // setupUi

    void retranslateUi(QDialog *fileexplorer)
    {
        fileexplorer->setWindowTitle(QApplication::translate("fileexplorer", "Dialog", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class fileexplorer: public Ui_fileexplorer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILEEXPLORER_H
