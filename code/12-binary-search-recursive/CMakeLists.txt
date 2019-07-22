cmake_minimum_required (VERSION 2.6)
set (CMAKE_CXX_STANDARD 11)

# This names our project
project (binary-search-recursive)

enable_testing()
add_test( Tests testing)

include_directories(./includes)
include_directories(../utils)

add_executable(bsearch main.cpp)

add_executable(testing test.cpp)
