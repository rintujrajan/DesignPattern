#include <iostream>
#include <iomanip>
#include "Iterators/PancakeHouseMenuIterator.h"
#include "Iterators/DinerMenuIterator.h"

/*
    Definition:
    The Iterator Pattern provides a way to access the elements of an aggregate object sequentially without exposing its underlying representation.

    It also places the task of traversal on the iterator object, not on the aggregate (Pancake Menu, Diner Menu, etc.),
    which simplifies the  aggregate interface and implementation, and places the responsibility where it should be.
    This not only keeps the aggregate interface and implementation simpler, it removes the responsibility for iteration from the
    aggregate and keeps the aggregate focused on the things it should be focused on (managing a collection of objects), not on iteration.

    The two aggregates in our code use two differenr ways of aggregation.
    - Diner Menu uses C style array 
    - Pancake Menu used std::vector

    The PancakeHouseMenu and DinerMenu classes implement an interface, IMenu. 
    The IMenuinterface has one method, createIterator(), that is implemented by PancakeHouseMenu and DinerMenu.
    Each menu class assumes the responsibility of creating a concrete Iterator that is appropriate for its internal implementation of the menu items.

    What if we allowed our aggregates to implement their internal collections and related operations AND the iteration methods?
    - Well, we already know that would expand the number of methods in the aggregate, but so what? Why is that so bad?
    - Well, to see why, you first need to recognize that when we allow a class to not only take care of its own business (managing
      some kind of aggregate) but also take on more responsibilities (like iteration) then we’ve given the class two reasons to change.
      Two? Yup, two: it can change if the collection changes in some way, and it can change if the way we iterate changes.

    So once again our friend CHANGE is at the center of another design principle:

    Design Principle: A class should have only one reason to change.(S in SOLID)

    Every responsibility of a class is an area of potential change.
    More than one responsibility means more than one area of change. This principle guides us to keep each class to a single responsibility.

*/

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
    // we can use an Iterator to iterate over any list of menu items without having to know about how the list of items is implemented
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
    /*
        Client only needs to be concerned with Menus and Iterators.
        The client is decoupled from the implementation of the menus,
        so we can use an Iterator to iterate over any list of menu items without having to know about how the list of items is implemented
    */

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