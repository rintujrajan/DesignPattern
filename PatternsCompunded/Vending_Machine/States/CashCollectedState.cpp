#include "CashCollectedState.h"
#include <iostream>
#include "../VendingMachine.h"
#include <cmath>

CashCollectedState::CashCollectedState(VendingMachine* vendingMachine)
{
    vendingMachineInstance = vendingMachine;
}

void CashCollectedState::readyToTakeOrder()
{
    std::cout<<"\n";
    vendingMachineInstance->setState(VendingMachine::MachineState::CASH_COLLECTED);
}

bool CashCollectedState::beverageSelected()
{
    return false;
}

bool CashCollectedState::cashCollected()
{
    float cost = vendingMachineInstance->getCostOfSelectedBeverage();
    float moneyReceived = vendingMachineInstance->getMoneyReceived();
    float change = moneyReceived - cost;
    if(change >= 0)
    {
        std::cout<< "Change dispensed:"<<change<<"\n";
        vendingMachineInstance->setState(VendingMachine::MachineState::CHANGE_DISPENSED);
        return true;
    }
    else
    {
        std::cout<<"You have paid " << std::abs(change) << " less. Money returned. Please provide proper cash.\n";
        vendingMachineInstance->setState(VendingMachine::MachineState::BEVERAGE_SELECTED);
        return false;
    }
}
void CashCollectedState::changeDispensed()
{
    std::cout<<"\n";
}
void CashCollectedState::beverageDispensedOrCancelOperation()
{    
    std::cout<<"Reset to starting status...\n";
    vendingMachineInstance->setState(VendingMachine::MachineState::READY_TO_TAKE_ORDER);
}