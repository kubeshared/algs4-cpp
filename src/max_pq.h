//
// Created by xuyc on 2021/1/22.
//

#ifndef ALGS4_MAX_PQ_H
#define ALGS4_MAX_PQ_H
#include <algorithm>
#include <vector>
namespace algs4 {
    template<typename Key>
    class MaxPQ {
    public:
        MaxPQ();

        explicit MaxPQ(int max);

        ~MaxPQ();

        MaxPQ(Key a[], int n);

        void insert(Key v);

        Key max();

        Key delMax();

        bool isEmpty();

        int size();

    private:
        int parent(int k) const;

        int leftChild(int k) const;

        int rightChild(int k) const;

        void resize(int size);

        void swim(int k);

        void sink(int k);

        int len;
        int cap;
        std::vector<Key> pq;
    };
}


#endif //ALGS4_MAX_PQ_H
