#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtTaskManager.h"

class QtTaskManager : public QMainWindow
{
	Q_OBJECT

public:
	QtTaskManager(QWidget *parent = Q_NULLPTR);

private:
	Ui::QtTaskManagerClass ui;
};
