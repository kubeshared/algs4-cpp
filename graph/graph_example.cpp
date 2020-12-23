#include <iostream>
#include "graph.h"
#include "bfs.h"

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
    BreadthFirstSearch bfs(g, 9);
    std::cout << "marked: " <<  bfs.marked(12) << std::endl;
    auto paths = bfs.pathTo(12);
    while (true) {
        std::cout << paths->top();
        paths->pop();
        if (paths->empty()) {
            break;
        }
         std::cout<< "-";
    }
    std::cout << std::endl;
    delete paths;
}