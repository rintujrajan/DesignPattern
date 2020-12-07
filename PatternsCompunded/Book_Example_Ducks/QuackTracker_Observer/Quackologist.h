#pragma once
#include "IObserver.h"

class Quackologist : public IObserver
{
public:
    void update(IQuackable* duckSubject) override;
};
