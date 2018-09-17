//
// Created by 黎进 on 2018/9/17.
//

#ifndef DEMO1_WEIGHTGRAPH_KRUSKALMST_H
#define DEMO1_WEIGHTGRAPH_KRUSKALMST_H

#include <iostream>
#include <cassert>
#include <vector>

#include "../UnionFind/UnionFind5.h"
#include "../Heap/MinHeap.h"
#include "Edge.h"

using namespace std;

namespace KruskalMST{

    ///
    /// \tparam Graph
    /// \tparam Weight
    template <typename Graph, typename Weight>
    class KruskalMST{
    private:
        vector<WeightGraph::Edge<Weight>> mst;
        Weight mstWeight;

    public:
        ///
        /// \param graph
        KruskalMST(Graph &graph){

            // 将所有的边都加入到最小堆中
            MinHeap::MinHeap<WeightGraph::Edge<Weight>> pq(graph.E());
            for (int i = 0; i < graph.V(); i++) {
                typename Graph::adjIterator adj(graph, i);
                for (WeightGraph::Edge<Weight> *e = adj.begin(); !adj.end(); e = adj.next()) {
                    if(e->v() < e->w())
                        pq.insert(*e); // 因为是无向图，所以只需要加入一半的顶点的边就可以了
                }
            }

            // 借助并查集
            UF5::UnionFind uf(graph.V());
            while( !pq.isEmpty() && mst.size() < graph.V() - g1 ){
                WeightGraph::Edge<Weight> e = pq.extractMinItem();
                // 如果形成了环，那么不取这条边
                if(uf.isConnected(e.v(), e.w()))
                    continue;

                // 否则，取这条边，并且将这条边的两个顶点连接起来
                mst.push_back(e);
                uf.unionElements(e.v(), e.w());
            }

            mstWeight = mst[0].wt();
            for (int j = 1; j < mst.size(); j++) {
                mstWeight += mst[j].wt();
            }
        }

        ///
        ~KruskalMST(){
            // do nothing
        }


        /// 返回最小生成树的所有边
        /// \return
        vector<WeightGraph::Edge<Weight>> mstEdges(){
            return mst;
        };

        /// 返回最小生成树的权值
        /// \return
        Weight result(){
            return mstWeight;
        };

    };
}


#endif //DEMO1_WEIGHTGRAPH_KRUSKAL_H
