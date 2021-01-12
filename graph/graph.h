#ifndef ALGS4_CPP_GRAPH
#define ALGS4_CPP_GRAPH

#include <vector>
#include <string>
#include <iostream>
#include <cassert>
#include <list>

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

class GraphIterator;

class GraphInterface;
class GraphList;



class GraphInterface {
public:
    GraphInterface(int v);
    virtual ~GraphInterface() = default;
    virtual size_t V() const { return _v; };
    virtual size_t E() const { return _e; };
    virtual void addEdge(int v, int w) = 0;
    virtual bool hasEdge(int v, int w) = 0;
    virtual const std::vector<int>* adj(int v) const = 0;
protected:
    size_t _v;
    size_t _e;
};


class GraphIterator {
public:
    virtual ~GraphIterator() = default;
    virtual bool hasNext() = 0;
    virtual int next() = 0;
};

class GraphListIterator :public GraphIterator {
public:
    GraphListIterator(const GraphList &g, int v);
     bool hasNext() override ;
     int next() override;
private:
    size_t _i;
    const std::vector<int>* _v;
};

class GraphList : public GraphInterface{
public:
   friend GraphListIterator;
   explicit GraphList(int v);
   explicit GraphList(int v, bool directed, bool parallel);
   void addEdge(int v, int w) override;
   bool hasEdge(int v, int w) override;
    const std::vector<int>* adj(int v) const override ;
private:
    bool _directed;
    bool _parallel;
    std::vector<std::vector<int>> _g;
};
#endif // !ALGS4_CPP_GRAPH