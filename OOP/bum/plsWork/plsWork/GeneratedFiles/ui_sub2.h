/********************************************************************************
** Form generated from reading UI file 'sub2.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUB2_H
#define UI_SUB2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_sub2
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QListWidget *listWidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *descriptionEdit;
    QPushButton *addButton;
    QPushButton *answerButton;
    QListWidget *secondList;
    QSpinBox *spinBox;

    void setupUi(QWidget *sub2)
    {
        if (sub2->objectName().isEmpty())
            sub2->setObjectName(QString::fromUtf8("sub2"));
        sub2->resize(503, 366);
        gridLayout = new QGridLayout(sub2);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        listWidget = new QListWidget(sub2);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        horizontalLayout->addWidget(listWidget);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        descriptionEdit = new QLineEdit(sub2);
        descriptionEdit->setObjectName(QString::fromUtf8("descriptionEdit"));

        verticalLayout->addWidget(descriptionEdit);

        addButton = new QPushButton(sub2);
        addButton->setObjectName(QString::fromUtf8("addButton"));

        verticalLayout->addWidget(addButton);

        answerButton = new QPushButton(sub2);
        answerButton->setObjectName(QString::fromUtf8("answerButton"));

        verticalLayout->addWidget(answerButton);

        secondList = new QListWidget(sub2);
        secondList->setObjectName(QString::fromUtf8("secondList"));

        verticalLayout->addWidget(secondList);

        spinBox = new QSpinBox(sub2);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));

        verticalLayout->addWidget(spinBox);


        horizontalLayout->addLayout(verticalLayout);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);


        retranslateUi(sub2);

        QMetaObject::connectSlotsByName(sub2);
    } // setupUi

    void retranslateUi(QWidget *sub2)
    {
        sub2->setWindowTitle(QApplication::translate("sub2", "sub2", nullptr));
        addButton->setText(QApplication::translate("sub2", "Add", nullptr));
        answerButton->setText(QApplication::translate("sub2", "Answer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class sub2: public Ui_sub2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUB2_H
