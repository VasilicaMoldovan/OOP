#pragma once
#include "C:\Qt\5.12.3\msvc2017_64\include\QtWidgets\qwidget.h"
#include "Controller.h"
#include <qlistwidget.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <iostream>
#include <qobject.h>
#include <qshortcut.h>
#include "ServantView.h"
#include "MyModel.h"

class gui : public QWidget
{
	Q_OBJECT
private:
	int numberOfNexts;
	int mode;
	std::string filename;
	std::string csvPath;
	TaskControllerModeA controllerRefurbishments;
	QListWidget *refurbishmentData;
	QListWidget *modeBData;
	QLineEdit *title, *type, *date, *numberOfRepetitions, *mirrorImage, *fileName, *csvHtmlPath;
	QLineEdit *typeB, *timesPerformed;
	QPushButton *addButton, *removeButton, *updateButton;
	QPushButton *nextButton, *saveButton, *listButton, *mylistButton;
	QPushButton *changeMode, *exitButton, *savePathButton;
	QPushButton *undoButton, *redoButton;
	ServantView *view;
	MyModel *model;
public:
	//gui(TaskControllerModeA controllerRefurbishments, std::string filename, std::string csvPath);
	gui(TaskControllerModeA controllerRefurbishments);

	~gui();

private:
	void construct();
	void populateTasksList();
	int getSelectedIndex();
	void connectSignalsAndSlots();
	void setPictureTableView();


	void listRefurbishmentChanged();
	void addButtonHandler();
	void deleteButtonHandler();
	void updateButtonHandler();
	void changeModeButtonHandler();
	void nextButtonHandler();
	void saveButtonHandler();
	void listButtonHandler();
	void mylistButtonHandler();
	void savePathHandler();
	void undoHandler();
	void redoHandler();
	
public slots:
	void addTask(const std::string& title, const std::string& type, const std::string& date, const int& numberOfRepetitions, const std::string& mirrorImage);
	void deleteTaskSlot(const std::string& title, const std::string& type, const std::string& date, const int& numberOfRepetitions, const std::string& mirrorImage);
	void updateTask(const std::string& title, const std::string& type, const std::string& date, const int& numberOfRepetitions, const std::string& mirrorImage);
	void changeModeSlot();
	void nextTask();
	void saveTask(const std::string& title);
	void listTasks(const std::string& type, const int& timesPerformed);
	void mylistTasks();
	void savePathTask(const std::string& file, const std::string& csvFile);
	void undoRefurbishment();
	void redoRefurbishment();

signals:
	void taskUpdatedSignal();
	void addSignal(const std::string& title, const std::string& type, const std::string& date, const int& numberOfRepetitions, const std::string& mirrorImage);
	void deleteSignal(const std::string& title, const std::string& type, const std::string& date, const int& numberOfRepetitions, const std::string& mirrorImage);
	void updateSignal(const std::string& title, const std::string& type, const std::string& date, const int& numberOfRepetitions, const std::string& mirrorImage);
	void changeModeSignal();
	void nextSignal();
	void saveSignal(const std::string& title);
	void listSignal(const std::string& type, const int& timesPerformed);
	void mylistSignal();
	void savePathSignal(const std::string& file, const std::string& csvFile);
	void undoSignal();
	void redoSignal();
};

