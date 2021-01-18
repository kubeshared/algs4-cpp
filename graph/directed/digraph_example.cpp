//
// Created by xuyc on 2021/1/18.
//

#include "digraph.h"

int main(int argc, const char *argv[])
{
    if (argc != 2) {
        perror("Error no invalid input");
        exit(1);
    }

    string filename(argv[1]);
    fstream in(filename);
    Digraph dg(in);
    cout << dg.toString();

    cout << dg.reverse().toString();
    in.close();
}