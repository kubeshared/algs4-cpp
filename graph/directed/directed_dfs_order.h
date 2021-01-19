//
// Created by xuyc on 2021/1/19.
//

#ifndef ALGS4_DIRECTED_DFS_ORDER_H
#define ALGS4_DIRECTED_DFS_ORDER_H

#include "digraph.h"
#include <queue>

class DepthFirstOrder {
public:
    DepthFirstOrder(const Digraph &G);

    ~DepthFirstOrder();

    const queue<int>* pre() const;

    const queue<int>* post() const;

    const deque<int>* reversePost() const;

private:
    void dfs(const Digraph &g, int s);

    queue<int>* preQueue;
    queue<int>* postQueue;
    deque<int>* reversePostQueue;
    bool *marked;
};


#endif //ALGS4_DIRECTED_DFS_ORDER_H
