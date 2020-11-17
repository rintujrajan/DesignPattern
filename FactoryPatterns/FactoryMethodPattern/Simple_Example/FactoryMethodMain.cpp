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
            std::cout<<"Created Windows button!\n";
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
            std::cout<<"Created Linux button!\n";
        }
        void click()
        {
            std::cout<<"Linux button clicked!\n";
        }    
    };
}

/*
    => The most important point to grasp here is that the ConcreteCreator is the client.
       In other words, the client is a subclass whose parent defines the factoryMethod().
       This is why we say that Factory Method is implemented by Inheritance.
    => The factory method is a method, and an abstract factory is an object.
       The Factory Method pattern uses inheritance and relies on a subclass to handle the desired object instantiation.
    => The intended purpose of the class containing a factory method is not to create objects, e.g. clickButton
       while an abstract factory should only be used to create objects.
*/
namespace Creators
{
    class GUI
    {
        public:
        virtual Products::IButton* createButton() = 0;
        void clickButton()
        {
        /* 
        1. The factory method is called directly in here and in AbstractFactory called via object of factory
        2. The following two lines are inside creator classes, while in AbstractFactory pattern it is iniside the client.
        3. The concrete factory method is called using inheritance via overriding factory method in sub classes,
           while in AbstracFactory, it is called using composition via object of Factory
        4. ****The Creator (parent) class invokes its own factoryMethod().****
           If we remove clickButton() from the parent class, leaving only a single method behind, it's no longer the FactoryMethod pattern.
           i.e., FactoryMethod cannot be implemented with less than two methods in the parent class; and one must invoke the other.
        */
            Products::IButton* button = createButton();
            button->click();
        }
    };
    class LinuxGUI : public GUI
    {
        public:
        Products::IButton* createButton()
        {
            return new Products::LinuxButton();
        }
    };
    class WindowsGUI : public GUI
    {
        public:
        Products::IButton* createButton()
        {
            return new Products::WindowsButton();
        }
    };
}

void clickButton(std::string os)
{
    if(os == "Windows")
    {
        Creators::GUI* windowsGUI = new Creators::WindowsGUI();
        windowsGUI->clickButton();   
        delete windowsGUI;     
    }
    else if(os == "Linux")
    {
        Creators::GUI* linuxGUI = new Creators::LinuxGUI();
        linuxGUI->clickButton();
        delete linuxGUI;
    }
}

int main()
{   
    char input = 127;
    while(input != 'e' && input != 'E')
    {
        std::cout<<"\nPlease choose the OS to use.\nEnter 'w' for Windows or 'l' for linux or 'e' to exit: ";
        std::cin>>input;
        switch (input)
        {
        case 'l':
        case 'L':
            clickButton("Linux");
            break;
        case 'w':
        case 'W':
            clickButton("Windows");
            break;  
        case 'e':
        case 'E':
            std::cout<<"Exiting loop!\n";
            break;        
        default:
            std::cout<<"=> Invalid OS selection!\n";
            break;
        }
        std::cin.get();
    }
 
    std::cin.get();
}