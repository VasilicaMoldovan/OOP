#include "QtGuiClass.h"

QtGuiClass::QtGuiClass(Auctioneer& c, QWidget *parent)
	: QWidget(parent), auct{c}
{
	ui.setupUi(this);
	//std::unique_ptr<Observer> p = std::make_unique<QtGuiClass>(c, parent);
	//this->auct.addObserver(std::move(p));
	this->auct.addObserver(this);
	//this->update();
	this->connectButtons();
}

void QtGuiClass::update()
{
	ui.listWidget->clear();
	Question q = this->auct.searchQuestion(ui.searchEdit->text().toStdString());
	std::vector<Answer> print = this->auct.searchAnswers(q);

	ui.listWidget->addItem(QString::fromStdString(q.toString()));
	for (auto elem : print)
	{
		ui.listWidget->addItem(QString::fromStdString(elem.toString()));
	}
}

void QtGuiClass::connectButtons()
{
	QObject::connect(ui.searchButton, &QPushButton::clicked, this, &QtGuiClass::update);

}

QtGuiClass::~QtGuiClass()
{
}
