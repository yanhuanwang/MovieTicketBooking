#ifndef BOOKINGSYSTEM_H
#define BOOKINGSYSTEM_H

#include <vector>
#include <string>
#include <unordered_map>
#include "Movie.h"
#include "Theater.h"
#include <mutex>

class BookingSystem {
public:
    void addMovie(const Movie& movie);
    void addTheater(const Theater& theater, const std::string& movieName);

    std::vector<std::string> getMovies() const;
    std::vector<std::string> getTheaters(const std::string& movieName) const;
    std::vector<int> getAvailableSeats(const std::string& movieName, const std::string& theaterName) const;
    bool bookSeats(const std::string& movieName, const std::string& theaterName, const std::vector<int>& seatNumbers);

private:
    std::vector<Movie> movies;
    std::unordered_map<std::string, std::vector<Theater>> movieTheaters;
    mutable std::mutex mtx;
};

#endif // BOOKINGSYSTEM_H
