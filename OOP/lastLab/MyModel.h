#pragma once
#include <QAbstractTableModel>
#include "repo.h"

class MyModel : public QAbstractTableModel
{
private:
	TaskRepository& repository;
public:
	MyModel(TaskRepository& repository);
	~MyModel();

	int rowCount(const QModelIndex &parent = QModelIndex()) const override;
	int columnCount(const QModelIndex &parent = QModelIndex()) const override;
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
	QVariant headerData(int section, Qt::Orientation orientation, int role) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
	Qt::ItemFlags flags(const QModelIndex &index) const override;

	void rowInserted()
	{
		int row = rowCount() - 1;
		if (row < 0)
			row = 0;

		beginInsertRows(QModelIndex(), row, row);
		endInsertRows();
	}
	void reset()
	{
		beginResetModel();
		endResetModel();
	}
};

