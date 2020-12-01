/********************************************************************************
** Form generated from reading UI file 'screenWritter.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCREENWRITTER_H
#define UI_SCREENWRITTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_screenWritterClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QListWidget *listWidget;
    QPushButton *addButton;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QPushButton *saveButton;
    QPushButton *savePlotButton;
    QPushButton *developButton;
    QPushButton *reviseButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *screenWritterClass)
    {
        if (screenWritterClass->objectName().isEmpty())
            screenWritterClass->setObjectName(QString::fromUtf8("screenWritterClass"));
        screenWritterClass->resize(600, 400);
        centralWidget = new QWidget(screenWritterClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        gridLayout->addWidget(listWidget, 0, 0, 1, 7);

        addButton = new QPushButton(centralWidget);
        addButton->setObjectName(QString::fromUtf8("addButton"));

        gridLayout->addWidget(addButton, 1, 0, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 1, 1, 1);

        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout->addWidget(lineEdit, 1, 2, 1, 3);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 5, 1, 1);

        lineEdit_2 = new QLineEdit(centralWidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        gridLayout->addWidget(lineEdit_2, 1, 6, 1, 1);

        saveButton = new QPushButton(centralWidget);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));

        gridLayout->addWidget(saveButton, 2, 0, 1, 1);

        savePlotButton = new QPushButton(centralWidget);
        savePlotButton->setObjectName(QString::fromUtf8("savePlotButton"));

        gridLayout->addWidget(savePlotButton, 2, 1, 1, 2);

        developButton = new QPushButton(centralWidget);
        developButton->setObjectName(QString::fromUtf8("developButton"));

        gridLayout->addWidget(developButton, 2, 3, 1, 1);

        reviseButton = new QPushButton(centralWidget);
        reviseButton->setObjectName(QString::fromUtf8("reviseButton"));

        gridLayout->addWidget(reviseButton, 2, 4, 1, 1);

        screenWritterClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(screenWritterClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 26));
        screenWritterClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(screenWritterClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        screenWritterClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(screenWritterClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        screenWritterClass->setStatusBar(statusBar);

        retranslateUi(screenWritterClass);

        QMetaObject::connectSlotsByName(screenWritterClass);
    } // setupUi

    void retranslateUi(QMainWindow *screenWritterClass)
    {
        screenWritterClass->setWindowTitle(QApplication::translate("screenWritterClass", "screenWritter", nullptr));
        addButton->setText(QApplication::translate("screenWritterClass", "ADD", nullptr));
        label->setText(QApplication::translate("screenWritterClass", "IDEA:", nullptr));
        label_2->setText(QApplication::translate("screenWritterClass", "ACT:", nullptr));
        saveButton->setText(QApplication::translate("screenWritterClass", "SAVE", nullptr));
        savePlotButton->setText(QApplication::translate("screenWritterClass", "SAVE PLOT", nullptr));
        developButton->setText(QApplication::translate("screenWritterClass", "DEVELOP", nullptr));
        reviseButton->setText(QApplication::translate("screenWritterClass", "REVISE", nullptr));
    } // retranslateUi

};

namespace Ui {
    class screenWritterClass: public Ui_screenWritterClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCREENWRITTER_H
