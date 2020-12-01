/********************************************************************************
** Form generated from reading UI file 'QtGuiTest.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTGUITEST_H
#define UI_QTGUITEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtGuiTestClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout;
    QListWidget *illnessData;
    QLineEdit *disorderEdit;
    QPushButton *searchButton;
    QGridLayout *gridLayout;
    QListWidget *symtomsData;
    QLineEdit *nameEdit;
    QPushButton *showButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtGuiTestClass)
    {
        if (QtGuiTestClass->objectName().isEmpty())
            QtGuiTestClass->setObjectName(QString::fromUtf8("QtGuiTestClass"));
        QtGuiTestClass->resize(812, 646);
        centralWidget = new QWidget(QtGuiTestClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        illnessData = new QListWidget(centralWidget);
        illnessData->setObjectName(QString::fromUtf8("illnessData"));

        verticalLayout->addWidget(illnessData);

        disorderEdit = new QLineEdit(centralWidget);
        disorderEdit->setObjectName(QString::fromUtf8("disorderEdit"));

        verticalLayout->addWidget(disorderEdit);

        searchButton = new QPushButton(centralWidget);
        searchButton->setObjectName(QString::fromUtf8("searchButton"));

        verticalLayout->addWidget(searchButton);


        gridLayout_2->addLayout(verticalLayout, 0, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        symtomsData = new QListWidget(centralWidget);
        symtomsData->setObjectName(QString::fromUtf8("symtomsData"));

        gridLayout->addWidget(symtomsData, 0, 0, 1, 1);

        nameEdit = new QLineEdit(centralWidget);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));

        gridLayout->addWidget(nameEdit, 1, 0, 1, 1);

        showButton = new QPushButton(centralWidget);
        showButton->setObjectName(QString::fromUtf8("showButton"));

        gridLayout->addWidget(showButton, 2, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 1, 1, 1);

        QtGuiTestClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QtGuiTestClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 812, 26));
        QtGuiTestClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtGuiTestClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        QtGuiTestClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(QtGuiTestClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        QtGuiTestClass->setStatusBar(statusBar);

        retranslateUi(QtGuiTestClass);

        QMetaObject::connectSlotsByName(QtGuiTestClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtGuiTestClass)
    {
        QtGuiTestClass->setWindowTitle(QApplication::translate("QtGuiTestClass", "QtGuiTest", nullptr));
        searchButton->setText(QApplication::translate("QtGuiTestClass", "Search Disorders", nullptr));
        showButton->setText(QApplication::translate("QtGuiTestClass", "Show symtoms", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtGuiTestClass: public Ui_QtGuiTestClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTGUITEST_H
