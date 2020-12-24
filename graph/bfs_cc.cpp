//
// Created by xuyc on 2020/12/24.
//

#include "bfs_cc.h"

BreadthFirstSearchCC::BreadthFirstSearchCC(const Graph &g) : _g(g) {
    _marked = std::vector<bool>(g.V(), false);
    _count = std::vector<int>(g.V(), 0);
    _ccCount = 0;
    for (auto i = 0; i < g.V(); i++) {
        if (!_marked[i]) {
            _bfs(i, _ccCount++);
        }
    }
}

void BreadthFirstSearchCC::_bfs(int v, int cc) {
    _marked[v] = true;
    _count[v] = cc;
    auto q = std::queue<int>();
    q.push(v);
    while (!q.empty()) {
        v = q.front();
        auto adjIt = _g.adj(v);
        for (auto it = adjIt->cbegin(); it != adjIt->cend(); it++) {
            if (!_marked[*it]) {
                _marked[*it] = true;
                _count[*it] = cc;
                q.push(*it);
            }
        }
        delete adjIt;
        q.pop();
    }
}

bool BreadthFirstSearchCC::connected(int s, int v) {
    assert(s >= 0 && s <= _g.V());
    assert(v >= 0 && v <= _g.V());

    return _count[s] == _count[v];
}

int BreadthFirstSearchCC::count() {
    return _ccCount;
}

int BreadthFirstSearchCC::id(int v) {
    assert(v >= 0 && v <= _g.V());
    return _count[v];
}