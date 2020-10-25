#include "MenuComponent.h"
#include <iostream>

std::string MenuComponent::GetName() const
{
    std::cout<<"Illegal operation!";
    throw;
}
std::string MenuComponent::GetDescription()
{
    std::cout<<"Illegal operation!";
    throw;
}
bool MenuComponent::IsVegetarian()
{
    std::cout<<"Illegal operation!";
    throw;
}
double MenuComponent::GetPrice()
{
    std::cout<<"Illegal operation!";
    throw;
}
void MenuComponent::print()
{
    std::cout<<"Illegal operation!";
    throw;
}
void MenuComponent::add(MenuComponent* component, bool hasChildMenu)
{
    std::cout<<"Illegal operation!";
    throw;
}
void MenuComponent::remove(MenuComponent* component)
{
    std::cout<<"Illegal operation!";
    throw;
}
MenuComponent* MenuComponent::getChild(int i)
{
    std::cout<<"Illegal operation!";
    throw;
}
bool MenuComponent::hasChildMenu()
{
    std::cout<<"Illegal operation!";
    throw;
}
IIterator* MenuComponent::createIterator()
{
    std::cout<<"Illegal operation!";
    throw;
}
size_t MenuComponent::size()
{
    std::cout<<"Illegal operation!";
    throw;
}
void MenuComponent::printDashLine()
{
    for (int i = 0; i <125; i++)
    {
        std::cout<<"-";
    }
    std::cout<<"\n";
}