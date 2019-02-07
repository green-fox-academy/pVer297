//
// Created by Egri Zoltán on 2019. 02. 07..
//

#include "apple.h"
std::string getApple()
{
    return "apple";
}

int sum(std::vector<int> listOfInts)
{
    int sum = 0;
    for(int num : listOfInts){
        sum += num;
    }
    return sum;
}
