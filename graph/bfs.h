//
// Created by xuyc on 2020/12/23.
//

#ifndef ALGS4_BFS_H
#define ALGS4_BFS_H
#include "graph.h"
#include <queue>
#include <vector>
#include <stack>
class BreadthFirstSearch {
public:
    BreadthFirstSearch() = default;
    BreadthFirstSearch(const Graph& G, int s);
    ~BreadthFirstSearch();
    bool marked(int v);
    int count() const;
    bool hasPathTo(int v);
    std::stack<int> *pathTo(int v);
private:
    void _bfs(const Graph& G, int v);
    bool *_marked;
    size_t _count;
    std::vector<int> _edgeTo;
    std::queue<int> _queue;
    const Graph &_g;
    int _s;
};


#endif //ALGS4_BFS_H
