/********************************************************************************
** Form generated from reading UI file 'codeReview.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CODEREVIEW_H
#define UI_CODEREVIEW_H

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

class Ui_codeReviewClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QPushButton *addButton;
    QPushButton *revisButton;
    QLineEdit *lineEdit;
    QLabel *labelDone;
    QLabel *labelLeft;
    QListWidget *listWidget;
    QPushButton *selectButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *codeReviewClass)
    {
        if (codeReviewClass->objectName().isEmpty())
            codeReviewClass->setObjectName(QString::fromUtf8("codeReviewClass"));
        codeReviewClass->resize(600, 400);
        centralWidget = new QWidget(codeReviewClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        addButton = new QPushButton(centralWidget);
        addButton->setObjectName(QString::fromUtf8("addButton"));

        gridLayout->addWidget(addButton, 2, 0, 1, 2);

        revisButton = new QPushButton(centralWidget);
        revisButton->setObjectName(QString::fromUtf8("revisButton"));

        gridLayout->addWidget(revisButton, 1, 3, 1, 1);

        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout->addWidget(lineEdit, 2, 3, 1, 1);

        labelDone = new QLabel(centralWidget);
        labelDone->setObjectName(QString::fromUtf8("labelDone"));

        gridLayout->addWidget(labelDone, 1, 1, 1, 1);

        labelLeft = new QLabel(centralWidget);
        labelLeft->setObjectName(QString::fromUtf8("labelLeft"));

        gridLayout->addWidget(labelLeft, 1, 0, 1, 1);

        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        gridLayout->addWidget(listWidget, 0, 0, 1, 4);

        selectButton = new QPushButton(centralWidget);
        selectButton->setObjectName(QString::fromUtf8("selectButton"));

        gridLayout->addWidget(selectButton, 1, 2, 1, 1);

        codeReviewClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(codeReviewClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 26));
        codeReviewClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(codeReviewClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        codeReviewClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(codeReviewClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        codeReviewClass->setStatusBar(statusBar);

        retranslateUi(codeReviewClass);

        QMetaObject::connectSlotsByName(codeReviewClass);
    } // setupUi

    void retranslateUi(QMainWindow *codeReviewClass)
    {
        codeReviewClass->setWindowTitle(QApplication::translate("codeReviewClass", "codeReview", nullptr));
        addButton->setText(QApplication::translate("codeReviewClass", "ADD", nullptr));
        revisButton->setText(QApplication::translate("codeReviewClass", "REVISE", nullptr));
        labelDone->setText(QApplication::translate("codeReviewClass", "Done: 5", nullptr));
        labelLeft->setText(QApplication::translate("codeReviewClass", "Left: 9 ", nullptr));
        selectButton->setText(QApplication::translate("codeReviewClass", "SELECT", nullptr));
    } // retranslateUi

};

namespace Ui {
    class codeReviewClass: public Ui_codeReviewClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CODEREVIEW_H
