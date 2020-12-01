#include "studentGui.h"

studentGui::studentGui(Controller& controller, std::string name, QWidget *parent)
	: QWidget(parent), controller{controller}, name{name}
{
	ui.setupUi(this);
	this->controller.addObserver(this);
	this->populate();
	this->connectSignals();
}

void studentGui::connectSignals()
{
	QObject::connect(ui.saveButton, &QPushButton::clicked, this, &studentGui::edit);
	QObject::connect(ui.cancelButton, &QPushButton::clicked, this, &studentGui::cancel);
}

void studentGui::cancel()
{
	ui.emailEdit->clear();
	ui.titleEdit->clear();
}

void studentGui::edit()
{
	std::string email = ui.emailEdit->text().toStdString();
	std::string title = ui.titleEdit->text().toStdString();
	
	QModelIndexList index = ui.studentsWidget->selectionModel()->selectedIndexes();

	int newIndex = index.at(0).row();
	std::vector<Student> students = this->controller.getCoord(name);

	this->controller.editStudent(students[newIndex].getId(), email, title);
	this->controller.notify();
}

void studentGui::update()
{
	this->populate();
}

void studentGui::populate()
{
	ui.studentsWidget->clear();
	std::vector<Student> students = this->controller.getCoord(name);
	for (auto elem : students)
	{
		ui.studentsWidget->addItem(QString::fromStdString(elem.toString()));
	}
}

studentGui::~studentGui()
{
}
