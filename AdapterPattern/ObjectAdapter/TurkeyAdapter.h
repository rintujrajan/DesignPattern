#pragma once
#include "IDuck.h"
#include "ITurkey.h"
class TurkeyAdapter : public IDuck
{
    ITurkey* turkey;
public:
    TurkeyAdapter(ITurkey* turkey);
    ~TurkeyAdapter();
    virtual void fly();
    virtual void quack();
};
