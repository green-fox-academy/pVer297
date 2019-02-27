#include <stdio.h>
#include <stdlib.h>

//Read the size of a matrix(don't have to be squared matrix) from the console.
//Allocate memory dynamically for the elements of the matrix, then read the elements.
//Create a function which can calculate the n-th percentile of the elements.
//Calculate the 80-th and the 90-th percentile.

double calcPercentile(int** matrix, int mRow, int mCol, int percentile)
{
    int sum = 0;
    for (int i = 0; i < mRow; i++) {
        for (int j = 0; j < mCol; j++) {
            sum += matrix[i][j];
        }
    }
    return (double) sum * ((double) percentile / 100.0);
}

int main()
{
    puts("Please write me the two parameters of the matrix(eg. 3 4)");
    int row = 0;
    int col = 0;
    scanf("%d %d", &row, &col);

    int** matrix = (int**) calloc(row, sizeof(int*));
    for (int i = 0; i < row; i++)
        matrix[i] = (int*) calloc(col, sizeof(int));

    printf("Please type in %d numbers, or %d numbers in %d rows\n", row * col, col, row);

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++)
            scanf("%d", &matrix[i][j]);
    }

    int perc = 0;
    puts("What percentile do you want to count");
    scanf("%d", &perc);

    printf("The %d-th percentile of the given matrix is %lf\n", perc, calcPercentile(matrix, row, col, perc));

    for (int i = 0; i < row; i++) {
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}