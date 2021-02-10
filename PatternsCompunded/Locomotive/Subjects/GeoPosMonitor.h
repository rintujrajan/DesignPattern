#pragma once

#include "Subject.h"

class GeoPosMonitor : public Subject
{
private:
    long curLatitude;
    long curLongitude;

public:
    void geoPositionChangeTo(long latitude, long longitude);
    inline long getCurrentLatitude() { return curLatitude; }
    inline long getCurrentLongitude() { return curLongitude; }
    void notifyEachObserver(const std::shared_ptr<IObserver> &observer) override;
};
