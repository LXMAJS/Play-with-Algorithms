//
// Created by 黎进 on 2018/9/14.
//

#ifndef DEMO1_WEIGHTGRAPH_LAZYPRIMMST_H
#define DEMO1_WEIGHTGRAPH_LAZYPRIMMST_H

#include <iostream>
#include <cassert>
#include <vector>

#include "../Heap/MinHeap.h"
#include "Edge.h"

using namespace std;

namespace LazyPrimMST{

    template <typename Graph, typename Weight>
    class LazyPrimMST{

    private:
        Graph &G;
        MinHeap::MinHeap<WeightGraph::Edge<Weight>> pq;
        bool * marked;
        vector<WeightGraph::Edge<Weight>> mst;
        Weight mstWeight;

        /// visit this vertex
        /// \param v
        void visit(int v){
            assert(v >= 0 && v <= G.V());
            assert( ! marked[v] );
            marked[v] = true;

            typename Graph::adjIterator adj(G, v);
            for (WeightGraph::Edge<Weight> e = adj.begin(); !adj.end(); e = adj.next()) {
                if(!marked[e->other(v)]){
                    pq.insert(*e);
                }
            }
        }


    public:
        LazyPrimMST(){
            marked = new bool[G.V()];
            for (int i = 0; i < G.V(); i++) {
                marked[i] = false;
            }
            mst.clear();

            // Lazy Prim
            while(!pq.isEmpty()){
                WeightGraph::Edge<Weight> e = pq.extractMinItem();
                if(marked[e.v()] == marked[e.w()])
                    continue;

                // push into mst
                mst.push_back(e);

                // one edge must be marked, so check and visit
                if(!marked[e.v()])
                    visit(e.v());
                else
                    visit(e.w());
            }

            // calculate mst's weight
            mstWeight = mst[0].wt();
            for (int j = 1; j < mst.size(); j++) {
                mstWeight += mst[j].wt();
            }
        }

        ~LazyPrimMST(){
            delete[] marked;
        }
    };
}


#endif //DEMO1_WEIGHTGRAPH_LAZYPRIMMST_H
