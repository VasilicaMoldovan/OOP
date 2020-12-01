#pragma once
#include "repo.h"

class UndoRedoAction
{
public:
	virtual bool executeUndo() = 0;
	virtual bool executeRedo() = 0;
	virtual ~UndoRedoAction();
};

class UndoRedoAdd : public UndoRedoAction
{
private:
	Refurbishment addedTask;
	TaskRepository &taskRepository;
public:
	UndoRedoAdd(TaskRepository &repository) : taskRepository(repository) {};
	void setAddedTask(Refurbishment newTask);
	bool executeUndo();
	bool executeRedo();
};

class UndoRedoRemove : public UndoRedoAction
{
private:
	Refurbishment deletedTask;
	TaskRepository &taskRepository;
public:
	UndoRedoRemove(TaskRepository &repository) : taskRepository(repository) {};
	void setDeletedTask(Refurbishment newTask);
	bool executeUndo();
	bool executeRedo();
};

class UndoRedoUpdate : public UndoRedoAction
{
private:
	Refurbishment updatedTask;
	Refurbishment oldTask;
	TaskRepository &taskRepository;
public:
	UndoRedoUpdate(TaskRepository &repository) : taskRepository(repository) {}
	void setUpdatedTask(Refurbishment newTask);
	void setOldTask(Refurbishment oldTask);
	bool executeUndo();
	bool executeRedo();
};

class UndoRedoSave : public UndoRedoAction
{
private:
	Refurbishment savedTask;
	TaskRepository &taskRepository;
public:
	UndoRedoSave(TaskRepository &repository) : taskRepository(repository) {};
	void setSavedTask(Refurbishment newTask);
	bool executeUndo();
	bool executeRedo();
};

class UndoRedoNext : public UndoRedoAction 
{
public:
	bool executeUndo();
	bool executeRedo();

};