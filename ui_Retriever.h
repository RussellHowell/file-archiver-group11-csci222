/********************************************************************************
** Form generated from reading UI file 'Retriever.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RETRIEVER_H
#define UI_RETRIEVER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_retriever
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *directoryedit;
    QPushButton *selectfile;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *nameedit;
    QPushButton *OK_retrieve;
    QPushButton *cancel;

    void setupUi(QDialog *retriever)
    {
        if (retriever->objectName().isEmpty())
            retriever->setObjectName(QString::fromUtf8("retriever"));
        retriever->resize(448, 294);
        layoutWidget = new QWidget(retriever);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 20, 401, 29));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(10);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        directoryedit = new QLineEdit(layoutWidget);
        directoryedit->setObjectName(QString::fromUtf8("directoryedit"));

        horizontalLayout->addWidget(directoryedit);

        selectfile = new QPushButton(layoutWidget);
        selectfile->setObjectName(QString::fromUtf8("selectfile"));

        horizontalLayout->addWidget(selectfile);

        layoutWidget1 = new QWidget(retriever);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 90, 321, 29));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Microsoft YaHei Light"));
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        label_2->setFont(font1);

        horizontalLayout_2->addWidget(label_2);

        nameedit = new QLineEdit(layoutWidget1);
        nameedit->setObjectName(QString::fromUtf8("nameedit"));

        horizontalLayout_2->addWidget(nameedit);

        OK_retrieve = new QPushButton(retriever);
        OK_retrieve->setObjectName(QString::fromUtf8("OK_retrieve"));
        OK_retrieve->setGeometry(QRect(348, 240, 81, 27));
        cancel = new QPushButton(retriever);
        cancel->setObjectName(QString::fromUtf8("cancel"));
        cancel->setGeometry(QRect(260, 240, 81, 27));

        retranslateUi(retriever);

        QMetaObject::connectSlotsByName(retriever);
    } // setupUi

    void retranslateUi(QDialog *retriever)
    {
        retriever->setWindowTitle(QApplication::translate("retriever", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("retriever", "Directory:", 0, QApplication::UnicodeUTF8));
        selectfile->setText(QApplication::translate("retriever", "Select", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("retriever", "Filename", 0, QApplication::UnicodeUTF8));
        OK_retrieve->setText(QApplication::translate("retriever", "OK", 0, QApplication::UnicodeUTF8));
        cancel->setText(QApplication::translate("retriever", "Cancel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class retriever: public Ui_retriever {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RETRIEVER_H
