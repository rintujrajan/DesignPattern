#include "Model.h"
#include <iostream>

Model Model::modelInstance;
Model::Model(/* args */)
{
}

Model &Model::getModelInstance()
{
    return modelInstance;
}

Model::~Model()
{
}

void Model::setTotalEntrances(int entrances)
{
    totalEntrances = entrances;
    for (int looper = 0; looper < entrances; ++looper)
    {
        std::vector<StructsAndEnums::ParkingSlot> parkingSlotEntranceHeap;
        singleSlotHeapByEntrance.push_back(parkingSlotEntranceHeap);
    }
}

void Model::addAParkingSlot(StructsAndEnums::ParkingSlot parkingSlot, std::vector<int> distanceFromEntrances)
{
    if (distanceFromEntrances.size() != totalEntrances)
    {
        std::cout << "Entry rejected. You have given distance of the slot from " << distanceFromEntrances.size()
                  << " while the actual number of entrances available are " << totalEntrances << "\n";
    }
    else
    {
        int looper = 0;
        for (auto parkingSlotHeap : singleSlotHeapByEntrance)
        {
            parkingSlot.distanceFromEntrance = distanceFromEntrances[looper];
            parkingSlotHeap.push_back(parkingSlot);
            singleSlotHeapByEntrance[looper] = parkingSlotHeap;
            looper++;
        }
    }
}

std::vector<std::vector<StructsAndEnums::ParkingSlot>>
Model::getSingleSlotHeapByEntrance()
{
    return singleSlotHeapByEntrance;
}

void Model::setSingleSlotHeapByEntrance(std::vector<std::vector<StructsAndEnums::ParkingSlot>> singleSlotHeapByEntrance)
{
    this->singleSlotHeapByEntrance = singleSlotHeapByEntrance;
}