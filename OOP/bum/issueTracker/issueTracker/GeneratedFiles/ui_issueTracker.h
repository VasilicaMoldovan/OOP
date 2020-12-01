/********************************************************************************
** Form generated from reading UI file 'issueTracker.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ISSUETRACKER_H
#define UI_ISSUETRACKER_H

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

class Ui_issueTrackerClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QListWidget *listWidget;
    QPushButton *addButton;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *removeButton;
    QPushButton *selectButton;
    QPushButton *resolveButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *issueTrackerClass)
    {
        if (issueTrackerClass->objectName().isEmpty())
            issueTrackerClass->setObjectName(QString::fromUtf8("issueTrackerClass"));
        issueTrackerClass->resize(600, 400);
        centralWidget = new QWidget(issueTrackerClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        gridLayout->addWidget(listWidget, 0, 0, 1, 4);

        addButton = new QPushButton(centralWidget);
        addButton->setObjectName(QString::fromUtf8("addButton"));

        gridLayout->addWidget(addButton, 1, 0, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 1, 1, 1);

        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout->addWidget(lineEdit, 1, 2, 1, 2);

        removeButton = new QPushButton(centralWidget);
        removeButton->setObjectName(QString::fromUtf8("removeButton"));

        gridLayout->addWidget(removeButton, 2, 0, 1, 1);

        selectButton = new QPushButton(centralWidget);
        selectButton->setObjectName(QString::fromUtf8("selectButton"));

        gridLayout->addWidget(selectButton, 2, 2, 1, 1);

        resolveButton = new QPushButton(centralWidget);
        resolveButton->setObjectName(QString::fromUtf8("resolveButton"));

        gridLayout->addWidget(resolveButton, 2, 3, 1, 1);

        issueTrackerClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(issueTrackerClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 26));
        issueTrackerClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(issueTrackerClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        issueTrackerClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(issueTrackerClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        issueTrackerClass->setStatusBar(statusBar);

        retranslateUi(issueTrackerClass);

        QMetaObject::connectSlotsByName(issueTrackerClass);
    } // setupUi

    void retranslateUi(QMainWindow *issueTrackerClass)
    {
        issueTrackerClass->setWindowTitle(QApplication::translate("issueTrackerClass", "issueTracker", nullptr));
        addButton->setText(QApplication::translate("issueTrackerClass", "ADD", nullptr));
        label->setText(QApplication::translate("issueTrackerClass", "ISSUE:", nullptr));
        removeButton->setText(QApplication::translate("issueTrackerClass", "REMOVE", nullptr));
        selectButton->setText(QApplication::translate("issueTrackerClass", "SELECT", nullptr));
        resolveButton->setText(QApplication::translate("issueTrackerClass", "RESOLVE", nullptr));
    } // retranslateUi

};

namespace Ui {
    class issueTrackerClass: public Ui_issueTrackerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ISSUETRACKER_H
