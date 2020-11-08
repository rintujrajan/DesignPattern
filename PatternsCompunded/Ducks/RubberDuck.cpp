#include "RubberDuck.h"
#include <iostream>

RubberDuck::RubberDuck()
{
    duckSubject = new DuckSubject(this);
}

void RubberDuck::quack()
{
    std::cout<<"\nRubberDuck: Squeak!\n";
    notifyObservers();
}

void RubberDuck::registerObserver(IObserver* observer)
{
    duckSubject->registerObserver(observer);
}

void RubberDuck::notifyObservers()
{
    duckSubject->notifyObservers();
}

