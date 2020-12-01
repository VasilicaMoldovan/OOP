#include "Controller.h"
#include <fstream>

Vehicle Controller::createEngine(std::string engineType, std::string fuelType, int autonomy, std::string bodyStyle) {
	if (engineType == "Eldrunic") {
		Engine* engine = new EldrunicEngine{ fuelType, autonomy };
		Vehicle newVehicle{ engine, bodyStyle };
		return newVehicle;
	}
	else {
		Engine* engine = new ArcMineralEngine{ fuelType };
		Vehicle newVehicle{ engine, bodyStyle };
		return newVehicle;
	}

}

void Controller::addVehicle(int basePrice, std::string engineType, std::string fuelType, std::string bodyStyle, int autonomy) {
	Vehicle newVehicle = this->createEngine(engineType, fuelType, autonomy, bodyStyle);
	this->listOfVehicles.push_back(newVehicle);
}

double Controller::getVehiclePrice() {
	return this->listOfVehicles[this->listOfVehicles.size() - 1].computePrice();
}

std::vector<Vehicle> Controller::getVehicleWithMaxPrice(double maxPrice) {
	std::vector<Vehicle> newVector;
	for (auto elem : this->listOfVehicles) {
		if (elem.computePrice() < maxPrice)
			newVector.push_back(elem);
	}

	std::string engineType, bodyType, fuelType;
	int autonomy = 0;
	engineType = "Arc-mineral";
	bodyType = "Carriage";
	fuelType = "geomantic";
	Engine* engine = new EldrunicEngine{ fuelType, autonomy };
	Vehicle newVehicle{ engine, bodyType };

	for (int i = 0; i < newVector.size() - 1; i++) {
		for (int j = i + 1; j < newVector.size(); j++) {
			if (newVector[i].computePrice() < newVector[j].computePrice())
				std::swap(newVector[i], newVector[j]);
		}
	}
	return newVector;
}

std::vector<Vehicle> Controller::getAllVehicles() {
	return this->listOfVehicles;
}

void Controller::writeToFile(std::string filename, std::vector<Vehicle> vectorOfVehicles) {
	std::ofstream fin(filename);
	for (auto elem : vectorOfVehicles) {
		fin << elem.printVehicle() << ", Final Price " << elem.computePrice() << "\n";
	}
}












Controller::Controller()
{
}


Controller::~Controller()
{
}
