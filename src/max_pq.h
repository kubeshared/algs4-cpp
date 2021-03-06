//
// Created by xuyc on 2021/1/22.
//

#ifndef ALGS4_MAX_PQ_H
#define ALGS4_MAX_PQ_H

#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

namespace algs4 {
    template<typename T>
    class MaxPQ {
    public:
        MaxPQ() {

            len = 0;
            pq = vector<T>(11);
        }

        explicit MaxPQ<T>(int max) {
            len = 0;
            pq = vector<T>(max + 1);
        }


        MaxPQ(vector<T> a) {
            len = 0;
            pq = move(a);
        }

        ~MaxPQ() = default;


        void insert(T v) {
            if (len == pq.size() - 1) {
                pq.resize(pq.size() * 2);
            }
            pq[++len] = v;
            swim(len);
        }

        T max() {
            return pq[1];
        }

        T delMax() {
            T max = pq[1];
            pq[1] = pq[len--];
            sink(1);
            if (len > 0 && (len == (pq.size() - 1) / 4)) {
                pq.resize(pq.size() / 2);
            }
            return max;
        }

        bool isEmpty() {
            return len == 0;
        }

        int size() {
            return len;
        }

    private:
        int parent(int k) const {
            return k / 2;
        }

        int leftChild(int k) const {
            return k * 2;
        }

        int rightChild(int k) const {
            return k * 2 + 1;
        }

        void swim(int k) {
            while (k > 1 && pq[k/2] < pq[k]) {
                std::swap(pq[k/2], pq[k]);
                k = k/2;
            }
        }

        void sink(int k) {
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

        int len;
        vector<T> pq;
    };
}


#endif //ALGS4_MAX_PQ_H
