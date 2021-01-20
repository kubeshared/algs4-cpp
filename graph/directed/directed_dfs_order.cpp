//
// Created by xuyc on 2021/1/19.
//

#include "directed_dfs_order.h"
DepthFirstOrder::DepthFirstOrder(const Digraph &G) {
    marked = new bool[G.V()];
    for (int i = 0; i < G.V(); i++)
        marked[i] = false;

    preQueue = new queue<int>;
    postQueue = new queue<int>;
    reversePostQueue = new stack<int>;

    for (int v = 0; v < G.V(); v++)
        if (!marked[v]) {
            dfs(G, v);
        }
}

DepthFirstOrder::~DepthFirstOrder() {
    delete []marked;
    delete preQueue;
    delete postQueue;
    delete reversePostQueue;
}

void DepthFirstOrder::dfs(const Digraph &g, int v) {
    marked[v] = true;
    preQueue->push(v);
    AdjacencyIterator adjIt = g.adj(v);
    while (adjIt.hasNext()){
        int w = adjIt.next();
        if (!marked[w]) {
            dfs(g, w);
        }
    }

    postQueue->push(v);
    reversePostQueue->push(v);
}

const queue<int>* DepthFirstOrder::pre() const {
    return preQueue;
}

const queue<int>* DepthFirstOrder::post() const {
    return postQueue;
}

const stack<int>* DepthFirstOrder::reversePost() const {
    return reversePostQueue;
}
