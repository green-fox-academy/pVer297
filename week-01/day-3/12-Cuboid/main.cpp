#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that stores 3 sides of a cuboid as variables (doubles)
    // The program should write the surface area and volume of the cuboid like:
    //
    // Surface Area: 600
    // Volume: 1000

    double length = 50.;
    double width = 27.5;
    double height = 33.3;

    double totalSurfaceArea = 2*((length*width)+(width*height)+(height*length));
    double volume = length*width*height;
    std::cout << "Surface Area: " << totalSurfaceArea << std::endl;
    std::cout << "Volume: " << volume << std::endl;



    return 0;
}