//
// Created by 黎进 on 2018/9/15.
//

#ifndef DEMO1_WEIGHTGRAPH_PRIMMST_H
#define DEMO1_WEIGHTGRAPH_PRIMMST_H

#include <iostream>
#include <cassert>
#include <vector>

#include "../Heap/IndexMinHeap.h"
#include "Edge.h"

using namespace std;


namespace PrimMST {

    ///
    /// \tparam Graph
    /// \tparam Weight
    template <typename Graph, typename Weight>
    class PrimMST{

    private:
        Graph &G;
        IndexMinHeap::IndexMinHeap<WeightGraph::Edge<Weight>> ipq; // index min heap
        vector<WeightGraph::Edge<Weight> *> edgeTo; //
        bool* marked;
        vector<WeightGraph::Edge<Weight>> mst;
        Weight mstWeight;

        void visit(int v){
            assert(v >= 0 && v <= G.V());
            assert(!marked[v]);
            marked[v] = true; // set marked

            typename Graph::adjIterator adj(G, v);
            for ( WeightGraph::Edge<Weight> e = adj.begin(); !adj.end(); e = adj.next() ) {
                int w = e->other(v); // get the other vertex

                if(!marked[w]){ // is an adjective edge

                    if( !edgeTo[w] ){
                        // haven visited yet
                        edgeTo[w]= e;
                        ipq.insert(w, e.wt());

                    } else if( e.wt() < edgeTo[w]->wt()){
                        // shorter than before, exchange it
                        edgeTo[w]= e;
                        ipq.change(w, e.wt());

                    }

                }

            }
        }

    public:
        ///
        PrimMST(Graph &graph) : G(graph), ipq(IndexMinHeap::IndexMinHeap<double>(G.V())) {
            marked = new bool[G.V()];
            for (int i = 0; i < G.V(); i) {
                marked[i] = false;
                edgeTo.push_back(NULL);
            }
            mst.clear();

            // prim alogrithm
            visit(0); // set first vertex
            while(!ipq.isEmpty()){
                int v = ipq.extracMinIndex();
                assert(edgeTo[v]);

                mst.push_back( *edgeTo[v] );
                visit(v);
            }

            // calculate mst's weight
            mstWeight = mst[0].wt();
            for (int j = 1; j < mst.size(); j++) {
                mstWeight += mst[j].wt();
            }
        }

        ///
        ~PrimMST(){
            delete[] marked;
        }

        ///
        /// \return
        vector<WeightGraph::Edge<Weight>> mstEdges(){
            return mst;
        };

        ///
        /// \return
        Weight result(){
            return mstWeight;
        };

    };


}
#endif //DEMO1_WEIGHTGRAPH_PRIMMST_H
