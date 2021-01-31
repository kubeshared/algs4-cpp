//
// Created by xuyc on 2021/1/31.
//

#ifndef SRC_UF_H
#define SRC_UF_H

namespace algs4 {
    class UF {
    public:
        /**
         * Returns the number of sets.
         * @return the number of sets between 0 and n
         */
        virtual int count() = 0;

        /**
         * Returns the canonical element of the set containing element p
         * @param p an element
         * @return  the canonical element of the set containing p
         */
        virtual int find(int p) = 0;

        /**
         *  Returns true if the two elements are in the same set
         * @param p one element
         * @param q the other element
         * @return true if p and q are in the same set;
         *         false otherwise.
         */
        virtual bool connected(int p, int q) = 0;

        /**
         * Merges the set containing element p with the
         * the set containing element q.
         *
         * @param p one element
         * @param q the other element
         */
        virtual void un(int p, int q) = 0;
    };
}

#endif //SRC_UF_H
