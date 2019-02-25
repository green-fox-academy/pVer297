#include <stdio.h>

int main()
{
    // Write a program that stores 3 sides of a cuboid as variables (doubles)
    // You should get these variables via console input
    // The program should write the surface area and volume of the cuboid like:
    //
    // Surface Area: 600
    // Volume: 1000

    double length = 50.;
    double width = 27.5;
    double height = 33.3;

    double totalSurfaceArea = 2 * ((length * width) + (width * height) + (height * length));
    double volume = length * width * height;
    printf("Surface Area: %.1f\n", totalSurfaceArea);
    printf("Volume: %.1f\n", volume);

    return 0;
}