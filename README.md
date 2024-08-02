# Movie Ticket Booking System

## Overview

This project implements a backend service in C++ for booking movie tickets. The service provides APIs for viewing movies, selecting movies and theaters, viewing available seats, and booking seats. It ensures that multiple booking requests can be handled simultaneously without over-bookings.

## Features

- View all playing movies
- Select a movie
- See all theaters showing the selected movie
- Select a theater
- View available seats in the selected theater
- Book one or more available seats
- Handles multiple simultaneous booking requests

## Technical Requirements

- Written in C++11 or later
- In-memory data storage (no DBMS)
- Thread-safe operations for concurrent bookings
- Clean, well-documented source code
- Unit tests for all functionalities

## Optional Features

- Conan package management
- Docker support
- Documentation generation using Doxygen

## Project Structure

MovieTicketBooking/
├── CMakeLists.txt
├── README.md
├── include/
│   ├── BookingSystem.h
│   ├── Movie.h
│   ├── Seat.h
│   └── Theater.h
├── src/
│   ├── BookingSystem.cpp
│   ├── Movie.cpp
│   ├── Seat.cpp
│   └── Theater.cpp
└── tests/
    ├── CMakeLists.txt
    └── test_booking_system.cpp



## Getting Started

### Prerequisites

- C++ compiler (supporting C++11 or later)
- CMake (version 3.10 or later)
- Google Test (gtest)

### Installing Google Test

On macOS, you can install Google Test using Homebrew:

```bash
brew install googletest
```

Building the Project
1. Clone the repository:
2. Create a build directory and navigate into it:
3. Run CMake to configure the project and generate build files:
4. Build the project:

Running the Application
```bash
./MovieTicketBooking
```


Running the Tests
To run the unit tests, execute the following command in the build directory:

```bash
./tests/runUnitTests
```

