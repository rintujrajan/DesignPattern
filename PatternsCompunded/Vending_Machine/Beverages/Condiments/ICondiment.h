#ifndef ICONDIMENT_H
#define ICONDIMENT_H
#include "../IBeverage.h"
class ICondiment : public IBeverage
{
protected:
    IBeverage* baseBeverage;
};
#endif