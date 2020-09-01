#include "Stereo.h"
#include <ostream>

Stereo::Stereo():player(Player::OFF)
{
}

Stereo::Stereo(const std::string &name):name(name), player(Player::OFF)
{
}
void Stereo::playCD()
{
    player = Player::CD;
}
void Stereo::playDVD()
{
    player = Player::DVD;
}
void Stereo::playRadio()
{
    player = Player::RADIO;
}
void Stereo::off()
{
    player = Player::OFF;
}
std::ostream& operator<<(std::ostream& out,const Stereo& stereo)
{
    switch (stereo.player)
    {
        case Stereo::Player::OFF:
            out<<"Stereo is off\n";
            break;
        case Stereo::Player::CD:
            out<<"Stereo CD Player is playing\n";
            break;
        case Stereo::Player::DVD:
            out<<"Stereo DVD Player is playing\n";
            break;
        case Stereo::Player::RADIO:
            out<<"Stereo Radio Player is playing\n";
            break;
        default:
            break;
    }
    return out;
}
