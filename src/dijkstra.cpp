// dijkstra.cpp
// Purpose: Implementation of Dijkstra's shortest path algorithm
// Module: 2

#include "dijkstra.h"
#include <iostream>
using namespace std;

vector<int> Dijkstra::findShortestPath(Graph& g, int src, int dest, int totalJunctions) {
    vector<int> dist(totalJunctions, INT_MAX);
    vector<int> parent(totalJunctions, -1);

    // Min-heap: (distance, vertex)
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int distance = pq.top().first;
        int vertex = pq.top().second;
        pq.pop();

        for (Road& adjNode : g.getNeighbors(vertex)) {
            int adjVertex = adjNode.to;
            int adjWeight = adjNode.distance;
            int d = distance + adjWeight;

            if (d < dist[adjVertex]) {
                dist[adjVertex] = d;
                parent[adjVertex] = vertex;
                pq.push({d, adjVertex});
            }
        }
    }

    // Build path by tracing parent[] from dest to src
    vector<int> path;
    int at = dest;
    while (at != -1) {
        path.insert(path.begin(), at);
        at = parent[at];
    }

    // If path[0] != src, destination is unreachable
    if (path.empty() || path[0] != src) {
        path.clear();
    }

    return path;
}

void Dijkstra::printPath(Graph& g, vector<int>& path) {
    if (path.empty()) {
        cout << "No path found" << endl;
        return;
    }
    cout << "Shortest Path: ";
    for (int i = 0; i < (int)path.size(); i++) {
        cout << g.getJunctionName(path[i]);
        if (i != (int)path.size() - 1) cout << " --> ";
    }
    cout << endl;
}
