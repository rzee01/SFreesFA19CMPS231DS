#define CATCH_CONFIG_MAIN
#include <stdexcept>
#include "catch.hpp"
#include "histogram.h"

using namespace std;

TEST_CASE("Constructor initializes all values to 0")
{
    Histogram h;
    for (int i = 0; i < Histogram::MAX; i++)
    {
        REQUIRE(h.count(i) == 0);
    }
}

TEST_CASE("Count throws exception if index out of bounds")
{
    // Notice here that we are using the catch.hpp library macro
    // to make the testing of exceptions a bit cleaner...
    Histogram h;
    CHECK_THROWS_AS(h.count(Histogram::MAX * 10), out_of_range);
}
TEST_CASE("Count throws exception if index out of bounds (negative)")
{
    Histogram h;
    CHECK_THROWS_AS(h.count(-5), out_of_range);
}

TEST_CASE("Sample throws exception if index out of bounds")
{
    Histogram h;
    CHECK_THROWS_AS(h.sample(Histogram::MAX * 10), out_of_range);
}
TEST_CASE("Sample throws exception if index out of bounds (negative)")
{
    Histogram h;
    CHECK_THROWS_AS(h.sample(-5), out_of_range);
}

TEST_CASE("Samples correctly")
{
    Histogram h;
    h.sample(5);
    h.sample(45);
    h.sample(92);
    h.sample(45);

    for (int i = 0; i < Histogram::MAX; i++)
    {
        if (i == 5)
        {
            REQUIRE(h.count(i) == 1);
        }
        else if (i == 45)
        {
            REQUIRE(h.count(i) == 2);
        }
        else if (i == 92)
        {
            REQUIRE(h.count(i) == 1);
        }
        else
        {
            REQUIRE(h.count(i) == 0);
        }
    }
}
