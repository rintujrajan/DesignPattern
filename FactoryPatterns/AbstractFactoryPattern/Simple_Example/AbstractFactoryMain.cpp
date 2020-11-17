#include <iostream>
namespace Products
{
    class IButton
    {
    public:
        virtual void click() = 0;
    };
    class WindowsButton : public IButton
    {
    public:
        WindowsButton()
        {
            std::cout<<"Created Windows button on menu!\n";
        }
        void click()
        {
            std::cout<<"Windows button clicked!\n";
        }
    };
    class LinuxButton : public IButton
    {
    public:
        LinuxButton()
        {
            std::cout<<"Created Linux button on menu!\n";
        }
        void click()
        {
            std::cout<<"Linux button clicked!\n";
        }
    };

    class IMenu
    {
    public:
        virtual void draw() = 0;
    };
    class WindowsMenu : public IMenu
    {
    public:
        WindowsMenu()
        {
            std::cout<<"Created Windows menu!\n";
        }
        void draw()
        {
            std::cout<<"Windows menu drawn!\n";
        }
    };
    class LinuxMenu : public IMenu
    {
    public:
        LinuxMenu()
        {
            std::cout<<"Created Linux menu!\n";
        }
        void draw()
        {
            std::cout<<"Linux menu drawn!\n";
        }
    };
}
namespace Factories
{
    class IAbstractFactory
    {
    public:
        virtual Products::IButton* createButton() = 0;
        virtual Products::IMenu* createMenu() = 0;
    };

    class WindowsFactory : public IAbstractFactory
    {
    public:
        Products::IButton* createButton() override
        {
            return new Products::WindowsButton();
        }
        Products::IMenu* createMenu() override
        {
            return new Products::WindowsMenu();
        }   
    };

    class LinuxFactory : public IAbstractFactory
    {
    public:
        Products::IButton* createButton() override
        {
            return new Products::LinuxButton();
        }  
        Products::IMenu* createMenu() override
        {
            return new Products::LinuxMenu();
        }   
    };
}
class Client
{
private:
    Factories::IAbstractFactory* factory; //for composition
public:
    Client(Factories::IAbstractFactory* factoryRequested)
    {
        factory = factoryRequested;
    }
    void pressButtonOnMenu()
    {
        /* 
        1. The factory method is called directly in here and in AbstractFactory called via object of factory.
        2. The following two lines are inside the client, while in FactoryMethod pattern inside creator classes.
        3. The concrete factory method is called using inheritance via overriding factory method in sub classes,
            while in AbstracFactory, it is called using composition via object of Factory.
        4. In the Abstract Factory pattern, a class delegates the responsibility of object instantiation to another object via composition.
        */
        /* 
            An object "Client", who wants to make a menu object.
            Instead of making the menu/button object itself (e.g., with a factory method),
            it's going to get a different object (the abstract factory) to create the menu/button object.
        */
        Products::IMenu* menu = factory->createMenu();
        menu->draw();
        Products::IButton* button =  factory->createButton();
        button->click();

        delete menu;
        delete button;
    }   
};
/*
    => The most important point to grasp here is that the abstract factory is injected into the client.
       This is why we say that Abstract Factory is implemented by Composition.
    => The intended purpose of the class containing a factory method is not to create objects, e.g. clickButton,
       while an abstract factory should only be used to create objects.
*/
int main()
{   
    std::cout<<"\n*************Abstract Factory Example*************\n";
    Factories::IAbstractFactory* factory = nullptr;
    char input = 127;
    while(input != 'e' && input != 'E')
    {
        std::cout<<"\nPlease choose the OS to use.\nEnter 'w' for Windows or 'l' for linux or 'e' to exit: ";
        std::cin>>input;
        switch (input)
        {
        case 'l':
        case 'L':
            factory = new Factories::LinuxFactory();
            std::cout<<"=> Linux Factory selected\n";
            break;
        case 'w':
        case 'W':
            factory = new Factories::WindowsFactory();
            std::cout<<"=> Windows Factory selected\n";
            break;  
        case 'e':
        case 'E':
            std::cout<<"Exiting loop!\n";
            factory = nullptr;
            break;        
        default:
            std::cout<<"=> Invalid OS selection!\n";
            factory = nullptr;
            break;
        }
        if(factory != nullptr)
        {
            Client client(factory);
            client.pressButtonOnMenu();
            delete factory;
        }
        std::cin.get();
    }
    std::cin.get();
}