//
// Created by xuyc on 2021/1/31.
//

#include "uf_impl.h"

using namespace algs4;

QuickFindUF::QuickFindUF(int n) {
    _id = new int[n];
    _count = n;
    for (int i = 0; i < n; i++) {
        _id[i] = i;
    }
}

QuickFindUF::~QuickFindUF() {
    delete[]_id;
}

int QuickFindUF::count() {
    return _count;
}

int QuickFindUF::find(int p) {
    assert(p >= 0 && p < _count);
    return _id[p];
}

bool QuickFindUF::connected(int p, int q) {
    return find(p) == find(q);
}

void QuickFindUF::un(int p, int q) {
    int pid = find(p);
    int qid = find(q);
    for (int i = 0; i < _count; i++) {
        if (_id[i] == qid) {
            _id[i] = pid;
        }
    }
    _count--;
}

QuickUnionUF::QuickUnionUF(int n) {
    _id = new int[n];
    _count = n;
    for (int i = 0; i < _count; i++) {
        _id[i] = i;
    }
}

QuickUnionUF::~QuickUnionUF() {
    delete[]_id;
}

int QuickUnionUF::count() {
    return _count;
}

int QuickUnionUF::find(int p) {
    assert(p >= 0 && p < _count);
    while (p != _id[p]) {
        p = _id[p];
    }
    return p;
}

bool QuickUnionUF::connected(int p, int q) {
    return find(p) == find(q);
}

void QuickUnionUF::un(int p, int q) {
    int pp = find(p);
    int qp = find(q);
    if (pp == qp) {
        return;
    }
    _id[pp] = qp;
    _count--;
}

QuickWeightedUnionUF::QuickWeightedUnionUF(int n) {
    _id = new int[n];
    _sz = new int[n];
    _count = n;
    for (int i = 0; i < n; i++) {
        _id[i] = i;
        _sz[i] = 0;
    }
}

QuickWeightedUnionUF::~QuickWeightedUnionUF() {
    delete []_id;
    delete []_sz;
}

int QuickWeightedUnionUF::count() {
    return _count;
}

int QuickWeightedUnionUF::find(int p) {
    assert(p >= 0 && p < _count);
    while (p != _id[p]) {
        p = _id[p];
    }
    return p;
}

bool QuickWeightedUnionUF::connected(int p, int q) {
    return find(p) == find(q);
}

void QuickWeightedUnionUF::un(int p, int q) {
    int pp = find(p);
    int qp = find(q);
    if (pp == qp) {
        return;
    }
    if (_sz[pp] > _sz[qp]) {
        _id[qp] = pp;
        _sz[pp] += _sz[qp];
    } else {
        _sz[pp] = qp;
        _sz[qp] += _sz[pp];
    }
    _count--;
}
