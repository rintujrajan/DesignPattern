#pragma once
#include "IPizza.h"
class CheezePizza :
	public IPizza
{
	void prepare() override;
	void bake() override;
	void cut() override;
	void box() override;
};

