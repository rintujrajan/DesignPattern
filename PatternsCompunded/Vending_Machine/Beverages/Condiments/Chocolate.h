#pragma once

#include "ICondiment.h"

class Chocolate : public ICondiment
{
private:
    Chocolate() = default;
public:
    Chocolate(IBeverage* beverage);
    ~Chocolate();
    virtual float cost() override;
    virtual inline BeverageSize getBeverageSize() override
    {
        return baseBeverage->getBeverageSize();
    }
};
