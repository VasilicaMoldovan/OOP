#pragma once
//#include <qstyleditemdelegate.h>
#include <QStyledItemDelegate>
#include "repo.h"

class TaskDelegate : public QStyledItemDelegate
{
public:
	TaskDelegate(QWidget *parent = 0);
	void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
	QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const override;
};

