#pragma once
#include <string>

class Stereo
{
    std::string name;
    enum class Player
    {
        CD,
        DVD,
        RADIO,
        OFF
    };
    Player player;
public:
    Stereo();
    Stereo(const std::string &name);
    void playCD();
    void playDVD();
    void playRadio();
    void off();
    inline std::string getname()
    {
        return name;
    }
    friend std::ostream& operator<<(std::ostream& out,const Stereo& stereo);
};
