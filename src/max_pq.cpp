//
// Created by xuyc on 2021/1/22.
//

#include "max_pq.h"

using namespace algs4;

template<typename Key>
MaxPQ<Key>::MaxPQ(int max) {
    len = 0;
    cap = max + 1;
    data = new Key[cap];
}

template<typename Key>
MaxPQ<Key>::MaxPQ(Key a[], int n) {
    len = 0;
    cap = n + 1;
    data = new Key[cap];
    for (int i = 1; i < cap; i++) {
        data[i] = a[i-1];
    }
}

template<typename Key>
MaxPQ<Key>::~MaxPQ() {
    delete[]data;
}

template<typename Key>
void MaxPQ<Key>::insert(Key v) {
    if (len > cap - 1) resize(cap * 2);
    data[len++] = v;
    swim(len);
}

template<typename Key>
void MaxPQ<Key>::swim(int k) {

}

template<typename Key>
int MaxPQ<Key>::parent(int k) {

}

template<typename Key>
int MaxPQ<Key>::leftChild(int k) {

}

template<typename Key>
int MaxPQ<Key>::rightChild(int k) {

}

template<typename Key>
void MaxPQ<Key>::resize(int size) {
    Key *tmp = new Key[size];
    for (int i = 0; i < size; i++) {
        tmp[i] = data[i];
    }
    delete []data;
}
