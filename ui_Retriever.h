/********************************************************************************
** Form generated from reading UI file 'Retriever.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RETRIEVER_H
#define UI_RETRIEVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

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
            retriever->setObjectName(QStringLiteral("retriever"));
        retriever->resize(448, 294);
        layoutWidget = new QWidget(retriever);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 20, 401, 29));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(10);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        directoryedit = new QLineEdit(layoutWidget);
        directoryedit->setObjectName(QStringLiteral("directoryedit"));

        horizontalLayout->addWidget(directoryedit);

        selectfile = new QPushButton(layoutWidget);
        selectfile->setObjectName(QStringLiteral("selectfile"));

        horizontalLayout->addWidget(selectfile);

        layoutWidget1 = new QWidget(retriever);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 90, 321, 29));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font1;
        font1.setFamily(QStringLiteral("Microsoft YaHei Light"));
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        label_2->setFont(font1);

        horizontalLayout_2->addWidget(label_2);

        nameedit = new QLineEdit(layoutWidget1);
        nameedit->setObjectName(QStringLiteral("nameedit"));

        horizontalLayout_2->addWidget(nameedit);

        OK_retrieve = new QPushButton(retriever);
        OK_retrieve->setObjectName(QStringLiteral("OK_retrieve"));
        OK_retrieve->setGeometry(QRect(348, 240, 81, 27));
        cancel = new QPushButton(retriever);
        cancel->setObjectName(QStringLiteral("cancel"));
        cancel->setGeometry(QRect(260, 240, 81, 27));

        retranslateUi(retriever);

        QMetaObject::connectSlotsByName(retriever);
    } // setupUi

    void retranslateUi(QDialog *retriever)
    {
        retriever->setWindowTitle(QApplication::translate("retriever", "Dialog", 0));
        label->setText(QApplication::translate("retriever", "Directory:", 0));
        selectfile->setText(QApplication::translate("retriever", "Select", 0));
        label_2->setText(QApplication::translate("retriever", "Filename", 0));
        OK_retrieve->setText(QApplication::translate("retriever", "OK", 0));
        cancel->setText(QApplication::translate("retriever", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class retriever: public Ui_retriever {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RETRIEVER_H
