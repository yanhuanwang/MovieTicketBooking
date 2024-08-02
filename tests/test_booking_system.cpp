#include <gtest/gtest.h>
#include "BookingSystem.h"

TEST(BookingSystemTest, AddAndRetrieveMovies) {
    BookingSystem system;
    system.addMovie(Movie("Movie1"));
    system.addMovie(Movie("Movie2"));

    auto movies = system.getMovies();
    EXPECT_EQ(movies.size(), 2);
    EXPECT_EQ(movies[0], "Movie1");
    EXPECT_EQ(movies[1], "Movie2");
}

TEST(BookingSystemTest, AddAndRetrieveTheaters) {
    BookingSystem system;
    system.addMovie(Movie("Movie1"));
    system.addTheater(Theater("Theater1"), "Movie1");
    system.addTheater(Theater("Theater2"), "Movie1");

    auto theaters = system.getTheaters("Movie1");
    EXPECT_EQ(theaters.size(), 2);
    EXPECT_EQ(theaters[0], "Theater1");
    EXPECT_EQ(theaters[1], "Theater2");
}

TEST(BookingSystemTest, BookSeats) {
    BookingSystem system;
    system.addMovie(Movie("Movie1"));
    system.addTheater(Theater("Theater1"), "Movie1");

    auto availableSeats = system.getAvailableSeats("Movie1", "Theater1");
    EXPECT_EQ(availableSeats.size(), 20);

    std::vector<int> seatsToBook = {1, 2, 3};
    bool bookingResult = system.bookSeats("Movie1", "Theater1", seatsToBook);
    EXPECT_TRUE(bookingResult);

    availableSeats = system.getAvailableSeats("Movie1", "Theater1");
    EXPECT_EQ(availableSeats.size(), 17);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
