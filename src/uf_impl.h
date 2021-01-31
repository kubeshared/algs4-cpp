//
// Created by xuyc on 2021/1/31.
//

#ifndef SRC_UF_IMPL_H
#define SRC_UF_IMPL_H

#include <cassert>
#include "uf.h"

namespace algs4 {
    class QuickFindUF : public UF {
    private:
        int _count;
        int *_id;
    public:
        QuickFindUF(int n);

        virtual ~QuickFindUF();

        int count() override;

        int find(int p) override;

        bool connected(int p, int q) override;

        void un(int p, int q) override;
    };

    class QuickUnionUF : public UF {
    private:
        int *_id;
        int _count;
    public:
        QuickUnionUF(int n);

        virtual ~QuickUnionUF();

        int count() override;

        int find(int p) override;

        bool connected(int p, int q) override;

        void un(int p, int q) override;
    };

    class QuickWeightedUnionUF : public UF {
    private:
        int *_id;
        int *_sz;
        int _count;
    public:
        QuickWeightedUnionUF(int n);

        virtual ~QuickWeightedUnionUF();

        int count() override;

        int find(int p) override;

        bool connected(int p, int q) override;

        void un(int p, int q) override;
    };
}


#endif //SRC_UF_IMPL_H
