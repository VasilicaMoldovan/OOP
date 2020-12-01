#pragma once
#include <vector>
#include <algorithm>
#include <memory>

class Observer
{
public:
	virtual void update() = 0;
	virtual ~Observer() {}
};

class Subject
{
private:
	//std::vector<std::unique_ptr<Observer>> observers;
	std::vector<Observer*> observers;
public:
	virtual ~Subject() {}

	void addObserver(Observer* obs)
	{
		observers.push_back(obs);
	}

	void removeObserver(Observer* obs)
	{
		observers.erase(std::remove(observers.begin(), observers.end(), obs));
	}

	void notify()
	{
		/*for (int i = 0; i < observers.size(); i++) {
			observers[i]->update();
		}*/
		for (auto obs : observers)
		{
			obs->update();
		}
	}
};