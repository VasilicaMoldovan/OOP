#pragma once
#include "Domain.h"
#include <vector>
class Repository
{
private:
	std::vector<Teacher> teachers;
	std::vector<Student> students;
public:
	Repository();
	void readTeachers();
	void readStudents();
	std::vector<std::string> readFromFile(std::string path);
	//std::vector<std::string> tokenize(std::string elem);
	std::vector<Teacher> getTeachers() { return this->teachers; }
	std::vector<Student> getStudents() { return this->students; }
	std::vector<Student> getStudentsFromTeacher(Teacher t);
	std::vector<Student> getStudentsSearch(std::string name);
	void addTeacher(Student s, std::string t);
	std::vector<Student> getCoordinated(std::string name);
	void changeStudent(std::string id, std::string email, std::string title);
	~Repository();
};

