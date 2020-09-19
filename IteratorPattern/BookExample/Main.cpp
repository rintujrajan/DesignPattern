#include <iostream>
#include <iomanip>
#include "Iterators/PancakeHouseMenuIterator.h"
#include "Iterators/DinerMenuIterator.h"

void printMenuTitle()
{
    std::cout<<std::left;
    std::cout << std::setw(30) << "Name"
        << std::setw(70) << "Description"
        << std::setw(10) << "Price"
        << std::setw(5) <<  "Veg/Non-Veg\n";
}
void printDashLine()
{
    for (int i = 0; i <125; i++)
    {
        std::cout<<"-";
    }
    std::cout<<"\n";
}
void printMenu(IIterator* iterator)
{
    printMenuTitle();
    printDashLine();
    while(iterator->hasNext())
    {
        MenuItem* item = iterator->next();
        std::cout<<item;
    }
    printDashLine();
}
int main()
{
    PancakeHouseMenu pancakeHouseMenu;
    IIterator *panCakeHouseIterator = pancakeHouseMenu.createIterator(); 
    printMenu(panCakeHouseIterator);

    std::cout<<"\n\n";

    DinerMenu dinerMenu; 
    IIterator *dinerIterator = dinerMenu.createIterator(); 
    printMenu(dinerIterator);

    std::cin.get();

    delete panCakeHouseIterator;
    delete dinerIterator;
    return 0;
}