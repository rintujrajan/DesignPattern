#ifndef STEAMEDMILK_H
#define STEAMEDMILK_H

#include "ICondiment.h"

class SteamedMilk : public ICondiment
{
private:
    SteamedMilk() = default;
public:
    SteamedMilk(IBeverage* beverage);
    ~SteamedMilk();
    virtual float cost() override;
    virtual inline BeverageSize getBeverageSize() override
    {
        return baseBeverage->getBeverageSize();
    }
};

#endif