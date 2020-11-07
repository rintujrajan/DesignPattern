#include "CurrentConditionsDisplay.h"
#include "..\Subjects\ISubject.h"
#include <iostream>


CurrentConditionsDisplay::CurrentConditionsDisplay()
	:temperature(0), humidity(0), pressure(0)
{
}

CurrentConditionsDisplay::CurrentConditionsDisplay(ISubject* weatherData)
	: temperature(0), humidity(0), pressure(0)
{
	localWeatherData = weatherData;
	localWeatherData->registerObserver(this);

}

void CurrentConditionsDisplay::update(float temperature, float humidity, float pressure)
{
	this->temperature = temperature;
	this->humidity = humidity;
	this->pressure = pressure;
	display();
}

std::string CurrentConditionsDisplay::getDescription()
{
	return "Current Conditions Display";
}

void CurrentConditionsDisplay::display()
{
	std::cout << "\nCurrent conditions Display:"
		<< "\n\tTemperature : " << temperature
		<< "\n\tHumidity    : " << humidity
		<< "\n\tPressure    : " << pressure;
}

void CurrentConditionsDisplay::removeFromObserving()
{
	localWeatherData->removeObserver(this);
}
