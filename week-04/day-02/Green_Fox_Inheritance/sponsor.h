//
// Created by Egri Zoltán on 2019. 02. 05..
//

#ifndef GREEN_FOX_INHERITANCE_SPONSOR_H
#define GREEN_FOX_INHERITANCE_SPONSOR_H

#include "person.h"

class Sponsor : public Person
{
 private:
    std::string _company;
    int _hiredStudents = 0;

 public:
    Sponsor();
    Sponsor(std::string name, int age, Gender gender, std::string company);

    void getGoal() override;
    void introduce() override;
    void hire();
};

#endif //GREEN_FOX_INHERITANCE_SPONSOR_H
