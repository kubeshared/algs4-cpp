//
// Created by xuyc on 2020/12/24.
//

#include "bfs_cycle.h"

BreadthFirstSearchCycle::BreadthFirstSearchCycle(const Graph &g) {
    _marked = std::vector<bool> (g.V(), false);
    _hasCycle = false;
}

void BreadthFirstSearchCycle::_bfs(const Graph &g, int v) {
    auto q = std::queue<int>();
    _marked[v] = true;
    q.push(v);
    while (!q.empty()) {
        v = q.front();
        auto adj = g.adj(v);
        for (auto it = adj->cbegin(); it != adj->cend(); it++) {
            if (!_marked[*it]) {
                q.push(*it);
                _marked[*it] = true;
            }
        }
        delete adj;
        q.pop();
    }
}