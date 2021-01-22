//
// Created by xuyc on 2021/1/22.
//

#include "max_pq.h"

using namespace algs4;

template<typename Key>
MaxPQ<Key>::MaxPQ() {
    len = 0;
    cap = 11;
    pq = new Key[cap];
}

template<typename Key>
MaxPQ<Key>::MaxPQ(int max) {
    len = 0;
    cap = max + 1;
    pq = new Key[cap];
}

template<typename Key>
MaxPQ<Key>::MaxPQ(Key a[], int n) {
    len = 0;
    cap = n + 1;
    pq = new Key[cap];
    for (int i = 1; i < cap; i++) {
        pq[i] = a[i - 1];
    }
}

template<typename Key>
MaxPQ<Key>::~MaxPQ() {
    delete[]pq;
}

template<typename Key>
void MaxPQ<Key>::insert(Key v) {
    if (len > cap - 1) resize(cap * 2);
    pq[len++] = v;
    swim(len);
}

template<typename Key>
void MaxPQ<Key>::swim(int k) {
    while (k > 1) {
        if (pq[k] > pq[parent(k)]) {
            std::swap(pq[parent(k)], pq[k]);
        }
        k = parent(k);
    }
}

template<typename Key>
void MaxPQ<Key>::sink(int k) {
    while (leftChild(k) <= len) {
        int j = leftChild(k);
        if (j < len && pq[j] < pq[rightChild(k)]) {
            j = rightChild(k);
        }
        if (pq[k] >= pq[j]) {
            break;
        }

        std::swap(pq[k], pq[j]);
        k = j;
    }
}

template<typename Key>
Key MaxPQ<Key>::max() {
    return pq[1];
}

template<typename Key>
Key MaxPQ<Key>::delMax() {
    Key max = pq[1];
    pq[1] = pq[len--];
    sink(1);
    if (len > 0 && (len == (cap - 1) / 4)) {
        resize(cap / 2);
    }
    return max;
}

template<typename Key>
int MaxPQ<Key>::size() {
    return len;
}

template<typename Key>
bool MaxPQ<Key>::isEmpty() {
    return len == 0;
}

template<typename Key>
int MaxPQ<Key>::parent(int k) const {
    return k / 2;
}

template<typename Key>
int MaxPQ<Key>::leftChild(int k) const {
    return k * 2;
}

template<typename Key>
int MaxPQ<Key>::rightChild(int k) const {
    return k * 2 + 1;
}

template<typename Key>
void MaxPQ<Key>::resize(int size) {
    Key *tmp = new Key[size];
    for (int i = 0; i < size; i++) {
        tmp[i] = pq[i];
    }
    delete[]pq;
    pq = tmp;
}
