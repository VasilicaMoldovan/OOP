#include "controller.h"

void TaskControllerModeA::addNewRefurbishment(TElem newTask) {
	this->controllerVector.addNewTask(newTask);
}

void TaskControllerModeA::updateExistingRefurbishment(TElem newTask) {
	this->controllerVector.updateExistingTask(newTask);
}

void TaskControllerModeA::deleteRefurbishment(TElem newTask) {
	this->controllerVector.deleteTask(newTask);
}

void TaskControllerModeA::listAllRefurbishments(char finalOutput[]) {
	this->controllerVector.listAllTasks(finalOutput);
}
