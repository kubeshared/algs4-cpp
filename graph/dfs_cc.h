//
// Created by 徐元昌 on 2020/12/23.
//

#ifndef ALGS4_DFS_CC_H
#define ALGS4_DFS_CC_H

#include <vector>
#include "graph.h"

class DepthFirstSearchCC {
public:
    DepthFirstSearchCC(const Graph &g);

    ~DepthFirstSearchCC() = default;

    bool connected(int s, int v);

private:
    void _dfs(int v, int cc);
    const Graph &_g;
    std::vector<int> _count;
    std::vector<bool > _marked;
};


#endif //ALGS4_DFS_CC_H
