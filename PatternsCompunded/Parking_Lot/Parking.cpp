#include "Parking.h"
#include <iostream>
#include <iomanip>
#include "Model.h"

Parking::Parking() //: curStrategy(nullptr)
{
}

Parking::~Parking()
{
}

void Parking::printParkingLotState()
{
    std::cout << "Parking-Lot slot availability status:\n";
    std::right;
    auto parkingSlotHeapsByEntrance = Model::getModelInstance().getSingleSlotHeapByEntrance();
    for (int i = 0; i < parkingSlotHeapsByEntrance.size(); ++i)
    {
        std::cout << "For Entrance No. " << i + 1 << "\n";
        std::cout << std::setw(10) << "ID" << std::setw(10) << "Distance"
                  << "\n";
        for (int dash = 0; dash < 38; dash++)
        {
            std::cout << "-";
        }
        std::cout << "\n";
        for (auto curParkingSlotByEntrance : parkingSlotHeapsByEntrance[i])
        {
            std::cout << std::setw(10) << curParkingSlotByEntrance.parkingSlotID
                      << std::setw(10) << curParkingSlotByEntrance.distanceFromEntrance
                      //   << std::setw(10) <<  curParkingSlot.floorNo
                      //   << std::setw(10) << curParkingSlot.slotType;
                      << "\n";
        }
    }
    std::cout << "\n";
}

void Parking::parkVehicleWithStrategy(std::unique_ptr<Strategy> usedStrategy, int selectedEntrance)
{
    usedStrategy->parkVehicle(selectedEntrance);
}

// std::ostream &operator<<(std::ostream &out, const StructsAndEnums::Slot &slotType)
// {
//     switch (slotType)
//     {
//     case StructsAndEnums::Slot::SINGLE:
//         out << "Single";
//         break;
//     case StructsAndEnums::Slot::COMPACT:
//         out << "Compact";
//         break;
//     case StructsAndEnums::Slot::LARGE:
//         out << "Large";
//         break;
//     }
//     return out;
// }

// std::ostream &operator<<(std::ostream &out, const StructsAndEnums::Floor &floorLevel)
// {
//     switch (floorLevel)
//     {
//     case StructsAndEnums::Floor::GROUND_FLOOR:
//         out << "Ground";
//         break;
//     case StructsAndEnums::Floor::FIRST_FLOOR:
//         out << "First";
//         break;
//     case StructsAndEnums::Floor::SECOND_FLOOR:
//         out << "Second";
//         break;
//     }
//     return out;
// }
