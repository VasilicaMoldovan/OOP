#pragma once
#include "domain.h"
#include "repo.h"
#include <string>

class RefurbishmentException : public std::exception {
private:
	std::string errorMessage;
public:
	RefurbishmentException(std::string errorMessage);
	std::string getErrorMessage() const noexcept;
};

class RefurbishmentValidator {
public:
	static bool validateRefurbishment(Refurbishment& task);
};

class RepositoryValidator{
public:
	virtual bool validateAdd(Refurbishment& task, std::vector<Refurbishment> vectorOfElements);
	virtual bool validateDeleteOrUpdate(Refurbishment& task, std::vector<Refurbishment> vectorOfElements);
	virtual bool existingElement(Refurbishment task, std::vector<Refurbishment> vectorOfElements);
};

class FakeValidator : public RepositoryValidator{
public:
	bool validateAdd(Refurbishment& task, std::vector<Refurbishment> vectorOfElements);
	bool validateDeleteOrUpdate(Refurbishment& task, std::vector<Refurbishment> vectorOfElements);
};