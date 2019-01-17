#include <iostream>

bool isAnagram(std::string, std::string);

int main() {
    std::string word1;
    std::string word2;
    std::cout << "Please provide me two words:" << std::endl;
    std::cin >> word1;
    std::cin >> word2;
    if (isAnagram(word1, word2)) {
        std::cout << word1 << " and " << word2 << " are anagrams of each other";
    } else {
        std::cout << word1 << " and " << word2 << " are NOT anagrams of each other";
    }

    system("PAUSE");
    return 0;
}


bool isAnagram(std::string word1, std::string word2) {
    if (word1.size() != word2.size()) {
        return false; //the number of characters does not match
    }
    int matchingLetters = 0;
    for (int i = 0; i < word1.size(); i++) { //letters of word1
        int containsLetter = 0;
        for (int j = 0; j < word2.size(); j++) { //letters of word2
            if(word1[i] == word2[j]){
                containsLetter += 1;
            }
        }
        if(containsLetter >= 0){
            matchingLetters += containsLetter;
        }
    }
    if(matchingLetters == word1.size()){
        return true;
    } else {
        return false;
    }
}