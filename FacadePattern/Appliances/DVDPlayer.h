#pragma once
#include <string>

class DVDPlayer
{

public:
    void on();
    void off();
    void eject();
    void pause();
    void play(std::string& movie);
    void stop();
    void setSurroundAudio();
    void setTwoChannelAudio();
};

