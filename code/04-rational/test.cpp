#define CATCH_CONFIG_MAIN
#include <stdexcept>
#include "catch.hpp"
#include "rational.h"

using namespace std;

TEST_CASE("Constructor initializes to 1/1")
{
    Rational r;
    REQUIRE(r.get_numerator() == 1);
    REQUIRE(r.get_denominator() == 1);
}

TEST_CASE("Constructor accepts initialization parameters")
{
    Rational r(2, 5);
    REQUIRE(r.get_numerator() == 2);
    REQUIRE(r.get_denominator() == 5);
}

TEST_CASE("Constructor reduces")
{
    Rational r(2, 6);
    REQUIRE(r.get_numerator() == 1);
    REQUIRE(r.get_denominator() == 3);
}

TEST_CASE("Constructor throws exception if denominator is 0")
{
    try
    {
        Rational r(2, 0);
        // We should never get here...
        REQUIRE(false);
    }
    catch (domain_error &e)
    {
        // OK.... threw an exception
    }
}

TEST_CASE("Adds correctly")
{
    Rational r1(2, 6);
    Rational r2(5, 3);
    Rational sum = r1.add(r2);
    REQUIRE(sum.get_numerator() == 2);
    REQUIRE(sum.get_denominator() == 1);
}

TEST_CASE("Adds correctly with overloads")
{
    Rational r1(2, 5);
    Rational r2(5, 3);
    Rational sum = r1 + r2;
    REQUIRE(sum.get_numerator() == 31);
    REQUIRE(sum.get_denominator() == 15);
}