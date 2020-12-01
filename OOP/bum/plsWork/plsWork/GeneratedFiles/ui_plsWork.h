/********************************************************************************
** Form generated from reading UI file 'plsWork.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLSWORK_H
#define UI_PLSWORK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_plsWorkClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QListWidget *listWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *plsWorkClass)
    {
        if (plsWorkClass->objectName().isEmpty())
            plsWorkClass->setObjectName(QString::fromUtf8("plsWorkClass"));
        plsWorkClass->resize(600, 400);
        centralWidget = new QWidget(plsWorkClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        horizontalLayout->addWidget(listWidget);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        plsWorkClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(plsWorkClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 26));
        plsWorkClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(plsWorkClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        plsWorkClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(plsWorkClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        plsWorkClass->setStatusBar(statusBar);

        retranslateUi(plsWorkClass);

        QMetaObject::connectSlotsByName(plsWorkClass);
    } // setupUi

    void retranslateUi(QMainWindow *plsWorkClass)
    {
        plsWorkClass->setWindowTitle(QApplication::translate("plsWorkClass", "plsWork", nullptr));
        pushButton->setText(QApplication::translate("plsWorkClass", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class plsWorkClass: public Ui_plsWorkClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLSWORK_H
