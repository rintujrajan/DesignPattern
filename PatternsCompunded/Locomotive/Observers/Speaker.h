#pragma once

#include "IObserver.h"
#include <memory>
class SpeedMonitor;
class Speaker : public IObserver
{
public:
    void notify(Subject *subject) override;
};
