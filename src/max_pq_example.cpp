//
// Created by xuyc on 2021/1/22.
//

#include <string>
#include <fstream>
#include <iostream>
#include "max_pq.h"

using namespace std;

int main(int argc, const char *argv[]) {
    if (argc != 2) {
        perror("Error invalid input");
        exit(1);
    }

    string filename(argv[argc]);
    algs4::MaxPQ<char *> pq;
    fstream in(filename);
    string line;
//    while (getline(in, line)) {
//        if (line == "-") {
//            while (!pq.isEmpty()) {
//                cout << pq.delMax() << " ";
//            }
//            cout << endl;
//        } else {
//            pq.insert(line);
//        }
//    }

    in.close();
}