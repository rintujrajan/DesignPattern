#include "DuckWithQuackCounter.h"
int DuckWithQuackCounter::quackCount;

DuckWithQuackCounter::DuckWithQuackCounter(IQuackable* duck)
{
    duckInstance = duck;
    duckSubject = new DuckSubject(this);
}

DuckWithQuackCounter::~DuckWithQuackCounter()
{
    delete duckInstance;
}

void DuckWithQuackCounter::quack()
{
    duckInstance->quack();
    quackCount++;
    notifyObservers();
}

int DuckWithQuackCounter::getQuackCount()
{
    return quackCount;
}

void DuckWithQuackCounter::registerObserver(IObserver* observer)
{
    duckInstance->registerObserver(observer);
}

void DuckWithQuackCounter::notifyObservers()
{
    /*
        Each Quackable does its own notification, so Decorator doesn’t have to worry about it.
        This happens when Decorator class delegates quack() to the duck object it is decorating(check quack function above).
    */
}
