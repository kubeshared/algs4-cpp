//
// Created by 徐元昌 on 2020/12/22.
//

#include "graph.h"

GraphAdjIterator::GraphAdjIterator(const Graph &G, int v) : _g(G), _v(v) {
    for (auto it = G._g[v].cbegin(); it != G._g[v].cend(); it++) {
        if (*it) _adjResults.push_back(it - G._g[v].cbegin());
    }
}

GraphAdjIterator::const_iterator GraphAdjIterator::cbegin() {
    return _adjResults.cbegin();
}

GraphAdjIterator::const_iterator GraphAdjIterator::cend() {
    return _adjResults.cend();
}

Graph::Graph(size_t v) {
    assert(v >= 0);
    _m = 0;
    _n = v;
    for (int i = 0; i < v; i++) {
        _g.push_back(std::vector<bool>(v, false));
    }
}

 size_t Graph::V() const {
    return _n;
}

 size_t Graph::E() const {
    return _m;
}

void Graph::addEdge(int v, int w) {
    assert(v >= 0 && v <= _n);
    assert(w >= 0 && w <= _n);

    if (hasEdge(v, w)) return;
    _g[v][w] = true;
    if (!_directed) _g[w][v] = true;
    _m++;
}

GraphAdjIterator* Graph::adj(int v) const{
    return new GraphAdjIterator(*this, v);
}

void Graph::toString() const {
    // TODO string buffer
    for (auto it = _g.cbegin(); it != _g.cend(); it++) {
        // TODO v append to string buffer
        size_t v = it - _g.cbegin();
        std::cout << v << ": ";
        auto ajdIterator = adj(v);
        for (auto git = ajdIterator->cbegin(); git != ajdIterator->cend(); git++)
            std::cout << *git << " ";
        delete ajdIterator;
        std::cout << std::endl;
    }
}

inline bool Graph::hasEdge(int v, int w) const {
    assert(v >= 0 && v <= _n);
    assert(w >= 0 && w <= _n);
    return _g[v][w];
}
