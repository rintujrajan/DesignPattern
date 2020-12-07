#pragma once
#include "../IQuackable.h"
#include "../QuackTracker_Observer/DuckSubject.h"

class DuckWithQuackCounter : public IQuackable
{
private:
    IQuackable* duckInstance;
    static int quackCount;
    DuckSubject* duckSubject;
public:
    DuckWithQuackCounter(IQuackable* duck);
    ~DuckWithQuackCounter();
    void quack() override;
    static int getQuackCount();
    void registerObserver(IObserver* observer) override;
    void notifyObservers() override;
};


