#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "classify.h"
#include "rational.h"

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

TEST_CASE("Rational numbers work", "[ascending]")
{
    Rational r1(2, 3), r2(4, 6), r3(8, 12), r4(1, 5), r5(8, 2);
    REQUIRE(classify(r1, r2, r3) == EQUAL);
    REQUIRE(classify(r4, r1, r5) == ASCENDING);
    REQUIRE(classify(r4, r4, r1) == DESCENDING);
    REQUIRE(classify(r4, r5, r1) == NO_ORDER);
}
