#include "Domain.h"

std::string Programmer::toString()
{
	std::string result = "";
	result += this->name;
	result += ", ";
	result += std::to_string(this->id);

	return result;
}

std::string Task::toString()
{
	std::string result = "";
	result += this->description;
	result += ", ";
	result += this->status;
	result += ", ";
	result += std::to_string(this->id);

	return result;
}