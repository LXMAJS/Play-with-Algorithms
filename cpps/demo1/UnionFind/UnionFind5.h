//
// Created by 黎进 on 2018/8/27.
//

#ifndef DEMO1_UNIONFIND5_H
#define DEMO1_UNIONFIND5_H
#include <iostream>
#include <cassert>

using namespace std;

namespace UF5 {

    class UnionFind {

    private:
        int* parent;
        int* rank;
        int count;

    public:
        /// construction
        UnionFind(int n) {
            count = n;
            parent = new int[n];
            rank = new int[n];

            for (int i = 0; i < n; i++) {
                parent[i] = i;
                rank[i] = 1;
            }
        }

        ///
        ~UnionFind() {
            count = 0;
            delete[] parent;
            delete[] rank;
        }

        ///
        /// \param p
        /// \return
        int find(int p) {
            assert(p >= 0 && p < count);

            // 两步一跳的压缩路径
//            while (p != parent[p]) {
//                parent[p] = parent[parent[p]];
//                p = parent[p];
//            }
//
//            return p;

            // 一次find压缩全部的节点路径
            if(p != parent[p])
                parent[p] = find( parent[p] );

            return parent[p];
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

            if(rank[pRoot] < rank[qRoot]) {
                parent[pRoot] = qRoot;
            }
            else if(rank[qRoot] < rank[pRoot]){
                parent[qRoot] = pRoot;
            }
            else{ // rank[qRoot] == rank[pRoot]
                parent[pRoot] = qRoot;
                rank[qRoot] += 1;
            }
            return;
        }
    };
}
#endif //DEMO1_UNIONFIND5_H
