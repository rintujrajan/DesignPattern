#include "Controller.h"
#include "Parking.h"
#include "Model.h"
#include "ParkingStrategy\SingleSlotParkingStrategy.h"

#include <iostream>

Controller::Controller(/* args */)
{
    parking = new Parking();
    init();
}

Controller::~Controller()
{
}

void Controller::init()
{
    initModelData();
    parking->printParkingLotState();
}

void Controller::initModelData()
{
    Model::getModelInstance().setTotalEntrances(2);

    int GROUND_FLOOR = 0;
    int FIRST_FLOOR = 1;
    int SECOND_FLOOR = 2;

    using namespace StructsAndEnums;
    Model::getModelInstance().addAParkingSlot(ParkingSlot{0, "000", Slot::SINGLE, GROUND_FLOOR}, std::vector<int>{1, 3});
    // Model::getModelInstance().addAParkingSlot(ParkingSlot{0, "001", Slot::SINGLE, GROUND_FLOOR}, std::vector<int>{2, 2});
    // Model::getModelInstance().addAParkingSlot(ParkingSlot{0, "002", Slot::SINGLE, GROUND_FLOOR}, std::vector<int>{3, 1});

    // Model::getModelInstance().addAParkingSlot(ParkingSlot{0, "100", Slot::SINGLE, FIRST_FLOOR}, std::vector<int>{1, 3});
    // Model::getModelInstance().addAParkingSlot(ParkingSlot{0, "101", Slot::SINGLE, FIRST_FLOOR}, std::vector<int>{2, 2});
    // Model::getModelInstance().addAParkingSlot(ParkingSlot{0, "102", Slot::SINGLE, FIRST_FLOOR}, std::vector<int>{3, 1});

    // Model::getModelInstance().addAParkingSlot(ParkingSlot{0, "200", Slot::SINGLE, SECOND_FLOOR}, std::vector<int>{1, 3});
    // Model::getModelInstance().addAParkingSlot(ParkingSlot{0, "201", Slot::SINGLE, SECOND_FLOOR}, std::vector<int>{2, 2});
    // Model::getModelInstance().addAParkingSlot(ParkingSlot{0, "202", Slot::SINGLE, SECOND_FLOOR}, std::vector<int>{3, 1});
}

void Controller::startApplication()
{
    int input = -1;
    int selectedEntrance = -1;
    while (input != 0)
    {
        std::cout << "You are coming in from entrance\n";
        char entranceChar = 'A';
        for (int i = 1; i <= Model::getModelInstance().getTotalEntrances(); ++i)
        {
            std::cout << "\t" << i << ". Entrance " << static_cast<char>(64 + i) << "\n";
        }
        std::cout << "   **Press 0 to exit\n";
        std::cout << "Entrance selected : ";
        std::cin >> input;
        if (input == 0)
        {
            std::cout << "Exiting..";
            continue;
        }
        selectedEntrance = input - 1;
        std::cout << "Which type of vehicle would you like to park\n"
                  << "\t1. MotorBike\n"
                  << "\t2. Car\n"
                  << "\t3. Bus\n"
                  << "   **Press 4 to see Parking-Lot Status or press 0 to exit\n";
        std::cout << "Your choice please:";
        std::cin >> input;
        switch (input)
        {
        case 1:
        {
            parking->parkVehicleWithStrategy(std::move(std::make_unique<SingleSlotParkingStrategy>()),
                                             selectedEntrance);
        }
        break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            parking->printParkingLotState();
            break;
        case 0:
            std::cout << "Exiting..";
            break;
        }
        std::cout << "**********************\n";
    }
}