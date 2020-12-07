#pragma once
#include "IState.h"

class BeverageDispensedOrCancelOperationState : public IState
{
public:
    BeverageDispensedOrCancelOperationState(VendingMachine* vendingMachine);
    void readyToTakeOrder() override;
    bool beverageSelected() override;
    bool cashCollected() override;
    void changeDispensed() override;
    void beverageDispensedOrCancelOperation() override;
};
