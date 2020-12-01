#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtGuiTest.h"
#include "controllerIllness.h"

class QtGuiTest : public QMainWindow
{
	Q_OBJECT
private:
	controllerIllness &illnessList;
public:
	QtGuiTest(controllerIllness &illnessList, QWidget *parent = Q_NULLPTR);

private:
	Ui::QtGuiTestClass ui;
	void populateList();
private slots:
	void handleSearch();
	void handleShow();
};
