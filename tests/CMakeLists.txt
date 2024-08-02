add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../external/googletest external/googletest)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(runUnitTests
    test_booking_system.cpp
    ../src/BookingSystem.cpp
    ../src/Movie.cpp
    ../src/Seat.cpp
    ../src/Theater.cpp
)

target_link_libraries(runUnitTests gtest gtest_main)
