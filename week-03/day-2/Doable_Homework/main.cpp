#include <iostream>
#include <vector>
#include <map>

void fillTreeData(std::map<std::string, std::map<std::string, std::string>> *dataBase);


std::string getTreeData(std::map<std::string, std::map<std::string, std::string>> listToSearch,
                        std::string treeType,
                        std::string dataToGet) {
    return listToSearch.at(treeType).at(dataToGet);
}


int main() {
    std::map<std::string, std::map<std::string, std::string>> trees;
    fillTreeData(&trees);

    std::cout << "What kind of tree are you looking for?" << std::endl;
    std::cout << "Yellow Birch, Red Maple, White Oak, ";
    std::cout << "Black Locust, Balsam Fir" << std::endl;
    std::string treeType;
    getline(std::cin, treeType);

    std::cout << "Which data do you want to see?" << std::endl;
    std::cout << "Leaf Color, Age, Sex" << std::endl;
    std::string data;
    getline(std::cin, data);

    std::cout << data << " for " << treeType << " is " << getTreeData(trees, treeType, data) << std::endl;

    return 0;
}

//key = type                 key = data         value
//std::map<std::string, std::map<std::string,std::string>>
//tree type, leaf color, age, sex
//vector[i].at("type")



void fillTreeData(std::map<std::string, std::map<std::string, std::string>> *dataBase) {
    std::map<std::string, std::string> YellowBirch;
    std::map<std::string, std::string> RedMaple;
    std::map<std::string, std::string> WhiteOak;
    std::map<std::string, std::string> BlackLocust;
    std::map<std::string, std::string> BalsamFir;

    //YellowBirch
    YellowBirch.insert(std::make_pair("Leaf Color", "Dark green"));
    YellowBirch.insert(std::make_pair("Age", "108"));
    YellowBirch.insert(std::make_pair("Sex", "Female"));
    //RedMaple
    RedMaple.insert(std::make_pair("Leaf Color", "Reddish orange"));
    RedMaple.insert(std::make_pair("Age", "67"));
    RedMaple.insert(std::make_pair("Sex", "Female"));
    //WhiteOak
    WhiteOak.insert(std::make_pair("Leaf Color", "Purple"));
    WhiteOak.insert(std::make_pair("Age", "473"));
    WhiteOak.insert(std::make_pair("Sex", "Male"));
    //BlackLocust
    BlackLocust.insert(std::make_pair("Leaf Color", "Dark blue-green"));
    BlackLocust.insert(std::make_pair("Age", "29"));
    BlackLocust.insert(std::make_pair("Sex", "Female"));
    //BalsamFir
    BalsamFir.insert(std::make_pair("Leaf Color", "Evergreen"));
    BalsamFir.insert(std::make_pair("Age", "82"));
    BalsamFir.insert(std::make_pair("Sex", "Male"));

    dataBase->insert(std::make_pair("Yellow Birch", YellowBirch));
    dataBase->insert(std::make_pair("Red Maple", RedMaple));
    dataBase->insert(std::make_pair("White Oak", WhiteOak));
    dataBase->insert(std::make_pair("Black Locust", BlackLocust));
    dataBase->insert(std::make_pair("Balsam Fir", BalsamFir));
}