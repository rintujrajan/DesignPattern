#pragma once
#include "IObserver.h"
#include "IDisplay.h"

class ISubject;

class AverageConditionsDisplay
	:public IObserver, public IDisplay
{
public:
	AverageConditionsDisplay();
	AverageConditionsDisplay(ISubject* weatherData);
	void update(float temperature, float humidity, float pressure) override;
	std::string getDescription() override;
	void display() override;
	void removeFromObserving();
private:
	float totalTemperature;
	float totalHumidity;
	float totalPressure;
	int countOfData;
	ISubject* localWeatherData;

};

