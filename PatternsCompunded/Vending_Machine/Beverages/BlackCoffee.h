#ifndef BLACKCOFFEE_H
#define BLACKCOFFEE_H

#include "IBeverage.h"
class BlackCoffee : public IBeverage
{
private:
    BlackCoffee() = default;
    BeverageSize beverageSize;
public:
    BlackCoffee(BeverageSize selBeverageSize);
    virtual float cost() override;
    virtual inline BeverageSize getBeverageSize() override
    {
        return beverageSize;
    }
    ~BlackCoffee() = default;
};


#endif