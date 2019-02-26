#include <stdio.h>
#include <mem.h>

/*
Create a struct that represents a House
It should store:
 - The address of the house
 - The price in EUR
 - The number of rooms
 - The area of the house in square meters
The market price of the houses is 400 EUR / square meters
Create a function that takes a pointer to a house and decides if it's worth to buy
(if the price is lower than the calculated price from it's area)
Create a function that takes an array of houses (and it's length), and counts the
houses that are worth to buy.
*/

typedef struct
{
    char* address;
    int price;
    int numberOfRooms;
    int area;
} house_t;

int countGoodValue(house_t* houses, int numOfHouses);
void housesInfo(house_t* houses, int numOfHouses);
int hasGoodPrice(house_t* house);

int main()
{
    house_t houses[10] = {{"This street", 52000, 3, 120},
                          {"That street", 10500, 1, 30},
                          {"Another street", 110000, 4, 210},
                          {"Yet another street", 16500, 2, 44},
                          {"Very creative street", 32000, 3, 80},
                          {"Less creative street", 37000, 3, 93},
                          {"Not-a-Street", 11000, 1, 25},
                          {"StreetFighter Street", 22000, 1, 50},
                          {"A66", 100000, 5, 260},
                          {"Streety McStreetface", 75000, 4, 180}};

    housesInfo(houses, sizeof(houses) / sizeof(houses[0]));
    return 0;
}

int hasGoodPrice(house_t* house)
{
    return (house->price <= (house->area * 400));
}

int countGoodValue(house_t* houses, int numOfHouses)
{
    int valueHouses = 0;
    for (int i = 0; i < numOfHouses; i++) {
        if (hasGoodPrice(&houses[i])) {
            valueHouses++;
        }
    }
    return valueHouses;
}

void housesInfo(house_t* houses, int numOfHouses)
{
    puts("Available houses:");
    for (int i = 0; i < numOfHouses; i++) {
        char worthy[25] = "";
        if (hasGoodPrice(&houses[i]))
            strcpy(worthy, " <- Has good value.");
        printf("A house at \'%s\' for %d EUR, %d rooms, %dm2%s\n",
               houses[i].address,
               houses[i].price,
               houses[i].numberOfRooms,
               houses[i].area,
               worthy);
    }

    printf("\nThere is %d houses that are worth to buy\n", countGoodValue(houses, numOfHouses));
}