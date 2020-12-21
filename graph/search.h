//
// Created by xuyc on 2020/12/20.
//
#include "graph.h"

#ifndef ALGS4_CPP_SEARCH_H
#define ALGS4_CPP_SEARCH_H
class Search{
public:
    Search() = default;
    explicit Search(Graph G, int s);
    bool marked(int v);
    int count();
};

class DepthFirstSearch{
public:
    DepthFirstSearch() = default;
    DepthFirstSearch(const Graph& G, int s);
    ~DepthFirstSearch();
    bool marked(int v);
    int count() const;
private:
    void _dfs(const Graph& G, int v);
    bool *_marked;
    size_t _count;
};

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
    auto adjs = G.adj(v);
    for (auto w : *adjs) {
        if (!_marked[w]) _dfs(G, w);
    }
    free(adjs);
}

bool DepthFirstSearch::marked(int v) {
    return _marked[v];
}

int DepthFirstSearch::count() const {
    return _count;
}

#endif //ALGS4_CPP_SEARCH_H
