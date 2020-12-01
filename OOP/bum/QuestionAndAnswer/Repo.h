#pragma once
#include "User.h"
#include "Answer.h"
#include "Question.h"
#include <vector>
#include "Subject.h"
class Repo :public Subject
{
private:
	std::vector<User> users;
	std::vector<Question> questions;
	std::vector<Answer> answers;

public:
	Repo();
	void addUser(std::string name)
	{
		users.push_back(User(name));
	}

	//input:int id, string question, string user that asks, int nr of votes
	//output:none
	//function wich adds a new question in the vector of questionss
	void addQuestion(int id, std::string text, std::string asker, int ans)
	{
		questions.push_back(Question(id, text, asker, ans));
		this->notify();
	}

	//input: id of the question
	//output: vector wich contains all the answers for the question with the give id
	//returns a vector with all the answers for the question selected
	std::vector<Answer>giveAnswer(int qid)
	{
		std::vector<Answer>answ;
		for (auto i : answers)
		{
			if (i.getQid() == qid)
				answ.push_back(i);
		}

		return answ;

	}
	void addAnswer(int id, int qid, std::string user, std::string text, int votes)
	{
		answers.push_back(Answer(id, qid, user, text, votes));
		this->notify();
	}

	void updateQuestion(int quid)
	{
		for(int i=0;i<questions.size();i++)
		{
			if (questions[i].getId() == quid)
			{
				questions[i].setAns(questions[i].getAns() + 1);
			}
		}
		this->notify();
	}

	/*void updateAnswer(int id, int x)
	{
		for (int i = 0; i < answers.size(); i++)
			if (answers[i].getId() == id)
				answers[i].setVotes(answers[i].getVotes() + x);

		this->notify();
	}*/

	std::vector<User> returnUsers()
	{
		return this->users;
	}

	std::vector<Question> returnQuestions()
	{
		return this->questions;
	}

	std::vector<Answer>returnAnswer()
	{
		return this->answers;
	}

	void readData();
	void saveData();

	~Repo();
};

