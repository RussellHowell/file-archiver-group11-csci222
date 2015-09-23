/********************************************************************************
** Form generated from reading UI file 'setreference.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETREFERENCE_H
#define UI_SETREFERENCE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_setreference
{
public:
    QLabel *label;
    QLabel *picture;
    QPushButton *pushButton;
    QPushButton *cancel;

    void setupUi(QDialog *setreference)
    {
        if (setreference->objectName().isEmpty())
            setreference->setObjectName(QString::fromUtf8("setreference"));
        setreference->resize(266, 135);
        setreference->setStyleSheet(QString::fromUtf8("border-color: rgb(4, 4, 4);"));
        label = new QLabel(setreference);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(90, 30, 161, 16));
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft YaHei"));
        font.setPointSize(12);
        font.setBold(false);
        font.setWeight(50);
        label->setFont(font);
        picture = new QLabel(setreference);
        picture->setObjectName(QString::fromUtf8("picture"));
        picture->setGeometry(QRect(20, 40, 61, 51));
        picture->setScaledContents(true);
        pushButton = new QPushButton(setreference);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(190, 90, 61, 23));
        cancel = new QPushButton(setreference);
        cancel->setObjectName(QString::fromUtf8("cancel"));
        cancel->setGeometry(QRect(110, 90, 75, 23));

        retranslateUi(setreference);

        QMetaObject::connectSlotsByName(setreference);
    } // setupUi

    void retranslateUi(QDialog *setreference)
    {
        setreference->setWindowTitle(QApplication::translate("setreference", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("setreference", "Set reference version", 0, QApplication::UnicodeUTF8));
        picture->setText(QString());
        pushButton->setText(QApplication::translate("setreference", "Ok", 0, QApplication::UnicodeUTF8));
        cancel->setText(QApplication::translate("setreference", "Cancel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class setreference: public Ui_setreference {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETREFERENCE_H
