//
// Created by xuyc on 2021/1/19.
//

#include "directed_cycle.h"

int main(const int argc, const char *argv[]) {
    if (argc != 2) {
        perror("Error no invalid input");
        exit(1);
    }

    //
    string filename(argv[1]);
    fstream in(filename);
    Digraph dg(in);
    in.close();

    DirectedCycle finder(dg);
    if (finder.hasCycle()) {
        for (int v : finder.cycle()) {
            cout << v << " ";
        }
        cout << endl;
    } else {
        cout << "No directed cycle" << endl;
    }
}