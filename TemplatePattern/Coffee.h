#ifndef COFFEE_BEVERAGE
#define COFFEE_BEVERAGE

#include "CaffeineBeverage.h"
#include <ostream>

class Coffee: public CaffeineBeverage 
{
public:
    virtual void brewBeverage();
    virtual void addCondiments();
    virtual bool customerNeedsCondiments();
    friend std::ostream& operator<<(std::ostream& out,const Coffee& coffee);
};
#endif COFFEE_BEVERAGE