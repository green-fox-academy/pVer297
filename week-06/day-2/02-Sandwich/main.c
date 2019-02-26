#include <stdio.h>
#include <math.h>

/*
Create a sandwich struct
It should store:
 - name
 - price (float)
 - weight (float)
Create a function which takes two parameters and returns the price of your order.
The parameters should be:
 - a sandwich struct
 - and an integer that represents how many sandwiches you want to order
*/

typedef struct
{
    char* name;
    float price;
    float weight;
} Sandwich;

float getPrice(Sandwich sandwich, int count)
{
    return sandwich.price * count;
}
int main()
{
    Sandwich tuna = {"Tuna sandwich", 1.3, 250};
    printf("This is a %s, it costs %.1f$ and has a %.0fg weight\n", tuna.name, tuna.price, tuna.weight);
    printf("Four of this sandwich would cost %.2f$\n", getPrice(tuna, 4));
    return 0;
}