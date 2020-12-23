//
// Created by xuyc on 2020/12/23.
//

#ifndef ALGS4_DFS_H
#define ALGS4_DFS_H
#include "graph.h"

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

#endif //ALGS4_DFS_H
