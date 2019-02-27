#include <stdio.h>
#include <stdlib.h>

// You will write a program that keeps track of exam results.
// First, your program should ask the user how many classes took the exam. Let's say this number is N.
// Then you need to ask how many students took the exam in the first class. Let's say this number is M.
// You need to ask for the name of the class, the the exam results in percentage M times and store them.
// The number of students might be different for each class.
// You need to repeat this N times.
// Make sure you have a separate function that reads the data and returns it.

// Once you have the data write functions for the following questions:
// Which class has the biggest difference between the worst and best exam and how much is the difference?
// Which class has the best exam?
// What is the average of all the exams?

typedef struct
{
    int students;
    char name[25];
    int* results;
} class_t;

typedef struct
{
    class_t* class;
    int numOfClasses;
} data_t;

data_t getData()
{
    data_t data;
    puts("How many classes took the exam: ");
    scanf("%d", &data.numOfClasses);
    data.class = (class_t*) calloc(data.numOfClasses, sizeof(class_t));
    for (int i = 0; i < data.numOfClasses; i++) {
        printf("Name of next class:\n");
        scanf("%s", data.class->name);
        printf("How many students took the exam at %s:\n", data.class->name);
        scanf("%d", &data.class->students);
        data.class->results = (int*) calloc(data.class->students, sizeof(int));
        for (int j = 0; j < data.class->students; j++) {
            printf("Student %d:\n", j + 1);
            scanf("%d", &data.class->results[j]);
        }
    }
    return data;
}

int main()
{
    data_t data = getData();
    return 0;
}