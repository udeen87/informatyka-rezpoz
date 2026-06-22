#include "Airplane.h"
#include "ConsoleUI.h"
#include <iostream>
#include <limits>

int main() {
    std::cout << "=== KONFIGURATOR LOTU ===\n";
    std::cout << "Wybierz model samolotu na dzisiejszy lot:\n";
    std::cout << "1. Embraer 190 (10 rzedow, 60 miejsc)\n";
    std::cout << "2. Airbus A320 (20 rzedow, 120 miejsc)\n";
    std::cout << "3. Boeing 737  (30 rzedow, 180 miejsc)\n";
    std::cout << "Twoj wybor (1-3): ";

    int choice;
    // Zabezpieczenie przed wpisaniem litery zamiast cyfry
    while (!(std::cin >> choice) || choice < 1 || choice > 3) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Nieprawidlowy wybor. Sprobuj ponownie: ";
    }

    std::string planeName;
    int rows;

    if (choice == 1) {
        planeName = "Embraer 190";
        rows = 10;
    } else if (choice == 2) {
        planeName = "Airbus A320";
        rows = 20;
    } else {
        planeName = "Boeing 737";
        rows = 30;
    }

    std::cout << "\nUruchamianie systemu dla maszyny: " << planeName << "...\n\n";

    // Inicjalizacja samolotu zgodnie z wyborem
    Airplane flight(planeName, rows);

    // Uruchomienie konsoli UI
    ConsoleUI ui(flight);
    ui.run();

    return 0;
}
