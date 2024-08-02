#include <gtest/gtest.h>
#include "BookingSystem.h"

// Test for adding and retrieving movies
TEST(BookingSystemTest, AddAndRetrieveMovies) {
    BookingSystem system;
    system.addMovie(Movie("Movie1"));
    system.addMovie(Movie("Movie2"));

    auto movies = system.getMovies();
    ASSERT_EQ(movies.size(), 2);
    EXPECT_EQ(movies[0], "Movie1");
    EXPECT_EQ(movies[1], "Movie2");
}

// Test for adding and retrieving theaters
TEST(BookingSystemTest, AddAndRetrieveTheaters) {
    BookingSystem system;
    system.addMovie(Movie("Movie1"));
    system.addTheater(Theater("Theater1"), "Movie1");
    system.addTheater(Theater("Theater2"), "Movie1");

    auto theaters = system.getTheaters("Movie1");
    ASSERT_EQ(theaters.size(), 2);
    EXPECT_EQ(theaters[0], "Theater1");
    EXPECT_EQ(theaters[1], "Theater2");
}

// Test for retrieving available seats
TEST(BookingSystemTest, RetrieveAvailableSeats) {
    BookingSystem system;
    system.addMovie(Movie("Movie1"));
    system.addTheater(Theater("Theater1"), "Movie1");

    auto availableSeats = system.getAvailableSeats("Movie1", "Theater1");
    ASSERT_EQ(availableSeats.size(), 20);
    for (int i = 1; i <= 20; ++i) {
        EXPECT_EQ(availableSeats[i-1], i);
    }
}

// Test for booking seats
TEST(BookingSystemTest, BookSeats) {
    BookingSystem system;
    system.addMovie(Movie("Movie1"));
    system.addTheater(Theater("Theater1"), "Movie1");

    std::vector<int> seatsToBook = {1, 2, 3};
    bool bookingResult = system.bookSeats("Movie1", "Theater1", seatsToBook);
    EXPECT_TRUE(bookingResult);

    auto availableSeats = system.getAvailableSeats("Movie1", "Theater1");
    ASSERT_EQ(availableSeats.size(), 17);  // 3 seats booked, 17 should be available

    // Try booking the same seats again
    bookingResult = system.bookSeats("Movie1", "Theater1", seatsToBook);
    EXPECT_FALSE(bookingResult);

    availableSeats = system.getAvailableSeats("Movie1", "Theater1");
    ASSERT_EQ(availableSeats.size(), 17);  // No additional seats should have been booked
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
