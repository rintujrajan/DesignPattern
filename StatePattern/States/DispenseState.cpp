#include "DispenseState.h"
#include "../GumBallMachine.h"
#include <iostream>

DispenseState::DispenseState(GumBallMachine* gumBallMachine)
{
    localGumBallMachineInstance = gumBallMachine;
}

void DispenseState::insertQuarter()
{
    std::cout<<"Please wait, we're already giving you a gumball"<<"\n";
}

void DispenseState::ejectQuarter()
{
    std::cout<<"Sorry, you already turned the crank. Dispensing in progress"<<"\n";
}

bool DispenseState::turnCrank()
{
    std::cout<<"Turning twice doesn't get you another gumball!"<<"\n";
    return false;
}

void DispenseState::dispenseGumBall()
{
    localGumBallMachineInstance->dispenseGumBall();
    if(localGumBallMachineInstance->numberOfGumBallsAvailable>0)
    {
        localGumBallMachineInstance->setState(
            localGumBallMachineInstance->getCorrespondingState(GumBallMachine::State::NO_QUARTER));   
    }
    else
    {
       localGumBallMachineInstance->setState(
            localGumBallMachineInstance->getCorrespondingState(GumBallMachine::State::SOLD_OUT));   
    }
}

bool DispenseState::addGumBalls(int noOfGumBallsToAdd)
{
    std::cout<<"Sorry, gumball machine is in operation.Try again later"<<"\n";
    return false;
}