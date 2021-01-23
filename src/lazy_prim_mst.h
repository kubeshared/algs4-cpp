//
// Created by xuyc on 2021/1/23.
//

#ifndef SRC_LAZY_PRIM_MST_H
#define SRC_LAZY_PRIM_MST_H

#include <queue>
#include "edge_weighted_graph.h"
#include "min_pq.h"
namespace algs4 {
    class LazyPrimMST {
    private:
        /**
         * run Prim's algorithm
         * @param G
         * @param s
         */
        void prim(const EdgeWeightedGraph& G, int s);

        /**
         * add all edges e incident to v onto pq if the other endpoint has not yet been scanned
         * @param G
         * @param v
         */
        void scan(const EdgeWeightedGraph& G, int v);

        queue<Edge> mst;
        double mstWeight;
        algs4::MinPQ<Edge> pq;
        bool *marked;
    public:
        /**
        * Compute a minimum spanning tree (or forest) of an edge-weighted graph.
        * @param G the edge-weighted graph
        */
        explicit LazyPrimMST(const EdgeWeightedGraph& G);

        /**
         * LazyPrimMST destructor
         */
        ~LazyPrimMST();

        /**
        * Returns the edges in a minimum spanning tree (or forest).
        * @return the edges in a minimum spanning tree (or forest) as
        *    an iterable of edges
        */
        queue<Edge> edges() const;

        /**
        * Returns the sum of the edge weights in a minimum spanning tree (or forest).
        * @return the sum of the edge weights in a minimum spanning tree (or forest)
        */
        double weight() const;
    };
}


#endif //SRC_LAZY_PRIM_MST_H
