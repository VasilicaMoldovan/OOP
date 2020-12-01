#include "Tests.h"
#include "assert.h"
Tests::Tests()
{
}


Tests::~Tests()
{
}


void Tests::testAdd()
{
	Repository repo{};
	std::vector<Student> students = repo.getStudents();
	try {
		repo.addTeacher(students[0], "Teacher1");
		assert(false);
	}
	catch (std::exception &error) {
		assert(strcmp(error.what(), "Error on adding a teacher!") == 0);
	}
	try {
		repo.addTeacher(students[students.size() - 1], "Teacher1");
		assert(true);
	}
	catch (std::exception &error) {
		assert(false);
	}

}

void Tests::testSearch()
{
	Repository repo{};
	//std::vector<Student> students = repo.getStudents();
	std::vector<Student> students = repo.getStudentsSearch("a8");
	assert(students.size() == 1);
	assert(students[0].getId() == "a861");
	std::vector<Student> students2 = repo.getStudentsSearch("Andreea are mere");
	assert(students2.size() == 0);
	std::vector<Student> students3 = repo.getStudentsSearch("2");
	assert(students3.size() == 2);
	assert(students3[0].getId()== "2ao7");
	assert(students3[1].getId() == "2se3");
}