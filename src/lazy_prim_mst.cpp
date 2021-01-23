//
// Created by xuyc on 2021/1/23.
//

#include "algs4.h"

using namespace algs4;

LazyPrimMST::LazyPrimMST(const EdgeWeightedGraph &G) {
    marked = new bool[G.V()];
    for (int i = 0; i < G.V(); i++) {
        marked[i] = false;
    }
    mstWeight = 0.0;
    mst = queue<Edge>();
    pq = algs4::MinPQ<Edge>();
    for (int s = 0; s < G.V(); s++) {
        if (!marked[s]) {
            prim(G, s);
        }
    }
}

LazyPrimMST::~LazyPrimMST() {
    delete[]marked;
}

void LazyPrimMST::prim(const EdgeWeightedGraph &G, int s) {
    scan(G, s);
    while (!pq.isEmpty()) {
        Edge e = pq.delMin();
        auto v = e.either();
        auto w = e.other(v);
        assert(marked[v] || marked[w]);
        if (marked[v] && marked[w]) {
            continue;
        }
        mst.push(e);
        mstWeight += e.weight();
        if (!marked[v]) {
            scan(G, v);
        }
        if (!marked[w]) {
            scan(G, w);
        }
    }
}

void LazyPrimMST::scan(const EdgeWeightedGraph &G, int v) {
    assert(!marked[v]);
    AdjacencyIterator<Edge> *it = G.adj(v);
    marked[v] = true;
    while (it->hasNext()) {
        Edge e = it->next();
        if (!marked[e.other(v)]) {
            pq.insert(e);
        }
    }
    delete it;
}

queue<Edge> LazyPrimMST::edges() const {
    return mst;
}

double LazyPrimMST::weight() const {
    return mstWeight;
}