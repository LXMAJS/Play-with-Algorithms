//
// Created by 黎进 on 2018/8/27.
//

#ifndef DEMO1_UNIONFIND3_H
#define DEMO1_UNIONFIND3_H
#include <iostream>
#include <cassert>

using namespace std;

namespace UF3 {

    class UnionFind {

    private:
        int* parent;
        int* sz;
        int count;

    public:
        /// construction
        UnionFind(int n) {
            count = n;
            parent = new int[n];
            sz = new int[n];

            for (int i = 0; i < n; i++) {
                parent[i] = i;
                sz[i] = 1;
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
            if(sz[qRoot] > sz[pRoot]) {
                parent[pRoot] = qRoot;
                sz[qRoot] += sz[pRoot];
            }
            else{
                parent[qRoot] = pRoot;
                sz[pRoot] += sz[qRoot];
            }
            return;
        }
    };
}
#endif //DEMO1_UNIONFIND3_H
