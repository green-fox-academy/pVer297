#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> makingMatches(const std::vector<std::string> &girls, const std::vector<std::string> &boys) {
    std::vector<std::string> matchedList;
    int numberOfRuns;
    if(girls.size() > boys.size()){
        numberOfRuns = girls.size();
    } else {
        numberOfRuns = boys.size();
    }

    for (unsigned int i = 0; i < numberOfRuns; i++) {
        if (i < girls.size()) {
            matchedList.push_back(girls[i]);
        }
        if (i < boys.size()) {
            matchedList.push_back(boys[i]);
        }
    }
    return matchedList;
}

int main(int argc, char *args[]) {
    std::vector<std::string> girls = {"Eve", "Ashley", "Claire", "Kat", "Jane"};
    std::vector<std::string> boys = {"Joe", "Fred", "Tom", "Todd", "Neef", "Jeff",};

    // Write a method that joins the two lists by matching one girl with one boy into a new list
    // If someone has no pair, he/she should be the element of the list too
    // Exepected output: "Eve", "Joe", "Ashley", "Fred"...

    std::vector<std::string> matches = makingMatches(girls, boys);

    for (int i = 0; i < matches.size(); ++i) {
        std::cout << matches[i] << " ";
    }

    return 0;
}