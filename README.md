# Adaptive Traffic Signal Optimization
### Team Syntax | DAA Project

## Team
- Daksh Baurai (Lead) — 2419310
- Sandeep Singh — 2418904
- Rishabh Joshi — 2418833
- Arun Singh Chauhan — 2418348

## Compile & Run
```
g++ src/*.cpp -o traffic
./traffic
```

## Modules
| Module | File | Status |
|--------|------|--------|
| Graph Builder | graph.h/cpp | Done |
| Dijkstra | dijkstra.h/cpp | Done |
| Scheduler | scheduler.h/cpp | Done |
| Emergency | emergency.h/cpp | Done |
| Baseline | baseline.h/cpp | Done |

## Algorithms
- Dijkstra: O(E log V) time, O(V+E) space
- Greedy Scheduler: O(n log n) per cycle
- Aging: O(n) per cycle
