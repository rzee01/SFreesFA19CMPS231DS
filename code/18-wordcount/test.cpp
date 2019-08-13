#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "WordCounter.h"
#include <string>
using namespace std;

void initialize(WordCounter &wc)
{
    wc.add("The");
    wc.add("quick");
    wc.add("brown");
    wc.add("fox");
    wc.add("jumps");
    wc.add("over");
    wc.add("the");
    wc.add("lazy");
    wc.add("dog");
}



TEST_CASE("Uninitialized returns 0 counts")
{
    WordCounter wc;
    REQUIRE(wc.count("quick") == 0);
}

TEST_CASE("Uninitialized returns empty list")
{
    WordCounter wc;
    REQUIRE(wc.words().size() == 0);
}

TEST_CASE("Uninitialized but queried still returns empty list")
{
    WordCounter wc;
    wc.count("quick");
    REQUIRE(wc.words().size() == 0);
}

TEST_CASE("Returns correct counts.")
{
    WordCounter wc;
    initialize(wc);
    REQUIRE(wc.words().size() == 8);  // the was listed twice...

    REQUIRE(wc.count("the") == 2);    // Case insensitive, The and the
    REQUIRE(wc.count("qUIcK") == 1);  // Case insensitive
    REQUIRE(wc.count("brown") == 1);
    REQUIRE(wc.count("fox") == 1);
    REQUIRE(wc.count("jumps") == 1);
    REQUIRE(wc.count("over") == 1);
    REQUIRE(wc.count("lazy") == 1);
    REQUIRE(wc.count("dog") == 1);
    REQUIRE(wc.count("foo") == 0);
}
