#pragma once
#include <string>

class Engine {
protected:
	std::string fuelType;
	double basePrice;
public:
	Engine() : fuelType{" "}, basePrice{ 0 } {}
	Engine(std::string fuelType, double basePrice) : fuelType{fuelType}, basePrice{basePrice} {}
	virtual	double getPrice();
	virtual std::string toString() = 0;
	//virtual void setPrice(double price) = 0;
};

class EldrunicEngine : public Engine{
private:
	int autonomy;
public:
	EldrunicEngine(std::string fuelType, int autonomy) : Engine{fuelType, 3000}, autonomy{autonomy} {}
	double getPrice() override;
	std::string toString();
	//void setPrice(double price) : basePrice{ price };
};

class ArcMineralEngine : public Engine {
public:
	ArcMineralEngine(std::string fuelType) : Engine{fuelType, 3000} {}
	double getPrice() override;
	std::string toString();
};

class Vehicle {
private:
	Engine* engine;
	std::string bodyStyle;
public:
	//Vehicle() : Engine{}, bodyStyle{ " " };
	Vehicle(Engine* engine, std::string bodyStyle)	: engine{engine}, bodyStyle{bodyStyle} {}
	double computePrice();
	std::string printVehicle();
};