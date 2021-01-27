//
// Created by xuyc on 2021/1/24.
//
#include <string>
#include <fstream>
#include <iostream>
#include "index_min_pq.h"

using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        perror("Error no invalid input");
        exit(1);
    }
    string filename(argv[1]);
    fstream in(filename);

    vector<string> contents;
    string line;
    while (getline(in, line)) {
        contents.push_back(line);
    }

    cout << "index min pq: " << endl;
    algs4::IndexMinPQ<string> minPQ(contents.size());
    for (auto i = 0; i < contents.size(); i++) {
        minPQ.insert(i, contents[i]);
    }

    minPQ.change(0, "Dijkstra   12/18/1995   837.42");
    while (!minPQ.isEmpty()) {
       cout <<  minPQ.keyOf(minPQ.delMin()) << endl;
    }

    in.close();

//    while (!maxPQ.isEmpty()) {
//        cout << maxPQ.delMax() << endl;
//    }

}
