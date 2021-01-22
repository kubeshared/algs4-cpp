//
// Created by xuyc on 2021/1/22.
//

#ifndef ALGS4_MAX_PQ_H
#define ALGS4_MAX_PQ_H

namespace algs4 {
    template<typename Key>
    class MaxPQ {
        MaxPQ() = default;

        explicit MaxPQ(int max);

        ~MaxPQ();

        MaxPQ(Key a[], int n);

        void insert(Key v);

        Key max();

        Key delMax();

        bool isEmpty();

        int size();

    private:
        int parent(int k);

        int leftChild(int k);

        int rightChild(int k);

        void resize(int size);

        void swim(int k);

        void sink(int k);

        int len;
        int cap;
        Key *data;
    };
}


#endif //ALGS4_MAX_PQ_H
