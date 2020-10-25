#pragma once
#include "IState.h"

class GumBallMachine;

class NoQuarterState : public IState
{
    GumBallMachine* localGumBallMachineInstance;
public:
    NoQuarterState(GumBallMachine* gumBallMachine);
    void insertQuarter() override;
    void ejectQuarter() override;
    bool turnCrank() override;
    void dispenseGumBall() override;
    bool addGumBalls(int noOfGumBallsToAdd) override;
};


