// scheduler.h
// Purpose: Adaptive priority-based traffic signal scheduling with aging
// Module: 3

#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

struct Lane {
    int id;
    string name;
    int vehicleCount;
    int waitingTime;
    int roadWidth;
    int priority;
    bool operator<(const Lane& other) const {
        return priority < other.priority;
    }
};

class Scheduler {
public:
    int calculatePriority(Lane& lane);
    void applyAgingIfNeeded(Lane& lane);
    void runScheduler(vector<Lane>& lanes, int cycles);
};

#endif // SCHEDULER_H
