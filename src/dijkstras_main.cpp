#include "dijkstras.h"
#include <iostream>

int main() {
    Graph G;
    file_to_graph("src/largest.txt", G);
    vector<int> previous0(G.numVertices, -1);
    vector<int> distances0 = dijkstra_shortest_path(G, 0, previous0);
    vector<int> shortest_path0 = extract_shortest_path(distances0, previous0, 1);
    print_path(shortest_path0, distances0[1]);

    vector<int> previous1(G.numVertices, -1);
    vector<int> distances1 = dijkstra_shortest_path(G, 1, previous1);
    vector<int> shortest_path1 = extract_shortest_path(distances1, previous1, 1);
    print_path(shortest_path1, distances1[1]);

    vector<int> previous2(G.numVertices, -1);
    vector<int> distances2 = dijkstra_shortest_path(G, 2, previous2);
    vector<int> shortest_path2 = extract_shortest_path(distances2, previous2, 1);
    print_path(shortest_path2, distances2[1]);

    vector<int> previous3(G.numVertices, -1);
    vector<int> distances3 = dijkstra_shortest_path(G, 3, previous3);
    vector<int> shortest_path3 = extract_shortest_path(distances3, previous3, 1);
    print_path(shortest_path3, distances3[1]);

    vector<int> previous4(G.numVertices, -1);
    vector<int> distances4 = dijkstra_shortest_path(G, 4, previous2);
    vector<int> shortest_path4 = extract_shortest_path(distances4, previous4, 1);
    print_path(shortest_path4, distances4[1]);

    vector<int> previous5(G.numVertices, -1);
    vector<int> distances5 = dijkstra_shortest_path(G, 5, previous5);
    vector<int> shortest_path5 = extract_shortest_path(distances5, previous5, 1);
    print_path(shortest_path5, distances5[1]);
    
    return 0;
}
