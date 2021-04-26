#pragma once
#include "IState.h"

class ChangeDispensedState : public IState
{
public:
    ChangeDispensedState(VendingMachine *vendingMachine);
    void readyToTakeOrder() override;
    bool beverageSelected() override;
    bool cashCollected() override;
    void changeDispensed() override;
    void beverageDispensedOrCancelOperation() override;
    ~ChangeDispensedState() = default;
};
