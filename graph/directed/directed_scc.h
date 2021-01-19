//
// Created by 徐元昌 on 2021/1/19.
//

#ifndef ALGS4_DIRECTED_SCC_H
#define ALGS4_DIRECTED_SCC_H
#include "digraph.h"

class SCC {
public:
    SCC(const Digraph& G);
    bool stronglyConnected(int v, int w);
    int count();
    int id(int v);

private:
};


#endif //ALGS4_DIRECTED_SCC_H
