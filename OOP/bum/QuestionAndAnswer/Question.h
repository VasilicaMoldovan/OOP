#pragma once
#include<string>
class Question
{
private:
	int id, ans;
	std::string text;
	std::string asker;

public:
	Question(int i,std::string t, std::string a,int an):id(i),text(t),asker(a),ans(an){}
	int getId()
	{
		return this->id;
	}
	std::string getText()
	{
		return this->text;
	}
	std::string getAsker()
	{
		return this->asker;
	}
	int getAns()
	{
		return this->ans;
	}
	void setId(int i)
	{
		this->id = i;
	}
	void setText(std::string x)
	{
		this->text = x;
	}
	void setAsker(std::string x)
	{
		this->asker = x;
	}
	void setAns(int x)
	{
		this->ans = x;
	}

	~Question(){}
};

