#include "CaffeineBeverage.h"
#include <iostream>

void CaffeineBeverage::prepareBeverage()
{
    /* The template method defines the sequence of steps, each represented by a method
       The prepareBeverage() method controls the algorithm, no one can change this,
       and it counts on subclasses to provide some or all of the implementation.

       The Template Method version provides a framework that,
       other caffeine beverages can be plugged into. 
       New caffeine beverages only need to implement a couple of methods
    */
    boilWater();
    brewBeverage();
    pourInCup();
    if(customerNeedsCondiments())
    {
        addCondiments();
    }
}
void CaffeineBeverage::boilWater()
{
    std::cout<<"Boling water for 3 minutes at 300 degrees\n";
}
void CaffeineBeverage::pourInCup()
{
    std::cout<<"Pouring out the prepared beverage in a cup\n";
}