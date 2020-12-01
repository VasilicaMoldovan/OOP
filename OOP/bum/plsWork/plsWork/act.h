#pragma once

#include <QWidget>
#include "ui_act.h"
#include "Observer.h"

class act : public QWidget
{
	Q_OBJECT

public:
	act(QWidget *parent = Q_NULLPTR);
	~act();

private:
	Ui::act ui;
};
