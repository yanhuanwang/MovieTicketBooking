#ifndef SEAT_H
#define SEAT_H

class Seat {
public:
    Seat(int number);

    int getNumber() const;
    bool isBooked() const;
    void book();

private:
    int number;
    bool booked;
};

#endif // SEAT_H
