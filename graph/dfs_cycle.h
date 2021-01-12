//
// Created by xuyc on 2020/12/24.
//

#ifndef ALGS4_CPP_DFS_CYCLE_H
#define ALGS4_CPP_DFS_CYCLE_H

#include "graph.h"
#include <vector>

class DepthFirstSearchCycle {
public:
    DepthFirstSearchCycle(const Graph &g);
    bool hasCycle();
    int cycleCount();

private:
    void _dfs(int v, int prev);
    int _cycleCount;
    bool _hasCycle;
    std::vector<bool> _marked;
    const Graph & _g;
};


#endif //ALGS4_CPP_DFS_CYCLE_H
