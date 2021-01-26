//
// Created by xuyc on 2021/1/21.
//

#include "edge.h"

Edge::Edge(int v, int w, double weight)
        : _v(v), _w(w), _weight(weight) {

}

//Edge::Edge(const Edge &rhs)
//        : _v(rhs._v), _w(rhs._w), _weight(rhs._weight) {
//}


double Edge::weight() const {
    return _weight;
}

int Edge::either() const {
    return _v;
}

int Edge::other(int v) const {
    if (v == _v) return _w;
    if (v == _w) return _v;
    return v;
}

bool Edge::empty() const {
    return _v == -1 && _w == -1;
}

bool Edge::operator!=(const Edge &rhs) const {
    return rhs._weight != this->_weight;
}

bool Edge::operator==(const Edge &rhs) const {
    return rhs._weight == this->_weight;
}

bool Edge::operator<(const Edge &rhs) const {
    return this->_weight < rhs._weight;
}

bool Edge::operator>(const Edge &rhs) const {
    return this->_weight > rhs._weight;
}

bool Edge::operator<=(const Edge &rhs) const {
    return this->_weight <= rhs._weight;
}

bool Edge::operator>=(const Edge &rhs) const {
    return this->_weight >= rhs._weight;
}