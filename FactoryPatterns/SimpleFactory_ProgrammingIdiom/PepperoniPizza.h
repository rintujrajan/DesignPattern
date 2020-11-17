#pragma once
#include "IPizza.h"
class PepperoniPizza :
	public IPizza
{
	void prepare() override;
	void bake() override;
	void cut() override;
	void box() override;
};

