//
// Created by Egri Zoltán on 2019. 01. 29..
//

#include "sharpie_set.h"

SharpieSet::SharpieSet(std::vector<Sharpie> *sharpies_)
{
    sharpies = sharpies_;
}

int SharpieSet::countUsable()
{
    int count = 0;
    for (int i = 0; i < sharpies->size(); i++) {
        if (!sharpies->at(i).isEmpty()) {
            count++;
        }
    }
    return count;
}

std::string SharpieSet::removeTrash()
{
    std::string removed;
    bool anyRemoved = false;
    removed += "Sharpies removed: ";
    for (int i = 0; i < sharpies->size(); i++) {
        if (sharpies->at(i).isEmpty()) {
            removed += sharpies->at(i).getColor() + ", ";
            sharpies->erase(sharpies->begin() + i);
            anyRemoved = true;
        }
    }
    if (!anyRemoved) {
        return "No sharpies removed";
    } else {
        return removed;
    }
}