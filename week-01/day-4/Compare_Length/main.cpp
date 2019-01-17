#include <iostream>
#include <string>

int main(int argc, char* args[]) {

    // - Create an array variable named `p1`
    //   with the following content: `[1, 2, 3]`
    // - Create an array variable named `p2`
    //   with the following content: `[4, 5]`
    // - Print if `p2` has more elements than `p1`

    int p1[3] = {1,2,3};
    int p2[2] = {4,5};
    int p1Size = sizeof(p1)/sizeof(p1[0]);
    int p2Size = sizeof(p2)/sizeof(p2[0]);
    if(p1Size > p2Size){
        std::cout << "p1 has more elements than p2";
    } else if(p1Size < p2Size){
        std::cout << "p2 has more elements than p1";
    } else {
        std::cout << "p2 and p1 has the same number of elements";
    }

    return 0;
}