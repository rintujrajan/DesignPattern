#pragma once
#include <string>
/*
    The ISubject(A Quack Observable) interface gives us a set of methods that any Subject/Observable must implement.
*/
class IObserver;
class ISubject
{
public:
    virtual void registerObserver(IObserver* observer) = 0;
    virtual void notifyObservers() = 0;
};


