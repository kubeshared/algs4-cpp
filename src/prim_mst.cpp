//
// Created by xuyc on 2021/1/25.
//

#include "prim_mst.h"
#include <limits>

using namespace algs4;

PrimMST::PrimMST(const EdgeWeightedGraph &G)
        : _pq(G.V()) {
    _marked = new bool[G.V()];
    _distTo = new double[G.V()];
    _weight = 0.0;
    for (int i = 0; i < G.V(); i++) {
        _marked[i] = false;
        _distTo[i] = numeric_limits<int>::max();
    }
    _edgeTo = vector<Edge>(G.V(), Edge(-1, -1, 0.0));
    // run from each vertex to find
//    for (int v = 0; v < G.V(); v++) {
//        // minimum spanning forest
//        if (!_marked[v]) {
//            prim(G, v);
//        }
//    }

    prim(G, 0);
}

PrimMST::~PrimMST() {
    delete[]_marked;
}

void PrimMST::prim(const EdgeWeightedGraph &G, int s) {
    _distTo[s] = 0.0;
    _pq.insert(s, _distTo[s]);
    while (!_pq.isEmpty()) {
        int v = _pq.delMin();
        scan(G, v);
    }
}

void PrimMST::scan(const EdgeWeightedGraph &G, int v) {
    _marked[v] = true;
    AdjacencyIterator<Edge> *it = G.adj(v);
    while (it->hasNext()) {
        Edge e = it->next();
        int w = e.other(v);
        if (_marked[w]) {
            continue;
        }
        if (e.weight() < _distTo[w]) {
            _distTo[w] = e.weight();
            _edgeTo[w] = e;
            if (_pq.contains(w)) {
                _pq.change(w, _distTo[w]);
            } else {
                _pq.insert(w, _distTo[w]);
            }
        }
    }
    delete it;
}

vector<Edge> PrimMST::edges() const {
    vector<Edge> mst;
    for ( Edge e : _edgeTo) {
        if (!e.empty()) {
            mst.insert(mst.begin(), e);
        }
    }

    return move(mst);
}

double PrimMST::weight() const {
    double weighted = 0.0;
    for ( Edge e : edges()) {
        weighted += e.weight();
    }

    return weighted;
}