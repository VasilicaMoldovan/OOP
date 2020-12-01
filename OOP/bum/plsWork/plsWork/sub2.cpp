#include "sub2.h"
#include <qmessagebox.h>
#include <qtablewidget.h>

sub2::sub2(Auctioneer& c, QWidget *parent)
	: QWidget(parent), auct{c}
{
	ui.setupUi(this);
	//std::unique_ptr<Observer> p = std::make_unique<sub2>(c, parent);
	//this->auct.addObserver(std::move(p));
	this->auct.addObserver(this);
	this->connectButtons();
	this->populate();
}

void sub2::update()
{
	this->populate();
}

void sub2::populate()
{
	ui.listWidget->clear();
	for (auto& elem : this->auct.getQuestion())
	{
		ui.listWidget->addItem(QString::fromStdString(elem.toString()));
	}

	/*if (this->auct.getQuestion().size() > 0)
		ui.listWidget->setCurrentRow(0);*/
}

void sub2::connectButtons()
{
	QObject::connect(ui.addButton, &QPushButton::clicked, this, &sub2::addQuestion);
	QObject::connect(ui.listWidget, &QListWidget::itemSelectionChanged, this, &sub2::seeAnswers);
	QObject::connect(ui.answerButton, &QPushButton::clicked, this, &sub2::addAnswer);
}

void sub2::addQuestion()
{
	QString q = ui.descriptionEdit->text();
	std::string name = windowTitle().toStdString();
	try {
		this->auct.addQuestionToController(name, q.toStdString());
		this->auct.notify();
	}
	catch (std::exception &error)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", error.what());
		return;
	}
}

void sub2::seeAnswers()
{
	QModelIndexList index = ui.listWidget->selectionModel()->selectedIndexes();

	int newIndex = index.at(0).row();
	ui.secondList->clear();
	std::string name = windowTitle().toStdString();
	Question q = this->auct.getQuestion()[newIndex];
	for (auto elem : this->auct.giveAnswers(q))
	{
		if (elem.getName() == name)
		{
			setStyleSheet("background-color:yellow;");
		}
		ui.secondList->addItem(QString::fromStdString(elem.toString()));
	}

	//ui.secondList->setCurrentRow(0);
}

void sub2::addAnswer()
{
	QModelIndexList index = ui.listWidget->selectionModel()->selectedIndexes();

	int newIndex = index.at(0).row();
	ui.secondList->clear();
	std::string name = windowTitle().toStdString();
	Question q = this->auct.getQuestion()[newIndex];

	QString text = ui.descriptionEdit->text();

	try {
		this->auct.addAnswerToController(q.getId(), name, text.toStdString());
		//this->auct.notify();
	}
	catch (std::exception &error)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", error.what());
		return;
	}
}

sub2::~sub2()
{
}
