cmake_minimum_required(VERSION 3.10)
project(MovieTicketBooking)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

add_executable(MovieTicketBooking
    src/main.cpp
    src/Movie.cpp
    src/Theater.cpp
    src/Seat.cpp
    src/BookingSystem.cpp
)

# Enable testing
enable_testing()

# Add Google Test
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.11.0.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Add test files
add_subdirectory(tests)
