#pragma once

#include "../IQuackable.h"
#include "Geese.h"
#include "../QuackTracker_Observer/DuckSubject.h"

class GeeseAdapter : public IQuackable
{
private:
    Geese* geeseInstance;
    DuckSubject* duckSubject;
public:
    GeeseAdapter(Geese* geese);
    void quack() override;
    inline std::string getName() override {return "Masked Goose";};
    void registerObserver(IObserver* observer) override;
    void notifyObservers() override;
};


