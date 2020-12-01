#include "QuestionAndAnswer.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Repo r;
	std::vector<User> users = r.returnUsers();
	for (auto i : users)
	{
		QuestionAndAnswer* w = new QuestionAndAnswer(r, i);
		r.addObserver(w);
		w->setWindowTitle(i.getName().c_str());
		w->show();
	}
	return a.exec();
}
