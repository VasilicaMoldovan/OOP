#pragma once
#include <string>
#include <vector>

class Teacher {
private:
	std::string name;
	//std::vector<Student> coordinated;
	//std::vector<Student> students;
public:
	Teacher() : name{""} {}
	Teacher(std::string teacherName) : name{teacherName} {}
	std::string getTeacherName() { return this->name; }
	std::string toString() { return this->name; }
	//void addStudent(Student s) { this->coordinated.push_back(s); }
};

class Student {
private:
	std::string id;
	std::string name;
	std::string email;
	int year;
	std::string title;
	std::string teacherName;
public:
	Student() : id{ "" }, name{ "" }, email{ "" }, year{ 0 }, title{ "No title" }, teacherName{ "" } {}
	Student(std::string i, std::string name, std::string email, int year, std::string title, std::string teacherName):
		id{i}, name{name}, email{email}, year{year}, title{title}, teacherName{teacherName} {}
	Student(std::string i, std::string name, std::string email, int year,std::string teacherName) :
		id{ i }, name{ name }, email{ email }, year{ year }, title{"No title" }, teacherName{ teacherName } {}
	std::string toString();
	std::string getTeacherName() { return this->teacherName; }
	int getYear() { return this->year; }
	friend std::istream& operator>>(std::istream& is, Student& s);
	std::string getId() { return this->id; }
	void setTeacherName(std::string newName) { this->teacherName = newName; }
	void setEmail(std::string newName) { this->email = newName; }
	void setTitle(std::string newName) { this->title = newName; }
	std::string getName() { return this->name; }
	std::string getTitle() { return this->title; }
};