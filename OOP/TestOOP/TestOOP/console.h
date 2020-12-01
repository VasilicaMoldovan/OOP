#pragma once
#include "controller.h"

class MicrospritesConsole {
private:
	MicrospritesController totalityOfMicrosprites;
public:
	MicrospritesConsole() {};
	void run();
	void printAllTheMicrosprites(DynamicVector<Microsprites> vectorOfMicrosprites);
};