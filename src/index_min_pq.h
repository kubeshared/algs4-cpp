//
// Created by xuyc on 2021/1/23.
//

#ifndef ALGS4_INDEX_MIN_PQ_H
#define ALGS4_INDEX_MIN_PQ_H

#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;

namespace algs4 {
    template<typename T>
    class IndexMinPQ {
    private:
        void swim(int k) {
            while (k > 1 && greater(k / 2, k)) {
                exch(k, k / 2);
                k = k / 2;
            }
        }

        void sink(int k) {
            int j;
            while (k * 2 <= n) {
                j = k * 2;
                if (j < n && greater(j, j + 1)) {
                    j += 1;
                }

                if (!(greater(k, j))) {
                    break;
                }
                exch(k, j);
                k = j;
            }
        }

        void exch(int i, int j) {
            swap(indexes[i], indexes[j]);
            swap(reverses[indexes[i]], reverses[indexes[j]]);
        }

        bool greater(int i, int j) {
            return data[indexes[i]] > data[indexes[j]];
        }

        int n;

        vector<T> data;

        int *indexes;

        int *reverses;
    public:
        /**
         * Initializes an empty indexed priority queue with indices between 0
         * and maxN - 1.
         * @param maxN keys on this priority queue are index from 0
         *        maxN - 1
         */
        explicit IndexMinPQ(int maxN) : n(0) {
            indexes = new int[maxN + 1];
            reverses = new int[maxN + 1];
            data = vector<T>(maxN + 1);
            for (int i = 0; i < maxN + 1; i++) {
                indexes[i] = 0;
                reverses[i] = indexes[i];
            }
        }

        ~IndexMinPQ() {
            delete[]indexes;
            delete[]reverses;
        }

        /**
         * Returns true if this priority queue is empty.
         * @return true if this priority queue is empty;
         *         false otherwise
         */
        bool isEmpty() const {
            return n == 0;
        }

        /**
         * Is i an index on this priority queue?
         * @param i index
         * @return true if i is an index on this priority queue;
         *         false otherwise
         */
        bool contains(int i) const {
            return indexes[i] != 0;
        }

        /**
         * Returns the number of keys on this priority queue.
         * @return the number of keys on this priority queue
         */
        int size() const {
            return n;
        }

        /**
         * Associates key with index i.
         * @param i i an index
         * @param key the key to associate with index i
         */
        void insert(int i, T key) {
            // the i must is between 1 and data.size
            assert(i >= 0 && i < data.size());
            n++;
            data[++i] = key;
            indexes[n] = i;
            reverses[i] = n;
            swim(n);
        }

        /**
         * Returns an index associated with a minimum key.
         * @return an index associated with a minimum key
         */
        int minIndex() const {
            return indexes[1];
        }

        /**
         *  Returns a minimum key.
         * @return a minimum key
         */
        T minKey() const {
            return data[indexes[1]];
        }

        /**
         * Removes a minimum key and returns its associated index.
         * @return an index associated with a minimum key
         */
        int delMin() {
            int index = indexes[1];
            swap(indexes[1], indexes[n--]);
            sink(1);
            return index;
        }

        /**
         * Returns the key associated with index i.
         * @param i
         * @return
         */
        T keyOf(int i) const {
            assert(i > 0 && i < data.size());
            return data[i];
        }

        /**
         * Change the key associated with index i to the specified value.
         * @param i i the index of the key to change
         * @param key key change the key associated with index i to this key
         */
        void changeKey(int i, T key) {
            data[i] = key;
            swim(reverses[i]);
            sink(reverses[i]);
        }

        /**
         * Change the key associated with index i to the specified value.
         * @param i i the index of the key to change
         * @param key key change the key associated with index i to this key
         */
        void change(int i, T key) {
            changeKey(i, key);
        }

        /**
         * Decrease the key associated with index i to the specified value.
         * @param i i the index of the key to decrease
         * @param key key decrease the key associated with index i to this key
         */
        void decreaseKey(int i, T key) {

        }

        /**
         * Increase the key associated with index i to the specified value.
         * @param i key increase the key associated with index i to this key
         * @param key
         */
        void increaseKey(int i, T key) {

        }

        /**
         * Remove the key associated with index i.
         * @param i the index of the key to remove
         */
        void deleteKey(int i) {

        }

    };
};

#endif //ALGS4_INDEX_MIN_PQ_H
