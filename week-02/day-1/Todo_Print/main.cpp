#include <iostream>
#include <string>

int main(int argc, char *args[]) {
    std::string todoText = " - Buy milk\n";

    std::string easterEgg = "- To do\n"
                            "- To do\n"
                            "- To do, to do, to do, to do\n"
                            "- To dooooo, dodododo";
    // Add "My todo:" to the beginning of the todoText
    // Add " - Download games" to the end of the todoText
    // Add " - Diablo" to the end of the todoText but with indentation

    // Expected outpt:

    // My todo:
    //  - Buy milk
    //  - Download games
    //      - Diablo
    std::string todoHead = "My todo:\n";
    std::string downloadText = " - Download games\n";
    std::string diabloText = "\t - Diablo";


    todoText.insert(0, todoHead);
    todoText += downloadText;
    todoText += diabloText;

    char input;
    std::cout << "Are you pink?(y/n)";
    std::cin >> input;

    if(input == 'y') {
        std::cout << easterEgg << std::endl;
    } else {
        std::cout << todoText << std::endl;
    }

    system("PAUSE");
    return 0;
}