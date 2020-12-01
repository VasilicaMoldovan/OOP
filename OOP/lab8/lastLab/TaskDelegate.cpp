#include "TaskDelegate.h"
#include <QPixmap>
#include <QPainter>
#include "domain.h"

TaskDelegate::TaskDelegate(QWidget *parent) : QStyledItemDelegate{ parent }
{
}

void TaskDelegate::paint(QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index) const
{
	QString task = index.model()->data(index, Qt::EditRole).toString();

	// show a picture only in the second column; the other columns remain unchanged
	if (index.column() != 1)
	{
		QStyledItemDelegate::paint(painter, option, index);
		return;
	}

	if (task.contains("Task1"))
	{
		QPixmap pixMap("refurbishment1.jpg");
		painter->drawPixmap(option.rect, pixMap);
	}
	else if (task.contains("Task2"))
	{
		QPixmap pixMap("refurbishment3.jpg");
		painter->drawPixmap(option.rect, pixMap);
	}
}

QSize TaskDelegate::sizeHint(const QStyleOptionViewItem & option, const QModelIndex & index) const
{
	// show a picture only in the second column; the other columns remain unchanged
	if (index.column() == 1)
	{
		return QSize(32, 100);
	}

	return QStyledItemDelegate::sizeHint(option, index);
}
