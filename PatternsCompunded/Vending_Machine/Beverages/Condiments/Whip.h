#pragma once

#include "ICondiment.h"

class Whip : public ICondiment
{
private:
    Whip() = default;
public:
    Whip(IBeverage* beverage);
    ~Whip();
    virtual float cost() override;
    virtual inline BeverageSize getBeverageSize() override
    {
        return baseBeverage->getBeverageSize();
    }
};
