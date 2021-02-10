#pragma once

#include "Subject.h"

class SpeedMonitor : public Subject
{
private:
    int curSpeed;

public:
    void speedChangedTo(int speed);
    inline int getCurrentSpeed() { return curSpeed; }
    void notifyEachObserver(const std::shared_ptr<IObserver> &observer) override;
};
