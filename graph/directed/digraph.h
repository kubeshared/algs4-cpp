//
// Created by xuyc on 2021/1/18.
//

#ifndef ALGS4_DIGRAPH_H
#define ALGS4_DIGRAPH_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cassert>
#include <iterator>
using namespace std;

template <class Container>
void split(const std::string& str, Container& cont);

class AdjacencyIterator {
public:
    AdjacencyIterator(vector<int>::const_iterator begin, vector<int>::const_iterator end);
    bool hasNext() const;
    int next();
private:
    vector<int>::const_iterator _beg, _end;
};

class Digraph {
public:
    explicit Digraph(int v);
    explicit Digraph(fstream& fs);
    int V() const;
    int E() const;
    void addEdge(int v, int w);
    AdjacencyIterator adj(int v) const;
    Digraph reverse() const;
    string toString() const;
    bool hasEdge(int v, int w);
private:
    int _v;
    int _e;
    vector<vector<int>> g;
};

#endif //ALGS4_DIGRAPH_H
