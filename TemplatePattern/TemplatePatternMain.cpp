#include <iostream>
#include "Tea.h"
#include "Coffee.h"
/*
    The Template Method Pattern defi nes the skeleton of an algorithm in a method,
    deferring some steps to subclasses. Template Method lets subclasses redefine
    certain steps of an algorithm without changing the algorithm’s structure.

    This pattern is all about creating a template for an algorithm. 
    It’s a method that defines an algorithm as a set of steps.
    One or more of these steps is defined to be pure virtual and implemented by a subclass. 
    This ensures the algorithm’s structure stays unchanged, 
    while subclasses provide some part of the implementation.

    The Strategy and Template Method Patterns both encapsulate algorithms,
    one by inheritance and one by composition.
    The Factory Method is a specialization of Template Method.

    In our example, the algorithm is about creating two different Caffeinated beverages.
    The steps to create the beverages - tea and coffee is the algorithm.
    Parts of the algorithm are common for creating them and some are different
    The algotithm for it is inside the prepareBeverage method called from herein
    Each class has to fill in for the specific parts
*/

int main()
{

    int input = 255;
    while (input != 0)
    {
            std::cout<<"\n*********************\n"
                        <<"Select beverage to prepare.\n"
                        <<"1. Tea\n"
                        <<"2. Coffee\n"
                        <<"Hit 0 to exit\nSelection:";
             std::cin>>input;

             if(input == 1)
             {
                std::cout<<"Preparing Tea...\n";
                Tea tea;
                tea.prepareBeverage();
                std::cout<<tea;
             }
             else if(input == 2)
             {
                std::cout<<"Preparing Coffee...\n";
                Coffee coffee;
                coffee.prepareBeverage();
                std::cout<<coffee;
             }
             else
             {
                std::cout<<"Incorrect Input!\n";
             }
    }
    
    std::cin.get();

    return 0;
}