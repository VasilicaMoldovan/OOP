#include "controller.h"
#include <iostream>

void TaskControllerModeA::openFile() {
	this->listOfChores->openRepoFile();
}

TaskControllerModeA::TaskControllerModeA(TaskRepository *controllerVector, TaskRepository *listOfChores, RepositoryValidator *repoValidator){
	this->controllerVector = controllerVector;
	this->listOfChores = listOfChores;
	this->repoValidator = repoValidator;
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
	return (valid1 && valid2);
}
/*
bool TaskControllerModeA::existingTask(TElem newTask) {
	return this->controllerVector.existingElement(newTask);
}*/

bool TaskControllerModeA::updateExistingRefurbishment(Refurbishment newTask) {
	bool valid1, valid2;
	valid1 = this->taskValidator.validateRefurbishment(newTask);
	valid2 = this->repoValidator->validateDeleteOrUpdate(newTask, this->controllerVector->getAllTasks());
	this->controllerVector->updateExistingTask(newTask);
	return (valid1 && valid2);
}

bool TaskControllerModeA::deleteRefurbishment(Refurbishment newTask) {
	bool valid1;
	valid1 = this->repoValidator->validateDeleteOrUpdate(newTask, this->controllerVector->getAllTasks());
	this->controllerVector->deleteTask(newTask);
	return valid1;
}

std::vector<Refurbishment> TaskControllerModeA::getAllRefurbishments() const {
	return this->controllerVector->getAllTasks();
}

int TaskControllerModeA::getNumberOfRefurbishments() {
	return this->controllerVector->getNumberOfAllTasks();
}

//functions for mode B
Refurbishment TaskControllerModeA::seeNextChore(int position) {
	return this->controllerVector->getChoreFromPosition(position);
}
void TaskControllerModeA::saveCurrentChore(std::string titleOfTheChore) {
	this->listOfChores->addNewTask(this->controllerVector->findChoreByTitle(titleOfTheChore));
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
	this->listOfChores =  new FileRepository();
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