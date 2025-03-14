#include "dijkstras.h"
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous) {
    int n = G.numVertices;

    vector<int> distance(n, INF);
    distance[source] = 0;
    vector<bool> visited(n, false);

    previous.assign(n, -1);

    priority_queue<pair<int, int>> pq;
    pq.push({source, 0});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if (visited[u] == true) {
            continue;
        }
        visited[u] = true;
        for (Edge neighbor : G[u]) {
            int v = neighbor.dst;
            int weight = neighbor.weight;
            if (!visited[v] && distance[u] + weight < distance[v] && distance[u] != INF) {
                distance[v] = distance[u] + weight;
                previous[v] = u;
                pq.push({v, distance[v]});
            }
        }
    }
    return distance;
}

vector<int> extract_shortest_path(const vector<int>& distances, const vector<int>& previous, int destination) {
    vector<int> shortest_path;
    for (int idx = destination; idx != -1; idx = previous[idx]) {
        shortest_path.push_back(idx);
    }
    if (shortest_path.empty() != false) {
        reverse(shortest_path.begin(), shortest_path.end());
    }
    return shortest_path;
}

void print_path(const vector<int>& v, int total) {
    for(int idx = 0; idx < v.size(); idx++) {
        cout << v[idx] << " ";
    }
    cout << endl;
    cout << "Total cost is " << total << endl;
}
