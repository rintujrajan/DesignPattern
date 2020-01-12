#pragma once
#include <string>
class IObserver
{
public:
	virtual void update(float temperature, float humidity, float pressure) = 0;
	virtual std::string getDescription() = 0;
};

