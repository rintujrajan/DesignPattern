#include "DuckCall.h"
#include <iostream>

DuckCall::DuckCall()
{
    duckSubject = new DuckSubject(this);
}

void DuckCall::quack()
{
    std::cout<<"\nDuckCall: Kwack!\n";
    notifyObservers();
}

void DuckCall::registerObserver(IObserver* observer)
{
    duckSubject->registerObserver(observer);
}

void DuckCall::notifyObservers()
{
    duckSubject->notifyObservers();
}

