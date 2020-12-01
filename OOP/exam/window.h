#pragma once

#include <QWidget>
#include "ui_window.h"
#include "Controller.h"
#include "studentGui.h"

class window : public QWidget, public Observer
{
	Q_OBJECT

private:
	Controller& controller;
	studentGui* gui;
public:
	window(Controller& controller, std::string name, QWidget *parent = Q_NULLPTR);
	~window();
	void update();
	void populate();
	void showSearch();
	void addFunction();
	void fileFunction();
	void createFile();

private:
	Ui::window ui;
	void connectSignals();
};
