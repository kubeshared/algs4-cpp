//
// Created by xuyc on 2020/12/20.
//


#ifndef ALGS4_CPP_SEARCH_H
#define ALGS4_CPP_SEARCH_H
#include "graph.h"
#include <queue>

class Search{
public:
    Search() = default;
    explicit Search(Graph G, int s);
    bool marked(int v);
    int count();
};


#endif //ALGS4_CPP_SEARCH_H
