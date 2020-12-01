#pragma once
#include<string>
class User
{
private:
	std::string name ;
public:
	User(std::string n):name(n){}
	std::string getName()
	{
		return this->name;
	}
	~User(){}
};

