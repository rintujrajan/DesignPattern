#include "SoldOutState.h"
#include "../GumBallMachine.h"

#include <iostream>

SoldOutState::SoldOutState(GumBallMachine* gumBallMachine)
{
    localGumBallMachineInstance = gumBallMachine;
}

void SoldOutState::insertQuarter()
{
    std::cout<<"You can't insert a quarter, the machine is sold out"<<"\n";
}

void SoldOutState::ejectQuarter()
{
    std::cout<<"You can't eject, you haven't inserted a quarter yet"<<"\n";
}

bool SoldOutState::turnCrank()
{
    std::cout<<"You tried to turn, but there are no gumballs!"<<"\n";
    return false;
}

void SoldOutState::dispenseGumBall()
{
    std::cout<<"No gumball present to dispenseGumBall!"<<"\n";
}

bool SoldOutState::addGumBalls(int noOfGumBallsToAdd)
{
    std::cout<< noOfGumBallsToAdd << " gumballs shall be added to the bowl"<<"\n";
    localGumBallMachineInstance->setState(
        localGumBallMachineInstance->getCorrespondingState(GumBallMachine::State::NO_QUARTER)); 
    return true;
}