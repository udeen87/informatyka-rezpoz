#include <stdio.h>
#include "Stack.h"

void menu(void)
{
    printf("\n");
    printf("===== STOS =====\n");
    printf("1 - poloz liczbe na stosie (Push)\n");
    printf("2 - odczytaj wartosc ze szczytu stosu (Top)\n");
    printf("3 - zdejmij liczbe ze stosu (Pop)\n");
    printf("4 - sprawdz czy stos jest pusty\n");
    printf("5 - sprawdz czy stos jest pelny\n");

    printf("\n===== KOLEJKA =====\n");
    printf("6 - dodaj liczbe do kolejki (Enqueue)\n");
    printf("7 - odczytaj pierwszy element kolejki (Front)\n");
    printf("8 - usun pierwszy element z kolejki (Dequeue)\n");
    printf("9 - sprawdz czy kolejka jest pusta\n");
    printf("10 - sprawdz czy kolejka jest pelna\n");

    printf("\n11 - koniec programu\n");
    printf("\n");
}

int main()
{
    int temp = 0;
    int option = 0;

    printf("STOS i KOLEJKA - implementacja w tablicy statycznej\n");

    while (1)
    {
        menu();
        scanf("%d", &option);

        switch (option)
        {
            case 1:
                if (!isStackFull()) {
                    printf("Podaj wartosc: ");
                    scanf("%d", &temp);
                    Push(temp);
                }
                else {
                    printf("Operacja niedozwolona - STOS pelny!\n");
                }
                break;

            case 2:
                if (!isStackEmpty()) {
                    temp = Top();
                    printf("Odczytana wartosc ze stosu: %d\n", temp);
                }
                else {
                    printf("Operacja niedozwolona - STOS pusty!\n");
                }
                break;

            case 3:
                if (!isStackEmpty()) {
                    temp = Pop();
                    printf("Zdjeta wartosc ze stosu: %d\n", temp);
                }
                else {
                    printf("Operacja niedozwolona - STOS pusty!\n");
                }
                break;

            case 4:
                if (isStackEmpty()) {
                    printf("STOS jest pusty.\n");
                }
                else {
                    printf("STOS nie jest pusty.\n");
                }
                break;

            case 5:
                if (isStackFull()) {
                    printf("STOS jest pelny.\n");
                }
                else {
                    printf("STOS nie jest pelny.\n");
                }
                break;

            case 6:
                if (!isQueueFull()) {
                    printf("Podaj wartosc: ");
                    scanf("%d", &temp);
                    Enqueue(temp);
                }
                else {
                    printf("Operacja niedozwolona - KOLEJKA pelna!\n");
                }
                break;

            case 7:
                if (!isQueueEmpty()) {
                    temp = Front();
                    printf("Pierwszy element kolejki: %d\n", temp);
                }
                else {
                    printf("Operacja niedozwolona - KOLEJKA pusta!\n");
                }
                break;

            case 8:
                if (!isQueueEmpty()) {
                    temp = Dequeue();
                    printf("Usuniety element z kolejki: %d\n", temp);
                }
                else {
                    printf("Operacja niedozwolona - KOLEJKA pusta!\n");
                }
                break;

            case 9:
                if (isQueueEmpty()) {
                    printf("KOLEJKA jest pusta.\n");
                }
                else {
                    printf("KOLEJKA nie jest pusta.\n");
                }
                break;

            case 10:
                if (isQueueFull()) {
                    printf("KOLEJKA jest pelna.\n");
                }
                else {
                    printf("KOLEJKA nie jest pelna.\n");
                }
                break;

            case 11:
                return 0;

            default:
                printf("Wybierz wlasciwa opcje.\n");
                break;
        }
    }

    return 0;
}