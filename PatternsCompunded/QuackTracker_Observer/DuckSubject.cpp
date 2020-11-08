#include "DuckSubject.h"
#include "IObserver.h"
#include "ISubject.h"

DuckSubject::DuckSubject(IQuackable* duckSubject)
{
    localDuckSubject = duckSubject;
}

void DuckSubject::registerObserver(IObserver* observer)
{
    observers.push_back(observer);
}
void DuckSubject::notifyObservers()
{
    if(!observers.empty())
    {
        for (auto &observer : observers)
        {
            observer->update(localDuckSubject);
        }
    }
}