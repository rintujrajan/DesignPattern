#pragma once
#include "IFlyBehavior.h"
class NoWingsToFly :
	public IFlyBehavior
{
public:
	void fly() override;
};

