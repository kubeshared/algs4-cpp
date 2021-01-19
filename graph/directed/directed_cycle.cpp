//
// Created by xuyc on 2021/1/19.
//

#include "directed_cycle.h"

DirectedCycle::DirectedCycle(const Digraph &G) {
    marked = new bool[G.V()];
    onStack = new bool[G.V()];
    edgeTo = new int[G.V()];
    for (int i = 0; i < G.V(); i++) {
        marked[i] = false;
        onStack[i] = false;
        edgeTo[i] = 0;
    }

    for (int s = 0; s < G.V(); s++) {
        if (!marked[s]) {
            dfs(G, s);
        }
    }
}

DirectedCycle::~DirectedCycle() {
    delete[]marked;
    delete[]onStack;
    delete[]edgeTo;
}

bool DirectedCycle::hasCycle() const {
    return !cycleStack.empty();
}

vector<int> DirectedCycle::cycle() const {
    vector<int> cycles;
    copy(cycleStack.cbegin(), cycleStack.cend(),
         back_inserter(cycles));
    return cycles;
}

void DirectedCycle::dfs(const Digraph &G, int s) {
    marked[s] = true;
    // The onStack[s]=true means is the s on the system call stack.
    onStack[s] = true;
    AdjacencyIterator adjIt = G.adj(s);
    while (adjIt.hasNext()) {
        if (hasCycle())
            return;
        int v = adjIt.next();
        if (!marked[v]) {
            edgeTo[v] = s;
            dfs(G, v);
        } else if (onStack[v]) {
            // s -> v -> w -> v
            for (int x = s; x != v; x = edgeTo[x]) {
                cycleStack.push_back(x);
            }
            cycleStack.push_back(v);
            cycleStack.push_back(s);
        }
    }
    // THe onStack[s]=false means is the s leave the system call stack.
    onStack[s] = false;
}