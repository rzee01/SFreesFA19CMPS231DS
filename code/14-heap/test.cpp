#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "heap.h"
#include <list>

using namespace std;

TEST_CASE("Insert and remove from heap")
{

    Heap h;
    h.push(5);
    h.push(19);
    h.push(2);
    h.push(-42);
    h.push(21);
    h.push(10);
    h.push(-5);
    int expected [] = {21, 19, 10, 5, 2, -5, -42};
    for ( int i = 0; i < 7; i++ ) {
        REQUIRE((h.top() == expected[i]));
        h.pop();
    }
}

