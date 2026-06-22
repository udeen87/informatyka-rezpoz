#include <iostream>
#include "functions.h"

using namespace std;

void printArray(int numbers[], int size) {
    for (int i = 0; i < size; i++) {
        printf("numbers[%d] = %d\n", i, *(numbers + i));
    }
}

int findMaximum(int numbers[], int size) {
    int max = numbers[0];

    for (int i = 0; i < size; i++) {
        if (max < *(numbers + i)) {
            max = *(numbers + i);
        }
    }

    return max;
}

int findMinimum(int numbers[], int size) {
    int min = numbers[0];

    for (int i = 0; i < size; i++) {
        if (min > *(numbers + i)) {
            min = *(numbers + i);
        }
    }

    return min;
}

float calculateAverage(int numbers[], int size) {
    int sum = 0;

    for (int i = 0; i < size; i++) {
        sum += *(numbers + i);
    }

    return (float)sum / size;
}

void copyArray(int numbers[], int temp[], int size) {
    for (int i = 0; i < size; i++) {
        temp[i] = *(numbers + i);
    }
}

float findMedian(int numbers[], int size) {
    int temp[SIZE];

    copyArray(numbers, temp, size);

    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (temp[i] > temp[j]) {
                int change = temp[i];
                temp[i] = temp[j];
                temp[j] = change;
            }
        }
    }

    if (size % 2 == 0) {
        return (temp[size / 2 - 1] + temp[size / 2]) / 2.0;
    } else {
        return temp[size / 2];
    }
}

//switch case, do, option, proste menu konsolowe, dodać funkcje po kolei