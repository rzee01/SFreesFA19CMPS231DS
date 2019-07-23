#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "btree.h"
#include <list>

using namespace std;

TEST_CASE("Insert / find on binary search tree")
{
    BSTree tree;
    tree.insert(5);
    tree.insert(19);
    tree.insert(2);
    tree.insert(-42);
    tree.insert(21);
    tree.insert(10);
    tree.insert(-5);

    REQUIRE(tree.find(21));
    REQUIRE(tree.find(5));
    REQUIRE(tree.find(98) == false);
}

TEST_CASE("Binary tree can be converted to ascending list")
{
    BSTree tree;
    tree.insert(5);
    tree.insert(19);
    tree.insert(2);
    tree.insert(-42);
    tree.insert(21);
    tree.insert(10);
    tree.insert(-5);

    auto list = tree.as_list();
    auto i = list.cbegin();
    REQUIRE(*i == -42);
    ++i;
    REQUIRE(*i == -5);
    ++i;
    REQUIRE(*i == 2);
    ++i;
    REQUIRE(*i == 5);
    ++i;
    REQUIRE(*i == 10);
    ++i;
    REQUIRE(*i == 19);
    ++i;
    REQUIRE(*i == 21);
    ++i;
    REQUIRE(i == list.cend());
}

TEST_CASE("Removal from binary search tree")
{
    BSTree tree;
    tree.insert(5);
    tree.insert(19);
    tree.insert(2);
    tree.insert(-42);
    tree.insert(21);
    tree.insert(10);
    tree.insert(-5);
    tree.insert(20);

    // delete a leaf node
    tree.remove(-5);
    // delete a node with two children
    tree.remove(19);
    // delete a node with one child
    tree.remove(2);
    // delete a value that doesn't exist - shouldn't crash!
    tree.remove(29);

    auto list = tree.as_list();

    auto i = list.cbegin();

    REQUIRE(*i == -42);
    ++i;
    REQUIRE(*i == 5);
    ++i;
    REQUIRE(*i == 10);
    ++i;
    REQUIRE(*i == 20);
    ++i;
    REQUIRE(*i == 21);
    ++i;
    REQUIRE(i == list.cend());
}