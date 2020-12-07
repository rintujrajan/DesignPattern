#pragma once

#include "../IQuackable.h"
#include "../QuackTracker_Observer/DuckSubject.h"

class MallardDuck : public IQuackable
{
private:
    DuckSubject* duckSubject;
public:
    MallardDuck();
    void quack() override;
    inline std::string getName() override {return "Mallard Duck";};
    void registerObserver(IObserver* observer) override;
    void notifyObservers() override;
};


