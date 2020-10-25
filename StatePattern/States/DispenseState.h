#pragma once
#include "IState.h"

class GumBallMachine;

class DispenseState : public IState
{
    GumBallMachine* localGumBallMachineInstance;
public:
    DispenseState(GumBallMachine* gumBallMachine);
    void insertQuarter() override;
    void ejectQuarter() override;
    bool turnCrank() override;
    void dispenseGumBall() override;
    bool addGumBalls(int noOfGumBallsToAdd) override;
};


