#include <stdio.h>
#include "phoneRegister.h"
#include "fileIO.h"

int main()
{
    char* file = "phones.txt";
    int numOfPhones = countLines(file);
    smartphone_t phones[numOfPhones];

    loadPhones(file, phones, numOfPhones);
    printInfo(phones, numOfPhones);

    printf("\nThe %s is the oldest device in the database\n", getOldestPhone(phones, numOfPhones));
    printf("There are %d phones with BIG(>= 15 cm) screen size\n", getScreenSizeCount(phones, numOfPhones, BIG));
    printf("There are %d phones with SMALL(< 12 cm) screen size\n", getScreenSizeCount(phones, numOfPhones, SMALL));

    generatePriceList("prices.txt", phones, numOfPhones);
    return 0;
}