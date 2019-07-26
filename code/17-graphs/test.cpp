#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "graph.h"
#include <string>
using namespace std;

void initialize(Graph<string> &cities)
{
    cities.add_vertex("Denver");
    cities.add_vertex("Chicago");
    cities.add_vertex("Washington");
    cities.add_vertex("Dallas");
    cities.add_vertex("Austin");
    cities.add_vertex("Atlanta");
    cities.add_vertex("Houston");

    cities.add_edge("Denver", "Chicago", 1000);    // 0 -> 1
    cities.add_edge("Dallas", "Chicago", 900);     // 3 -> 1
    cities.add_edge("Washington", "Dallas", 1300); // 2 -> 3
    cities.add_edge("Washington", "Atlanta", 600); // 2 -> 5
    cities.add_edge("Atlanta", "Washington", 600); // 2 -> 5
    cities.add_edge("Denver", "Atlanta", 1400);    // 0 -> 5
    cities.add_edge("Dallas", "Denver", 780);      // 3 -> 0
    cities.add_edge("Dallas", "Austin", 200);      // 3 -> 4
    cities.add_edge("Austin", "Dallas", 200);
    cities.add_edge("Austin", "Houston", 160);  // 4 -> 6
    cities.add_edge("Atlanta", "Houston", 800); // 5 -> 6
    cities.add_edge("Houston", "Atlanta", 800);
}

TEST_CASE("Create graph, vertices, edges")
{
    Graph<string> cities;
    initialize(cities);
    REQUIRE(cities.get_edge("Denver", "Atlanta") == 1400);
}

TEST_CASE("Adjacency")
{

    Graph<string> cities;
    initialize(cities);
    REQUIRE(cities.adjacent("Denver").size() == 2);
    REQUIRE(cities.adjacent("Dallas").size() == 3);
}

TEST_CASE("Depth-first path finding")
{
    Graph<string> cities;
    initialize(cities);
    REQUIRE(cities.depth_first("Washington", "Houston"));
    REQUIRE(cities.depth_first("Houston", "Austin"));
    REQUIRE(cities.depth_first("Chicago", "Austin") == false);
}
TEST_CASE("Breadth-first path finding")
{
    Graph<string> cities;
    initialize(cities);
    REQUIRE(cities.breadth_first("Washington", "Houston"));
    REQUIRE(cities.breadth_first("Houston", "Austin"));
    REQUIRE(cities.breadth_first("Chicago", "Austin") == false);
}
