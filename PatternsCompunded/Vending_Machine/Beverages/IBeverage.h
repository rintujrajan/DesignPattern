#ifndef IBEVERAGE_H
#define IBEVERAGE_H
#include <ostream>
class IBeverage
{
public:
    enum class BeverageSize
    {
        SMALL = 1,
        MEDIUM = 2,
        LARGE = 3
    };
    virtual float cost() = 0;
    virtual BeverageSize getBeverageSize() = 0;
    virtual ~IBeverage() = 0; //for pure virtual destructor definition has to be provide.Hence the .cpp file!
};

#endif