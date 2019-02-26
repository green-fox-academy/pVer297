//
// Created by Egri Zoltán on 2019. 02. 26..
//

#include "phoneRegister.h"
char* getOldestPhone(smartphone_t* phones, int arraySize)
{
    int currentOldest = 0;
    int indexOfOldest = 0;

    for (int i = 0; i < arraySize; i++) {
        int age = CURRENT_YEAR - phones[i].releaseYear;
        if (age > currentOldest) {
            currentOldest = age;
            indexOfOldest = i;
        }
    }
    return phones[indexOfOldest].name;
}
int getScreenSizeCount(smartphone_t* phones, int arraySize, enum ScreenSize size)
{
    int count = 0;
    for (int i = 0; i < arraySize; i++) {
        if (phones[i].size == size)
            count++;
    }
    return count;
}
int calculatePrice(smartphone_t phone)
{
    int price = 300;

    switch (phone.size) {
        case BIG:price *= 2;
            break;
        case MEDIUM:price += 100;
            break;
        case SMALL:break;
    }

    int age = CURRENT_YEAR - phone.releaseYear;
    int priceLoss = age * 50;
    if (priceLoss > 250)
        priceLoss = 250;

    return (price - priceLoss);
}
enum ScreenSize getSize(int size)
{
    if (size < 12) {
        return SMALL;
    } else if (size >= 12 && size < 15) {
        return MEDIUM;
    } else {
        return BIG;
    }
}

void printInfo(smartphone_t* phones, int arrayLength)
{
    printf("There is %d phones in the list:\n", arrayLength);
    for (int i = 0; i < arrayLength; i++) {
        printf("%d: %s\n\tYear: %d, Size: %s\n",
               i + 1,
               phones[i].name,
               phones[i].releaseYear,
               sizeToString(phones[i].size));
    }
}
char* sizeToString(enum ScreenSize size)
{
    switch (size) {
        case BIG: return "Big";
        case MEDIUM: return "Medium";
        case SMALL: return "Small";
    }
}
