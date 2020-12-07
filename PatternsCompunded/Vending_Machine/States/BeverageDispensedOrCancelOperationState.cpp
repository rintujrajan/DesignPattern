#include "BeverageDispensedOrCancelOperationState.h"
#include <iostream>
#include "../VendingMachine.h"

BeverageDispensedOrCancelOperationState::BeverageDispensedOrCancelOperationState(VendingMachine* vendingMachine)
{
    vendingMachineInstance = vendingMachine;
}

void BeverageDispensedOrCancelOperationState::readyToTakeOrder()
{
    std::cout<<"\n";
}

bool BeverageDispensedOrCancelOperationState::beverageSelected()
{
    return false;
}

bool BeverageDispensedOrCancelOperationState::cashCollected()
{
    std::cout<<"\n";
    return false;
}

void BeverageDispensedOrCancelOperationState::changeDispensed()
{
    std::cout<<"\n";
}

void BeverageDispensedOrCancelOperationState::beverageDispensedOrCancelOperation()
{
    std::cout<<"Reset to starting status...\n";
    vendingMachineInstance->setState(VendingMachine::MachineState::READY_TO_TAKE_ORDER);
}