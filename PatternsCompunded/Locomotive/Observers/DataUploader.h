#pragma once

#include "IObserver.h"
#include <memory>
class SpeedMonitor;
class GeoPosMonitor;
class DataUploader : public IObserver
{
private:
    SpeedMonitor *localSpeedMonitor;   //should not be delted. It only contains pointer to the smart pointer and no new memory is allocated
    GeoPosMonitor *localGeoPosMonitor; //should not be delted. It only contains pointer to the smart pointer and no new memory is allocated

public:
    DataUploader() = delete; //so that only the parameterized constructor can be called
    DataUploader(SpeedMonitor *speedMonitor, GeoPosMonitor *geoPosMonitor);
    ~DataUploader();
    void notify(Subject *subject) override;
};
