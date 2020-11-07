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

	//default copy constructors and assignment operators deleted so that they are not used by mistake
	CurrentConditionsDisplay(const CurrentConditionsDisplay&) = delete;
	CurrentConditionsDisplay& operator =(const CurrentConditionsDisplay&) = delete;

private:
	float temperature;
	float humidity;
	float pressure;
	ISubject* localWeatherData;
};

