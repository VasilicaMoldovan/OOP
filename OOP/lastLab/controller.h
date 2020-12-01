#pragma once
#include "repo.h"
#include "validator.h"
#include <cstring>
#include <memory>
#include "UndoAction.h"

class TaskControllerModeA {
private:
	//TaskRepository controllerVector;
	TaskRepository* controllerVector;
	RefurbishmentValidator taskValidator;
	RepositoryValidator *repoValidator;
	TaskRepository* listOfChores;
	std::vector<std::shared_ptr<UndoRedoAction>> listOfActionsModeA;
	std::vector<std::shared_ptr<UndoRedoAction>> listOfActionsModeB;
	int numberOfUndos, numberOfRedos;
	int undoB, redoB;

	void deletePositions(std::string mode);
public:
	void undoTask(std::string mode);
	void redoTask(std::string mode);
	TaskRepository* getListOfChores() { return this->listOfChores; }
	TaskControllerModeA(TaskRepository *controllerVector, TaskRepository *listOfChores, RepositoryValidator *repoValidator);
	TaskControllerModeA() {};
	bool addNewRefurbishment(Refurbishment newTask);
	bool existingTask(Refurbishment newTask);
	bool updateExistingRefurbishment(Refurbishment newTask);
	bool deleteRefurbishment(Refurbishment newTask);
	void deleteFromPosition(int index);
	std::vector<Refurbishment> getAllRefurbishments() const;
	int getNumberOfRefurbishments();
	Refurbishment getRefurbishmentFromPosition(int index);
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