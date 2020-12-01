/********************************************************************************
** Form generated from reading UI file 'act.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACT_H
#define UI_ACT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_act
{
public:

    void setupUi(QWidget *act)
    {
        if (act->objectName().isEmpty())
            act->setObjectName(QString::fromUtf8("act"));
        act->resize(400, 300);

        retranslateUi(act);

        QMetaObject::connectSlotsByName(act);
    } // setupUi

    void retranslateUi(QWidget *act)
    {
        act->setWindowTitle(QApplication::translate("act", "act", nullptr));
    } // retranslateUi

};

namespace Ui {
    class act: public Ui_act {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACT_H
