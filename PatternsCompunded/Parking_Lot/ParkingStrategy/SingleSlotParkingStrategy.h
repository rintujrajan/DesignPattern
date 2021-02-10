#pragma once
#include "Strategy.h"
class SingleSlotParkingStrategy : public Strategy
{
private:
    /* data */
public:
    SingleSlotParkingStrategy(/* args */);
    ~SingleSlotParkingStrategy();
    void parkVehicle(int selectedEntrance, bool tryHigherSlotsIfNeeded) override;
};
