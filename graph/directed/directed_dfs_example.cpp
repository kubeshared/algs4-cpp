//
// Created by xuyc on 2021/1/18.
//

#include "digraph.h"
#include "directed_dfs.h"

int main(int argc, const char *argv[])
{
    if (argc < 3) {
        perror("Error no invalid input");
        exit(1);
    }

    // create a directed graph
    string filename(argv[1]);
    fstream in(filename);
    Digraph dg(in);
    in.close();

    // collect user input vertexes to the vector
    vector<int> sources;
    for (int i = 2; i < argc; i++) {
        sources.push_back(atoi(argv[i]));
    }

    // use dfs resolve to reachable problem
    DirectedDFS reachable(dg, sources);

    for (int v = 0; v < dg.V(); v++) {
        if (reachable.mark(v)) {
            cout << v << " ";
        }
    }
    cout << endl;
}