#pragma once
#include <string>

class Microsprites {
private:
	char *type;
	int numberOfOrganisms;
	bool immunity;
public:
	Microsprites(char type[], int numberOfOrganisms, bool immunity);
	Microsprites();
	char* getType() const;
	int getNumberOfOrganisms() const;
	bool getImmunity() const;
	std::string toString() const;
	void setNumberOfOrganisms(int newNumber);
};