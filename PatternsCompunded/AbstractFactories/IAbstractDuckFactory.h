#pragma once
class IQuackable;
class IAbstractDuckFactory
{
public:
    virtual IQuackable* createMallardDuck() = 0;
    virtual IQuackable* createRedHeadDuck() = 0;
    virtual IQuackable* createDuckCall() = 0;
    virtual IQuackable* createRubberDuck() = 0;
};
