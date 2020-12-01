#pragma once
#include "dynamicVector.h"
#include "domain.h"

typedef Refurbishment TElem;

class TaskRepository {
private:
	DynamicVector<TElem> repositoryVector;
public:
	TaskRepository() {};
	void addNewTask(TElem newTask);
	void updateExistingTask(TElem newTask);
	void deleteTask(TElem newTask);
	TElem* getAllTasks() const;
	int getNumberOfAllTasks();
	TElem getChoreFromPosition(int position);
	TElem findChoreByTitle(char titleOfTheChore[]);
	DynamicVector<TElem> getAllChoresWithProperty(char typeOfTheChore[], int numberOfRepetitions);
};
