#pragma once
#include "IState.h"

class GumBallMachine;

class SoldOutState : public IState
{
    GumBallMachine* localGumBallMachineInstance;
public:
    SoldOutState(GumBallMachine* gumBallMachine);
    void insertQuarter() override;
    void ejectQuarter() override;
    bool turnCrank() override;
    void dispenseGumBall() override;
    bool addGumBalls(int noOfGumBallsToAdd) override;
};


