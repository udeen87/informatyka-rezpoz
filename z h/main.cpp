#include <iostream>
#include "functions.h"

using namespace std;

int main() {
    printf("Arrays\n");

    int numbers[SIZE] = {1, -21, 37, 420, -5, 67, 7, 8, 9, 10};

    printArray(numbers, SIZE);
    printf("max = %d\n", findMaximum(numbers, SIZE));
    printf("min = %d\n", findMinimum(numbers, SIZE));
    printf("average = %.2f\n", calculateAverage(numbers, SIZE));
    printf("median = %.2f\n", findMedian(numbers, SIZE));

    return 0;
}