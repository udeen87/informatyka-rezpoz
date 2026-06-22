#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {

    char zdanie[1000] = "";

    for (int i = 1; i < argc; i++) {
        strcat(zdanie, argv[i]);
        if (i < argc - 1) {
            strcat(zdanie, " ");
        }
    }

    printf("Oryginal: %s\n", zdanie);

    for (int i = 0; i < strlen(zdanie); i++) {
        if (zdanie[i] >= 'a' && zdanie[i] <= 'z') {
            zdanie[i] = zdanie[i] - 32;
        }
        else if (zdanie[i] >= 'A' && zdanie[i] <= 'Z') {
            zdanie[i] = zdanie[i] + 32;
        }
    }

    printf("Zamienione: %s\n", zdanie);

    printf("Liczba znakow: %d\n", (int)strlen(zdanie));

    return 0;
}