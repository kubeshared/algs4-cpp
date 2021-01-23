//
// Created by xuyc on 2021/1/23.
//

#include "lazy_prim_mst.h"

int main(int argc, const char *argv[]) {
    if (argc != 2) {
        perror("Error no invalid input");
        exit(1);
    }
    string filename(argv[1]);
    fstream in(filename);
    EdgeWeightedGraph ewg(in);
    in.close();

    algs4::LazyPrimMST mst(ewg);
    queue<Edge> edges = mst.edges();
    cout << argv[0] << " " << argv[1] << endl;
    while (!edges.empty()) {
        Edge e = edges.front();
        cout << e.either() << "-" << e.other(e.either()) << " " << e.weight() << endl;
        edges.pop();
    }
    cout << mst.weight() << endl;
}