#pragma once
#include "ISubject.h"
#include <vector>
class WeatherData :
	public ISubject
{
public:
	WeatherData();
	void registerObserver(IObserver* observer) override;
	void removeObserver(IObserver* observer) override;
	void notifyObservers() override;
	void measurementsChanged();
	void setMeasurements(float temperature, float humidity, float pressure);

	//default copy constructors and assignment operators deleted so that they are not used by mistake
	WeatherData(const WeatherData&) = delete;
	WeatherData& operator =(const WeatherData&) = delete;
private:
	std::vector<IObserver*> observers;
	float temperature;
	float humidity;
	float pressure;
};

