//
// Created by 徐元昌 on 2020/12/22.
//

#include "graph.h"

GraphAdjIterator::GraphAdjIterator(const Graph &G, int v) : _g(G), _v(v) {
    for (auto it = G._g[v].cbegin(); it != G._g[v].cend(); it++) {
        if (*it) _adjResults.push_back(it - G._g[v].cbegin());
    }
}

GraphAdjIterator::const_iterator GraphAdjIterator::cbegin() {
    return _adjResults.cbegin();
}

GraphAdjIterator::const_iterator GraphAdjIterator::cend() {
    return _adjResults.cend();
}

Graph::Graph(size_t v) {
    assert(v >= 0);
    _m = 0;
    _n = v;
    for (int i = 0; i < v; i++) {
        _g.push_back(std::vector<bool>(v, false));
    }
}

Graph::Graph(size_t v, bool directed) {
    assert(v >= 0);
    _m = 0;
    _n = v;
    _directed = directed;
    for (int i = 0; i < v; i++) {
        _g.push_back(std::vector<bool>(v, false));
    }
}

size_t Graph::V() const {
    return _n;
}

size_t Graph::E() const {
    return _m;
}

void Graph::addEdge(int v, int w) {
    assert(v >= 0 && v <= _n);
    assert(w >= 0 && w <= _n);

    if (hasEdge(v, w)) return;
    _g[v][w] = true;
    if (!_directed) _g[w][v] = true;
    _m++;
}

GraphAdjIterator *Graph::adj(int v) const {
    return new GraphAdjIterator(*this, v);
}

void Graph::toString() const {
    // TODO string buffer
    for (auto it = _g.cbegin(); it != _g.cend(); it++) {
        // TODO v append to string buffer
        size_t v = it - _g.cbegin();
        std::cout << v << ": ";
        auto ajdIterator = adj(v);
        for (auto git = ajdIterator->cbegin(); git != ajdIterator->cend(); git++)
            std::cout << *git << " ";
        delete ajdIterator;
        std::cout << std::endl;
    }
}

inline bool Graph::hasEdge(int v, int w) const {
    assert(v >= 0 && v <= _n);
    assert(w >= 0 && w <= _n);
    return _g[v][w];
}

GraphList::GraphList(int v) {
    _v = v;
    _g = vector<vector<int>>(_v);
    _directed = false;
    _parallel = false;
}

GraphList::GraphList(fstream &in) {
    int e;
    in >> _v >> e;
    _g = vector<vector<int>>(_v);
    _directed = false;
    _parallel = false;

    for (int i = 0; i < e; i++) {
        int v, w;
        in >> v >> w;
        addEdge(v, w);
    }
}

GraphList::GraphList(int v, bool directed, bool parallel) {
    _v = v;
    _g = vector<vector<int>>(_v);
    _directed = directed;
    _parallel = parallel;
}

int GraphList::V() const {
    return _v;
}

int GraphList::E() const {
    return _e;
}

void GraphList::addEdge(int v, int w) {
    assert(v >= 0 && v <= _v);
    assert(w >= 0 && w <= _v);
    if (hasEdge(v, w) && !_parallel) return;
    _g[v].insert(_g[v].begin(), w);
    if (!_directed)(_g[w]).insert(_g[w].begin(), v);
    _e++;
}

bool GraphList::hasEdge(int v, int w) {
    assert(v >= 0 && v <= _v);
    assert(w >= 0 && w <= _v);

    // O(N)
    for (auto i : (_g[v])) {
        if (i == w) return true;
    }
    return false;
}

AdjacencyIterator<int> *GraphList::adj(int v) const {
    return new GraphListAdjacencyIterator<int>(*this, v);
}

string GraphList::toString() const {
    stringstream ss;
    ss << _v << " vertices, " << _e << " edges\n";
    for (int i = 0; i < _v; i++) {
        AdjacencyIterator<int> *it = adj(i);
        ss << i << ": ";
        while (it->hasNext()) {
            ss << it->next() << " ";
        }
        ss << "\n";
        delete it;
    }

    return std::move(string(ss.str()));
}

GraphMatrix::GraphMatrix(int v) {
    _v = v;
    _g = vector<vector<bool>>(_v, vector<bool>(_v, false));
    _directed = false;
    _parallel = false;
}

GraphMatrix::GraphMatrix(fstream &in)
        : _e(0) {
    int e;
    in >> _v >> e;
    _g = vector<vector<bool>>(_v, vector<bool>(_v, false));
    _directed = false;
    _parallel = false;

    for (int i = 0; i < e; i++) {
        int v, w;
        in >> v >> w;
        addEdge(v, w);
    }
}

GraphMatrix::GraphMatrix(int v, bool directed, bool parallel) {
    _v = v;
    _g = vector<vector<bool>>(_v, vector<bool>(_v, false));
    _directed = directed;
    _parallel = parallel;
}


int GraphMatrix::V() const {
    return _v;
}

int GraphMatrix::E() const {
    return _e;
}

void GraphMatrix::addEdge(int v, int w) {
    assert(v >= 0 && v <= _v);
    assert(w >= 0 && w <= _v);
    if (hasEdge(v, w) && !_parallel) return;
    _g[v][w] = true;
    if (!_directed) _g[w][v] = true;
    this->_e++;
}

bool GraphMatrix::hasEdge(int v, int w) {
    assert(v >= 0 && v <= _v);
    assert(w >= 0 && w <= _v);

    // O(1)
    return _g[v][w];
}

AdjacencyIterator<int> *GraphMatrix::adj(int v) const {
    return new GraphMatrixAdjacencyIterator<int>(*this, v);
}

string GraphMatrix::toString() const {
    stringstream ss;
    ss << _v << " vertices, " << this->_e << " edges\n";
    for (int i = 0; i < _v; i++) {
        AdjacencyIterator<int> *it = adj(i);
        ss << i << ": ";
        while (it->hasNext()) {
            ss << it->next() << " ";
        }
        delete it;
        ss << "\n";
    }

    return std::move(string(ss.str()));
}

template <typename T>
GraphListAdjacencyIterator<T>::GraphListAdjacencyIterator(const GraphList &G, int v)
        : g(G), w(0) {
    this->v = v;
}

template <typename T>
bool GraphListAdjacencyIterator<T>::hasNext() {
    return this->w < g._g[v].size();
}

template <typename T>
T GraphListAdjacencyIterator<T>::next() {
    return g._g[this->v][this->w++];
}


template <typename T>
GraphMatrixAdjacencyIterator<T>::GraphMatrixAdjacencyIterator(const GraphMatrix &G, int v)
        : g(G), w(0) {
    this->v = v;
}

template <typename T>
bool GraphMatrixAdjacencyIterator<T>::hasNext() {
    while (w < g._v) {
        if (g._g[this->v][this->w]) {
            return true;
        }
        w++;
    }
    return false;
}

template <typename T>
T GraphMatrixAdjacencyIterator<T>::next() {
    return this->w++;
}

