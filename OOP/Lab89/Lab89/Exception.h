#pragma once
#include <string>

class Exception : public std::exception
{
private:
	std::string message;
public:
	Exception(const std::string &message);
	std::string get_message();
	~Exception();
};

