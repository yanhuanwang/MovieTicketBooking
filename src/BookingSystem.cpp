#include "BookingSystem.h"

void BookingSystem::addMovie(const Movie& movie) {
    std::lock_guard<std::mutex> lock(mtx);
    movies.push_back(movie);
}

void BookingSystem::addTheater(const Theater& theater, const std::string& movieName) {
    std::lock_guard<std::mutex> lock(mtx);
    movieTheaters[movieName].push_back(theater);
}

std::vector<std::string> BookingSystem::getMovies() const {
    std::lock_guard<std::mutex> lock(mtx);
    std::vector<std::string> movieNames;
    for (const auto& movie : movies) {
        movieNames.push_back(movie.getName());
    }
    return movieNames;
}

std::vector<std::string> BookingSystem::getTheaters(const std::string& movieName) const {
    std::lock_guard<std::mutex> lock(mtx);
    std::vector<std::string> theaterNames;
    if (movieTheaters.find(movieName) != movieTheaters.end()) {
        for (const auto& theater : movieTheaters.at(movieName)) {
            theaterNames.push_back(theater.getName());
        }
    }
    return theaterNames;
}

std::vector<int> BookingSystem::getAvailableSeats(const std::string& movieName, const std::string& theaterName) const {
    std::lock_guard<std::mutex> lock(mtx);
    std::vector<int> availableSeats;
    if (movieTheaters.find(movieName) != movieTheaters.end()) {
        for (const auto& theater : movieTheaters.at(movieName)) {
            if (theater.getName() == theaterName) {
                for (const auto& seat : theater.getSeats()) {
                    if (!seat.isBooked()) {
                        availableSeats.push_back(seat.getNumber());
                    }
                }
                break;
            }
        }
    }
    return availableSeats;
}

bool BookingSystem::bookSeats(const std::string& movieName, const std::string& theaterName, const std::vector<int>& seatNumbers) {
    std::lock_guard<std::mutex> lock(mtx);
    if (movieTheaters.find(movieName) != movieTheaters.end()) {
        for (auto& theater : movieTheaters.at(movieName)) {
            if (theater.getName() == theaterName) {
                for (const auto& seatNumber : seatNumbers) {
                    if (!theater.bookSeat(seatNumber)) {
                        return false;
                    }
                }
                return true;
            }
        }
    }
    return false;
}
