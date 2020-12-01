#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_BachelorTheses.h"

class BachelorTheses : public QMainWindow
{
	Q_OBJECT

public:
	BachelorTheses(QWidget *parent = Q_NULLPTR);

private:
	Ui::BachelorThesesClass ui;
};
