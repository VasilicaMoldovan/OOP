#pragma once
#include "repo.h"
#include "validator.h"
#include <cstring>

class TaskControllerModeA {
private:
	//TaskRepository controllerVector;
	TaskRepository* controllerVector;
	RefurbishmentValidator taskValidator;
	RepositoryValidator *repoValidator;
	TaskRepository* listOfChores;
	
public:
	TaskControllerModeA(TaskRepository *controllerVector, TaskRepository *listOfChores, RepositoryValidator *repoValidator);
	TaskControllerModeA() {};
	bool addNewRefurbishment(Refurbishment newTask);
	bool existingTask(Refurbishment newTask);
	bool updateExistingRefurbishment(Refurbishment newTask);
	bool deleteRefurbishment(Refurbishment newTask);
	std::vector<Refurbishment> getAllRefurbishments() const;
	int getNumberOfRefurbishments();
	Refurbishment seeNextChore(int position);
	void saveCurrentChore(std::string titleOfTheChore);
	std::vector<Refurbishment> listAllChoresOfTypeAndProperty(std::string typeOfTheChore, int numberOfRepetitions, int& lengthOfVector);
	std::vector<Refurbishment> getAllSavedChores(int& numberOfChores);
	void readRepositoryFromFile(std::string pathToFile);
	void writeRepoToFile();
	void savePath(std::string pathToFile);
	void saveExtension(std::string extensionOfFile);
	void writeToCSVHtmlFile(std::string extensionOfFile);
	void setRepositoryType(std::string extensionOfFile);
	void openFile();
};