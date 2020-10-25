#include "HasQuarterState.h"
#include "../GumBallMachine.h"
#include <iostream>

HasQuarterState::HasQuarterState(GumBallMachine* gumBallMachine)
{
    localGumBallMachineInstance = gumBallMachine;
}

void HasQuarterState::insertQuarter()
{
    std::cout<<"A quarter is already inserted, you can't insert another"<<"\n";
}

void HasQuarterState::ejectQuarter()
{
    std::cout<<"Quarter returned"<<"\n";
    localGumBallMachineInstance->setState(
        localGumBallMachineInstance->getCorrespondingState(GumBallMachine::State::NO_QUARTER));    
}

bool HasQuarterState::turnCrank()
{
    std::cout<<"You turned..."<<"\n";
    localGumBallMachineInstance->setState(
        localGumBallMachineInstance->getCorrespondingState(GumBallMachine::State::DISPENSE)); 
    return true;     
}

void HasQuarterState::dispenseGumBall()
{
  std::cout<<"No gumball dispensed"<<"\n";
}

bool HasQuarterState::addGumBalls(int noOfGumBallsToAdd)
{
    std::cout<<"Sorry, gumball machine is in operation.Try again later"<<"\n";
    return false;
}