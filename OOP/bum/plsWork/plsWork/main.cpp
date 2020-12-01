#include "plsWork.h"
#include <QtWidgets/QApplication>
#include "Auctioneer.h"
#include "sub2.h"
#include "QtGuiClass.h"
#include <iostream>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Repository repo{};
	Auctioneer auct{ repo };

	for (auto elem : repo.getUsers())
	{
		sub2* gui = new sub2{ auct };
		gui->setWindowTitle(QString::fromStdString(elem.getName()));
		gui->show();
	}
	
	QtGuiClass diff{ auct };
	diff.show();

	//repo.writeToFile();
	return a.exec();

	//repo.writeToFile();

	//return 0;
}
