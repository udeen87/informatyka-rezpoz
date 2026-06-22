#include <iostream>

void toLower(char *text) {
    while (*text) {
        if ('A' <= *text && *text <= 'Z') {
            *text += ('a' - 'A');
        }
        text++;
    }
}

int textSize(char *text) {
    int size = 0;
    while (*text) {
        size++;
        text++;
    }
    return size;
}

int main() {
    char text[] = "Ala ma kota.";
    printf("%s\n", text);
    toLower(text);
    printf("%s\n", text);
    printf("%d\n", textSize(text));

    return 0;
}

// int main(int argc, char const *argv[]) {
//     // char asciiVal = 65;
//     char asciiVal = 'A';
//     printf("%c\n", asciiVal);
//     printf("%d\n", asciiVal);
//     printf("%x\n", asciiVal);
//     return 0;
// }

// int main() {
//     char text[] = "Ala ma kota.";
//     printf("%s\n", text);
//     // text[4] = 0x30;
//     text[4] = '0';
//     text[5] = 0;
//     printf("%s\n", text);
//
//     return 0;
// }
