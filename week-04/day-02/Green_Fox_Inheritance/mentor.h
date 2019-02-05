//
// Created by Egri Zoltán on 2019. 02. 05..
//

#ifndef GREEN_FOX_INHERITANCE_MENTOR_H
#define GREEN_FOX_INHERITANCE_MENTOR_H

#include "person.h"

enum Level {
    JUNIOR,
    INTERMEDIATE,
    SENIOR
};
class Mentor : public Person
{
 private:
    Level _level;

 public:
    Mentor();
    Mentor(std::string name, int age, Gender gender, Level level);

    void getGoal() override;
    void introduce() override;
    std::string levelToString(Level level);
};

#endif //GREEN_FOX_INHERITANCE_MENTOR_H
