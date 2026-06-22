#include "Airplane.h"

Airplane::Airplane(std::string name, int rows) : planeName(name), numRows(rows) {
    initializeSeats();
}

void Airplane::initializeSeats() {
    std::vector<char> cols = {'A', 'B', 'C', 'D', 'E', 'F'};

    for (int i = 1; i <= numRows; ++i) {
        std::vector<Seat> row;
        for (char c : cols) {
            Seat s;
            s.id = std::to_string(i) + c;
            s.owner = ""; // Wszystkie miejsca zaczynają jako wolne
            row.push_back(s);
        }
        seats.push_back(row);
    }
}

SelectResult Airplane::toggleSeat(const std::string& seatId, const std::string& passengerName) {
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < 6; ++j) {
            if (seats[i][j].id == seatId) {

                // Jeśli miejsce jest zajęte i właścicielem NIE JEST obecny pasażer
                if (!seats[i][j].isAvailable() && seats[i][j].owner != passengerName) {
                    return SelectResult::ERROR_OCCUPIED;
                }

                // Jeśli miejsce należy do obecnego pasażera -> zwalnia je
                if (seats[i][j].owner == passengerName) {
                    seats[i][j].owner = "";
                    return SelectResult::SUCCESS_REMOVED;
                }

                // Jeśli miejsce jest wolne -> rezerwuje je
                if (seats[i][j].isAvailable()) {
                    seats[i][j].owner = passengerName;
                    return SelectResult::SUCCESS_ADDED;
                }
            }
        }
    }
    return SelectResult::ERROR_INVALID;
}

std::string Airplane::getName() const {
    return planeName;
}

int Airplane::getNumRows() const {
    return numRows;
}

const std::vector<std::vector<Seat>>& Airplane::getSeats() const {
    return seats;
}

std::vector<std::string> Airplane::getSelectedSeats(const std::string& passengerName) const {
    std::vector<std::string> userSeats;
    for (const auto& row : seats) {
        for (const auto& seat : row) {
            if (seat.owner == passengerName) {
                userSeats.push_back(seat.id);
            }
        }
    }
    return userSeats;
}

// Pobiera wszystkie miejsca, które ktoś już zajął
std::vector<Seat> Airplane::getOccupiedSeats() const {
    std::vector<Seat> occupied;
    for (const auto& row : seats) {
        for (const auto& seat : row) {
            if (!seat.isAvailable()) {
                occupied.push_back(seat);
            }
        }
    }
    return occupied;
}
