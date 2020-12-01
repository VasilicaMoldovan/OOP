#pragma once
#include <string>

class User
{
private:
	std::string name;
public:
	User() : name{""} {}
	User(std::string n) : name{n} {}
	std::string getName() const { return this->name; }
};

class Question
{
private:
	int id;
	std::string text;
	std::string name;
public:
	Question() : id{0}, text{""}, name{""} {}
	Question(int newId, std::string t, std::string n) : id{newId}, text{t}, name{n} {}
	int getId() const { return this->id; }
	std::string getText() const { return this->text; }
	std::string getName() const { return this->name; }
	std::string toString();
	void setName(std::string n) { this->name = n; }
	void setText(std::string t) { this->text = t; }
	void setId(int nr) { this->id = nr; }
};

class Answer
{
private:
	int id;
	int questionId;
	std::string name;
	std::string text;
	int votes;
public:
	Answer() : id{0}, questionId{0}, name{""}, text{""}, votes{0} {}
	Answer(int i, int q, std::string n, std::string t, int nr) : id{i}, questionId{q}, name{n}, text{t}, votes{nr} {}
	int getId() const { return this->id; }
	int getQuestionId() const { return this->questionId; }
	std::string getName() const { return this->name; }
	std::string getText() const { return this->text; }
	int getVotes() const { return this->votes; }
	std::string toString();
};
