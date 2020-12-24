//
// Created by xuyc on 2020/12/24.
//

#include "dfs_cycle.h"

DepthFirstSearchCycle::DepthFirstSearchCycle(const Graph &g) :_g(g){
    _marked = std::vector<bool>(g.V(), false);
    _hasCycle = false;
    _cycleCount = 0;
    for(auto i = 0; i < g.V(); i++) {
        if (!_marked[i]) {
            _dfs(i, i);
        }
    }
}

void DepthFirstSearchCycle::_dfs(int v, int prev) {
    _marked[v] = true;
    auto adj = _g.adj(v);
    for (auto it = adj->cbegin(); it != adj->cend(); it++) {
        if (!_marked[*it]) {
            _dfs(*it, v);
            // the adjacent edge of the current vertex v is not the previous vertex
            // and returns to the marked vertex through v, so the graph has cycle.
        } else if (*it != prev) {
            _hasCycle = true;
            _cycleCount++;
        }
    }
    delete adj;
}

bool DepthFirstSearchCycle::hasCycle() {
    return _hasCycle;
}

int DepthFirstSearchCycle::cycleCount() {
    return _cycleCount;
}