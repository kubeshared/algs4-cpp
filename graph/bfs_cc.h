//
// Created by xuyc on 2020/12/24.
//

#ifndef ALGS4_BFS_CC_H
#define ALGS4_BFS_CC_H
#include "graph.h"
#include <vector>
#include <queue>

class BreadthFirstSearchCC {
public:
    BreadthFirstSearchCC(const Graph &g);
    bool connected(int s, int v);
    int count();
    int id(int v);
private:
    const Graph &_g;
    int _ccCount;
    std::vector<bool> _marked;
    std::vector<int> _count;
    void _bfs(int v, int cc);
};


#endif //ALGS4_BFS_CC_H
