//
// Created by 黎进 on 2018/9/19.
//

#ifndef DEMO1_SPARSEGRAPH_H
#define DEMO1_SPARSEGRAPH_H

#include <iostream>
#include <vector>

#include "Edge.h"

using namespace std;

namespace ShortestPath {
    /*
     * 稀疏图，邻接表
     */
    template <typename Weight>
    class SparseGraph {
    private:
        int n; // count of vertex
        int m; // count of edge
        bool directed; // if directed
        vector<vector<Edge<Weight> *>> g; // graph

    public:
        ///
        /// \param n
        /// \param directed
        SparseGraph(int n, bool directed) {
            this->n = n;
            this->m = 0;
            this->directed = directed;
            g = vector<vector<Edge<Weight> *>>(n, vector<Edge<Weight> *>());
        }

        ~SparseGraph() {
            for( int i = 0 ; i < n ; i ++ )
                for( int j = 0 ; j < g[i].size() ; j ++ )
                    delete g[i][j];
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
                if (g[v][i]->other(v) == w)
                    return true;
            }
            return false;
        }

        ///
        /// \param v
        /// \param w
        void addEdge(int v, int w, Weight weight) {
            assert(v >= 0 && v <= n);
            assert(w >= 0 && w <= n);

            g[v].push_back(new Edge<Weight>(v, w, weight));
            // 处理自环边ß
            if (v != w && !directed) {
                g[w].push_back(new Edge<Weight>(w, v, weight));
            }
            m++;
            return;
        }

        /// show an sparse graph
        void show(){
            for (int i = 0; i < V(); i++) {
                cout<<"vertex "<<i<<":\t";
                for (int j = 0; j < g[i].size(); j++) {
                    cout<<"( to:"<<g[i][j]->w()<<",wt:"<<g[i][j]->wt()<<")\t";
                }
                cout<<endl;
            }
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
            Edge<Weight> * begin() {
                index = 0;
                if (G.g[v].size() > 0) {
                    return G.g[v][index];
                }
                return NULL;
            }

            ///
            /// \return
            Edge<Weight> * next(){
                index ++;
                if(index < G.g[v].size()){
                    return G.g[v][index];
                }
                return NULL;
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
