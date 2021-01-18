//
// Created by 徐元昌 on 2021/1/18.
//

#ifndef ALGS4_DIRECTED_DFS_H
#define ALGS4_DIRECTED_DFS_H
#include "digraph.h"

class DirectedDFS {
public:
    explicit DirectedDFS(const Digraph& g, int s);
    explicit DirectedDFS(const Digraph& g, const vector<int>& sources);
    ~DirectedDFS();
    bool mark(int v);
private:
    bool *marked{};
    void dfs(const Digraph& g, int s);
};


#endif //ALGS4_DIRECTED_DFS_H
