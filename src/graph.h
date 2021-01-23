#ifndef ALGS4_CPP_GRAPH
#define ALGS4_CPP_GRAPH

#include <vector>
#include <string>
#include <iostream>
#include <cassert>
#include <list>
#include <fstream>
#include <sstream>
#include <memory>
#include <limits>
#include <iterator>

using namespace std;

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

    explicit Graph(size_t v, bool directed);

    ~Graph() = default;

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

template<typename T> class AdjacencyIterator;
template<typename T> class GraphListAdjacencyIterator;
template<typename T> class GraphListMatrixIterator;

class GraphInterface;
class GraphList;
class GraphMatrix;

// API for undirected graph
class GraphInterface {
public:
    virtual ~GraphInterface() = default;

    virtual int V() const = 0;

    virtual int E() const = 0;

    virtual void addEdge(int v, int w) = 0;

    virtual bool hasEdge(int v, int w) = 0;

    virtual AdjacencyIterator<int> *adj(int v) const = 0;

    virtual string toString() const = 0;
};

// API for undirected graph adjacency iterator
template <typename T>
class AdjacencyIterator {
public:
    virtual ~AdjacencyIterator() = default;

    virtual bool hasNext() = 0;

    virtual T next() = 0;

protected:
    int v;
};

template<typename T> class GraphListAdjacencyIterator : public AdjacencyIterator<T> {
public:
    explicit GraphListAdjacencyIterator(const GraphList& G, int v);

    ~GraphListAdjacencyIterator() override = default;

    bool hasNext()  override;

    T next() override;

private:
    int w;
    int v;
    const GraphList& g;
};

template<typename T> class GraphMatrixAdjacencyIterator : public AdjacencyIterator<T> {
public:
    explicit GraphMatrixAdjacencyIterator(const GraphMatrix& G, int v);

    ~GraphMatrixAdjacencyIterator() override = default;

    bool hasNext() override;

    T next() override;

private:
    int w;
    const GraphMatrix& g;
};

class GraphList : public GraphInterface {
    friend GraphListAdjacencyIterator<int>;
public:
    explicit GraphList(int v);

    explicit GraphList(fstream &in);

    explicit GraphList(int v, bool directed, bool parallel);

    int V() const override;

    int E() const override;

    ~GraphList() override = default;

    void addEdge(int v, int w) override;

    bool hasEdge(int v, int w) override;

    AdjacencyIterator<int> *adj(int v) const override;

    string toString() const override;

private:
    int _v;
    int _e;
    bool _directed;
    bool _parallel;
    vector<vector<int>> _g;
};

class GraphMatrix : public GraphInterface {
    friend GraphMatrixAdjacencyIterator<int>;
public:
    explicit GraphMatrix(int v);

    explicit GraphMatrix(fstream &in);

    explicit GraphMatrix(int v, bool directed, bool parallel);

    ~GraphMatrix() override = default;

    int V() const override;

    int E() const override;

    void addEdge(int v, int w) override;

    bool hasEdge(int v, int w) override;

    AdjacencyIterator<int> *adj(int v) const override;

    string toString() const override;

private:
    bool _directed;
    bool _parallel;
    int _v;
    int _e;
    vector<vector<bool>> _g;
};

#endif // !ALGS4_CPP_GRAPH