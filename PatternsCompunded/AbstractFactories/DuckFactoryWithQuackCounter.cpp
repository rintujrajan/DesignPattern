#include "DuckFactoryWithQuackCounter.h"

#include "..\Ducks\MallardDuck.h"
#include "..\Ducks\RedheadDuck.h"
#include "..\Ducks\DuckCall.h"
#include "..\Ducks\RubberDuck.h"
#include "..\Decorator\DuckWithQuackCounter.h"

IQuackable* DuckFactoryWithQuackCounter::createMallardDuck() 
{
    return new DuckWithQuackCounter(new  MallardDuck());
}

IQuackable* DuckFactoryWithQuackCounter::createRedHeadDuck() 
{
    return new DuckWithQuackCounter(new  RedheadDuck());
}

IQuackable* DuckFactoryWithQuackCounter::createDuckCall() 
{
    return new  DuckCall();
}

IQuackable* DuckFactoryWithQuackCounter::createRubberDuck() 
{
    return new  RubberDuck();
}