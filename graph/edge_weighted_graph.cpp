//
// Created by xuyc on 2021/1/21.
//

#include "edge_weighted_graph.h"

EdgeWeightedGraph::EdgeWeightedGraph(int v) {
    this->v = v;
    this->e = 0;
    this->g = vector<vector<Edge>>(this->v, vector<Edge>());
}

EdgeWeightedGraph::EdgeWeightedGraph(fstream &in) {
    int v, e;
    in >> v >> e;
    this->v = v;
    this->e = 0;
    this->g = vector<vector<Edge>>(this->v, vector<Edge>());
    for (int i = 0; i < e; i++) {
        int v, w;
        double weight;
        in >> v >> w >> weight;
        addEdge(Edge(v, w, weight));
    }
}

void EdgeWeightedGraph::addEdge(Edge e) {
    int v = e.either();
    int w = e.other(v);
    g[v][w] = e;
    g[w][v] = e;
}

AdjacencyIterator<Edge>* EdgeWeightedGraph::adj(int v) {

}