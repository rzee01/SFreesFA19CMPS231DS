#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "sort.h"

TEST_CASE("Sorting out of order should work", "[out of order]")
{
    int x = 5, y = 2, z = 9;
    sort_in_place(x, y, z);
    REQUIRE((x <= y && y <= z));
}

TEST_CASE("Sorting in order should work", "[in order]")
{
    int x = 5, y = 6, z = 7;
    sort_in_place(x, y, z);
    REQUIRE((x <= y && y <= z));
}

TEST_CASE("Sorting equal should work", "[equal]")
{
    int x = 5, y = 5, z = 5;
    sort_in_place(x, y, z);
    REQUIRE((x <= y && y <= z));
}