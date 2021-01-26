//
// Created by xuyc on 2021/1/25.
//

#ifndef SRC_PRIM_MST_H
#define SRC_PRIM_MST_H

#include "edge_weighted_graph.h"
#include "index_min_pq.h"
#include <queue>

using namespace std;

namespace algs4 {
    class PrimMST {
    private:
        /**
         * run Prim's algorithm in graph G, starting from vertex s
         * @param G is graph
         * @param s starting vertex
         */
        void prim(const EdgeWeightedGraph& G, int s);

        /**
         * scan vertex v in graph G
         * @param G is graph
         * @param v scan vertex
         */
        void scan(const EdgeWeightedGraph& G, int v);

        bool *_marked;
        double *_distTo;
        vector<Edge> _edgeTo;
        IndexMinPQ<double> _pq;
    public:
        /**
         * Compute a minimum spanning tree (or forest) of an edge-weighted graph.
         * @param G
         */
        explicit PrimMST(const EdgeWeightedGraph& G);

        ~PrimMST();

        /**
         * Returns the edges in a minimum spanning tree (or forest).
         * @return the edges in a minimum spanning tree (or forest) as
         *      an iterable of edges
         */
        vector<Edge> edges() const;

        /**
         * Returns the sum of the edge weights in a minimum spanning tree (or forest).
         * @return the sum of the edge weights in a minimum spanning tree (or forest)
         */
        double weight() const;
    };
}



#endif //SRC_PRIM_MST_H
