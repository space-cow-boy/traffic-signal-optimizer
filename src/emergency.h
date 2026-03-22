// emergency.h
// Purpose: Emergency vehicle preemption using Dijkstra shortest path
// Module: 4

#ifndef EMERGENCY_H
#define EMERGENCY_H

#include <iostream>
#include "graph.h"
#include "dijkstra.h"
using namespace std;

class Emergency {
public:
    void triggerEmergency(Graph& g, Dijkstra& d, int src, int dest, int totalJunctions);
};

#endif // EMERGENCY_H
