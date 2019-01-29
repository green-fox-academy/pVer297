#include <iostream>
#include "station.h"
#include "car.h"


int main()
{
    Station centralStation(250);

    Car redSedan(5,45);
    Car blueWagon(12,53);
    Car yellowCabrio(3,38);
    Car greyHatchback(8,35);
    Car greenWagon(5,55);

    centralStation.fill(redSedan);
    centralStation.fill(blueWagon);
    centralStation.fill(yellowCabrio);
    centralStation.fill(greyHatchback);
    centralStation.fill(greenWagon);
    return 0;
}