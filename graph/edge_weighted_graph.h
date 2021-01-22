//
// Created by xuyc on 2021/1/21.
//

#ifndef ALGS4_EDGE_GRAPH_H
#define ALGS4_EDGE_GRAPH_H

#include "graph.h"
#include "edge.h"
#include <fstream>
#include <algorithm>
#include <sstream>

using namespace std;

class EdgeWeightedGraph;

template<typename T>
class EdgeWeightedAdjacencyIterator;

class EdgeWeightedGraph {
    friend EdgeWeightedAdjacencyIterator<Edge>;
public:
    explicit EdgeWeightedGraph(int v);

    explicit EdgeWeightedGraph(fstream &in);

    int V() const;

    int E() const;

    void addEdge(Edge e);

    AdjacencyIterator<Edge> *adj(int v);

    vector<Edge> edges();

    string toString();

private:
    int _v;
    int _e;
    vector<vector<Edge>> _g;
};

template<typename T>
class EdgeWeightedAdjacencyIterator
        : public AdjacencyIterator<T> {
public:
    explicit EdgeWeightedAdjacencyIterator(const EdgeWeightedGraph &G, int v);

    ~EdgeWeightedAdjacencyIterator() = default;

    bool hasNext() override;

    T next() override;

private:
    int _v;
    int _w;
    const EdgeWeightedGraph &_g;
};


#endif //ALGS4_EDGE_GRAPH_H
