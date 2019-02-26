#include <stdio.h>

// Write a function that takes a car as an argument and prints all it's stats
// If the car is a Tesla it should not print it's gas level

enum car_type {VOLVO, TOYOTA, LAND_ROVER, TESLA};

typedef struct {
    enum car_type type;
    double km;
    double gas;
} Car;

char* getType(enum car_type type){
    switch(type){
        case VOLVO: return "Volvo";
        case TOYOTA: return "Toyota";
        case LAND_ROVER: return "Land Rover";
        case TESLA: return "Tesla";
    }
}

void printStats(Car car){
    if(car.type != TESLA){
        printf("This is a %s it has %.2fkm in it and has %.2fl in its fuel tank\n",getType(car.type),car.km,car.gas);
    } else {
        printf("This is a %s it has %.2fkm in it. It's an electric, YAY\n",getType(car.type),car.km);
    }
}

int main()
{
    Car volvo = {VOLVO,146200.1,32.7};
    Car tesla = {TESLA,1233.5,0};
    Car toyota = {TOYOTA,298153.0,62};
    Car lrover = {LAND_ROVER,98200.8,32.7};

    printStats(volvo);
    printStats(toyota);
    printStats(lrover);
    printStats(tesla);
    return 0;
}