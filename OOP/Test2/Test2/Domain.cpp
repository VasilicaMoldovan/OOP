#include "Domain.h"


double Engine::getPrice() {
	return this->basePrice;
}

double EldrunicEngine::getPrice() {
	return (this->basePrice + this->autonomy * 0.01);
}

std::string EldrunicEngine::toString() {
	std::string stringToPrint;
	stringToPrint = "Fuel Type " + this->fuelType;
	stringToPrint += ", Base Price " + std::to_string(this->basePrice);
	stringToPrint += ", Autonomy " + std::to_string(this->autonomy);
	return stringToPrint;
}

double ArcMineralEngine::getPrice() {
	if (this->fuelType == "geomantic") {
		return (this->basePrice + 0.01 * 150);
	}
	else
		return (this->basePrice + 0.01 * 100);
}

std::string ArcMineralEngine::toString() {
	std::string stringToPrint;
	stringToPrint = "Fuel Type " + this->fuelType;
	stringToPrint += ", Base Price " + std::to_string(this->basePrice);
	return stringToPrint;
}

double Vehicle::computePrice() {
	double price = 0;
	if (this->bodyStyle == "Chariot") {
		price = 8000;
		price += this->engine->getPrice();
	}
	else {
		price = 1000;
		price += this->engine->getPrice();
	}
	return price;
}

std::string Vehicle::printVehicle() {
	std::string stringToPrint = this->engine->toString();
	stringToPrint += ", Body Style " + this->bodyStyle;
	return stringToPrint;
}