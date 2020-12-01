#include "QtTaskManager.h"
#include <QtWidgets/QApplication>
#include "Repository.h"
#include "Controller.h"
#include "Window.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	Repository repo{};
	Controller ctrl{ repo };

	for (auto elem : ctrl.getProgm())
	{
		Window* gui = new Window{ ctrl };
		gui->setWindowTitle(QString::fromStdString(elem.getName()));
		gui->show();
	}
	
	return a.exec();
}
