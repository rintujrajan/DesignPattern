#include "Coffee.h"
#include <iostream>

void Coffee::brewBeverage()
{
    std::cout<<"Steeping the Coffee\n";
}
bool Coffee::customerNeedsCondiments()
{
    std::cout<<"Do you wish to have milk and sugar with your Coffee?(y/n)";
    char input;
    std::cin>>input;
    isCondimentsAdded = (input == 'y');
    return isCondimentsAdded;
}

void Coffee::addCondiments()
{
    std::cout<<"Adding milk and sugar\n";
}

std::ostream& operator<<(std::ostream& out,const Coffee& coffee)
{
    out<<"Coffee prepared ";
    if(coffee.isCondimentsAdded)
    {
        out<<"with milk and sugar as added condiments";
    }
    else
    {
        out<<"with no added condiment(s)";
    }   
    out<<"\n";
    return out;
}