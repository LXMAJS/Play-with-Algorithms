//
// Created by 黎进 on 2018/9/25.
//

#ifndef DEMO1_SHORTESTPATH_BELLMANFORD_H
#define DEMO1_SHORTESTPATH_BELLMANFORD_H

#include <iostream>
#include <vector>
#include <cassert>
#include <stack>

#include "Edge.h"

using namespace std;

namespace ShortestPath {

    template <typename Graph, typename Weight>
    class BellmanFord {
    private:
        Graph &G;
        int s; // source
        Weight * distTo;
        vector<Edge<Weight> *> from; //
        bool hasNegativeCycle;

        ///
        /// \return
        bool detectNegativeCycle(){
            for (int i = 0; i < G.V(); i++) {
                typename Graph::adjIterator adj(G, i);
                for (Edge<Weight> e = adj.begin(); !adj.end() ; e = adj.next()) {
                    if( from[e->v()] && (!from[e->w()] || distTo[e->v()] + e.wt() < distTo[e.w()] ) ){
                        return true;
                    }
                }
            }
        }

    public:
        ///
        /// \param graph
        /// \param s
        BellmanFord(Graph graph, int s) : G(graph){
            this->s = s;
            distTo = new Weight[G.V()];
            for (int i = 0; i < G.V(); i++) {
                from.push_back(NULL);
            }

            distTo[s] = Weight();
            from[s] = new Edge<Weight>(s, s, Weight());

            //
            for (int pass = 0; pass < G.V(); pass++) {
                for (int i = 0; i < G.V(); i++) {
                    typename Graph::adjIterator adj(G, i);
                    for (Edge<Weight> e = adj.begin(); !adj.end() ; e = adj.next()) {
                        if( from[e->v()] && (!from[e->w()] || distTo[e->v()] + e.wt() < distTo[e.w()] ) ){
                            distTo[e.w()] = distTo[e->v()] + e.wt();
                            from[e.w()] = e;
                        }
                    }
                }
            }

            // justify
            hasNegativeCycle = detectNegativeCycle();

        }

        ///
        ~BellmanFord(){
            delete [] distTo;
            delete from[s];
        }

        ///
        /// \return
        bool negativeCycle(){
            return hasNegativeCycle;
        }

        ///
        /// \param w
        /// \return
        Weight shortestPathTo(int w){
            assert(w >= 0 && w < G.V());
            assert(negativeCycle());
            assert(hasPathTo(w));
            return distTo[w];
        }

        ///
        /// \param w
        /// \return
        bool hasPathTo(int w){
            assert(w >= 0 && w < G.V());
            return from[w] != NULL;
        }

        ///
        /// \param w
        /// \param vec
        void shortestPath(int w, vector<Edge<Weight>> &vec){
            assert(w >= 0 && w < G.V());
            assert(negativeCycle());
            assert(hasPathTo(w));

            stack<Edge<Weight>*> sta;
            Edge<Weight>* e = from[w];
            while(e->v() != this->s){
                sta.push(e);
                e = from[e->v()];
            }

            // add to vector
            while(!sta.empty()){
                e = sta.top();
                vec.push_back(*e);
                sta.pop();
            }
        }

        ///
        /// \param w
        void showPath(int w){
            assert(w >= 0 && w < G.V());
            assert(negativeCycle());
            assert(hasPathTo(w));

            vector<Edge<Weight>> vec;
            shortestPathTo(w, vec);
            for (int i = 0; i < vec.size(); i++) {
                cout<<vec[i].v()<<" -> ";
                if( i == vec.size()-1 )
                    cout<<vec[i].w()<<endl;
            }
        }

    };
}


#endif //DEMO1_SHORTESTPATH_BELLMANFORD_H
