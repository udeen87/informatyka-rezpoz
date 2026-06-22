#include <iostream>
#include "functions.h"

using namespace std;

void printArray(int array[], int size) {
    printf("\nArray content:\n");
    for (int i = 0; i < size; ++i) {
        printf("array[%d] = %d\n", i, array[i]);
    }
    printf("\n");
}

void menu(void) {
    printf("1. Enter the values into the array\n");
    printf("2. Display the content of the array\n");
    printf("3. Determine the minimum value\n");
    printf("4. Determine the maximum value\n");
    printf("5. Determine the average value\n");
    printf("0. EXIT\n");
    printf("Select an option:\n");
}

void enterValues(int array[], int size) {
    printf("\nEnter values:\n");
    for (int i = 0; i < size; i++) {
        printf("array[%d] = ", i);
        scanf("%d", &array[i]);
    }
    printf("\n");
}

int findMinimum(int array[], int size) {
    int min = array[0];

    for (int i = 0; i < size; i++) {
        if (array[i] < min) {
            min = array[i];
        }
    }

    return min;
}

int findMaximum(int array[], int size) {
    int max = array[0];

    for (int i = 0; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }

    return max;
}

float calculateAverage(int array[], int size) {
    int sum = 0;

    for (int i = 0; i < size; i++) {
        sum += array[i];
    }

    return (float)sum / size;
}