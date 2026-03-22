// graph.h
// Purpose: Graph data structure for road network (junctions and roads)
// Module: 1

#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

struct Junction {
    int id;
    string name;
};

struct Road {
    int to;
    int distance;
    int width;
};

class Graph {
public:
    void addJunction(int id, string name);
    void addRoad(int from, int to, int distance, int width);
    void display();
    vector<Road>& getNeighbors(int id);
    int getNumJunctions();
    string getJunctionName(int id);

private:
    vector<Junction> junctions;
    unordered_map<int, vector<Road>> adjList;
};

#endif // GRAPH_H
