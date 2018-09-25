//
// Created by 黎进 on 2018/9/19.
//

#ifndef DEMO1_SHORTESTPATH_DIJKSTRA_H
#define DEMO1_SHORTESTPATH_DIJKSTRA_H

#include <iostream>
#include <cassert>
#include <vector>
#include <stack>
#include "Edge.h"
#include "../Heap/IndexMinHeap.h"

using namespace std;

namespace ShortestPath {

    template <typename Graph, typename Weight>
    class Dijkstra {

    private:
        Graph &G;
        int s;

        Weight * distTo; // from s to every vertex's weight
        bool * marked; // record if a vertex is marked;
        vector<Edge<Weight> *> from; // the last edge to visit vertex 'i' is from[i]

    public:
        ///
        /// \param graph
        /// \param s
        Dijkstra(Graph &graph, int s) : G(graph) {
            // init
            assert(s >= 0 && s <= G.V());
            this->s = s;


            distTo = new Weight[G.V()];
            marked = new bool[G.V()];
            for (int i = 0; i < G.V(); i++) {
                distTo[i] = Weight();
                marked[i] = false;
            }

            // Dijkstra
            IndexMinHeap::IndexMinHeap<Weight> ipq(G.V());

            distTo[s] = Weight();
            from[s] = new Edge<Weight>(s, s, Weight());
            ipq.insert(s, distTo[s]);
            marked[s] = true;

            while(!ipq.isEmpty()){
                // extract min index
                int v = ipq.extracMinIndex();
                marked[v] = true;

                typename Graph::adjIterator adj(G, v);
                for (Edge<Weight> e = adj.begin();  !adj.end() ; e = adj.next()) {
                    int w = e.other(v);
                    if(!marked[w]){
                        // w is not visited
                        // w's path is longer than v + e.wt()
                        if(from[w] == NULL || distTo[v] + e.wt() < distTo[w] ){
                            from[w] = e;
                            distTo[w] = distTo[v] + e.wt();
                            if(ipq.contain(w))
                                ipq.change(w, e.wt());
                            else
                                ipq.insert(w, e.wt());
                        }
                    }
                }
            }
        }

        ///
        ~Dijkstra() {
            delete [] distTo;
            delete [] marked;
            delete from[0];
        }

        ///
        /// \param w
        /// \return
        bool hasPath( int w ){
            assert(w >= 0 && w <= G.V());
            return marked[w];
        }

        ///
        /// \param w
        /// \return
        Weight shortestPathTo( int w ){
            assert(w >= 0 && w <= G.V());
            assert( hasPath(w) );
            return distTo[w];
        }

        ///
        /// \param w
        /// \param vec
        void shortestPath(int w, vector<Edge<Weight>> &vec){
            assert(w >= 0 && w <= G.V());
            assert(hasPath(w));

            stack<Edge<Weight> *> s;
            Edge<Weight>* e = from[w];
            while(e->v() != this->s){
                s.push(e);
                e = from[e->v()];
            }

            while(!s.empty()){
                e = s.top();
                vec.push_back(*e);
                s.pop();
            }
            return;
        }

        ///
        /// \param w
        void showShortestPath(int w){
            assert(w >= 0 && w <= G.V());
            assert(hasPath(w));

            vector<Edge<Weight>> vec;
            shortestPath(w, vec);

            for (int i = 0; i < vec.size(); i++) {
                cout<<vec[i].v()<<" -> ";
                if( i == vec.size()-1 )
                    cout<<vec[i].w()<<endl;
            }
        }

    };
}

#endif //DEMO1_SHORTESTPATH_DIJKSTRA_H
