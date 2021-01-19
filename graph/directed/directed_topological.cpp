//
// Created by xuyc on 2021/1/19.
//

#include "directed_topological.h"
Topological::Topological(const Digraph &G) {
    DirectedCycle finder(G);
    if (!finder.hasCycle()) {
        DepthFirstOrder order(G);
        reverseOrder = order.reversePost();
    }
}

bool Topological::isDAG() const {
    return reverseOrder != nullptr;
}

const stack<int, deque<int>>& Topological::order() const {
    return *reverseOrder;
}