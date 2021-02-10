#pragma once

#include <string>

class Strategy
{
protected:
    void removeSlotfromAllEntranceBasedSlotListings(std::string slotID);

public:
    virtual void parkVehicle(int selectedEntrance, bool tryHigherSlotsIfNeeded = false) = 0;
};
