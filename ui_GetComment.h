/********************************************************************************
** Form generated from reading UI file 'GetComment.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GETCOMMENT_H
#define UI_GETCOMMENT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_GetComment
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QTextEdit *textEdit;

    void setupUi(QDialog *GetComment)
    {
        if (GetComment->objectName().isEmpty())
            GetComment->setObjectName(QString::fromUtf8("GetComment"));
        GetComment->resize(392, 297);
        buttonBox = new QDialogButtonBox(GetComment);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 250, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(GetComment);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 20, 311, 21));
        QFont font;
        font.setFamily(QString::fromUtf8("MS Reference Sans Serif"));
        font.setPointSize(11);
        label->setFont(font);
        textEdit = new QTextEdit(GetComment);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(20, 50, 321, 171));

        retranslateUi(GetComment);
        QObject::connect(buttonBox, SIGNAL(accepted()), GetComment, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), GetComment, SLOT(reject()));

        QMetaObject::connectSlotsByName(GetComment);
    } // setupUi

    void retranslateUi(QDialog *GetComment)
    {
        GetComment->setWindowTitle(QApplication::translate("GetComment", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("GetComment", "Comment to go with version of file:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class GetComment: public Ui_GetComment {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GETCOMMENT_H
