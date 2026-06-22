#ifndef AIRPLANE_H
#define AIRPLANE_H

#include <vector>
#include <string>
#include "Seat.h"

// Typ wyliczeniowy określający rezultat wyboru
enum class SelectResult { SUCCESS_ADDED, SUCCESS_REMOVED, ERROR_OCCUPIED, ERROR_INVALID };

class Airplane {
private:
    std::string planeName; // Nazwa wybranego samolotu
    int numRows;
    std::vector<std::vector<Seat>> seats;

    void initializeSeats();

public:
    // Konstruktor teraz przyjmuje nazwę samolotu i liczbę rzędów
    Airplane(std::string name, int rows);

    SelectResult toggleSeat(const std::string& seatId, const std::string& passengerName);

    std::string getName() const;
    int getNumRows() const;
    const std::vector<std::vector<Seat>>& getSeats() const;

    // Zwraca miejsca przypisane do konkretnego użytkownika
    std::vector<std::string> getSelectedSeats(const std::string& passengerName) const;

    // NOWE: Zwraca listę WSZYSTKICH zajętych miejsc (do podglądu i zapisu do pliku)
    std::vector<Seat> getOccupiedSeats() const;
};

#endif // AIRPLANE_H
