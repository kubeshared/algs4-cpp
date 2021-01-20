//
// Created by 徐元昌 on 2021/1/19.
//

#ifndef ALGS4_DIRECTED_SCC_H
#define ALGS4_DIRECTED_SCC_H
#include "digraph.h"
#include "directed_dfs_order.h"
class KosarajuSCC {
public:
    KosarajuSCC(const Digraph& G);
    ~KosarajuSCC();
    bool stronglyConnected(int v, int w);
    int count();
    int id(int v);
private:
    void dfs(const Digraph& G, int s);
    bool *marked;
    int *_id;
    int _count;
};


#endif //ALGS4_DIRECTED_SCC_H
