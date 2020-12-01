#include "MyModel.h"
#include <qcolor.h>
#include <string>

MyModel::MyModel(TaskRepository& repository) : repository(repository)
{
	
}

MyModel::~MyModel()
{
}

int MyModel::rowCount(const QModelIndex &parent) const
{
	return this->repository.getNumberOfAllTasks();
}

int MyModel::columnCount(const QModelIndex &parent) const
{
	return 5;
}

QVariant MyModel::data(const QModelIndex &index, int role) const
{
	int row = index.row();
	int col = index.column();

	Refurbishment& currentTask = this->repository.getTasks()[row];

	if (role == Qt::DisplayRole || role == Qt::EditRole )
	{
		switch (col)
		{
		case 0:
			return QString::fromStdString(currentTask.getTitle());
		case 1:
			return QString::fromStdString(currentTask.getType());
		case 2:
			return QString::fromStdString(currentTask.getDate());
		case 3:
			return QString::fromStdString(std::to_string(currentTask.getNumberOfRepetitions()));
		case 4:
			return QString::fromStdString(currentTask.getMirrorImage());
		default:
			break;
		}
	}

	if (role == Qt::BackgroundColorRole)
	{
		if (row % 2 == 0)
			return QColor{ "yellow" };
	}

	return QVariant();
}

QVariant MyModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (role == Qt::DisplayRole && orientation == Qt::Horizontal)
	{
		switch (section)
		{
		case 0:
			return "Title";
		case 1:
			return "Type";
		case 2:
			return "Date";
		case 3:
			return "Repetitions";
		case 4:
			return "Vision";
		}
	}
	return QVariant();
}

bool MyModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
	if (role == Qt::EditRole || role == Qt::DisplayRole)
	{
		Refurbishment& currentTask = this->repository.getAllTasks()[index.row()];
		int column = index.column();
		switch (column)
		{
		case 0:
		{
			currentTask.setTitle(value.toString().toStdString());
			break;
		}
		case 1:
		{
			currentTask.setType(value.toString().toStdString());
			break;
		}
		case 2:
		{
			currentTask.setDate(value.toString().toStdString());
			break;
		}
		case 3:
		{
			currentTask.setNumberOfRepetitions(atoi(value.toString().toStdString().c_str()));
			break;
		}
		case 4:
		{
			currentTask.setMirrorImage(value.toString().toStdString());
			break;
		}
		}
	}
	emit dataChanged(index, index);
	return true;
}

Qt::ItemFlags MyModel::flags(const QModelIndex &index) const
{
	return Qt::ItemIsEditable | QAbstractTableModel::flags(index);
}