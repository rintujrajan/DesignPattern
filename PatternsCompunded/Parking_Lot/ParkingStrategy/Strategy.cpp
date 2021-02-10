#include "Strategy.h"
#include "../Model.h"
#include <algorithm>

void Strategy::removeSlotfromAllEntranceBasedSlotListings(std::string slotID)
{
    auto parkingSlotHeapsByEntrance = Model::getModelInstance().getSingleSlotHeapByEntrance();
    for (auto &parkingSlotList : parkingSlotHeapsByEntrance)
    {
        std::remove_if(parkingSlotList.begin(), parkingSlotList.end(),
                       [&slotID](StructsAndEnums::ParkingSlot &slot) { return slot.parkingSlotID == slotID; });
        parkingSlotList.pop_back();
    }
    Model::getModelInstance().setSingleSlotHeapByEntrance(parkingSlotHeapsByEntrance);
}