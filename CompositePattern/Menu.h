// #pragma once

#include <string>
#include "MenuComponent.h"
#include <vector>

class IIterator;

class Menu : public MenuComponent
{
private:
    std::string mName;
    std::string mDescription;
    std::vector<MenuComponent*> menuComponents;
    bool mHasChildMenu;
    IIterator* iterator;
public:
    Menu(std::string name, std::string description);
    void add(MenuComponent* component, bool hasChildMenu = false) override;
    void remove(MenuComponent* component) override;
    MenuComponent* getChild(int i) override;
    inline std::string GetName() const override{ return mName; };
    void print() override;
    inline bool hasChildMenu() override { return true;}
    size_t size() override;
    IIterator* createIterator() override;
};
