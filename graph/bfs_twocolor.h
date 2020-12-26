//
// Created by 徐元昌 on 2020/12/26.
//

#ifndef ALGS4_BFS_TWOCOLOR_H
#define ALGS4_BFS_TWOCOLOR_H
#include "graph.h"
#include <vector>
#include <queue>


class BreadthFirstSearchTwoColor {
public:
    BreadthFirstSearchTwoColor(const Graph &g);
    bool isBipartite();

private:
    void _bfs(const Graph &g, int v);
    bool _isTwoColorable;
    std::vector<bool> _marked;
    std::vector<bool> _color;
};


#endif //ALGS4_BFS_TWOCOLOR_H
