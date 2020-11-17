#pragma once
#include <iostream>
class IPizza
{
public:
	virtual void prepare() = 0;
	virtual void bake() = 0;
	virtual void cut() = 0;
	virtual void box() = 0;
	void clearOrder()
	{
		std::cout << "Delivered\n\n";
	}
};

