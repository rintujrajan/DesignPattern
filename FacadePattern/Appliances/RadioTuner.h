#pragma once
#include <string>

class RadioTuner
{
    enum class Tuner
    {
        AM,
        FM,
        ON_STANDBY,
        OFF
    };
    Tuner tuner;
    float frequency;
public:
    RadioTuner();
    void setAM();
    void setFM();
    void on();
    void off();
    void setFrequency(float frequency);
    friend std::ostream& operator<<(std::ostream& out,const RadioTuner& RadioTuner);
};
