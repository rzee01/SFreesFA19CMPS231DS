#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "search.h"
using namespace std;


TEST_CASE("Recursive Binary search") {
    int values [] {-42, -5, 2, 5, 10, 19, 21};
    
    REQUIRE(binary_search(values, 7, 21) == 6);
    REQUIRE(binary_search(values, 7, 5) == 3);
    REQUIRE(binary_search(values, 7, 54) == -1);
    
}