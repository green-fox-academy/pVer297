#include <iostream>

int main(int argc, char* args[]) {

    int currentHours = 14;
    int currentMinutes = 34;
    int currentSeconds = 42;

    // Write a program that prints the remaining seconds (as an integer) from a
    // day if the current time is represented by the variables

    int remainingHours = 24-currentHours;
    int remainingMinutes = 60-currentMinutes;
    int remainingSeconds = 60-currentSeconds;

    int secondsLeft = (remainingHours*3600)+(remainingMinutes*60)+remainingSeconds;

    std::cout << "Seconds left from the day: " << secondsLeft << std::endl;

    return 0;
}