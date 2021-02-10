#include "DataUploader.h"
#include <iostream>
#include "../Subjects/SpeedMonitor.h"
#include "../Subjects/GeoPosMonitor.h"
#include "../Commands/UploadSpeedCommand.h"
#include "../Controller.h"

DataUploader::DataUploader(SpeedMonitor *speedMonitor, GeoPosMonitor *geoPosMonitor)
    : localSpeedMonitor(speedMonitor), localGeoPosMonitor(geoPosMonitor)
{
}

DataUploader::~DataUploader()
{
}

void DataUploader::notify(Subject *subject)
{
    if (subject == localSpeedMonitor) //we match the pointer. we cannot use it to get the concrete subjects data
    {
        std::cout << "DataUploader::update - new speed :" << localSpeedMonitor->getCurrentSpeed() << "\n";
        std::unique_ptr<UploadSpeedCommand> uploadSpeedCommand = std::make_unique<UploadSpeedCommand>();
        uploadSpeedCommand->setSpeed(localSpeedMonitor->getCurrentSpeed());
        Controller::getControllerInstance().addCommandToBeExecuted(std::move(uploadSpeedCommand));
    }
    else if (subject == localGeoPosMonitor)
    {
        std::cout << "DataUploader::update - "
                  << "new latitude : " << localGeoPosMonitor->getCurrentLatitude() << " ~~ "
                  << "new longitude : " << localGeoPosMonitor->getCurrentLongitude() << "\n";
    }
}