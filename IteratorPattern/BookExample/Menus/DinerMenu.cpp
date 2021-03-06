#include "DinerMenu.h"
#include "MenuItem.h"
#include "../Iterators/DinerMenuIterator.h"
#include <vector>

DinerMenu::DinerMenu():numberOfItems(0)
{
    addItem("Vegetarian BLT", "(Fakin) Bacon with lettuce & tomato on whole wheat", true, 2.99);
    addItem("BLT", "Bacon with lettuce & tomato on whole wheat", false, 2.99);
    addItem("Soup of the day", "Soup of the day, with a side of potato salad", false, 3.29);
    addItem("Hotdog", "A hot dog, with saurkraut, relish, onions, topped with cheese", false, 3.05);
}

DinerMenu::~DinerMenu()
{
    for (auto menuItem : menuItems)
    {
        delete menuItem;
    }
}

void DinerMenu::addItem(std::string name, std::string description,bool vegetarian, double price)
{
    MenuItem* menuItem = new MenuItem(name,description,vegetarian,price);
    menuItems[numberOfItems] = menuItem;
    numberOfItems++;
}

/*
    Each ConcreteAggregate is responsible for instantiating a ConcreteIterator that can iterate over its collection of objects.
    DinerMenu implements the IMenu interface, which means it need to implement the createIterator() method.
*/
IIterator* DinerMenu::createIterator() //similar to begin() in std Iterators
{
    // initializes the iterator with zeroeth index of the aggregate 
    // The ConcreteAggregate has a collection of objects and implements the method that returns an Iterator for its collection.
    return new DinerMenuIterator(menuItems, numberOfItems);
}