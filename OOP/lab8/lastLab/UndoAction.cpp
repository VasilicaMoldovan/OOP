#include "UndoAction.h"

bool UndoRedoAdd::executeUndo()
{
	this->taskRepository.deleteTask(this->addedTask);
	return true;
}

bool UndoRedoAdd::executeRedo()
{
	this->taskRepository.addNewTask(this->addedTask);
	return true;
}


void UndoRedoAdd::setAddedTask(Refurbishment newTask)
{
	this->addedTask.setDate(newTask.getDate());
	this->addedTask.setMirrorImage(newTask.getMirrorImage());
	this->addedTask.setNumberOfRepetitions(newTask.getNumberOfRepetitions());
	this->addedTask.setTitle(newTask.getTitle());
	this->addedTask.setType(newTask.getType());
}

bool UndoRedoRemove::executeUndo()
{
	this->taskRepository.addNewTask(this->deletedTask);
	return true;
}

bool UndoRedoRemove::executeRedo()
{
	this->taskRepository.deleteTask(this->deletedTask);
	return true;
}

void UndoRedoRemove::setDeletedTask(Refurbishment newTask)
{
	this->deletedTask.setDate(newTask.getDate());
	this->deletedTask.setMirrorImage(newTask.getMirrorImage());
	this->deletedTask.setNumberOfRepetitions(newTask.getNumberOfRepetitions());
	this->deletedTask.setTitle(newTask.getTitle());
	this->deletedTask.setType(newTask.getType());
}

bool UndoRedoUpdate::executeUndo()
{
	this->taskRepository.updateExistingTask(this->oldTask);
	return true;
}

bool UndoRedoUpdate::executeRedo()
{
	this->taskRepository.updateExistingTask(this->updatedTask);
	return true;
}

void UndoRedoUpdate::setOldTask(Refurbishment newTask)
{
	this->oldTask.setDate(newTask.getDate());
	this->oldTask.setMirrorImage(newTask.getMirrorImage());
	this->oldTask.setNumberOfRepetitions(newTask.getNumberOfRepetitions());
	this->oldTask.setTitle(newTask.getTitle());
	this->oldTask.setType(newTask.getType());
}

void UndoRedoUpdate::setUpdatedTask(Refurbishment newTask)
{
	this->updatedTask.setDate(newTask.getDate());
	this->updatedTask.setMirrorImage(newTask.getMirrorImage());
	this->updatedTask.setNumberOfRepetitions(newTask.getNumberOfRepetitions());
	this->updatedTask.setTitle(newTask.getTitle());
	this->updatedTask.setType(newTask.getType());
	//this->updatedTask = this->taskRepository.findChoreByTitle(newTask.getTitle());
}

bool UndoRedoSave::executeUndo()
{
	this->taskRepository.deleteTask(this->savedTask);
	return true;
}

bool UndoRedoSave::executeRedo()
{
	this->taskRepository.addNewTask(this->savedTask);
	return true;
}

void UndoRedoSave::setSavedTask(Refurbishment newTask)
{
	this->savedTask.setDate(newTask.getDate());
	this->savedTask.setMirrorImage(newTask.getMirrorImage());
	this->savedTask.setNumberOfRepetitions(newTask.getNumberOfRepetitions());
	this->savedTask.setTitle(newTask.getTitle());
	this->savedTask.setType(newTask.getType());
}

bool UndoRedoNext::executeUndo()
{
	return false;
}

bool UndoRedoNext::executeRedo()
{
	return false;
}

UndoRedoAction::~UndoRedoAction()
{
}