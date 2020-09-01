#pragma once
#include <string>

class CeilingFan
{
private:
    std::string name;
    enum class Speed{
        HIGH,
        MEDIUM,
        LOW,
        OFF
    };
    Speed speed;
public:
    CeilingFan() = default;
    CeilingFan(const std::string &name);
    void high();
    void medium();
    void low();
    void off();
    friend std::ostream& operator<<(std::ostream& out,const CeilingFan& fan);
    inline std::string getname()
    {
        return name;
    } 
};

