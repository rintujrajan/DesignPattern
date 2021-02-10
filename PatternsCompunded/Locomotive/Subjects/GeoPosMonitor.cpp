#include "GeoPosMonitor.h"
#include "../Observers/IObserver.h"

void GeoPosMonitor::geoPositionChangeTo(long latitude, long longitude)
{
    curLatitude = latitude;
    curLongitude = longitude;
    notifyAllObservers();
}

void GeoPosMonitor::notifyEachObserver(const std::shared_ptr<IObserver> &observer)
{
    observer->notify(this);
}