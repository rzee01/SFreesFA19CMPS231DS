cmake_minimum_required (VERSION 2.6)
set (CMAKE_CXX_STANDARD 11)

# This names our project
project (starting)


enable_testing()
add_test( Tests testing)


# add the dependencies - the other source code files in your program
include_directories(./includes)

# note we can include any number of directories - but you should be careful
# to only include the ones you need.
# another note:  The path specified is always relative to the CMakeLists.txt
# file that is referencing it.
include_directories(../utils)

add_library(hello includes/hello.cpp)

# This defines the name of our executable, and the file that contains main.
add_executable(starting main.cpp)
target_link_libraries(starting hello)

# Add another executable for testing
add_executable(testing test.cpp)
target_link_libraries(testing hello)

