/* When creating testing programs, your
   entry point file should always define
   this before including catch.hpp.

   This tells the catch library to inject a ready-made
   main function into this file.
*/
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "hello.h"

TEST_CASE("Things are added correctly", "[hello]")
{
    REQUIRE(add(1, 0) == 1);
    REQUIRE(add(2, 2) == 4);
    REQUIRE(add(3, 9) == 12);
    REQUIRE(add(10, -2) == 8);
}