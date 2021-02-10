#pragma once

#include <memory>
class Subject;
class SpeedMonitor;

class SpeedSensor
{
private:
    std::shared_ptr<SpeedMonitor> localSpeedMonitorPtr;

public:
    SpeedSensor(std::shared_ptr<SpeedMonitor> speedMonitorPtr);
    ~SpeedSensor();
    void speedChangedTo(int speed);
};
