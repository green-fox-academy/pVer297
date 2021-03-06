//
// Created by Egri Zoltán on 2019. 02. 05..
//

#include "mentor.h"
Mentor::Mentor()
{
    _level = Level::INTERMEDIATE;
}
Mentor::Mentor(std::string name, int age, Gender gender, Level level) :
    Person(name, age, gender)
{
    _level = level;
}
void Mentor::getGoal()
{
    std::cout << "My goal is: Educate brilliant junior software developers." << std::endl;
}
void Mentor::introduce()
{
    std::cout << "Hi, I'm " << _name << ", a " << _age << " year old "
              << genderToString(_gender) << " " << levelToString(_level)
              << " mentor." << std::endl;
}
std::string Mentor::levelToString(Level level)
{
    switch (level) {
        case Level::JUNIOR: return "junior";
        case Level::INTERMEDIATE: return "intermediate";
        case Level::SENIOR: return "senior";
        default: return "not a";
    }
}
