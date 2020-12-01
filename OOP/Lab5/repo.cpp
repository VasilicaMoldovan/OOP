#include "repo.h"
#include <cstring>
#include <cstdlib>
using namespace std;
//#include <new>

void TaskRepository::addNewTask(TElem newTask) {
	this->repositoryVector.addElement(newTask);
}

void TaskRepository::updateExistingTask(TElem newTask) {
	this->repositoryVector.updateElement(newTask);
}

void TaskRepository::deleteTask(TElem newTask) {
	this->repositoryVector.deleteElement(newTask);
}

void TaskRepository::listAllTasks(char tasksOutput[]) {
	TElem* tasksToPrint = this->repositoryVector.getAllElems();
	strcpy(tasksOutput, "");
	char buffer[15];
	for (int index = 0; index < this->repositoryVector.getNumberOfElements(); index++) {
		strcat(tasksOutput, "Title: ");
		strcat(tasksOutput, tasksToPrint[index].getTitle());
		strcat(tasksOutput, ", Type: ");
		strcat(tasksOutput, tasksToPrint[index].getType());
		strcat(tasksOutput, ", Last performed: ");
		strcat(tasksOutput, tasksToPrint[index].getDate());
		strcat(tasksOutput, ", Times performes: ");
		_itoa(tasksToPrint[index].getNumberOfRepetitions(), buffer, 10);
		strcat(tasksOutput, buffer);
		strcat(tasksOutput, ", Vision: ");
		strcat(tasksOutput, tasksToPrint[index].getMirrorImage());
		strcat(tasksOutput, "\n");
	}
}
