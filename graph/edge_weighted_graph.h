//
// Created by xuyc on 2021/1/21.
//

#ifndef ALGS4_EDGE_GRAPH_H
#define ALGS4_EDGE_GRAPH_H

#include "graph.h"
#include "edge.h"
#include <fstream>

using namespace std;

class EdgeWeightedGraph {
public:
    EdgeWeightedGraph(int v);
    EdgeWeightedGraph(fstream& in);
    int V() const;
    int E() const;
    void addEdge(Edge e);
    AdjacencyIterator<Edge>* adj(int v);
    vector<Edge> edges();
    string toString();

private:
    int v;
    int e;
    vector<vector<Edge>> g;
};


#endif //ALGS4_EDGE_GRAPH_H
