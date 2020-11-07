#include "WeatherData.h"
#include "..\Observers\IObserver.h"
#include <iostream>
#include <string>

WeatherData::WeatherData():
	temperature(0), humidity(0), pressure(0) { }

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
		std::cout << "\n\nRemoved observer : " << observer->getDescription();
	}
}

void WeatherData::notifyObservers()
{
	if (observers.empty())
	{
		std::cout << "No observers found!";
		return;
	}
	else
	{
		std::cout << std::to_string(observers.size()) + " observer(s) found:\n";
		for (int it = 0; it < observers.size(); ++it)
		{
			std::cout<< "\t" <<it+1 << ". " << observers[it]->getDescription()<<"\n";
		}
		for (auto observer : observers)
		{
			std::cout<<"Updating the observer(s)...\n";
			observer->update(temperature, humidity, pressure);
		}	
	}
}

void WeatherData::measurementsChanged()
{
	notifyObservers();
}

void WeatherData::setMeasurements(float temperature, float humidity, float pressure)
{
	std::cout<<"\n\nWeather measurements have changed (Temp: "<< temperature 
				<< ", Humidity: " << humidity 
				<< ", Pressure: " << pressure << ")!\n";
	this->temperature = temperature;
	this->humidity = humidity;
	this->pressure = pressure;
	measurementsChanged();
}
