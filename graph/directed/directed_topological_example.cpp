//
// Created by xuyc on 2021/1/18.
//

#include "digraph.h"
#include "directed_topological.h"

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
    stack<int> topOrder = top.order();
    while (!topOrder.empty()) {
        cout << topOrder.top() << " ";
        topOrder.pop();
    }
    cout << endl;
}