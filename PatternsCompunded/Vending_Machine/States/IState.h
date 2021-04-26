#pragma once

// #include "../VendingMachine.h"
class VendingMachine;
class IState
{
protected:
    VendingMachine *vendingMachineInstance;

public:
    virtual void readyToTakeOrder() = 0;
    virtual bool beverageSelected() = 0;
    virtual bool cashCollected() = 0;
    virtual void changeDispensed() = 0;
    virtual void beverageDispensedOrCancelOperation() = 0;
    virtual ~IState(){};
};
