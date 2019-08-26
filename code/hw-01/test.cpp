#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "mirror.h"

TEST_CASE("Test Case 1", "[simple, positive]")
{
    REQUIRE(mirror("abcdef", "fedcba"));
}

TEST_CASE("Test Case 2", "[simple, negative]")
{
    REQUIRE(!mirror("abcef", "fecbda"));
}

TEST_CASE("Test Case 3", "[ignoring spaces and punctuation]")
{
    REQUIRE(mirror("a, b. c:", "c,b;a"));
}

TEST_CASE("Test Case 4", "[ignoring capitalization]")
{
    REQUIRE(mirror("abcdef", "FEDCbA"));
}
