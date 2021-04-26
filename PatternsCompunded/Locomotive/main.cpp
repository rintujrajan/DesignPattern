#include <iostream>
#include <thread>
#include <algorithm>
#include <vector>

#include "Subjects\SpeedMonitor.h"
#include "Subjects\GeoPosMonitor.h"

#include "Observers\DataUploader.h"
#include "Observers\Speaker.h"

#include "Sensors\SpeedSensor.h"
#include "Sensors\GPSSensor.h"

#include "Controller.h"

int main()
{

    std::thread threadToExecuteCommands([]() { Controller::getControllerInstance().executeQueuedCommands(); });

    std::vector<int> speeds = {0, 1, 2, 3, 4, 5};

    // We have used shared_ptr instead of unique_ptr since the pointer is shared by various classes
    // If we use a unique_ptr and then move it, we will get segfault at next usage

    // We create share pointers to both of our concrete subjects
    // notice that there is object slicing and concrete subjects are used
    std::shared_ptr<SpeedMonitor>
        speedMonitor = std::make_shared<SpeedMonitor>();
    std::shared_ptr<GeoPosMonitor> geoPosMonitor = std::make_shared<GeoPosMonitor>();

    // We create shared pointer for the DataUploader observer and then register it to the two concrete subjects
    std::shared_ptr<IObserver> dataUploader = std::make_shared<DataUploader>();
    speedMonitor->registerObserver(dataUploader);
    geoPosMonitor->registerObserver(dataUploader);

    // We create shared pointer for the Speaker observer and then register it to the concrete subject - SpeedMonitor
    std::shared_ptr<IObserver> speaker = std::make_shared<Speaker>();
    speedMonitor->registerObserver(speaker);

    // We here try to simulate a speed sensor updating speed data which would trigger to the Subject-SpeedMonitor to notify it's observers
    SpeedSensor speedSensor(speedMonitor);
    for (auto speed : speeds)
    {
        speedSensor.speedChangedTo(speed); //this can be some external api call as well
    }
    std::this_thread::sleep_for(std::chrono::seconds(3));

    // We here try to simulate a GPS sensor updating GPS data which would trigger to the Subject-GeoPosMonitor to notify it's observers
    GPSSensor gpsSensor(geoPosMonitor);
    gpsSensor.geoPositionChangedTo(200, 500); //this can be some external api call as well
    auto incSpeedByFives = [](int &speed) { return speed + 5; };
    std::transform(speeds.begin(), speeds.end(), speeds.begin(), incSpeedByFives);
    for (auto speed : speeds)
    {
        speedSensor.speedChangedTo(speed); //this can be some external api call as well
    }
    std::this_thread::sleep_for(std::chrono::seconds(3));

    // We now remove the DataUploader Observer from observing the SpeedMonitor Subject. When speed changes only the Speaker subject would be notified
    // speedMonitor->removeObserver(dataUploader);
    std::transform(speeds.begin(), speeds.end(), speeds.begin(), incSpeedByFives);
    for (auto speed : speeds)
    {
        speedSensor.speedChangedTo(speed); //this can be some external api call as well
    }
    std::this_thread::sleep_for(std::chrono::seconds(3));
    Controller::getControllerInstance().stopLoop();
    threadToExecuteCommands.join();
    std::cin.get();
}