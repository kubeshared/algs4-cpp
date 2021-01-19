//
// Created by xuyc on 2021/1/19.
//

#ifndef ALGS4_DIRECTED_TOPOLOGICAL_H
#define ALGS4_DIRECTED_TOPOLOGICAL_H

#include "digraph.h"
#include "directed_cycle.h"
#include "directed_dfs_order.h"



class Topological {
public:
    Topological(const Digraph& G);

    bool isDAG() const;

    stack<int> order() const;
private:
    stack<int> reverseOrder;
};


#endif //ALGS4_DIRECTED_TOPOLOGICAL_H
