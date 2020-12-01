#include "controller.h"
#include <iostream>
#include <algorithm>


void TaskControllerModeA::deletePositions(std::string mode)
{
	if (mode == "A")
	{
		if (this->listOfActionsModeA.size() > 0 && numberOfUndos < listOfActionsModeA.size())
			this->listOfActionsModeA.erase(this->listOfActionsModeA.begin() + numberOfUndos + 1, this->listOfActionsModeA.end());
	}
	else
	{
		if (this->listOfActionsModeB.size() > 0 && undoB < listOfActionsModeB.size())
			this->listOfActionsModeB.erase(this->listOfActionsModeB.begin() + undoB + 1, this->listOfActionsModeB.end());
	}
}


void TaskControllerModeA::undoTask(std::string mode)
{
	if (mode == "A")
	{
		if (numberOfUndos >= 0)
		{
			this->listOfActionsModeA[numberOfUndos]->executeUndo();
			numberOfUndos--;
		}
		else
			throw RefurbishmentException("No possible undo");
	}
	else
	{
		if (undoB >= 0)
		{
			this->listOfActionsModeB[undoB]->executeUndo();
			undoB--;
		}
		else
			throw RefurbishmentException("No possible undo");
	}
}

void TaskControllerModeA::redoTask(std::string mode)
{
	if (mode == "A")
	{
		if (numberOfUndos != this->listOfActionsModeA.size() - 1)
		{
			numberOfUndos++;
			this->listOfActionsModeA[numberOfUndos]->executeRedo();
		}
		else
			throw RefurbishmentException("No possible undo");
	}
	else
	{
		if (undoB != this->listOfActionsModeB.size() - 1)
		{
			undoB++;
			this->listOfActionsModeB[undoB]->executeRedo();
		}
		else
			throw RefurbishmentException("No possible undo");
	}
}

void TaskControllerModeA::openFile() {
	this->listOfChores->openRepoFile();
}

TaskControllerModeA::TaskControllerModeA(TaskRepository *controllerVector, TaskRepository *listOfChores, RepositoryValidator *repoValidator) {
	this->controllerVector = controllerVector;
	this->listOfChores = listOfChores;
	this->repoValidator = repoValidator;
	this->numberOfUndos = -1;
	this->undoB = -1;
	this->redoB = 0;
	this->numberOfRedos = 0;
}

void TaskControllerModeA::readRepositoryFromFile(std::string pathToFile) {
	this->controllerVector->readFromFile(pathToFile);
}

//functions for mode A
bool TaskControllerModeA::addNewRefurbishment(Refurbishment newTask) {
	bool valid1, valid2;
	valid1 = this->taskValidator.validateRefurbishment(newTask);
	valid2 = this->repoValidator->validateAdd(newTask, this->controllerVector->getAllTasks());
	this->controllerVector->addNewTask(newTask);
	this->controllerVector->writeToFile();
	
	this->deletePositions("A");
	UndoRedoAdd undo = UndoRedoAdd(*this->controllerVector);
	undo.setAddedTask(newTask);
	std::shared_ptr<UndoRedoAction> pointer = std::make_shared<UndoRedoAdd>(undo);
	this->listOfActionsModeA.push_back(pointer);
	this->numberOfUndos++;
	return (valid1 && valid2);
}

bool TaskControllerModeA::updateExistingRefurbishment(Refurbishment newTask) {
	bool valid1, valid2;
	valid1 = this->taskValidator.validateRefurbishment(newTask);
	valid2 = this->repoValidator->validateDeleteOrUpdate(newTask, this->controllerVector->getAllTasks());
	Refurbishment oldTask = this->controllerVector->findChoreByTitle(newTask.getTitle());
	this->controllerVector->updateExistingTask(newTask);
	this->controllerVector->writeToFile();
	
	this->deletePositions("A");
	UndoRedoUpdate undo = UndoRedoUpdate(*this->controllerVector);
	undo.setUpdatedTask(newTask);
	undo.setOldTask(oldTask);
	std::shared_ptr<UndoRedoAction> pointer = std::make_shared<UndoRedoUpdate>(undo);
	this->listOfActionsModeA.push_back(pointer);
	this->numberOfUndos++;
	//this->listOfActionsModeA.push_back(undo);
	return (valid1 && valid2);
}

