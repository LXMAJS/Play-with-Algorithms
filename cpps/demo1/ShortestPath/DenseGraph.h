//
// Created by 黎进 on 2018/9/19.
//

#ifndef DEMO1_SHORTESTPATH_DENSEGRAPH_H
#define DEMO1_SHORTESTPATH_DENSEGRAPH_H

#include <iostream>
#include <cassert>
#include <vector>
#include "Edge.h"

using namespace std;

namespace ShortestPath {

    ///
    /// \tparam Weight
    template <typename Weight>
    class DenseGraph{
    private:
        int n; // count of vectrix
        int m; // count of edge
        bool directed; // if directed
        vector<vector<Edge<Weight> *>> g; // graph

    public:
        /// construction
        /// \param n
        /// \param directed
        DenseGraph(int n, bool directed){
            this->n = n;
            this->m = 0;
            this->directed = directed;

            for (int i = 0; i < n; i++) {
                g.push_back( vector<Edge<Weight> *>(n, NULL) ); //TODO: can't understand now
            }
        }

        ~DenseGraph(){
            for( int i = 0 ; i < n ; i ++ )
                for( int j = 0 ; j < n ; j ++ )
                    if( g[i][j] != NULL )
                        delete g[i][j];
        }

        int V(){ return n; }
        int E(){ return m; }

        /// confirm two v has e
        /// \param v
        /// \param w
        /// \return
        bool hasEdge(int v, int w){
            assert(v >= 0 && v <= n);
            assert(w >= 0 && w <= n);

            return g[v][w] != NULL;
        }

        ///  add edge
        /// \param v
        /// \param w
        void addEdge(int v, int w, Weight weight) {
            assert(v >= 0 && v <= n);
            assert(w >= 0 && w <= n);

            // 去掉了平行边的概念
            if (hasEdge(v, w)) {
                delete g[v][w];
                if(!directed)
                    delete g[w][v];
            }

            g[v][w] = new Edge<Weight>(v, w, weight);
            if(!directed){
                g[w][v] = new Edge<Weight>(w, v, weight);
            }
            m++;
            return;
        }

        /// show a dense graph
        void show(){
            for (int i = 0; i < V(); i++) {
                for (int j = 0; j < V(); j++) {
                    if( g[i][j] )
                        cout<<g[i][j]->wt()<<"\t";
                    else
                        cout<<"NULL\t";
                }
                cout<<endl;
            }
        }


        /*
         *
         */
        class adjIterator{
        private:
            DenseGraph &G;
            int v; // current vertex
            int index;

        public:
            adjIterator(DenseGraph graph, int v) : G(graph) {
                this->v = v;
                this->index = -1; // 数组的下标从0开始，因此初始值可设置为 -1;
            }

            ///
            /// \return
            Edge<Weight>* begin(){
                index = -1;
                return next(); // 将index设置为-1，然后返回第一个next即可
            }

            ///
            /// \return
            Edge<Weight>* next(){
                index += 1;
                for ( ; index < G.V() ; index++) {
                    if(G.g[v][index])
                        return index; // 返回值为true的图的index
                }
                return -1;
            }

            bool end(){
                return index >= G.V();
            }
        };
    };
}

#endif //DEMO1_SHORTESTPATH_DENSEGRAPH_H
