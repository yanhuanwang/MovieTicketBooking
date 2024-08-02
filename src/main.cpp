#include <iostream>
#include "BookingSystem.h"

int main() {
    BookingSystem system;

    // Add movies
    system.addMovie(Movie("Movie1"));
    system.addMovie(Movie("Movie2"));

    // Add theaters
    system.addTheater(Theater("Theater1"), "Movie1");
    system.addTheater(Theater("Theater2"), "Movie1");
    system.addTheater(Theater("Theater3"), "Movie2");

    // Display movies
    auto movies = system.getMovies();
    std::cout << "Movies currently playing:" << std::endl;
    for (const auto& movie : movies) {
        std::cout << "- " << movie << std::endl;
    }

    // Display theaters for a movie
    auto theaters = system.getTheaters("Movie1");
    std::cout << "\nTheaters showing Movie1:" << std::endl;
    for (const auto& theater : theaters) {
        std::cout << "- " << theater << std::endl;
    }

    // Display available seats in a theater for a movie
    auto availableSeats = system.getAvailableSeats("Movie1", "Theater1");
    std::cout << "\nAvailable seats in Theater1 for Movie1:" << std::endl;
    for (const auto& seat : availableSeats) {
        std::cout << "Seat " << seat << std::endl;
    }

    // Book seats
    std::vector<int> seatsToBook = {1, 2, 3};
    if (system.bookSeats("Movie1", "Theater1", seatsToBook)) {
        std::cout << "\nSuccessfully booked seats 1, 2, 3 in Theater1 for Movie1." << std::endl;
    } else {
        std::cout << "\nFailed to book seats 1, 2, 3 in Theater1 for Movie1." << std::endl;
    }

    // Display available seats after booking
    availableSeats = system.getAvailableSeats("Movie1", "Theater1");
    std::cout << "\nAvailable seats in Theater1 for Movie1 after booking:" << std::endl;
    for (const auto& seat : availableSeats) {
        std::cout << "Seat " << seat << std::endl;
    }

    return 0;
}
