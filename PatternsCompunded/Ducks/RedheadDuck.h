#pragma once

#include "../IQuackable.h"
#include "../QuackTracker_Observer/DuckSubject.h"

class RedheadDuck : public IQuackable
{
private:
    DuckSubject* duckSubject;    
public:
    RedheadDuck();
    void quack() override;
    inline std::string getName() override {return "Redhead Duck";};
    void registerObserver(IObserver* observer) override;
    void notifyObservers() override;
};


