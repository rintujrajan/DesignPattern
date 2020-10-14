#include "RadioTuner.h"
#include <iostream>

RadioTuner::RadioTuner():tuner(Tuner::OFF){}

void RadioTuner::setAM()
{
    tuner = Tuner::AM;
    std::cout<<"Radio Tuner set to AM band\n";
}
void RadioTuner::setFM()
{
    tuner = Tuner::FM;
    std::cout<<"Radio Tuner set to FM band\n";
}
void RadioTuner::on()
{
    tuner = Tuner::ON_STANDBY;
    std::cout<<"Radio Tuner turned on\n";
}
void RadioTuner::off()
{
    tuner = Tuner::OFF;
    std::cout<<"Radio Tuner turned off\n";
}
void RadioTuner::setFrequency(float frequency)
{
    this->frequency = frequency;
    std::cout<<"Radio Tuner tunning to frequency "<< frequency <<  " \n";
}
std::ostream& operator<<(std::ostream& out,const RadioTuner& RadioTuner)
{
    switch (RadioTuner.tuner)
    {
        case RadioTuner::Tuner::OFF:
            out<<"RadioTuner is off\n";
            break;
        case RadioTuner::Tuner::FM:
            out<<"RadioTuner is playing FM at frequency "<< RadioTuner.frequency <<"\n";
            break;
        case RadioTuner::Tuner::AM:
            out<<"RadioTuner is playing AM at frequency "<< RadioTuner.frequency <<"\n";
            break;
        case RadioTuner::Tuner::ON_STANDBY:
            out<<"RadioTuner is on and put it on standby\n";
            break;
        default:
            break;
    }
    return out;
}
