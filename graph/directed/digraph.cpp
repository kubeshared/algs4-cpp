//
// Created by xuyc on 2021/1/18.
//

#include "digraph.h"

Digraph::Digraph(int v) {
    _v = v;
    g = vector<vector<int>>(v, vector<int>());
}

// TODO problem
Digraph::Digraph(fstream& in) {
    int v, e;
    in >> v >> e;

    assert(v >= 0);
    assert(e >= 0);

    g = vector<vector<int>>(v, vector<int>());
    _v = v;
    for (int i = 0; i < e; i++) {
        int v1, v2;
        in >> v1 >> v2;
        addEdge(v1, v2);
    }
}

void Digraph::addEdge(int v, int w) {
    g[v].insert(g[v].begin(), w);
    _e++;
}

bool Digraph::hasEdge(int v, int w) {
    assert(v <= _v && v >= 0);
    assert(w <= _v && w >= 0);
    for (auto item : g[v]) {
        if (item == w) return true;
    }

    return false;
}

int Digraph::V() const {
    return _v;
}

int Digraph::E() const {
    return _e;
}

GraphListAdjacencyIterator Digraph::adj(int v) const{
    assert(v <= _v && v >= 0);
    return {g[v].cbegin(), g[v].cend()};
}

Digraph Digraph::reverse() const{
    Digraph reverse(_v);
    for (int v = 0; v < _v; v++) {
        GraphListAdjacencyIterator adjIt = adj(v);
        while (adjIt.hasNext()) {
            int w = adjIt.next();
            reverse.addEdge(w, v);
        }
    }
    return reverse;
}

string Digraph::toString() const {
    stringstream ss;
    ss << _v << " vertices, " << _e << " edges\n";
    for(int i = 0; i < _v; i++) {
        GraphListAdjacencyIterator it = adj(i);
        ss << i << ": ";
        while (it.hasNext()) {
            ss << it.next() << " ";
        }
        ss << "\n";
    }

    return std::move(string(ss.str()));
}

template <class Container>
void split(const std::string& str, Container& cont)
{
    std::istringstream iss(str);
    std::copy(std::istream_iterator<std::string>(iss),
              std::istream_iterator<std::string>(),
              std::back_inserter(cont));
}

GraphListAdjacencyIterator::GraphListAdjacencyIterator(vector<int>::const_iterator begin, vector<int>::const_iterator end)
:_beg(begin), _end(end) {
}

bool GraphListAdjacencyIterator::hasNext() const {
    return _beg != _end;
}

int GraphListAdjacencyIterator::next() {
    return *_beg++;
}