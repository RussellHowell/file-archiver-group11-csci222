/********************************************************************************
** Form generated from reading UI file 'GetComment.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GETCOMMENT_H
#define UI_GETCOMMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextEdit>

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
            GetComment->setObjectName(QStringLiteral("GetComment"));
        GetComment->resize(392, 297);
        buttonBox = new QDialogButtonBox(GetComment);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 250, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(GetComment);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 20, 311, 21));
        QFont font;
        font.setFamily(QStringLiteral("MS Reference Sans Serif"));
        font.setPointSize(11);
        label->setFont(font);
        textEdit = new QTextEdit(GetComment);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(20, 50, 321, 171));

        retranslateUi(GetComment);
        QObject::connect(buttonBox, SIGNAL(accepted()), GetComment, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), GetComment, SLOT(reject()));

        QMetaObject::connectSlotsByName(GetComment);
    } // setupUi

    void retranslateUi(QDialog *GetComment)
    {
        GetComment->setWindowTitle(QApplication::translate("GetComment", "Dialog", 0));
        label->setText(QApplication::translate("GetComment", "Comment to go with version of file:", 0));
    } // retranslateUi

};

namespace Ui {
    class GetComment: public Ui_GetComment {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GETCOMMENT_H
