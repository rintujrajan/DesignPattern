#pragma once
#include "IAbstractDuckFactory.h"
class DuckFactory : public IAbstractDuckFactory
{
public:
     IQuackable* createMallardDuck() override;
     IQuackable* createRedHeadDuck() override;
     IQuackable* createDuckCall() override;
     IQuackable* createRubberDuck() override;
};

