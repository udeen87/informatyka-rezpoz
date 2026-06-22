#ifndef CONSOLE_UI_H
#define CONSOLE_UI_H

#include "Airplane.h"
#include <string>

class ConsoleUI {
private:
    Airplane& airplane;

    void displaySeats(const std::string& currentPassenger) const;
    void displaySelectedSeats(const std::string& currentPassenger) const;
    void handleSeatSelectionResult(SelectResult result, const std::string& seatId) const;
    void toUpperString(std::string& str) const;

    void runPassengerSession(const std::string& passengerName);

    // Funkcja zapisująca dane do pliku tekstowego z aktualnym czasem
    void saveToFile() const;

public:
    ConsoleUI(Airplane& plane);
    void run();
};

#endif // CONSOLE_UI_H