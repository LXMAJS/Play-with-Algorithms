//
// Created by 黎进 on 2018/8/27.
//

#ifndef DEMO1_UNIONFIND2_H
#define DEMO1_UNIONFIND2_H
#include <iostream>
#include <cassert>

using namespace std;

namespace UF2 {

    class UnionFind {

    private:
        int *parent;
        int count;

    public:
        /// construction
        UnionFind(int n) {
            count = n;
            parent = new int[n];

            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }

        ///
        ~UnionFind() {
            count = 0;
            delete[] parent;
        }

        ///
        /// \param p
        /// \return
        int find(int p) {
            assert(p >= 0 && p < count);

            while (p != parent[p]) {
                p = parent[p];
            }

            return p;
        }

        ///
        /// \param p
        /// \param q
        /// \return
        bool isConnected(int p, int q) {
            return find(p) == find(q);
        }

        ///
        /// \param p
        /// \param q
        void unionElements(int p, int q) {
            int pRoot = find(p);
            int qRoot = find(q);

            if (pRoot == qRoot)
                return;

            parent[pRoot] = qRoot;
            return;
        }
    };
}
#endif //DEMO1_UNIONFIND2_H
