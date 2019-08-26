#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "linked-list.h"

TEST_CASE("Test Case 1", "Split/Switch")
{
    List<int> list;
    for (int i = 0; i < 20; i++)
    {
        list.push_back(i);
    }

    REQUIRE(list.size() == 20);
    REQUIRE(list.back() == 19);
    REQUIRE(list.front() == 0);

    list.SplitAndSwitch();
    REQUIRE(list.size() == 20);
    REQUIRE(list.back() == 9);
    REQUIRE(list.front() == 10);

    int expected[] = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    auto it = list.begin();
    for (int i = 0; i < 20; i++)
    {
        REQUIRE(it.data() == expected[i]);
        it.forward();
    }
    // Ensure things really a set up correctly after split/switch
    list.clear();
}

TEST_CASE("Test Case 2", "Split/Switch on short list")
{
    List<int> list;
    list.push_back(0);
    list.push_back(1);

    REQUIRE(list.size() == 2);
    REQUIRE(list.back() == 1);
    REQUIRE(list.front() == 0);

    list.SplitAndSwitch();
    REQUIRE(list.size() == 2);
    REQUIRE(list.back() == 0);
    REQUIRE(list.front() == 1);
}

TEST_CASE("Test Case 3", "Split/Switch on list of one")
{
    List<int> list;
    list.push_back(1);

    REQUIRE(list.size() == 1);

    list.SplitAndSwitch();
    REQUIRE(list.size() == 1);
}

TEST_CASE("Test Case 4", "Split/Switch on empty")
{
    List<int> list;

    REQUIRE(list.size() == 0);

    list.SplitAndSwitch();
    REQUIRE(list.size() == 0);
}

TEST_CASE("Test Case 5", "Reverse")
{
    List<int> list;
    for (int i = 0; i < 20; i++)
    {
        list.push_back(i);
    }

    REQUIRE(list.size() == 20);
    REQUIRE(list.back() == 19);
    REQUIRE(list.front() == 0);

    list.Reverse();
    REQUIRE(list.size() == 20);
    REQUIRE(list.back() == 0);
    REQUIRE(list.front() == 19);

    auto it = list.begin();
    for (int i = 19; i >= 0; i--)
    {
        REQUIRE(it.data() == i);
        it.forward();
    }
    // Ensure things really a set up correctly after split/switch
    list.clear();
}

TEST_CASE("Test Case 6", "Reverse on list of one")
{
    List<int> list;
    list.push_back(1);

    REQUIRE(list.size() == 1);

    list.Reverse();
    REQUIRE(list.size() == 1);
}

TEST_CASE("Test Case 7", "Reverse on empty")
{
    List<int> list;

    REQUIRE(list.size() == 0);

    list.Reverse();
    REQUIRE(list.size() == 0);
}