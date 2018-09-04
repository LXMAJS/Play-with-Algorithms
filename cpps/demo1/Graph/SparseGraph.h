//
// Created by 黎进 on 2018/8/31.
//

#ifndef DEMO1_SPARSEGRAPH_H
#define DEMO1_SPARSEGRAPH_H

#include <iostream>
#include <vector>

using namespace std;

namespace SparseGraph {

    /*
     * advance list
     */
    class SparseGraph {
    private:
        int n; // count of v
        int m; // count of edge
        bool directed; // if directed
        vector<vector<int>> g; // graph

    public:
        ///
        /// \param n
        /// \param directed
        SparseGraph(int n, bool directed) {
            this->n = n;
            this->m = 0;
            this->directed = directed;
            g = vector<vector<int>>(n, vector<int>());
        }

        ~SparseGraph() {
            // Do nothing
        }

        int V() { return n; }

        int E() { return m; }

        ///
        /// \param v
        /// \param w
        /// \return
        bool hasEdge(int v, int w) {
            assert(v >= 0 && v <= n);
            assert(w >= 0 && w <= n);

            for (int i = 0; i < g[v].size(); i++) {
                if (g[v][i] == w)
                    return true;
            }
            return false;
        }

        ///
        /// \param v
        /// \param w
        void addEdge(int v, int w) {
            assert(v >= 0 && v <= n);
            assert(w >= 0 && w <= n);

            g[v].push_back(w);
            // 处理自环边ß
            if (v != w && !directed) {
                g[w].push_back(v);
            }
            m++;
            return;
        }

        /*
         * adjacent iterator
         */
        class adjIterator {
        private:
            SparseGraph &G;
            int v;
            int index;

        public:
            adjIterator(SparseGraph graph, int v) : G(graph) {
                this->v = v;
                this->index = 0;
            }

            ///
            /// \return
            int begin() {
                index = 0;
                if (G.g[v].size() > 0) {
                    return G.g[v][index];
                }
                return -1;
            }

            ///
            /// \return
            int next(){
                index ++;
                if(index < G.g[v].size()){
                    return G.g[v][index];
                }
                return -1;
            }

            ///
            /// \return
            bool end(){
                return index >= G.g[v].size();
            }
        };
    };
}

#endif //DEMO1_SPARSEGRAPH_H
