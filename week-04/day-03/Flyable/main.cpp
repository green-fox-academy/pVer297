#include <iostream>
#include "flyable.h"
#include "animal.h"
#include "vehicle.h"
#include "helicopter.h"
#include "bird.h"

int main()
{
    Bird falcon("Falcon");
    Helicopter helicopter(450,1200);

    falcon.takeOff();
    falcon.fly();
    falcon.land();
    falcon.info();

    helicopter.takeOff();
    helicopter.fly();
    helicopter.land();
    helicopter.info();

    return 0;
}