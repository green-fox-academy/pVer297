//
// Created by Egri Zoltán on 2019. 02. 05..
//

#ifndef GREEN_FOX_INHERITANCE_PERSON_H
#define GREEN_FOX_INHERITANCE_PERSON_H

#include <iostream>

enum Gender {
    MALE,
    FEMALE
};

class Person
{
 protected:
    std::string _name;
    int _age;
    Gender _gender;

 public:
    Person();
    Person(std::string name, int age, Gender gender);

    virtual void introduce();
    virtual void getGoal();
    std::string genderToString(Gender gender);
};

#endif //GREEN_FOX_INHERITANCE_PERSON_H
