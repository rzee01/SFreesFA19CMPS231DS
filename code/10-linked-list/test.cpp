#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "linked-list.h"
using namespace std;

TEST_CASE("List has no size on construction")
{
    List<int> list;
    REQUIRE(list.size() == 0);
    REQUIRE(list.is_empty()== true);
}

TEST_CASE("You can clear an empty list, and nothing blows up") {
    List<int> list;
    list.clear();
    REQUIRE(list.size() == 0);
    REQUIRE(list.is_empty()== true);
}

TEST_CASE("After insert, the size should be updated properly") {
    List<int> list;
    list.push_front(5);
    list.push_front(10);
    REQUIRE(list.is_empty() == false);
    REQUIRE(list.size() == 2);
    REQUIRE(list.front() == 10);

    // while we are at it, make sure clear does it's job...
    list.clear();
    REQUIRE(list.is_empty() == true);
    REQUIRE(list.size() == 0);
}

TEST_CASE("Front returns copy - list contents cannot change") {
    List<int> list;

    list.push_front(5);

    int v = list.front();
    v = 42;
    REQUIRE(list.front() == 5);

    // Front does not change the list's size.
    REQUIRE(list.size() == 1);
}

TEST_CASE("Calling front on an empty list throws") {
    List<int> list;
    CHECK_THROWS_AS(list.front(), std::underflow_error);
}

TEST_CASE("Pop back removes items from list and updates length") {
    List<int> list;
    list.push_front(5);
    list.push_front(10);
    list.push_front(15);
    list.push_front(20);
    // 20, 15, 10, 5
    REQUIRE(list.size() == 4);
    list.pop_front();
    list.pop_front();
    // expect 10, 5
    REQUIRE(list.front() == 10);
    REQUIRE(list.size() == 2);
}

TEST_CASE("Calling pop_front on an empty list throws") {
    List<int> list;
    CHECK_THROWS_AS(list.pop_front(), std::underflow_error);
}

TEST_CASE("Clear should remove all elements") {
    List<int> list;
    list.push_front(5);
    list.push_front(10);
    list.push_front(15);
    list.push_front(20);
    list.clear();
    REQUIRE(list.size() == 0);
    REQUIRE(list.is_empty() == true);
}

/////////////////////////////////////////////////////////
// Destructor test
/////////////////////////////////////////////////////////
// The following test is designed to ensure that the 
// destructor of each node is always called when a List
// goes out of scope.  This is tricky though... we need
// to introduce a "spy", an object that can keep track 
// of of how many times destructors are called.
class Spy {
    public:
        Spy() {
            // Spy is a useless object, it's just a placeholder
            // with destructor counting.
        }
        ~Spy() {
            Spy::destructor_count++;
        }
        
        static int destructor_count;
};

// Initialize the static counter.
int Spy::destructor_count = 0;

// We will call this function inside our test.
// Remember, we know List's destructor will be called, 
// there is no need to test whether C++ is correct.
// What we are worried about is if the destructor
// of the ELEMENT is called.
void dummy_function() {
    List<Spy> spies;
    spies.push_front(Spy());
    spies.push_front(Spy());
    return;
}

TEST_CASE("Destructor should be called on all nodes") {

    dummy_function();

    // Dummy function inserts two spies, so why do we expect
    // that the destructor would get called 6 times?
    REQUIRE(Spy::destructor_count == 6);
    // - Each spy object is constructed and passed BY COPY inside
    //   dummy function to push_front, these objects get destructed as soon
    //   as the call is completed (2).
    // - Inside push_front, we pass the "data" by copy to the node constructor, 
    //   and when push_front returns, the objects passed to it (by copy) are 
    //   destructed (4).
    // - Finally, when the list of spies goes out of scope, 
    //   list deletes each spy - hopefully (6).

    // Note, we could have also put a static counter in the node class, and
    // had the node's destructor decrement the counter.  This would allow
    // us to test without a fake spy object - but it's not a good idea, since
    // that would mean our list nodes would always carry this overhead in 
    // real actual programs...

    // As an exercise, see if you can build a test case that
    // proves that the destructor of the node is always called
    // when pop_front, pop_back, and remove are called.  Hint, re-use
    // the same Spy class - but reset the static counter to keep things
    // simple in your test cases.
}


TEST_CASE("Push back inserts at end and updates length") {
    List<int> list;
    list.push_front(5);
    list.push_front(10);
    list.push_front(15);
    list.push_front(20);
    // 20, 15, 10, 5
    list.push_back(25);
    list.push_back(30);
    // 20, 15, 10, 6, 25, 30
    REQUIRE(list.size() == 6);
}

TEST_CASE("Pop back can't be called on an empty list") {
    List<int> list;
    CHECK_THROWS_AS(list.pop_back(), std::underflow_error);
}

TEST_CASE("Back returns the last element, and cannot be called on empty list") {
    List<int> list;
    CHECK_THROWS_AS(list.back(), std::underflow_error);
    list.push_front(5);
    list.push_front(10);
    list.push_front(15);
    list.push_front(20);
    // 20, 15, 10, 5
    list.push_back(25);
    list.push_back(30);
    // 20, 15, 10, 6, 25, 30
    REQUIRE(list.back() == 30);
}

TEST_CASE("Pop back removes the end of the list and updates length") {
    List<int> list;
    list.push_front(5);
    list.push_front(10);
    list.push_front(15);
    list.push_front(20);
    // 20, 15, 10, 5
    list.pop_back();
    REQUIRE(list.size() == 3);
    REQUIRE(list.back() == 10);

    list.pop_back();
    REQUIRE(list.size() == 2);
    REQUIRE(list.back() == 15);
}

TEST_CASE("Push back can insert into empty list") {
    List<int> list;
    list.push_back(5);
    REQUIRE(list.size() == 1);
    REQUIRE(list.back() == 5);
}

TEST_CASE("Pop front handles list with one element well."){
    List<int> list;
    list.push_front(5);
    list.pop_front();
    REQUIRE(list.is_empty() == true);
    REQUIRE(list.size() == 0);
}
TEST_CASE("Pop back handles list with one element well."){
    List<int> list;
    list.push_front(5);
    list.pop_back();
    REQUIRE(list.is_empty() == true);
    REQUIRE(list.size() == 0);
}

// When you are building a template class, ALWAYS test with at least
// another data type to ensure that the template has been constructed
// correctly.  It's easy to miss a T and replace it with int!