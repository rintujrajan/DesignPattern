#pragma once
#include "States\IState.h"
#include <ostream>

class GumBallMachine
{
public:
    enum State{ SOLD_OUT, NO_QUARTER, HAS_QUARTER, DISPENSE};    
    friend class DispenseState;  
private:
    IState *soldOutState; 
    IState *noQuarterState; 
    IState *hasQuarterState; 
    IState *dispenseState; 
    IState *curState;
    int numberOfGumBallsAvailable;  
public:
    GumBallMachine(int noOfGumBallsToStart);
    void insertQuarter();
    void ejectQuarter();
    void turnCrank();
    void setState(IState* state);
    IState* getCorrespondingState(State state);
    void addGumBalls(int noOfGumBallsToAdd);
    friend std::ostream& operator<<(std::ostream& out, const GumBallMachine* gumBallMachine);
private:
    void dispenseGumBall();
    void printCurrentState();
};

