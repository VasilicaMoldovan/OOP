#pragma once
#include "Domain.h"
#include "Repository.h"
#include "Observer.h"

class Controller : public Subject
{
private:
	Repository& repo;
public:
	Controller(Repository& repo) : repo{repo} {}
	~Controller() {}
	std::vector<Programmer> getProgm() { return this->repo.getProgrammers(); }
	std::vector<Task> getTasksFromCtrl() { return this->repo.getTasks(); }
	void addNewTask(std::string desc, int id) { this->repo.addElement(desc, id); }
	void removeOldTask(std::string desc) { this->repo.deleteTask(desc); }
	void startNewTask(Task t, int id) { this->repo.changeStatus(t, id); }
};