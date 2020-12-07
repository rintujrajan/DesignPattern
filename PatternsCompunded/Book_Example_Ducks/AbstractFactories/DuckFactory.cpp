#include "DuckFactory.h"

#include "..\Ducks\MallardDuck.h"
#include "..\Ducks\RedheadDuck.h"
#include "..\Ducks\DuckCall.h"
#include "..\Ducks\RubberDuck.h"

IQuackable* DuckFactory::createMallardDuck() 
{
    return new MallardDuck();
};
IQuackable* DuckFactory::createRedHeadDuck() 
{
    return new RedheadDuck();
};
IQuackable* DuckFactory::createDuckCall() 
{
    return new DuckCall();
};
IQuackable* DuckFactory::createRubberDuck() 
{
    return new RubberDuck();
};