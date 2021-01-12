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

Graph::Graph(size_t v, bool directed) {
    assert(v >= 0);
    _m = 0;
    _n = v;
    _directed = directed;
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

GraphInterface::GraphInterface(int v) {
    _v = v;
}

GraphList::GraphList(int v): GraphInterface(v) {
    _g = std::vector<std::vector<int>>(_v);
    _directed = false;
    _parallel = false;
    for (int i = 0; i < v; i++) {
        _g.push_back(std::vector<int>());
    }
}

GraphList::GraphList(int v, bool directed, bool parallel) :GraphInterface(v) {
    _g = std::vector<std::vector<int>>(_v);
    _directed = directed;
    _parallel = parallel;
}

void GraphList::addEdge(int v, int w) {
    assert(v >= 0 && v <= _v);
    assert(w >= 0 && w <= _v);
    if (hasEdge(v, w) && !_parallel) return;

    _g[v].push_back(w);
    if (_directed) _g[w].push_back(v);
    _e++;
}

bool GraphList::hasEdge(int v, int w) {
    assert(v >= 0 && v <= _v);
    assert(w >= 0 && w <= _v);

    // O(N)
    for (auto it = _g[v].cbegin(); it != _g[v].cend(); it++)
        if (*it == w) return true;
    return false;
}

const std::vector<int>* GraphList::adj(int v) const {
//    std::cout << _g[v].size() << std::endl;
//    GraphIterator *iter = new GraphListIterator(*this, v);
//    return iter;
    return &_g[v];
}

GraphListIterator::GraphListIterator(const GraphList &g, int v) {
    assert(v >= 0 && v <= g.V());
    std::cout << g._g[v].size() << std::endl;
    _v = &g._g[v];
    _i = 0;
}


bool GraphListIterator::hasNext() {
    return _i < _v->size();
}

int GraphListIterator::next() {
    return (*_v)[_i++];
}