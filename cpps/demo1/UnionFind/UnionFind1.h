//
// Created by 黎进 on 2018/8/27.
//

#ifndef DEMO1_UNIONFIND1_H
#define DEMO1_UNIONFIND1_H

#include <iostream>
#include <cassert>

using namespace std;

namespace UF1 {

    class UnionFind1 {

    private:
        int *id;
        int count;

    public:
        /// construction
        UnionFind1(int n) {
            count = n;
            id = new int [n];

            for (int i = 0; i < n; i++) {
                id[i] = i;
            }
        }

        ///
        ~UnionFind1(){
            count = 0;
            delete [] id;
        }

        /// find id
        /// \param p
        /// \return
        int find(int p){
            assert(p >= 0 && p < count);
            return id[p];
        }

        ///
        /// \param p
        /// \param q
        /// \return
        bool isContected(int p, int q){
            return find(p) == find(q);
        }

        ///
        void unionElements(int p, int q){
            int pId = find(p);
            int qId = find(q);

            if(pId == qId)
                return;

            for (int i = 0; i < count; i++) {
                if(id[i] == pId)
                    id[i] = qId;
            }
        }

    };
}

#endif //DEMO1_UNIONFIND1_H
