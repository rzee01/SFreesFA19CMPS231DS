#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include <vector>
#include <iterator>
#include <algorithm>
#include <deque>
#include <stack>
#include <queue>
using namespace std;

TEST_CASE("push_back adds to the back of the vector")
{
    vector<int> v;
    for (int i = 0; i < 20; i++)
    {
        v.push_back(i);
    }
    REQUIRE(v.size() == 20);
    REQUIRE(v.at(2) == 2); // at reads a value at an index
    REQUIRE(v[6] == 6);    // the [] is overloaded
}

TEST_CASE("the [] operator supports writing")
{
    vector<int> v;
    for (int i = 0; i < 20; i++)
    {
        v.push_back(i);
    }
    v[10] = 42;
    REQUIRE(v.size() == 20);
    REQUIRE(v.at(10) == 42);
}

TEST_CASE("the [] operator supports writing, but it's dangerous!")
{
    vector<int> v;
    for (int i = 0; i < 20; i++)
    {
        v.push_back(i);
    }

    // This is UNDEFINED behavior
    // On most systems it does not throw an exception
    // Bounds are not checked for performance reasons.
    v[100] = 42;

    // Setting a value at an index greater than size
    // DOES NOT CHANGE size.
    REQUIRE(v.size() == 20);

    // Although the return value is UNDEFINED, this
    // will not throw an exception - as the index
    // operator is not bounds checked.
    REQUIRE_NOTHROW(v[100]);

    // The at method IS bounds checked, and will
    // throw an exception for an invalid access.
    // This is a safer way to go, and in most cases
    // the performance penalty is well worth the safety.
    CHECK_THROWS(v.at(100));
}

TEST_CASE("Using assign allows you to ensure size.")
{
    vector<int> v;
    for (int i = 0; i < 20; i++)
    {
        v.push_back(i);
    }

    v.assign(1000, 0); // Assigns 0 to 1000 elements - safely growing the size.

    REQUIRE(v.size() == 1000);
    REQUIRE(v.at(74) == 0);
}

TEST_CASE("Assign and Reserve...  not the same")
{
    vector<int> v;

    v.assign(10, 42); // Fills 10 elements with the value of 42.
    REQUIRE(v.size() == 10);

    // Increases the underlying storage capacity, but does not
    // actually change the size of the vector.
    v.reserve(1000);
    REQUIRE(v.size() == 10);
    REQUIRE(v.capacity() == 1000);

    // Capacity is useful to know if you plan on the vector growing.
    // Each time you call push_back, the vector MAY resize it's capacity.
    // If you are going to do 100000 push_backs, it's better to reserve right
    // away - and not have the vector resize itself a bunch of times as you
    // insert 1 by 1!
}

TEST_CASE("Vectors size can be reduced")
{
    vector<int> v;

    v.assign(10, 42); // Fills 10 elements with the value of 42.

    v.resize(5);
    REQUIRE(v.size() == 5);

    v.clear();
    REQUIRE(v.size() == 0);
}

TEST_CASE("Vectors can be resized up")
{
    vector<int> v;

    v.assign(10, 42); // Fills 10 elements with the value of 42.

    v.resize(500);
    REQUIRE(v.size() == 500);

    // The following won't throw an error, but the value
    // is undefined, since we didn't specify what to fill
    // the new elements with!
    REQUIRE_NOTHROW(v.at(450));

    // We can resize with a filling value
    v.resize(5000, 86);
    REQUIRE(v.at(4096) == 86);
}

TEST_CASE("We can always remove from the back of the vector")
{
    vector<int> v;
    for (int i = 0; i < 20; i++)
    {
        v.push_back(i * 10);
    }

    REQUIRE(v.size() == 20);

    // Back returns last value - equivelant to
    // v.at(v.size()-1)
    REQUIRE(v.back() == 190);

    v.pop_back();
    REQUIRE(v.back() == 180);
    REQUIRE(v.size() == 19);
}

TEST_CASE("Uses iterators")
{
    vector<int> v;
    for (int i = 0; i < 20; i++)
    {
        v.push_back(i * 10);
    }

    auto i = v.begin();
    i++;
    REQUIRE(*i == 10);

    i += 5;
    REQUIRE(*i == 60);

    i = std::prev(i);
    REQUIRE(*i == 50);

    i = std::next(i, 5);
    REQUIRE(*i == 100);
}

TEST_CASE("Uses iterators to iterate :)")
{
    vector<int> v;
    for (int i = 0; i < 20; i++)
    {
        v.push_back(i * 10);
    }

    int a = 0;
    for (auto i = v.begin(); i < v.end(); i++)
    {
        REQUIRE(*i == a);
        a += 10;
    }

    a = 0;
    // C++ 11 range loop
    for (auto const &value : v)
    {
        REQUIRE(a == value);
        a += 10;
    }
}

TEST_CASE("Works with algorithms")
{
    vector<int> v;
    for (int i = 0; i < 20; i++)
    {
        v.push_back(i * 10);
    }

    int sum = 0;
    // accumulate the values in v with low-tech syntax...
    for (int i = 0; i < v.size(); i++)
        sum += v[i];

    REQUIRE(sum == 1900);

    // accumulate the values in v using the language itself..
    sum = std::accumulate(v.begin(), v.end(), 0);
    REQUIRE(sum == 1900);
}

TEST_CASE("Supports insert")
{
    vector<int> v;
    for (int i = 0; i < 20; i++)
    {
        v.push_back(i * 10);
    }

    auto i = v.end() - 5; // points to index 15, with 150 in it.
    v.insert(i, 1);       // put 1 at index 15

    REQUIRE(v.size() == 21);
    REQUIRE(v.at(14) == 140);
    REQUIRE(v.at(15) == 1);
    REQUIRE(v.at(16) == 150);
}

TEST_CASE("Supports erase")
{
    vector<int> v;
    for (int i = 0; i < 20; i++)
    {
        v.push_back(i * 10);
    }

    auto i = v.end() - 5; // points to index 15, with 150 in it.
    v.erase(i);           // Removes index 15

    REQUIRE(v.size() == 19);
    // we cannot re-use the iterator, it's no longer valid.
    i = v.end() - 5; // this is not index 14, 140
    REQUIRE(*i == 140);

    v.erase(v.begin(), v.begin() + 4);
    REQUIRE(v.size() == 15);
    REQUIRE(v.front() == 40);
}

TEST_CASE("Bonus :) Stacks and Queues")
{
    stack<int> s;
    queue<int> q;

    for (int i = 0; i < 20; i++)
    {
        s.push(i);
        q.push(i);
    }

    for (int i = 0; i < 20; i++)
    {
        int v = s.top();
        REQUIRE(v == 19 - i);
        s.pop();
    }

    for (int i = 0; i < 20; i++)
    {
        int v = q.front();
        REQUIRE(v == i);
        q.pop();
    }
}
