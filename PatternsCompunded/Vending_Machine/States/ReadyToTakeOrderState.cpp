#include "ReadyToTakeOrderState.h"
#include <iostream>
#include "../VendingMachine.h"

ReadyToTakeOrderState::ReadyToTakeOrderState(VendingMachine* vendingMachine)
{
    vendingMachineInstance = vendingMachine;
}

void ReadyToTakeOrderState::readyToTakeOrder()
{
    int coffeeType = -1;
    int beverageSize = -1;
    float cost = 0;
    float cashReceived = 0;
    std::cout<<"\nMenu:"
             << "\n\t1. Black Coffee"
             << "\n\t2. Café au Lait(Black Coffee and Steamed milk)"
             << "\n\t3. Espresso"
             << "\n\t4. Latte(Espresso and Steamed milk)"
             << "\n\t5. Cappuccino(Espresso ,Steamed milk and Whip/Foam)"
             << "\n\t6. Mocha(Espresso, Chocolate and Steamed milk)"
             << "\n\t   *****Enter 0 to Exit*****"
             << "\nYour beverage choice please:";
    std::cin>>coffeeType;
    if(coffeeType!=0)
    {
        std::cout<<"\nAvailable Beverage Sizes :"
                 << "\n\t1. Small"
                 << "\n\t2. Medium"
                 << "\n\t3. Large"
                 << "\nYour beverage size please:";
        std::cin>>beverageSize;
        vendingMachineInstance->selectBeverage(coffeeType,beverageSize);
        std::cout<<"Thanks, beverage selection done. Cost of selected beverage is "<<vendingMachineInstance->getCostOfSelectedBeverage();
        vendingMachineInstance->setState(VendingMachine::MachineState::BEVERAGE_SELECTED);
    }  
}

bool ReadyToTakeOrderState::beverageSelected()
{
    std::cout<<"Invalid selection. Please select a beverage.\n";
    return false;
}

bool ReadyToTakeOrderState::cashCollected()
{
    std::cout<<"\n";
    return false;
}

void ReadyToTakeOrderState::changeDispensed()
{
    std::cout<<"\n";
}

void ReadyToTakeOrderState::beverageDispensedOrCancelOperation()
{
    std::cout<<"No action performed\n";
}