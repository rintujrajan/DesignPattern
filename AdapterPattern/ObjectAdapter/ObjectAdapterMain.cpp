#include <iostream>
#include "MallardDuck.h"
#include "WildTukey.h"
#include "TurkeyAdapter.h"

void testDuck(IDuck* duck)
{
    duck->fly();
    duck->quack();
}
int main()
{
    IDuck* mallardDuck = new MallardDuck();
    testDuck(mallardDuck);

    ITurkey* wildTurkey = new WildTurkey();
    TurkeyAdapter* wildTurkeyAdapter = new TurkeyAdapter(wildTurkey);
    testDuck(wildTurkeyAdapter);

    std::cin.get();

    delete mallardDuck;
    delete wildTurkey;
    delete wildTurkeyAdapter;
    return 0;
}