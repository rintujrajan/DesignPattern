#include "Flock.h"

Flock::Flock()
{
    duckSubject = new DuckSubject(this);
}

void Flock::add(IQuackable* quacker)
{
    quackers.push_back(quacker);
}

void Flock::quack()
{
    auto it = quackers.begin();
    for(;it != quackers.end(); ++it)
    {
        IQuackable* quacker = *it;
        quacker->quack();
    }
}
/*
    When you register as an Observer with the Flock, you actually get registered with everything that’s in the flock,
    which is every Quackable, whether it’s a duck or another Flock.
    We iterate through all the Quackables in the Flock and delegate the call to each Quackable.
    If the Quackable is another Flock, it will do the same(recursion).

*/
void Flock::registerObserver(IObserver* observer)
{
    auto it = quackers.begin();
    for(;it != quackers.end(); ++it)
    {
        IQuackable* quacker = *it;
        quacker->registerObserver(observer);
    }
}

void Flock::notifyObservers()
{
    /*
        Each Quackable does its own notification, so Flock doesn’t have to worry about it.
        This happens when Flock delegates quack() to each Quackable in the Flock(check quack function above).
    */
}