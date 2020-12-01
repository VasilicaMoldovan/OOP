#pragma once
#include "repo.h"

class TaskControllerModeA {
private:
	TaskRepository controllerVector;
	//
	TaskRepository listOfChores;

public:
	TaskControllerModeA() {};
	void addNewRefurbishment(TElem newTask);
	void updateExistingRefurbishment(TElem newTask);
	void deleteRefurbishment(TElem newTask);
	TElem* getAllRefurbishments() const;
	int getNumberOfRefurbishments();
	TElem seeNextChore(int position);
	void saveCurrentChore(char titleOfTheChore[]);
	DynamicVector<TElem> listAllChoresOfTypeAndProperty(char typeOfTheChore[], int numberOfRepetitions, int& lengthOfVector);
	//TElem* listAllChoresOfTypeAndProperty(char typeOfTheChore[], int numberOfRepetitions, int& lengthOfVector);
	//DynamicVector<TElem> getAllSavedChores(int& numberOf);
	TElem* getAllSavedChores(int& numberOfChores);

};