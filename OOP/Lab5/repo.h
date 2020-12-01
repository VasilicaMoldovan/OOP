#pragma once
#include "dynamicVector.h"

class TaskRepository {
private:
	DynamicVector repositoryVector;
public:
	TaskRepository() {};
	void addNewTask(TElem newTask);
	void updateExistingTask(TElem newTask);
	void deleteTask(TElem newTask);
	void listAllTasks(char tasksOutput[]);
	//~TaskRepository();
};
