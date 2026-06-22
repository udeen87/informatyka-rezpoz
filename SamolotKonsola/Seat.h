#ifndef SEAT_H
#define SEAT_H

#include <string>

// Struktura fotele - oparta na właścicielu (owner)
struct Seat {
    std::string id;       // Numer miejsca, np. "1A", "5F"
    std::string owner;    // Imię i nazwisko pasażera (puste, jeśli wolne)

    // Metoda sprawdzająca, czy miejsce jest wolne
    bool isAvailable() const {
        return owner.empty();
    }
};

#endif // SEAT_H