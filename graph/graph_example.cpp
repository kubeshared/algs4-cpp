#include <iostream>
#include "graph.h"
#include "bfs.h"
#include "dfs.h"
#include "dfs_cc.h"
#include "bfs_cc.h"
#include "dfs_cycle.h"
#include "bfs_cycle.h"
#include "dfs_twocolor.h"
#include "bfs_twocolor.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        perror("Error no invalid input");
        exit(1);
    }
    string filename(argv[1]);
    fstream in(filename);
    cout << "Graph adjacency list: " << endl;
    GraphInterface* g = new GraphList(in);
    cout << g->toString() << endl;
    delete g;
    in.close();

    in.open(filename);
    cout << "Graph adjacency matrix: " << endl;
    g = new GraphMatrix(in);
    cout << g->toString() << endl;
    delete g;
    in.close();
//    Graph g(13);
//    g.addEdge(0, 1);
//    g.addEdge(0, 2);
//    g.addEdge(2, 5);
//    g.addEdge(5, 0);
//    g.addEdge(0, 5);
//    g.addEdge(0, 6);
//    g.addEdge(3, 5);
//    g.addEdge(3, 4);
//    g.addEdge(7, 8);
//    g.addEdge(9, 10);
//    g.addEdge(10, 11);
//    g.addEdge(11, 12);
//
//    DepthFirstSearch dfs(g, 9);
//    std::cout << "dfs marked: " <<  dfs.marked(12) << std::endl;
//    auto dfsPaths = dfs.pathTo(12);
//    std::cout << "dfs paths: ";
//    while (true) {
//        std::cout << dfsPaths->top();
//        dfsPaths->pop();
//        if (dfsPaths->empty()) {
//            break;
//        }
//        std::cout<< "-";
//    }
//    std::cout << std::endl;
//    delete dfsPaths;
//
//
//    BreadthFirstSearch bfs(g, 9);
//    std::cout << "bfs marked: " <<  bfs.marked(12) << std::endl;
//    auto bfsPaths = bfs.pathTo(12);
//    std::cout << "bfs paths: ";
//    while (true) {
//        std::cout << bfsPaths->top();
//        bfsPaths->pop();
//        if (bfsPaths->empty()) {
//            break;
//        }
//        std::cout<< "-";
//    }
//    std::cout << std::endl;
//    delete bfsPaths;
//
//    DepthFirstSearchCC dfscc(g);
//    std::cout << "dfs connected 0, 6: " << dfscc.connected(0, 6) << std::endl;
//    std::cout << "dfs connected 9, 12: " << dfscc.connected(9, 12) << std::endl;
//    std::cout << "dfs connected 0, 9: " << dfscc.connected(0, 9) << std::endl;
//
//
//    BreadthFirstSearchCC bfscc(g);
//    std::cout << "bfs connected 0, 6: " << bfscc.connected(0, 6) << std::endl;
//    std::cout << "bfs connected 9, 12: " << bfscc.connected(9, 12) << std::endl;
//    std::cout << "bfs connected 0, 9: " << bfscc.connected(0, 9) << std::endl;
//
//    Graph g2(5);
//    g2.addEdge(0, 1);
//    g2.addEdge(1, 2);
//    g2.addEdge(2, 3);
//    g2.addEdge(3, 4);
//    g2.addEdge(4, 0);
//    g2.addEdge(2, 0);
//    DepthFirstSearchCycle dfscycle(g2);
//    std::cout << "dfs has cycle: " << dfscycle.hasCycle() << std::endl;
//    std::cout << "dfs cycle count: " << dfscycle.cycleCount() << std::endl;
//
//    BreadthFirstSearchCycle bfscycle(g2);
//    std::cout << "bfs has cycle: " << bfscycle.hasCycle() << std::endl;
//
//    Graph colorGraph(5);
//    colorGraph.addEdge(0, 1);
//    colorGraph.addEdge(0, 2);
//    colorGraph.addEdge(1, 3);
//    colorGraph.addEdge(2, 3);
//    colorGraph.addEdge(3, 4);
//    DepthFirstSearchTwoColor dfsTwoColor(colorGraph);
//    std::cout << "Undirected Graph is bipartite [using dfs]: " << dfsTwoColor.isBipartite() << std::endl;
//
//    BreadthFirstSearchTwoColor bfsTwoColor(colorGraph);
//    std::cout << "Undirected Graph is bipartite [using bfs]: " << bfsTwoColor.isBipartite() << std::endl;
}
