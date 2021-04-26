#include "DataUploader.h"
#include <iostream>
#include "../Subjects/SpeedMonitor.h"
#include "../Subjects/GeoPosMonitor.h"
#include "../Commands/UploadSpeedCommand.h"
#include "../Controller.h"

void DataUploader::notify(Subject *subject)
{
    SpeedMonitor *speedMonitor = dynamic_cast<SpeedMonitor *>(subject);
    if (speedMonitor)
    {
        std::cout << "DataUploader::update - new speed :" << speedMonitor->getCurrentSpeed() << "\n";
        std::unique_ptr<UploadSpeedCommand> uploadSpeedCommand = std::make_unique<UploadSpeedCommand>();
        uploadSpeedCommand->setSpeed(speedMonitor->getCurrentSpeed());
        Controller::getControllerInstance().addCommandToBeExecuted(std::move(uploadSpeedCommand));
    }

    GeoPosMonitor *geoPosMonitor = dynamic_cast<GeoPosMonitor *>(subject);
    if (geoPosMonitor)
    {
        std::cout << "DataUploader::update - "
                  << "new latitude : " << geoPosMonitor->getCurrentLatitude() << " ~~ "
                  << "new longitude : " << geoPosMonitor->getCurrentLongitude() << "\n";
    }
}