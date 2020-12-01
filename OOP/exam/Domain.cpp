#include "Domain.h"
#include <vector>
#include <sstream>
#include <fstream>

std::string Student::toString()
{
	std::string result = "";
	result += this->id;
	result += ", ";
	result += this->name;
	result += ", ";
	result += this->email;
	result += ", ";
	result += std::to_string(this->year);
	result += ", ";
	result += this->title;
	result += ", ";
	result += this->teacherName;

	return result;
}


std::vector<std::string> tokenize(std::string stringToBeRead, char delimiter)
{
	std::vector <std::string> result;
	std::stringstream ss(stringToBeRead);
	std::string token;
	while (getline(ss, token, delimiter))
		result.push_back(token);

	return result;
}

std::istream& operator>>(std::istream& is, Student& s) {
	std::string line;
	getline(is, line);

	std::vector<std::string> tokens = tokenize(line, ',');
	//if (tokens.size() != 6 || tokens.size() != 5) 
		//return is;
	if (tokens.size() == 6)
	{
		s.id = tokens[0];
		s.name = tokens[1];
		s.email = tokens[2];
		std::string::size_type sizeType;
		s.year = std::stoi(tokens[3], &sizeType);
		s.title = tokens[4];
		s.teacherName = tokens[5];
		return is;
	}
	else
	{
		if (tokens.size() == 5)
		{
			s.id = tokens[0];
			s.name = tokens[1];
			s.email = tokens[2];
			std::string::size_type sizeType;
			s.year = std::stoi(tokens[3], &sizeType);
			s.title = tokens[4];
			s.teacherName = "";
			return is;
		}
		else
			return is;
			
	}
}
