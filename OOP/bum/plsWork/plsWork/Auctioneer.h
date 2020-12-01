#pragma once
#include "Observer.h"
#include <vector>
#include "Domain.h"
#include <sstream>
#include "Repository.h"

class Auctioneer :
	public Subject
{
private:
	Repository& repo;
public:
	Auctioneer(Repository& repo) : repo{repo} {}
	~Auctioneer();
	std::vector<Question> getQuestion() { return this->repo.getAnsweredSoFar(); }
	std::vector<User> getUser() { return this->repo.getUsers(); }
	std::vector<Question> getA() { return this->repo.getQuestions(); }
	Question searchQuestion(std::string text) { return this->repo.simillarQ(text); }
	std::vector<Answer> searchAnswers(Question q) { return this->repo.searchQ(q); }
	void addQuestionToController(std::string name, std::string text) { this->repo.addNewQuestion(name, text); this->repo.writeToFile(); }
	std::vector<Answer> giveAnswers(Question q) { return this->repo.giveAns(q); }
	void addAnswerToController(int qId, std::string name, std::string text) { this->repo.addNewAnswer(qId, name, text); this->repo.writeToFile(); }
};

