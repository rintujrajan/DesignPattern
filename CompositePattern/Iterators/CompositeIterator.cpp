#include "CompositeIterator.h"
#include "../Menu.h"
#include "../MenuItem.h"

CompositeIterator::CompositeIterator(std::vector<MenuComponent*> menuComponents)
{
    this->menuComponents = menuComponents;
    menuComponentsIterator = this->menuComponents.begin();
    menuqueue.push(dynamic_cast<Menu*>(*menuComponentsIterator));
    looper = 0;
    looping = true;
    curMenu = menuqueue.front();
}

bool CompositeIterator::hasNext()
{
    bool hasNext = false;
    if(!menuqueue.empty())
    {
        hasNext = true;
        if(looping) return true;
        curMenu = menuqueue.front();
    }
    else
    {
        menuComponentsIterator++;
        if(menuComponentsIterator != menuComponents.end())
        {
            menuqueue.push(dynamic_cast<Menu*>(*menuComponentsIterator));
            curMenu = menuqueue.front();
            hasNext = true;
        }
    }
    
    return hasNext;
}
MenuComponent* CompositeIterator::next()
{
    static bool flag = false;
    MenuItem* menuItem = nullptr;
    // bool newMenuBeingLooped = false;
    // if(hasNext())
    // {
        // MenuComponent* menuComponent = curMenu->getChild(looper);
        MenuComponent* menuComponent = curMenu;
        if(menuComponent->hasChildMenu() & flag)
        {
            menuqueue.push(dynamic_cast<Menu*>(menuComponent));
            // curMenu = menuqueue.back();
            // looper = 0;
            // menuItem =  dynamic_cast<MenuItem*>(curMenu->getChild(looper));
            // newMenuBeingLooped = true;
        }
        else
        {
            // menuItem =  dynamic_cast<MenuItem*>(menuComponent);
            menuComponent = curMenu->getChild(looper);
        }
        looper++;
        looping = looper< curMenu->size();
        if(!looping)
        {
            menuqueue.pop();
            // if(!newMenuBeingLooped)
             looper = 0;
        }
    // }
    flag = true;
    return menuComponent;
}