#include <iostream>
#include "graph.h"
#include "bfs.h"
#include "dfs.h"

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
    g.addEdge(10, 11);
    g.addEdge(11, 12);


    DepthFirstSearch dfs(g, 9);
    std::cout << "dfs marked: " <<  dfs.marked(12) << std::endl;
    auto dfsPaths = dfs.pathTo(12);
    std::cout << "dfs paths: ";
    while (true) {
        std::cout << dfsPaths->top();
        dfsPaths->pop();
        if (dfsPaths->empty()) {
            break;
        }
        std::cout<< "-";
    }
    std::cout << std::endl;
    delete dfsPaths;


    BreadthFirstSearch bfs(g, 9);
    std::cout << "bfs marked: " <<  bfs.marked(12) << std::endl;
    auto bfsPaths = bfs.pathTo(12);
    std::cout << "bfs paths: ";
    while (true) {
        std::cout << bfsPaths->top();
        bfsPaths->pop();
        if (bfsPaths->empty()) {
            break;
        }
        std::cout<< "-";
    }
    std::cout << std::endl;
    delete bfsPaths;
}