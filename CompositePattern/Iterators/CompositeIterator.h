#pragma once
#include "IIterator.h"
#include <vector>
#include <queue>
/*
    The ConcreteIterator is responsible for managing the current position of the iteration.
    It is manged by pIteratorPosition in here.
*/
class MenuItem;
class Menu;
class CompositeIterator : public IIterator 
{
private:
    std::vector<MenuComponent*> menuComponents;
    std::vector<MenuComponent*>::iterator menuComponentsIterator;
    std::queue<Menu*> menuqueue;
    std::vector<MenuItem*> menuItems;
    std::vector<MenuItem*>::iterator menuItemsIterator;
    Menu* curMenu;
    int looper;
    bool looping;
public:
    CompositeIterator(std::vector<MenuComponent*> menuComponents);
    bool hasNext();
    MenuComponent* next();
};

