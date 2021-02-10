#include "SpeedSensor.h"
#include "../Subjects/SpeedMonitor.h"

SpeedSensor::SpeedSensor(std::shared_ptr<SpeedMonitor> speedMonitorPtr)
    : localSpeedMonitorPtr(speedMonitorPtr)
{
}

SpeedSensor::~SpeedSensor()
{
}

void SpeedSensor::speedChangedTo(int speed)
{
    localSpeedMonitorPtr->speedChangedTo(speed);
}