#include <iostream>

class Sharpie {
private:
    std::string color;
    float width;
    float inkAmmount;

public:
    Sharpie(std::string color_, float width_) {
        color = color_;
        width = width_;
        inkAmmount = 100;
    }

    void use() {
        inkAmmount -= 0.25;
    }

    std::string getColor() {
        return color;
    }

    float getWidth() {
        return width;
    }

    float getInkAmmount() {
        return inkAmmount;
    }

};

int main() {
    Sharpie yellowSharpie("Yellow", 1.5);
    for (int i = 0; i < 20; i++) {
        yellowSharpie.use();
    }

    std::cout << "The color is: " << yellowSharpie.getColor() << std::endl;
    std::cout << "The width is: " << yellowSharpie.getWidth() << std::endl;
    std::cout << "There is " << yellowSharpie.getInkAmmount() << "% ink remaining." << std::endl;
    return 0;
}