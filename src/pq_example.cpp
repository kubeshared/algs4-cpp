//
// Created by xuyc on 2021/1/22.
//

#include "max_pq.h"
#include "min_pq.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        perror("Error no invalid input");
        exit(1);
    }
    string filename(argv[1]);
    fstream in(filename);
    string line;

    cout << "max pq: " << endl;
    algs4::MaxPQ<string> maxPQ;
    while (getline(in, line)) {
        maxPQ.insert(line);
    }
    in.close();

    while (!maxPQ.isEmpty()) {
        cout << maxPQ.delMax() << endl;
    }

    cout << "min pq: " << endl;
    in.open(filename);
    algs4::MinPQ<string> minPQ;
    while (getline(in, line)) {
        minPQ.insert(line);
    }
    in.close();

    while (!minPQ.isEmpty()) {
        cout << minPQ.delMin() << endl;
    }
}