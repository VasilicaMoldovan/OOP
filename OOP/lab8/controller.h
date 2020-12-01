#pragma once
#include "repo.h"
#include <cstring>

class TaskControllerModeA {
private:
	TaskRepository controllerVector;
	//FileRepository controllerVector;
	//
	TaskRepository listOfChores;

public:
	TaskControllerModeA() {};
	void addNewRefurbishment(TElem newTask);
	void updateExistingRefurbishment(TElem newTask);
	void deleteRefurbishment(TElem newTask);
	std::vector<TElem> getAllRefurbishments() const;
	int getNumberOfRefurbishments();
	TElem seeNextChore(int position);
	void saveCurrentChore(std::string titleOfTheChore);
	std::vector<TElem> listAllChoresOfTypeAndProperty(std::string typeOfTheChore, int numberOfRepetitions, int& lengthOfVector);
	std::vector<TElem> getAllSavedChores(int& numberOfChores);
	void readRepositoryFromFile(std::string pathToFile);
	void writeRepoToFile();
};