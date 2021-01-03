//
// Created by 徐元昌 on 2020/12/23.
//

#include "dfs_cc.h"


DepthFirstSearchCC::DepthFirstSearchCC(const Graph &g) :_g(g) {
     _count = std::vector<int>(g.V());
     _marked = std::vector<bool>(g.V(), false);
    _ccCount = 0;
     for (auto i = 0; i < g.V(); i++) {
         if (!_marked[i]) {
             _dfs(i, _ccCount++);
         }
     }
}

void DepthFirstSearchCC::_dfs(int v, int cc) {
    _marked[v] = true;
    _count[v] = cc;
    auto adjIt = _g.adj(v);
    for (auto it = adjIt->cbegin(); it != adjIt->cend(); it++) {
        if (!_marked[*it]) _dfs(*it, cc);
    }
    delete adjIt;
}

bool DepthFirstSearchCC::connected(int s, int v) {
    assert(s >= 0 && s <= _g.V());
    assert(v >= 0 && v <= _g.V());
    return _count[s] == _count[v];
}

int DepthFirstSearchCC::count() {
    return _ccCount;
}

int DepthFirstSearchCC::id(int v) {
    assert(v >= 0 && v <= _g.V());
    return _count[v];
}