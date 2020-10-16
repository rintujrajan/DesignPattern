#include "PancakeHouseMenu.h"
#include "../Iterators/PancakeHouseMenuIterator.h"

PancakeHouseMenu::PancakeHouseMenu()
{
    addItem("K&B's Pancake Breakfast","Pancakes with scrambled eggs, and toast",true,2.99);
    addItem("Regular Pancake Breakfast","Pancakes with fried eggs, sausage",false,2.99);
    addItem("Blueberry Pancakes","Pancakes made with fresh blueberries",true,3.49);
    addItem("Waffles","Waffles, with your choice of blueberries or strawberries",true,3.59);
}

PancakeHouseMenu::~PancakeHouseMenu()
{
    menuItems.clear();
    for (auto menuItem : menuItems)
    {
        delete menuItem;
    }
}

void PancakeHouseMenu::addItem(std::string name, std::string description,bool vegetarian, double price)
{
    MenuItem* menuItem = new MenuItem(name,description,vegetarian,price);
    menuItems.push_back(menuItem);
}

/*
    Each ConcreteAggregate is responsible for instantiating a ConcreteIterator that can iterate over its collection of objects.
    PancakeHouseMenu implements the IMenu interface, which means it need to implement the createIterator() method.
*/
IIterator* PancakeHouseMenu::createIterator() //similar to begin() in std Iterators
{
    // initializes the iterator with zeroeth index of the aggregate
    // The ConcreteAggregate has a collection of objects and implements the method that returns an Iterator for its collection.
    return new PancakeHouseMenuIterator(menuItems);
}