// baseline.cpp
// Purpose: Fixed-time round-robin baseline scheduler for comparison
// Module: 5

#include "baseline.h"

void Baseline::runBaseline(vector<Lane>& lanes, int cycles) {
    cout << "\n========= BASELINE FIXED-TIME SCHEDULER =========" << endl;
    int lanesCount = (int)lanes.size();
    int fixedGreenTime = 30; // fixed seconds per lane

    for (int cycle = 1; cycle <= cycles; cycle++) {
        int laneIndex = (cycle - 1) % lanesCount;
        Lane& lane = lanes[laneIndex];

        cout << "\n--- Cycle " << cycle << " ---" << endl;
        cout << "  GREEN SIGNAL  --> " << lane.name << endl;
        cout << "  Fixed Time    : " << fixedGreenTime << " sec" << endl;
        cout << "  (No priority, no aging, no adaptive control)" << endl;
    }

    double avgWait = calculateAverageWait(lanes, cycles);
    cout << "\n  Average Waiting Time (Baseline): " << avgWait << " sec" << endl;
    cout << "==================================================" << endl;
}

double Baseline::calculateAverageWait(vector<Lane>& lanes, int cycles) {
    int lanesCount = (int)lanes.size();
    // Fixed formula: ((cycles / lanesCount) * 30) / 2
    return ((double)cycles / lanesCount * 30.0) / 2.0;
}
