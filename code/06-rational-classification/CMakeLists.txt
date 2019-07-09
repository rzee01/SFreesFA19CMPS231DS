cmake_minimum_required (VERSION 2.6)
set (CMAKE_CXX_STANDARD 11)

project (classify-rational)

enable_testing()
add_test( Tests testing)

include_directories(./includes)
include_directories(../utils)

add_library(classify includes/classify.cpp)
add_library(rational includes/rational.cpp)

add_executable(classify-ui main.cpp)
target_link_libraries(classify-ui classify)
target_link_libraries(classify-ui rational)

# Add another executable for testing
add_executable(testing test.cpp)
target_link_libraries(testing classify)
target_link_libraries(testing rational)

