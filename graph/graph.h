#ifndef ALGS4_CPP_GRAPH
#define ALGS4_CPP_GRAPH

#include <vector>
#include <string>
#include <iostream>
#include <cassert>

class GraphAdjIterator;

class Graph;

class GraphAdjIterator {
    typedef std::vector<int>::const_iterator const_iterator;

public:
    GraphAdjIterator(const Graph &G, int v);
    const_iterator cbegin();

    const_iterator cend();

private:
    const Graph &_g;
    int _v;
    std::vector<int> _adjResults;
};

class Graph {
    friend GraphAdjIterator;
public:
    Graph() = default;

    explicit Graph(size_t v);

    // TODO stdin
     size_t V() const;

     size_t E() const;

    void addEdge(int v, int w);

    GraphAdjIterator *adj(int v) const;

    inline bool hasEdge(int v, int w) const;

    void toString() const;

private:
    size_t _n;
    size_t _m;
    bool _directed;
    std::vector<std::vector<bool>> _g;
private:
};

#endif // !ALGS4_CPP_GRAPH