#include <iostream>
#include "search.h"

int main() {
    Graph g(13);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 5);
    g.addEdge(0, 6);
    g.addEdge(3, 5);
    g.addEdge(3, 4);
    g.addEdge(7, 8);
    g.addEdge(9, 10);
    g.addEdge(9, 11);
    g.addEdge(9, 12);
    DepthFirstSearch dfs(g, 0);
    std::cout << dfs.marked(5) << std::endl;

}