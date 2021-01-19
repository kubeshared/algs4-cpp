//
// Created by xuyc on 2021/1/18.
//

#include "digraph.h"
#include "directed_topological.h"
#include <algorithm>

int main(int argc, const char *argv[])
{
    if (argc != 2) {
        perror("Error no invalid input");
        exit(1);
    }

    string filename(argv[1]);
    fstream in(filename);
    Digraph dg(in);
    in.close();

    Topological top(dg);
    if (top.isDAG()) {
        for (int v : begin(top.order())) {
            cout << v << " ";
        }
        cout << endl;
    }
}