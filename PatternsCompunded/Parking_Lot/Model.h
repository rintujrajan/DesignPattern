#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include <queue>
#include "Parking.h"
struct ParkingAvailableByFloor
{
    int single;
    int compact;
    int large;
};

class Model
{
private:
    std::vector<ParkingAvailableByFloor> parkingAvailable;
    std::vector<std::vector<StructsAndEnums::ParkingSlot>> singleSlotHeapByEntrance;
    static Model modelInstance;
    int totalEntrances;

private:
    Model(/* args */);
    ~Model();

public:
    static Model &getModelInstance();

    Model(const Model &) = delete;
    Model &operator=(const Model &) = delete;
    Model(Model &&) = delete;
    Model &operator=(Model &&) = delete;

    void setTotalEntrances(int entrances);
    inline int getTotalEntrances() { return totalEntrances; }
    void addAParkingSlot(StructsAndEnums::ParkingSlot parkingSlot, std::vector<int> distanceFromEntrances);
    std::vector<std::vector<StructsAndEnums::ParkingSlot>>
    getSingleSlotHeapByEntrance();
    void setSingleSlotHeapByEntrance(std::vector<std::vector<StructsAndEnums::ParkingSlot>> singleSlotHeapByEntrance);
};
#endif