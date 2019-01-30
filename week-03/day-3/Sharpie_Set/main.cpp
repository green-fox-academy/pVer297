#include <iostream>
#include <vector>
#include "sharpie.h"
#include "sharpie_set.h"

int main()
{
    std::vector<Sharpie> sharpies = {Sharpie("Red", 1),
                                     Sharpie("Orange", 0.8),
                                     Sharpie("Yellow", 3),
                                     Sharpie("Green", 0.5),
                                     Sharpie("Cyan", 1.5),
                                     Sharpie("Blue", 0.3),
                                     Sharpie("Purple", 0.5)};

    SharpieSet rainbowSharpies(&sharpies);

    std::cout << "There is " << rainbowSharpies.countUsable() << " usable sharpies in the set" << std::endl;

    while (!sharpies[4].isEmpty()) {
        sharpies[4].use();
    }

    sharpies[4].use();

    while (!sharpies[0].isEmpty()) {
        sharpies[0].use();
    }

    std::cout << "There is " << rainbowSharpies.countUsable() << " usable sharpies in the set" << std::endl;
    std::cout << rainbowSharpies.removeTrash() << std::endl;

    return 0;
}