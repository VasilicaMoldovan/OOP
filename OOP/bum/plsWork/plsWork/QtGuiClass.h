#pragma once

#include <QWidget>
#include "ui_QtGuiClass.h"
#include "Observer.h"
#include "Auctioneer.h"

class QtGuiClass : public QWidget, public Observer
{
	Q_OBJECT

private:
	Auctioneer& auct;
public:
	QtGuiClass(Auctioneer& c, QWidget *parent = Q_NULLPTR);
	~QtGuiClass();

	void update() override;

private:
	Ui::QtGuiClass ui;
	void connectButtons();
};
