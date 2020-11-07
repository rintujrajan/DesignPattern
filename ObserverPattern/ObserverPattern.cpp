// ObserverPattern.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Subjects\WeatherData.h"
#include "Observers\CurrentConditionsDisplay.h"
#include "Observers\AverageConditionsDisplay.h"

/******************************************************************************
*******************************************************************************
*******************************************************************************
The code for this pattern is based up on the Head First Design patterns book
which is available in the root folder of the project

The Observer Pattern defines a one-to-many dependency between objects so that
when one object changes state, all of its dependents are notified and updated
automatically

There would always be a Subject and an Observer Interface.

The Subject Interface would have the methods to 
	-> Register observer -  add new observers
	-> Remove observer - remove existing observers
	-> Notify Observer - notify of any change to the registered observers

A Concrete Subject(Weather Data) inherits the Subject Interface and implements
the three above mentioned methods of the subject interface. The Notify Observer 
method can be triggered by an external event(measurementsChanged() in code)

The Object Interface has one method
	-> Update

The update method is called by the a Concrete Subject from the Notify Observer
method

Concrete Observer classes(teh display classes in the code) inherit the 
Observer Interface and implements the update method

Each Concrete Observer has to register themselves to a Concrete Subject. It is 
done in the constructor of the Concrete Observers(Dsiplay classes) in the 
current code. 

An import design principle - Strive for losely coupled designs between objects
that interact

For a clear picture refer to page 22(64) and 56(68) of the book

*******************************************************************************
*******************************************************************************
*******************************************************************************/

int main()
{
	WeatherData *weatherData = new WeatherData();

	// 1st sample data set - no observers
	weatherData->setMeasurements(1, 5, 10);

	// 1st observer
	CurrentConditionsDisplay* currentconditionsDisplay = new CurrentConditionsDisplay();
	weatherData->registerObserver(currentconditionsDisplay);   // observer registered to subject

	// 2nd observer - observer registered in constructor below.
	// Hence can only be removed as an observer from the object class. Shown below
	AverageConditionsDisplay* averageConditionsDisplay = new AverageConditionsDisplay(weatherData);

	// 2nd sample data set
	weatherData->setMeasurements(5, 10, 15);

	// 1st observer now removed from observing
	weatherData->removeObserver(currentconditionsDisplay);

	// 3rd sample data set - only 2nd observer now observing
	weatherData->setMeasurements(50, 100, 150);

	// 2nd observer now removed from observing
	averageConditionsDisplay->removeFromObserving();

	// 4th sample data set - no observers left
	weatherData->setMeasurements(500, 1000, 1500);

	std::cin.get();
}
