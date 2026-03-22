// scheduler.cpp
// Purpose: Adaptive priority-based traffic signal scheduling with starvation aging
// Module: 3

#include "scheduler.h"
#include <algorithm>
using namespace std;

int Scheduler::calculatePriority(Lane& lane) {
    return (2 * lane.vehicleCount) + (3 * lane.waitingTime) + (1 * lane.roadWidth);
}

void Scheduler::applyAgingIfNeeded(Lane& lane) {
    if (lane.waitingTime > 30) {
        lane.priority += 20;
        cout << "  [AGING BOOST] " << lane.name
             << " waiting too long (" << lane.waitingTime
             << "s > 30s) -> priority +20" << endl;
    }
}

void Scheduler::runScheduler(vector<Lane>& lanes, int cycles) {
    cout << "\n========= ADAPTIVE SCHEDULER =========" << endl;

    for (int cycle = 1; cycle <= cycles; cycle++) {
        cout << "\n--- Cycle " << cycle << " ---" << endl;

        // Recalculate priority for all lanes
        for (Lane& lane : lanes) {
            lane.priority = calculatePriority(lane);
        }

        // Apply aging to all lanes
        for (Lane& lane : lanes) {
            applyAgingIfNeeded(lane);
        }

        // Push all lanes into max-heap priority queue
        priority_queue<Lane> pq;
        for (Lane& lane : lanes) {
            pq.push(lane);
        }

        // Top of heap = green signal lane
        Lane greenLane = pq.top();

        cout << "  GREEN SIGNAL  --> " << greenLane.name << endl;
        cout << "  Vehicle Count : " << greenLane.vehicleCount << endl;
        cout << "  Waiting Time  : " << greenLane.waitingTime << " sec" << endl;
        cout << "  Road Width    : " << greenLane.roadWidth << " lanes" << endl;
        cout << "  Priority Score: " << greenLane.priority << endl;

        // Update lanes after green signal
        for (Lane& lane : lanes) {
            if (lane.id == greenLane.id) {
                // Green lane: reduce vehicles, reset waiting time
                lane.vehicleCount = max(0, lane.vehicleCount - 5);
                lane.waitingTime = 0;
            } else {
                // All other lanes keep waiting
                lane.waitingTime += 10;
            }
        }
    }

    cout << "\n======================================" << endl;
}
