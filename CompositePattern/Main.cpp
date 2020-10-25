#include <iostream>
#include <iomanip>
#include "MenuComponent.h"
#include "MenuItem.h"
#include "Menu.h"
#include "Iterators\IIterator.h"
/*
    
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
// void printMenu(IIterator* iterator)
// {
//     printMenuTitle();
//     printDashLine();
//     while(iterator->hasNext())
//     {
//         MenuItem* item = iterator->next();
//         std::cout<<item;
//     }
//     printDashLine();
// }
void addPancakeMenuItems(MenuComponent* pancakeHouseMenu)
{
    pancakeHouseMenu->add(new MenuItem("K&B's Pancake Breakfast","Pancakes with scrambled eggs, and toast",true,2.99));
    // pancakeHouseMenu->add(new MenuItem("Regular Pancake Breakfast","Pancakes with fried eggs, sausage",false,2.99));
    // pancakeHouseMenu->add(new MenuItem("Blueberry Pancakes","Pancakes made with fresh blueberries",true,3.49));
    // pancakeHouseMenu->add(new MenuItem("Waffles","Waffles, with your choice of blueberries or strawberries",true,3.59));
}

void addDinerMenuItems(MenuComponent* dinerMenu)
{
    dinerMenu->add(new MenuItem("Vegetarian BLT", "(Fakin) Bacon with lettuce & tomato on whole wheat", true, 2.99));
    // dinerMenu->add(new MenuItem("BLT", "Bacon with lettuce & tomato on whole wheat", false, 2.99));
    // dinerMenu->add(new MenuItem("Soup of the day", "Soup of the day, with a side of potato salad", false, 3.29));
    // dinerMenu->add(new MenuItem("Hotdog", "A hot dog, with saurkraut, relish, onions, topped with cheese", false, 3.05));
}

void addDessertMenuItems(MenuComponent* desertMenu)
{
    desertMenu->add(new MenuItem("Apple Pie", "Apple pie with a flakey crust, topped with vanilla icecream", true, 1.59));
    // desertMenu->add(new MenuItem("Cheesecake", "Creamy New York cheesecake, with a chocolate graham crust", true, 1.99));
    // desertMenu->add(new MenuItem("Sorbet", "A scoop of raspberry and a scoop of lime", true, 1.89));
}

int main()
{
    MenuComponent* pancakeHouseMenu = new Menu("PANCAKE HOUSE MENU", "Breakfast");
    MenuComponent* dinerMenu = new Menu("DINER MENU", "Lunch");
    MenuComponent* dessertMenu = new Menu("DESSERT MENU", "Dessert of course!");
    MenuComponent* allMenus = new Menu("ALL MENUS", "All menus combined");

    addPancakeMenuItems(pancakeHouseMenu);
    addDinerMenuItems(dinerMenu);
    dinerMenu->add(dessertMenu, true);
    addDessertMenuItems(dessertMenu);

    allMenus->add(pancakeHouseMenu);
    allMenus->add(dinerMenu);

    allMenus->print();
    IIterator* it = allMenus->createIterator();
    printDashLine();
    printDashLine();
    while(it->hasNext())
    {
        MenuComponent* component = it->next();
        component->print();
    }

    std::cin.get();

    delete pancakeHouseMenu;
    delete dinerMenu;
    delete dessertMenu;
    delete allMenus;
    
    return 0;
}