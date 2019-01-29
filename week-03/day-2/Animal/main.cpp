#include <iostream>

class Animal {
private:
    int hunger;
    int thirst;
public:
    Animal() {
        hunger = 50;
        thirst = 50;
    }

    void eat() {
        hunger--;
    }

    void drink() {
        thirst--;
    }

    void play() {
        hunger++;
        thirst++;
    }
};


int main() {
    Animal dog;
    dog.eat();
    dog.drink();
    dog.play();
    return 0;
}