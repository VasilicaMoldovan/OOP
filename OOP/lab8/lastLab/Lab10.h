#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_Lab10.h"
#include "Controller.h"
#include "domain.h"
#include <QtWidgets/qmainwindow.h>
#include <QtWidgets/qlistwidget.h>
#include <QtWidgets/qboxlayout.h>
#include <QtWidgets/qlineedit.h>
#include <QtWidgets/qformlayout.h>
#include <QtWidgets/qlabel.h>
#include <QtWidgets/qpushbutton.h>
#include <QtWidgets/qradiobutton.h>
#include <QtWidgets/qmessagebox.h>
#include <QtWidgets/qbuttongroup.h>
#include <vector>
#include <algorithm>

class Lab10 : public QMainWindow
{
	Q_OBJECT

public:
	Lab10(QWidget *parent = Q_NULLPTR);

private:
	Ui::Lab10Class ui;
};
