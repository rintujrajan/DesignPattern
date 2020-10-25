#pragma once
#include "IState.h"

class GumBallMachine;

class HasQuarterState : public IState
{
    GumBallMachine* localGumBallMachineInstance;
public:
    HasQuarterState(GumBallMachine* gumBallMachine);
    void insertQuarter() override;
    void ejectQuarter() override;
    bool turnCrank() override;
    void dispenseGumBall() override;
    bool addGumBalls(int noOfGumBallsToAdd) override;
};


