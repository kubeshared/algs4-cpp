//
// Created by xuyc on 2020/12/20.
//


#ifndef ALGS4_CPP_SEARCH_H
#define ALGS4_CPP_SEARCH_H
#include "graph.h"
#include <queue>

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
    void _dfs(const Graph& G, int v);    bool *_marked;
    size_t _count;
};

class BreadthFirstSearch {
public:
    BreadthFirstSearch() = default;
    BreadthFirstSearch(const Graph& G, int s);
    ~BreadthFirstSearch();
    bool marked(int v);
    int count() const;
private:
    void _bfs(const Graph& G, int v);
    bool *_marked;
    size_t _count;
    std::queue<int> _queue;
};

#endif //ALGS4_CPP_SEARCH_H
