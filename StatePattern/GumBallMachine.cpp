#include "GumBallMachine.h"
#include "States\SoldOutState.h"
#include "States\NoQuarterState.h"
#include "States\HasQuarterState.h"
#include "States\DispenseState.h"

#include <iostream>

GumBallMachine::GumBallMachine(int noOfGumBallsToStart)
{
    soldOutState = new SoldOutState(this);
    noQuarterState = new NoQuarterState(this);
    hasQuarterState = new HasQuarterState(this);
    dispenseState = new DispenseState(this);
    numberOfGumBallsAvailable = noOfGumBallsToStart;
    if(numberOfGumBallsAvailable < 1)
    {
        curState = soldOutState;
    }
    else
    {
        curState = noQuarterState;
    }
}

void GumBallMachine::insertQuarter()
{
    std::cout<< "Quarter Inserted -> ";
    curState->insertQuarter();
}

void GumBallMachine::ejectQuarter()
{
    std::cout<< "Quarter Ejected -> ";
    curState->ejectQuarter();
}

void GumBallMachine::turnCrank()
{
    std::cout<< "Crank Turned -> ";
    const bool didCrankTurn = curState->turnCrank();
    if(didCrankTurn)
    {
        curState->dispenseGumBall();
    }
}

void GumBallMachine::dispenseGumBall()
{
    std::cout<<"A gumball comes rolling out the slot...\n";
    if(numberOfGumBallsAvailable > 0)
    {
        numberOfGumBallsAvailable--;
    }
}

void GumBallMachine::setState(IState* state)
{
    std::cout<<"State changed from ";
    printCurrentState();

    curState = state;

    std::cout<< " to ";
    printCurrentState();
    std::cout<<"\n"; 
}

IState* GumBallMachine::getCorrespondingState(State state)
{
    IState* returnState= nullptr;
    switch (state)
    {
    case State::SOLD_OUT:
        returnState = soldOutState;
        break;
    case State::NO_QUARTER:
        returnState = noQuarterState;
        break;
    case State::HAS_QUARTER:
        returnState = hasQuarterState;
        break;
    case State::DISPENSE:
        returnState = dispenseState;
        break;                
    }
    return returnState;
}

void GumBallMachine::addGumBalls(int noOfGumBallsToAdd)
{
    if(noOfGumBallsToAdd > 0)
    {
        std::cout<< "Trying to add gumballs -> ";
        if(curState->addGumBalls(noOfGumBallsToAdd))
        {
            numberOfGumBallsAvailable += noOfGumBallsToAdd;
        }
    }    
}

std::ostream& operator<<(std::ostream& out, const GumBallMachine* gumBallMachine)
{
    out<<"XYZ Gumball Company"
        <<"\tInventory: "<<gumBallMachine->numberOfGumBallsAvailable<<"\tState: ";
    if(gumBallMachine->curState == gumBallMachine->soldOutState)
    {
        out<<"Machine is sold out";
    }
    if(gumBallMachine->curState == gumBallMachine->noQuarterState)
    {
        out<<"Machine is waiting for quarter";
    }
    out<<"\n";
    return out;
}

void GumBallMachine::printCurrentState() 
{
    if(curState == soldOutState)
    {
        std::cout<<"\"Sold Out\"";
    }
    else if(curState == noQuarterState)
    {
        std::cout<<"\"No Quarter\"";
    }
    else if(curState == hasQuarterState)
    {
        std::cout<<"\"Has Quarter\"";
    }
    else if(curState == dispenseState)
    {
        std::cout<<"\"Dispense\"";
    }
}