#pragma once
#include "Model.h"
#include "Parking.h"
#include <memory>

class Controller
{
private:
    Parking *parking;

private:
    void init();
    void initModelData();

public:
    Controller(/* args */);
    ~Controller();
    void startApplication();
};
