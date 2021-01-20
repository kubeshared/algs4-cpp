//
// Created by 徐元昌 on 2021/1/18.
//

#include "directed_dfs.h"

DirectedDFS::DirectedDFS(const Digraph &g, int s) {
    assert(s <= g.V() && s >= 0);

    marked = new bool[g.V()];
    for (int i = 0; i < g.V(); i++)
        marked[i] = false;

    dfs(g, s);
}

DirectedDFS::DirectedDFS(const Digraph &g, const vector<int>& sources) {
    marked = new bool[g.V()];
    for (int i = 0; i < g.V(); i++)
        marked[i] = false;

    for (int s : sources) {
        if (!marked[s]) {
            assert(s <= g.V() && s >= 0);
            dfs(g, s);
        }
    }
}

DirectedDFS::~DirectedDFS() {
    delete []marked;
}

bool DirectedDFS::mark(int v) {
    return marked[v];
}

void DirectedDFS::dfs(const Digraph &g, int s) {
    marked[s] = true;
    GraphListAdjacencyIterator adjIt = g.adj(s);
    while (adjIt.hasNext()) {
        int v = adjIt.next();
        if (!marked[v]) {
            dfs(g, v);
        }
    }
}

void DirectedDFS::dfsOnStack(const Digraph &g, int s) {
    marked[s] = true;
    _stack = stack<int>();
    _stack.push(s);
    while (!_stack.empty()) {
        GraphListAdjacencyIterator adjIt = g.adj(_stack.top());
        while (adjIt.hasNext()) {
            int v = adjIt.next();
            if (!marked[v]) {
                _stack.push(v);
                marked[v] = true;
            }
        }
        _stack.pop();
    }
}
