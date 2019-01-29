#include <iostream>

#include "fleet.h"

int main(int argc, char* args[])
{
    Fleet fleet;
    // Create a fleet of things to have this output:
    // 1. [ ] Get milk
    // 2. [ ] Remove the obstacles
    // 3. [x] Stand up
    // 4. [x] Eat lunch

    Thing getMilk("Get milk");
    Thing removeObs("Remove the obstacles");
    Thing standUp("Stand up");
    Thing eatLunch("Eat lunch");

    standUp.complete();
    eatLunch.complete();

    fleet.add(getMilk);
    fleet.add(removeObs);
    fleet.add(standUp);
    fleet.add(eatLunch);

    std::cout << fleet.toString() << std::endl;
    return 0;
}