bool TaskControllerModeA::deleteRefurbishment(Refurbishment newTask) {
	bool valid1;
	//valid1 = this->repoValidator->validateDeleteOrUpdate(newTask, this->controllerVector->getAllTasks());
	this->controllerVector->deleteTask(newTask);
	this->controllerVector->writeToFile();
	
	this->deletePositions("A");
	UndoRedoRemove undo = UndoRedoRemove(*this->controllerVector);
	undo.setDeletedTask(newTask);
	std::shared_ptr<UndoRedoAction> pointer = std::make_shared<UndoRedoRemove>(undo);
	this->listOfActionsModeA.push_back(pointer);
	this->numberOfUndos++;

	return valid1;
}

void  TaskControllerModeA::deleteFromPosition(int index)
{
	this->controllerVector->deletePosition(index);
	this->controllerVector->writeToFile();
}

std::vector<Refurbishment> TaskControllerModeA::getAllRefurbishments() const {
	return this->controllerVector->getAllTasks();
}

int TaskControllerModeA::getNumberOfRefurbishments() {
	return this->controllerVector->getNumberOfAllTasks();
}

Refurbishment TaskControllerModeA::getRefurbishmentFromPosition(int index) {
	return this->controllerVector->getChoreFromPosition(index);
}

//functions for mode B
Refurbishment TaskControllerModeA::seeNextChore(int position) {
	return this->controllerVector->getChoreFromPosition(position);

}
void TaskControllerModeA::saveCurrentChore(std::string titleOfTheChore) {
	Refurbishment chore = this->controllerVector->findChoreByTitle(titleOfTheChore);
	this->listOfChores->addNewTask(chore);
	
	this->deletePositions("B");
	UndoRedoSave undo = UndoRedoSave(*this->listOfChores);
	undo.setSavedTask(chore);
	std::shared_ptr<UndoRedoAction> pointer = std::make_shared<UndoRedoSave>(undo);
	this->listOfActionsModeB.push_back(pointer);
	this->undoB++;
}

std::vector<Refurbishment> TaskControllerModeA::listAllChoresOfTypeAndProperty(std::string typeOfTheChore, int numberOfRepetitions, int& lengthOfVector) {
	return this->controllerVector->getAllChoresWithProperty(typeOfTheChore, numberOfRepetitions);
}

std::vector<Refurbishment> TaskControllerModeA::getAllSavedChores(int& numberOfChores) {
	numberOfChores = this->listOfChores->getNumberOfAllTasks();
	return this->listOfChores->getAllTasks();
}
void TaskControllerModeA::writeRepoToFile() {
	this->controllerVector->writeToFile();
}

void TaskControllerModeA::savePath(std::string pathToFile) {
	this->listOfChores->setPath(pathToFile);
}

void TaskControllerModeA::saveExtension(std::string extensionOfFile) {
	this->listOfChores = new FileRepository();
	//this->listOfChores->setExtension(extensionOfFile);
}

void TaskControllerModeA::writeToCSVHtmlFile(std::string extensionOfFile) {
	this->listOfChores->writeToFile();
}

void TaskControllerModeA::setRepositoryType(std::string extensionOfFile) {
	if (extensionOfFile == "csv") {
		delete this->listOfChores;
		CSVRepository *newRepository = new CSVRepository();
		this->listOfChores = newRepository;
	}
	else {
		if (extensionOfFile == "html") {
			delete this->listOfChores;
			HtmlRepository *newRepository = new HtmlRepository();
			this->listOfChores = newRepository;
		}
		else
		{
			delete this->controllerVector;
			FileRepository *newRepository = new FileRepository();
			this->controllerVector = newRepository;
		}
	}
}