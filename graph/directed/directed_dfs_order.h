//
// Created by xuyc on 2021/1/19.
//

#ifndef ALGS4_DIRECTED_DFS_ORDER_H
#define ALGS4_DIRECTED_DFS_ORDER_H

#include "digraph.h"
#include <queue>
#include <stack>

class DepthFirstOrder {
public:
    DepthFirstOrder(const Digraph &G);

    ~DepthFirstOrder();

    const queue<int>* pre() const;

    const queue<int>* post() const;

    const stack<int>* reversePost() const;

private:
    void dfs(const Digraph &g, int s);

    queue<int>* preQueue;
    queue<int>* postQueue;
    stack<int>* reversePostQueue;
    bool *marked;
};


#endif //ALGS4_DIRECTED_DFS_ORDER_H
