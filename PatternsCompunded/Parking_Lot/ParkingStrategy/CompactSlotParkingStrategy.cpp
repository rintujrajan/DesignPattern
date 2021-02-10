#include "CompactSlotParkingStrategy.h"
#include "../Model.h"

#include <iostream>
#include <iomanip>
#include <algorithm>

CompactSlotParkingStrategy::CompactSlotParkingStrategy(/* args */)
{
}

CompactSlotParkingStrategy::~CompactSlotParkingStrategy()
{
}

void CompactSlotParkingStrategy::parkVehicle(int selectedEntrance, bool tryHigherSlotsIfNeeded)
{
    auto selectedSingleSlotHeap = Model::getModelInstance().getSingleSlotHeapByEntrance()[selectedEntrance];
    if (!selectedSingleSlotHeap.empty())
    {
        std::make_heap(selectedSingleSlotHeap.begin(), selectedSingleSlotHeap.end(),
                       [](StructsAndEnums::ParkingSlot &left, StructsAndEnums::ParkingSlot &right) {
                           return (left.floorNo > right.floorNo) ||
                                  ((left.floorNo == right.floorNo) && (left.distanceFromEntrance > right.distanceFromEntrance));
                       });
        auto selParkingSlot = selectedSingleSlotHeap.front();

        std::cout << "Following slot has been reserved:\n";

        std::cout << std::setw(10) << "ID" << std::setw(10) << "Distance"
                  << "\n";
        std::cout << std::setw(10) << selParkingSlot.parkingSlotID
                  << std::setw(10) << selParkingSlot.distanceFromEntrance
                  << "\n";
        removeSlotfromAllEntranceBasedSlotListings(selParkingSlot.parkingSlotID);
    }
    else
    {
        if (tryHigherSlotsIfNeeded)
        {
            std::cout << "No Compact slot found..Looking for a Large slot..\n";
            CompactSlotParkingStrategy compactSlotParkingStrategy;
            compactSlotParkingStrategy.parkVehicle(selectedEntrance);
        }
        else
        {
            std::cout << "Sorry no slots available for parking..\n";
        }
    }
}