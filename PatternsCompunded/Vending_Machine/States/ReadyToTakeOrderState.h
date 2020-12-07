#pragma once
#include "IState.h"

class ReadyToTakeOrderState : public IState
{
public:
    ReadyToTakeOrderState(VendingMachine* vendingMachine);
    void readyToTakeOrder() override;
    bool beverageSelected() override;
    bool cashCollected() override;
    void changeDispensed() override;
    void beverageDispensedOrCancelOperation() override;
};
