//
// Created by 徐元昌 on 2020/12/26.
//

#ifndef ALGS4_DFS_TWOCOLOR_H
#define ALGS4_DFS_TWOCOLOR_H

#include "graph.h"
#include <vector>

class DepthFirstSearchTwoColor {
public:
    DepthFirstSearchTwoColor(const Graph &g);

    bool isBipartite();
private:
    void _dfs(const Graph &g, int v);
    std::vector<bool> _marked;
    std::vector<bool> _color;
    bool _isTwoColorable;
};


#endif //ALGS4_DFS_TWOCOLOR_H
