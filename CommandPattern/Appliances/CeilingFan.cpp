#include "CeilingFan.h"
#include <ostream>

CeilingFan::CeilingFan(const std::string &name):name(name), speed(Speed::OFF)
{
}
void CeilingFan::high()
{
    speed = Speed::HIGH;
}
void CeilingFan::medium()
{
    speed = Speed::MEDIUM;
}
void CeilingFan::low()
{
    speed = Speed::LOW;
}
void CeilingFan::off()
{
    speed = Speed::OFF;
}
std::ostream& operator<<(std::ostream& out,const CeilingFan& fan)
{
    switch (fan.speed)
    {
        case CeilingFan::Speed::OFF:
            out<< fan.name <<" Ceiling Fan is off\n";
            break;
        case CeilingFan::Speed::HIGH:
            out<< fan.name <<" Ceiling Fan is running at High Speed\n";
            break;
        case CeilingFan::Speed::MEDIUM:
            out<< fan.name <<" Ceiling Fan is running at Medium Speed\n";
            break;
        case CeilingFan::Speed::LOW:
            out<< fan.name <<" Ceiling Fan is running at Low Speed\n";
            break;
        default:
            break;
    }
    return out;
}
