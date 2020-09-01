#pragma once
#include <string>

class Light
{
    std::string name;
public:
    Light() = default;
    Light(const std::string &name);
    void on();
    void off();
    inline std::string getname()
    {
        return name;
    }
};
