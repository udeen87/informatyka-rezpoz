#include "ConsoleUI.h"
#include <iostream>
#include <cctype>
#include <fstream>
#include <chrono>  // Do obsługi czasu
#include <ctime>   // Do konwersji czasu
#include <iomanip> // Do formatowania wyjścia (put_time)

ConsoleUI::ConsoleUI(Airplane& plane) : airplane(plane) {}

void ConsoleUI::toUpperString(std::string& str) const {
    for (char& c : str) {
        c = toupper(c);
    }
}

void ConsoleUI::displaySeats(const std::string& currentPassenger) const {
    std::cout << "\n=== UKLAD MIEJSC (" << airplane.getName() << ") ===\n";
    std::cout << "Pasazer: " << currentPassenger << "\n";
    std::cout << "Legenda: [ ] Wolne | [X] Zajete (ktos inny) | [*] Twoje miejsca\n\n";
    std::cout << "    A   B   C       D   E   F\n";

    const auto& seats = airplane.getSeats();
    int rows = airplane.getNumRows();

    for (int i = 0; i < rows; ++i) {
        if (i + 1 < 10) std::cout << " ";
        std::cout << i + 1 << " ";

        for (int j = 0; j < 6; ++j) {
            const Seat& currentSeat = seats[i][j];

            if (currentSeat.isAvailable()) {
                std::cout << "[ ] ";
            } else if (currentSeat.owner == currentPassenger) {
                std::cout << "[*] ";
            } else {
                std::cout << "[X] ";
            }

            if (j == 2) std::cout << "   ";
        }
        std::cout << "\n";
    }

    auto occupied = airplane.getOccupiedSeats();
    if (!occupied.empty()) {
        std::cout << "\n--- LISTA ZAJETYCH MIEJSC ---\n";
        for (const auto& seat : occupied) {
            std::cout << "Miejsce " << seat.id << " -> " << seat.owner << "\n";
        }
        std::cout << "-----------------------------\n";
    }
    std::cout << "\n";
}

void ConsoleUI::displaySelectedSeats(const std::string& currentPassenger) const {
    std::vector<std::string> currentSeats = airplane.getSelectedSeats(currentPassenger);

    std::cout << "Twoje wybrane miejsca: ";
    if (currentSeats.empty()) {
        std::cout << "Brak\n";
    } else {
        for (size_t i = 0; i < currentSeats.size(); ++i) {
            std::cout << currentSeats[i];
            if (i < currentSeats.size() - 1) std::cout << ", ";
        }
        std::cout << "\n";
    }
}

void ConsoleUI::handleSeatSelectionResult(SelectResult result, const std::string& seatId) const {
    switch (result) {
        case SelectResult::SUCCESS_ADDED:
            std::cout << "--- Dodano miejsce " << seatId << " do rezerwacji ---\n";
            break;
        case SelectResult::SUCCESS_REMOVED:
            std::cout << "--- Odznaczono miejsce " << seatId << " ---\n";
            break;
        case SelectResult::ERROR_OCCUPIED: {
            std::string ownerName = "Ktos inny";
            for (const auto& seat : airplane.getOccupiedSeats()) {
                if (seat.id == seatId) {
                    ownerName = seat.owner;
                    break;
                }
            }
            std::cout << "--- BLAD: To miejsce jest juz zajete przez pasazera: " << ownerName << " ! ---\n";
            break;
        }
        case SelectResult::ERROR_INVALID:
            std::cout << "--- BLAD: Nieprawidlowy numer miejsca (np. wpisz 1A albo 5C). ---\n";
            break;
    }
}

void ConsoleUI::runPassengerSession(const std::string& passengerName) {
    std::string input;

    while (true) {
        displaySeats(passengerName);
        displaySelectedSeats(passengerName);

        std::cout << "\nWpisz numer miejsca (np. 3B) aby je ZAZNACZYC/ODZNACZYC,\n'Z' aby ZAKONCZYC rezerwacje dla tej osoby: ";
        std::cin >> input;
        toUpperString(input);

        if (input == "Z") {
            std::cout << "\nZapisano miejsca dla pasazera: " << passengerName << ".\n";
            break;
        } else {
            SelectResult result = airplane.toggleSeat(input, passengerName);
            handleSeatSelectionResult(result, input);
        }
    }
}

// Zapisuje wszystkie rezerwacje do pliku tekstowego na dysku wraz z AKTUALNYM CZASEM
void ConsoleUI::saveToFile() const {
    std::ofstream file("rezerwacje.txt");
    if (file.is_open()) {
        // Pobieranie i formatowanie aktualnej daty i godziny
        auto now = std::chrono::system_clock::now();
        std::time_t now_c = std::chrono::system_clock::to_time_t(now);

        file << "=== RAPORT REZERWACJI ===\n";
        file << "Wygenerowano: " << std::put_time(std::localtime(&now_c), "%Y-%m-%d %H:%M:%S") << "\n";
        file << "Samolot: " << airplane.getName() << "\n\n";

        auto occupied = airplane.getOccupiedSeats();
        if (occupied.empty()) {
            file << "Brak zarezerwowanych miejsc. Lot jest pusty.\n";
        } else {
            for (const auto& seat : occupied) {
                file << "Miejsce " << seat.id << " -> Pasazer: " << seat.owner << "\n";
            }
        }
        file.close();
        std::cout << "\n[!] Utworzono plik 'rezerwacje.txt' z lista pasazerow i stamplem czasowym.\n";
    } else {
        std::cout << "\n[Blad] Nie udalo sie utworzyc pliku 'rezerwacje.txt'.\n";
    }
}

void ConsoleUI::run() {
    std::cout << "Witaj w systemie obslugi pasazerow!\n";

    while (true) {
        std::cout << "\n=========================================\n";
        std::cout << "Kto teraz wybiera miejsce?\n";
        std::cout << "(Wpisz Imie i Nazwisko lub 'W' aby wyjsc z programu): ";

        std::string passengerName;
        std::getline(std::cin >> std::ws, passengerName);

        if (passengerName == "W" || passengerName == "w") {
            // Przed wyjściem generujemy plik
            saveToFile();
            std::cout << "Zamykanie systemu rezerwacji. Do widzenia!\n";
            break;
        }

        runPassengerSession(passengerName);
    }
}
