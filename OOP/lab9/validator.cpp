#include "validator.h"

RefurbishmentException::RefurbishmentException(std::string errorMessage) {
	this->errorMessage = errorMessage;
}

std::string RefurbishmentException::getErrorMessage() const noexcept {
	return this->errorMessage;
}

bool RefurbishmentValidator::validateRefurbishment(Refurbishment& task) {
	std::string errors;
	char date[100];
	strcpy(date, task.getDate().c_str());
	int count = 0;
	for (int index = 0; index < strlen(date); index++) {
		if (date[index] == '-')
			count++;
	}
	if (count != 2) {
		errors += "Invalid date\n";
	}
	else {
		char *token = strtok(date, "-");
		if (atoi(token) < 0 || atoi(token) > 31)
			errors += "Invalid day number\n";
		int day = atoi(token);
		token = strtok(NULL, "-");
		if (atoi(token) < 0 || atoi(token) > 12)
			errors += "Invalid month number\n";
		if (atoi(token) % 2 == 0) {
			if (atoi(token) == 2 && day > 28)
				errors += "Invalid day number for an even month\n";
			else {
				if (day > 30)
					errors += "Invalid day number for an even given month\n";
			}
		}
		token = strtok(NULL, "-");
		if (atoi(token) < 0)
			errors += "Inavlid year number\n";
	}
	if (errors.size() > 0) {
		throw RefurbishmentException(errors);
		return false;
	}
	else
		return true;
}

bool RepositoryValidator::validateAdd(Refurbishment& task, std::vector<Refurbishment> vectorOfElements) {
	if (existingElement(task, vectorOfElements) == true) {
		throw RefurbishmentException("This task already exists in the list\n");
		return false;
	}
	else
		return true;
}

bool RepositoryValidator::validateDeleteOrUpdate(Refurbishment& task, std::vector<Refurbishment> vectorOfElements) {
	if (existingElement(task, vectorOfElements) == false) {
		throw RefurbishmentException("The given element does not exist in the list\n");
		return false;
	}
	else
		return true;
}

bool FakeValidator::validateAdd(Refurbishment& task, std::vector<Refurbishment> vectorOfElements) {
	if (task.getTitle() == "cleanup")
		throw RefurbishmentException("faked validator");
	else
		return false;
}

bool FakeValidator::validateDeleteOrUpdate(Refurbishment& task, std::vector<Refurbishment> vectorOfElements) {
	return true;
}

bool RepositoryValidator::existingElement(Refurbishment task, std::vector<Refurbishment> vectorOfElements) {
	bool exists = false;
	for (auto element : vectorOfElements) {
		if (element.getTitle() == task.getTitle()) {
			exists = true;
			break;
		}
	}
	return exists;
}