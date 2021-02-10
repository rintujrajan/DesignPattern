#include "SpeedMonitor.h"
#include "../Observers/IObserver.h"

void SpeedMonitor::speedChangedTo(int speed)
{
    curSpeed = speed;
    notifyAllObservers();
}

void SpeedMonitor::notifyEachObserver(const std::shared_ptr<IObserver> &observer)
{
    observer->notify(this);
}