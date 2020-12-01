#pragma once
#include <string>
class Answer
{
private:
	int id;
	int qid;
	std::string user;
	std::string text;
	int votes;
	//int colour;
public:
	Answer(int x, int y, std::string xx, std::string yy, int h):id(x),qid(y),user(xx),text(yy),votes(h){}
	int getId()
	{
		return this->id;
	}
	int getQid()
	{
		return this->qid;
	}
	int getVotes()
	{
		return this->votes;
	}
	std::string getUser()
	{
		return this->user;
	}
	std::string getText()
	{
		return this->text;
	}
	void setId(int i)
	{
		this->id = i;
	}
	void setQid(int x)
	{
		this->qid = x;
	}
	void setVotes(int x)
	{
		this->votes = x;
	}
	void setText(std::string t)
	{
		this->text = t;
	}
	void setUser(std::string x)
	{
		this->user = x;
	}
	~Answer(){}
};

