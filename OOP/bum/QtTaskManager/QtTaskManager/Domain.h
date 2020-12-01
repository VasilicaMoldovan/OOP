#pragma once
#include <string>

class Programmer
{
private:
	std::string name;
	int id;
public:
	Programmer() : name{""}, id{0} {}
	Programmer(std::string n, int i) : name{n}, id{i} {}
	std::string getName() const { return this->name; }
	int getId() const { return this->id; }
	std::string toString();
};

class Task
{
private:
	std::string description;
	std::string status; //open, in progress, closed
	int id;
public:
	Task() : description{""}, status{""}, id{0} {}
	Task(std::string d, std::string s) : description{d}, status{s}, id{0} {}
	Task(std::string d, std::string s, int i) : description{d}, status{s}, id{i} {}
	std::string getDescription() const { return this->description; }
	std::string getStatus() const { return this->status; }
	int getId() const { return this->id; }
	std::string toString();
	void setStatus(std::string s) { this->status = s; }
	void setId(int i) { this->id = i; }
};

