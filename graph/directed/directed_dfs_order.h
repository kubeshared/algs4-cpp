//
// Created by xuyc on 2021/1/19.
//

#ifndef ALGS4_DIRECTED_DFS_ORDER_H
#define ALGS4_DIRECTED_DFS_ORDER_H

#include "digraph.h"
#include <stack>
#include <queue>

template<typename T, typename Container = std::deque<T>>
class StackIterator
        : public std::stack<T, Container>
{
    using std::stack<T, Container>::c;

public:

    // expose just the iterators of the underlying container
    decltype(begin(c)) begin() { return std::begin(c); }
    decltype(end(c)) end() { return std::end(c); }
    decltype(cbegin(c)) begin() const { return std::begin(c); }
    decltype(cend(c)) end() const { return std::end(c); }
};


class DepthFirstOrder {
public:
    DepthFirstOrder(const Digraph &G);

    ~DepthFirstOrder();

    const queue<int>* pre() const;

    const queue<int>* post() const;

    const stack<int>* reversePost() const;

private:
    void dfs(const Digraph &g, int v);

    queue<int>* preQueue;
    queue<int>* postQueue;
    stack<int>* reversePostQueue;
    bool *marked;
};


#endif //ALGS4_DIRECTED_DFS_ORDER_H
