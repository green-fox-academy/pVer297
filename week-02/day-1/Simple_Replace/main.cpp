#include <iostream>
#include <string>

int main(int argc, char* args[])
{
	std::string example("In a dishwasher far far away");
	std::string replace = "dishwasher";
	//example.replace("dishwasher", "galaxy");

    // I would like to replace "dishwasher" with "galaxy" in this example, but it has a problem.
    // Please fix it for me!
    // Expected output: In a galaxy far far away

    example.replace(example.find(replace),replace.length(), "galaxy");

    std::cout << example << std::endl;
    return 0;
}