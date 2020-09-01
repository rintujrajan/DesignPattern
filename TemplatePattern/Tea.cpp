#include "Tea.h"
#include <iostream>

void Tea::brewBeverage()
{
    std::cout<<"Steeping the tea\n";
}
bool Tea::customerNeedsCondiments()
{
    std::cout<<"Do you wish to have lemon with your tea?(y/n)";
    char input;
    std::cin>>input;
    isCondimentsAdded = (input == 'y');
    return isCondimentsAdded;
}
void Tea::addCondiments()
{
    std::cout<<"Adding lemon\n";
}

std::ostream& operator<<(std::ostream& out,const Tea& tea)
{
    out<<"Tea prepared ";
    if(tea.isCondimentsAdded)
    {
        out<<"with lemon as added condiment";
    }
    else
    {
        out<<"with no added condiment(s)";
    }   
    out<<"\n";
    return out;
}