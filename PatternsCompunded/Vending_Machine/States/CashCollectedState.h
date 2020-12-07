#pragma once
#include "IState.h"

class CashCollectedState : public IState
{
public:
    CashCollectedState(VendingMachine* vendingMachine);
    void readyToTakeOrder() override;
    bool beverageSelected() override;
    bool cashCollected() override;
    void changeDispensed() override;
    void beverageDispensedOrCancelOperation() override;    
};
