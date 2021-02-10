#ifndef PARKING_H
#define PARKING_H

#include <ostream>
#include "ParkingStrategy\Strategy.h"
#include <memory>

namespace StructsAndEnums
{
    enum class VehicleType
    {
        MOTORBIKE = 1,
        CAR = 2,
        BUS = 3
    };
    enum class Slot
    {
        SINGLE = 1,
        COMPACT = 2,
        LARGE = 3
    };
    struct ParkingSlot
    {
        int distanceFromEntrance;
        std::string parkingSlotID;
        Slot slotType;
        int floorNo;
    };
} // namespace StructsAndEnums
using namespace StructsAndEnums;
class Parking
{
private:
    std::unique_ptr<Strategy> curStrategy;

public:
    Parking();
    ~Parking();
    void printParkingLotState();
    void parkVehicleWithStrategy(std::unique_ptr<Strategy> usedStrategy, int selectedEntrance);
    // friend std::ostream &operator<<(std::ostream &out, const Slot &slotType);
    // friend std::ostream &operator<<(std::ostream &out, const Floor &floorLevel);
};
#endif
