//
// Created by xuyc on 2021/1/19.
//

#ifndef ALGS4_DIRECTED_CYCLE_H
#define ALGS4_DIRECTED_CYCLE_H

#include "digraph.h"
#include <stack>
#include <queue>
#include <algorithm>
class DirectedCycle {
public:
    DirectedCycle(const Digraph& G);
    ~DirectedCycle();
    bool hasCycle() const;
    vector<int> cycle() const;
private:
    void dfs(const Digraph& G, int s);
    bool *marked;
    bool *onStack;
    int *edgeTo;
    deque<int> cycleStack;
};


#endif //ALGS4_DIRECTED_CYCLE_H
