#pragma once
#include "IDuck.h"
class MallardDuck : public IDuck
{
public:
    virtual void fly();
    virtual void quack();
};
