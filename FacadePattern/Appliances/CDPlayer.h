#pragma once
#include <string>

class CDPlayer
{

public:
    void on();
    void off();
    void eject();
    void pause();
    void play(std::string& title);
    void stop();
};

