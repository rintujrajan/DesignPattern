#include "Menu.h"
#include <iostream>
#include <algorithm>
#include <iomanip>
#include "Iterators\CompositeIterator.h"

Menu::Menu(std::string name, std::string description)
{
    mName = name;
    mDescription = description;
    mHasChildMenu = false;
    iterator = nullptr;
}

void Menu::add(MenuComponent* component, bool hasChildMenu)
{
    menuComponents.push_back(component);
    mHasChildMenu = hasChildMenu;
}

void Menu::remove(MenuComponent* component)
{
    std::vector<MenuComponent*>::iterator it = std::find_if(menuComponents.begin(), menuComponents.end(), 
                                                        [component](const MenuComponent* componentLhs)
                                                        { return componentLhs->GetName() == component->GetName();});
    if(it!=menuComponents.end())
    {
        menuComponents.erase(it);
    }
    mHasChildMenu = menuComponents.size() != 0;
}

MenuComponent* Menu::getChild(int i)
{
    return (menuComponents[i]);
}

void Menu::print()
{
    std::cout<<"\n\n";
    printDashLine();
    std::cout<<std::left;
    std::cout << std::setw(30) << mName
        << std::setw(70) << mDescription<<"\n";
    printDashLine();
    for(auto menuComponent : menuComponents)
    {
        menuComponent->print();
    }
}

IIterator* Menu::createIterator()
{
    if(iterator == nullptr)
    {
        iterator = new CompositeIterator(menuComponents);
    }
    return iterator;
}
size_t Menu::size()
{
    return menuComponents.size();
}