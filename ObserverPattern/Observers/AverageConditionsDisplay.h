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

	//default copy constructors and assignment operators deleted so that they are not used by mistake
	AverageConditionsDisplay(const AverageConditionsDisplay&) = delete;
	AverageConditionsDisplay& operator =(const AverageConditionsDisplay&) = delete;
private:
	float totalTemperature;
	float totalHumidity;
	float totalPressure;
	int countOfData;
	ISubject* localWeatherData;

};

