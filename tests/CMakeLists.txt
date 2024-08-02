include(GoogleTest)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(runUnitTests test_booking_system.cpp)
target_link_libraries(runUnitTests ${GTEST_LIBRARIES} pthread)

gtest_discover_tests(runUnitTests)
