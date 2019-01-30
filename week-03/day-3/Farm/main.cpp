#include <iostream>
#include <vector>
#include <ctime>
#include "Animal.h"
#include "Farm.h"

int random(int startValue, int endValue)
{
    return (rand() % (endValue - startValue + 1)) + startValue;
}

int main()
{
    srand(time(nullptr));
    int randomAnimals = random(50, 200),
        randomFarmSize = random(200, 300),
        randomBreed = random(5, 50),
        randomSlaughter = random(10, 30);
    //randomising stuff, no boring things here

    std::vector<Animal> animals;

    for (int i = 0; i < randomAnimals; i++) {
        animals.push_back(Animal());
    }
    Farm farm(randomFarmSize, &animals);

    std::cout << "You got a farm with " << farm.getNumberOfAnimals() << " animals" << std::endl;

    for (int i = 0; i < randomBreed; i++) {
        farm.breed();
    }

    for (int i = 0; i < 1000; i++) {
        bool feed = random(0, 1);
        if (feed) {
            animals[random(0, animals.size())].eat();
        } else {
            animals[random(0, animals.size())].play();
        }
    }

    for (int i = 0; i < randomSlaughter; i++) {
        farm.slaughter();
    }

    return 0;
}