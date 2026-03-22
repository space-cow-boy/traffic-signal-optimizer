// graph.cpp
// Purpose: Implementation of Graph class for road network
// Module: 1

#include "graph.h"

void Graph::addJunction(int id, string name) {
    Junction j;
    j.id = id;
    j.name = name;
    junctions.push_back(j);
    adjList[id]; // initialize empty adjacency list
}

void Graph::addRoad(int from, int to, int distance, int width) {
    Road r1;
    r1.to = to;
    r1.distance = distance;
    r1.width = width;
    adjList[from].push_back(r1);

    Road r2;
    r2.to = from;
    r2.distance = distance;
    r2.width = width;
    adjList[to].push_back(r2);
}

void Graph::display() {
    cout << "========= ROAD NETWORK GRAPH =========" << endl;
    for (Junction& j : junctions) {
        cout << "Junction " << j.id << " [" << j.name << "] connects to:" << endl;
        for (Road& r : adjList[j.id]) {
            string neighborName = getJunctionName(r.to);
            cout << "   --> Junction " << r.to << " [" << neighborName << "]"
                 << " | Distance: " << r.distance << " km"
                 << " | Width: " << r.width << " lanes" << endl;
        }
    }
    cout << "======================================" << endl;
}

vector<Road>& Graph::getNeighbors(int id) {
    return adjList[id];
}

int Graph::getNumJunctions() {
    return (int)junctions.size();
}

string Graph::getJunctionName(int id) {
    for (Junction& j : junctions) {
        if (j.id == id) return j.name;
    }
    return "Unknown";
}
