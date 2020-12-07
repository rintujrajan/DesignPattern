#pragma once
#include "../IQuackable.h"
#include "../QuackTracker_Observer/DuckSubject.h"
#include <vector>

class Flock: public IQuackable
{
private:
    std::vector<IQuackable*> quackers;
    DuckSubject* duckSubject;
public:
    Flock();
    void add(IQuackable* quacker);
    void quack() override;
    void registerObserver(IObserver* observer) override;
    void notifyObservers() override;
};