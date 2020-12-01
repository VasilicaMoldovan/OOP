#pragma once

#include <QWidget>
#include "ui_ServantView.h"

class ServantView : public QWidget
{
	Q_OBJECT
private:
	QAbstractItemModel* model;
public:
	ServantView(QAbstractItemModel* model, QWidget *parent = Q_NULLPTR);
	~ServantView();
	void setServant();

private:
	Ui::ServantView ui;
};
