#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QuestionAndAnswer.h"
#include "Repo.h"
#include "Observer.h"

class QuestionAndAnswer : public QMainWindow,public Observer
{
	Q_OBJECT

public:
	QuestionAndAnswer(Repo& repos, User u, QWidget *parent = Q_NULLPTR);

private:
	Ui::QuestionAndAnswerClass ui;
	Repo& repo;
	User user;
	void afisare();
	void print(int qui);
	void update()override { this->afisare(); }

private slots:
	void handleAdd();
	void handleAnswer();
	void handleSelect(QListWidgetItem* h);
	//void handleUpvote();
};
