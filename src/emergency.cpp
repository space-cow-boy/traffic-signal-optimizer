// emergency.cpp
// Purpose: Emergency vehicle preemption - overrides signals using Dijkstra path
// Module: 4

#include "emergency.h"

void Emergency::triggerEmergency(Graph& g, Dijkstra& d, int src, int dest, int totalJunctions) {
    cout << "\n=========================================" << endl;
    cout << "  *** EMERGENCY VEHICLE DETECTED ***" << endl;
    cout << "=========================================" << endl;

    cout << "  From: " << g.getJunctionName(src)
         << "  To: " << g.getJunctionName(dest) << endl;

    vector<int> path = d.findShortestPath(g, src, dest, totalJunctions);
    d.printPath(g, path);

    if (!path.empty()) {
        cout << "\n  Signals on path overridden to GREEN:" << endl;
        for (int junctionId : path) {
            cout << "    " << g.getJunctionName(junctionId) << " --> GREEN" << endl;
        }
    }

    cout << "\n  Normal scheduling will resume after clearance" << endl;
    cout << "=========================================" << endl;
}
