#pragma once
#include "Duck.h"
class ARealDuck :
	public Duck
{
public:
	ARealDuck();
	void identifyDuck() override;
};

