#include <iostream>
#include <ctime>
#include "Pirate.h"

int main()
{
    srand(time(nullptr));
    Pirate pirate = Pirate("Jack Sparrow");
    Pirate pirate2 = Pirate();

    pirate.brawl(pirate2);
    pirate.brawl(pirate2);

    return 0;
}