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
    string line;
    if (!getline(in, line)) {
        perror("Error get Digraph V");
        exit(1);
    }
    int v = stoi(line);
    assert(v >= 0);
    if (!getline(in, line)) {
        perror("Error get Digraph E");
        exit(1);
    }
    int e = stoi(line);
    assert(e >= 0);

    cout << v << endl;
    cout << e << endl;

    g = vector<vector<int>>(v, vector<int>());
    _v = v;
    for (int i = 0; i < e; i++) {
        if (getline(in, line)) {
            vector<string> edges;
            split(line, edges);
            assert(edges.size() == 2);
            cout << stoi(edges[0]) << "," << stoi(edges[1]) << endl;
            addEdge(stoi(edges[0]), stoi(edges[1]));
        }
    }
}

void Digraph::addEdge(int v, int w) {
    if (hasEdge(v, w)) return;
    g[v].push_back(w);
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

AdjacencyIterator Digraph::adj(int v) const{
    assert(v <= _v && v >= 0);
    return {g[v].cbegin(), g[v].cend()};
}

Digraph Digraph::reverse() const{
    Digraph reverse(_v);
    for (int v = 0; v < _v; v++) {
        AdjacencyIterator adjIt = adj(v);
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
        AdjacencyIterator it = adj(i);
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

AdjacencyIterator::AdjacencyIterator(vector<int>::const_iterator begin, vector<int>::const_iterator end)
:_beg(begin), _end(end) {
}

bool AdjacencyIterator::hasNext() const {
    return _beg != _end;
}

int AdjacencyIterator::next() {
    return *_beg++;
}