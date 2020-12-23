//
// Created by xuyc on 2020/12/23.
//

#include "dfs.h"

DepthFirstSearch::DepthFirstSearch(const Graph& G, int s) {
    _marked = new bool [G.V()];
    for (size_t i = 0; i < G.V(); i++) _marked[i] = false;
    _count = 0;
    _dfs(G, s);
}

DepthFirstSearch::~DepthFirstSearch() {
    delete _marked;
}

void DepthFirstSearch::_dfs(const Graph& G, int v) {
    _marked[v] = true;
    _count++;
    auto ajdIterator = G.adj(v);
    for (auto it = ajdIterator->cbegin(); it != ajdIterator->cend(); it++)
        if (!_marked[*it]) _dfs(G, *it);
    delete ajdIterator;
}

bool DepthFirstSearch::marked(int v) {
    return _marked[v];
}

int DepthFirstSearch::count() const {
    return _count;
}
