#include "GeeseAdapter.h"

#include <iostream>

GeeseAdapter::GeeseAdapter(Geese* geese)
{
    geeseInstance = geese;
    duckSubject = new DuckSubject(this);
}

void GeeseAdapter::quack()
{
    geeseInstance->honk();
    notifyObservers();
}

void GeeseAdapter::registerObserver(IObserver* observer)
{
    duckSubject->registerObserver(observer);
}

void GeeseAdapter::notifyObservers()
{
    duckSubject->notifyObservers();
}

