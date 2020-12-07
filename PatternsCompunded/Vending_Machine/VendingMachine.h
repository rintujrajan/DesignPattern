#pragma once
#include "Beverages/IBeverage.h"
#include "States/IState.h"
#include "BeverageFactory.h"

class VendingMachine
{
public:
    enum class MachineState
    {
        READY_TO_TAKE_ORDER,
        BEVERAGE_SELECTED,
        CASH_COLLECTED,
        CHANGE_DISPENSED,
        BEVERAGE_DISPENSED
    };
private:
    IBeverage* curBeverage;
    IState* curMachineState;
    IState* readyToTakeOrderState;
    IState* beverageSelectedState;
    IState* cashCollectedState;
    IState* changeDispensedState;
    IState* beverageDispensedOrCancelOperationState;
    BeverageFactory beverageFactory;
    float moneyReceived;
    void printCurrentState();

public:
    VendingMachine();
    ~VendingMachine();
    void setState(MachineState state);
    float getCostOfSelectedBeverage();
    inline float getMoneyReceived(){ return moneyReceived;} 
    inline void setMoneyReceived(float money){ moneyReceived = money;} 
    void selectBeverage(int coffeeType,int beverageSize);
    void chooseAction();
};
