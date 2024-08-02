#ifndef THEATER_H
#define THEATER_H

#include <string>
#include <vector>
#include "Seat.h"

class Theater {
public:
    Theater(const std::string& name);

    std::string getName() const;
    const std::vector<Seat>& getSeats() const;
    bool bookSeat(int seatNumber);

private:
    std::string name;
    std::vector<Seat> seats;
};

#endif // THEATER_H
