#pragma once
#include "SauceBase.h"
class MarianaSauce:public SauceBase
{
private:
    virtual std::string getName();
public:
    MarianaSauce();
};

