//
// Created by xuyc on 2021/1/21.
//

#ifndef ALGS4_EDGE_H
#define ALGS4_EDGE_H


class Edge {
public:
    explicit Edge(int v, int w, double weight);

    ~Edge() = default;

    double weight() const;

    int either() const;

    int other(int v) const;

    bool operator==(const Edge &rhs) const;

    bool operator!=(const Edge &rhs) const;

    bool operator<(const Edge &rhs) const;

    bool operator>(const Edge &rhs) const;

private:
    int _v, _w;
    double _weight;
};

#endif //ALGS4_EDGE_H
