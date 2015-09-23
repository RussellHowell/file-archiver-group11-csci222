/********************************************************************************
** Form generated from reading UI file 'retriever.ui'
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
#include <QtGui/QDialogButtonBox>
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
    QDialogButtonBox *buttonBox;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *directoryedit;
    QPushButton *selectfile;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit;

    void setupUi(QDialog *retriever)
    {
        if (retriever->objectName().isEmpty())
            retriever->setObjectName(QString::fromUtf8("retriever"));
        retriever->resize(448, 294);
        buttonBox = new QDialogButtonBox(retriever);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(80, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        widget = new QWidget(retriever);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 20, 401, 25));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(10);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        directoryedit = new QLineEdit(widget);
        directoryedit->setObjectName(QString::fromUtf8("directoryedit"));

        horizontalLayout->addWidget(directoryedit);

        selectfile = new QPushButton(widget);
        selectfile->setObjectName(QString::fromUtf8("selectfile"));

        horizontalLayout->addWidget(selectfile);

        widget1 = new QWidget(retriever);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(10, 90, 321, 22));
        horizontalLayout_2 = new QHBoxLayout(widget1);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Microsoft YaHei Light"));
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        label_2->setFont(font1);

        horizontalLayout_2->addWidget(label_2);

        lineEdit = new QLineEdit(widget1);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout_2->addWidget(lineEdit);


        retranslateUi(retriever);
        QObject::connect(buttonBox, SIGNAL(accepted()), retriever, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), retriever, SLOT(reject()));

        QMetaObject::connectSlotsByName(retriever);
    } // setupUi

    void retranslateUi(QDialog *retriever)
    {
        retriever->setWindowTitle(QApplication::translate("retriever", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("retriever", "Directory:", 0, QApplication::UnicodeUTF8));
        selectfile->setText(QApplication::translate("retriever", "Select", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("retriever", "Filename", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class retriever: public Ui_retriever {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RETRIEVER_H
