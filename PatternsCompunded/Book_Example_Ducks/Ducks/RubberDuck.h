#pragma once

#include "../IQuackable.h"
#include "../QuackTracker_Observer/DuckSubject.h"

class RubberDuck : public IQuackable
{
private:
    DuckSubject* duckSubject;    
public:
    RubberDuck();
    void quack() override;
    inline std::string getName() override {return "Rubber Duck";};
    void registerObserver(IObserver* observer) override;
    void notifyObservers() override;
};


