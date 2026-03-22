// baseline.h
// Purpose: Fixed-time round-robin baseline scheduler for performance comparison
// Module: 5

#ifndef BASELINE_H
#define BASELINE_H

#include <iostream>
#include <vector>
#include "scheduler.h"
using namespace std;

class Baseline {
public:
    void runBaseline(vector<Lane>& lanes, int cycles);
    double calculateAverageWait(vector<Lane>& lanes, int cycles);
};

#endif // BASELINE_H
