#include <stdio.h>
#include <stdlib.h>
#include <mem.h>
#include <limits.h>

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

typedef struct
{
    char name[25];
    int difference;
} diff_t;

data_t getData()
{
    data_t data;
    puts("How many classes took the exam: ");
    scanf("%d", &data.numOfClasses);
    data.class = (class_t*) calloc(data.numOfClasses, sizeof(class_t));
    for (int i = 0; i < data.numOfClasses; i++) {
        printf("Name of next class:\n");
        scanf("%s", data.class[i].name);
        printf("How many students took the exam at %s:\n", data.class[i].name);
        scanf("%d", &data.class[i].students);
        data.class[i].results = (int*) calloc(data.class[i].students, sizeof(int));
        for (int j = 0; j < data.class[i].students; j++) {
            printf("Student %d:\n", j + 1);
            scanf("%d", &data.class[i].results[j]);
        }
    }
    return data;
}

float resultAvg(data_t* data)
{
    int numOfResults = 0;
    int resultSum = 0;
    for (int i = 0; i < data->numOfClasses; i++) {
        numOfResults += data->class[i].students;
        for (int j = 0; j < data->class[i].students; j++) {
            resultSum += data->class[i].results[j];
        }
    }
    return (float) resultSum / (float) numOfResults;
}

char* bestExam(data_t* data)
{
    int bestResult = 0;
    int bestClassIndex = 0;
    for (int i = 0; i < data->numOfClasses; i++) {
        for (int j = 0; j < data->class[i].students; j++) {
            int currentRes = data->class[i].results[j];
            if (currentRes > bestResult) {
                bestResult = currentRes;
                bestClassIndex = i;
            }
        }
    }
    return data->class[bestClassIndex].name;
}

diff_t* biggestDiff(data_t* data, diff_t* diff)
{
    int maxDiff = 0;
    int maxDiffIndex = 0;
    for (int i = 0; i < data->numOfClasses; i++) {
        int classMin = data->class[i].results[0];
        int classMax = classMin;
        for (int j = 0; j < data->class[i].students; j++) {
            int currentRes = data->class[i].results[j];
            if (currentRes < classMin)
                classMin = currentRes;
            if (currentRes > classMax)
                classMax = currentRes;
        }
        int currentDiff = classMax - classMin;
        if (currentDiff > maxDiff) {
            maxDiff = currentDiff;
            maxDiffIndex = i;
        }
    }
    strcpy(diff->name, data->class[maxDiffIndex].name);
    diff->difference = maxDiff;
    return diff;
}

void freeDataHeap(data_t* data)
{
    for (int i = 0; i < data->numOfClasses; i++) {
        free(data->class[i].results);
    }
    free(data->class);
}

int main()
{
    data_t data = getData();
    diff_t diff;
    biggestDiff(&data, &diff);
    printf("The biggest difference is at %s, the difference is %d\n", diff.name, diff.difference);
    printf("The best exam result is at %s\n", bestExam(&data));
    printf("Avg: %.2f\n", resultAvg(&data));

    freeDataHeap(&data);

    puts("Type \'e\' to exit.");
    scanf("%*s");
    return 0;
}