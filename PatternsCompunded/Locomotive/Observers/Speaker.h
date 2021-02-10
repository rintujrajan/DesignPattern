#pragma once

#include "IObserver.h"
#include <memory>
class SpeedMonitor;
class Speaker : public IObserver
{
private:
    SpeedMonitor *localSpeedMonitor; //should not be delted. It only contains pointer to the smart pointer and no new memory is allocated

public:
    Speaker() = delete; //so that only the parameterized constructor can be called
    Speaker(SpeedMonitor *speedMonitor);
    ~Speaker();
    void notify(Subject *subject) override;
};
