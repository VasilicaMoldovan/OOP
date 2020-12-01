#include "window.h"
#include <qmessagebox.h>
#include <fstream>

window::window(Controller& controller, std::string name, QWidget *parent)
	: QWidget(parent), controller{controller}
{
	setWindowTitle(QString::fromStdString(name));
	ui.setupUi(this);
	setWindowTitle(QString::fromStdString(name));
	this->populate();
	this->connectSignals();
	this->controller.addObserver(this);
}

void window::connectSignals()
{
	QObject::connect(ui.seacrhEdit, &QLineEdit::textChanged, this, &window::showSearch);
	QObject::connect(ui.addButton, &QPushButton::clicked, this, &window::addFunction);
	QObject::connect(ui.editButton, &QPushButton::clicked, this, &window::fileFunction);
	QObject::connect(ui.fileButton, &QPushButton::clicked, this, &window::createFile);
	//QObject::connect(ui.searchButton, &QPushButton::clicked, this, &window::showSearch);
}

void window::createFile()
{
	QModelIndexList index = ui.searchWidget->selectionModel()->selectedIndexes();

	int newIndex = index.at(0).row();
	std::string teacherName = windowTitle().toStdString();
	std::vector<Student> result = this->controller.getStudentsByTeacher(teacherName);

	std::string path = result[newIndex].getName();
	path += ".txt";
	std::ifstream file(path);
	//file << teacherName.c_str() << " approves the thesis " << result[newIndex].getTitle().c_str() << " authored by " << result[newIndex].getName().c_str();
	file.close();
}

void window::fileFunction()
{
	std::string teacherName = windowTitle().toStdString();
	this->gui = new studentGui{ controller , teacherName};
	this->gui->show();
}

void window::addFunction()
{
	QModelIndexList index = ui.searchWidget->selectionModel()->selectedIndexes();

	int newIndex = index.at(0).row();

	std::string teacherName = windowTitle().toStdString();
	std::string name = ui.seacrhEdit->text().toStdString();

	std::vector<Student> result = this->controller.getStudentsForSearch(name);
	try {
		this->controller.addCoordinator(result[newIndex], teacherName);
	}
	catch (std::exception &error)
	{
		QMessageBox box;
		box.critical(0, "Error", error.what());
		box.show();
	}

	this->controller.notify();
}

void window::showSearch()
{
	ui.searchWidget->clear();
	std::string name = ui.seacrhEdit->text().toStdString();

	for (auto elem : this->controller.getStudentsForSearch(name))
	{
		ui.searchWidget->addItem(QString::fromStdString(elem.toString()));
	}
}


void window::update()
{
	this->populate();
}


void window::populate()
{
	ui.listWidget->clear();
	std::string name = windowTitle().toStdString();
	for (auto elem : this->controller.getStudentsByTeacher(name))
	{
		ui.listWidget->addItem(QString::fromStdString(elem.toString()));
	}
}
window::~window()
{
}
