#include <iostream>
#include <string>

int main(int argc, char* args[]) {

    // - Create (dynamically) a two dimensional array
    //   with the following matrix. Use a loop!
    //   by dynamically, we mean here that you can change the size of the matrix
    //   by changing an input value or a parameter or this combined
    //
    //   1 0 0 0
    //   0 1 0 0
    //   0 0 1 0
    //   0 0 0 1
    //
    // - Print this two dimensional array to the output
    int sizeOfMatrix = 0;
    std::cout << "Please provide me a number between 3 and 10" << std::endl;
    std::cin >> sizeOfMatrix;
    if(sizeOfMatrix > 10){
        sizeOfMatrix = 10;
    } else if(sizeOfMatrix < 3){
        sizeOfMatrix = 3;
    }
    int matrix[sizeOfMatrix][sizeOfMatrix];
    int indexOfOne = 0;

    //Creating matrix
    for(int i = 0;i<sizeOfMatrix;i++){
        for(int j = 0;j<sizeOfMatrix;j++){
            if(j == indexOfOne){
                matrix[i][j] = 1;
            } else {
                matrix[i][j] = 0;
            }
        }
        indexOfOne++;
    }

    //Printing Matrix
    for(int i = 0;i<sizeOfMatrix;i++){
        for(int j = 0;j<sizeOfMatrix;j++){
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }


    system("PAUSE");
    return 0;
}