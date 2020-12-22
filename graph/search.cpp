//
// Created by 徐元昌 on 2020/12/22.
//

#include "graph.h"
#include "search.h"

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

BreadthFirstSearch::BreadthFirstSearch(const Graph &g, int s) {
    _queue = std::queue<int>();
    _count = 0;
    _marked = new bool[g.V()];
    _bfs(g, s);
}

BreadthFirstSearch::~BreadthFirstSearch() {
    delete _marked;
}


void BreadthFirstSearch::_bfs(const Graph &G, int v) {
    _marked[v] = true;
    _queue.push(v);
    _count++;
    while (!_queue.empty()) {
        v = _queue.front();
        _queue.pop();
        auto ajdIt = G.adj(v);
        for (auto it = ajdIt->cbegin(); it != ajdIt->cend(); it++) {
            if  (!_marked[*it]) {
                _queue.push(*it);
                _count++;
                _marked[*it] = true;
            }
        }
        delete ajdIt;
    }
}

bool BreadthFirstSearch::marked(int v) {
    return _marked[v];
}