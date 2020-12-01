#include "Domain.h"

std::string Question::toString()
{
	std::string finalS = "";
	finalS += std::to_string(this->id);
	finalS += ", ";
	finalS += this->name;
	finalS += ", ";
	finalS += this->text;

	return finalS;
}

std::string Answer::toString()
{
	std::string result = "";
	result += std::to_string(this->id);
	result += ", ";
	result += std::to_string(this->questionId);
	result += ", ";
	result += this->name;
	result += ", ";
	result += this->text;
	result += ", ";
	result += std::to_string(this->votes);

	return result;
}