//
// Created by Egri Zoltán on 2019. 02. 05..
//

#include "sponsor.h"
Sponsor::Sponsor()
{
    _company = "Google";
}
Sponsor::Sponsor(std::string name, int age, Gender gender, std::string company) :
    Person(name, age, gender)
{
    _company = company;
}
void Sponsor::getGoal()
{
    std::cout << "My goal is: Hire brilliant junior software developers." << std::endl;
}
void Sponsor::introduce()
{
    std::cout << "Hi, I'm " << _name << ", a " << _age << " year old "
    << genderToString(_gender) << " who represents " << _company
    << " and hired " << _hiredStudents << " students so far." << std::endl;
}
void Sponsor::hire()
{
    _hiredStudents++;
}

