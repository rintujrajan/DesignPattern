#pragma once
#include "ISubject.h"
#include "../IQuackable.h"
#include "vector"
/*
 Each concrete Quackable has an instance of Subject/Observable to keep track of their observers and notify them when the Quackable quacks. 

 We could approach this by implementing registration and notification in each and every class (like we did with Observer pattern example).
 But we’re going to do it a little differently this time: 
 we’re going to encapsulate the registration and notification code in another class, call it DuckSubject/Observable.
 That way we only write the real code once and the Subject just needs enough code to delegate to the helper class Observable.
 E.g.
 a. RedHead duck uses uses composition of ISubject and then from there delegates the call to the current class for registration and notification.
 b. FLock in a similar way delegates but delegates to each individual quackable under it
*/
class DuckSubject : public ISubject
{
private:
    std::vector<IObserver*> observers;
    IQuackable* localDuckSubject;
public:
    DuckSubject(IQuackable* duckSubject);
    void registerObserver(IObserver* observer) override;
    void notifyObservers() override;
};

