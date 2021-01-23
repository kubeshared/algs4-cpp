//
// Created by xuyc on 2021/1/23.
//

#ifndef ALGS4_MIN_PQ_H
#define ALGS4_MIN_PQ_H


#include <fstream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

namespace algs4 {
    template<typename T>
    class MinPQ {
    public:
        MinPQ() {

            len = 0;
            pq = vector<T>(11);
        }

        explicit MinPQ(int max) {
            len = 0;
            pq = vector<T>(max + 1);
        }


        MinPQ(vector<T> a) {
            len = 0;
            pq = move(a);
        }

        ~MinPQ() = default;


        void insert(T v) {
            if (len == pq.size() - 1) {
                pq.resize(pq.size() * 2);
            }
            pq[++len] = v;
            swim(len);
        }

        T min() {
            return pq[1];
        }

        T delMin() {
            T max = pq[1];
            swap(pq[1], pq[len--]);
            sink(1);
            pq.erase(pq.begin() + (len + 1));
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
            while (k > 1 && pq[k] < pq[parent(k)]) {
                std::swap(pq[k], pq[parent(k)]);
                k = parent(k);
            }
        }

        void sink(int k) {
            while (leftChild(k) <= len) {
                int j = leftChild(k);
                if (j < len && pq[j] > pq[rightChild(k)]) {
                    j = rightChild(k);
                }
                if (pq[k] <= pq[j]) {
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


#endif //ALGS4_MIN_PQ_H
