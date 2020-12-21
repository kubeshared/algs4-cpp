#ifndef ALGS4_CPP_GRAPH
#define ALGS4_CPP_GRAPH

#include <vector>
#include <string>
#include <iostream>
#include <cassert>

class Graph {
public:
    Graph() = default;

    explicit Graph(size_t v);

    // TODO stdin
    inline size_t V() const;

    inline size_t E() const;

    void addEdge(int v, int w);

    std::vector<int> *adj(int v) const;

    inline bool hasEdge(int v, int w) const;

    void toString() const;

private:
    size_t _n;
    size_t _m;
    bool _directed;
    std::vector<std::vector<bool>> _g;

private:
};

Graph::Graph(size_t v) {
    assert(v >= 0);
    _m = 0;
    _n = v;
    for (int i = 0; i < v; i++) {
        _g.push_back(std::vector<bool>(v, false));
    }
}


inline size_t Graph::V() const {
    return _n;
}

inline size_t Graph::E() const {
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

std::vector<int> *Graph::adj(int v) const {
    auto *adjs = new std::vector<int>();
    for (auto it = _g[v].cbegin(); it != _g[v].cend(); it++)
        if (*it) (*adjs).push_back(it - _g[v].cbegin());
    return adjs;
}

void Graph::toString() const {
    // TODO string buffer
    for (auto it = _g.cbegin(); it != _g.cend(); it++) {
        // TODO v append to string buffer
        size_t v = it - _g.cbegin();
        std::cout << v << ": ";
        auto adjs = adj(v);
        for (auto w : *adjs) {
            std::cout << w << " ";
        }
        delete adjs;
        std::cout << std::endl;
    }
}

inline bool Graph::hasEdge(int v, int w) const {
    assert(v >= 0 && v <= _n);
    assert(w >= 0 && w <= _n);
    return _g[v][w];
}


#endif // !ALGS4_CPP_GRAPH
