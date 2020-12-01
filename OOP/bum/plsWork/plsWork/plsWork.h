#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_plsWork.h"

class plsWork : public QMainWindow
{
	Q_OBJECT

public:
	plsWork(QWidget *parent = Q_NULLPTR);

private:
	Ui::plsWorkClass ui;
};
