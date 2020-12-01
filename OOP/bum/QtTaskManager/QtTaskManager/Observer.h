#pragma once
#include <vector>
#include <algorithm>

class Observer
{
public:
	virtual void update() = 0;
	virtual ~Observer() {}
};

class Subject
{
private:
	std::vector<Observer*> observers;
public:
	void addObserver(Observer *obs)
	{
		observers.push_back(obs);
	}

	void deleteObserver(Observer *obs)
	{
		observers.erase(std::remove(observers.begin(), observers.end(), obs));
	}

	void notify()
	{
		for (auto obs : observers)
		{
			obs->update();
		}
	}
};
