//
// Created by 徐元昌 on 2021/1/19.
//

#include "directed_scc.h"

KosarajuSCC::KosarajuSCC(const Digraph &G) {
    marked = new bool[G.V()];
    _id = new int[G.V()];
    _count = 0;
    DepthFirstOrder order(G.reverse());
    // TODO avoid to copy stack
    stack<int> reverseOrder = *order.reversePost();
    while (!reverseOrder.empty()) {
        int v = reverseOrder.top();
        reverseOrder.pop();
        if (!marked[v]) {
            dfs(G, v);
            _count++;
        }
    }
}

KosarajuSCC::~KosarajuSCC() {
    delete []marked;
    delete []_id;
}

bool KosarajuSCC::stronglyConnected(int v, int w) {
    return id(v) == id(w);
}

int KosarajuSCC::count() {
    return _count;
}

int KosarajuSCC::id(int v) {
    return _id[v];
}

void KosarajuSCC::dfs(const Digraph &G, int s) {
    marked[s] = true;
    _id[s] = _count;
    GraphListAdjacencyIterator adjIt = G.adj(s);
    while (adjIt.hasNext()) {
        int v = adjIt.next();
        if (!marked[v])
            dfs(G, v);
    }
}