//
// Created by Egri Zoltán on 2019. 02. 05..
//

#ifndef GREEN_FOX_INHERITANCE_COHORT_H
#define GREEN_FOX_INHERITANCE_COHORT_H

#include <iostream>
#include <vector>
#include "student.h"
#include "mentor.h"

class Cohort
{
 private:
    std::string _name;
    std::vector<Student*> students;
    std::vector<Mentor*> mentors;

 public:
    Cohort(std::string name);

    void addStudent(Student* student);
    void addMentor(Mentor* mentor);
    void info();

};

#endif //GREEN_FOX_INHERITANCE_COHORT_H
