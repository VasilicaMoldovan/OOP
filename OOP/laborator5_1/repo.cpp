#include "repo.h"
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <Windows.h>
using namespace std;

int TaskRepository::getNumberOfAllTasks() {
	return this->repositoryVector.getNumberOfElements();
}

TElem* TaskRepository::getAllTasks() const {
	return this->repositoryVector.getAllElems();
}

void TaskRepository::addNewTask(TElem newTask) {
	this->repositoryVector.addElement(newTask);
}

void TaskRepository::updateExistingTask(TElem newTask) {
	this->repositoryVector.updateElement(newTask);
}

void TaskRepository::deleteTask(TElem newTask) {
	this->repositoryVector.deleteElement(newTask);
}

TElem TaskRepository::getChoreFromPosition(int position) {
	return this->repositoryVector.getElementFromPosition(position);
}

TElem TaskRepository::findChoreByTitle(char titleOfTheChore[]) {
	for (int index = 0; index <= this->repositoryVector.getNumberOfElements(); index++) {
		if (strcmp(this->repositoryVector.getElementFromPosition(index).getTitle(), titleOfTheChore) == 0) {
			return this->repositoryVector.getElementFromPosition(index);
		}
	}
}

DynamicVector<TElem> TaskRepository::getAllChoresWithProperty(char typeOfTheChore[], int numberOfRepetitions) {
	DynamicVector<TElem> choresWithProperty = DynamicVector<TElem>();
	for (int index = 0; index < this->repositoryVector.getNumberOfElements(); index++) {
		if (strstr(this->repositoryVector.getElementFromPosition(index).getType(), typeOfTheChore) != NULL && this->repositoryVector.getElementFromPosition(index).getNumberOfRepetitions() < numberOfRepetitions) {
			choresWithProperty.addElement(this->repositoryVector.getElementFromPosition(index));
		}
	}
	return choresWithProperty;
}
