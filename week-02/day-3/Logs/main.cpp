#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

// Read all data from 'log.txt'.
// Each line represents a log message from a web server
// Write a function that returns an array with the unique IP adresses.
// Write a function that returns the GET / POST request ratio.


double getPostRatio(std::vector<std::string> status) {
    double numOfGets = 0;
    for(int i = 0;i<status.size();i++){
        if(status[i] == "GET"){
            numOfGets++;
        }
    }
    return numOfGets/(status.size()-numOfGets);
}

std::vector<std::string> pushIfUnique(std::string input, std::vector<std::string> list) {
    bool hasValue = false;
    for (int i = 0; i < list.size(); i++) {
        if (input == list.at(i)) {
            hasValue = true;
        }
    }
    if (!hasValue) {
        list.push_back(input);
    }

    return list;
}

int main() {
    std::ifstream log("log.txt");
    std::string readLine;

    std::vector<std::string> ipAddress;
    std::vector<std::string> status; //get/post

    while (std::getline(log, readLine)) {
        std::istringstream stream(readLine);
        std::string token;
        int index = 1;
        while (std::getline(stream, token, ' ')) {
            if (index == 9) { //IP number column
                //std::cout << token << std::endl;
                ipAddress = pushIfUnique(token, ipAddress);
            }
            if (index == 12) { //GET/POST column
                status.push_back(token);
            }
            index++;
        }
    }
    std::cout << "There is " << getPostRatio(status) << " times more POST than GET" << std::endl;
    std::cout << "There is " << ipAddress.size() << " unique IP Address" << std::endl;
    std::cout << std::endl << std::endl;

    for (int i = 0; i < ipAddress.size(); i++) {
        std::cout << ipAddress.at(i) << std::endl;
    }


    return 0;
}