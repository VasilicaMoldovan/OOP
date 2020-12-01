#include "QtGuiTest.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	controllerIllness listOfDisorders;
	listOfDisorders.loadFromFileIllness("input.txt");
	QtGuiTest w{ listOfDisorders };
	w.show();
	return a.exec();
}
