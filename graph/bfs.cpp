//
// Created by xuyc on 2020/12/23.
//

#include "bfs.h"
BreadthFirstSearch::BreadthFirstSearch(const GraphInterface &g, int s) : _g(g), _s(s) {
    _queue = std::queue<int>();
    _count = 0;
    _marked = new bool[g.V()];
    _bfs(g, s);
}

BreadthFirstSearch::~BreadthFirstSearch() {
    delete _marked;
}

void BreadthFirstSearch::_bfs(const GraphInterface &G, int s) {
    _marked[s] = true;
    _queue.push(s);
    _count++;
    _edgeTo = std::vector<int>(G.V());
    while (!_queue.empty()) {
        int v = _queue.front();
        auto ajdIt = G.adj(v);
        for (auto it = ajdIt->cbegin(); it != ajdIt->cend(); it++) {
            if (!_marked[*it]) {
                _queue.push(*it);
                _count++;
                _marked[*it] = true;
                _edgeTo[*it] = v;
            }
        }
        _queue.pop();
    }
}

bool BreadthFirstSearch::marked(int v) {
    return _marked[v];
}

int BreadthFirstSearch::count() const {
    return _count;
}

bool BreadthFirstSearch::hasPathTo(int v) {
    return _edgeTo[v] != 0;
}

std::stack<int> *BreadthFirstSearch::pathTo(int v) {
    assert(v >= 0 && v <= _g.V());
    auto *s = new std::stack<int>();
    for (auto x = v; x != _s; x = _edgeTo[x]) {
        s->push(x);
    }
    s->push(_s);
    return s;
}

// Bacon, Kevin
// Kidman, Nicole