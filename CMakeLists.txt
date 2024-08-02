cmake_minimum_required(VERSION 3.10)
project(MovieTicketBooking)

set(CMAKE_CXX_STANDARD 14)

# Find Boost libraries
find_package(Boost REQUIRED COMPONENTS system thread)

include_directories(include ${Boost_INCLUDE_DIRS})

add_executable(MovieTicketBooking
    src/main.cpp
    src/Movie.cpp
    src/Theater.cpp
    src/Seat.cpp
    src/BookingSystem.cpp
)

# Link Boost libraries
target_link_libraries(MovieTicketBooking PRIVATE ${Boost_LIBRARIES})

# Enable testing
enable_testing()

# Add Google Test from the external directory
add_subdirectory(external/googletest)
include_directories(external/googletest/googletest/include)

# Add test directory
add_subdirectory(tests)

# Add custom target to copy Swagger-UI files to the build directory
add_custom_target(copy-swagger-ui ALL
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/external/swagger-ui/dist ${CMAKE_BINARY_DIR}/swagger-ui
    COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_SOURCE_DIR}/external/swagger-ui/spec/swagger.yaml ${CMAKE_BINARY_DIR}/swagger-ui/swagger.yaml
)
add_dependencies(MovieTicketBooking copy-swagger-ui)