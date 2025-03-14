#include "dijkstras.h"
#include <iostream>

int main() {
    Graph G;
    file_to_graph("src/largest.txt", G);
    vector<int> previous(G.numVertices, -1);
    vector<int> distances = dijkstra_shortest_path(G, 4, previous);
    vector<int> shortest_path = extract_shortest_path(distances, previous, 1);
    print_path(shortest_path, distances[1]);
    return 0;
}
