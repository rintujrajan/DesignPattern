#pragma once
#include "Strategy.h"
class CompactSlotParkingStrategy : public Strategy
{
private:
    /* data */
public:
    CompactSlotParkingStrategy(/* args */);
    ~CompactSlotParkingStrategy();
    void parkVehicle(int selectedEntrance, bool tryHigherSlotsIfNeeded = false) override;
};
