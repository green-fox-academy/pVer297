//
// Created by Egri Zoltán on 2019. 02. 26..
//

#include "stringFunctions.h"

char* toLower(char* string)
{
    int index = 0;
    while (string[index]) {
        if (isBetween(string[index], 65, 90))
            string[index] += 32;
        index++;
    }
    return string;
}

int isBetween(int value, int start, int end)
{ //inclusive
    if (value >= start && value <= end)
        return 1;
    return 0;
}