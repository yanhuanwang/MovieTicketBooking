#define CROW_MAIN
#include "crow_all.h"
#include "BookingSystem.h"
#include <mutex>

BookingSystem bookingSystem; // Rename to avoid conflict
std::mutex mtx;

int main() {
    crow::SimpleApp app;

    bookingSystem.addMovie(Movie("Movie1"));
    bookingSystem.addMovie(Movie("Movie2"));

    bookingSystem.addTheater(Theater("Theater1"), "Movie1");
    bookingSystem.addTheater(Theater("Theater2"), "Movie1");
    bookingSystem.addTheater(Theater("Theater3"), "Movie2");

    CROW_ROUTE(app, "/movies")
        .methods(crow::HTTPMethod::GET)([]() {
            std::lock_guard<std::mutex> lock(mtx);
            crow::json::wvalue x;
            auto movies = bookingSystem.getMovies();
            for (size_t i = 0; i < movies.size(); ++i) {
                x[i] = movies[i];
            }
            return x;
        });

    CROW_ROUTE(app, "/movies/<string>/theaters")
        .methods(crow::HTTPMethod::GET)([](const crow::request& req, crow::response& res, std::string movie) {
            std::lock_guard<std::mutex> lock(mtx);
            crow::json::wvalue x;
            auto theaters = bookingSystem.getTheaters(movie);
            for (size_t i = 0; i < theaters.size(); ++i) {
                x[i] = theaters[i];
            }
            res.write(x.dump());
            res.end();
        });

    CROW_ROUTE(app, "/movies/<string>/theaters/<string>/seats")
        .methods(crow::HTTPMethod::GET)([](const crow::request& req, crow::response& res, std::string movie, std::string theater) {
            std::lock_guard<std::mutex> lock(mtx);
            crow::json::wvalue x;
            auto availableSeats = bookingSystem.getAvailableSeats(movie, theater);
            for (size_t i = 0; i < availableSeats.size(); ++i) {
                x[i] = availableSeats[i];
            }
            res.write(x.dump());
            res.end();
        });

    CROW_ROUTE(app, "/movies/<string>/theaters/<string>/seats")
        .methods(crow::HTTPMethod::POST)([](const crow::request& req, crow::response& res, std::string movie, std::string theater) {
            std::lock_guard<std::mutex> lock(mtx);
            auto body = crow::json::load(req.body);
            if (!body) {
                res.code = 400; // BAD_REQUEST
                res.write("Invalid JSON");
                res.end();
                return;
            }

            std::vector<int> seatsToBook;
            for (const auto& seat : body) {
                seatsToBook.push_back(seat.i());
            }

            bool success = bookingSystem.bookSeats(movie, theater, seatsToBook);
            if (success) {
                res.code = 200; // OK
                res.write("Booking successful");
            } else {
                res.code = 400; // BAD_REQUEST
                res.write("Booking failed");
            }
            res.end();
        });

    app.port(8080).multithreaded().run();
}
