#pragma once
#include "Controller.h"

class Console
{
private:
	Controller newController;
public:
	Console() {};
	void run();
	~Console();
};

