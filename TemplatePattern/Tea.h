#ifndef TEA_BEVERAGE
#define TEA_BEVERAGE

#include "CaffeineBeverage.h"
#include <ostream>

class Tea: public CaffeineBeverage 
{
public:
    virtual void brewBeverage();
    virtual void addCondiments();
    virtual bool customerNeedsCondiments();
    friend std::ostream& operator<<(std::ostream& out,const Tea& tea);
};


#endif TEA_BEVERAGE