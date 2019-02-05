//
// Created by Egri Zoltán on 2019. 02. 05..
//

#ifndef GREEN_FOX_INHERITANCE_STUDENT_H
#define GREEN_FOX_INHERITANCE_STUDENT_H

#include "person.h"

class Student : public Person
{
 private:
    std::string _previousOrganization;
    int _skippedDays = 0;

 public:
    Student();
    Student(std::string name, int age, Gender gender, std::string previousOrganization);

    void getGoal() override;
    void introduce() override;
    void skipDays(int numberOfDays);
};

#endif //GREEN_FOX_INHERITANCE_STUDENT_H
