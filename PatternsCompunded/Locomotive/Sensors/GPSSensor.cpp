#include "GPSSensor.h"
#include "../Subjects/GeoPosMonitor.h"

GPSSensor::GPSSensor(std::shared_ptr<GeoPosMonitor> geoPosMonitorPtr)
    : localGeoPosMonitorPtr(geoPosMonitorPtr)
{
}

GPSSensor::~GPSSensor()
{
}

void GPSSensor::geoPositionChangedTo(long latitude, long longitude)
{
    localGeoPosMonitorPtr->geoPositionChangeTo(latitude, longitude);
}