/********************************************************************************
** Form generated from reading UI file 'taskManager.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASKMANAGER_H
#define UI_TASKMANAGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
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

class Ui_taskManagerClass
{
public:
    QWidget *centralWidget;
    QListWidget *TaskListWidget;
    QPushButton *AddButton;
    QLineEdit *descriptionLineEdit;
    QLabel *descriptionLabel;
    QPushButton *doneButton;
    QPushButton *removeButton;
    QPushButton *STARTButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *taskManagerClass)
    {
        if (taskManagerClass->objectName().isEmpty())
            taskManagerClass->setObjectName(QString::fromUtf8("taskManagerClass"));
        taskManagerClass->resize(600, 400);
        centralWidget = new QWidget(taskManagerClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        TaskListWidget = new QListWidget(centralWidget);
        TaskListWidget->setObjectName(QString::fromUtf8("TaskListWidget"));
        TaskListWidget->setGeometry(QRect(0, 0, 591, 192));
        AddButton = new QPushButton(centralWidget);
        AddButton->setObjectName(QString::fromUtf8("AddButton"));
        AddButton->setGeometry(QRect(10, 210, 93, 28));
        descriptionLineEdit = new QLineEdit(centralWidget);
        descriptionLineEdit->setObjectName(QString::fromUtf8("descriptionLineEdit"));
        descriptionLineEdit->setGeometry(QRect(200, 210, 371, 22));
        descriptionLabel = new QLabel(centralWidget);
        descriptionLabel->setObjectName(QString::fromUtf8("descriptionLabel"));
        descriptionLabel->setGeometry(QRect(120, 210, 71, 20));
        doneButton = new QPushButton(centralWidget);
        doneButton->setObjectName(QString::fromUtf8("doneButton"));
        doneButton->setGeometry(QRect(10, 270, 93, 28));
        removeButton = new QPushButton(centralWidget);
        removeButton->setObjectName(QString::fromUtf8("removeButton"));
        removeButton->setGeometry(QRect(160, 270, 93, 28));
        STARTButton = new QPushButton(centralWidget);
        STARTButton->setObjectName(QString::fromUtf8("STARTButton"));
        STARTButton->setGeometry(QRect(320, 270, 93, 28));
        taskManagerClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(taskManagerClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 26));
        taskManagerClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(taskManagerClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        taskManagerClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(taskManagerClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        taskManagerClass->setStatusBar(statusBar);

        retranslateUi(taskManagerClass);

        QMetaObject::connectSlotsByName(taskManagerClass);
    } // setupUi

    void retranslateUi(QMainWindow *taskManagerClass)
    {
        taskManagerClass->setWindowTitle(QApplication::translate("taskManagerClass", "taskManager", nullptr));
        AddButton->setText(QApplication::translate("taskManagerClass", "ADD", nullptr));
        descriptionLabel->setText(QApplication::translate("taskManagerClass", "description:", nullptr));
        doneButton->setText(QApplication::translate("taskManagerClass", "DONE", nullptr));
        removeButton->setText(QApplication::translate("taskManagerClass", "REMOVE", nullptr));
        STARTButton->setText(QApplication::translate("taskManagerClass", "START", nullptr));
    } // retranslateUi

};

namespace Ui {
    class taskManagerClass: public Ui_taskManagerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASKMANAGER_H
