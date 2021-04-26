#pragma once

#include "IObserver.h"
#include <memory>
class SpeedMonitor;
class GeoPosMonitor;
class DataUploader : public IObserver
{
public:
    void notify(Subject *subject) override;
};
