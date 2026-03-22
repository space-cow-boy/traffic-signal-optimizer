// dijkstra.h
// Purpose: Shortest path computation using Dijkstra's algorithm
// Module: 2

#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <vector>
#include <queue>
#include <climits>
#include "graph.h"
using namespace std;

class Dijkstra {
public:
    vector<int> findShortestPath(Graph& g, int src, int dest, int totalJunctions);
    void printPath(Graph& g, vector<int>& path);
};

#endif // DIJKSTRA_H
