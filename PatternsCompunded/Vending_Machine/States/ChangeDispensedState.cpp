#include "ChangeDispensedState.h"
#include <iostream>
#include "../VendingMachine.h"

ChangeDispensedState::ChangeDispensedState(VendingMachine* vendingMachine)
{
    vendingMachineInstance = vendingMachine;
}

void ChangeDispensedState::readyToTakeOrder()
{
}

bool ChangeDispensedState::beverageSelected()
{
    return false;
}

bool ChangeDispensedState::cashCollected()
{
    return false;
}

void ChangeDispensedState::changeDispensed()
{
    std::cout<<"Dispensing beverage...\n";
    vendingMachineInstance->setState(VendingMachine::MachineState::BEVERAGE_DISPENSED);
}

void ChangeDispensedState::beverageDispensedOrCancelOperation()
{
    std::cout<<"Reset to starting status...\n";
    vendingMachineInstance->setState(VendingMachine::MachineState::READY_TO_TAKE_ORDER);
}