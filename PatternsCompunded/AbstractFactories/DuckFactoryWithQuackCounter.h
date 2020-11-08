#pragma once
#include "IAbstractDuckFactory.h"
class DuckFactoryWithQuackCounter : public IAbstractDuckFactory
{
public:
     DuckFactoryWithQuackCounter() = default;
     IQuackable* createMallardDuck() override;
     IQuackable* createRedHeadDuck() override;
     IQuackable* createDuckCall() override;
     IQuackable* createRubberDuck() override;
};

