/********************************************************************************
** Form generated from reading UI file 'Archiver.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ARCHIVER_H
#define UI_ARCHIVER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTableView>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Archiver
{
public:
    QWidget *centralWidget;
    QLabel *label_2;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *fileEdit;
    QPushButton *file_button;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout;
    QPushButton *save_button;
    QPushButton *retrieve_button;
    QPushButton *reference_button;
    QPushButton *comment_button;
    QTableView *fileviewer;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Archiver)
    {
        if (Archiver->objectName().isEmpty())
            Archiver->setObjectName(QString::fromUtf8("Archiver"));
        Archiver->resize(696, 404);
        centralWidget = new QWidget(Archiver);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 60, 141, 21));
        QFont font;
        font.setFamily(QString::fromUtf8("MS Sans Serif"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        label_2->setFont(font);
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 10, 651, 29));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("MS Sans Serif"));
        font1.setPointSize(11);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);

        horizontalLayout->addWidget(label);

        fileEdit = new QLineEdit(layoutWidget);
        fileEdit->setObjectName(QString::fromUtf8("fileEdit"));

        horizontalLayout->addWidget(fileEdit);

        file_button = new QPushButton(layoutWidget);
        file_button->setObjectName(QString::fromUtf8("file_button"));

        horizontalLayout->addWidget(file_button);

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(500, 110, 161, 191));
        gridLayout = new QGridLayout(layoutWidget1);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        save_button = new QPushButton(layoutWidget1);
        save_button->setObjectName(QString::fromUtf8("save_button"));

        gridLayout->addWidget(save_button, 0, 0, 1, 1);

        retrieve_button = new QPushButton(layoutWidget1);
        retrieve_button->setObjectName(QString::fromUtf8("retrieve_button"));

        gridLayout->addWidget(retrieve_button, 1, 0, 1, 1);

        reference_button = new QPushButton(layoutWidget1);
        reference_button->setObjectName(QString::fromUtf8("reference_button"));

        gridLayout->addWidget(reference_button, 2, 0, 1, 1);

        comment_button = new QPushButton(layoutWidget1);
        comment_button->setObjectName(QString::fromUtf8("comment_button"));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(168, 168, 168, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(252, 252, 252, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(210, 210, 210, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(84, 84, 84, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(112, 112, 112, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush6(QColor(255, 255, 255, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        QBrush brush7(QColor(211, 211, 211, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush7);
        QBrush brush8(QColor(255, 255, 220, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        comment_button->setPalette(palette);

        gridLayout->addWidget(comment_button, 3, 0, 1, 1);

        fileviewer = new QTableView(centralWidget);
        fileviewer->setObjectName(QString::fromUtf8("fileviewer"));
        fileviewer->setGeometry(QRect(20, 110, 461, 191));
        Archiver->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Archiver);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 696, 25));
        Archiver->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Archiver);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Archiver->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Archiver);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Archiver->setStatusBar(statusBar);

        retranslateUi(Archiver);

        QMetaObject::connectSlotsByName(Archiver);
    } // setupUi

    void retranslateUi(QMainWindow *Archiver)
    {
        Archiver->setWindowTitle(QApplication::translate("Archiver", "Archiver", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Archiver", "Version Data", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Archiver", "File", 0, QApplication::UnicodeUTF8));
        file_button->setText(QApplication::translate("Archiver", "Select File", 0, QApplication::UnicodeUTF8));
        save_button->setText(QApplication::translate("Archiver", "Save Current", 0, QApplication::UnicodeUTF8));
        retrieve_button->setText(QApplication::translate("Archiver", "Retrieve Version", 0, QApplication::UnicodeUTF8));
        reference_button->setText(QApplication::translate("Archiver", "Set as reference", 0, QApplication::UnicodeUTF8));
        comment_button->setText(QApplication::translate("Archiver", "Show Comment", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Archiver: public Ui_Archiver {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ARCHIVER_H
