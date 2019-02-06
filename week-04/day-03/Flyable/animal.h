//
// Created by Egri Zoltán on 2019. 02. 06..
//

#ifndef ZOO_ANIMAL_H
#define ZOO_ANIMAL_H

#include <iostream>

enum Gender{
    MALE,
    FEMALE
};

class Animal
{
 protected:
    std::string _name;
    int _age;
    Gender _gender;
    int _numberOfLimbs;
 public:
    virtual std::string getName() = 0;
    virtual std::string breed() = 0;
    std::string genderToString(Gender gender);

};

#endif //ZOO_ANIMAL_H
