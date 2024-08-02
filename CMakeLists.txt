cmake_minimum_required(VERSION 3.10)
project(MovieTicketBooking)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

add_executable(MovieTicketBooking
    src/Movie.cpp
    src/Theater.cpp
    src/Seat.cpp
    src/BookingSystem.cpp
)

enable_testing()

add_subdirectory(tests)
