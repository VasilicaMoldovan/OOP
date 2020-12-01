#include "Console.h"
#include <iostream>

using namespace std;

void Console::run() {
	char command[256];
	std::string engineType, bodyType, fuelType, initialCommmand;
	int autonomy;
	double price;
	bool exitCondition = false;
	char *token;
	engineType = "Eldrunic";
	bodyType = "Chariot";
	fuelType = "diesel";
	autonomy = 10;
	this->newController.addVehicle(0, engineType, fuelType, bodyType, autonomy);
	engineType = "Arc-mineral";
	bodyType = "Carriage";
	fuelType = "geomantic";
	this->newController.addVehicle(0, engineType, fuelType, bodyType, autonomy);

	while (!exitCondition) {
		cin.getline(command, 256);
		token = strtok(command, " ,\n");
		initialCommmand = token;
		if (initialCommmand == "add") {
			token = strtok(NULL, " ,\n");
			bodyType = token;
			token = strtok(NULL, " ,\n");
			engineType = token;
			token = strtok(NULL, " ,\n");
			fuelType = token;
			token = strtok(NULL, " ,\n");
			autonomy = atoi(token);

			this->newController.addVehicle(3000, engineType, fuelType, bodyType, autonomy);
			cout << "The price is " << this->newController.getVehiclePrice() << "\n";
		}
		else {
			if (initialCommmand == "list") {
				vector<Vehicle> vectorOfVehicles = this->newController.getAllVehicles();
				for (auto elem : vectorOfVehicles) {
					cout << elem.printVehicle() << "\n";
				}
			}
			else {
				if (initialCommmand == "listInFile")
				{
					token = strtok(NULL, " ,\n");
					price = atoi(token);
					token = strtok(NULL, " ,\n");
					vector<Vehicle> vectorOfVehicles = this->newController.getVehicleWithMaxPrice(price);
					this->newController.writeToFile(token, vectorOfVehicles);
				}
				else {
					exitCondition = true;
				}
			}
		}
	}
}

Console::~Console()
{
}
