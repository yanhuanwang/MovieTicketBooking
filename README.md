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
- Docker support

## Project Structure

MovieTicketBooking/\
├── CMakeLists.txt\
├── README.md\
├── include/\
│   ├── BookingSystem.h\
│   ├── Movie.h\
│   ├── Seat.h\
│   └── Theater.h\
├── src/\
│   ├── BookingSystem.cpp\
│   ├── Movie.cpp\
│   ├── Seat.cpp\
│   └── Theater.cpp\
└── tests/\
    ├── CMakeLists.txt\
    └── test_booking_system.cpp\



## Getting Started

### Prerequisites

- C++ compiler (supporting C++11 or later)
- CMake (version 3.10 or later)
- Google Test (gtest)

Building the Project
1. Clone the repository:
2. Run CMake to configure the project and generate build files:
3. Build the project:
```bash
git clone https://github.com/yanhuanwang/MovieTicketBooking.git
cd MovieTicketBooking
./build.sh
```

Running the Application
```bash
cd build
./MovieTicketBooking
```


Running the Tests
To run the unit tests, execute the following command in the build directory:

```bash
cd build
./tests/runUnitTests
ctest
```


Build the Docker image:
```bash
docker build -t movie-ticket-booking .
```

Run the Docker container:
```bash
docker run -p 8080:8080 movie-ticket-booking
```

Access UI with browser:
http://localhost:8080/swagger/index.html


Run with docker images from docker hub:
```bash
docker run -p 8080:8080 yanhuanwang/movie-ticket-booking:latest
```