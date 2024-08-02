#include "Theater.h"

Theater::Theater(const std::string& name) : name(name) {
    for (int i = 1; i <= 20; ++i) {
        seats.emplace_back(i);
    }
}

std::string Theater::getName() const {
    return name;
}

const std::vector<Seat>& Theater::getSeats() const {
    return seats;
}

bool Theater::bookSeat(int seatNumber) {
    if (seatNumber < 1 || seatNumber > 20) return false;
    if (seats[seatNumber - 1].isBooked()) return false;
    seats[seatNumber - 1].book();
    return true;
}
