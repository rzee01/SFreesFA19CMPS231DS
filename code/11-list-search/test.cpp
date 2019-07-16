#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include <list>
#include "search.h"
using namespace std;

TEST_CASE("Can search a standard list") {
    list<int> my_list;
    my_list.push_back(5);
    my_list.push_back(2);
    my_list.push_back(-5);
    my_list.push_back(10);
    my_list.push_back(21);
    my_list.push_back(19);
    my_list.push_back(-42);

    auto result = find_unsorted(my_list, 21);
    REQUIRE(result != my_list.cend());

    result = find_unsorted(my_list, 5);
    REQUIRE(result != my_list.cend());

    result = find_unsorted(my_list, 54);
    REQUIRE(result == my_list.cend());
}

TEST_CASE("Can build a sorted list") {
    list<int> my_list;
    
    insert_sorted(my_list, 5);
    insert_sorted(my_list, 2);
    insert_sorted(my_list, -5);
    insert_sorted(my_list, 10);
    insert_sorted(my_list, 21);
    insert_sorted(my_list, 19);
    insert_sorted(my_list, -42);

    auto i = my_list.cbegin();
    REQUIRE(*i == -42);  ++i;
    REQUIRE(*i == -5);  ++i;
    REQUIRE(*i == 2);  ++i;
    REQUIRE(*i == 5);  ++i;
    REQUIRE(*i == 10);  ++i;
    REQUIRE(*i == 19);  ++i;
    REQUIRE(*i == 21);  ++i;
    REQUIRE(i == my_list.cend());
}

TEST_CASE("Can search a sorted list") {
    list<int> my_list;
    
    insert_sorted(my_list, 5);
    insert_sorted(my_list, 2);
    insert_sorted(my_list, -5);
    insert_sorted(my_list, 10);
    insert_sorted(my_list, 21);
    insert_sorted(my_list, 19);
    insert_sorted(my_list, -42);

    auto result = find_unsorted(my_list, 21);
    REQUIRE(result != my_list.cend());

    result = find_unsorted(my_list, 5);
    REQUIRE(result != my_list.cend());

    result = find_unsorted(my_list, 54);
    REQUIRE(result == my_list.cend());
}

TEST_CASE("Simple Binary search") {
    int values [] {-42, -5, 2, 5, 10, 19, 21};
    
    REQUIRE(binary_search(values, 7, 21) == 6);
    REQUIRE(binary_search(values, 7, 5) == 3);
    REQUIRE(binary_search(values, 7, 54) == -1);
    
}