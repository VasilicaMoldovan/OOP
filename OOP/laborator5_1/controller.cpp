#include "controller.h"
#include <iostream>

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

TElem* TaskControllerModeA::getAllRefurbishments() const {
	return this->controllerVector.getAllTasks();
}

int TaskControllerModeA::getNumberOfRefurbishments() {
	return this->controllerVector.getNumberOfAllTasks();
}

//functions for mode B
TElem TaskControllerModeA::seeNextChore(int position) {
	return this->controllerVector.getChoreFromPosition(position);
}
void TaskControllerModeA::saveCurrentChore(char titleOfTheChore[]) {
	this->listOfChores.addNewTask(this->controllerVector.findChoreByTitle(titleOfTheChore));
	//this->listOfChores.addElement(this->controllerVector.findChoreByTitle(titleOfTheChore));
}

DynamicVector<TElem> TaskControllerModeA::listAllChoresOfTypeAndProperty(char typeOfTheChore[], int numberOfRepetitions, int& lengthOfVector) {
	DynamicVector<TElem> choresOfTypeAndProperty = DynamicVector<TElem>();
	return this->controllerVector.getAllChoresWithProperty(typeOfTheChore, numberOfRepetitions);
	// lengthOfVector = this->controllerVector.getAllChoresWithProperty(typeOfTheChore, numberOfRepetitions).getNumberOfElements();
	
	//return this->controllerVector.getAllChoresWithProperty(typeOfTheChore, numberOfRepetitions).getAllElems();
}

TElem* TaskControllerModeA::getAllSavedChores(int& numberOfChores) {
	numberOfChores = this->listOfChores.getNumberOfAllTasks();
	//numberOfChores = this->listOfChores.getNumberOfElements();
	return this->listOfChores.getAllTasks();
	//return this->listOfChores.getAllElems();
}
