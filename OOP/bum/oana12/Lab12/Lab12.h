#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Lab12.h"
#include "Controller.h"

class Lab12 : public QMainWindow
{
	Q_OBJECT

public:
	Lab12(Controller & controller, QWidget *parent = Q_NULLPTR);

private:
	Controller & movieController;

private slots:
	void handleAddButton();
	void handleUpdateButton();
	void handleRemoveButton();
	void handleSaveIDButton();
	void handleSaveButton();
	void handleOpenExternallyButton();
	void handleNextButton();
	void handleUserlistButton();
	void handleFilterByLikesButton();
	void handleFilterByLikesGenreButton();
	void handleLoadFileButton();
	void handleUndoButton();
	void handleRedoButton();

private:
	Ui::Lab12Class ui;

	void populateAdminDatabase();
	void populateUserDatabase();
};
