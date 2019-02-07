#include "project.h"
std::map<char, int> countLetters(std::string input)
{
    std::map<char, int> characters;
    for (char c : input) {
        if(characters.find(c) == characters.end()){
            characters.insert(std::make_pair(c, 1));
        } else {
            characters.at(c) += 1;
        }
    }
    return characters;
}
