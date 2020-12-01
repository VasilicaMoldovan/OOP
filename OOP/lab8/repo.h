#pragma once
#include "dynamicVector.h"
#include "domain.h"

typedef Refurbishment TElem;

class TaskRepository {
protected:
	std::vector<TElem> repositoryVector;
	std::string pathToFile;
public:
	TaskRepository() {};
	void addNewTask(TElem newTask);
	void updateExistingTask(TElem newTask);
	void deleteTask(TElem newTask);
	std::vector<TElem> getAllTasks() const;
	int getNumberOfAllTasks();
	TElem getChoreFromPosition(int position);
	TElem findChoreByTitle(std::string titleOfTheChore);
	std::vector<TElem> getAllChoresWithProperty(std::string typeOfTheChore, int numberOfRepetitions);
	void readFromFile(std::string pathToFile);
	void writeToFile();
};