#pragma once
#include "domain.h"

typedef Refurbishment Refurbishment;

class TaskRepository {
protected:
	std::vector<Refurbishment> repositoryVector;
	std::string pathToFile;
public:
	TaskRepository() {};
	TaskRepository(std::string pathToFile) : pathToFile{ pathToFile } {};
	virtual void addNewTask(Refurbishment newTask);
	void updateExistingTask(Refurbishment newTask);
	virtual void deleteTask(Refurbishment newTask);
	void deletePosition(int index);
	std::vector<Refurbishment> getAllTasks() const;
	std::vector<Refurbishment>& getTasks() { return this->repositoryVector; }
	int getNumberOfAllTasks();
	Refurbishment getChoreFromPosition(int position);
	Refurbishment findChoreByTitle(std::string titleOfTheChore);
	std::vector<Refurbishment> getAllChoresWithProperty(std::string typeOfTheChore, int numberOfRepetitions);
	virtual void readFromFile(std::string pathToFile) = 0;
	virtual void writeToFile() = 0;
	void setPath(std::string pathToFile);
	std::string getPath() { return this->pathToFile; }
	virtual void openRepoFile();
};

class InMemoryRepo : public TaskRepository {
public:
	InMemoryRepo() : TaskRepository{} {};
	InMemoryRepo(TaskRepository *repo);
	void readFromFile(std::string pathToFile) { return; };
	void writeToFile() { return; };
};

class FileRepository : public TaskRepository {
private:
	std::string extensionOfFile;
public:
	FileRepository(std::string pathToFile) : TaskRepository{ pathToFile } {};
	FileRepository() : TaskRepository{} {};
	//void deleteTask(Refurbishment newTask) { return; }
	void readFromFile(std::string pathToFile);
	void writeToFile();
};

class CSVRepository : public TaskRepository {
private:
	std::string extensionOfFile;
public:
	void setExtension(std::string extensionOfFile);
	void deleteTask(Refurbishment newTask) { return; }
	void writeToFile();
	void readFromFile(std::string pathToFile) { return; };
};


class HtmlRepository : public TaskRepository {
private:
	std::string extensionOfFile;
public:
	void setExtension(std::string extensionOfFile);
	void writeToFile();
	//void deleteTask(Refurbishment newTask) { return; }
	void readFromFile(std::string pathToFile) { return; }
};

class TestRepository : public TaskRepository {
private:
	std::string extensionOfFile;
public:
	//void deleteTask(Refurbishment newTask) { return; }
	void readFromFile(std::string pathToFile) { return; }
	void writeToFile() { return; }
};