//
// Created by xuyc on 2021/1/19.
//

#include "directed_dfs_order.h"
DepthFirstOrder::DepthFirstOrder(const Digraph &G) {
    marked = new bool[G.V()];
    preQueue = new queue<int>;
    postQueue = new queue<int>;
    reversePostQueue = new stack<int>;

    for (int s = 0; s < G.V(); s++)
        if (!marked[s])
            dfs(G, s);
}

DepthFirstOrder::~DepthFirstOrder() {
    delete []marked;
    delete preQueue;
    delete postQueue;
    delete reversePostQueue;
}

void DepthFirstOrder::dfs(const Digraph &g, int s) {
    preQueue->push(s);

    marked[s] = true;
    AdjacencyIterator adjIt = g.adj(s);
    while (adjIt.hasNext()){
        int v = adjIt.next();
        if (!marked[v]) {
            dfs(g, v);
        }
    }

    postQueue->push(s);
    reversePostQueue->push(s);
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
