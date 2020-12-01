#include "controller.h"

void TaskControllerModeA::readRepositoryFromFile(std::string pathToFile) {
	this->controllerVector.readFromFile(pathToFile);
}

//functions for mode A
void TaskControllerModeA::addNewRefurbishment(TElem newTask) {
	this->controllerVector.addNewTask(newTask);
}

void TaskControllerModeA::updateExistingRefurbishment(TElem newTask) {
	this->controllerVector.updateExistingTask(newTask);
}

void TaskControllerModeA::deleteRefurbishment(TElem newTask) {
	this->controllerVector.deleteTask(newTask);
}

std::vector<TElem> TaskControllerModeA::getAllRefurbishments() const {
	return this->controllerVector.getAllTasks();
}

int TaskControllerModeA::getNumberOfRefurbishments() {
	return this->controllerVector.getNumberOfAllTasks();
}

//functions for mode B
TElem TaskControllerModeA::seeNextChore(int position) {
	return this->controllerVector.getChoreFromPosition(position);
}
void TaskControllerModeA::saveCurrentChore(std::string titleOfTheChore) {
	this->listOfChores.addNewTask(this->controllerVector.findChoreByTitle(titleOfTheChore));
}

std::vector<TElem> TaskControllerModeA::listAllChoresOfTypeAndProperty(std::string typeOfTheChore, int numberOfRepetitions, int& lengthOfVector) {
	return this->controllerVector.getAllChoresWithProperty(typeOfTheChore, numberOfRepetitions);
}

std::vector<TElem> TaskControllerModeA::getAllSavedChores(int& numberOfChores) {
	numberOfChores = this->listOfChores.getNumberOfAllTasks();
	return this->listOfChores.getAllTasks();
}
void TaskControllerModeA::writeRepoToFile() {
	this->controllerVector.writeToFile();
}