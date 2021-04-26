#include "SpeedMonitor.h"
#include "../Observers/IObserver.h"

void SpeedMonitor::speedChangedTo(int speed)
{
    curSpeed = speed;
    notifyEachObserver();
}

void SpeedMonitor::notifyEachObserver()
{
    for (auto &&observer : observersSet)
    {
        // each observer is notified from the concrete subjects, so that the "this" pointer of the concrete subjects can be passed
        observer->notify(this);
    }
}