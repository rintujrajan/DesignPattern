#pragma once
#include "IQuackBehavior.h"
class RealQuacking :
	public IQuackBehavior
{
public:
	void quack() override;
};

