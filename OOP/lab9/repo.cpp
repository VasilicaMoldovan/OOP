#include "repo.h"
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <Windows.h>
#include <algorithm>
#include <fstream>
#include <Windows.h>
using namespace std;

int TaskRepository::getNumberOfAllTasks() {
	return this->repositoryVector.size();
}

void TaskRepository::openRepoFile() {
	ShellExecute(nullptr, "open", this->pathToFile.c_str(), nullptr, nullptr, SW_SHOWNORMAL);
}

std::vector<Refurbishment> TaskRepository::getAllTasks() const {
	return this->repositoryVector;
}

void TaskRepository::setPath(std::string pathToFile) {
	this->pathToFile = pathToFile;
}

void TaskRepository::addNewTask(Refurbishment newTask) {
	this->repositoryVector.push_back(newTask);
}

void TaskRepository::updateExistingTask(Refurbishment newTask) {
	for (int index = 0; index < this->repositoryVector.size(); index++) {
		if ( this->repositoryVector[index].getTitle() == newTask.getTitle()) {
			this->repositoryVector[index].setDate(newTask.getDate());
			this->repositoryVector[index].setMirrorImage(newTask.getMirrorImage());
			this->repositoryVector[index].setNumberOfRepetitions(newTask.getNumberOfRepetitions());
			this->repositoryVector[index].setType(newTask.getType());
			break;
		}
	}
}

void TaskRepository::deleteTask(Refurbishment newTask) {
	for (int index = 0; index < this->repositoryVector.size(); index++) {
		if (this->repositoryVector[index].getTitle() == newTask.getTitle()) {
			this->repositoryVector.erase(this->repositoryVector.begin() + index);
			break;
		}
	}}

Refurbishment TaskRepository::getChoreFromPosition(int position) {
	return this->repositoryVector[position];
}

Refurbishment TaskRepository::findChoreByTitle(std::string titleOfTheChore) {
	for (auto chore : this->repositoryVector) {
		if ( chore.getTitle() == titleOfTheChore)
			return chore;
	}
}

std::vector<Refurbishment> TaskRepository::getAllChoresWithProperty(std::string typeOfTheChore, int numberOfRepetitions) {
	std::vector<Refurbishment> choresWithProperty(this->repositoryVector.size());
	auto it = std::copy_if(this->repositoryVector.begin(), this->repositoryVector.end(), choresWithProperty.begin(), [typeOfTheChore, numberOfRepetitions](Refurbishment chore) {return (chore.getType().find(typeOfTheChore) != string::npos && chore.getNumberOfRepetitions() < numberOfRepetitions); });
	choresWithProperty.resize(std::distance(choresWithProperty.begin(), it));
	return choresWithProperty;
}

void FileRepository::readFromFile(std::string pathToFile) {
	this->pathToFile = pathToFile;
	ifstream file(pathToFile);
	if (!file.is_open())return;

	Refurbishment task{ "", "", "", 0, "" };
	while (file >> task)
	{
		addNewTask(task);
	}
	file.close();
}

void FileRepository::writeToFile() {
	ofstream file(this->pathToFile);
	if (!file.is_open())return;

	for (auto task : getAllTasks())
	{
		//file << task;
		file << task.getTitle() << "," << task.getType() << "," << task.getDate() << "," << task.getNumberOfRepetitions() << "," << task.getMirrorImage() << "\n";
	}

	file.close();
}

void CSVRepository::writeToFile() {
	ofstream file(this->pathToFile);
	if (!file.is_open())return;

	for (auto task : getAllTasks())
	{
		file << task.getTitle() << "," << task.getType() << "," << task.getDate() << "," << task.getNumberOfRepetitions() << "," << task.getMirrorImage() << "\n";
	}

	file.close();
	
}


void HtmlRepository::setExtension(std::string extensionOfFile) {
	this->extensionOfFile = extensionOfFile;
}

void HtmlRepository::writeToFile() {
	ofstream file(this->pathToFile);
	if (!file.is_open()) return;

	file << "<!DOCTYPE html>";
	file << "<html>";
	file << "	<head>";
	file << "		<title>Task</title>";
	file << "	</head>";
	file << "	<body>";
	file << "		<table border=" << char(34) << "1" << char(34) << ">";
	file << "		<tr>";
	file << "			<td>Title</td>";
	file << "			<td>Type</td>";
	file << "			<td>Date</td>";
	file << "			<td>Number of repetitions</td>";
	file << "			<td>Vision</td>";
	file << "		</tr>";

	for (auto task : getAllTasks()) {
		file << "		<tr>";
		file << "			<td>" << task.getTitle() << "</td>";
		file << "			<td>" << task.getType() << "</td>";
		file << "			<td>" << task.getDate() << "</td>";
		file << "			<td>" << task.getNumberOfRepetitions() << "</td>";
		file << "			<td>" << task.getMirrorImage() << "</td>";
		file << "		</tr>";
	}
	file << "		</table>";
	file << "	</body>";
	file << "</html>";
	file.close();
	
}
