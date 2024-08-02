#include "Seat.h"

Seat::Seat(int number) : number(number), booked(false) {}

int Seat::getNumber() const {
    return number;
}

bool Seat::isBooked() const {
    return booked;
}

void Seat::book() {
    booked = true;
}
