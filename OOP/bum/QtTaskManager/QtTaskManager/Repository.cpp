#include "Repository.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <stdexcept>

Repository::Repository()
{
	this->readProgrammers();
	this->readTasks();
}

void Repository::readTasks()
{
	std::vector<std::string> aux = this->readFromFile("f2.txt");
	std::string::size_type sz;

	for (auto& elem : aux)
	{
		std::vector<std::string> tokens = tokenize(elem);
		if (tokens.size() == 3)
		{
			this->tasks.push_back(Task{ tokens[0], tokens[1], std::stoi(tokens[2], &sz) });
		}
	}

	sort(tasks.begin(), tasks.end(), [](Task a, Task b) {return a.getStatus() < b.getStatus(); });
}

void Repository::readProgrammers()
{
	std::vector<std::string> aux = this->readFromFile("f1.txt");
	std::string::size_type sz;

	for (auto& elem : aux)
	{
		std::vector<std::string> tokens = tokenize(elem);
		if (tokens.size() == 2)
		{
			this->programmers.push_back(Programmer{ tokens[0], std::stoi(tokens[1], &sz) });
			id = std::stoi(tokens[1], &sz) + 1;
		}
	}

}

std::vector<std::string> Repository::tokenize(std::string elem)
{
	std::vector<std::string> tokens;
	std::string token;
	 
	std::istringstream stream{ elem };
	while (getline(stream, token, ','))
	{
		tokens.push_back(token);
	}
	return tokens;
}

std::vector<std::string> Repository::readFromFile(std::string path)
{
	std::vector<std::string> result;

	std::ifstream file(path);
	if (!file.is_open())
		return result;

	std::string input;
	while (!file.eof())
	{
		getline(file, input);
		if (input.length() > 0)
			result.push_back(input);
	}
	file.close();
	return result;
}

void Repository::addElement(std::string desc, int id)
{
	Task t{ desc, "open", id };
	this->tasks.push_back(t);
}

void Repository::deleteTask(std::string desc)
{
	int i = 0;
	for (int j = 0; j < this->tasks.size(); j++)
	{
		if (this->tasks[j].getDescription() == desc)
			break;
		i++;
	}
	this->tasks.erase(this->tasks.begin() + i);
}

void Repository::changeStatus(Task t, int id)
{
	bool ex = false;
	for (int i = 0; i < this->tasks.size(); i++)
	{
		if (this->tasks[i].getId() == t.getId())
		{
			if (this->tasks[i].getStatus() == "open")
			{
				this->tasks[i].setStatus("in progress");
				this->tasks[i].setId(id);
			}
			else
				ex = true;
			break;
		}
	}
	if (ex)
		throw std::exception("The task is not open!");
}

Repository::~Repository()
{
}
