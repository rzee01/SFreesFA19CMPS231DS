#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "array-list.h"
#include <stdexcept>
using namespace std;

TEST_CASE("Constructor initializes the array correctly")
{
    ArrayList al;
    REQUIRE(al.length() == 0);
}

TEST_CASE("Appending changes length")
{
    ArrayList al;
    al.append(5);
    al.append(10);
    REQUIRE(al.length() == 2);
}

TEST_CASE("Prepending changes length")
{
    ArrayList al;
    al.prepend(5);
    al.prepend(10);
    REQUIRE(al.length() == 2);
}

TEST_CASE("Get returns the correct value")
{
    ArrayList al;
    al.prepend(5);
    al.prepend(10);
    // expect 10, 5
    REQUIRE(al.get(1) == 5);
}

TEST_CASE("Get throws exception if index is less than 0")
{
    ArrayList al;
    al.prepend(5);
    al.prepend(10);
    CHECK_THROWS_AS(al.get(-1), out_of_range);
}

TEST_CASE("Get throws exception if index greater than length")
{
    ArrayList al;
    al.prepend(5);
    al.prepend(10);
    CHECK_THROWS_AS(al.get(3), out_of_range);
}

TEST_CASE("Find returns -1 if not found")
{
    ArrayList al;
    al.prepend(5);
    al.prepend(10);
    REQUIRE(al.find(21) == -1);
}

TEST_CASE("Find returns the correct index for the given value")
{
    ArrayList al;
    al.prepend(5);
    al.prepend(10);
    al.prepend(15);
    al.prepend(20);
    // expect 20, 15, 10, 5
    REQUIRE(al.find(15) == 1);
}