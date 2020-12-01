#include "repo.h"
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <Windows.h>
#include <algorithm>
#include <fstream>
using namespace std;

int TaskRepository::getNumberOfAllTasks() {
	return this->repositoryVector.size();
}

std::vector<TElem> TaskRepository::getAllTasks() const {
	return this->repositoryVector;
}

void TaskRepository::addNewTask(TElem newTask) {
	this->repositoryVector.push_back(newTask);
}

void TaskRepository::updateExistingTask(TElem newTask) {
	for (int index = 0; index < this->repositoryVector.size(); index++) {
		if ( this->repositoryVector[index].getTitle() == newTask.getTitle()) {
			this->repositoryVector[index].setDate(newTask.getDate());
			this->repositoryVector[index].setMirrorImage(newTask.getMirrorImage());
			this->repositoryVector[index].setNumberOfRepetitions(newTask.getNumberOfRepetitions());
			this->repositoryVector[index].setType(newTask.getType());
			break;
		}
	}
}

void TaskRepository::deleteTask(TElem newTask) {
	for (int index = 0; index < this->repositoryVector.size(); index++) {
		if (this->repositoryVector[index].getTitle() == newTask.getTitle()) {
			this->repositoryVector.erase(this->repositoryVector.begin() + index);
			break;
		}
	}}

TElem TaskRepository::getChoreFromPosition(int position) {
	return this->repositoryVector[position];
}

TElem TaskRepository::findChoreByTitle(std::string titleOfTheChore) {
	for (auto chore : this->repositoryVector) {
		if ( chore.getTitle() == titleOfTheChore)
			return chore;
	}}

std::vector<TElem> TaskRepository::getAllChoresWithProperty(std::string typeOfTheChore, int numberOfRepetitions) {
	std::vector<TElem> choresWithProperty(this->repositoryVector.size());
	auto it = std::copy_if(this->repositoryVector.begin(), this->repositoryVector.end(), choresWithProperty.begin(), [typeOfTheChore, numberOfRepetitions](TElem chore) {return (chore.getType().find(typeOfTheChore) != string::npos && chore.getNumberOfRepetitions() < numberOfRepetitions); });
	choresWithProperty.resize(std::distance(choresWithProperty.begin(), it));
	return choresWithProperty;
}

void TaskRepository::readFromFile(std::string pathToFile) {
	this->pathToFile = pathToFile;
	ifstream f(pathToFile);
	if (!f.is_open())return;

	TElem task{"", "", "", 0, ""};
	while ( f >> task )
	{
		this->repositoryVector.push_back(task);
	}
	f.close();
}

void TaskRepository::writeToFile() {
	ofstream f(this->pathToFile);	
	if (!f.is_open())return;

	for (auto task : this->repositoryVector)
	{
		f << task;
	}

	f.close();
}