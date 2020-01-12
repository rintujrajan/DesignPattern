#include "WeatherData.h"
#include <iostream>
#include <sstream>

WeatherData::WeatherData():
	temperature(0), humidity(0), pressure(0)
{

}

void WeatherData::registerObserver(IObserver* observer)
{
	observers.push_back(observer);
}

void WeatherData::removeObserver(IObserver* observer)
{
	auto it = std::find(observers.begin(), observers.end(), observer);
	if (it != observers.end())
	{
		observers.erase(it);
		std::cout << "\nRemoved observer : " << observer->getDescription();
	}
}

void WeatherData::notifyObservers()
{
	if (observers.empty())
	{
		std::cout << "\nNo observers found!";
		return;
	}
	else
	{
		std::stringstream ss;
		ss<< observers.size(); //using string stream to put the size_t type in a stream
		std::cout << "\n" + ss.str()+ " observer(s) found!";
	}
	for (auto observer : observers)
	{
		observer->update(temperature, humidity, pressure);
	}
}

void WeatherData::measurementsChanged()
{
	notifyObservers();
}

void WeatherData::setMeasurements(float temperature, float humidity, float pressure)
{
	this->temperature = temperature;
	this->humidity = humidity;
	this->pressure = pressure;
	measurementsChanged();
}
