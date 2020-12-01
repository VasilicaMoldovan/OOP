#include "Repository.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <stdexcept>

Repository::Repository()
{
	this->readUsers();
	this->readQuestions();
	this->readAnswers();
}

void Repository::readUsers()
{
	std::vector<std::string> result = this->readFromFile("f1.txt");
	for (auto& elem : result)
	{
		this->users.push_back(User{ elem });
	}
}

std::vector<std::string> Repository::readFromFile(std::string path)
{
	std::vector<std::string> elems;
	std::ifstream file(path);
	if (!file.is_open())
		return elems;

	std::string input;
	while (!file.eof())
	{
		getline(file, input);
		if (!input.empty())
			elems.push_back(input);
	}
	file.close();
	return elems;
}

std::vector<std::string> Repository::tokenize(std::string readString)
{
	std::vector<std::string> tokens;
	std::string token;

	std::istringstream stream{ readString };
	while (getline(stream, token, ','))
	{
		tokens.push_back(token);
	}

	return tokens;
}

void Repository::readQuestions()
{
	std::vector<std::string> result = this->readFromFile("f2.txt");
	std::string::size_type sz;

	for (auto& elem : result)
	{
		std::vector<std::string> tokens = tokenize(elem);
		if (tokens.size() == 3)
		{
			this->questions.push_back(Question{ std::stoi(tokens[0], &sz), tokens[1], tokens[2] });
			idQ = std::stoi(tokens[0], &sz) + 1;
		}
	}
}

void Repository::readAnswers()
{
	std::vector<std::string> result = this->readFromFile("f3.txt");
	std::string::size_type sz;

	for (auto& elem : result)
	{
		std::vector<std::string> tokens = tokenize(elem);
		if (tokens.size() == 5)
		{
			this->answers.push_back(Answer{ std::stoi(tokens[0], &sz), std::stoi(tokens[1], &sz), tokens[2], tokens[3], std::stoi(tokens[4], &sz)});
			idA = std::stoi(tokens[0], &sz) + 1;
		}
	}
}

std::vector<Question> Repository::getAnsweredSoFar()
{
	std::vector<Answer> result = this->answers;
	sort(result.begin(), result.end(), [](Answer a, Answer b) {return a.getVotes() > b.getVotes(); });
	std::vector<Question> final;
	int votes = 0;
	for (auto elem : result)
	{
		int i = 0;
		while (i < this->questions.size() && elem.getQuestionId() != this->questions[i].getId())
			i++;

		bool f = false;
		int  j = 0;
		while (j < final.size() && !f)
		{
			if (final[j].getId() == this->questions[i].getId())
				f = true;
			j++;
		}

		if (!(votes == elem.getVotes() && elem.getQuestionId() == final[final.size() - 1].getId()) && !f)
		{
			final.push_back(this->questions[i]);
			votes = elem.getVotes();
		}
	}
	return final;
}

Question Repository::simillarQ(std::string question)
{
	int ma = 0;
	bool stop = false;
	char q[200], aux[200];
	Question result{};
	strcpy(q, question.c_str());
	for (auto elem : this->questions)
	{
		int locM = 0;
		strcpy(aux, elem.getText().c_str());
		for (int i = 0; i < strlen(aux); i++)
		{
			if (i >= strlen(q))
				break;

			if (aux[i] == q[i])
				locM++;
		}
		if (locM > ma)
		{
			ma = locM;
			result.setId(elem.getId());
			result.setName(elem.getName());
			result.setText(elem.getText());
		}
	}
	return result;
}


std::vector<Answer> Repository::searchQ(Question q)
{
	std::vector<Answer> result = this->answers;
	sort(result.begin(), result.end(), [](Answer a, Answer b) {return a.getVotes() > b.getVotes(); });
	std::vector<Answer> finalV;
	int i = 0;
	for (auto elem : result)
	{
		if (i == 3)
			break;
		if (elem.getQuestionId() == q.getId())
		{
			finalV.push_back(elem);
			i++;
		}
	}
	return finalV;
}

void Repository::addNewQuestion(std::string name, std::string text) {
	if (text.length() == 0)
		throw std::exception("Invalid description");
	else
	{
		Question q{ idQ, text, name };
		idQ++;
		this->questions.push_back(q);
	}
}

std::vector<Answer> Repository::giveAns(Question q)
{
	std::vector<Answer> result;
	for (auto elem : this->answers)
	{
		if (elem.getQuestionId() == q.getId())
			result.push_back(elem);
	}
	return result;
}

void Repository::writeToFile()
{
	std::ofstream file2("f2.txt");
	if (!file2.is_open())
		return;
	for (auto elem : this->questions)
	{
		file2 << elem.toString() << "\n";
	}
	file2.close();
	
	std::ofstream file3("f3.txt");
	if (!file3.is_open())
		return;
	for (auto elem : this->answers)
	{
		file3 << elem.toString() << "\n";
	}
	file3.close();
}

void Repository::addNewAnswer(int qId, std::string name, std::string text)
{
	Answer q{ idA, qId, name, text, 0 };
	if (text.length() == 0)
		throw std::exception("Empty text");
	else
	{
		this->answers.push_back(q);
		idA++;
	}
}	

Repository::~Repository()
{
}
