#include "BeverageSelectedState.h"
#include <iostream>
#include "../VendingMachine.h"

BeverageSelectedState::BeverageSelectedState(VendingMachine* vendingMachine)
{
    vendingMachineInstance = vendingMachine;
}

void BeverageSelectedState::readyToTakeOrder()
{
    std::cout<<"Invalid selection. There is a beverage selected. Either pay or cancel order\n";
}

bool BeverageSelectedState::beverageSelected()
{
    float moneyReceived;
    std::cout<<"Please provide payment:";
    std::cin>>moneyReceived;
    std::cout<< "Received money: "<<moneyReceived<<"\n";
    vendingMachineInstance->setMoneyReceived(moneyReceived);
    vendingMachineInstance->setState(VendingMachine::MachineState::CASH_COLLECTED);
    return true;
}

bool BeverageSelectedState::cashCollected()
{
    std::cout<<"\n";
    return false;
}

void BeverageSelectedState::changeDispensed()
{
    std::cout<<"\n";
}
void BeverageSelectedState::beverageDispensedOrCancelOperation()
{
    std::cout<<"Reset to starting status...\n";
    vendingMachineInstance->setState(VendingMachine::MachineState::READY_TO_TAKE_ORDER);
}