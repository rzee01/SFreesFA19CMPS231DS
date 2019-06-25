cmake_minimum_required (VERSION 2.6)
set (CMAKE_CXX_STANDARD 11)

# This names our project
project (sort-in-place)


enable_testing()
add_test( Tests sort-test)


# add the dependencies - the other source code files in your program
include_directories(./includes)
include_directories(../utils)

add_library(sort includes/sort.cpp)

# This defines the name of our executable, and the file that contains main.
add_executable(sort-ui main.cpp)
target_link_libraries(sort-ui sort)

# Add another executable for testing
add_executable(sort-test test.cpp)
target_link_libraries(sort-test sort)

