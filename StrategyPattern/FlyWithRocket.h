#pragma once
#include "IFlyBehavior.h"
class FlyWithRocket :
	public IFlyBehavior
{
public:
	void fly() override;
};

