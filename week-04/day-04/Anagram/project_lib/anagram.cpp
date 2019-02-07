//
// Created by Egri Zoltán on 2019. 02. 07..
//

#include "anagram.h"

bool isAnagram(std::string word1, std::string word2)
{
    if (word1.size() != word2.size()) {
        return false; //the number of characters does not match
    }
    word1 = sortWord(word1);
    word2 = sortWord(word2);
    return word1 == word2;
}

std::string sortWord(std::string word)
{
    std::sort(word.begin(),word.end());
    return word;
}
