#pragma once
#include "IQuackBehavior.h"
class Squeaking :
	public IQuackBehavior
{
public:
	void quack() override;
};

