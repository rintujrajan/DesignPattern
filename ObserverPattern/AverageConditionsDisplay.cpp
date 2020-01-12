#include "AverageConditionsDisplay.h"
#include <iostream>


AverageConditionsDisplay::AverageConditionsDisplay()
	:totalTemperature(0), totalHumidity(0), totalPressure(0), countOfData(0)
{
}

AverageConditionsDisplay::AverageConditionsDisplay(ISubject* weatherData)
	: totalTemperature(0), totalHumidity(0), totalPressure(0), countOfData(0)
{
	localWeatherData = weatherData;
	localWeatherData->registerObserver(this);
}

void AverageConditionsDisplay::update(float temperature, float humidity, float pressure)
{
	this->totalTemperature += temperature;
	this->totalHumidity += humidity;
	this->totalPressure += pressure;
	countOfData++;
	display();
}

std::string AverageConditionsDisplay::getDescription()
{
	return "Average Conditions Display";
}

void AverageConditionsDisplay::display()
{
	std::cout << "\nAverage conditions :"
		<< "\n\tAverage Temperature : " << totalTemperature/countOfData
		<< "\n\tAverage Humidity    : " << totalHumidity / countOfData
		<< "\n\tAverage Pressure    : " << totalPressure / countOfData;
}

void AverageConditionsDisplay::removeFromObserving()
{
	localWeatherData->removeObserver(this);
}

