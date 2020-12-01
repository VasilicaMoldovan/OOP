#pragma once
#include "repo.h"

class TaskControllerModeA {
private:
	TaskRepository controllerVector;
public:
	TaskControllerModeA() {};
	void addNewRefurbishment(TElem newTask);
	void updateExistingRefurbishment(TElem newTask);
	void deleteRefurbishment(TElem newTask);
	void listAllRefurbishments(char finalOutput[]);
};

class TaskControllerModeB {
private:
	TaskRepository controllerVector;
public:
	TaskControllerModeB() {};
	void listAllRefurbishments(char finalOutput[]);

};