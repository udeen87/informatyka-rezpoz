#include <iostream>
#include "functions.h"

using namespace std;

int main() {
    int array[SIZE] = {1, 2, 3, -4, 50, 6, 7, 8, 9, 10};
    int option = 0;

    printf("SIMPLE ARRAY\n\n");

    do {
        menu();
        scanf("%d", &option);

        switch (option) {
            case 0:
                printf("Exiting program...\n\n");
                break;

            case 1:
                printf("Entering values into the array\n");
                enterValues(array, SIZE);
                break;

            case 2:
                printArray(array, SIZE);
                break;

            case 3:
                printf("Minimum value = %d\n\n", findMinimum(array, SIZE));
                break;

            case 4:
                printf("Maximum value = %d\n\n", findMaximum(array, SIZE));
                break;

            case 5:
                printf("Average value = %.2f\n\n", calculateAverage(array, SIZE));
                break;

            default:
                printf("Choose the right option...\n\n");
        }

    } while (option != 0);

    printf("THE END!\n");

    return 0;
}