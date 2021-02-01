//
// Created by xuyc on 2021/2/1.
//

#include "uf_impl.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void computeUF(algs4::UF *uf, fstream &in, int line) {

    int p, q;
    for (int i = 0; i < line; i++) {
        in >> p >> q;
        if (uf->find(p) == uf->find(q)) continue;
        uf->un(p, q);
        cout << p << " " << q << endl;
    }
    cout << uf->count() << " components" << endl;
}

int main(int argc, const char *argv[]) {
    if (argc != 2) {
        perror("Error no invalid input");
        exit(1);
    }
    algs4::UF *uf;
    string filename(argv[1]);

    cout << "QuickFindUF: " << endl;
    fstream in(filename);
    int line;
    in >> line;
    uf = new algs4::QuickFindUF(line);
    computeUF(uf, in, line);
    delete uf;
    in.close();
    cout << endl;

    cout << "QuickUnionUF: " << endl;
    in.open(filename);
    in >> line;
    uf = new algs4::QuickUnionUF(line);
    computeUF(uf, in, line);
    delete uf;
    in.close();
    cout << endl;


    cout << "QuickWeightedUnionUF: " << endl;
    in.open(filename);
    in >> line;
    uf = new algs4::QuickWeightedUnionUF(line);
    computeUF(uf, in, line);
    delete uf;
    in.close();
    cout << endl;
}

