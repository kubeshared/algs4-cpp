//
// Created by xuyc on 2021/1/22.
//

#include <iostream>
#include "edge_weighted_graph.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        perror("Error no invalid input");
        exit(1);
    }
    string filename(argv[1]);
    fstream in(filename);
    auto *g = new EdgeWeightedGraph(in);
    cout << g->toString() << endl;
    delete g;
    in.close();
}