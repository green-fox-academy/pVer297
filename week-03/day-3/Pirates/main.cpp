#include <iostream>
#include <ctime>
#include <vector>
#include "Pirate.h"
#include "Ship.h"

int main()
{
    srand(time(nullptr));
    Pirate pirate = Pirate();
    Pirate pirate2 = Pirate();

    pirate.brawl(pirate2);
    pirate.brawl(pirate2);

    std::cout << std::endl << std::endl; //end of pirate demo ; start of ship demo

    Ship blackPearl("Black Pearl", "Jack Sparrow");
    Ship flyingDutchman("Flying Dutchman", "Davy Jones");

    blackPearl.fillShip();
    flyingDutchman.fillShip();

    blackPearl.info();
    std::cout << std::endl;
    flyingDutchman.info();

    std::cout << std::endl;
    blackPearl.battle(flyingDutchman);
    std::cout << std::endl;

    blackPearl.info();
    std::cout << std::endl;
    flyingDutchman.info();
    return 0;
}