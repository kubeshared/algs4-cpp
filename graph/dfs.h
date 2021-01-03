//
// Created by xuyc on 2020/12/23.
//

#ifndef ALGS4_DFS_H
#define ALGS4_DFS_H
#include "graph.h"
#include <stack>
class DepthFirstSearch{
public:
    DepthFirstSearch() = default;
    DepthFirstSearch(const Graph& G, int s);
    ~DepthFirstSearch();
    bool marked(int v);
    int count() const;
    std::stack<int> *pathTo(int v);
    bool hasPathTo(int v);
private:
    void _dfs(const Graph& G, int v);
    bool *_marked;
    size_t _count;
    int _s;
    const Graph &_g;
    std::vector<int> _edgeTo;
};

#endif //ALGS4_DFS_H
