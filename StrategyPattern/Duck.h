#pragma once
#include "IFlyBehavior.h"
#include "IQuackBehavior.h"
class Duck
{
public:
	IFlyBehavior* flyBehavior;
	IQuackBehavior* quackBehavior;

	void performFly();
	void performDuckSound();
	void setFlyBehavior(IFlyBehavior* newFlyBehavior);
	virtual void identifyDuck() = 0;
};

