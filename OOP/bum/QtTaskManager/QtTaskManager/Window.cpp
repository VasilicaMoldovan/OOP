#include "Window.h"
#include <qmessagebox.h>

Window::Window(Controller& ctrl, QWidget *parent)
	: QWidget(parent), ctrl{ctrl}
{
	ui.setupUi(this);
	this->ctrl.addObserver(this);
	this->populate();
	this->connectSignals();
}

void Window::startTask()
{
	QModelIndexList index = ui.listWidget->selectionModel()->selectedIndexes();
	int newIndex = index.at(0).row();
	std::string name = windowTitle().toStdString();
	int i = 0;
	for (auto elem : this->ctrl.getProgm())
	{
		if (elem.getName() == name)
		{
			i = elem.getId();
			break;
		}
	}

	try {
		Task t = this->ctrl.getTasksFromCtrl()[newIndex];
		this->ctrl.startNewTask(t, i);
		this->ctrl.notify();
	}
	catch (std::exception &error)
	{
		QMessageBox box;
		box.critical(0, "Error", error.what());
		return;
	}

}

void Window::removeTask()
{
	QModelIndexList index = ui.listWidget->selectionModel()->selectedIndexes();

	int newIndex = index.at(0).row();

	this->ctrl.removeOldTask(this->ctrl.getTasksFromCtrl()[newIndex].getDescription());

	this->ctrl.notify();
}

void Window::addTask()
{
	QString t = ui.taskEdit->text();
	std::string name = windowTitle().toStdString();
	int id = -1;
	for (auto elem : ctrl.getProgm())
	{
		if (elem.getName() == name)
		{
			id = elem.getId();
			break;
		}
	}
	this->ctrl.addNewTask(t.toStdString(), id);
	this->ctrl.notify();
}

void Window::populate()
{
	ui.listWidget->clear();

	for (auto elem : this->ctrl.getTasksFromCtrl())
	{
		if (elem.getStatus() == "in progress")
		{
			std::string name = "";
			for (auto e : this->ctrl.getProgm())
			{
				if (e.getId() == elem.getId())
				{
					name = e.getName();
					break;
				}
			}
			std::string aux = elem.toString();
			aux += ", ";
			aux += name;
			ui.listWidget->addItem(QString::fromStdString(aux));
		}
		else
			ui.listWidget->addItem(QString::fromStdString(elem.toString()));
	}
}

void Window::connectSignals()
{
	QObject::connect(ui.addButton, &QPushButton::clicked, this, &Window::addTask);
	QObject::connect(ui.removeButton, &QPushButton::clicked, this, &Window::removeTask);
	QObject::connect(ui.startButton, &QPushButton::clicked, this, &Window::startTask);
}

void Window::update()
{
	this->populate();
}

Window::~Window()
{
	this->ctrl.deleteObserver(this);
}
