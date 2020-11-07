#pragma once
#include "IObserver.h"
#include "IDisplay.h"

class ISubject;

class CurrentConditionsDisplay :
	public IObserver, public IDisplay
{
public:
	CurrentConditionsDisplay();
	CurrentConditionsDisplay(ISubject* weatherData);
	void update(float temperature, float humidity, float pressure) override;
	std::string getDescription() override;
	void display() override;
	void removeFromObserving();

private:
	float temperature;
	float humidity;
	float pressure;
	ISubject* localWeatherData;
};

