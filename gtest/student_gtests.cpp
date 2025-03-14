#include <gtest/gtest.h>

#include "dijkstras.h"
// #include "ladder.h"

// TEST(Replace, Me) {
  
// }

TEST(Dijsktras, shortest_path) {
  Graph G;
  file_to_graph("src/largest.txt", G);
  vector<int> previous0(G.numVertices, -1);
  vector<int> distances0 = dijkstra_shortest_path(G, 0, previous0);
  EXPECT_EQ(distances0, "");
}
