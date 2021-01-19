//
// Created by 徐元昌 on 2021/1/19.
//

#include "directed_scc.h"

SCC::SCC(const Digraph &G) {
    marked = new bool[G.V()];
    _id = new int[G.V()];
    _count = 0;
    DepthFirstOrder order(G.reverse());
    for (int v : *order.reversePost()) {
        if (!marked[v]) {
            dfs(G, v);
            _count++;
        }
    }
}

SCC::~SCC() {
    delete []marked;
    delete []_id;
}

bool SCC::stronglyConnected(int v, int w) {
    return id(v) == id(w);
}

int SCC::count() {
    return _count;
}

int SCC::id(int v) {
    return _id[v];
}

void SCC::dfs(const Digraph &G, int s) {
    marked[s] = true;
    _id[s] = _count;
    AdjacencyIterator adjIt = G.adj(s);
    while (adjIt.hasNext()) {
        int v = adjIt.next();
        if (!marked[v])
            dfs(G, v);
    }
}