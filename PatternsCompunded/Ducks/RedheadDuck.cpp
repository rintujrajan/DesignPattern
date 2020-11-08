#include "RedheadDuck.h"
#include <iostream>

RedheadDuck::RedheadDuck()
{
    duckSubject = new DuckSubject(this);
}

void RedheadDuck::quack()
{
    std::cout<<"\nRedheadDuck: Quack!\n";
    notifyObservers();
}

void RedheadDuck::registerObserver(IObserver* observer)
{
    duckSubject->registerObserver(observer);
}

void RedheadDuck::notifyObservers()
{
    duckSubject->notifyObservers();
}
