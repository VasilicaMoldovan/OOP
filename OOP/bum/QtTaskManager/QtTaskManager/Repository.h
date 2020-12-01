#pragma once
#include "Domain.h"
#include <vector>

class Repository
{
private:
	std::vector<Programmer> programmers;
	std::vector<Task> tasks;
	int id;
public:
	Repository();
	std::vector<std::string> readFromFile(std::string path);
	std::vector<std::string> tokenize(std::string elem);
	void readProgrammers();
	void readTasks();
	std::vector<Programmer> getProgrammers() { return this->programmers; }
	std::vector<Task> getTasks() { return this->tasks; }
	~Repository();
	void addElement(std::string desc, int id);
	void deleteTask(std::string desc);
	void changeStatus(Task t, int id);
};

