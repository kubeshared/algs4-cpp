//
// Created by xuyc on 2021/1/21.
//

#include "edge_weighted_graph.h"

EdgeWeightedGraph::EdgeWeightedGraph(int v) {
    this->_v = v;
    this->_e = 0;
    this->_g = vector<vector<Edge>>(this->_v, vector<Edge>());
}

EdgeWeightedGraph::EdgeWeightedGraph(fstream &in) {
    int v, e;
    in >> v >> e;
    this->_v = v;
    this->_e = 0;
    this->_g = vector<vector<Edge>>(this->_v, vector<Edge>());
    for (int i = 0; i < e; i++) {
        int v1, v2;
        double weight;
        in >> v1 >> v2 >> weight;
        addEdge(Edge(v1, v2, weight));
    }
}

int EdgeWeightedGraph::V() const {
    return _v;
}

int EdgeWeightedGraph::E() const {
    return _e;
}

void EdgeWeightedGraph::addEdge(Edge e) {
    int v = e.either();
    int w = e.other(v);
    _g[v].insert(_g[v].begin(), e);
    _g[w].insert(_g[w].begin(), e);
}

AdjacencyIterator<Edge> *EdgeWeightedGraph::adj(int v) {
    return new EdgeWeightedAdjacencyIterator<Edge>(*this, v);
}

vector<Edge> EdgeWeightedGraph::edges() {
    vector<Edge> edges(_e);
    for (vector<Edge> vec : _g) {
        copy_n(vec.begin(), vec.size(), edges.begin());
    }
    return move(edges);
}

string EdgeWeightedGraph::toString() {
    stringstream ss;
    ss << _v << " " << _e << endl;
    for (int v = 0; v < _v; v++) {
        ss << v << ": ";
        for (auto edge : _g[v]) {
            ss << edge.either() << "-" << edge.other(edge.either())
               << " " << edge.weight() << " ";
        }
        ss << endl;
    }
    return move(string(ss.str()));
}

template<typename T>
EdgeWeightedAdjacencyIterator<T>::EdgeWeightedAdjacencyIterator(const EdgeWeightedGraph &G, int v)
        :_g(G), _v(v), _w(0) {

}

template<typename T>
bool EdgeWeightedAdjacencyIterator<T>::hasNext() {
    return _w < _g._g[_v].size();
}

template<typename T>
T EdgeWeightedAdjacencyIterator<T>::next() {
    return _g._g[_v][_w++];
}