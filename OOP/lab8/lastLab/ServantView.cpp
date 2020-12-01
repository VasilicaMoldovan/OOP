#include "ServantView.h"
#include "domain.h"
#include "MyModel.h"
#include "TaskDelegate.h"


ServantView::ServantView(QAbstractItemModel* model, QWidget *parent)
	: QWidget(parent), model{model}
{
	ui.setupUi(this);

	this->ui.tableView->setModel(this->model);
}

void ServantView::setServant()
{
	//this->ui.tableView->setModel(this->model);
	/*this->ui.tableView->setItemDelegate(new TaskDelegate{});
	
	// force the columns to resize, according to the size of their contents
	this->ui.tableView->resizeColumnsToContents();
	this->ui.tableView->resizeRowsToContents();
	// hide the vertical header
	this->ui.tableView->verticalHeader()->hide();*/
}

ServantView::~ServantView()
{
}
