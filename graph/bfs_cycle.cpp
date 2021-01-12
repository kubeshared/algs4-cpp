//
// Created by xuyc on 2020/12/24.
//

#include "bfs_cycle.h"

BreadthFirstSearchCycle::BreadthFirstSearchCycle(const Graph &g) {
    _marked = std::vector<bool> (g.V(), false);
    _parent = std::vector<int> (g.V(), 0);
    _hasCycle = false;
    for (auto x = 0; x < g.V(); x++)
        if (!_marked[x])
            _bfs(g, x);
}

void BreadthFirstSearchCycle::_bfs(const Graph &g, int v) {
    auto q = std::queue<int>();
    _marked[v] = true;
    q.push(v);
    while (!q.empty()) {
        v = q.front();
        q.pop();
        auto adj = g.adj(v);
        for (auto it = adj->cbegin(); it != adj->cend(); it++) {
            if (!_marked[*it]) {
                q.push(*it);
                _marked[*it] = true;
                _parent[*it] = v;
            } else {
                if (*it != _parent[v]) {
                    _hasCycle = true;
                }
            }
        }
        delete adj;
        
    }
}

bool BreadthFirstSearchCycle::hasCycle() {
    return _hasCycle;
}
