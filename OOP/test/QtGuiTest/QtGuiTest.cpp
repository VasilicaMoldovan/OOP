#include "QtGuiTest.h"

QtGuiTest::QtGuiTest(controllerIllness &illnessList, QWidget *parent)
	: QMainWindow(parent), illnessList(illnessList)
{
	ui.setupUi(this);
	populateList();

	connect(ui.searchButton, SIGNAL(released()), this, SLOT(this->handleSearch()));
	connect(ui.showButton, SIGNAL(released()), this, SLOT(this->handleShow()));
}

void QtGuiTest::populateList()
{
	for (auto elem : this->illnessList.getAllDisorders())
	{
		ui.illnessData->addItem(QString::fromStdString(elem.toString()));
	}
}

void QtGuiTest::handleShow()
{
	ui.symtomsData->clear();
	QString disorder = ui.disorderEdit->text();
	ui.symtomsData->addItem(QString::fromStdString(this->illnessList.showSymtoms(disorder.toStdString())));
}

void QtGuiTest::handleSearch()
{
	ui.illnessData->clear();
	QString disorder = ui.disorderEdit->text();
	for (auto elem : this->illnessList.searchByNameOrCategory(disorder.toStdString()))
	{
		ui.illnessData->addItem(QString::fromStdString(elem.toString()));
	}
}
