#pragma once

#include <QWidget>
#include "ui_studentGui.h"
#include "Controller.h"

class studentGui : public QWidget, public Observer
{
	Q_OBJECT

private:
	Controller& controller;
	std::vector<Student> students;
	std::string name;
public:
	studentGui(Controller& controller, std::string name, QWidget *parent = Q_NULLPTR);
	~studentGui();
	void update();
	void populate();
	void edit();
	void cancel();

private:
	Ui::studentGui ui;
	void connectSignals();
};
