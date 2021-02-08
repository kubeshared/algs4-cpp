//
// Created by xuyc on 2021/1/31.
//

#include "uf_impl.h"

using namespace algs4;

QuickFindUF::QuickFindUF(int n) {
    _id = new int[n];
    _count = n;
    for (int i = 0; i < _count; i++) {
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
    return _id[p];
}

bool QuickFindUF::connected(int p, int q) {
    return _id[p] == _id[q];
}

void QuickFindUF::un(int p, int q) {
    int pid = find(p);
    int qid = find(q);
    for (int i = 0; i < _count; i++) {
        if (_id[i] == pid) {
            _id[i] = qid;
        }
    }
    _count--;
}

QuickUnionUF::QuickUnionUF(int n) {
    _id = new int[n];
    _n = n;
    _count = n;
    for (int i = 0; i < _n; i++) {
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
    // we start from point p and get the parent of point p
    // through id[p] until we find the root node.
    while (p != _id[p]) {
        // get the parent of point p
        p = _id[p];
    }
    return p;
}

bool QuickUnionUF::connected(int p, int q) {
    return find(p) == find(q);
}

void QuickUnionUF::un(int p, int q) {
    // get the root node of p
    int pRoot = find(p);
    // get the root node of q
    int qRoot = find(q);
    // do nothing, because p and q in same connected component.
    if (pRoot == qRoot) {
        return;
    }
    // union all points in the set of connected components pRoot to qRoot, now
    // the p and q in same connected component.
    _id[pRoot] = qRoot;
    _count--;
}

QuickWeightedUnionUF::QuickWeightedUnionUF(int n) {
    _id = new int[n];
    _sz = new int[n];
    _n = n;
    _count = n;
    for (int i = 0; i < _n; i++) {
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
    // get the root of p
    int pRoot = find(p);
    // get the root of q
    int qRoot = find(q);
    if (pRoot == qRoot) {
        return;
    }
    // we always union small tree into large tree.
    if (_sz[pRoot] > _sz[qRoot]) {
        _id[qRoot] = pRoot;
        // update the tree height.
        _sz[pRoot] += _sz[qRoot];
    } else {
        _sz[pRoot] = qRoot;
        _sz[qRoot] += _sz[pRoot];
    }
    _count--;
}
