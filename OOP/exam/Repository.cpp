#include "Repository.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <stdexcept>

Repository::Repository()
{
	this->readTeachers();
	this->readStudents();
}


void Repository::readTeachers()
{
	std::ifstream file("f1.txt");
	if (!file.is_open())
		return;

	std::string name;
	while (file >> name)
	{
		this->teachers.push_back(Teacher{ name });
	}
	file.close();
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


void Repository::readStudents()
{
	std::ifstream file("f2.txt");
	if (!file.is_open())
		return;

	Student s{};
	while (file >> s)
	{
		this->students.push_back(s);
	}
	file.close();
}

std::vector<Student> Repository::getStudentsFromTeacher(Teacher t)
{
	std::vector<Student> result;
	std::vector<Student> currentYear;
	std::vector<Student> diffYear;
	for (auto elem : this->students)
	{
		if (elem.getTeacherName() == t.getTeacherName())
		{
			if (elem.getYear() == 2019)
				currentYear.push_back(elem);
			else
				diffYear.push_back(elem);
		}
	}

	sort(diffYear.begin(), diffYear.end(), [](Student a, Student b) {return a.getYear() > b.getYear(); });
	for (auto elem : currentYear)
		result.push_back(elem);
	for (auto elem : diffYear)
		result.push_back(elem);

	return result;
}

std::vector<Student> Repository::getStudentsSearch(std::string name)
{
	/*Function which searches for a student by name or id
	Input: name - the name/id after which search about
	Output: result - a vector of Student containing of the students with id/name name
	*/
	std::vector<Student> result;
	char aux[256];
	strcpy(aux, name.c_str());
	char student[256];
	for (auto elem : this->students)
	{
		strcpy(student, elem.getTeacherName().c_str());
		if (strstr(student, aux))
			result.push_back(elem);
		else
		{
			strcpy(student, elem.getId().c_str());
			if (strstr(student, aux))
				result.push_back(elem);
		}
	}
	return result;
}

void Repository::addTeacher(Student s, std::string t)
{
	/*Function which adds a coordinator to a student
	Input: s - the students for which the coordinator is added
			t - the name of the added coordinator
	Output: -
	It throws an exception if the student has already a coordinator
	*/
	bool aux = false;
	for (int i = 0; i < this->students.size(); i++)
	{
		if (this->students[i].getId() == s.getId())
		{
			if (this->students[i].getTeacherName() == "")
			{
				this->students[i].setTeacherName(t);
				
			}
			else
				aux = true;
			break;
		}
	}
	if (aux)
		throw std::exception("Error on adding a teacher!");
}

std::vector<Student> Repository::getCoordinated(std::string name)
{
	std::vector<Student> result;
	for (auto elem : this->students)
	{
		if (elem.getTeacherName() == name)
			result.push_back(elem);
	}
	return result;
}

void Repository::changeStudent(std::string id, std::string email, std::string title)
{
	for (int i = 0; i < this->students.size(); i++)
	{
		if (this->students[i].getId() == id)
		{
			if (email != "")
				this->students[i].setEmail(email);
			if (title != "")
				this->students[i].setTitle(title);
			break;
		}
	}
}

Repository::~Repository()
{
}
