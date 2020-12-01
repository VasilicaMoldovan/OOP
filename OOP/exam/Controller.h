#pragma once
#include "Repository.h"
#include "Observer.h"

class Controller : public Subject
{
private:
	Repository& bachelorRepo;
public:
	Controller(Repository& repo) : bachelorRepo{repo} {}
	std::vector<Teacher> getAllTeachers() { return this->bachelorRepo.getTeachers(); }
	std::vector<Student> getAllStudents() { return this->bachelorRepo.getStudents(); }
	std::vector<Student> getStudentsByTeacher(Teacher t) { return this->bachelorRepo.getStudentsFromTeacher(t); }
	std::vector<Student> getStudentsForSearch(std::string name) { return this->bachelorRepo.getStudentsSearch(name); }
	void addCoordinator(Student s, std::string teacher) { this->bachelorRepo.addTeacher(s, teacher); }
	std::vector<Student> getCoord(std::string name) { return this->bachelorRepo.getCoordinated(name); }
	void editStudent(std::string id, std::string email, std::string title) { this->bachelorRepo.changeStudent(id, email, title); }
};