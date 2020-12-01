#pragma once
#include "Domain.h"
#include <sstream>
#include <vector>

class Repository
{
private:
	std::vector<User> users;
	std::vector<Question> questions;
	std::vector<Answer> answers;
	int idQ, idA;
public:
	Repository();
	void readUsers();
	std::vector<std::string> readFromFile(std::string path);
	std::vector<std::string> tokenize(std::string readString);
	void readQuestions();
	void readAnswers();
	std::vector<User> getUsers() { return this->users; }
	std::vector<Question> getQuestions() { return this->questions; }
	std::vector<Answer> getAnswers() { return this->answers; }
	std::vector<Question> getAnsweredSoFar();
	Question simillarQ(std::string question);
	std::vector<Answer> searchQ(Question q);
	void addNewQuestion(std::string name, std::string text);
	std::vector<Answer> giveAns(Question q);
	void writeToFile();
	void addNewAnswer(int qId, std::string name, std::string text);
	~Repository();
};

