#pragma once
class IState
{
public:
    virtual void insertQuarter() = 0;
    virtual void ejectQuarter() = 0;
    virtual bool turnCrank() = 0;
    virtual void dispenseGumBall() = 0;
    virtual bool addGumBalls(int noOfGumBallsToAdd) = 0;
};


