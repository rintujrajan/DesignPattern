#include "Speaker.h"
#include <iostream>
#include "../Subjects/SpeedMonitor.h"

Speaker::Speaker(SpeedMonitor *speedMonitor)
    : localSpeedMonitor(speedMonitor)
{
}

Speaker::~Speaker()
{
}

void Speaker::notify(Subject *subject)
{
    if (subject == localSpeedMonitor) //we match the pointer. we cannot use it to get the concrete subjects data
    {
        std::cout << "Speaker::update - new speed :" << localSpeedMonitor->getCurrentSpeed() << "\n";
    }
}