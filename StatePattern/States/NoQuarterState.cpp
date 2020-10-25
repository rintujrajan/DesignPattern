#include "NoQuarterState.h"
#include "../GumBallMachine.h"
#include <iostream>

NoQuarterState::NoQuarterState(GumBallMachine* gumBallMachine)
{
    localGumBallMachineInstance = gumBallMachine;
}

void NoQuarterState::insertQuarter()
{
    std::cout<<"You inserted a quarter"<<"\n";
    localGumBallMachineInstance->setState(
        localGumBallMachineInstance->getCorrespondingState(GumBallMachine::State::HAS_QUARTER));
}

void NoQuarterState::ejectQuarter()
{
    std::cout<<"You haven't inserted a quarter"<<"\n";
}

bool NoQuarterState::turnCrank()
{
    std::cout<<"You tried to turn, but there's no quarter"<<"\n";
    return false;
}

void NoQuarterState::dispenseGumBall()
{
    std::cout<<"You need to pay first"<<"\n";
}

bool NoQuarterState::addGumBalls(int noOfGumBallsToAdd)
{
    std::cout<< noOfGumBallsToAdd << " gumballs shall be added to the bowl"<<"\n";
    return true;
}