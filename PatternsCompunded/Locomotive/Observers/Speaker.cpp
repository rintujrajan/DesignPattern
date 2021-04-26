#include "Speaker.h"
#include <iostream>
#include "../Subjects/SpeedMonitor.h"

void Speaker::notify(Subject *subject)
{
    SpeedMonitor *speedMonitor = dynamic_cast<SpeedMonitor *>(subject);
    if (speedMonitor)
    {
        std::cout << "Speaker::update - new speed :" << speedMonitor->getCurrentSpeed() << "\n";
    }
}