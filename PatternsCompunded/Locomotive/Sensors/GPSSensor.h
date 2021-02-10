#pragma once

#include <memory>
class Subject;
class GeoPosMonitor;

class GPSSensor
{
private:
    std::shared_ptr<GeoPosMonitor> localGeoPosMonitorPtr;

public:
    GPSSensor(std::shared_ptr<GeoPosMonitor> geoPosMonitorPtr);
    ~GPSSensor();
    void geoPositionChangedTo(long latitude, long longitude);
};
