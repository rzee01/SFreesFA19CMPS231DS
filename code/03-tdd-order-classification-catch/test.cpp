#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "classify.h"

TEST_CASE("Equality works", "[equal]")
{
    REQUIRE(classify(0, 0, 0) == EQUAL);
    REQUIRE(classify(1, 1, 1) == EQUAL);
    REQUIRE(classify(-1, -1, -1) == EQUAL);
}

TEST_CASE("Ascending works", "[ascending]")
{
    REQUIRE(classify(2, 3, 4) == ASCENDING);
    REQUIRE(classify(2, 3, 3) == ASCENDING);
    REQUIRE(classify(3, 3, 4) == ASCENDING);
}

TEST_CASE("Descending works", "[descending]")
{
    REQUIRE(classify(4, 3, 2) == DESCENDING);
    REQUIRE(classify(3, 3, 2) == DESCENDING);
    REQUIRE(classify(4, 3, 3) == DESCENDING);
}

TEST_CASE("No order works", "[no-order]")
{
    REQUIRE(classify(4, 5, 4) == NO_ORDER);
    REQUIRE(classify(1, 0, 9) == NO_ORDER);
    REQUIRE(classify(-9, 9, -9) == NO_ORDER);
}