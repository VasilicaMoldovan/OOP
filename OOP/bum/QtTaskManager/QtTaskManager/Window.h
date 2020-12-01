#pragma once

#include <QWidget>
#include "ui_Window.h"
#include "Observer.h"
#include "Controller.h"

class Window : public QWidget, public Observer
{
	Q_OBJECT

private:
	Controller& ctrl;

public:
	Window(Controller& ctrl , QWidget *parent = Q_NULLPTR);
	~Window();
	void update() override;
	void populate();
	void addTask();
	void removeTask();
	void startTask();

private:
	Ui::Window ui;
	void connectSignals();
};

