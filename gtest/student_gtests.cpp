#include <gtest/gtest.h>
#include "dijkstras.h"
#include <vector>
#include "ladder.h"

using namespace std;

TEST(Dijsktras, test1) {
  Graph G;
  file_to_graph("src/large.txt", G);
  vector<int> previous(G.numVertices, -1);
  vector<int> distances = dijkstra_shortest_path(G, 0, previous);
  vector<int> expected = {0, 7, 15, 5, 14, 11, 12};
  EXPECT_EQ(distances, expected);

  vector<int> shortest_path = extract_shortest_path(distances, previous, 1);
  vector<int> expected_path = {0, 1};
  EXPECT_EQ(shortest_path, expected_path);

  int total = distances[1];
  EXPECT_EQ(total, 7);
}

TEST(Dijsktras, test2) {
  Graph G;
  file_to_graph("src/large.txt", G);
  vector<int> previous(G.numVertices, -1);
  vector<int> distances = dijkstra_shortest_path(G, 1, previous);
  vector<int> expected = {2147483647, 0, 8, 9, 7, 15, 16};
  EXPECT_EQ(distances, expected);

  vector<int> shortest_path = extract_shortest_path(distances, previous, 1);
  vector<int> expected_path = {1};
  EXPECT_EQ(shortest_path, expected_path);

  int total = distances[1];
  EXPECT_EQ(total, 0);
}

TEST(Dijsktras, test3) {
  Graph G;
  file_to_graph("src/large.txt", G);
  vector<int> previous(G.numVertices, -1);
  vector<int> distances = dijkstra_shortest_path(G, 2, previous);
  vector<int> expected = {2147483647, 2147483647, 0, 2147483647, 5, 13, 14};
  EXPECT_EQ(distances, expected);

  vector<int> shortest_path = extract_shortest_path(distances, previous, 1);
  vector<int> expected_path = {1};
  EXPECT_EQ(shortest_path, expected_path);

  int total = distances[1];
  EXPECT_EQ(total, 2147483647);
}

TEST(Dijsktras, test4) {
  Graph G;
  file_to_graph("src/large.txt", G);
  vector<int> previous(G.numVertices, -1);
  vector<int> distances = dijkstra_shortest_path(G, 3, previous);
  vector<int> expected = {2147483647, 2147483647, 2147483647, 0, 15, 6, 7};
  EXPECT_EQ(distances, expected);

  vector<int> shortest_path = extract_shortest_path(distances, previous, 1);
  vector<int> expected_path = {1};
  EXPECT_EQ(shortest_path, expected_path);

  int total = distances[1];
  EXPECT_EQ(total, 2147483647);
}

TEST(Dijsktras, test5) {
  Graph G;
  file_to_graph("src/large.txt", G);
  vector<int> previous(G.numVertices, -1);
  vector<int> distances = dijkstra_shortest_path(G, 4, previous);
  vector<int> expected = {2147483647, 2147483647, 2147483647, 2147483647, 0, 8, 9};
  EXPECT_EQ(distances, expected);

  vector<int> shortest_path = extract_shortest_path(distances, previous, 1);
  vector<int> expected_path = {1};
  EXPECT_EQ(shortest_path, expected_path);

  int total = distances[1];
  EXPECT_EQ(total, 2147483647);
}

TEST(Ladder, edit_distance_within_test_true) {
  EXPECT_EQ(edit_distance_within("car", "bar", 1), true);

  EXPECT_EQ(edit_distance_within("tee", "the", 1), true);

  EXPECT_EQ(edit_distance_within("crap", "wrap", 1), true);

  EXPECT_EQ(edit_distance_within("theirs", "the", 3), true);

  EXPECT_EQ(edit_distance_within("their", "the", 2), true);

  EXPECT_EQ(edit_distance_within("thee", "the", 1), true);

  EXPECT_EQ(edit_distance_within("rat", "rate", 1), true);

  EXPECT_EQ(edit_distance_within("mate", "ate", 1), true);
}

TEST(Ladder, edit_distance_within_test_false) {
  EXPECT_EQ(edit_distance_within("mark", "bar", 1), false);

  EXPECT_EQ(edit_distance_within("tear", "the", 1), false);

  EXPECT_EQ(edit_distance_within("crap", "wear", 1), false);

  EXPECT_EQ(edit_distance_within("theirs", "car", 1), false);

  EXPECT_EQ(edit_distance_within("war", "fare", 1), false);

  EXPECT_EQ(edit_distance_within("cat", "dog", 1), false);

  EXPECT_EQ(edit_distance_within("fabulous", "rate", 1), false);

  EXPECT_EQ(edit_distance_within("mate", "fart", 1), false);
}

TEST(Ladder, generate_word_ladder) {
  set<string> word_list;
  load_words(word_list, "src/words.txt");

  vector<string> result = generate_word_ladder("car", "dog", word_list);
  vector<string> expected = { "car", "bar", "bag", "bog", "dog" };
  EXPECT_EQ(result.size(), 5);
  EXPECT_EQ(result, expected);

  result = generate_word_ladder("car", "that", word_list);
  expected = {"car", "cat", "chat", "that"};
  EXPECT_EQ(result.size(), 4);
  EXPECT_EQ(result, expected);

  result = generate_word_ladder("fart", "that", word_list);
  expected = {"fart", "fat", "hat", "that"};
  EXPECT_EQ(result.size(), 4);
  EXPECT_EQ(result, expected);

  result = generate_word_ladder("care", "their", word_list);
  expected = {"care", "car", "ear", "hear", "heir", "their"};
  EXPECT_EQ(result.size(), 6);
  EXPECT_EQ(result, expected);
}