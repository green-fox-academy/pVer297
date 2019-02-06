//
// Created by Egri Zoltán on 2019. 02. 06..
//

#include "animal.h"
std::string Animal::genderToString(Gender gender)
{
    switch(gender){
        case Gender::MALE: return "male";
        case Gender::FEMALE: return "female";
        default: return "other";
    }
}
