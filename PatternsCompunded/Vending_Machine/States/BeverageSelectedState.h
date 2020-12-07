#pragma once
#include "IState.h"

class BeverageSelectedState : public IState
{
public:
    BeverageSelectedState(VendingMachine* vendingMachine);
    void readyToTakeOrder() override;
    bool beverageSelected() override;
    bool cashCollected() override;
    void changeDispensed() override;
    void beverageDispensedOrCancelOperation() override;
};
