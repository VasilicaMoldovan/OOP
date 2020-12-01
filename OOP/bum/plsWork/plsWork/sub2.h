#pragma once

#include <QWidget>
#include "ui_sub2.h"
#include "Auctioneer.h"
#include "Observer.h"

class sub2 : public QWidget, public Observer
{
	Q_OBJECT

private:
	Auctioneer& auct;
public:
	sub2(Auctioneer& c, QWidget *parent = Q_NULLPTR);
	~sub2();
	void update() override;
	void addQuestion();
	void seeAnswers();
	void populate();
	void addAnswer();

private:
	Ui::sub2 ui;
	void connectButtons();
};
