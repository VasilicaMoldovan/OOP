/********************************************************************************
** Form generated from reading UI file 'QtTaskManager.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTTASKMANAGER_H
#define UI_QTTASKMANAGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtTaskManagerClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtTaskManagerClass)
    {
        if (QtTaskManagerClass->objectName().isEmpty())
            QtTaskManagerClass->setObjectName(QString::fromUtf8("QtTaskManagerClass"));
        QtTaskManagerClass->resize(600, 400);
        menuBar = new QMenuBar(QtTaskManagerClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        QtTaskManagerClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtTaskManagerClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        QtTaskManagerClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(QtTaskManagerClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        QtTaskManagerClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(QtTaskManagerClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        QtTaskManagerClass->setStatusBar(statusBar);

        retranslateUi(QtTaskManagerClass);

        QMetaObject::connectSlotsByName(QtTaskManagerClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtTaskManagerClass)
    {
        QtTaskManagerClass->setWindowTitle(QApplication::translate("QtTaskManagerClass", "QtTaskManager", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtTaskManagerClass: public Ui_QtTaskManagerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTTASKMANAGER_H
