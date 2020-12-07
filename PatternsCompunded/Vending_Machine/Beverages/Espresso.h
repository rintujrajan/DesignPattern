#pragma once

#include "IBeverage.h"
class Espresso : public IBeverage
{
private:
    Espresso() = default;
    BeverageSize beverageSize;
public:
    Espresso(BeverageSize selBeverageSize);
    virtual float cost() override;
    virtual inline BeverageSize getBeverageSize() override
    {
        return beverageSize;
    }
    ~Espresso() = default;
};
