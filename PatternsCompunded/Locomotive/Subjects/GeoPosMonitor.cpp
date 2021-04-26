#include "GeoPosMonitor.h"
#include "../Observers/IObserver.h"

void GeoPosMonitor::geoPositionChangeTo(long latitude, long longitude)
{
    curLatitude = latitude;
    curLongitude = longitude;
    notifyEachObserver();
}

void GeoPosMonitor::notifyEachObserver()
{
    for (auto &&observer : observersSet)
    {
        // each observer is notified from the concrete subjects, so that the "this" pointer of the concrete subjects can be passed
        observer->notify(this);
    }
}