//
// Created by xuyc on 2021/1/23.
//

#ifndef ALGS4_INDEX_MIN_PQ_H
#define ALGS4_INDEX_MIN_PQ_H

namespace algs4 {
    template<typename T>
    class IndexMinPQ {
    private:
        void swim(int k) {

        }

        void sink(int k) {

        }

    public:
        /**
         * Initializes an empty indexed priority queue with indices between 0
         * and maxN - 1.
         * @param maxN keys on this priority queue are index from 0
         *        maxN - 1
         */
        explicit IndexMinPQ(int maxN) {

        }

        /**
         * Returns true if this priority queue is empty.
         * @return true if this priority queue is empty;
         *         false otherwise
         */
        bool isEmpty() const {

        }

        /**
         * Is i an index on this priority queue?
         * @param i index
         * @return true if i is an index on this priority queue;
         *         false otherwise
         */
        bool contains(int i) const {

        }

        /**
         * Returns the number of keys on this priority queue.
         * @return the number of keys on this priority queue
         */
        int size() const {

        }

        /**
         * Associates key with index i.
         * @param i i an index
         * @param key the key to associate with index i
         */
        void insert(int i, T key) {

        }

        /**
         * Returns an index associated with a minimum key.
         * @return an index associated with a minimum key
         */
        int minIndex() const {

        }

        /**
         *  Returns a minimum key.
         * @return a minimum key
         */
        T minKey() const {

        }

        /**
         * Removes a minimum key and returns its associated index.
         * @return an index associated with a minimum key
         */
        int delMin() {

        }

        /**
         * Returns the key associated with index i.
         * @param i
         * @return
         */
        T keyOf(int i) const {

        }

        /**
         * Change the key associated with index i to the specified value.
         * @param i i the index of the key to change
         * @param key key change the key associated with index i to this key
         */
        void changeKey(int i, T key) {

        }

        /**
         * Change the key associated with index i to the specified value.
         * @param i i the index of the key to change
         * @param key key change the key associated with index i to this key
         */
        void change(int i, T key) {

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
        void delete (int i) {

        }
    };
};

#endif //ALGS4_INDEX_MIN_PQ_H
