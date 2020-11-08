#pragma once

#include "../IQuackable.h"
#include "../QuackTracker_Observer/DuckSubject.h"

class DuckCall : public IQuackable
{
private:
    DuckSubject* duckSubject;
public:
    DuckCall();
    void quack() override;
    inline std::string getName() override {return "Duck Call";};
    void registerObserver(IObserver* observer) override;
    void notifyObservers() override;
};


