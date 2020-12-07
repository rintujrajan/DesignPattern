#include "MallardDuck.h"
#include <iostream>

MallardDuck::MallardDuck()
{
    duckSubject = new DuckSubject(this);
}

void MallardDuck::quack()
{
    std::cout<<"\nMallardDuck: Quack!\n";
    notifyObservers();
}

void MallardDuck::registerObserver(IObserver* observer)
{
    duckSubject->registerObserver(observer);
}

void MallardDuck::notifyObservers()
{
    duckSubject->notifyObservers();
}

