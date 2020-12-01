#include "BachelorTheses.h"
#include <QtWidgets/QApplication>
#include "Controller.h"
#include "window.h"
#include "Tests.h"

int main(int argc, char *argv[])
{
	Tests t{};
	t.testAdd();
	t.testSearch();

	QApplication a(argc, argv);
	Repository repo{};
	Controller controller{ repo };

	for (auto elem : controller.getAllTeachers())
	{
		window* gui = new window{ controller, elem.getTeacherName()};
		//gui->setWindowTitle(QString::fromStdString(elem.getTeacherName()));
		gui->show();
	}

	return a.exec();
}
