#pragma once
#include "Domain.h"
#include <vector>


class Controller
{
private:
	std::vector<Vehicle> listOfVehicles;
public:
	Controller();
	void addVehicle(int basePrice, std::string engineType, std::string fuelType, std::string bodyStyle, int autonomy);
	std::vector<Vehicle> getAllVehicles();
	std::vector<Vehicle> getVehicleWithMaxPrice(double maxPrice);
	void writeToFile(std::string filename, std::vector<Vehicle> vectorOfVehicles);
	double getVehiclePrice();
	~Controller();
private:
	Vehicle createEngine(std::string engineType, std::string fuelType, int autonomy, std::string bodyStyle);
};

