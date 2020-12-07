#include "VendingMachine.h"

#include <iostream>

#include "States/ReadyToTakeOrderState.h"
#include "States/BeverageSelectedState.h"
#include "States/CashCollectedState.h"
#include "States/ChangeDispensedState.h"
#include "States/BeverageDispensedOrCancelOperationState.h"

VendingMachine::VendingMachine()
               : curBeverage(nullptr), moneyReceived(0)

{
    readyToTakeOrderState = new ReadyToTakeOrderState(this);
    beverageSelectedState = new BeverageSelectedState(this);
    cashCollectedState = new CashCollectedState(this);
    changeDispensedState = new ChangeDispensedState(this);
    beverageDispensedOrCancelOperationState = new BeverageDispensedOrCancelOperationState(this); 
    curMachineState = readyToTakeOrderState;
}

VendingMachine::~VendingMachine()
{
    delete curBeverage;
    delete readyToTakeOrderState;
    delete beverageSelectedState;
    delete cashCollectedState;
    delete changeDispensedState;
    delete beverageDispensedOrCancelOperationState;
}

void VendingMachine::printCurrentState() 
{
    if(curMachineState == readyToTakeOrderState)
    {
        std::cout<<"\"Ready to take order\"";
    }
    else if(curMachineState == beverageSelectedState)
    {
        std::cout<<"\"Beverage Selected\"";
    }
    else if(curMachineState == cashCollectedState)
    {
        std::cout<<"\"Cash collected\"";
    }
    else if(curMachineState == changeDispensedState)
    {
        std::cout<<"\"Change dispensed\"";
    }
    else if(curMachineState == beverageDispensedOrCancelOperationState)
    {
        std::cout<<"\"Beverage dispensed\"";
    }
}

void VendingMachine::setState(MachineState state)
{
    
    std::cout<<"\n\n\t\t######State changed from ";
    printCurrentState();

    switch (state)
    {
    case MachineState::READY_TO_TAKE_ORDER:
        curMachineState = readyToTakeOrderState;
        break;
    case MachineState::BEVERAGE_SELECTED:
        curMachineState = beverageSelectedState;
        break;
    case MachineState::CASH_COLLECTED:
        curMachineState = cashCollectedState;
        break;
    case MachineState::CHANGE_DISPENSED:
        curMachineState = changeDispensedState;
        break;
    case MachineState::BEVERAGE_DISPENSED:
        curMachineState = beverageDispensedOrCancelOperationState;
        break;
    }
    std::cout<< " to ";
    printCurrentState();
    std::cout<<"######\n\n\n"; 
}

float VendingMachine::getCostOfSelectedBeverage()
{
    if(curBeverage!=nullptr)
    {
        return curBeverage->cost();
    }
    else
    {
        std::cout<<"No beverage currently selected!";
        return 0;
    }
}

void VendingMachine::selectBeverage(int coffeeType,int beverageSize)
{
    delete curBeverage;
    curBeverage = beverageFactory.prepareBeverage(coffeeType,beverageSize);    
}

void VendingMachine::chooseAction()
{
    int input = -1;
    while(input != 0)
    {   
        std::cout<<"\n***********************************************************"
                 <<"\nTake action:"
                 << "\n\t1. Start"
                 << "\n\t2. Pay money"
                 << "\n\t3. Cancel operation"
                 << "\n\t****0 to exit****\n"; 
        std::cout<<"Your action please:";
        std::cin>>input;
        switch (input)
        {
        case 0:
            std::cout<<"Stopping Vending Machine!! Press any key to exit application.";
            break;
        case 1:
            curMachineState->readyToTakeOrder();
            break;
        case 2:
            if(curMachineState->beverageSelected())
            {
                if(curMachineState->cashCollected())
                {
                    curMachineState->changeDispensed();
                    curMachineState->beverageDispensedOrCancelOperation();
                    curBeverage = nullptr;
                }
            }
            break;
        case 3:
            curMachineState->beverageDispensedOrCancelOperation();
            curBeverage = nullptr;
            break;
        }
    }
}

